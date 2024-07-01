#include<iostream>
using namespace std;
void drawboard(char*spaces);
void player1choice(char*spaces, char player1);
void player2choice(char*spaces, char player2);
bool checkwinner(char*spaces,char player1, char player2);
bool draw(char*spaces);
int main(){
    char ans;
    char player1='X';
    char player2='O';
    do{
    char spaces[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    bool running=true;
    drawboard(spaces);
    while(running){
    player1choice(spaces,player1);
    drawboard(spaces);
    if(checkwinner(spaces,player1,player2)){
        running=false;
        break;
    }
    if (draw(spaces)){
        running=false;
        break;
    }
    player2choice(spaces,player2);
    drawboard(spaces);
    if(checkwinner(spaces,player1,player2)){
        running=false;
        break;
    }
    if (draw(spaces)){
        running=false;
        break;
    }
    }
    cout << "Do you wish to play another game? (y/n): ";
        cin >> ans;
     }while (ans == 'y' || ans == 'Y');
    cout<<"Thank you for playing!!\n";
    cout<<"Goodbye!!";
    return 0;
    }
void drawboard(char*spaces){
    cout<<"\n";
    cout<<"     |     |     \n";
    cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<  "\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<  "\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<  "\n";
    cout<<"     |     |     \n";
    cout<<"\n";
}
void player1choice(char*spaces, char player1){
    int number=-1;
    while(number>8||number<0||spaces[number]!=' '){
     cout<<"Player 1\n";    
     cout<<"Enter the position where you would like to put 'X' from(1 to 9):";
     cin>>number;
     number--;
     if(spaces[number]==' '){
         spaces[number]=player1;
         break;
     }
     cout<<"Invalid choice\n Try again!";
    }
}
void player2choice(char*spaces, char player2){
    int number=-1;
    while(number>8||number<0||spaces[number]!=' '){
     cout<<"Player 2\n";    
     cout<<"Enter the position where you would like to put 'O' from(1 to 9):";
     cin>>number;
     number--;
     if(spaces[number]==' '){
         spaces[number]=player2;
         break;
     }
     cout<<"Invalid choice\n Try again!";
    }
}
bool checkwinner(char*spaces,char player1, char player2){
    if(spaces[0]==spaces[1]&&spaces[1]==spaces[2]&&spaces[0]!=' '){
        spaces[0]==player1? cout<<"Player 1 you won!\n" : cout<<"Player 2 you won";
        return true;
    }
    else if(spaces[3]==spaces[4]&&spaces[4]==spaces[5]&& spaces[3]!=' '){
        spaces[3]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[6]==spaces[7]&&spaces[7]==spaces[8]&& spaces[6]!=' '){
        spaces[6]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[0]==spaces[4]&&spaces[4]==spaces[8]&& spaces[0]!=' '){
        spaces[0]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[2]==spaces[4]&&spaces[4]==spaces[6]&& spaces[2]!=' '){
        spaces[2]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[0]==spaces[3]&&spaces[3]==spaces[6]&& spaces[0]!=' '){
        spaces[0]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[1]==spaces[4]&&spaces[4]==spaces[7]&& spaces[1]!=' '){
        spaces[1]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    else if(spaces[2]==spaces[5]&&spaces[5]==spaces[8]&& spaces[2]!=' '){
        spaces[2]==player1? cout<<"Player 1 you won\n": cout<<"Player 2 you won\n"; 
        return true;
    }
    return false;
}
bool draw(char*spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' '){
            return false;
        }
    }
    cout<<"It is a draw!\n";
    return true;
}
