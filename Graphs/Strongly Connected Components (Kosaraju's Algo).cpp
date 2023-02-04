//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    private:
        void dfs(int node, vector<int>&vis, vector<int>adj[], stack<int>&s) {
            vis[node] = 1;
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    dfs(it,vis,adj,s);
                }
            }
            s.push(node);
        }
        
        void dfs2(int node, vector<int>&vis, vector<int>adjT[]) {
            vis[node] = 1;
            for(auto it : adjT[node]) {
                if(!vis[it]) {
                    dfs2(it,vis,adjT);
                }
            }
        }
        
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
    //   step 1 : sort all the edges according to their finishing time
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i,vis,adj,s);
            }
        }
        
    //  step 2 : reverse the edges
        vector<int>adjT[V];
        for(int i=0; i<V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }
        
        // step 3 : do dfs and count the connected components
        int scc = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                scc++;
                dfs2(node,vis,adjT);
            }
        }
        
        return scc;
    }
    
    
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends