int main() {
    MyDic dic;

    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("computer", "컴퓨터");

    dic.print();

    dic.store("words.txt");

    // 새 객체에 불러오기
    MyDic newDic;
    newDic.load("words.txt");
    newDic.print();

    cout << "ID 1의 영어 단어: " << newDic.getEng(1) << endl;
    cout << "ID 1의 한글 설명: " << newDic.getKor(1) << endl;

    return 0;
}