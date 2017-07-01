#!/usr/bin/python
# -*- coding: UTF-8 -*-

class Employee:
    '员工基类'
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1

    def displayCount(self):
        print "employee num: %d" %(empCount)

    def displayEmployee(self):
        print "employee name: %s, salary: %d" %(self.name, self.salary)

print "Employee.__doc__:", Employee.__doc__
print "Employee.__name__:", Employee.__name__
print "Employee.__module__:", Employee.__module__
print "Employee.__bases__:", Employee.__bases__
print "Employee.__dict__:", Employee.__dict__

print "__name__: ", __name__

