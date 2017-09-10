#!/bin/bash

coverage run test_all.py

coverage report --omit="*_test.py"

rm unittest/*.pyc
