#include "RussianRoulette.h"

int playRussianRoulette(int nTurns, int nBullets, int nChambers) {
    int start = rand() % nTurns;
    printf("\n총을 돌렸습니다. %d번부터 시작합니다.\n", start + 1);

    while (true) {
        int pos = rand() % nChambers;
        printf("[%d번] 탄창을 무작위로 돌렸습니다.\n", start + 1);
        printf("\t엔터를 누르면 격발됩니다...");
        getchar();

        if (pos < nBullets) break;

        printf("\t휴~~~ 살았습니다!!!!\n");
        start = (start + 1) % nTurns;
    }

    printf("\t빵~~~~~~~~~!!!\n");
    return start + 1;
}

#include "RussianRoulette.h"

void main() {
    int nTurn, nBullets, nChambers;

    srand((unsigned)time(NULL));

    printf("게임 인원 (최소 2) => ");
    scanf("%d", &nTurn);

    printf("총알 개수 (최대 탄창 크기) => ");
    scanf("%d", &nBullets);

    printf("탄창 크기 (최소 1) => ");
    scanf("%d", &nChambers);
   
    getchar(); // 입력 버퍼 비우기

    int bang = playRussianRoulette(nTurn, nBullets, nChambers);
    printf("\n -----> %d번 참가자가 총에 맞았습니다.\n", bang);
}