#!/usr/bin/python3

import sys

class B:
    __num = 10

    def __init__(self, num=1):
        self.__num = num

    def func_b(self):
        self.__num += 100
        return self.__num

def main():
    b = B(6)
    print(b.func_b())

if __name__ == '__main__':
    main()

