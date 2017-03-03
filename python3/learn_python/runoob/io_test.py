#!/usr/bin/python3

str__ = str(1/7)
print(str__)
str__ = repr(1/7)
print(str__.rjust(4))

print('{}网址:{}'.format('helo', 'world'))
print('{}网址:{}'.format('helo', 1024))

f = open('test_io_file', 'a')
f.write("hello\n")
f.close()

f = open('test_io_file')
for line in f:
    print(line, end=' ')
f.close()

f = open('test_io_file', 'w')
#write content must be string
value = 4
s = str(value)
print(s)
f.write(s)
f.close()


