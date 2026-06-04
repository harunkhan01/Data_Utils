#include "vector.h"

int main(){
    struct vector *new_vec = init_vec(1);

    char buf[] = "Hello";

    append_vec(new_vec, &buf[0]);
    append_vec(new_vec, &buf[1]);
    append_vec(new_vec, &buf[2]);
    append_vec(new_vec, &buf[3]);
    append_vec(new_vec, &buf[4]);
    
    print_vec(new_vec);

    return 0;
}