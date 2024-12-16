#include <iostream>
#include <cstring>
using namespace std;

void charList()
{

    char str1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str2[5] = {'h', 'e', 'l', 'l', 'o'};
    // char str3[5] = "hello";  // 会报错，最后还有一个空字符
    char str3[6] = "hello"; // 这个是对的
}

void stringTest()
{
    string a = "hello";
    cout << "a:" << a << endl;
    cout << "a.size:" << a.size() << endl;     // 和.length()一样，但是size可以用在vector上
    cout << "sizeof(a):" << sizeof(a) << endl; // 所占内存大小
    cout << "a.length():" << a.length() << endl;
    // cout <<  "strlen(a):"<< strlen(a) << endl;  // 不能用在string上，只能是char数组
}

void stringcharTest()
{
    // 字符串字面值与标准库string不是同一种类型
    string a("hello");
    char b[6] = "world";
    cout << "a+b:" << a + "world" << endl;  // string后面可以直接拼
    cout << "b+a:" << b + a << endl;  // 后面可以直接拼string

    cout << "b+a:" << "hello" + a << endl;  // 后面可以直接拼string
    // cout << "" << "hello" + "world" << endl;  // 不能直接拼
}
void stringMain()
{
    stringTest();
}