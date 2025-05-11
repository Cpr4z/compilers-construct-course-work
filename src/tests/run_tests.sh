#!/bin/bash

BUILD_DIR="../cmake-build-debug"
PROGRAMS_DIR="./programs"
EXPECTED_DIR="./expected"
OUTPUT_DIR="./output"
LL_DIR="./ll"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

ALL_PASSED=true

./clean.sh

for file in "$PROGRAMS_DIR"/*.b; do
      filename=$(basename -- "$file")
      name="${filename%.*}"

      "$BUILD_DIR/bCompiler" "$file" -o
      if [ $? -ne 0 ]; then
          echo -e "${RED}[FAIL]${NC} Компиляция не удалась: $file"
          ALL_PASSED=false
          continue
      fi

      lli "$LL_DIR/$name.ll" > "$OUTPUT_DIR/$name.output"

      if diff -q "$OUTPUT_DIR/$name.output" "$EXPECTED_DIR/$name.expected" > /dev/null; then
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