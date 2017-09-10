#!/usr/bin/python3

import sys
import unittest

import class_1

class TestA(unittest.TestCase):
    
    def setUp(self):
        self.test_a = class_1.A(1)

    def test_func_a(self):
        self.assertEqual(1025, self.test_a.func_a())

if __name__ == '__main__':
    a = class_1.A(1)
    print(a.func_a())

    unittest.main()

