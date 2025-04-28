class Monster {
    int x, y;          // 몬스터 위치
    int nEnergy;       // 몬스터 에너지

public:
    // 생성자
    Monster() {
        x = 0;
        y = 0;
        nEnergy = 1000;  // 에너지 초기화
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // 아이템을 먹었는지 여부를 인자로 받는 eat 함수
    void eat(bool itemEaten) {
        if (itemEaten) {
            nEnergy += 8; // 아이템 먹으면 에너지 +8
        }
        else {
            nEnergy -= 1; // 못 먹으면 에너지 -1
            if (nEnergy < 0)
                nEnergy = 0; // 에너지는 최소 0
        }
    }

    void print() {
        cout << "몬스터 위치: (" << x << ", " << y << "), "
             << "에너지: " << nEnergy << endl;
    }

    int getEnergy() {
        return nEnergy;
    }
};