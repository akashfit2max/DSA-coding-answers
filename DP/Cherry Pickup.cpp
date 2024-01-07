class Solution {
    int maxc = 0;

    //  DFS from top to bottom
    private void solve(int r, int c, int[][] grid, int ccsf, int n, int m) {
        // boundary cond
        if(r >= n || c >= m || grid[r][c] == -1) return;
        // base case
        if(r == n-1 && c == m-1) {
            helper(r,c,grid,ccsf,n,m);
            return;
        }

        int cherries = grid[r][c];
        grid[r][c] = 0;
        solve(r+1,c,grid,ccsf + cherries,n,m);
        solve(r,c+1,grid,ccsf + cherries,n,m);
        grid[r][c] = cherries;
    }

    private void helper(int r, int c, int[][] grid, int ccsf, int n, int m) {
        // boundary cond
        if(r < 0 || c < 0 || grid[r][c] == -1) return;
        // base case
        if(r == 0 && c == 0) {
            ccsf += grid[r][c];
            maxc = Math.max(maxc,ccsf);
            return;
        }

        int cherries = grid[r][c];
        grid[r][c] = 0;
        helper(r-1,c,grid,ccsf + cherries,n,m);
        helper(r,c-1,grid,ccsf + cherries,n,m);
        grid[r][c] = cherries;
    }

    // recursion
    public int recursion(int[][] grid,int r1,int c1,int r2,int c2) {
        if(r1>=grid.length || r2>=grid.length || c1>=grid[0].length || c2>=grid[0].length || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return Integer.MIN_VALUE;
        }
        if(r1==grid.length-1 && c1==grid[0].length-1){
             return grid[r1][c1];
        }
        int cherry=0;
        if(r1==r2 && c1==c2){
            cherry+=grid[r1][c1];
        }else{
            cherry+=grid[r1][c1]+grid[r2][c2];
        }
        int dir1=recursion(grid,r1+1,c1,r2+1,c2);
        int dir2=recursion(grid,r1,c1+1,r2,c2+1);
        int dir3=recursion(grid,r1+1,c1,r2,c2+1);
        int dir4=recursion(grid,r1,c1+1,r2+1,c2);
        cherry+=Math.max(Math.max(dir1,dir2),Math.max(dir3,dir4));
        return cherry;
    }    


    // memoization
    Integer[][][][] dp;
    public int memo(int[][] grid,int r1,int c1,int r2,int c2) {
        if(r1>=grid.length || r2>=grid.length || c1>=grid[0].length || c2>=grid[0].length || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return Integer.MIN_VALUE;
        }
        if(r1==grid.length-1 && c1==grid[0].length-1){
             return grid[r1][c1];
        }
        if(dp[r1][c1][r2][c2]!=null){
            return dp[r1][c1][r2][c2];
        }
        int cherry=0;
        if(r1==r2 && c1==c2){
            cherry+=grid[r1][c1];
        }else{
            cherry+=grid[r1][c1]+grid[r2][c2];
        }
        int dir1=memo(grid,r1+1,c1,r2+1,c2);
        int dir2=memo(grid,r1,c1+1,r2,c2+1);
        int dir3=memo(grid,r1+1,c1,r2,c2+1);
        int dir4=memo(grid,r1,c1+1,r2+1,c2);
        cherry+=Math.max(Math.max(dir1,dir2),Math.max(dir3,dir4));
        return dp[r1][c1][r2][c2] = cherry;
    }    


    Integer[][][] dp2;
    public int memoop(int[][] grid,int r1,int c1,int r2) {
        int c2 = r1+c1-r2;
        if(r1>=grid.length || r2>=grid.length || c1>=grid[0].length || c2>=grid[0].length || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return Integer.MIN_VALUE;
        }
        if(r1==grid.length-1 && c1==grid[0].length-1){
             return grid[r1][c1];
        }
        if(dp2[r1][c1][r2]!=null){
            return dp2[r1][c1][r2];
        }
        int cherry=0;
        if(r1==r2 && c1==c2){
            cherry+=grid[r1][c1];
        }else{
            cherry+=grid[r1][c1]+grid[r2][c2];
        }
        int dir1=memoop(grid,r1+1,c1,r2+1);
        int dir2=memoop(grid,r1,c1+1,r2);
        int dir3=memoop(grid,r1+1,c1,r2);
        int dir4=memoop(grid,r1,c1+1,r2+1);
        cherry+=Math.max(Math.max(dir1,dir2),Math.max(dir3,dir4));
        return dp2[r1][c1][r2] = cherry;
    }    

    public int cherryPickup(int[][] grid) {
        // brute force backtracking
        int n = grid.length, m = grid[0].length;
        // solve(0,0,grid,0,n,m);
        // return maxc;
        dp = new Integer[n][n][n][n];
        dp2 = new Integer[n][n][n];
        // return Math.max(0,recursion(grid,0,0,0,0));
        // return Math.max(0,memo(grid,0,0,0,0));
        return Math.max(0,memoop(grid,0,0,0));
    }
}