
dict = {'name':'miao', 'age':29}

print "age: %s" % dict.get('age')
print "sex: %s" % dict.get('sec', "None")

key = "name"
if key in dict:
    print "key: name is in dict"

print "***"
print "name" in dict
