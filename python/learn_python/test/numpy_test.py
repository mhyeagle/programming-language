#!/usr/bin/python
# -*- coding=UTF-8 -*-

import numpy as np

a = range(1000)
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

