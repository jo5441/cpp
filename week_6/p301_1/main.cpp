#include "MyTime.h"

int main() {
    MyTime t1, t2, t3;

    t1.convert(3754.567);  // 1:02:34:567
    t2.read();             // 사용자 입력 받기
    t3 = t1.add(t2);       // 시간 더하기

    std::cout << "t1: ";
    t1.print();
    std::cout << "t2: ";
    t2.print();
    std::cout << "t3: ";
    t3.print();

    t3.reset();
    std::cout << "t3 after reset: ";
    t3.print();

    return 0;
}
