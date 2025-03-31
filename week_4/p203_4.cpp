#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

class PuzzleGame {
private:
    int size;  // 퍼즐 크기
    vector<vector<string>> board;  // 퍼즐 보드
    pair<int, int> empty_pos;  // 빈 칸 위치
    vector<string> moves;  // 이동 내역
    time_t start_time;  // 게임 시작 시간
    vector<vector<string>> initial_board;  // 최초 섞인 퍼즐 맵

public:
    // 생성자: 퍼즐 크기 설정
    PuzzleGame(int s = 4);

    // 퍼즐 보드 생성
    vector<vector<string>> createBoard();

    // 보드 출력
    void printBoard();

    // 퍼즐 섞기 (랜덤하게 섞기)
    void shuffle();

    // 이동하기
    void makeMove(const string& direction);

    // 이동이 유효한지 확인
    bool isValidMove(pair<int, int> target);

    // 빈 칸이 이동할 수 있는 방향을 반환
    vector<string> getPossibleMoves();

    // 게임 종료 여부 확인 (게임이 맞춰졌는지)
    bool isGameWon();

    // 게임 저장
    void saveGame(const string& filename);

    // 게임 불러오기
    void loadGame(const string& filename);

    // 랭킹 저장
    void saveRanking(const string& filename, int score);

    // 랭킹 불러오기
    vector<pair<int, time_t>> loadRanking(const string& filename);

    // 리플레이 (이동 내역 출력)
    void replay();

    time_t getStartTime();  // 시작 시간 반환
};

// 생성자: 퍼즐 크기 설정
PuzzleGame::PuzzleGame(int s) : size(s) {
    board = createBoard();
    empty_pos = {size - 1, size - 1};  // 빈 칸 위치 (맨 마지막)
    moves.clear();
    start_time = time(0);  // 게임 시작 시간
    initial_board = board; // 최초 섞인 퍼즐 보드 저장
}

// 퍼즐 보드 생성
vector<vector<string>> PuzzleGame::createBoard() {
    vector<vector<string>> new_board(size, vector<string>(size));
    char c = 'A';  // 예시로 문자로 채워넣기 (그림 퍼즐)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            new_board[i][j] = (i == size - 1 && j == size - 1) ? " " : string(1, c++);
        }
    }
    return new_board;
}

// 보드 출력
void PuzzleGame::printBoard() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// 퍼즐 섞기 (랜덤하게 섞기)
void PuzzleGame::shuffle() {
    for (int i = 0; i < 1000; ++i) {
        vector<string> possible_moves = getPossibleMoves();
        makeMove(possible_moves[rand() % possible_moves.size()]);
    }
}

// 이동하기
void PuzzleGame::makeMove(const string& direction) {
    int x = empty_pos.first;
    int y = empty_pos.second;
    pair<int, int> target;

    if (direction == "up") {
        target = {x - 1, y};
    } else if (direction == "down") {
        target = {x + 1, y};
    } else if (direction == "left") {
        target = {x, y - 1};
    } else if (direction == "right") {
        target = {x, y + 1};
    }

    // 이동이 유효한지 확인
    if (isValidMove(target)) {
        swap(board[x][y], board[target.first][target.second]);
        empty_pos = target;
        moves.push_back(direction);
    }
}

// 이동이 유효한지 확인
bool PuzzleGame::isValidMove(pair<int, int> target) {
    int x = empty_pos.first;
    int y = empty_pos.second;
    return target.first >= 0 && target.first < size && target.second >= 0 && target.second < size;
}

// 빈 칸이 이동할 수 있는 방향을 반환
vector<string> PuzzleGame::getPossibleMoves() {
    vector<string> moves;
    int x = empty_pos.first;
    int y = empty_pos.second;
    if (x > 0) moves.push_back("up");
    if (x < size - 1) moves.push_back("down");
    if (y > 0) moves.push_back("left");
    if (y < size - 1) moves.push_back("right");
    return moves;
}

// 게임 종료 여부 확인 (게임이 맞춰졌는지)
bool PuzzleGame::isGameWon() {
    char c = 'A';
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size - 1 && j == size - 1) break;
            if (board[i][j] != string(1, c++)) return false;
        }
    }
    return true;
}

// 게임 저장
void PuzzleGame::saveGame(const string& filename) {
    ofstream file(filename, ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(reinterpret_cast<char*>(&start_time), sizeof(start_time));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file.write(board[i][j].c_str(), sizeof(char));
            }
        }
        size_t moves_size = moves.size();
        file.write(reinterpret_cast<char*>(&moves_size), sizeof(moves_size));
        for (const string& move : moves) {
            size_t len = move.size();
            file.write(reinterpret_cast<char*>(&len), sizeof(len));
            file.write(move.c_str(), len);
        }
        file.close();
    }
}

// 게임 불러오기
void PuzzleGame::loadGame(const string& filename) {
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        file.read(reinterpret_cast<char*>(&start_time), sizeof(start_time));
        board.resize(size, vector<string>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                file.read(&board[i][j][0], sizeof(char));
            }
        }
        size_t moves_size;
        file.read(reinterpret_cast<char*>(&moves_size), sizeof(moves_size));
        moves.resize(moves_size);
        for (size_t i = 0; i < moves_size; ++i) {
            size_t len;
            file.read(reinterpret_cast<char*>(&len), sizeof(len));
            moves[i].resize(len);
            file.read(&moves[i][0], len);
        }
        file.close();
    }
}

// 랭킹 저장
void PuzzleGame::saveRanking(const string& filename, int score) {
    vector<pair<int, time_t>> ranking = loadRanking(filename);
    ranking.push_back({score, time(0)});
    sort(ranking.begin(), ranking.end(), greater<pair<int, time_t>>());

    // 상위 10개만 저장
    if (ranking.size() > 10) {
        ranking.pop_back();
    }

    ofstream file(filename, ios::binary);
    for (const auto& entry : ranking) {
        file.write(reinterpret_cast<const char*>(&entry.first), sizeof(entry.first));
        file.write(reinterpret_cast<const char*>(&entry.second), sizeof(entry.second));
    }
    file.close();
}

// 랭킹 불러오기
vector<pair<int, time_t>> PuzzleGame::loadRanking(const string& filename) {
    vector<pair<int, time_t>> ranking;
    ifstream file(filename, ios::binary);
    if (file.is_open()) {
        while (file.peek() != EOF) {
            int score;
            time_t timestamp;
            file.read(reinterpret_cast<char*>(&score), sizeof(score));
            file.read(reinterpret_cast<char*>(&timestamp), sizeof(timestamp));
            ranking.push_back({score, timestamp});
        }
        file.close();
    }
    return ranking;
}

// 리플레이 (이동 내역 출력)
void PuzzleGame::replay() {
    cout << "Replay of moves:" << endl;
    for (const string& move : moves) {
        cout << move << endl;
        makeMove(move);
        printBoard();
        _sleep(1);
    }
}

time_t PuzzleGame::getStartTime() { return start_time; }

// 메인 함수
int main() {
    srand(time(0));  // 랜덤 시드 초기화
    int size;
    cout << "퍼즐 크기를 입력하세요 (3, 4, 5 중 선택): ";
    cin >> size;

    PuzzleGame game(size);
    game.shuffle();
    game.printBoard();

    while (true) {
        cout << "이동할 방향을 입력하세요 (up, down, left, right): ";
        string move;
        cin >> move;

        if (move == "quit") break;
        game.makeMove(move);
        game.printBoard();

        if (game.isGameWon()) {
            cout << "축하합니다! 퍼즐을 맞추셨습니다!" << endl;
            break;
        }
    }

    // 게임 저장 여부
    cout << "게임을 저장하시겠습니까? (y/n): ";
    char save;
    cin >> save;
    if (save == 'y') {
        cout << "저장할 파일 이름을 입력하세요: ";
        string filename;
        cin >> filename;
        game.saveGame(filename);
    }

    // 랭킹 저장
    int score = game.moves.size();
    game.saveRanking("ranking.dat", score);

    // 최고 점수 출력
    vector<pair<int, time_t>> ranking = game.loadRanking("ranking.dat");
    cout << "랭킹:" << endl;
    for (const auto& entry : ranking) {
        cout << "점수: " << entry.first << ", 시간: " << ctime(&entry.second);
    }

    // 리플레이
    cout << "리플레이를 원하시면 'y'를 입력하세요: ";
    char replay_choice;
    cin >> replay_choice;
    if (replay_choice == 'y') {
        game.replay();
    }

    return 0;
}
