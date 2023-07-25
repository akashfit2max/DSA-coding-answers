class Solution {
    vector<int>temp;
private:
    void dfs(int s, int e, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& temp) {
        temp.push_back(s);
        if(s == e) {
            ans.push_back(temp);
        }
        for(auto i : graph[s]) {
            dfs(i,e,graph,ans,temp);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(0,n-1,graph,ans,temp);
        return ans;
    }
};