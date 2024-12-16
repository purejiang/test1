#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std;

void mathTest()
{
    int a = -10;
    cout << "abs:" << abs(a) << endl;

    double x = 0.1, y = 0.2;
    cout << "x+y:" << x + y << endl;
}
void randomTest()
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int a = rand();
        cout << "normal:" << a << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        int range_min = 0, range_max = 100;
        int b = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
        cout << "special:" << b << endl;
    }
}

void randomBack(int arry[], int ranges)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < ranges; i++)
    {
        int b = rand() % 100;
        arry[i] = b;
    }
}
/**
 * 实现一个随机红包
 */
void suijiRedbag(double money, int peopleNumer)
{
    srand((unsigned int)time(NULL));

    double golds[peopleNumer];
    int prs[peopleNumer];

    double total = 0; // 发出去的总金额
    int sum = 0;   // 随机数总和
    int max = 0;

    // randomBack(prs, peopleNumer);

    for (int i = 0; i < peopleNumer; i++)
    {
        prs[i] = rand() % 100;
        sum += prs[i];
        if (prs[i] > prs[max])
        {
            max = i;
        }
    }

    for (int i = 0; i < peopleNumer; i++)
    {
        double gold;
        if (i == peopleNumer)
        {
            gold = money - total;
        }
        else
        {
            gold = round((prs[i] * money / sum) * 100) / 100.0;
        }
        golds[i] = gold;
        total += gold;
        cout << "第" << i + 1 << "个人的红包是:" << setiosflags(ios::right) << setiosflags(ios::fixed) << setprecision(2) << gold << endl;
        // cout << "第" << i + 1 << "个人抢到的钱：" << gold << endl;
    }
    cout << "运气最好的人：" << max + 1 << "，金额：" << golds[max] << endl;
}
void test()
{
    double money;
    int peopleNumer;
    cout << "请输入金额：";
    cin >> money;
    cout << "请输入人数：";
    cin >> peopleNumer;
    suijiRedbag(money, peopleNumer);
}
void shuziMain()
{
    // mathTest();
    // demoTest();
    test();
    // int *array = new int[10];
    // randomBack2(array, 100, 10);
    // // size_of返回的是数组指针所占内存的大小，并不是数组的长度，64位系统，内存地址是8字节，所以size_of返回8。
    // cout << "size_of array" << sizeof(array) << endl;
    // // array是数组指针，所以输出的是数组指针的地址。
    // cout << "array:" << array << endl;
    // // size_of返回的是int的大小，int型占4个字节，所以返回4。
    // cout << "size_of *array" << sizeof(*array) << endl;
    // // *array是数组指针指向的元素，所以输出的是数组指针指向的元素的值。
    // cout << "*array" << *array << endl;

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "array[" << i << "]" << array[i] << endl;
    // }
    // // 释放掉动态分配的内存
    // delete[] array;
}