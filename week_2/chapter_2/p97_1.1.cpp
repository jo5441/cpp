#include <iostream>

int main() {
    int n = 5; // 출력할 줄 수

    for (int i = 1; i <= n; i++) { // 줄 수
        for (int j = 1; j <= i; j++) { // 각 줄에 출력할 숫자
            std::cout << j << " ";
        }
        std::cout << std::endl; // 줄바꿈
    }

    return 0;
}