#!/usr/bin/python
# -*- coding=UTF-8 -*-
import logging

logging.basicConfig(level = logging.DEBUG,
        format = '%(asctime)s %(filename)s[line:%(lineno)d] %(levelname)s %(message)s',
        datefmt = '%a, %d %b %Y %H:%M%S',
        filename = './myapp.log',
        filemode = 'w')

logging.debug('This is debug message')
logging.info('This is info message')
logging.warning('This is warning message')
logging.error('This is error message')

print "***********1***********"
print "logging.info"
print eval("logging.DEBUG")


