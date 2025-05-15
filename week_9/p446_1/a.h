int main() {
    Point p(10, 20);
    p.draw();  // 원래 Point의 draw()

    Rectangle r(2, 30, 100, 200);
    r.draw();  // Rectangle에서 재정의한 draw()

    return 0;
}