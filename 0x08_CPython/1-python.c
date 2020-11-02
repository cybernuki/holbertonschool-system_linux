#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
  * print_python_list_info - Print python list info
  * @p: modulo object
  */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, size = (((PyVarObject *)(p))->ob_size);
	Py_ssize_t allocated = (((PyListObject *)(p))->allocated);
	PyObject *element;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %zd\n", size);
	printf("[*] Allocated = %zd\n", allocated);

	for (i = 0; i < size; i++)
	{
		element = PyList_GetItem(p, i);
		printf("Element %zd: %s\n", i, (char *)(element->ob_type)->tp_name);
	}
}
