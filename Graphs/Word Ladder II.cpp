class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        // <{bat}>
        // <{bat,pat}>
        queue<vector<string>>q;
        q.push({beginWord});
        // to keep trackl of the words used on that level
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        // current lvl
        int lvl = 0;
        vector<vector<string>>ans;

        while(!q.empty()) {
            vector<string>vec = q.front();
            //remove from queue
            q.pop();

            // remove the words used in the previous lvl as you come to new lvl
            if(vec.size() > lvl) {
                lvl++;
                for(auto it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            // last word in the sequence
            string word = vec.back();

            if(word == endWord) {
                if(ans.size() == 0) {
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            for(int i=0; i<word.length(); i++) {
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    } 
                }
                word[i] = original;
            }
        }
        return ans;
    }
};