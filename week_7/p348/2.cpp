#include <iostream>
using namespace std;

class MyTime {
    int hour;
    int minute;
    int second;
    int millisecond;

public:
    // double 타입 duration 생성자
    MyTime(double duration) {
        hour = (int)(duration / 3600);          // 시간 계산
        duration -= hour * 3600;                // 시간 만큼 빼기

        minute = (int)(duration / 60);           // 분 계산
        duration -= minute * 60;                 // 분 만큼 빼기

        second = (int)(duration);                // 남은 정수 부분은 초
        duration -= second;                      // 초 만큼 빼기

        millisecond = (int)(duration * 1000);     // 남은 소수 부분은 밀리초
    }

    // 출력 함수 (테스트용)
    void print() {
        cout << hour << "시 " << minute << "분 "
             << second << "초 " << millisecond << "밀리초" << endl;
    }
};

int main() {
    MyTime t(3661.789);  // 3661.789초 = 1시간 1분 1초 789밀리초
    t.print();

    return 0;
}

