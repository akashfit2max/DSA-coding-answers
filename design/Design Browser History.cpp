struct Node {
    string value;
    Node *next = nullptr; 
    Node *prev = nullptr;
    Node(string _value) {
        value = _value;
    }
}; 

class BrowserHistory {
   
public:
    Node* curr = nullptr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps-- > 0) {
            curr = curr->prev;
        }
        return curr->value;
    }
    
    string forward(int steps) {
        while(curr->next && steps-- > 0) {
            curr = curr->next;
        }        
        return curr->value;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */