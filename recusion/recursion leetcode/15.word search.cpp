class Solution {
public:
    
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    int vis[7][7];
    bool f(int i, int j, vector<vector<char>>&board , string word,int index){
        int m = board.size();
        int n = board[0].size();
        if(index == word.size()) return true;
        for(int k=0;k<4;k++){
            int nr = dr[k]+i;
            int nc = dc[k]+j;
            if(nr>=0 && nc>=0 && nr<m && nc<n){
                if(board[nr][nc] == word[index]){
                      if(!vis[nr][nc]){
                      vis[nr][nc]=1;
                      if(f(nr,nc,board,word,index+1)) return true;
                      vis[nr][nc]=0;
                      }
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(f(i,j,board,word,1)) return true;
                    vis[i][j]=0;
                }
            }
        }

        return false;
     

    }
};