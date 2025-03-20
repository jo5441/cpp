
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

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

// 2. 문자열 변환 후 reverse 함수 사용
int reverseByString(int num) {
    string str = to_string(num);
    reverse(str.begin(), str.end());
    return stoi(str);
}

// 3. 재귀를 활용한 방법
int reverseByRecursion(int num, int reversedNum = 0) {
    if (num == 0) return reversedNum;
    return reverseByRecursion(num / 10, reversedNum * 10 + num % 10);
}

// 4. 스택을 이용한 방법
int reverseByStack(int num) {
    stack<int> s;
    while (num > 0) {
        s.push(num % 10);
        num /= 10;
    }
   
    int reversedNum = 0;
    while (!s.empty()) {
        reversedNum = reversedNum * 10 + s.top();
        s.pop();
    }
    return reversedNum;
}

int main() {
    int num;
    cout << "정수를 입력하세요: ";
    cin >> num;

    cout << "1. 나머지 연산 활용: " << reverseByMod(num) << endl;
    cout << "2. 문자열 변환: " << reverseByString(num) << endl;
    cout << "3. 재귀 함수: " << reverseByRecursion(num) << endl;
    cout << "4. 스택 활용: " << reverseByStack(num) << endl;

    return 0;
}
