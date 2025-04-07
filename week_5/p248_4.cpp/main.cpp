#include "MineSweeper.h"

int main() {
    int total;
    std::cout << "지뢰찾기 Mine Sweeper\n";
    std::cout << "매설할 총 지뢰의 개수 입력: ";
    std::cin >> total;
    playMineSweeper(total);
    return 0;
}

