#!/usr/bin/python3

import sys

class A:
    __num = 0

    def __init__(self, num=0):
        self.__num = num

    def func_a(self):
        self.__num += 1024
        return self.__num

def main():
    a = A(10)
    num = a.func_a()
    print(num)

if __name__ == '__main__':
    main()

