void inOrder(Node *root) {

    if(root!=nullptr){        
        inOrder(root->left);
        std::cout<<root->data<<" ";
        inOrder(root->right);
    }

}