#include<iostream>
using namespace std;
//here we have initialized board char array.
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char token='x';
bool tie=false;
string n1;
string n2;
//display board.
void displayboard()
{
    
  
    cout<<"   |    |  \n";
    cout<<" "<<board[0][0]<<" |"<<board[0][1]<<"   | "<<board[0][2]<<"  \n";
    cout<<"___|____|___\n";
    cout<<"   |    |    \n";
    cout<<" "<<board[1][0]<<" |"<<board[1][1]<<"   | "<<board[1][2]<<"  \n";
    cout<<"___|____|___\n";
    cout<<"   |    |    \n";
    cout<<" "<<board[2][0]<<" |"<<board[2][1]<<"   | "<<board[2][2]<<"  \n";
    cout<<"   |    |  \n";


}
//place where players want to enter.
void locfunction()
{
    int digit;
    if(token=='x')
    {
        cout<<n1<<" please enter:";
        cin>>digit;
    }
     if(token=='0')
    {
        cout<<n2<<" please enter:";
        cin>>digit;
    }
   
  switch(digit)
  {
    case 1: row=0;
    column=0;
    break;
    case 2: row=0;
    column=1;
    break;
    case 3:row=0;
    column=2;
    break;
    case 4:row=1;
    column=0;
    break;
    case 5:row=1;
    column=1;
    break;
    case 6:row=1;
    column=2;
    break;
    case 7:row=2;
    column=0;
    break;;
    case 8:row=2;
    column=1;
    break;
    case 9:row=2;
    column=2; 
    break;
    default : cout<<"invalid"<<endl;
    

  }
  
   if(token=='x'&& board[row][column]!='x'&&board[row][column]!='0')
   {
   board[row][column]='x';
   token='0';
   }

    else if(token=='0'&& board[row][column]!='x'&&board[row][column]!='0')
   {
   board[row][column]='0';
   token='x';
   }
   else{
    cout<<"there is no empty space:"<<endl;
    locfunction();
    
   

   }
   

}
//winner situation
bool winfunction()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2] ||board[0][i]==board[1][i]&&board[0][i]==board[2][i])
        return true;
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2] ||board[0][2]==board[1][1]&&board[1][1]==board[2][0])
    {
        return true;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         if(board[i][j]!='x'&&  board[i][j]!='0')
          {
            return false;
          }

        }
    }
    tie=true;
    return true;
}
int main()
{

cout<<"*************************Welcome to tic-tac-toe Game**************************\n\n\n"<<endl;
cout<<"how to play the game?\n\n\n\n\n"<<endl;
cout<<"Program a two-person game of Tic-Tac-Toe. \n The game is played on a three by three board. \n Each player has a marker One player has an X, the other an o.\n  Players alternate turns to place their marker on the board.\n\n\n"<<endl;
cout<<"************************* Winner situation *****************************\n\n\n"<<endl;
cout<<"The first player to get three in a row either diagonally, horizontally, or vertically, \n  wins the games.In the event all squares are taken on the board without a winner then it is a tie.\n\n\n"<<endl;

cout<<"Now let's start the game"<<endl;

    cout<<"So: \nplease enter the name of the first player :\n";
    getline(cin,n1);
    cout<<"please enter the name of the second player :\n";
    getline(cin,n2);
    cout<<n1<<" is player1 so he/she will play first \n";
    cout<<n2<<" is player1 so he/she will play second \n";
    

    while(!winfunction())
    {
        displayboard();
        locfunction();
        winfunction();

    }
    if(token=='x'&&tie==false)
    {
        displayboard();
        cout<<n2<<" wins!"<<endl;
    }
     else if(token=='0'&& tie==false)
    {
        displayboard();
        cout<<n1<<" wins!"<<endl;
    }
    else {
        displayboard();
        cout<<"it is a draw!"<<endl;
    }

}