int height(Node* root) {
        if(root==nullptr)
            return -1;
        else if(root->left == nullptr && root->right == nullptr)
            return 0;
        return 1 + max(height(root->left),height(root->right));
}