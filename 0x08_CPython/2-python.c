#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_bytes - Prints python bytes info
 * @p: module object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i = 0, size = (((PyVarObject *)(p))->ob_size);

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %zd\n", size);
	printf("  trying string: %s\n", ((PyBytesObject *)p)->ob_sval);

	size = size < 9 ? size + 1 : 10;
	printf("  first %zd bytes: ", size);
	for (i = 0; i < size; i++)
		printf("%.2x%c",
			   ((PyBytesObject *)p)->ob_sval[i], i + 1 == size ? '\n' : ' ');
}

/**
  * print_python_list - Print python list info
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
		element = ((PyListObject *)p)->ob_item[i];
		printf("Element %zd: %s\n", i, (char *)(element->ob_type)->tp_name);
		if (PyBytes_Check(element))
			print_python_bytes(element);
	}
}
