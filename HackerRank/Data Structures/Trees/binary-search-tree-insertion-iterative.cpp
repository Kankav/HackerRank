Node * insert(Node * root, int data) {

    Node* newNode = new Node(data);
    
    if(root==nullptr){
        root = newNode;
        return root;
    }

    Node* temp = root;

    while(temp!=nullptr){

        if(data <= temp->data){            
            if(temp->left==nullptr){
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        }
        else{
            if(temp->right==nullptr){
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }

    }

    return root;
}