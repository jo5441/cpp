#include "MineSweeper.h"
#define DIM 9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };

static int MineMapLabel[DIM][DIM]; // 0~8 or Bomb
static int MineMapMask[DIM][DIM];  // Hide, Open, Flag
static int nx = DIM, ny = DIM;
static int nBomb = DIM;

// 보조 함수
inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

static void dig(int x, int y) {
    if (!isValid(x, y) || mask(x, y) == Open) return;
    mask(x, y) = Open;
    if (label(x, y) == 0) {
        for (int dy = -1; dy <= 1; dy++)
            for (int dx = -1; dx <= 1; dx++)
                if (dx != 0 || dy != 0)
                    dig(x + dx, y + dy);
    }
}

static void mark(int x, int y) {
    if (isValid(x, y) && mask(x, y) == Hide)
        mask(x, y) = Flag;
}

static int getBombCount() {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (mask(x, y) == Flag) count++;
    return count;
}

static void print() {
    system("cls");  // Windows 전용
    std::cout << "발견: " << getBombCount() << " 전체: " << nBomb << "\n";
    std::cout << "  ";
    for (int x = 0; x < nx; x++)
        std::cout << " " << x + 1;
    std::cout << "\n";

    for (int y = 0; y < ny; y++) {
        std::cout << static_cast<char>('A' + y) << " ";
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Hide) std::cout << "□ ";
            else if (mask(x, y) == Flag) std::cout << "P ";
            else {
                if (isBomb(x, y)) std::cout << "* ";
                else if (isEmpty(x, y)) std::cout << "  ";
                else std::cout << label(x, y) << " ";
            }
        }
        std::cout << "\n";
    }
}

static int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isValid(xx, yy) && label(xx, yy) == Bomb) count++;
    return count;
}

static void init(int total) {
    srand((unsigned int)time(NULL));
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            mask(x, y) = Hide;
            label(x, y) = Empty;
        }

    nBomb = total;
    int x, y;
    for (int i = 0; i < nBomb; i++) {
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (label(x, y) != Empty);
        label(x, y) = Bomb;
    }

    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x, y) == Empty)
                label(x, y) = countNbrBombs(x, y);
}

static bool getPos(int& x, int& y) {
    std::cout << "\n지뢰(P)형(A~I)열(1~9)\n입력 --> ";
    char ch;
    ch = toupper(_getch());  // 행
    y = ch - 'A';
    bool isMark = false;
    if (ch == 'P') {
        isMark = true;
        y = toupper(_getch()) - 'A';
    }
    x = _getch() - '1'; // 열
    return isMark;
}

static int checkDone() {
    int count = 0;
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) != Open) count++;
            else if (isBomb(x, y)) return -1;  // 폭탄 밟음
        }
    return (count == nBomb) ? 1 : 0;
}

void playMineSweeper(int total) {
    int x, y, status;
    init(total);
    do {
        print();
        bool isBomb = getPos(x, y);
        if (isBomb) mark(x, y);
        else dig(x, y);
        status = checkDone();
    } while (status == 0);

    print();
    if (status < 0)
        std::cout << "\n실패!! 지뢰 폭발!!!\n";
    else
        std::cout << "\n성공! 탐색 성공!!\n";
}

