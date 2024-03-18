// Sample code that demonstrates using pthread mutex synchronization.
// from the same shared global variable in Static Data.
// Interleaving of reads and writes will sometimes cause printed sum to be less
// than expected.
//
// Remember to compile with -pthread

#include <pthread.h>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

const int NUM_THREADS = 50;
const int LOOP_NUM = 10000;

static int sum_total = 0;
static pthread_mutex_t sum_lock;  // global, accessible by all threads


// increment sum_total LOOP_NUM times in an atomic fashion
void *thread_main(void *arg) {
    for (int i = 0; i < LOOP_NUM; i++) {
        pthread_mutex_lock(&sum_lock);
        sum_total++;
        pthread_mutex_unlock(&sum_lock);
    }
    return nullptr;  // return type is a pointer
}


int main(int argc, char** argv) {
    pthread_t thds[NUM_THREADS];  // array of thread ids
    pthread_mutex_init(&sum_lock, nullptr);  // initialize mutex to default

    // create threads to run thread_main()
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&thds[i], nullptr, &thread_main, nullptr) != 0) {
            cerr << "pthread_create failed" << endl;
        }
    }

    // wait for all child threads to finish
    // (children may terminate out of order, but cleans up in order)
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(thds[i], nullptr) != 0) {
            cerr << "pthread_join failed" << endl;
        }
    }

    // print out the final sum (expecting NUM_THREADS * LOOP_NUM)
    cout << "Total: " << sum_total << endl;

    pthread_mutex_destroy(&sum_lock);  // destroy the mutex to clean up
    return EXIT_SUCCESS;
}