int findCeil(Node* node, int x) {
    if (node == NULL) return -1;
    int ceil = -1;
    while(node) {
        if(node->data == x) {
            ceil = node->data;
            return ceil;
        }
        if(x > node->data) {
            node = node->right;
        }
        else {
            ceil = node->data;
            node = node->left;
        }
    }
     return ceil;
    // Your code here
}