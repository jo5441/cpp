#include <iostream>
#include <iomanip>
using namespace std;

class TimeHMS {
    int hour, min, sec;

    void normalize() {
        if (sec >= 60) { min += sec / 60; sec %= 60; }
        if (min >= 60) { hour += min / 60; min %= 60; }
        if (sec < 0) { int b = (abs(sec) + 59) / 60; min -= b; sec += b * 60; }
        if (min < 0) { int b = (abs(min) + 59) / 60; hour -= b; min += b * 60; }
    }

public:
    TimeHMS(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) { normalize(); }

    
    TimeHMS operator+(const TimeHMS& t) const {
        return TimeHMS(hour + t.hour, min + t.min, sec + t.sec);
    }

    TimeHMS operator-(const TimeHMS& t) const {
        int total1 = hour * 3600 + min * 60 + sec;
        int total2 = t.hour * 3600 + t.min * 60 + t.sec;
        int diff = total1 - total2;
        return TimeHMS(0, 0, diff);
    }

    bool operator!=(const TimeHMS& t) const {
        return hour != t.hour || min != t.min || sec != t.sec;
    }

    TimeHMS& operator++() { hour++; return *this; }
    TimeHMS& operator--() { hour--; return *this; }

    TimeHMS operator++(int) {
        TimeHMS temp = *this;
        sec++;
        normalize();
        return temp;
    }

    TimeHMS operator--(int) {
        TimeHMS temp = *this;
        sec--;
        normalize();
        return temp;
    }

    int operator[](int index) const {
        if (index == 0) return hour;
        else if (index == 1) return min;
        else if (index == 2) return sec;
        else return -1;
    }

    operator int() const {
        return hour * 3600 + min * 60 + sec;
    }

    operator double() const {
        return hour + min / 60.0 + sec / 3600.0;
    }

    TimeHMS operator*(int n) const {
        int total = (hour * 3600 + min * 60 + sec) * n;
        return TimeHMS(0, 0, total);
    }

    friend ostream& operator<<(ostream& os, const TimeHMS& t) {
        os << setfill('0') << setw(2) << t.hour << ":"
           << setw(2) << t.min << ":"
           << setw(2) << t.sec;
        return os;
    }

    friend istream& operator>>(istream& is, TimeHMS& t) {
        char ch;
        is >> t.hour >> ch >> t.min >> ch >> t.sec;
        t.normalize();
        return is;
    }
};

