void levelOrder(Node * root) {

    queue<Node* >q;

    if(root!=nullptr){
        q.push(root);
    }

    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=nullptr)
            q.push(curr->left);

        if(curr->right!=nullptr)
        q.push(curr->right);
    }


}