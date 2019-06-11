//A binary tree is a BST if its inorder traversal gives nodes in ascending order

void inorder(Node* root, vector<int> &v){

    if(root==nullptr){
        return;
    }

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);

}

bool checkBST(Node* root) {

    vector<int > v;
    inorder(root,v);
    int n=v.size();

    for(int i=0;i<n-1;i++){
        if(v[i]>=v[i+1])
            return false;        
    }
    return true;
        
}