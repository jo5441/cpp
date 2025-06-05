int main() {
    CustomerAccount acc(1000);  // 초기 잔액 1000

    cout << "초기 잔액: " << acc.getBalance() << endl;

    // 입금 테스트
    try {
        acc.deposit(500);  // 정상 입금
        cout << "500원 입금 후 잔액: " << acc.getBalance() << endl;

        acc.deposit(-100); // 예외 발생
    } catch (const AccountException& e) {
        cout << "[예외 발생] " << e.getMessage() << " (금액: " << e.getAmount() << ")\n";
    }

    // 출금 테스트
    try {
        acc.withdraw(300);  // 정상 출금
        cout << "300원 출금 후 잔액: " << acc.getBalance() << endl;

        acc.withdraw(2000); // 예외 발생
    } catch (const AccountException& e) {
        cout << "[예외 발생] " << e.getMessage() << " (금액: " << e.getAmount() << ")\n";
    }

    return 0;
}