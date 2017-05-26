import json

data = {'a':1, 'b':2, 'x':3, 'c':4}

json_text = json.dumps(data, sort_keys=True, indent=4)

print "json_text: " 
print json_text

data_str = '{"a":1, "c":2, "b":3}'
json_obj = json.loads(data_str)
print "json_obj type: %s" %(type(json_obj))
print "a: %d" %(json_obj["a"])
print "c: %d" %(json_obj["c"])


