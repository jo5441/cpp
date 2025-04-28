#include <iostream>
#include "Monster.h"
using namespace std;

int main() {
    Monster m;

    m.print();  // 처음 상태

    // 아이템 먹은 경우
    m.eat(true);
    m.print();

    // 아이템 못 먹은 경우
    for (int i = 0; i < 5; i++) {
        m.eat(false);
    }
    m.print();

    return 0;
}