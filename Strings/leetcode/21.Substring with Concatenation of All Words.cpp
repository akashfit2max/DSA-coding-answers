class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length(), noOfWords = words.size();
        vector<int>res;
        unordered_map<string,int>mp;
        
        if (len * noOfWords > s.length())
            return res;
        
        
        for(auto word : words)
        {
            mp[word]++;
        }
        
        int inc = noOfWords*len;
        for(int i=0; i <= s.length()-inc; i++)
        {
            unordered_map<string,int>wordUsed;
            
            for(int j=i; j < i+inc; j+=len)
            {
                string ch = s.substr(j,len);
                
                if(mp.find(ch) == mp.end())
                {
                    break;
                }
                
                wordUsed[ch]++;
                
                if(wordUsed[ch] > mp[ch])
                {
                    break;
                }
            }
            
            if(mp == wordUsed)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};