class Solution {
public:
    int drow[4] = {-1,0,+1,0};
    int dcol[4] = {0,+1,0,-1};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>>q;
        int count = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0,0});
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    count ++;
                }
            }
        }

        // 2^count-1 - we got all keys
        int final_key_status_decimal = pow(2,count)-1;
        int vis[m][n][final_key_status_decimal+1];
        memset(vis,0,sizeof(vis));

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            int r = temp[0];
            int c = temp[1];
            int steps = temp[2];
            int curr_key_status_decimal = temp[3];

            if(curr_key_status_decimal == final_key_status_decimal) return steps;

            // 4 dir
            for(int i=0; i<4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                // boundary check
                if(nr >=0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != '#') {

                    char ch = grid[nr][nc];
                    // 3 case
                    // 1- lock
                    if(ch >= 'A' && ch <= 'F') {
                        if(vis[nr][nc][curr_key_status_decimal]==0 && (curr_key_status_decimal >> (ch-'A')) & 1 == 1 ) {
                            vis[nr][nc][curr_key_status_decimal] = 1;
                            q.push({nr,nc,steps+1,curr_key_status_decimal});
                        }

                    }
                    // 2 - key
                    else if (ch >= 'a' && ch <= 'f') {
                        int new_key_status_decimal = (1 << (ch-'a')) | curr_key_status_decimal;
                        if(vis[nr][nc][new_key_status_decimal]==0) {
                            vis[nr][nc][new_key_status_decimal] = 1;
                            q.push({nr,nc,steps+1,new_key_status_decimal});
                        }
                    }
                    // 3- dot
                    else {
                        if(vis[nr][nc][curr_key_status_decimal]==0) {
                            vis[nr][nc][curr_key_status_decimal] = 1;
                            q.push({nr,nc,steps+1,curr_key_status_decimal});
                        }
                    }
                }
            }
        } 
        return -1;
    }
};