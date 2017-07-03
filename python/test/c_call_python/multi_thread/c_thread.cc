#include <iostream>
#include <string>

#include <unistd.h>
#include <pthread.h>

using namespace std;

static void* thread_func(void* arg) {
    int seconds = *((int*)arg);
    pthread_t threadid = pthread_self();
    for(int i = 0; i < seconds; ++i) {
        cout << "thread: " << threadid << " time: " << i << endl;
        sleep(1);
    }
}

int main() {
    pthread_t tids[10];
    int turn = 5;
    for(int i = 0; i < 10; ++i) {
        pthread_create(&tids[i], NULL, &thread_func, &turn);
    }

    for(int i = 0; i < 10; ++i) {
        pthread_join(tids[i], NULL);
    }

    return 0;
}
