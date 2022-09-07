class Solution {
public:
    string getPermutation(int n, int k) {
        //let n=4 ,k=17
        //step1-> possible numbers{1,2,3,4}
        //factorial=6
        vector<int> numbers;
        int fact=1;
        for(int i=1;i<=n;i++)
        {
            fact=fact*i;
            numbers.push_back(i);
        }
        k=k-1 ; //zero based indexing
        fact=fact/n; //if size=n we want factorial=(n-1)!
        string res="";
        while(true)
        {                               //idx->0,1,2,3   
            res+=to_string(numbers[k/fact]); //[1,2,3,4] index_no=16/6 ->2 
            numbers.erase(numbers.begin()+(k/fact));
            if(numbers.size()==0)
                break;
            k=k%fact;       //sequence number=16%6 -> 4
            fact=fact/numbers.size();
        }
        return res;
    }
};