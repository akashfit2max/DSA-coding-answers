class Solution {
    // hasmap to store the order
    map<char,int>mp;
public:
    bool correctOrder(string &a, string &b) {
        int s = min(a.size(),b.size());

// comparing the words order according to their index
        for(int i=0; i<s; i++) {
            if(mp[a[i]] < mp[b[i]])
                return true;
            else if(mp[a[i]] > mp[b[i]])
                return false;
        }

        // if b is substring of a 
        if(a.size() > b.size() && a.find(b) != string::npos) {
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        // storing the order of chars
        for(int i=0; i<order.length(); i++) {
            mp.insert({order[i],i});
        }

        for(int i=0; i<words.size()-1; i++) {
            if(!correctOrder(words[i], words[i+1]))
                return false;
        }
        return true;
    }
};