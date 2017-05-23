#!/usr/bin/python
# -*- coding=UTF-8 -*-

import os
from ctypes import *

home_dir = os.path.split(os.path.realpath(__file__))[0]
print "os.path.realpath(__file__): " + os.path.realpath(__file__)
print "home_dir: " + home_dir

so_name = home_dir + "/libcpp_test.so"
print "so_name: " + so_name

#cpp_lib = cdll.LoadLibrary("./cpp_test.so")
cpp_lib = cdll.LoadLibrary(so_name)

print cpp_lib

cpp_output = cpp_lib.output

cpp_output()


