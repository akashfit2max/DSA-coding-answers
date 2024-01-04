class Logger {
private:
    unordered_map<string, int> m;
public:
    /**
     * @param timestamp: Timestamp
     * @param message: Message
     * @return: Whether the log can be printed
     */
    bool couldPrintMessage(int timestamp, string &message) {
        // --- write your code here ---
        if (timestamp < m[message]) {
            return false;
        }

        m[message] = timestamp + 10;
        
        return true;
    }
};