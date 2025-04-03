#include <iostream>
using namespace std;

struct mytime {
    int hour;
    int minute;
    int second;
    
    // 기본 생성자
    mytime(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    
    // 시간을 출력하는 함수
    void print() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};
//1
mytime addtime(mytime t1, mytime t2) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    int hour = total_seconds / 3600;
    total_seconds %= 3600;
    int minute = total_seconds / 60;
    int second = total_seconds % 60;
    
    return mytime(hour, minute, second);
}
//2
void addtime(mytime t1, mytime t2, mytime t3) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    t3.hour = total_seconds / 3600;
    total_seconds %= 3600;
    t3.minute = total_seconds / 60;
    t3.second = total_seconds % 60;
}
//3
void addtime(mytime t1, mytime t2, mytime* pt) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    pt->hour = total_seconds / 3600;
    total_seconds %= 3600;
    pt->minute = total_seconds / 60;
    pt->second = total_seconds % 60;
}

int main() {
    mytime t1(2, 45, 30);
    mytime t2(3, 15, 45);
    
    // 1번 방법
    mytime result1 = addtime(t1, t2);
    cout << "Result 1: ";
    result1.print();
    
    // 2번 방법
    mytime result2;
    addtime(t1, t2, result2);
    cout << "Result 2: ";
    result2.print();
    
    // 3번 방법
    mytime result3;
    addtime(t1, t2, &result3);
    cout << "Result 3: ";
    result3.print();
    
    return 0;
}
