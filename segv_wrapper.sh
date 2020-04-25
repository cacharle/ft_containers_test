#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Usage: $0 [runnable] [output file]"
    exit 1
fi

runnable=$1
output_file=$2
segv_status=139

$1 2>&1 > $2

if [ $? -eq $segv_status ]; then
    echo "Test Segfaulted: the last runned assertion was:"
    tail -n 1 $output_file
else
    python3 prettier.py < $output_file
fi

