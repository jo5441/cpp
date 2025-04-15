#include "MyTime.h"
#include <iostream>
#include <iomanip>
using namespace std;

MyTime::MyTime() : hour(0), min(0), sec(0), msec(0) {}

void MyTime::reset() {
    hour = min = sec = msec = 0;
}

void MyTime::convert(double duration) {
    hour = static_cast<int>(duration / 3600);
    duration -= hour * 3600;

    min = static_cast<int>(duration / 60);
    duration -= min * 60;

    sec = static_cast<int>(duration);
    duration -= sec;

    msec = static_cast<int>(duration * 1000);
}

void MyTime::print() const {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << ":"
         << setw(3) << msec << endl;
}

MyTime MyTime::add(MyTime t) const {
    MyTime result;
    result.msec = msec + t.msec;
    result.sec = sec + t.sec + result.msec / 1000;
    result.msec %= 1000;

    result.min = min + t.min + result.sec / 60;
    result.sec %= 60;

    result.hour = hour + t.hour + result.min / 60;
    result.min %= 60;

    return result;
}

void MyTime::read() {
    cout << "시간(시)을 입력하세요: ";
    cin >> hour;
    cout << "분을 입력하세요: ";
    cin >> min;
    cout << "초를 입력하세요: ";
    cin >> sec;
    cout << "밀리초를 입력하세요: ";
    cin >> msec;
}
