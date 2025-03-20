#include <iostream>
using namespace std;

int main() {
    int n = 5; // 출력할 줄 수

    for (int i = 1; i <= n; i++) { // 줄 수
        // 공백 출력 (삼각형 정렬)
        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }

        // 왼쪽 역순 숫자 출력
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // 오른쪽 증가 숫자 출력
        for (int j = 2; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl; // 줄바꿈
    }

    return 0;
}