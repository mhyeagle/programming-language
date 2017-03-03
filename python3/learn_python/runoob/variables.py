#!/usr/bin/python3

a = b = c = 1

print(a)
print(b)
a = 2
print(c)
print("a =", a)
print("a.type:", type(a))

str = "island"
print(str[0:3])
print("str[0:-1]", str[0:-0])
print(str * 2);
print(r"hello\nword")
print('''multi
    line
    string''')
print('''python string cannot assigned, str[3]='a' will be error''')
print('''type of number of list can be diffrence''')
list = [1, 2, 'hello', 4.5]
print(list)
print("""number of list cann assigned, list[1] = 1 while success""")
list[1:-1] = []
print('''list[1:-1]=[] delete elements of list''')
print(list)

tuple__ = (1,2,3)
print(tuple__)
print("""elements in tuple cannot be changed""")

set__ = set('abcdefg')
set2 = set('xyz')
print(set__)
set3 = set__ | set2
print(set3)

dict__ = {}
dict__[1] = "one"
dict__['hello'] = 'world'
print(dict__)
print(dict__.keys())
print(dict__.values())
dict__.clear()

print('''int to other type, str(x) for example''')

a = 1
b = 2
print('a/b = float', a/b)
print('a//b = int', a//b)

print('a and b:', (a and b))

str = "hello world"
print(str)
str = str[0:6] + 'rookie'
print(str)

list__ = [1,2,3,4,5]
it = iter(list__)
for x in it:
    print(x, end=",\n")

it = iter(list__)
print(next(it))
print("output next(it): {}".format(next(it)))
