#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "n을 입력하세요: ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    cout << "1부터 " << n << "까지의 합: " << sum << endl;
    return 0;
}