#!/usr/bin/python3

import re

m = re.match('foo', 'food is precise')
if m is not None:
    print(m.group())

m = re.match('foo', 'my food is precise')
if m is not None:
    print(m.group())
else:
    print("m is empty")

m = re.search('foo', 'my food is food precise')
if m is not None:
    print(m.group())
else:
    print("m is empty")

search_str = 'abc|def'
m = re.search(search_str, 'my food is iabc food precise')
if m is not None:
    print(m.group())
else:
    print("m is empty")

pattern_str = '\w+@(\w+\.)?\w+\.com'
target_str = 'mhyeagle@123github.com'
m = re.match(pattern_str, target_str)
if m is not None:
    print(m.group())
else:
    print("m is empty")

pattern_str = '\d'

pattern_str = '(\w\w\w)-(\d\d\d)'
target_str = 'abc-123'
m = re.match(pattern_str, target_str)
if m is not None:
    print("m.groups() output is:{}".format(m.groups()))
    print("m.group(0) output is:{}".format(m.group(0)))
    print(m.group(1))
    print(m.group(2))

pattern_str = r'\bthe'
target_str = 'hello the world'
m = re.search(pattern_str, target_str)
if m is not None:
    print("first: {}".format(m.group()))

print("------------1-------------")
s = "This and that"
n = re.findall(r'th\w+ and th\w+', s, re.I)
print("result 1: {}".format(n))

print("------------2-------------")
pattern_str = 'car'
target_str = 'car car car'
m = re.findall(pattern_str, target_str)
print("result 2: {}".format(m))

print("------------3-------------")
pattern_str = r'(this=".*?\.jpg)" ok'
target_str = 'ming this="hello.jpg" ok ming'
m = re.findall(pattern_str, target_str)
print("result 3: {}".format(m))

print("------------4-------------")
pattern_str = r'hello'
target_str = 'hello world!'
pattern_obj = re.compile(pattern_str)
m = re.match(pattern_obj, target_str)
print("result 4: {}".format(m.group()))
print("m.string: {}".format(m.string))
print("m.re: {}".format(m.re))
print("m.pos: {}".format(m.pos))
print("m.endpos: {}".format(m.endpos))
print("m.lastindex: {}".format(m.lastindex))
print("m.lastgroup: {}".format(m.lastgroup))

print("------------5-------------")
pattern_str = r'\d+'
target_str = 'one1two2three3four'
pattern_obj = re.compile(pattern_str)
n = re.split(pattern_obj, target_str)
print("m.split: {}".format(n))

print("------------6-------------")
n = re.findall(pattern_obj, target_str)
print("m.findall: {}".format(n))

print("------------7-------------")
for i in re.finditer(pattern_obj, target_str):
    print(i.group())

print("------------8-------------")
pattern_str = r'(\w+) (\w+)'
target_str = 'i say, hello world, miao hongyuan'
pattern_obj = re.compile(pattern_str)
r = re.sub(pattern_obj, r'\2 \1', target_str)
print('result: {}'.format(r))
def sub_func(m):
    return m.group(1).title() + ' ' + m.group(2).title()
r = re.sub(pattern_obj, sub_func, target_str)
print('result: {}'.format(r))
l = re.subn(pattern_obj, sub_func, target_str)
print('subn result: {}'.format(l))

