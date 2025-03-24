#include <iostream>
#include "p147_2.5.h"

int reverseByMod(int num) {
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return reversedNum;
}

int main() {
    int num;
   std:: cout << "정수를 입력하세요: ";
   std:: cin >> num;

    std::cout << "1. 나머지 연산 활용: " << reverseByMod(num) << std::endl;

    return 0;
}
