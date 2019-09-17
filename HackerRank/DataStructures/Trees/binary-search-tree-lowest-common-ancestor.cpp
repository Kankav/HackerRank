Node* lca(Node *root, int v1, int v2) {

    int l = min(v1,v2);
    int r = max(v1,v2);

    while(root!=nullptr && !(root->data>=l && root->data<=r)){
        if(root->data>=r){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return root;
	
}