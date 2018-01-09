#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printPartition(int * part, int length)
{
	int ind;
	for (ind = 0; ind < length - 1; ind ++)
	{
	printf("%d + ", part[ind]);
	}
	printf("%d\n", part[length - 1]);
}
void partition(int * part, int ind, int left)
{
	int val;
	if (left == 0)
	{
	printPartition(part, ind);
        return;
	}
	for (val = 1; val <= left; val ++)
	{
	part[ind] = val;
	partition(part, ind + 1, left - val);
//        printf("%d\n",val);
	}
}
int main(int argc, char * argv[])
{
	if (argc != 2) {
		printf("usage: q2 <number>\n");
		return EXIT_FAILURE;
	}
	int n = (int) strtol(argv[1], NULL, 10);
	if (n <= 0) {
		printf("must be a positive number\n");
		return EXIT_FAILURE;
	}
	int * arr;
	arr = malloc(sizeof(int) * n);
	partition(arr, 0, n);
	free (arr);
	return EXIT_SUCCESS;
}

