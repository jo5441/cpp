#ifndef MYTIME_H
#define MYTIME_H

class MyTime {
private:
    int hour, min, sec, msec;

public:
    MyTime(); // 기본 생성자
    void reset(); // 시간 초기화
    void convert(double duration); // double -> 시간 변환
    void print() const; // 시간 출력
    MyTime add(MyTime t) const; // 시간 덧셈
    void read(); // 사용자로부터 시간 입력
};

#endif
