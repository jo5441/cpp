int main() {
    int total;
    cout << "Mine Sweeper\n";
    cout << "매설할 지뢰 개수를 입력: ";
    cin >> total;
    cin.ignore(); // getline 전에 버퍼 비우기
    playMineSweeper(total);
    return 0;
}