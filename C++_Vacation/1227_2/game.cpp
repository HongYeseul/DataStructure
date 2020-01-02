#include <iostream>
using namespace std;

class Player{
    Card card[15];
    int cardNum;
    public:
        char name[10];
        string getName();
        void put();
        void get();
        int getNum();
        bool trueCard();
};

class Game{
    Card card[100];
    Player player[3];
    int num_players;
public:
    void run();
private:
    void shuffle();
};

void Game :: run(){
    shuffle(); //카드를 섞는다 
    
    while(1){
        for(int player =0; player < num_players ; player++){
            //1. 플레이어1이 카드를 낸다
            if(player[player].trueCard() == 0)
                player[player].put();
            else
                player[player].get();
            //2. 낸 카드가 유효한가?
            //3. 플레이어가 갖고있는 카드가 없으면 게임 끝
            if(player[player].getNum() == 0){
                cout << "player " << player[player].getName() << "win!" << endl;
                break;
            }
        }
    }
}

int main(){
    Game game;
    game.run();
}
