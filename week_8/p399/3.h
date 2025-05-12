int main() {
    MonsterWorld world;

    world.addMonster(new Monster());
    world.addMonster(new Monster());

    world.printAll();
    cout << "== 먹이 -150씩 제공 ==" << endl;
    world.feedAll(-150); // 일부러 굶기기

    world.checkStarvation();  // 에너지 0 이하인 몬스터 제거
    world.printAll();         // 남은 몬스터 정보 출력

    return 0;
}