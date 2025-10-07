#!/usr/bin/bash

fileBasenameNoExtension="${1}"
exe="${fileBasenameNoExtension}.out";
mkdir -p input output;

in="input/${fileBasenameNoExtension}.txt";
out="output/${fileBasenameNoExtension}.txt";

# input 파일 없으면 생성 후 종료
if [ ! -f "$in" ]; then
  echo "[INFO] input file not found, created $in";
  : > "$in";
  exit 0;
fi;

# 실행 파일 없으면 에러
if [ ! -x "$exe" ]; then
  echo "[ERR] executable $exe not found. build first.";
  exit 1;
fi;

# 실행 및 리다이렉션
./"$exe" < "$in" > "$out";
echo "[OK] wrote -> $out";
