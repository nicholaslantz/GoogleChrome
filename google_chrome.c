#include<stdlib.h>
#include<unistd.h>

#define ever (;;)

int main(int argc, char **argv) {

    int num_cpus = sysconf(_SC_NPROCESSORS_ONLN);

    for (int i = 0; i < num_cpus - 1; i++) {
        pid_t pid = fork();

        if (pid == 0)  { // child
            for ever;
        }
    }

    for (long long mem = 1ll << 62;
         mem != 1ll << 24; // Linux needs 2**12 pages apparently
         mem >>= 1) {

        void *junk_ptr = malloc(mem);
        char i = (char) junk_ptr;
        for (char *p = junk_ptr;
             junk_ptr && p < junk_ptr + mem;
             *++p = i++);
    }

    for ever;

    return EXIT_SUCCESS;
}
