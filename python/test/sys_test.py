#-*-coding:UTF-8-*-

import sys
import os
import traceback

print __file__
os_path_abspath = os.path.abspath(__file__)
print "os.path.abspath: %s" %(os_path_abspath)
dirname, filename = os.path.split(os_path_abspath)
print "dirname: %s, filename: %s" %(dirname, filename)
os_path_pardir = os.path.pardir
print "os_path_abspath: %s" %(os_path_pardir)

print "-----------1------------"
home_dir = os.path.join(os.path.split(os.path.realpath(__file__))[0],os.path.pardir)
print "home_dir: %s" %(home_dir)

print "-----------2------------"
platform = sys.platform
print "platform: %s"%(platform)
flag = platform.startswith("win")
print flag

print "-----------3------------"
print "使用sys.exit()语句会抛出一个异常"
try:
    sys.exit(0)
except SystemExit:
    print "catch SystemExit"
except:
    print "catch other except:"
    traceback.print_exc()

print "-----------4------------"
#try:
#    if 1 == 1:
#        return
#except:
#    print "catch except"

