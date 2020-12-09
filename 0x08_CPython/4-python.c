#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_string - Prints python string info
 * @p: module object
 */
void print_python_string(PyObject *p)
{
	printf("[.] string object info\n");

	if (((PyASCIIObject *)p)->state.ascii)
		printf("  type: compact ascii\n");
	else
		printf("  type: compact unicode object\n");

	printf("  length: %ld\n", ((PyASCIIObject *)p)->length);
	printf("  value: %ls\n", PyUnicode_AS_UNICODE(p));
}
