#include <stdio.h>
#include <unistd.h>
int main() {
    for (int i = 0; i < 10; ++i) {

        printf("%d\n",i*10);
        //usleep(500000);
        sleep(1);
    }
    printf("Hello, World!\n");
    return 0;
}