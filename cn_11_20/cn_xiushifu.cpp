#include <iostream>
using namespace std;

void signedTest()
{



    // 有符号数转成无符号数，得出补码，正数的原码=反码=补码
    // char 8位，1个字节，- 128~127
    signed char a = -126; 
    // 0111 1110
    // 0000 0001
    // 0000 0010
    // 1000 0010
    // 所以 130
    unsigned char b;
    b = a;
    cout << "b:" << (int)b << endl;
    // b=255

    short x = -32767; 
    //  011111111 1111111
    //  000000000 0000000
    //  100000000 0000001
    // 所以32769
    unsigned short y;    
    y = x;      
    cout << "y:" << y << endl;

    // 无符号数转成有符号数
    unsigned char c = 254; 
    char d;
    d = c;
    cout << "d:" << (int)d << endl;
}
void volTest()
{
    // volatile 往往会用于多线程的修饰，每次都从内存中读取值
    volatile int i = 10;

    int j;
    j = 20;
    int a = i;
    int b = j;
    volatile int *p = &i;

    cout << "*p:" << *p << endl;
    cout << "p:" << p << endl;

    cout << "i:" << i << endl;
    // 不知道为啥指针指向的地址是1，c语言没问题（未知问题）
    cout << "&i:" << &i << endl;

    cout << "&j:" << &j << endl;
    cout << "&a:" << &a << endl;
}
void staticTest1()
{
    // 静态变量，函数内全局使用，函数外不可访问
    static int i = 10;
    int *p = &i;
    cout << "i:" << static_cast<char>(i) << endl;
    cout << "p:" << p << endl;
    i++;
}

class Test1
{
public:
    Test1() : a(10) {}; // 1.不能在定义的时候初始化，只能在构造函数里初始化
    // Test1():b(10){};  // 静态成员不能在构造函数里初始化，因为它不属于某个对象。
    // Test1():c(10){};  //
private:
    const int a; // 1. 成员常量不能在这里初始化，只能在构造函数里
    static int b;
    // static const int c = 100; // 3. 静态成员常量可以直接初始化，但是后续不能再修改值.
    static const int c;
    void const test()
    {
        b++;
    };
};

int Test1::b = 20; // 静态成员可以在外部赋值，因为它不属于某个对象。

// int Test1::a = 20; // 1. 非静态数据成员不能在其类的外部定义。
/*static*/ const int Test1::c = 30; // 3. 在外部给静态成员变量赋值时，不需要加static修饰符，但要加cosnt。
void staticTest()
{
    staticTest1();

    staticTest1();

    staticTest1();
    // 结果输出
    // i:0
    // i:1
    // i:2
}

void xiushifuMain()
{
    signedTest();
    // volTest();
    // staticTest();
}
