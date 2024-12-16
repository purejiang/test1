#include <stdio.h>

void test1(){
 // volatile 往往会用于多线程的修饰，每次都从内存中读取值
    volatile int i = 10;

    volatile char m = 'c';

    int j;
    j = 20;
    int a = i;
    int b = j;
    volatile int *p = &i;

    printf("i = %d, j = %d\n", a, b);
    printf("&i = %x, &j = %x\n", &i, &b);
    volatile int myVolatileInt;
    volatile int* ptr = &myVolatileInt; // Much better!
}
void name(){
    printf("hello world\n");
}
void main(){
   
    // jisuanMain();
    // xiushifuMain();
    void (*p)(void) = test1;
    void (*p2)(void) = name;
    printf ("*p:%p\n", *p);
    printf ("p:%p\n", p);
    printf ("*p2:%p\n", *p2);
    printf ("p2:%p\n", p2);
}
