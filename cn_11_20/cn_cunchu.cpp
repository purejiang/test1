#include <iostream>
#include <thread>

using namespace std;

// 文件内可访问
static int a;
// 每个线程的值都可以不一样，随着线程销毁而销毁，
thread_local int b;

void threadFunc(int x)
{
    b = x;
    cout << "----b = ----" << b << endl;
}
void threadFunc2(int x)
{
    b = x;
    cout << "^^^^b = ^^^^" << b << endl;
}
void threadTest()
{
    thread t1(threadFunc, 10);
    thread t2(threadFunc2, 20);

    t1.join();

    t2.join();
}
void cunchuMain()
{
    threadTest();
}

