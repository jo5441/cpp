#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;

// === Monster 클래스 ===
class Monster {
protected:
    int x, y;
    char icon;
public:
    Monster(int x = 0, int y = 0, char icon = 'M') : x(x), y(y), icon(icon) {}
    virtual void move(char** map, int xMax, int yMax) = 0;
    int getX() const { return x; }
    int getY() const { return y; }
    char getIcon() const { return icon; }
    virtual ~Monster() {}
};

// === Smombi: 대각선 이동 ===
class Smombi : public Monster {
    int dx = 1, dy = 1;
public:
    Smombi(int x = 1, int y = 1) : Monster(x, y, 'S') {}
    void move(char** map, int xMax, int yMax) override {
        int nx = x + dx, ny = y + dy;
        if (nx <= 0 || nx >= xMax - 1) dx *= -1;
        if (ny <= 0 || ny >= yMax - 1) dy *= -1;
        x += dx;
        y += dy;
    }
};

// === Jiangshi (기존 클래스) ===
class Jiangshi : public Monster {
protected:
    int direction = 1; // 1: 오른쪽, -1: 왼쪽
public:
    Jiangshi(int x = 1, int y = 1) : Monster(x, y, 'J') {}
    void move(char** map, int xMax, int yMax) override {
        int nx = x + direction;
        if (nx <= 0 || nx >= xMax - 1) direction *= -1;
        x += direction;
    }
};

// === Siangshi: 일정 시간마다 방향 바꿈 ===
class Siangshi : public Jiangshi {
    int timer = 0;
    int interval = 5;
public:
    Siangshi(int x = 1, int y = 2) {
        this->x = x;
        this->y = y;
        this->icon = 'G';
    }
    void move(char** map, int xMax, int yMax) override {
        timer++;
        if (timer >= interval) {
            direction *= -1;
            timer = 0;
        }
        int nx = x + direction;
        if (nx <= 0 || nx >= xMax - 1) direction *= -1;
        x += direction;
    }
};

// === 사용자 정의 몬스터: 위아래 반복 이동 ===
class MyMonster : public Monster {
    int dy = 1;
public:
    MyMonster(int x = 10, int y = 1) : Monster(x, y, 'U') {}
    void move(char** map, int xMax, int yMax) override {
        int ny = y + dy;
        if (ny <= 0 || ny >= yMax - 1) dy *= -1;
        y += dy;
    }
};

// === MonsterWorld ===
class MonsterWorld {
    char** map;
    int xMax = 20;
    int yMax = 10;
    vector<Monster*> monsters;
public:
    MonsterWorld() {
        map = new char*[yMax];
        for (int i = 0; i < yMax; i++) {
            map[i] = new char[xMax];
            for (int j = 0; j < xMax; j++)
                map[i][j] = '.';
        }

        for (int i = 0; i < yMax; i++) {
            map[i][0] = '*';
            map[i][xMax - 1] = '*';
        }
        for (int j = 0; j < xMax; j++) {
            map[0][j] = '*';
            map[yMax - 1][j] = '*';
        }
    }

    void addMonster(Monster* m) {
        monsters.push_back(m);
    }

    void draw() {
        system("cls");
        char temp[10][20];

        for (int i = 0; i < yMax; i++)
            for (int j = 0; j < xMax; j++)
                temp[i][j] = map[i][j];

        for (auto m : monsters)
            temp[m->getY()][m->getX()] = m->getIcon();

        for (int i = 0; i < yMax; i++) {
            for (int j = 0; j < xMax; j++)
                cout << temp[i][j];
            cout << endl;
        }
    }

    void play() {
        while (true) {
            for (auto m : monsters)
                m->move(map, xMax, yMax);
            draw();
            Sleep(300);
        }
    }

    ~MonsterWorld() {
        for (int i = 0; i < yMax; i++)
            delete[] map[i];
        delete[] map;
        for (auto m : monsters)
            delete m;
    }
};