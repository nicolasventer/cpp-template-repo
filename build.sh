#!/usr/bin/env bash

cmake --build build "$@" || exit $?

cp -f "build/math" .
