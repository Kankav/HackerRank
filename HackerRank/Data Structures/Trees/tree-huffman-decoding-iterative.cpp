void decode_huff(node * root, string s) {

    int l = s.length();
    int i = 0;

    node* temp = root;

    //root can never be a leaf node since s is non-empty

    while(i!=l){

        char ch = s[i];

        if(ch=='0'){
            temp = temp->left;
        }            
        else
        {
            temp = temp->right;
        }
        
        if(temp->data != '\0'){
            cout<<temp->data;
            temp=root;
        }

        i++;
    }
    
}