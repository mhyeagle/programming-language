#!/usr/bin/python3

import os
import sys
import unittest
home_dir = os.path.split(os.path.realpath(__file__))[0]
sys.path.append(home_dir + "/unittest")
print("home_dir", home_dir)
print(sys.path)
import class_1_test
import class_2_test

def suite():
    modules_to_test = ('class_1_test',
                        'class_2_test')
    alltests = unittest.TestSuite()
    for module in map(__import__, modules_to_test):
        if hasattr(module, '__list_module__'):
            for module in module.__list_module__():
                alltests.addTest(unittest.findTestCases(module))
        else:
            alltests.addTest(unittest.findTestCases(module))

    return alltests


if __name__ == '__main__':
    unittest.main(defaultTest = 'suite')


