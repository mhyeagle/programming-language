#include <iostream>

#include <time.h>
#include <pthread.h>
#include <Python.h>

using namespace std;

void getcurrent() {
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    return;
}

static void* thread_func(void * arg) {
    PyObject* func_ptr = (PyObject*)(arg);
    PyEval_CallObject(func_ptr, NULL);
}

int main() {
    struct timespec start, end, cost_ns;

    Py_Initialize();
    getcurrent();

    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    PyObject * pArg = NULL;

    pModule = PyImport_ImportModule("compute");
    pFunc = PyObject_GetAttrString(pModule, "compute");
    //PyEval_CallObject(pFunc, NULL);

    clock_gettime(CLOCK_MONOTONIC, &start);

    pthread_t tid;
    pthread_create(&tid, NULL, &thread_func, pFunc);
    pthread_join(tid, NULL);
    
    clock_gettime(CLOCK_MONOTONIC, &end);

    Py_Finalize();

    if (end.tv_nsec < start.tv_nsec) {
        end.tv_sec -= 1;
        end.tv_nsec += 1000000000;
    }
    cost_ns.tv_sec = end.tv_sec - start.tv_sec;
    cost_ns.tv_nsec = end.tv_nsec - start.tv_nsec;

    cout << "time cost: " << endl;
    cout << cost_ns.tv_sec << endl;
    cout << cost_ns.tv_nsec << endl;

    return 0;
}
