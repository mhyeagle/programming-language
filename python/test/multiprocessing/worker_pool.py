#!/usr/bin/python

from multiprocessing import Pool, TimeoutError
import time
import os

def f(x):
    return x*x

if __name__=='__main__':
    pool = Pool(processes=4)

    print pool.map(f, range(10))

    for i in pool.imap_unordered(f, range(20)):
        print i

    res = pool.apply_async(f, (20,))
    print res.get(timeout=1)

    res = pool.apply_async(os.getpid, ())
    print res.get(timeout=1)

    multiple_results = [pool.apply_async(os.getpid, ()) for i in range(4)]
    print [res.get(timeout=1) for res in multiple_results]

    res = pool.apply_async(time.sleep, (10,))
    try:
        print res.get(timeout=1)
    except TimeoutError:
        print "We lacked patience and get a multiprocessing. TimeoutError"


