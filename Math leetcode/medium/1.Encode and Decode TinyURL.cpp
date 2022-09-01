class Solution {
public:

    // Encodes a URL to a shortened URL.
    string str;
    string encode(string longUrl) {
        str = longUrl;
        return str;
    }   

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return str;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));