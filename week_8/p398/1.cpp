#include <iostream>
#include <cstring>

class Sample {
    char *name;
    static int count;

public:
    // 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        count++;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
        count--;
    }

    // 정적 함수
    static void printcount() {
        std::cout << "Sample 객체의 개수: " << count << std::endl;
    }
};

int Sample::count = 0;

int main() {
    Sample a("sample");
    Sample::printcount(); // 1

    Sample b(a);
    Sample::printcount(); // 2

    return 0;
}
