import sys
import os

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

