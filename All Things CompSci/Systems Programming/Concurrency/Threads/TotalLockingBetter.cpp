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

static pthread_mutex_t sum_lock;  // global, accessible by all threads

// NEW: struct to pass arguments to thread_main
struct thd_arg {
    int *sum_ptr;
    int num;
};

// increment sum_total LOOP_NUM times in an atomic fashion
void *thread_main(void *arg) {
    // NEW: cast arguments back into struct
    struct thd_arg *a = reinterpret_cast<struct thd_arg *>(arg);
    int local_sum = 0;
    
    for (int i = 0; i < a->num; i++) {
        local_sum++;
    }
    pthread_mutex_lock(&sum_lock);
    *a->sum_ptr += local_sum;
    pthread_mutex_unlock(&sum_lock);
    // NEW: delete dynamically-allocated struct
    delete a;
    return nullptr;  // return type is a pointer
}


int main(int argc, char** argv) {
    // NEW: made sum_total a local variable
    int sum_total = 0;
    pthread_t thds[NUM_THREADS];  // array of thread ids
    pthread_mutex_init(&sum_lock, nullptr);  // initialize mutex to default

    // create threads to run thread_main()
    for (int i = 0; i < NUM_THREADS; i++) {
        struct thd_arg *args = new struct thd_arg;
        args->sum_ptr = &sum_total;
        args->num = LOOP_NUM;
        if (pthread_create(&thds[i], nullptr, &thread_main, args) != 0) {
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