#!/usr/bin/python
# -*- coding=UTF-8 -*-

list1 = [1, 2, 3]
list2 = ["hello " + str(ele) + " right" for ele in list1]
print list2

print "***1***"
list3 = ['sequence  %d\n' %i for i in range(10)]
print list3

for i in range(len(list3)):
    print list3[i]

""""---illustration---
为了便于理解它，让我们从右向左看。li 是一个将要映射的 list。Python 循环遍历 li 中的每个元素。对每个元素均执行如下操作：首先临时将其值赋给变量 elem，然后 Python 应用函数 elem*2 进行计算，最后将计算结果追加到要返回的 list 中。 """

