// constructing unordered_sets
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isVaild(vector<vector<char> > &board, char test, int vert, int hori){
        if(board[vert][hori] == test){
            return true;
        }
        
        for(int i = 0; i < 9; i++){
            if(board[vert][i] == test){
                return false;
            }
            if(board[i][hori] == test){
                return false;
            }
        }
        int vv = vert / 3;
        int hh = hori / 3;
 
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
               if(board[3 * vv + i][3 * hh + j] == test){
                   return false;
               }
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char> > &board, int vert, int hori){
        while(board[vert][hori] != '.'){
            hori++;
            vert = vert + hori/9;
            hori = hori%9;
            if(vert == 9){
                return true;
            }
        }
        
        for(char i = '1'; i <= '9'; i++){
            if(isVaild(board, i, vert, hori)){
                board[vert][hori] = i;
                if(solveSudoku(board, vert , hori)){
                    return true;
                }else{
                    board[vert][hori] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        solveSudoku(board, 0, 0);
    }

};


int main(int argv, char* argc[]){
	Solution sl;
	vector<vector<char> > v;
    for (int i = 0; i < 9; ++i)
    {
        vector<char> vv (9,0);
        v.push_back(vv);
    }

    char a[] = {
                '5',
                '3',
                '.',
                '.',
                '7',
                '.',
                '.',
                '.',
                '.',
                '6',
                '.',
                '.',
                '1',
                '9',
                '5',
                '.',
                '.',
                '.',
                '.',
                '9',
                '8',
                '.',
                '.',
                '.',
                '.',
                '6',
                '.',
                '8',
                '.',
                '.',
                '.',
                '6',
                '.',
                '.',
                '.',
                '3',
                '4',
                '.',
                '.',
                '8',
                '.',
                '3',
                '.',
                '.',
                '1',
                '7',
                '.',
                '.',
                '.',
                '2',
                '.',
                '.',
                '.',
                '6',
                '.',
                '6',
                '.',
                '.',
                '.',
                '.',
                '2',
                '8',
                '.',
                '.',
                '.',
                '.',
                '4',
                '1',
                '9',
                '.',
                '.',
                '5',
                '.',
                '.',
                '.',
                '.',
                '8',
                '.',
                '.',
                '7',
                '9'};

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            v[i][j] = '.';
        }
    }

    sl.solveSudoku(v);

     for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << v[i][j] << "\t";
            if (j%3 == 2)
            {
                cout << "\t";
            }
        }
        cout << endl;
        if (i%3 == 2)
        {
                cout << endl;
        }
    }
}