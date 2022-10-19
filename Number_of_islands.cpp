class Solution {
    
    void  mark_current_island(vector<vector<char>>& grid, int x,int y, int r, int c){
        
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]!='1')  //Boundary case for matrix
            return;
        
        //Mark current cell as visited
        grid[x][y] = '2';
        
        //Make recursive call in all 4 adjacent directions
        mark_current_island(grid,x+1,y,r,c);  //DOWN
        mark_current_island(grid,x,y+1,r,c);  //RIGHT
        mark_current_island(grid,x-1,y,r,c);  //TOP
        mark_current_island(grid,x,y-1,r,c);  //LEFT
        }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        
        if(m==0) return 0;
    //    vector<vector<bool>> vis(n,vector<bool>(n,false));
        int count=0;
        for(int i = 0 ; i < m;i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == '1' ){
                    mark_current_island(grid,i,j,m,n);
                    count+=1;
                }
            }
        }
        return count;
    }
};
