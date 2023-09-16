class Solution {
public:
    pair<int,int> findPos(int val, int n) {
        int r = n-(val-1)/n-1;
        int c = (val-1)%n;
        return r%2 == n%2 ? make_pair(r,n-1-c) : make_pair(r,c);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        //queue to store where we reach at each step
        queue<int>q;
        q.push(1);
        int steps = 0;
        while(!q.empty()) {
            int s = q.size();
            // iterate over all the cordinates
            for(int i=0; i<s; i++) {
                int val = q.front();
                q.pop();
                if(val == n*n) return steps;
                // 6 faces in a die
                for(int j=1; j<=6; j++) {
                    int currval = val + j;
                    if(currval > n*n) break;
                    pair<int,int>pos = findPos(currval,n);
                    int r = pos.first;
                    int c = pos.second;
                    cout<<"("<<r<<","<<c<<") ";
                    if(!vis[r][c]) {
                        vis[r][c] = true;
                        if(board[r][c] != -1) {
                            q.push(board[r][c]);
                        }
                        else {
                            q.push(currval);
                        }
                    }
                }
                cout<<endl;
            }
            steps++;
        }
        return -1;
    }
};