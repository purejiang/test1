#include <iostream>
using namespace std;

int zhiTest(int x, int y)
{
    x *= 2;
    y *= 2;
    return x + y;
}

// 传入指针类型的参数，修改时会改到原值，因为是改到引用地址的数据
int zhizhenTest(int *x, int *y)
{
    *x *= 10;
    *y *= 10;
    return *x + *y;
}
// 传入引用的参数，修改时直接改到引用的原始值
int yingyongTest(int &x, int &y)
{
    x = 1;
    y = 2;
    return x + y;
}

void lambda()
{
    // 后面可以直接加();执行方法
    int m=0;
    // = 复制捕获，&引用捕获
    [=]{ cout << "m:" << m<< endl; }();

    int x[] = {1, 2, 3, 4, 5, 6};
    int count = 0;
    for (int i : x)
    {
        auto test = [&count](int val)
        {
            cout << "val & 1:" << (val & 1) << endl;
            if (!(val & 1))
            {
                ++count;
            }
        };
        test(i);
    }
}
void hanshuMain()
{
    // int x = 1;
    // int y = 2;
    // cout << zhiTest(x, y) << endl;
    // cout << "x:" << x << "y:" << y << endl;
    // cout << zhizhenTest(&x, &y) << endl;
    // cout << "x:" << x << "y:" << y << endl;

    // cout << yingyongTest(x, y) << endl;
    // cout << "x:" << x << "y:" << y << endl;

    lambda();
}