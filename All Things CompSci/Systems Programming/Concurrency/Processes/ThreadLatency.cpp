#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define LOOPCOUNT 100000

void *NullChild(void *) { }

int main(int argc, char **argv) {
    int forkcount = 0;
    struct timeval before, after;

    gettimeofday(&before, nullptr);  // once to warm up call path
    gettimeofday(&before, nullptr);  // once for real-sies
    
    while (1) {
        pthread_t thr;

        pthread_create(&thr, nullptr, &NullChild, nullptr);
        pthread_join(thr, nullptr);
        forkcount++;
        if (forkcount == LOOPCOUNT)
            break;
    }
    gettimeofday(&after, nullptr);

    float diff_us = (after.tv_sec - before.tv_sec) * 1000000.0;
    diff_us += (after.tv_usec - before.tv_usec);
    diff_us /= LOOPCOUNT;

    printf("microseconds per thread create: %f\n", diff_us);
    return EXIT_SUCCESS;
}