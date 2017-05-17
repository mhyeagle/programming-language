import Queue
import threading
import time

exitFlag = 0

class myThread(threading.Thread):
    def __init__(self, threadID, name, queue):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.queue = queue

    def run(self):
        print "Starting " + self.name
        process_data(self.name, self.queue)
        print "Exiting " + self.name

queueLock = threading.Lock()
workQueue = Queue.Queue(10)

def process_data(threadName, queue):
    while not exitFlag:
        queueLock.acquire()
        if not workQueue.empty():
            data = queue.get()
            queueLock.release()
            print "%s processing %s" %(threadName, data)
        else:
            queueLock.release()
        time.sleep(1)

threadList = ["thread-1", "thread-2", "thread-3"]
nameList = ["one", "two", "three", "four", "five"]
threads = []

threadID = 1
for tName in threadList:
    thread = myThread(threadID, tName, workQueue)
    thread.start()
    threads.append(thread)
    threadID += 1

queueLock.acquire()
for word in nameList:
    workQueue.put(word)
queueLock.release()

while not workQueue.empty():
    pass

exitFlag = 1

for t in threads:
    t.join()

print "Exiting Main Thread"

