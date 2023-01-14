class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int delrow[], int delcol[], 
    int ini_color,    int color) {
        ans[row][col] = color;

        for(int i=0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];

            if(nrow >=0 && nrow < image.size() && ncol>=0 && ncol < image[0].size() && image[nrow][ncol] == ini_color && 
            ans[nrow][ncol] != color) {
                dfs(nrow,ncol,image,ans,delrow,delcol,ini_color,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_color = image[sr][sc];
        vector<vector<int>>ans = image;

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        dfs(sr,sc,image,ans,delrow,delcol,ini_color,color);

        return ans;
    }
};