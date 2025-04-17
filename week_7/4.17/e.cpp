#include <iostream>
using namespace std;

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

    // + 연산자 오버로딩
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};

int main() {
    Complex a(1, 2);   // 1 + 2i
    Complex b(3, 4);   // 3 + 4i

    Complex c = a + b; // operator+ 호출

    cout << "Result (c = a + b): ";
    c.print();         // 출력: 4 + 6i

    return 0;
}
