#include <stdio.h>
#include <math.h>

struct multi {
    unsigned int size; 
    unsigned char num [];
};

void print_multi(struct multi *p) {
    unsigned int res = 0;
    for (int i  = p->size - 1; i >= 0; i--) {
        res = res | (p->num[i] << (i * 8));
    }
    printf("%x\n", res);
}

int main() {
    struct multi m;
    m.size = 4;
    m.num[0] = 0x03;
    m.num[1] = 0x80;
    m.num[2] = 0x0F;
    m.num[3] = 0x99;
    print_multi(&m);
    return 0;
}