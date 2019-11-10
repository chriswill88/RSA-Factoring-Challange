#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*""" this factors modual gets the first two factors of any number """*/

int main(int argc, char *argv[])
{
    char *ar = NULL, *ptr = "\0";
    size_t len = 0;
    FILE *fd;
    int r;
    long double num = 0, sq, i;

    //printf("%s\n", argv[1]);
    fd = fopen(argv[1], "r");
    if (fd == NULL || argc < 1)
        return (-1);
    while ((r = getline(&ar, &len, fd)) != -1)
    {
        printf("string ver -> %s\n", ar);
        num = strtold(ar, &ptr);
        printf("num ver --> %Lf\n", strtold(ar, &ptr));
        if (fmodl(num,2) == 0)
            printf("%.0Lf = %.0Lf * %d\n", num, num/2, 2);
        else
        {
            sq = sqrtl(num);

            //printf("the sq == %Lf\n", sq);
            //printf("the remainder = %Lf\n", fmodl(sq, 1));
            sq -= fmodl(sq, 1);
            if (fmodl(sq, 2))
                sq += 1;
            //printf("%Lf\n", sq);
            fflush(stdout);
            for (i = 3; i <= sq; i += 2)
            {
                if (fmod(num,i) == 0)
                {
                    printf("%.0Lf = %.0Lf * %.0Lf\n", num, num/i, i);
                    break;
                }
                if (fmod(num, sq - i) == 0)
                {
                    printf("%.0Lf = %.0Lf * %.0Lf\n", num, num/(sq - i), sq - i);
                    break;
                }
                if (fmod(num, sq + i) == 0)
                {
                    printf("%.0Lf = %.0Lf * %.0Lf\n", num, num/(sq + i), sq - i);
                    break;
                }
            }
        }
        
    }
    fclose(fd);
    if (ar)
        free(ar);
    return (0);
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