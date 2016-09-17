#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv) {

    for (int i = 0; i < sysconf(_SC_NPROCESSORS_ONLN) - 1; i++)
        if (fork() == 0) for (;;);

    for (long long mem = 1ll << 62;
         mem != 1ll << 25; // Linux needs 2**13 pages apparently
         mem >>= 1) {

        void *junk_ptr = malloc(mem);
        for (long double *p = (long double *) junk_ptr;
             junk_ptr && p < junk_ptr + mem;
             *p++ = *p);
    }

    for (;;);

    return EXIT_SUCCESS;
}
