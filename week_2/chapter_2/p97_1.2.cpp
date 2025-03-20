#include <iostream>

int main() {
    int n = 5; // 출력할 줄 수

    for (int i = 0; i < n; i++) { // 줄 수
        for (int j = n; j > i; j--) { // 5부터 감소
            std::cout << j << " ";
        }
        std::cout << std::endl; // 줄바꿈
    }

    return 0;
}

