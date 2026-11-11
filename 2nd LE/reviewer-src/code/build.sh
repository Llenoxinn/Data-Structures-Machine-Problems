#!/usr/bin/env bash
# Compiles and runs every program of the reviewer.
#   tracing/*.c(pp), notes/*.c(pp) : output captured in out/<name>.txt (shown in the book)
#   test/*.c(pp)                   : self-checking tests (sample tests, brute force, leaks)
# A program's force-included headers are listed on its first line, e.g.
#   // libs: lib/sll.h sol/p18.c       (paths from code/; the line is not shown in the book)
cd "$(dirname "$0")"
mkdir -p bin out
CFLAGS="-std=c99 -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-unused-function -O1"
CXXFLAGS="-std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-write-strings -Wno-sign-compare -O1"
fail=0

libs_of() {   # prints -include flags for the files named on line 1 (paths from code/)
  local line; line=$(head -1 "$1")
  case "$line" in
    "// libs:"*) for h in ${line#// libs:}; do printf -- '-include %s ' "$h"; done ;;
  esac
}

build() {     # build <src> <extra flags>
  local src=$1 extra=$2 name exe
  name=$(basename "${src%.*}"); exe="bin/$name.exe"
  if [[ $src == *.cpp ]]; then
    g++ $CXXFLAGS $extra -include lib/harness.h $(libs_of "$src") "$src" -o "$exe" 2> "bin/$name.err"
  else
    gcc $CFLAGS $extra -include lib/harness.h $(libs_of "$src") "$src" -o "$exe" 2> "bin/$name.err"
  fi
  if [[ $? -ne 0 ]]; then echo "COMPILE ERROR $src"; cat "bin/$name.err"; fail=1; return 1; fi
  if [[ -s "bin/$name.err" ]]; then echo "warnings in $src:"; cat "bin/$name.err"; fi
  return 0
}

only=${1:-}
for src in tracing/*.c tracing/*.cpp notes/*.c notes/*.cpp; do
  [[ -e $src ]] || continue
  [[ -n $only && $src != *$only* ]] && continue
  name=$(basename "${src%.*}")
  if build "$src" ""; then
    if [[ -f "${src%.*}.in" ]]; then ./bin/$name.exe < "${src%.*}.in" > "out/$name.txt"
    else ./bin/$name.exe > "out/$name.txt"; fi
    echo "ran $src (exit $?)"
  fi
done
for src in test/*.c test/*.cpp; do
  [[ -e $src ]] || continue
  [[ -n $only && $src != *$only* ]] && continue
  name=$(basename "${src%.*}")
  if build "$src" "-DCOUNT_BLOCKS -Wno-misleading-indentation -Wno-maybe-uninitialized"; then
    printf '%-24s ' "$src"; ./bin/$name.exe || fail=1
  fi
done
exit $fail
