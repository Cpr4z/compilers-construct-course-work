#!/bin/bash

BUILD_DIR="./cmake-build-debug"
PROGRAMS_DIR="./programs"
EXPECTED_DIR="./expected"
OUTPUT_DIR="./output"

mkdir -p "$OUTPUT_DIR"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

if [ ! -f "$BUILD_DIR/bCompiler.exe" ]; then
  cmake -S .. -B "$BUILD_DIR" && cmake --build "$BUILD_DIR"
  if [ $? -ne 0 ]; then
    echo -e "${RED}[ERROR] Не удалось собрать проект.${NC}"
    exit 1
  fi
else
  echo -e "${GREEN} Найден бинарник: $BUILD_DIR/bCompiler${NC}"
fi

ALL_PASSED=true


for file in "$PROGRAMS_DIR"/*.b; do
      filename=$(basename -- "$file")
      name="${filename%.*}"

      "$BUILD_DIR/bCompiler" "$file" -o "$OUTPUT_DIR/$name.ll"
      if [ $? -ne 0 ]; then
          echo -e "${RED}[FAIL]${NC} Компиляция не удалась: $file"
          ALL_PASSED=false
          continue
      fi

      clang "$OUTPUT_DIR/$name.ll" -o "$OUTPUT_DIR/$name.out"
      if [ $? -ne 0 ]; then
          echo -e "${RED}[FAIL]${NC} Линковка не удалась: $name.ll"
          ALL_PASSED=false
          continue
      fi

      "$OUTPUT_DIR/$name.out" > "$OUTPUT_DIR/$name.output"

      diff -q "$OUTPUT_DIR/$name.output" "$EXPECTED_DIR/$name.expected" > /dev/null
      if [ $? -eq 0 ]; then
          echo -e "${GREEN}[PASS]${NC} $name"
      else
          echo -e "${RED}[FAIL]${NC} $name"
          echo "Expected:"
          cat "$EXPECTED_DIR/$name.expected"
          echo "Got:"
          cat "$OUTPUT_DIR/$name.output"
          ALL_PASSED=false
      fi
done

if [ "$ALL_PASSED" = true ]; then
    echo -e "\n${GREEN} Все тесты пройдены успешно!${NC}"
    exit 0
else
    echo -e "\n${RED} Некоторые тесты не пройдены.${NC}"
    exit 1
fi