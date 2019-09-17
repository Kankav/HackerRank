void decode_huff_util(node* root, node* temp, string s, int index, int l) {    

    if(temp->data != '\0'){
        cout<<temp->data;
        temp = root;
    }

    if(index==l)
        return;

    if(s[index]=='0'){
        decode_huff_util(root, temp->left, s, index+1, l);
    }            
    else
    {
        decode_huff_util(root, temp->right, s, index+1, l);
    }

}

void decode_huff(node * root, string s) {

    int l = s.length();

    decode_huff_util(root, root, s, 0, l);
    
}
