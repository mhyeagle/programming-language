import threading
import time

class MyThread(threading.Thread):
    def __init__(self, id):
        threading.Thread.__init__(self)
        self.id = id

    def run(self):
        x = 0
        time.sleep(10)
        print self.id

if __name__ == "__main__":
    t1 = MyThread(999)
    '''
    t1.setDaemon()方法，主线程A中创建了子线程B，把主线程A设置成守护线程，只要主线程A运行结束，那么子线程B就一起退出；
    与join()方法相反
    setDaemon()必须在start()方法开始前执行
    '''
    t1.start()
    t1.join()
    
    for i in range(5):
        print i

