#!/usr/bin/python
# -*- coding: UTF-8 -*-

Money = 200
def AddMoney():
    #需要在当前函数中增加 global Money的声明
    global Money
    Money = Money + 1

print Money
AddMoney()
print Money

