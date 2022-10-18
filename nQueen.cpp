#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
bool isSafe(vector<vector<int>> board, int n, int row, int col){
    for(int i=0; i<col; i++){
        if(board[row][i]) return false; 
    }
    for(int i=row, j=col; (i>=0 && j>=0); i--, j--){
        if(board[i][j]) return false;
    }
    for(int i=row, j=col; (i<n && j>=0); i++, j--){
        if(board[i][j] ) return false;
    }
    return true;
}
void nQueenRec(vector<vector<int>> board, int n, int col , vector<int> curr){
    if(col==n){
        ans.push_back(curr);
        return;
    }
    for(int i=0; i<n; i++){
        if(isSafe(board, n, i, col)){
            curr.push_back(i+1);
            board[i][col]=1;
            nQueenRec(board, n, col+1, curr);
            board[i][col]=0;
            curr.pop_back();
        }   
    }
}
vector<vector<int>> nQueen(int n){
    // code here
    ans.clear();
    vector<int> curr;
    vector<vector<int>> board(n, vector<int>(n,0));
    nQueenRec(board, n, 0, curr);
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> ans = nQueen(n);
    if(ans.size() == 0)
        cout<<-1<<"\n";
    else {
        for(int i = 0;i < ans.size();i++){
            cout<<"[";
            int j=1;
            for(int u: ans[i])
                cout<< "("<< j++<<", "<<u<< ") ";
            cout<<"] \n";

        }
        cout<<endl;
    }
    return 0;
}