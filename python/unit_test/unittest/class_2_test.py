#!/usr/bin/python3

import sys
import unittest

import class_2

class TestB(unittest.TestCase):
    def setUp(self):
        self.test_b = class_2.B()

    def test_func_b(self):
        self.assertEqual(101, self.test_b.func_b())


if __name__ == '__main__':
    unittest.main()

