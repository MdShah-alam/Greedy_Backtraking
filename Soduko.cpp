#include<bits/stdc++.h>
using namespace std;
int N=9;
vector<vector<char>>solution_board;

bool solution_found(vector<vector<char> >sudoku_board)
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sudoku_board[i][j]=='.')
                return false;
        }
    }
    return true;
}

pair<int,int>get_first_free_cell(vector<vector<char>>sudoku_board)
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(sudoku_board[i][j]=='.')
                return {i , j};
        }
    }
    return {-1 , -1};
}

vector<char>get_candidates(vector<vector<char>>sudoku_board, pair<int,int >free_cell)
{
    int ro = free_cell.first;
    int col = free_cell.second;

    vector<char>valid_candidates;

    for(char digit='1' ; digit<='9' ; digit++){
        bool is_canidate=true;

        // 1. check the row
        for(int j=0;j<N;j++){
            if(sudoku_board[ro][j]==digit){
                is_canidate=false;
                break;
            }
        }
        // 2. check the column
        for(int i=0;i<N;i++){
            if(sudoku_board[i][col]==digit){
                is_canidate = false;
                break;
            }
        }
        // 3 . check the submatrix

        int r=(ro/3) * 3;
        int c=(col/3) * 3;

        for(int i=r ; i<r+3; i++){
            for(int j = c; j<c+3;j++){
                if(sudoku_board[i][j] == digit){
                    is_canidate=false;
                    break;
                }
            }
        }
        if(is_canidate){
            valid_candidates.push_back(digit);
        }
    }
    return valid_candidates;
}

bool back_track(vector<vector<char>>sudoku_board)
{
    if(solution_found(sudoku_board)){
        solution_board=sudoku_board;
        return true;
    }
    pair<int,int>free_cell = get_first_free_cell(sudoku_board);
    vector<char>candidates = get_candidates(sudoku_board,free_cell);

    for(char candidate : candidates){
        int ro = free_cell.first;
        int col = free_cell.second;

        //- add candidate to state
        sudoku_board[ro][col]=candidate;

        // backtrack(state)
        bool solution_found=back_track(sudoku_board);
        if(solution_found){
            return true;
        }

        // remove candidate from state
        sudoku_board[ro][col]= '.';
    }
    return false;
}

int main()
{
    vector<vector<char>>sudoku_board(N,vector<char>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin>>sudoku_board[i][j];
    }
    back_track(sudoku_board);

    cout<<endl;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<solution_board[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}/**

5 3 . .7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . .6 .
8 . . . 6 . . .3
4 . . 8 .3 . .1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

*/
