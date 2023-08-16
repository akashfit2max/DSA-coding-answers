class Solution {
    unordered_map<string,bool>mp;
private:
    bool isConcatenated(string word, unordered_set<string>& s) {
        int l = word.length();

        if(mp.find(word) != mp.end()) {
            return mp[word];
        }
        // O(n * l^4)
        for(int i=0; i<l ;i++) {
            string prefix = word.substr(0,i+1);
            string suffix = word.substr(i+1);

            // check kro if prefix aur suffix dono h set me, wrna prefix h aur suffix furter divide ho 
            // skta h aur res me aaskta h
            if((s.count(prefix) && s.count(suffix)) || (s.count(prefix) && isConcatenated(suffix,s))) {
                return mp[word] = true;
            }
        }
        return mp[word] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>s(words.begin(),words.end());
        vector<string>res;
        for(int i=0; i<words.size(); i++) {
            if(isConcatenated(words[i],s)) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};