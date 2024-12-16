#include <iostream>

using namespace std;

void printArray()
{
    int arry[] = {1, 2, 3, 4};
    // int arry2[];
    // arry2 = {1, 2, 3, 4};  // 赋值的时候不能给
}

// int *backArray()
// {
//     // 数组在函数执行完成之后就会被清掉，在这里返回指针会有问题
//     int arr[4];
//     arr[0] = 1;
//     arr[1] = 2;
//     arr[2] = 3;
//     arr[3] = 4;
//     cout << "arr:" << arr << endl;
//     cout << "&arr:" << &arr << endl;
//     return arr;
// }

int *backArray2()
{
    // 改为static，或者直接new（动态分配内存）
    // static *arry = new int[2];
    int *arry = new int[2];
    arry[0] = 1;
    arry[1] = 2;
    return arry;
}

// 将动态分配内存的数组传进来，然后修改数组，执行完之后再清理内存
void backArray3(int arry[])
{
    arry[0] = 1;
    arry[1] = 2;
}

void getArrayLength(int arry[])
{
    cout << "arry:" << arry << endl;
    cout << "&arry:" << &arry << endl;
    // cout<< "sizeof(arry):"<< sizeof(arry)<<endl;  // 其实拿的是int指针的内存大小
    cout << "sizeof(int):" << sizeof(int) << endl;
    cout << "sizeof* aary:" << sizeof(*arry) << endl;
}

void shuzuMain()
{
    // int *a = backArray();
    // cout << "a[1]:" << sizeof(a) << endl;
    // cout << "&a:" << &a << endl;

    int *b = backArray2();
    cout << "b[1]:" << sizeof(b) << endl;
    cout << "b[1]:" << b[1] << endl;
    cout << "&b:" << &b << endl;

    // 在哪里new就在哪里清理，如果放在函数里清理又变成和backArray一样了
    int *c = new int[2];
    backArray3(c);
    delete[] c;

    // getArrayLength(b);
    // cout << "sizeof:" << b[0]<< endl;
}