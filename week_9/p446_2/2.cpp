#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

constexpr int W = 20;      // 맵 가로크기
constexpr int H = 12;      // 맵 세로크기

class Monster {
protected:
    int x, y;
    int energy = 100;
public:
    Monster() {
        x = std::rand() % W;
        y = std::rand() % H;
    }
    virtual ~Monster() = default;
    virtual void move() = 0;
    virtual char symbol() const = 0;
    int  getEnergy() const { return energy; }
};

class Jiangshi : public Monster {
    bool horiz = true;
public:
    void move() override {
        if (horiz)       x += (std::rand()%2 ? 1:-1);
        else             y += (std::rand()%2 ? 1:-1);
        horiz = !horiz;
        x = (x+W)%W; y = (y+H)%H;     // 경계 래핑
    }
    char symbol() const override { return 'J'; }
};

class Smombi : public Monster {
public:
    void move() override {
        x += (std::rand()%2 ? 1:-1);
        y += (std::rand()%2 ? 1:-1);
        x = (x+W)%W; y = (y+H)%H;
    }
    char symbol() const override { return 'S'; }
};

class Siangshi : public Jiangshi {
    bool diag = false;
    int  tick = 0;
    static constexpr int PERIOD = 15;
public:
    void move() override {
        if (++tick % PERIOD == 0) diag = !diag;
        if (diag) {
            int dx = (std::rand()%2 ? 1:-1);
            int dy = (std::rand()%2 ? 1:-1);
            x = (x+dx+W)%W;
            y = (y+dy+H)%H;
        } else {
            Jiangshi::move();
        }
    }
    char symbol() const override { return diag ? 'X' : 'x'; }
};

class Boomer : public Monster {
    int life = 25;
public:
    void move() override {
        --life;
        x = (x + (std::rand()%3 -1) + W) % W;
        y = (y + (std::rand()%3 -1) + H) % H;
        if (life <= 0) energy = 0;
    }
    char symbol() const override { return 'B'; }
};

class MonsterWorld {
    std::vector<Monster*> mlist;
public:
    ~MonsterWorld(){ for(auto m:mlist) delete m; }

    void add(Monster* m){ mlist.push_back(m); }

    void step() {
        for (auto m: mlist) m->move();
        removeDead();
        draw();
    }
private:
    void removeDead() {
        for (auto it=mlist.begin(); it!=mlist.end();) {
            if ((*it)->getEnergy() <= 0) {
                delete *it;
                it = mlist.erase(it);
                std::cout << ">> 몬스터 하나가 사라졌습니다!\n";
            } else ++it;
        }
    }
    void draw() const {
        char map[H][W];
        for(int r=0;r<H;++r) for(int c=0;c<W;++c) map[r][c]='.';
        for (auto m: mlist) map[m->y][m->x] = m->symbol();

        std::cout << "\n=== Monster World ===\n";
        for(int r=0;r<H;++r){
            for(int c=0;c<W;++c) std::cout << map[r][c];
            std::cout << '\n';
        }
        std::cout << "남은 몬스터 수: " << mlist.size() << "\n";
    }
};