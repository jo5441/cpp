#include <iostream>
#include <cstdlib>  // rand(), srand() 함수 사용을 위한 헤더
#include <ctime>    // time() 함수 사용을 위한 헤더

void randommap(int map[5][5]) {
    // 난수 생성을 위한 시드 초기화
    srand(static_cast<unsigned int>(time(0)));

    // 5x5 크기의 배열을 채우기
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // 0 또는 1을 랜덤으로 생성하여 배열에 할당
            map[i][j] = rand() % 2;  // rand() % 2 -> 0 또는 1
        }
    }
}

// 배열을 출력하는 함수
void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int map[5][5];  // 5x5 크기의 배열 선언

    randommap(map);  // 배열에 임의의 0과 1을 채움

    std::cout << "랜덤으로 생성된 5x5 맵:" << std::endl;
    printMap(map);  // 배열 출력

    return 0;
}
