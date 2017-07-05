#!/usr/bin/python

from multiprocessing import Process, Manager

def f(d, l):
    d[1] = '1'
    d['2'] = 2
    d['hello'] = 'world'
    l.reverse()

if __name__=='__main__':
    manager = Manager()

    d = manager.dict()
    l = manager.list(range(10))

    p = Process(target = f, args = (d, l))
    p.start()
    p.join()

    print d
    print l

