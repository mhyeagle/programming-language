import ConfigParser

cf = ConfigParser.ConfigParser()

cf.read("test.conf")
secs = cf.sections()
print "sections:", secs

opts = cf.options("sec_a")
print "options of sec_a:", opts

kvs = cf.items("sec_a")
print "items of sec_a:", kvs

str_val1 = cf.get("sec_a", "a_key1")
print "sec_a's a_key1:", str_val1
int_val2 = cf.getint("sec_a", "a_key2")
print "sec_a's a_key2:", int_val2

cf.set("sec_b", "b_key3", "new++python")

'''cf.add_section("a_new_section")'''
cf.set("a_new_section", "new_key1", "1")

cf.write(open("test.conf", "w"))

