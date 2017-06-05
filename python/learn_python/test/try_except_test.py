#!/usr/bin/python
# -*- coding: UTF-8 -*-

try:
    fh = open("testfile", "w")
    fh.write("testfile writed by python program\n")
except IOError:
    print "Error: file not found"
else:
    fh.close()
    print "write to file success"

print "*********1**********"

def myException(level):
    if level < 1:
        raise Exception("invalid level!", level)

try:
    myException(0)
#except "invalid level!":
except:
    print 1
else:
    print 2

print "*********2**********"

try:
    fh = open("no_exist_file")
    fh.write("no exist\n");
except Exception as e:
    print e

