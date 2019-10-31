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
    for i in range(2, num):
        if num % i == 0:
            print("{}={}*{}".format(num, i, int(num/i)))
            return


with open(argv[1]) as f:
    for line in f:
        factor(line)
