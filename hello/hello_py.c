/* ======================================================================================
   MODULE file
   This file

   ======================================================================================*/
#include <Python.h>           //must be the first thing included
#include "c-sources/hello.h"

//function declarations
static PyObject * hello_helloworld(PyObject *self, PyObject * args);

//this is the method table that links a python name to the c functions.
static PyMethodDef HelloMethods[] = {
      {"helloworld", hello_helloworld, METH_VARARGS, "Print hello string."},
      {NULL, NULL, 0, NULL}
};

//module definition structure
static struct PyModuleDef hello_py = {
   PyModuleDef_HEAD_INIT,
   "hello", /*name of the module*/
   NULL, /*spam doc, may be null*/
   -1, /*the module keeps state in global variables*/
   HelloMethods
};

//the init function
PyMODINIT_FUNC
PyInit_hello(void){
   return PyModule_Create(&hello_py);
}
// ======================================================================================
// Function wrappers
// ======================================================================================
static PyObject * hello_helloworld(PyObject *self, PyObject * args){
   char *input;
   char *result;
   PyObject *ret;

   //Parse arguments
   if(!PyArg_ParseTuple(args, "s", &input)){
      return NULL;
   }

   //return the actual function
   result = helloworld(input);
   return Py_BuildValue("s", result);
}
