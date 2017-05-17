import thread
import time

def thread_func(threadName, delay):
    count = 0
    while count < 5:
        time.sleep(delay)
        count += 1
        print "%s, %s" %(threadName, time.ctime(time.time()))

try:
    thread.start_new_thread(thread_func, ("thread-1", 2, ))
    thread.start_new_thread(thread_func, ("thread-2", 1, ))
except:
    print "Error: unable to start thread"

while 1:
    pass

