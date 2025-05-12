#include <iostream>
#include <vector>
using namespace std;

class Monster {
private:
    int nEnergy;
    static int count;

public:
    Monster() : nEnergy(100) {
        count++;
    }

    ~Monster() {
        count--;
    }

    void eat(int food) {
        nEnergy += food;
    }

    int getEnergy() const {
        return nEnergy;
    }

    void print() const {
        cout << "Monster 에너지: " << nEnergy << endl;
    }

    static void printCount() {
        cout << "전체 몬스터 수: " << count << endl;
    }

    static void decreaseCount() {
        count--;
    }
};

int Monster::count = 0;

class MonsterWorld {
private:
    vector<Monster*> pMon;

public:
    void addMonster(Monster* m) {
        pMon.push_back(m);
    }

    void feedAll(int food) {
        for (auto m : pMon)
            m->eat(food);
    }

    void printAll() const {
        for (auto m : pMon)
            m->print();
        Monster::printCount();
    }

    void checkStarvation() {
        for (auto it = pMon.begin(); it != pMon.end(); ) {
            if ((*it)->getEnergy() <= 0) {
                cout << "Monster 하나가 굶어죽습니다." << endl;
                delete *it;
                it = pMon.erase(it);
                Monster::decreaseCount();
            } else {
                ++it;
            }
        }
    }

    ~MonsterWorld() {
        for (auto m : pMon) delete m;
        pMon.clear();
    }
};