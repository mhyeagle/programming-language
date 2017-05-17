#!/usr/bin/python
# -*- coding: UTF-8 -*-

class Rectangle:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Rectangle(self.x + other.x, self.y + other.y)

    def output(self):
        print "object x:", self.x, " y:", self.y
    
r1 = Rectangle(10, 20)
r2 = Rectangle(10, -1)

r3 = r1 + r2
print r3
#下面这个函数没有返回值，所以输出时会显示一个None
print r3.output()
print "***"

