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

    // 멤버 함수로 정의된 add: this = a + b
    void add(Complex& a, Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }
};

int main() {
    Complex a(1, 2);  // a = 1 + 2i
    Complex b(3, 4);  // b = 3 + 4i
    Complex c;        // 결과 저장 객체

    c.add(a, b);      // c = a + b

    cout << "Result (c = a + b): ";
    c.print();        // 출력: 4 + 6i

    return 0;
}
