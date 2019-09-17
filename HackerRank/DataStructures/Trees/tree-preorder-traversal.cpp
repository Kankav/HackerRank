void preOrder(Node *root) {

    if(root!=nullptr){
        std::cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }

}