#include <iostream>
#include <string>
using namespace std;

// 예외 클래스 정의
class AccountException {
    string message;
    int amount;

public:
    AccountException(string msg, int amt)
        : message(msg), amount(amt) {}

    string getMessage() const { return message; }
    int getAmount() const { return amount; }
};

// 고객 계좌 클래스
class CustomerAccount {
    int balance;

public:
    CustomerAccount(int b = 0) : balance(b) {}

    int getBalance() const { return balance; }

    int deposit(int amount) {
        if (amount <= 0)
            throw AccountException("입금 금액이 0 이하입니다.", amount);
        balance += amount;
        return balance;
    }

    int withdraw(int amount) {
        if (amount > balance)
            throw AccountException("출금 금액이 잔액보다 많습니다.", amount);
        balance -= amount;
        return balance;
    }
};
