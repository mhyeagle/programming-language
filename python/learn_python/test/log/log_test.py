#!/usr/bin/python
# -*- coding=UTF-8 -*-
import logging
import logging.handlers
import time

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


print "***********2***********"

main_logger=logging.getLogger("main_logger")
main_logger.setLevel(logging.INFO)

file_hanler=logging.handlers.TimedRotatingFileHandler("test_log", when="H", interval=1, backupCount=168)
file_hanler.suffix="%Y-%m-%d_%H"
main_logger.addHandler(file_hanler)


main_logger.info('This is info message')
main_logger.warning('This is warning message')
main_logger.error('This is error message')

while 1:
    time.sleep(1)
    main_logger.info('info')

