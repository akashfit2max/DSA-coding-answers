class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        for(int i=0;i<num1.length();i++)
        {
            for(int j=0;j<num2.length();j++)
            {
                int digit = (num1[i]-'0')*(num2[j]-'0');
                res[i+j] += digit;
                res[i+j+1] += res[i+j]/10;
                res[i+j] = res[i+j]%10;
            }
        }
        
        int x = 0;
        reverse(res.begin(),res.end());
        string ans = "";
        while (res[x] == 0) x++;
        while (x < res.size()) ans += to_string(res[x++]);
        return ans;
    }
};