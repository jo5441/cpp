#include <iostream>
#include <cstdlib>  // rand(), srand() 함수 사용을 위한 헤더
#include <ctime>    // time() 함수 사용을 위한 헤더

// 배열에 0과 1을 무작위로 채우는 함수
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

// 배열을 보기 좋게 출력하는 함수
void printmap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << map[i][j] << " ";  // 배열 요소 출력
        }
        std::cout << std::endl;  // 한 행 출력 후 줄 바꿈
    }
}

int main() {
    int map[5][5];  // 5x5 크기의 배열 선언

    // 무작위로 0과 1을 채우기
    randommap(map);

    // 무작위로 생성된 5x5 맵 출력
    std::cout << "무작위로 생성된 체커 보드:" << std::endl;
    printmap(map);

    return 0;
}
