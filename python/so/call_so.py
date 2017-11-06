from ctypes import *

test = cdll.LoadLibrary("./libtest.so")
print test
testpy = test.testFunc
testpy.argtype = c_char_p
testpy.restype = c_char_p
ss = "hello python call so"
res_str = testpy(ss)
print res_str

print "***"
testpy1 = test.testFunc1
num = 1024
res = testpy1(num)
print res

