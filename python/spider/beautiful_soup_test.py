#!/usr/bin/python3

from bs4 import BeautifulSoup
import bs4

html = """
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title" name="dromouse"><b>The Dormouse's story</b></p>
<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1"><!-- Elsie --></a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>
<p class="story">...</p>
"""
#open file below
#soup = BeautifulSoup(open('index.html'))

soup = BeautifulSoup(html, "lxml")
print(soup.prettify())

print('----------------title-----------------')
print("soup.title: ", soup.title)
print("type of soup.title: ", type(soup.title))
print("soup.title.name: ", soup.title.name)
print("soup.title.attrs: ", soup.title.attrs)
print('----------------head-----------------')
print("soup.head: ", soup.head)
print("type of soup.head: ", type(soup.head))
print("soup.head.name: ", soup.head.name)
print("soup.head.attrs: ", soup.head.attrs)
print("soup.head.contents: ", soup.head.contents)
print("soup.head.children: ", soup.head.children)
for x in soup.head.children:
    print(x)
print('----------------a-----------------')
print("soup.a: ", soup.a)
print("type of soup.a: ", type(soup.a))
print("soup.a.name: ", soup.a.name)
print("soup.a.attrs: ", soup.a.attrs)
print("soup.a.string:", soup.a.string)
print("type of soup.a.string: ", type(soup.a.string))
if type(soup.a.string)==bs4.element.Comment:
    print(soup.a.string)
print('----------------p-----------------')
print("soup.p: ", soup.p)
print("type of soup.p: ", type(soup.p))
print("soup.p.name: ", soup.p.name)
print("soup.p.attrs: ", soup.p.attrs)
print("soup.p['class']: ", soup.p['class'])
sg = soup.p.get('class')
print("soup.p.get('class'): ", sg)
soup.p['class'] = 'newClass'
print("soup.p['class']: ", soup.p['class'])
print("soup.p.string: ", soup.p.string)
print("type of soup.p.string: ", type(soup.p.string))

print('----------------body-----------------')
print("soup.body: ", soup.body)
print("type of soup.body: ", type(soup.body))
for x in soup.body.children:
    print(x)

print('----------------body-----------------')
for x in soup.body.descendants:
    print(x)

