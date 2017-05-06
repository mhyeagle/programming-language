#!/usr/bin/python3

import urllib3
import json
import time

my_headers = {'User-Agent':'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'}

http = urllib3.PoolManager()
response = http.request('GET', 'http://www.baidu.com', headers=my_headers)

print("response.data: {}".format(response.data))
print("response.status: {}".format(response.status))
print("response.header: {}".format(response.headers))


ticks = time.time()
print("start: {}".format(ticks))

try:
    r = http.request('GET', 'http://httpbin.org/ip', headers=my_headers, timeout=urllib3.Timeout(connect=1.0, read=2.0), retries=False)
    #print("r.status: {}".format(r.status))
except:
    print("unexpected error")
ticks = time.time()
print("end: {}".format(ticks))


