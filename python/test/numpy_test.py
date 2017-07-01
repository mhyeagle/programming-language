#!/usr/bin/python
# -*- coding=UTF-8 -*-

import numpy as np
import random
import time

a = range(100000)
print a
random.shuffle(a)
print "after shuffle:"
print a

max_a = np.max(a)
min_a = np.min(a)
mean_a = np.mean(a)
a_99 = np.percentile(a, 99)
a_999 = np.percentile(a, 99.9)

print "max_a: " + str(max_a)
print "min_a: " + str(min_a)
print "mean_a: " + str(mean_a)
print "a_99: " + str(a_99)
print "a_999: " + str(a_999)

print '******time cost******'
begin_time_s = time.time()
for i in range(10, 100, 1):
    print np.percentile(a, i)
end_time_s = time.time()
print "sort 90 times: cost seconds"
print end_time_s - begin_time_s

random.shuffle(a)
begin_time_s = time.time()
a.sort()
end_time_s = time.time()
print "sort one time cost second:"
print end_time_s - begin_time_s

