
#include<iostream>

using namespace std;

class MyInteger {

    friend ostream& operator<<(ostream& out, MyInteger myint);

public:
    MyInteger() {
        m_Num = 0;
    }

    // 前置++
    MyInteger& operator++() {
        // 先++
        m_Num++;
        // 再返回
        return *this;
    }

    // 后置++
    MyInteger operator++(int) {
        // 先记录当前本身的值
        MyInteger temp = *this;
        // 本身的值加1
        m_Num++;
        // 返回以前的值
        return temp;
    }

private:
    int m_Num;
};

ostream& operator<<(ostream& out, MyInteger myint) {
    out << myint.m_Num;
    return out;
}

// 前置++ 先++ 再返回
void test01() {
    MyInteger myInt;
    cout << ++myInt << endl;
    cout << myInt << endl;
}

// 后置++ 先返回 再++
void test02() {
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}

int main() {
    test01();
    test02();

    system("pause");

    return 0;
}