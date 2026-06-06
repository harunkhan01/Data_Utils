#include <stdint.h>

#include "queue.h"
#include "vector.h"

int main(){
    struct vector *new_vec = init_vec(1);

    char buf[] = "Hello";

    char buf2[] = "World";

    struct Q *new_q = init_q(1);

    for (int i = 0; i < 5; i++){
        append_queue(new_q, &buf[i]);
    }

    print_queue(new_q);
    

    return 0;
}