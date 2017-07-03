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

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: ./a.out num" << endl;
        exit(1);
    }
    
    int thread_num = atoi(argv[1]);
    cout << "thread number: " << thread_num << endl;

    struct timespec start, end, cost_ns;
    pthread_t tids[thread_num];

    Py_Initialize();
    getcurrent();

    PyObject * pModule = NULL;
    PyObject * pFunc = NULL;
    PyObject * pArg = NULL;

    pModule = PyImport_ImportModule("compute");
    pFunc = PyObject_GetAttrString(pModule, "compute");
    //PyEval_CallObject(pFunc, NULL);

    clock_gettime(CLOCK_MONOTONIC, &start);

    for(int i = 0; i < thread_num; ++i) {
        pthread_create(&tids[i], NULL, &thread_func, pFunc);
    }
    for(int i = 0; i < thread_num; ++i) {
        pthread_join(tids[i], NULL);
    }

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
