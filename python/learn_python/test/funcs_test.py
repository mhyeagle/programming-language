x = 1
num = eval("x+1")
print num

a = eval
print a

print "**********0***********"

def func1(x, y):
    return x+y

def func2(d):
    for x, y in d.items():
        print x, " ", y

t1 = (1, 2)
dic = {"name":"miao", "sex":"male"}

print "************1************"
func1(*t1)
func2(dic)

