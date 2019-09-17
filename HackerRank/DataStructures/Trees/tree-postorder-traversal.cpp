void postOrder(Node *root) {

    if(root!=nullptr){
        postOrder(root->left);
        postOrder(root->right);
        std::cout<<root->data<<" ";
    }

}