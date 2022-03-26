#!/bin/bash

make
valgrind --leak-check=full --error-exitcode=1 ./tema1
valgrind_error=$?

echo ""

score=0

begin_test='output_'
begin_result='reference/result_'
termination='.out'

arr=( "arrive_train" "leave_train" "add_train_car" "remove_train_cars" "move_train_cars" "find_express_train" "find_overload_train" "find_optimal_train" "find_heaviest_sequence_train" "order_train" "fix_overload_train" )
scores=( 5 5 5 5 10 5 5 5 15 15 15)

for i in ${!arr[@]}
do
    element=${arr[$i]}
    testFileName=$begin_test$element$termination
    resultFileName=$begin_result$element$termination
    result=$(diff $testFileName $resultFileName | wc -l)

    if [ -f $testFileName ] && [ -f $resultFileName ] && [ "$result" -eq "0" ]; then
        echo "Test ${arr[$i]}...........................passed"
        score=$((score+${scores[$i]}))
    else
        echo "Test ${arr[$i]}...........................failed"
    fi
done

echo ""

if [[ ${valgrind_error} -eq 0 ]]; then
    echo "Valgrind errors...........................passed"
    score=$((score+10))
else
    echo "Valgrind errors...........................failed"
fi

echo "                                      Total: $score"

make clean
