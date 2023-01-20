class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // using bfs
        // {word,steps}
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        //add wordlist in set so that you can remove the words once visited
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            //hit,hot,dog
            for(int i=0; i<word.length(); i++) {
                //h,h,d
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++) {
                    //ait,bit,cit
                    //hat,hbt....hot
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
