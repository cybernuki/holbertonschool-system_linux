#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_int - Prints python integers info
 * @p: module object
 */
void print_python_int(PyObject *p)
{
	unsigned long number = 0;
	ssize_t i = 0, size = 0;
	int shift = 0;

	if (!PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		return;
	}

	size = ((PyVarObject *)p)->ob_size;
	size = size < 0 ? -size : size;
	if (size == 3 && (((PyLongObject *)p)->ob_digit[2] > 0xf || size > 3))
	{
		printf("C unsigned long int overflow\n");
		return;
	}
	for (i = 0; i < size; i++)
	{
		shift = PyLong_SHIFT * i;
		unsigned long sub =
			((unsigned long)((PyLongObject *)p)->ob_digit[i]) * (1UL << (shift));
		number += sub;
	}
	if (size < 0)
		printf("-");
	printf("%lu\n", number);
}
