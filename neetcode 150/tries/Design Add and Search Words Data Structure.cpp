struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }

    void put(char ch, Node* node) { links[ch - 'a'] = node; }

    Node* get(char ch) { return links[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};
class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool dfs(int ind, Node* node, string word) {
        if (ind == word.length())
            return node->isEnd();
        if (word[ind] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->containsKey(i + 'a') &&
                    dfs(ind + 1, node->get(i + 'a'), word))
                    return true;
            }
            return false;
        } else {
            if (!node->containsKey(word[ind]))
                return false;
            return dfs(ind + 1, node->get(word[ind]), word);
        }
    }

    bool search(string word) { return dfs(0, root, word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */