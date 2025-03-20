#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n을 입력하세요: ";
    cin >> n;

    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }

    cout << n << "! (팩토리얼): " << factorial << endl;
    return 0;
}