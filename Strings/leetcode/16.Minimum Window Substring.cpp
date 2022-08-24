class Solution {
public:
    string minWindow(string s, string t) {
        if( s.length()==0 || t.length()==0) return "";
        unordered_map<char,int>mp;
        for(auto it : t)
        {
            mp[it]++;
        }
        
        int i=0,j=0,count = mp.size();
        int left=0,right=s.length()-1,minlen = s.length();
        bool found=false;
        
        while(j< s.length())
        {
            //traverse the string and drecement the and reduce the char freq if any char freq becomes zero reduce the 
            // count
            char endchar = s[j++];
            if(mp.find(endchar)!=mp.end())
            {
                mp[endchar]--;
                if(mp[endchar]==0)
                {
                    count--;
                }
            }
            
            if(count > 0) continue;
            // move the i pointer and remove not required letters
            while(count==0)
            {
                char startchar = s[i++];
                if(mp.find(startchar)!=mp.end())
                {
                    mp[startchar]++;
                    if(mp[startchar] > 0)
                    {
                        count++;
                    }
                }
            }
            
            if((j-i) < minlen)
            {
                left = i;
                right = j;
                minlen = j-i+1;
                found = true;
            }   
        }
        
        return found ? s.substr(left-1,minlen) : "";
    }
};