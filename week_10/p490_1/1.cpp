#include <iostream>
#include <vector>
#include <conio.h>   
#include <windows.h> 
using namespace std;

class Monster {
protected:
    int x, y;
    char icon;
public:
    Monster(int x = 0, int y = 0, char icon = 'M') : x(x), y(y), icon(icon) {}
    virtual void move(char** map, int xMax, int yMax) = 0;
    virtual char getIcon() { return icon; }
    int getX() const { return x; }
    int getY() const { return y; }
    virtual ~Monster() {}
};

class Human : public Monster {
public:
    Human(int x = 0, int y = 0, char icon = '@') : Monster(x, y, icon) {}
    virtual void move(char** map, int xMax, int yMax) override {}
};

class Tuman : public Human {
public:
    Tuman(int x = 0, int y = 0, char icon = '@') : Human(x, y, icon) {}

    void move(char** map, int xMax, int yMax, unsigned char ch) {
        int nx = x, ny = y;
        switch (ch) {
            case 72: ny--; break; // ↑ 방향키
            case 80: ny++; break; // ↓
            case 75: nx--; break; // ←
            case 77: nx++; break; // →
            case 'w': ny--; break;
            case 's': ny++; break;
            case 'a': nx--; break;
            case 'd': nx++; break;
        }

        if (nx >= 0 && nx < xMax && ny >= 0 && ny < yMax && map[ny][nx] != '*') {
            x = nx;
            y = ny;
        }
    }

    void move(char** map, int xMax, int yMax) override {} // 무시됨
};

class MonsterWorld {
private:
    int xMax = 20;
    int yMax = 10;
    char** map;
    vector<Monster*> pMon;

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
        pMon.push_back(m);
    }

    char** Data() { return map; }

    void draw() {
        system("cls"); 
        char temp[10][20];

        for (int i = 0; i < yMax; i++)
            for (int j = 0; j < xMax; j++)
                temp[i][j] = map[i][j];

        for (auto m : pMon)
            temp[m->getY()][m->getX()] = m->getIcon();

        for (int i = 0; i < yMax; i++) {
            for (int j = 0; j < xMax; j++)
                cout << temp[i][j];
            cout << '\n';
        }
    }

    void play() {
        while (true) {
            for (size_t i = 0; i < pMon.size() - 2; ++i)
                pMon[i]->move(map, xMax, yMax);

            if (_kbhit()) {
                unsigned char ch = _getche();
                if (ch == 224) ch = _getche(); 
                if (ch == 72 || ch == 80 || ch == 75 || ch == 77) {
                    ((Tuman*)pMon[pMon.size() - 1])->move(map, xMax, yMax, ch);
                } else {
                    ((Tuman*)pMon[pMon.size() - 2])->move(map, xMax, yMax, ch); 
                }
            }

            draw();
            Sleep(100); 
        }
    }

    ~MonsterWorld() {
        for (int i = 0; i < yMax; i++)
            delete[] map[i];
        delete[] map;

        for (auto m : pMon)
            delete m;
    }
};


int main() {
    MonsterWorld mw;


    mw.addMonster(new Tuman(1, 1, '좌'));          
    mw.addMonster(new Tuman(18, 8, '우'));        
    mw.play();

    return 0;
}
