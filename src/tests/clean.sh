#!/bin/bash

LL_DIR="./ll"
OUTPUT_DIR="./output"

find "$LL_DIR" -type f -regex '.*/test[0-9]\+\.b' -delete
find "$OUTPUT_DIR" -type f -regex '.*/test[0-9]\+\.b' -delete

#rm -f "$LL_DIR"/*
#rm -f "$OUTPUT_DIR"/*