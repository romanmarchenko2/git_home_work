#include <stdio.h>

extern void src_1_func();
extern void src_2_func();
extern void src_3_func();

int main() {
    src_1_func();
    src_2_func();
    src_3_func();

    return 0;
}
