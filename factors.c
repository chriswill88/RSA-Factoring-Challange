#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*""" this factors modual gets the first two factors of any number """*/


void main(int argc, char *argv[])
{
    char *ar = NULL, *ptr;
    size_t len = 0;
    FILE *fd;
    long double num, sq, i;

    printf("%s\n", argv[1]);
    fd = fopen(argv[1], "r");
    if (fd < 0)
        return;
    while (getline(&ar, &len, fd) != -1)
    {
        printf("%s", ar);
        num = strtol(ar, &ptr, 10);
        printf("%Lf\n", num);
        if (fmodl(num,2) == 0)
            printf("%Lf = %Lf * %d\n", num, num/2, 2);
        else
        {
            for (i = 3; i * i <= num; i += 2)
            {
                printf("%Lf, %Lf", i, num);
                if (fmod(num,i) == 0)
                    printf("%Lf = %Lf * %Lf\n", num, num/i, i);
                    break;
            }
        }
        
    }
    fclose(fd);
    if (ar)
        free(ar);
}
/**
    if num % 2 == 0:
        i = 2   
        print("{}={}*{}".format(num, int(num/i), i))
    else:
        sq = math.sqrt(num)
        if sq % 2 == 0:
            print("{}={}*{}".format(num, sq, int(num/sq)))
            return
        sq = int(sq) + 1
        for i in range(3, sq, +2):
            if num % i == 0:
                print("{}={}*{}".format(num, int(num/i), i))
                return
            if num % (sq + i) == 0:
                print("{}={}*{}".format(num, int(num/i), sq + i))
                return
            if num % (sq - i) == 0:
                print("{}={}*{}".format(num, int(num/i), sq - 1))
                return


with open(argv[1]) as f:
    for line in f:
        factor(int(line))
*/