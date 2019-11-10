#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - this program is designed to find smaller primes for a number
 * @argc: not used
 * @argv: takes the file name in from commandline
 * Description: this is the c version of factors.py (which can be found in this dir)
 * this function pretty much works but strtol is inaccurate with very big numbers so
 * so it doesnt work with numbers whose digits are over 21 digits long
 * Returns 0 if succesful and -1 if failed
 */
int main(int argc, char *argv[])
{
	char *ar = NULL, *ptr = "\0";
	size_t len = 0;
	FILE *fd;
	long double num = 0, sq, i;

	/*printf("%s\n", argv[1]);*/
	fd = fopen(argv[1], "r");
	if (fd == NULL || argc < 1)
		return (-1);
	while ((getline(&ar, &len, fd)) != -1)
	{
		/*printf("string ver -> %s\n", ar);*/
		num = strtold(ar, (char **)NULL);
		/*printf("num ver --> %Lf\n", strtold(ar, (char**)NULL));*/
		if (fmodl(num, 2) == 0)
			printf("%.0Lf = %.0Lf * %d\n", num, num / 2, 2);
		else
		{
			sq = sqrtl(num);

			/*printf("the sq == %Lf\n", sq);*/
			/*printf("the remainder = %Lf\n", fmodl(sq, 1));*/
			sq -= fmodl(sq, 1);
			if (fmodl(sq, 2))
				sq += 1;
			/*printf("%Lf\n", sq);*/
			fflush(stdout);
			for (i = 3; i <= sq; i += 2)
			{
				if (fmod(num, i) == 0)
				{
					printf("%.0Lf=%.0Lf*%.0Lf\n", num, num / i, i);
					break;
				}
				if (fmod(num, sq - i) == 0)
				{
					printf("%.0Lf=%.0Lf*%.0Lf\n", num, num / (sq - i), sq - i);
					break;
				}
				if (fmod(num, sq + i) == 0)
				{
					printf("%.0Lf=%.0Lf*%.0Lf\n", num, num / (sq + i), sq - i);
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
