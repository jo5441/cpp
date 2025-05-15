#include <iostream>
using namespace std;

// Point 클래스 정의
class Point {
protected:
    int x, y;

public:
    Point(int xx, int yy) : x(xx), y(yy) {}

    void draw() {
        cout << x << "," << y << "에 점을 그려라.\n";
    }
};

// Point 클래스를 상속한 Rectangle 클래스 정의
class Rectangle : public Point {
protected:
    int width, height;

public:
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) {}

    void draw() {
        cout << x << "," << y << "에 가로 " << width
             << " 세로 " << height << "인 사각형을 그려라.\n";
    }
};

