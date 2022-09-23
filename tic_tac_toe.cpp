#include <iostream>
#include <vector>
#include <string>
using namespace std;
void space_tab(){
    for(int i=0;i<40;i++){
        cout<<" ";
    }
}
void update_board(int move, vector<string> &board, int player)
{
    if (player == 1)
    {
        if (move <= 3)
        {
            board[0][move - 1] = 'O';
        }
        else if (move > 3 && move <= 6)
        {
            board[1][move - 4] = 'O';
        }

        else if (move > 6 && move <= 9)
        {
            board[2][move - 7] = 'O';
        }

       
    }

    else if (player == 2)
    {
        if (move <= 3)
        {
            board[0][move - 1] = 'X';
        }
        else if (move > 3 && move <= 6)
        {
            board[1][move - 4] = 'X';
        }

        else if (move > 6 && move <= 9)
        {
            board[2][move - 7] = 'X';
        }

       
    }
}
bool status(vector<string> &board, char sym)
{

    // all columns

    for (int i = 0; i < 3; i++)
    {
        int allcol = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[j][i] == sym)
            {
                allcol++;
            }
            else
            {
                break;
            }
        }
        if (allcol == 3)
        {
            return true;
        }
    }















    // all rows


    for (int i = 0; i < 3; i++)
    {

        int allrows = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == sym)
            {
                allrows++;
            }
            else
            {
                break;
            }
        }
        if (allrows == 3)
        {
            return true;
        }
    }













   //left to right diagnol



   int lrdiag=0;
   for(int i=0;i<3;i++){
    if(board[i][i]==sym){
        lrdiag++;
    }
    else{
        break;
    }

   }

   if(lrdiag==3){
    return true;
   }














/////right to left diagonal

int rlcols=0;

for(int i=0,j=2;i<3&&j>=0;i++,j--){

    if(board[i][j]==sym){
        rlcols++;
    }
    else{
        break;
    }
}


if(rlcols==3){
    return true;
}



return false;











}

void display_board(vector<string> &board)
{  

    cout<<endl<<endl;

for(int i=0;i<3;i++){
    space_tab();
  for(int i=0;i<20;i++)cout<<" ";
    for(int j=0;j<3;j++){
       cout<<board[i][j]<<"  "; 
    }
    cout<<endl;

}
cout<<endl<<endl;

}

int main()
{
    int n = 3;
    int cells = 9;
    int drawflag = 0;
    cout<<endl<<endl;
    space_tab();
    cout <<"*****************   TIC-TAC-TOE  ********************" << endl
         << endl;
    string player1;
    string player2;
    string winner;
    
    vector<string> board(n);
    string st = "....";
    for (int i = 0; i < n; i++)
    {
        board[i] = st;
    }
    space_tab();
    cout << "Hello,Player 1 enter your name:";
    cin >> player1;
    cout<<endl<<endl;
    space_tab();
    cout << "Hello,Player 2 enter your name:";
    cin >> player2;
    int i = 0;
    int move1;
    int move2;
    cout<<endl<<endl;
    space_tab();
    cout<<"Instructions to the players"<<endl<<endl;
    space_tab();
    cout<<player1<<" , your move is O"<<endl;
    space_tab();
    cout<<player2<<" , your move is X"<<endl;
    cout<<endl<<endl;
    space_tab();
    cout<<"Your move is the cell number ex:to change first cell give your move as 1!!"<<endl<<endl;
      space_tab();  
    cout<<"You are ready to play now!!"<<endl<<endl;
    char yes='y';
    while(yes=='y'){
         for (int i = 0; i < n; i++)
    {
        board[i] = st;
    }
    display_board(board);
    while (true)
    {
        if (cells != 0)
        {

            if (i % 2 == 0)
            {   space_tab();
                cout << player1 << ","
                     << "enter move:";
                cells--;
                cin >> move1;
                update_board(move1,board,1);
                display_board(board);
                
                if (status(board, 'O'))
                {
                    winner = player1;
                    break;
                }
            }
            else if (i % 2 != 0)
            {   space_tab();
                cout << player2 << ","
                     << "enter move:";
                cells--;
                cin >> move2;
                update_board(move2,board,2);
                display_board(board);

                if (status(board, 'X'))
                {
                    winner = player2;
                    break;
                }
            }
        }

        else
        {
            drawflag = 1;
            break;
        }
        i++;
    }

    if (drawflag == 1)
    {   space_tab();
        cout << "It is a Draw" << endl;
    }

    else
    {   space_tab();
        cout << winner << " is the Winner!" << endl;
    }
    space_tab();
    cout<<"Do you want to play again[y/n]:";
    cin>>yes;
    
    if(yes=='y'){
        space_tab();
        cout<<"Thank you enjoy pandagoww!!"<<endl;
    }
    else{
        space_tab();
        cout<<"Okay bye bye"<<endl<<endl;
    }
    }
}