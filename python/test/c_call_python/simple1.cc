#include <stdio.h>
#include <Python.h>

void getpythonenv() {
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    PyRun_SimpleString("import numpy");
}

int main(int argc, char* argv[]) {
    Py_Initialize();
    getpythonenv();
    
    PyObject *pModule = NULL;
    PyObject *pFunc = NULL;
    PyObject *pArg = NULL;

    pModule = PyImport_ImportModule("demo");
    if (pModule == NULL) {
        printf("pModule is NULL\n");
        exit(-1);
    }
    pFunc = PyObject_GetAttrString(pModule, "print_arg");
    if (pFunc == NULL) {
        printf("get python function print_arg is null!\n");
        exit(-1);
    }
    pArg = Py_BuildValue("(s)", "hello python");
    PyEval_CallObject(pFunc, pArg);

    Py_Finalize(); 

    return 0;
}
