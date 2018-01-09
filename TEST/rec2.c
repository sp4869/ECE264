#include <stdio.h>
#include <stdlib.h>
int f(int n)
{
	int i;
	int sum = 0;
	if (n == 1)
	{
		return 1;
	}
	for (i = 1; i < n; i ++)
	{
		sum += f(n - i);
	}
	sum ++;
	return sum;
}
int main(int argc, char * argv[])
{
	int n;
	if (argc < 2)
	{
		printf("need one positive integer.\n");
		return EXIT_FAILURE;
	}
	n = (int) strtol(argv[1], NULL, 10);
	if (n <= 0)
	{
		printf("need one positive integer.\n");
		return EXIT_FAILURE;
	}
	printf("f(%d) = %d.\n", n, f(n));
	return EXIT_SUCCESS;
}


