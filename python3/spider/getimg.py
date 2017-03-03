#!/usr/bin/python3

import re
import urllib3

def getHtml(url):
    http = urllib3.PoolManager()
    response = http.request('GET', url)
    html = response.data.decode('utf-8')
    return html

def getImg(html):
    reg = r'src="(.+?\.jpg)" pic_ext'
    imgre = re.compile(reg)
    #imglist = imgre.findall('src=abcd.jpg pic_ext=')
    imglist = imgre.findall(html)
    return imglist

html = getHtml("http://tieba.baidu.com/p/2460150866")
#print(html)
print(getImg(html))

