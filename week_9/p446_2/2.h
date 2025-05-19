int main(){
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    MonsterWorld w;
    w.add(new Jiangshi());
    w.add(new Smombi());
    w.add(new Siangshi());
    w.add(new Boomer());

    for(int i=0;i<120 && std::cin.good();++i){
        w.step();
        std::cout << "Enter 입력 시 다음 턴, Ctrl‑D 종료...";
        std::cin.get();
    }
    return 0;
}