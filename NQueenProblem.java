public class NQueenProblem {
    public static void main(String[] args){
        problem p = new problem(8);
        p.Solution();
    }
}
class problem{
    int n;
    public problem(int n){
        this.n = n;
    }
    public void Solution(){
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                board[i][j] = 0;
            }
        }
        solve(board);
    }
    public void solve(int[][] board){
        method(board,0);
        printSolution(board);
    }
    public void printSolution(int[][] board)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.print(" " + board[i][j]
                        + " ");
            System.out.println();
        }
    }
    public boolean method(int[][] board, int col){
        if (col>=n){
            return true;
        }
        for (int i = 0; i<n; i++){
            if (safe(board, i, col)){
                board[i][col] = 1;
                if (method(board, col + 1)){
                    return true;
                }
            }
            board[i][col] = 0;
        }
        return false;
    }
    public boolean safe(int[][] board, int row, int col ){
        for (int i = 0; i<col; i++){
            if (board[row][i] == 1){
                return false;
            }
        }
        for (int i = row, j = col; i>=0 && j >= 0; i--, j--){
            if (board[i][j]==1){
                return false;
            }
        }
        for (int i = row, j = col; i<n && j >=0; i++ , j--){
            if (board[i][j] == 1){
                return false;
            }
        }
        return true;
    }
}