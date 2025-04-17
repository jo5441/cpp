#include <iostream>
using namespace std;

// 복소수 클래스 정의
class Complex {
public:
    double real;
    double imag;

    // 생성자
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // 복소수 출력 함수
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

// add 함수: 복소수 두 개를 더해서 결과를 반환
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

int main() {
    Complex a(1, 2);   // a = 1 + 2i
    Complex b(3, 4);   // b = 3 + 4i

    Complex c = add(a, b);  // c = a + b

    cout << "Result (c = a + b): ";
    c.print();  // 출력: 4 + 6i

    return 0;
}
