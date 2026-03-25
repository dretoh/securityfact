#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print(void *ptr, int size){
        unsigned char *p = (unsigned char *)ptr;
        for (int i = 0; i < size; i++) {
                if (i % 8 == 0)
                        printf("\n%02x ", p[i]);
                else
                        printf("%02x ", p[i]);
        }
        printf("\n");
}


int main(int argc, char **argv){
        uint8_t buf[8*4];
        memset(buf, 0, sizeof(buf));

        *(int *)buf = 3; // [0]
        *(double *)&buf[8] = 3.14; // [1]

        // double -> int
        *(int *)&buf[16] = *(int *)(buf+8); // ? [2]
        *(int *)&buf[24] = (int)*(double *)(buf+8); // [3]

        print(buf,sizeof(buf));
        printf("[1] as double = %f\n", *(double *)&buf[8]);
        printf("[2] as int = %d\n", *(int *)&buf[16]);
        printf("[3] as int = %d\n", *(int *)&buf[24]);

        return 0;
}
