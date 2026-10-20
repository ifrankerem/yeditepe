#!/usr/bin/env bash
# Usage: ./grade.sh ex00        grade one exercise (prefix is enough)
#        ./grade.sh ex00 gdb    build with debug info and open it in gdb instead of grading
#        ./grade.sh all         grade every exercise, in order
cd "$(dirname "$0")" || exit 1
ulimit -c 0   # no vgcore.* / core dump files when a test crashes

EXERCISES=(
    ex00_sum_list
    ex01_nth_from_end
    ex02_delete_all
    ex03_stack
    ex04_balanced
    ex05_circular_queue
    ex06_merge_sorted
    ex07_dlist
    ex08_insert_after_max
    ex09_remove_not_in
    ex10_new_minimums
)
FORBIDDEN='#include *<(stack|queue|list|forward_list|vector|deque|array|algorithm|set|map)>'

grade() {
    local ex=$1 src="rendu/$1.cpp" forbidden=$FORBIDDEN
    [ "$ex" = ex10_new_minimums ] && forbidden=${FORBIDDEN/|vector/}   # this one returns a vector
    if [ ! -f "$src" ]; then
        echo "$ex: KO (missing $src)"; return 1
    fi
    if grep -nE "$forbidden" "$src"; then
        echo "$ex: KO (forbidden include)"; return 1
    fi
    if grep -nE '\bmain *\(' "$src"; then
        echo "$ex: KO (do not write main, the grader has its own)"; return 1
    fi

    local bin
    bin=$(mktemp)
    if ! g++ -std=c++17 -Wall -Wextra -Werror -g -O0 -o "$bin" "tests/$ex.cpp" 2> "$bin.log"; then
        echo "$ex: KO (compile error)"; head -20 "$bin.log"
        rm -f "$bin" "$bin.log"; return 1
    fi
    if [ "$2" = gdb ]; then
        gdb -q "$bin"; rm -f "$bin" "$bin.log"; return 0
    fi

    local run=()
    command -v valgrind > /dev/null && run=(valgrind -q --leak-check=full --errors-for-leak-kinds=definite,indirect --error-exitcode=42)
    timeout 10 "${run[@]}" "$bin"
    local rc=$?
    rm -f "$bin" "$bin.log"
    case $rc in
        0)   echo "$ex: OK"; return 0 ;;
        124) echo "$ex: KO (timeout: infinite loop?)" ;;
        42)  echo "$ex: KO (memory error or leak, see valgrind output above)" ;;
        1)   echo "$ex: KO" ;;  # the test printed what failed above
        *)   echo "$ex: KO (crashed, exit code $rc)" ;;
    esac
    return 1
}

if [ "$1" = "all" ]; then
    passed=0
    for ex in "${EXERCISES[@]}"; do
        grade "$ex" && passed=$((passed + 1))
    done
    echo "----"
    echo "Score: $passed / ${#EXERCISES[@]}"
    exit 0
fi

for ex in "${EXERCISES[@]}"; do
    if [ -n "$1" ] && [[ $ex == "$1"* ]]; then
        grade "$ex" "$2"; exit $?
    fi
done
echo "usage: ./grade.sh <exercise|all> [gdb]   e.g. ./grade.sh ex00 gdb"
printf '  %s\n' "${EXERCISES[@]}"
exit 2
