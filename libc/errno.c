#include <basic.h>
#include <errno.h>
#include <stdio.h>

// TODO: errno should be thread-local
int errno;

#include "autogenerated_errnos.c"

#ifndef __kernel__
void perror(const char *const message) {
    if (errno >= 0 && errno <= ERRNO_MAX) {
        fprintf(stderr, "%s: %s\n", message, perror_strings[errno]);
    } else {
        fprintf(stderr, "%s: Unknown Error (%i)\n", message, errno);
    }
}

const char *strerror(enum errno_value errno) {
    return perror_strings[errno];
}
#endif // ifndef __kernel__