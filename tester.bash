#!/bin/bash

# This script is used to test the program

run_test_case() {
    echo "Test case $1"
    MAX=0
    MIN=10000000
    AVG=0
    ITER=$2
    N=$1
    MAX_ARGS=""
    ABOVE_5500_COUNT=0
    
    # Create a temporary directory to store outputs
    TMP_DIR=$(mktemp -d)
    
    # Function to run a single test iteration
    run_iteration() {
        local iter=$1
        local ARG=$(seq -1000 1000 | shuf -n $N)
        local OPS=$(./push_swap $ARG | wc -l | tr -d '[:space:]')
        local OK=$(./push_swap $ARG | ./checker_linux $ARG | tr -d '[:space:]')

        echo "$OPS" > "$TMP_DIR/ops_$iter"
        echo "$ARG" > "$TMP_DIR/arg_$iter"
        echo "$OK" > "$TMP_DIR/ok_$iter"
    }

    export -f run_iteration
    export TMP_DIR MAX MIN MAX_ARGS AVG N

    # Run the iterations in parallel
    seq 1 $ITER | xargs -n 1 -P 8 bash -c 'run_iteration "$@"' _

    # Process results
    for file in $TMP_DIR/ops_*; do
        if [ -f "$file" ]; then
            local iter=$(basename $file | cut -d'_' -f2)
            local OPS=$(cat "$file")
            local ARG=$(cat "$TMP_DIR/arg_$iter")
            local OK=$(cat "$TMP_DIR/ok_$iter")
            AVG=$((AVG + OPS))

            if [ "$OPS" -gt "$MAX" ]; then
                MAX=$OPS
                MAX_ARGS="Max: $OPS | $(echo $ARG | tr -d '\n')"
            fi

            if [ "$OPS" -lt "$MIN" ]; then
                MIN=$OPS
            fi

            if [ "$OPS" -gt 5500 ]; then
                ABOVE_5500_COUNT=$((ABOVE_5500_COUNT + 1))
            fi

            if [ "$OK" != "OK" ]; then
                echo "================================"
                echo "Error"
                echo "Args: $ARG"
                echo "Ops: $OPS"
                echo "Checker: $OK"
                echo "================================"
            fi
        fi
    done

    AVG=$((AVG / ITER))
    echo "Iterations: $ITER"
    echo "Max: $MAX"
    echo "Min: $MIN"
    echo "Average: $AVG"
    echo "--------------------------------"
    echo "Max Args: $MAX_ARGS"
    echo "--------------------------------"
    if [ "$N" -eq 500 ]; then
        echo "Number of tests with OPS > 5500: $ABOVE_5500_COUNT"
        echo "--------------------------------"
    fi
    echo ""
    
    # Clean up
    rm -rf "$TMP_DIR"
}

run_test_case 1 10
run_test_case 2 10
run_test_case 3 200
run_test_case 5 200
run_test_case 50 100
run_test_case 100 1000
run_test_case 500 1000