import os

USER_HOME = os.path.expanduser("~")
print USER_HOME
MODULE_DIR = os.sep.join([USER_HOME, "modules"])
print MODULE_DIR

print "-------------1-------------"
print os.path.realpath(__file__)
print os.path.split(os.path.realpath(__file__))
print "os.path.pardir: %s"%(os.path.pardir)
home_dir = os.path.join(os.path.split(os.path.realpath(__file__))[0], os.path.pardir)
print home_dir
 
print "-------------2-------------"
print os.path.pardir
