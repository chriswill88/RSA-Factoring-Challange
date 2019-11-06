#!/usr/bin/python3
from sys import argv
import time
""" this factors modual gets the first two factors of any number """


def factor(line=""):
    """
        This factor function
        gets the factors of
        a number and
        prints them out
    """
    num = int(line)
    if num % 2 == 0:
        i = 2
    else:
        for i in range(3, num, 2):
            if num % i == 0:
                break
    print("{}={}*{}".format(num, i, int(num/i)))


with open(argv[1]) as f:
    for line in f:
        factor(line)
