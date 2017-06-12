
dic = {'name':'miao', 'age':29}

print "age: %s" % dic.get('age')
print "sex: %s" % dic.get('sec', "None")

key = "name"
if key in dic:
    print "key: name is in dict"

print "***"
print "name" in dic

print "***items***"
print dic.items()
print "***iteritems***"
print dic.iteritems()

