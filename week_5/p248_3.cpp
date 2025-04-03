#include <iostream>
using namespace std;

struct mytime {
    int hour, minute, second;

    mytime(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
};

// 1. 값에 의한 호출 (Call by Value)
mytime addtime_by_value(mytime t1, mytime t2) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + 
                        (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    return mytime(total_seconds / 3600, (total_seconds % 3600) / 60, total_seconds % 60);
}

// 2. 주소에 의한 호출 (Call by Address)
void addtime_by_address(mytime t1, mytime t2, mytime* pt) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + 
                        (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    pt->hour = total_seconds / 3600;
    pt->minute = (total_seconds % 3600) / 60;
    pt->second = total_seconds % 60;
}

// 3. 참조에 의한 호출 (Call by Reference)
void addtime_by_reference(mytime t1, mytime t2, mytime &t3) {
    int total_seconds = (t1.hour * 3600 + t1.minute * 60 + t1.second) + 
                        (t2.hour * 3600 + t2.minute * 60 + t2.second);
    
    t3.hour = total_seconds / 3600;
    t3.minute = (total_seconds % 3600) / 60;
    t3.second = total_seconds % 60;
}

void print_time(const mytime &t) {
    cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}

int main() {
    mytime t1(2, 45, 30);
    mytime t2(3, 15, 45);

    // 1. 값에 의한 호출 (Call by Value)
    mytime result1 = addtime_by_value(t1, t2);
    cout << "Result by Value: ";
    print_time(result1);

    // 2. 주소에 의한 호출 (Call by Address)
    mytime result2;
    addtime_by_address(t1, t2, &result2);
    cout << "Result by Address: ";
    print_time(result2);

    // 3. 참조에 의한 호출 (Call by Reference)
    mytime result3;
    addtime_by_reference(t1, t2, result3);
    cout << "Result by Reference: ";
    print_time(result3);

    return 0;
}
