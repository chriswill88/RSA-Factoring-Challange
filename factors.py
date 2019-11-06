#!/usr/bin/python3
from sys import argv
import math
""" this factors modual gets the first two factors of any number """


def factor(num):
    """
        This factor function
        gets the factors of
        a number and
        prints them out
    """
    if num % 2 == 0:
        i = 2
        print("{}={}*{}".format(num, i, int(num/i)))
    else:
        sq = math.sqrt(num)
        if sq % 2 == 0:
            print("{}={}*{}".format(num, sq, int(num/sq)))
            return
        sq = int(sq) + 1
        for i in range(3, sq, +2):
            if num % i == 0:
                print("{}={}*{}".format(num, i, int(num/i)))
                return
            if num % (sq + i) == 0:
                print("{}={}*{}".format(num, sq + i, int(num/i)))
                return
            if num % (sq - i) == 0:
                print("{}={}*{}".format(num, sq - i, int(num/i)))
                return


with open(argv[1]) as f:
    for line in f:
        factor(int(line))
