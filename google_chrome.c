#include<stdlib.h>

#define ever (;;)

// TODO: Fork for each core on CPU, busy wait on each child

int main( int argc, char **argv ) {

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
