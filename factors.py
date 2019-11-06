#!/usr/bin/python3
from sys import argv
""" this factors modual gets the first two factors of any number """


def factor(num):
    """
        This factor function
        gets the factors of
        a number and
        prints them out
    """
    # num = int(line)
    if num == 0:
        i = 0
        print("{}={}*{}".format(num, i, num))
        return
    elif num == 1 or num == -1:
        i = 1
        print("{}={}*{}".format(num, i, int(num/i)))

    elif num % 2 == 0:
        i = 2
        print("{}={}*{}".format(num, i, int(num/i)))

    else:
        for i in range(3, int(num/2), 2):
            if num % i == 0:
                print("{}={}*{}".format(num, i, int(num/i)))
                return


with open(argv[1]) as f:
    for line in f:
        factor(int(line))
