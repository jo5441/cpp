int main() {
    MyDic dic;

    // 단어 추가
    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("computer", "컴퓨터");

    // 단어장 출력
    cout << "현재 등록된 단어들:" << endl;
    dic.print();

    // 파일로 저장
    dic.store("mydictionary.txt");

    // 새 객체에 불러오기 테스트
    MyDic loadedDic;
    loadedDic.load("mydictionary.txt");

    cout << "\n파일에서 불러온 단어들:" << endl;
    loadedDic.print();

    // 특정 단어 확인
    cout << "\nID 1의 단어: " << loadedDic.getEng(1) << " - " << loadedDic.getKor(1) << endl;

    return 0;
}
