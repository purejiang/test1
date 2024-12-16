#include <iostream>
#include <bitset>

using namespace std;

void weiyi()
{
    // 位移运算
    unsigned int num1 = 67;
    /**
     * 01000011
     * 00010000
     * 16
     */
    cout << "num1:" << (num1 >> 2) << endl;
    cout << "num1>>2:" << bitset<8>(num1 >> 2) << endl;

    int num2 = -86;
    /**
     * 11010110
     * 10101001
     * 10101010
     * 11101010
     * 11101001
     * 10010110
     * -22
     */
    cout << "num2>>2:" << bitset<8>(num2 >> 2) << endl;
    cout << "num2:" << (num2 >> 2) << endl;
}
void daxiao()
{
    signed int i = -10;
    unsigned int j = 9;
    // false, 有符号数会被提升为无符号数，再比较
    cout << "i<j:" << (i < j) << endl;

    char a = -9;
    unsigned char b = 8;
    //  比int小的整型(char, signed char, unsigned char, short, unsigned short)，如果该类型所有可能值都包含在int中，他们会被提升为int型，否则被提升为unsigned int型
    // true, 因为都会被提升为 int 型（是带符号的）
    cout << "a<b:" << (a < b) << endl;

    long long c = -9223372031212168L;
    unsigned long long d = 9223372031212167;
    // false，有符号数会被提升为无符号数，再比较
    cout << "c<d:" << (c < d) << endl;

    cout << "char:" << sizeof(char) << endl;
    cout << "short:" << sizeof(short) << endl;
    cout << "int:" << sizeof(int) << endl;
    cout << "long int :" << sizeof(long int) << endl;
    cout << "long long int:" << sizeof(long long int) << endl;
    cout << "float:" << sizeof(float) << endl;
    cout << "double:" << sizeof(double) << endl;
}

void other()
{
    int val = 2;
    if (val == true)
    { // 不会进入if
        cout << "val==true" << endl;
    }

    int ival;
    int *pval;
    //  ival = pval = 0; // 不同类型不能这样写
    string s1, s2;
    s1 = s2 = "OK"; // ok
}
void yunsuanMain()
{
    // weiyi();
    // daxiao();
    other();
}