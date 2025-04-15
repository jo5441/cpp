#include <iostream>
#include "MyTime.h"
using namespace std;

int main() {
    MyTime t1, t2, t3;

    cout << "첫 번째 시간 입력:" << endl;
    t1.read();

    cout << "두 번째 시간 입력:" << endl;
    t2.read();

    t3 = t1.add(t2);

    cout << "첫 번째 시간: ";
    t1.print();

    cout << "두 번째 시간: ";
    t2.print();

    cout << "합계 시간: ";
    t3.print();

    cout << "초 단위 입력 (예: 3674.321): ";
    double duration;
    cin >> duration;

    MyTime converted;
    converted.convert(duration);
    cout << "변환된 시간: ";
    converted.print();

    return 0;
}
