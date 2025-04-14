#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAXWORDS = 100;

struct WordPair {
    string eng; // 영어 단어
    string kor; // 한글 설명
};

class MyDic {
    WordPair words[MAXWORDS]; // 저장된 단어 배열
    int nwords;               // 현재 등록된 단어 수

public:
    // 생성자에서 단어 수 초기화
    MyDic() { nwords = 0; }

    // 하나의 단어 추가
    void add(string eng, string kor) {
        if (nwords < MAXWORDS) {
            words[nwords].eng = eng;
            words[nwords].kor = kor;
            nwords++;
        }
    }

    // 파일에서 단어 읽기
    void load(string filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "파일을 열 수 없습니다." << endl;
            return;
        }

        nwords = 0; // 초기화
        string eng, kor;
        while (inFile >> eng >> kor) {
            add(eng, kor);
        }
        inFile.close();
    }

    // 파일에 모든 단어 저장
    void store(string filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "파일을 저장할 수 없습니다." << endl;
            return;
        }

        for (int i = 0; i < nwords; i++) {
            outFile << words[i].eng << " " << words[i].kor << endl;
        }
        outFile.close();
    }

    // 모든 단어를 화면에 출력
    void print() {
        for (int i = 0; i < nwords; i++) {
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    // id번째의 영어 단어 반환
    string getEng(int id) {
        if (id >= 0 && id < nwords)
            return words[id].eng;
        return "";
    }

    // id번째의 한글 설명 반환
    string getKor(int id) {
        if (id >= 0 && id < nwords)
            return words[id].kor;
        return "";
    }
};
