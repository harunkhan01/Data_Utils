#include <stdint.h>

#include "vector.h"

int main(){
    struct vector *new_vec = init_vec(1);

    char buf[] = "Hello";

    char buf2[] = "World";

    append_vec(new_vec, &buf2[0]);
    append_vec(new_vec, &buf2[1]);
    append_vec(new_vec, &buf2[2]);
    append_vec(new_vec, &buf2[3]);
    append_vec(new_vec, &buf2[4]);

    insert_vec(new_vec, &buf[4], 0);
    insert_vec(new_vec, &buf[3], 0);
    insert_vec(new_vec, &buf[2], 0);
    insert_vec(new_vec, &buf[1], 0);
    insert_vec(new_vec, &buf[0], 0);
    
    print_vec(new_vec);


    /* Trigger memory violation */
    struct vector *vio_mem_vec = init_vec(1);

    size_t bound = 1 << 26;

    uint8_t val = 0;
    for (size_t i=0; i < bound; i++){
        append_vec(vio_mem_vec, &val);
        val++;
    }

    return 0;
}