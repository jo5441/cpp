#include <iostream>
#include <cstdlib>  // rand(), srand() 함수 사용을 위한 헤더
#include <ctime>    // time() 함수 사용을 위한 헤더

// 배열에 0과 1을 무작위로 채우는 함수
void randommap(int map[5][5]) {
    srand(static_cast<unsigned int>(time(0)));  // 난수 생성을 위한 시드 초기화

    // 5x5 크기의 배열을 무작위로 채우기
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;  // rand() % 2 -> 0 또는 1
        }
    }
}

// 가로, 세로, 대각선 방향이 모두 동일한 값인 부분을 찾아 출력하는 함수
void checkmap(int map[5][5]) {
    // 가로 검사
    for (int i = 0; i < 5; i++) {
        bool isRowSame = true;
        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) {
                isRowSame = false;
                break;
            }
        }
        if (isRowSame) {
            std::cout << "가로 방향 동일: " << map[i][0] << " (행 " << i << ")" << std::endl;
        }
    }

    // 세로 검사
    for (int j = 0; j < 5; j++) {
        bool isColSame = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) {
                isColSame = false;
                break;
            }
        }
        if (isColSame) {
            std::cout << "세로 방향 동일: " << map[0][j] << " (열 " << j << ")" << std::endl;
        }
    }

    // 왼쪽 상단 -> 오른쪽 하단 대각선 검사
    bool isDiagonal1Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) {
            isDiagonal1Same = false;
            break;
        }
    }
    if (isDiagonal1Same) {
        std::cout << "대각선 (왼쪽 상단 -> 오른쪽 하단) 동일: " << map[0][0] << std::endl;
    }

    // 오른쪽 상단 -> 왼쪽 하단 대각선 검사
    bool isDiagonal2Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) {
            isDiagonal2Same = false;
            break;
        }
    }
    if (isDiagonal2Same) {
        std::cout << "대각선 (오른쪽 상단 -> 왼쪽 하단) 동일: " << map[0][4] << std::endl;
    }
}

int main() {
    int map[5][5];  // 5x5 크기의 배열 선언

    // 무작위로 0과 1을 채우기
    randommap(map);

    std::cout << "무작위로 생성된 5x5 맵:" << std::endl;
    // 무작위로 생성된 맵 출력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << map[i][j] << " ";  // 배열 요소 출력
        }
        std::cout << std::endl;  // 한 행 출력 후 줄 바꿈
    }

    std::cout << "\n맵 검사 결과:" << std::endl;
    // 무작위로 생성된 맵에서 동일한 부분 검사
    checkmap(map);

    return 0;
}
