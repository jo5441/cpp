int main() {
    MonsterWorld world;
    world.addMonster(new Smombi(2, 2));
    world.addMonster(new Siangshi(5, 4));
    world.addMonster(new MyMonster(10, 1));
    world.play();
    return 0;
}