#include <stdio.h>     // for sscanf, fprintf, perror
#include <stdlib.h>    // for malloc, exit, EXIT_SUCCESS, EXIT_FAILURE
#include <stdint.h>    // for int32_t
#include <inttypes.h>  // for SCNd32, PRId32
#include <errno.h>     // for EINTR
#include <fcntl.h>     // for open, O_RDONLY
#include <unistd.h>    // for read, close

// Use POSIX file I/O to read n bytes from a file and print
// them to stdout (using C library printf for output).

// Print out the usage of the program and exit.
void Usage(void);


int main(int argc, char** argv) {
    int32_t fd, n, bytes_left, result;
    char* buf;

    // input checking (# args, 2nd arg is a positive number)
    if ( (argc != 3) || (sscanf(argv[2], "%" SCNd32, &n) != 1) || (n <= 0) )
    Usage();

    // open input file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    // allocate buffer for requested number of bytes
    buf = (char*) malloc((n+1)*sizeof(char));
    if (buf == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // attempt to read in n bytes using POSIX read() with error handling
    // note: there are multiple ways of adjusting pointers and keeping
    // track of the offset in the buffer where the next chunk of data
    // should be stored when read.  This is one way to do it, but it is
    // also possible to do arithmetic on the pointer itself to update the
    // "where to store next" location, etc.
    bytes_left = n;
    while (bytes_left > 0) {
        result = read(fd, buf + (n - bytes_left), bytes_left);
        if (result == -1) {
            if (errno != EINTR) {
                perror("read failed");
                exit(EXIT_FAILURE);
            }
            continue;
        } else if (result == 0) {
            fprintf(stderr, "end of file reached: %" PRId32 " bytes read.\n", n - bytes_left);
            break;
        }
        bytes_left -= result;
    }
    buf[n - bytes_left] = '\0';  // null-terminate string
    printf("Read: %s\n", buf);
    free(buf);
    close(fd);

    return EXIT_SUCCESS;
}


void Usage(void) {
    fprintf(stderr, "Usage: ./readn filename n\nn > 0\n");
    exit(EXIT_FAILURE);
}