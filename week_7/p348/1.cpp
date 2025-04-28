#include <iostream>
using namespace std;

class MyTime {
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    // 1번 (a) 모든 값을 전달받아 초기화하는 생성자
    MyTime(int h, int m, int s, int ms) {
        hour = h;
        minute = m;
        second = s;
        millisecond = ms;
    }

    // 1번 (b) 기본 생성자 (매개변수 없이 모든 값을 0으로)
    MyTime() {
        hour = 0;
        minute = 0;
        second = 0;
        millisecond = 0;
    }

    // 2번 (duration을 받아서 시, 분, 초, 밀리초 계산)
    MyTime(double duration) {
        hour = (int)(duration / 3600);
        duration -= hour * 3600;

        minute = (int)(duration / 60);
        duration -= minute * 60;

        second = (int)(duration);
        duration -= second;

        millisecond = (int)(duration * 1000);
    }

    void print() {
        cout << hour << "시 " << minute << "분 "
             << second << "초 " << millisecond << "밀리초" << endl;
    }
};

int main() {
    MyTime t1(1, 30, 45, 500); // 1시간 30분 45초 500밀리초
    MyTime t2;                 // 모두 0
    MyTime t3(3661.789);        // 1시간 1초 789밀리초

    cout << "t1: ";
    t1.print();

    cout << "t2: ";
    t2.print();

    cout << "t3: ";
    t3.print();

    return 0;
}

