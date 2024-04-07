class Solution 
{
    public:
    
    static bool cmp(Job J1, Job J2){
        if(J1.dead != J2.dead)
            return J1.dead < J2.dead;
        return J1.profit > J2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int curr = 0;
        int p = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            Job j = arr[i];
            if(curr < j.dead) {
                curr++;
                pq.push(j.profit);
            }
            else if(curr == j.dead && pq.top() < j.profit) {
                pq.pop();
                pq.push(j.profit);
            }
        }
        
        while(!pq.empty()){
            p += pq.top();
            pq.pop();
        }
        
        return {curr, p};
        
    } 
};