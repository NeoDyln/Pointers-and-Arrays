#include <stdio.h>

/**
 *main - Shows size of data types
 *
 *
 *Return: Always 0
 */

int main(void)
{
	int c;
	int *p = &c;
	printf("Size of char is: %lu bytes\n", sizeof(char));
	printf("Size of int is: %lu bytes\n", sizeof(int));
	printf("Size of long int is: %lu bytes\n", sizeof(long int));
	printf("Size of float is: %lu bytes\n", sizeof(float));
	printf("Size of double is: %lu bytes\n", sizeof(double));
	printf("Address of variable c is %p\n", &c);
	printf("Size of a pointer is %lu \n", *p);
	return (0);
}
