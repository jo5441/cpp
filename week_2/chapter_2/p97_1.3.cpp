#include <iostream>

int main() {
    int n = 5; // 출력할 줄 수

    for (int i = 1; i <= n; i++) { // 줄 수
        for (int j = i; j >= 1; j--) { // 현재 줄 번호부터 1까지 역순 출력
            std::cout << j << " ";
        }
        std::cout << std::endl; // 줄바꿈
    }

    return 0;
}