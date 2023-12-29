

int find(vector<int> &boards, int m) {
    int painters = 1;
    int sum = 0;
    for(auto& it : boards) {
        sum += it;
        if(sum > m) {
            painters++;
            sum = it;
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int l = *max_element(boards.begin(),boards.end());
    int h = accumulate(boards.begin(), boards.end(), 0);
    int ans;
    while(l <= h) {
        int m = l + (h-l)/2;
        int painters = find(boards,m);
        if(painters > k) {
            l = m+1;
        }
        else {
            ans = m;
            h = m-1;
        }
    }
    return ans;
}