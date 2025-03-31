#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <vector>
#include <string>
#include <ctime>
#include <utility>

class PuzzleGame {
private:
    int size;  // 퍼즐 크기
    std::vector<std::vector<int>> board;  // 퍼즐 보드
    std::pair<int, int> empty_pos;  // 빈 칸 위치
    std::vector<std::string> moves;  // 이동 내역
    time_t start_time;  // 게임 시작 시간

public:
    // 생성자: 퍼즐 크기 설정
    PuzzleGame(int s = 4);

    // 퍼즐 보드 생성
    std::vector<std::vector<int>> createBoard();

    // 보드 출력
    void printBoard();

    // 퍼즐 섞기 (랜덤하게 섞기)
    void shuffle();

    // 이동하기
    void makeMove(const std::string& direction);

    // 이동이 유효한지 확인
    bool isValidMove(std::pair<int, int> target);

    // 빈 칸이 이동할 수 있는 방향을 반환
    std::vector<std::string> getPossibleMoves();

    // 게임 종료 여부 확인 (게임이 맞춰졌는지)
    bool isGameWon();

    // 게임 저장
    void saveGame(const std::string& filename);

    // 게임 불러오기
    void loadGame(const std::string& filename);

    // 랭킹 저장
    void saveRanking(const std::string& filename, int score);

    // 랭킹 불러오기
    std::vector<std::pair<int, time_t>> loadRanking(const std::string& filename);

    // 리플레이 (이동 내역 출력)
    void replay();

    time_t getStartTime();  // 시작 시간 반환
};

#endif // PUZZLE_GAME_H
