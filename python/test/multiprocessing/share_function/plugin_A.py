import sys
import os

class AModel(object):
    def __init__(self):
        self.__num_list = [1, 2, 3]

    def func(self, news):
        for i in self.__num_list:
            news[1] = "one"
            news[2] = "two"
            news[3] = "three"

if __name__ == "__main__":
    news_1 = {}
    obj = AModel()
    obj.func(news_1)
    for key in news_1:
        print key
        print news_1[key]

