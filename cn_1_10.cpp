#include <iostream>
#include <limits>
using namespace std;

void ifTest();
void EnumTest();
void DataTest();
void NumTest();
void PointTest();
void scopeTest();
void constTest();
// typedef enum Date
//     {
//         yesterday,
//         today,
//         tomorrow
//     } DateType;
// typedef 可以用 using 代替，可读性高
using DateType = enum Date { yesterday,
                             today,
                             tomorrow };
int main()
{

    // ifTest();
    // PointTest();
    // DataTest();
    // EnumTest();
    // scopeTest();
    constTest();
    return 0;
}
// #的特殊用法
void ifTest()
{
#if 1
    cout << "Hello World" << endl;
#else
    cout << "start game" << endl;
#endif
}
// 枚举类型
void EnumTest()
{

    DateType date = today;
    DateType *p;
    p = &date;
    switch (date)
    {
    case yesterday:
        cout << "yesterday";
        break;
    case today:
        cout << "today";
        break;
    case tomorrow:
        cout << "tomorrow";
        break;
    default:
        break;
    }
}
// 数据类型
void DataTest()
{
    cout << "int min:" << INT_MIN;
    cout << "\tint max:" << INT_MAX;
    cout << "\tint size:" << sizeof(int) << endl;
    cout << "char min:" << CHAR_MIN;
    cout << "\tchar max:" << CHAR_MAX;
    cout << "\tunsigned char min:" << numeric_limits<unsigned char>::min();
    cout << "\tunsigned char max:" << numeric_limits<unsigned char>::max();
    cout << "\tchar size:" << sizeof(char) << endl;
    cout << "long min:" << LONG_MIN;
    cout << "\tlong max:" << LONG_MAX;
    cout << "\tunsigned long min:" << numeric_limits<unsigned long>::min();
    cout << "\tunsigned long max:" << numeric_limits<unsigned long>::max();
    cout << "\tsigned long min:" << numeric_limits<signed long>::min();
    cout << "\tsigned long max:" << numeric_limits<signed long>::max();
    cout << "\tlong size:" << sizeof(long) << endl;
    cout << "short min:" << SHRT_MIN;
    cout << "\tshort max:" << SHRT_MAX;
    cout << "\tshort size:" << sizeof(short) << endl;
}

// 整型测试
void NumTest()
{
    int a = 4294967295;
    cout << "a:" << a;
}

// 指针
void PointTest()
{
    int var = 20; // 实际变量的声明
    int *ip;      // 指针变量的声明

    ip = &var; // 在指针变量中存储 var 的地址
    cout << "Value:" << var << endl;

    cout << "ip:" << ip << endl;
}

// 全局都可访问
int a = 10;
// 本文件中可访问,全局变量可以自动初始化
static int c;
// 变量作用域
void scopeTest()
{

    {
        // 分配的是不同的内存地址
        int a;
        // 如果没有对a进行初始化，c++没有编译报错，a的值是不定的，由分配的内存地址之前存储的数据决定的
        cout << "inner a:" << a << endl;
        cout << "inner a ip:" << &a << endl; // inner a ip:0x5ffe6c，栈内存中
        cout << "outer a:" << ::a << endl;
        cout << "outer a ip:" << &::a << endl; // outer a ip:0x7ff632844000 静态存储区中
    }
    cout << "outer a:" << a << endl;
    cout << "outer a ip:" << &a << endl; // outer a ip:0x7ff632844000
    // 全局都可访问
    extern int b;
    cout << "extern b:" << b << endl;
    cout << "extern b ip:" << &b << endl;

    cout << " c:" << c << endl;
    cout << " c ip:" << &c << endl; // extern c ip:0x7ff632848030

    ::c = 30;
    cout << "c:" << ::c << endl;
}
int b = 20;

// 常量测试
#define TEST_MIN 11
#define TEST_MAX 49.1;
void constTest()
{
    auto a = TEST_MIN * TEST_MAX;
    cout << "TEST_MIN * TEST_MAX:" << a << endl;
// 宏定义是可以取消的
#undef TEST_MIN
#define TEST_MIN 10
    a = TEST_MIN * TEST_MAX;
    cout << "TEST_MIN * TEST_MAX:" << a << endl;

    const double pi = 3.14159265; // 圆周率的值用pi表示
    cout << "圆周率的近似值是" << pi << endl;
    // const 常量的声明
    int b, d = 10;
    int c, f = 20;
    const int *p = &b;
    p = &c; // 不会报错，指针可以修改
    //*p = 10;  // 会报错，指针指向的内容不能修改
    cout << "p:" << p << endl;
    cout << "*p:" << *p << endl;
    int *const p2 = &d;
    // p2 = &f;  // 会报错，指针不能修改
    *p2 = 10; // 不会报错，指针指向的内容可以修改
    cout << "p2:" << p2 << endl;
    cout << "*p2:" << *p2 << endl;
    // const int * const p2 = &d; *p 和p都不能改
}
