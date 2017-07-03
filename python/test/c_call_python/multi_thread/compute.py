#!/usr/bin/python

def compute():
    sum = 0
    for i in xrange(100000000):
        sum += i
    print sum

if __name__ == "__main__":
    compute()

