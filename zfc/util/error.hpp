/**
 * Error - error routines.
 */

#include <stdio.h>
#include <stdlib.h>

#define ZF_ARGS(...) , ##__VA_ARGS__

#define ZF_ERROR(msg, ...) do { \
    fprintf(stderr, "zfc: "); \
    fprintf(stderr, msg "\n" ZF_ARGS(__VA_ARGS__)); \
    exit(-1); \
} while (0)

#define ZF_WARN(msg, ...) do { \
    fprintf(stderr, "zfc: warning: "); \
    fprintf(stderr, msg "\n" ZF_ARGS(__VA_ARGS__)); \
} while (0)
