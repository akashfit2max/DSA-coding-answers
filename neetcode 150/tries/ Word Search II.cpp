class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isWord = true;
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    void search(vector<vector<char>>& board, int i, int j, int m, int n,
                TrieNode* node, string word, vector<string>& res,
                vector<vector<bool>>& vis) {

        char c = board[i][j];
        if (node->children[c - 'a'] == NULL) {
            return;
        }

        node = node->children[c - 'a'];
        word += c;

        if (node->isWord) {
            res.push_back(word);
            node->isWord = false; // Avoid duplicate entries of the same word
        }

        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc]) {
                search(board, nr, nc, m, n, node, word, res, vis);
            }
        }

        vis[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (auto& word : words) {
            insert(word);
        }

        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, root, "", res, vis);
            }
        }

        return res;
    }
};
