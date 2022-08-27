class Solution {
public:
    bool isNumber(string s) {
        bool digitSceen=false, eSceen=false, dotSceen=false;
        int countPlusMinus=0;
        
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            
            //dot
            if(isdigit(ch))
            {
                digitSceen=true;
            }
            //plus/minus - 6+ , 6+0, ++
            else if(ch=='+' || ch=='-')
            {
                if(countPlusMinus == 2)
                {
                    return false;
                }
                
                if(i>0 && s[i-1]!='e' && s[i-1] != 'E')
                {
                    return false;
                }
                
                if(i==s.length()-1)
                {
                    return false;
                }
                
                countPlusMinus++;
            }
            //dot
            else if(ch == '.')
            {
                if(eSceen || dotSceen)
                {
                    return false;
                }
                
                if(i==s.length()-1 && !digitSceen)
                {
                    return false;
                }
                
                dotSceen=true;
            }
            //E/e
            else if(ch=='e' || ch=='E')
            {
                if(eSceen || !digitSceen || i==s.length()-1)
                {
                    return false;
                }
                eSceen=true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};