#!/usr/bin/python3

f = open('lines')

i = 0
for line in f:
    print('line{}: {}'.format(i, line))
    i = i+1

i = 0
f.seek(0, 0)
line = f.readline()
while(line):
    print('readline{}: {}'.format(i, line))
    line = f.readline()
    i = i+1

sum = 0
f.seek(0, 0)
for line in f:
    sum = sum + int(line)

print("lines sum: ", sum)


f.close()
