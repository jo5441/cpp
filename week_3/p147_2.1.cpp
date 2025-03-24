#include <iostream>
using namespace std;

// 1. 반복문과 나머지 연산을 활용한 방법
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
    cout << "정수를 입력하세요: ";
    cin >> num;

    cout << "1. 나머지 연산 활용: " << reverseByMod(num) << endl;

    return 0;
}
