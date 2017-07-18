import sys
import os
from multiprocessing import Process

def fork_func(func, news):
    print "in fork_func"
    func(news)
    for key in news:
        print key
        print news[key]

def main():
    home_dir = os.path.split(os.path.realpath(__file__))[0]
    print home_dir
    sys.path.append(home_dir)
    model_obj = __import__('plugin_A')
    class_refer = getattr(model_obj, 'AModel')
    obj = class_refer()
    news = {}
    p_func = getattr(obj, 'func')

    process_1 = Process(target=fork_func, args=(p_func, news))
    process_1.start()
    process_1.join()
#    p_func(news)
    print "***main***"
    news[0] = 'hello'
    for key in news:
        print key
        print news[key]

if __name__ == '__main__':
    main()

