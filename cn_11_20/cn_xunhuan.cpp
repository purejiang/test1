#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void whileTest()
{
    int i = 10;
    int j = 0;
    while (i--)
    {
        j++;
    }
    // i=-1，因为先判断i，然后再--，判断到i=0时，退出循环，但是会继续执行--
    // j=10
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;

    int a = 10;
    int b = 0;
    do
    {
        b++;
    } while (a--);

    // a =-1，因为先判断a，然后再--，判断到a=0时，退出循环，但是会继续执行--
    // b =11，因为先执行一次，再判断
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

void forTest()
{
    // 死循环
    //  for(;;){
    //      cout<<"hello"<<endl;
    //  }
    string str("hello");
    for (auto c : str)
    {
        cout << "(int)c:" << (int)c << endl;
        cout << "c:" << c << endl;
    }

    int test[] = {1, 2, 3, 4, 5};
    for (int i : test)
    {
        cout << "i:" << i << endl;
        cout << "&i:" << &i << endl;
        i *= 2;
    }
    //&会改变test中的值
    for (int &j : test)
    {
        cout << "j:" << j << endl;
        cout << "&j:" << &j << endl;
        j *= 2;
    }
}

void hanshuTest()
{
    vector<int> test = {1, 2, 3, 4, 5};
    for_each(test.begin(), test.end(), [](int i) { i *= 2; cout << "i:" << i << endl; });
}
void xunhuanMain()
{
    // whileTest();
    // forTest();
    hanshuTest();
}