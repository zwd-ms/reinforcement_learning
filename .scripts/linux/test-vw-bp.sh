#!/bin/bash

set -e
set -x

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR=$SCRIPT_DIR/../../

cd $REPO_DIR/external_parser/build

# Run unit test suite for external parser

export CTEST_OUTPUT_ON_FAILURE=1
make test

cd vw_binary_parser/vowpalwabbit

./vw --extra_metrics metrics.json -d ../../../unit_tests/test_files/valid_joined_logs/cb_simple.log --binary_parser --cb_explore_adf

python -m json.tool metrics.json
