import threading
import time

exitFlag = 0
mutex = threading.Lock()

class MyThread(threading.Thread):
    def __init__(self, threadId, name, counter):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.counter = counter

    def run(self):
        print "Starting " + self.name
        mutex.acquire()
        print_time(self.name, self.counter, 5)
        mutex.release()
        print "Exiting " + self.name

def print_time(threadName, delay, counter):
    while counter:
        if exitFlag:
            threading.Thread.exit()
        time.sleep(delay)
        print "%s: %s" %(threadName, time.ctime(time.time()))
        counter -= 1

thread1 = MyThread(1, "thread-1", 1)
thread2 = MyThread(2, "thread-2", 2)

thread1.start()
thread2.start()

threads = []
threads.append(thread1)
threads.append(thread2)

for t in threads:
    t.join()

print "Exiting Main Thread"

