#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n을 입력하세요: ";
    cin >> n;

    int sum = n * (n + 1) / 2; // 합 공식 사용

    cout << "1부터 " << n << "까지의 합: " << sum << endl;
    return 0;
}

