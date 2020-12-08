#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    while(1){
        int computer,you;
        do {
            computer = rand() % 3;
            do {
                cout << "请出手，0（石头），1（剪刀），2（布）：";
                cin >> you;
            }while (you < 0 || you >2);
                switch(you - computer){
                    case 0:
                    cout << "平手" << endl;
                    break;
                    case 1: case -2:
                    cout << "你输了！"<<endl;
                    break;
                    case -1: case 2:
                    cout << " 你赢了!" <<endl;
                }
        }while (computer == you);
        cout << "还要玩吗?Y/N:";
        char play;
        cin >>play;
        if (play == 'N'||play == 'n')break;
    }
        return 0;
}