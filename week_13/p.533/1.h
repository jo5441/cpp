int main() {
    TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;

    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;

    t3 = t1 + t2;
    cout << "t3 = t1 + t2: " << t3 << endl;

    t3 = t1 - t2;
    cout << "t3 = t1 - t2: " << t3 << endl;

    cout << "t1 != t2: " << (t1 != t2 ? "true" : "false") << endl;

    cout << "++t1: " << ++t1 << endl;
    cout << "--t1: " << --t1 << endl;

    cout << "t1++: " << t1++ << endl;
    cout << "t1 after t1++: " << t1 << endl;

    cout << "t1[0]: " << t1[0] << ", t1[1]: " << t1[1] << ", t1[2]: " << t1[2] << endl;

    int seconds = (int)t1;
    double hours = (double)t1;
    cout << "(int)t1: " << seconds << "초" << endl;
    cout << "(double)t1: " << hours << "시간" << endl;

    TimeHMS t4 = t1 * 2;
    cout << "t4 = t1 * 2: " << t4 << endl;

    TimeHMS inputTime;
    cout << "시간 입력 (hh:mm:ss 형식): ";
    cin >> inputTime;
    cout << "입력한 시간: " << inputTime << endl;

    return 0;
}