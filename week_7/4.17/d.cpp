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

    // 출력 함수
    void print() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // 멤버 함수 add: a.add(b) → return a + b
    Complex add(Complex& other) {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }
};

int main() {
    Complex a(1, 2);   // a = 1 + 2i
    Complex b(3, 4);   // b = 3 + 4i

    Complex c = a.add(b); // c = a + b

    cout << "Result (c = a.add(b)): ";
    c.print();  // 출력: 4 + 6i

    return 0;
}
