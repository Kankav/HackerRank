//This solution prints only the outer nodes of given tree.
//eg. If tree is as shown below
//       1
//      /|\
//     2 | 3
//    /|\|
//   4 | 5
//   | |/ 
//   | 6
//   |/
//   7
//  /|
// 8 |
//It will print 4 2 1 3 which is not the actual top view
//Top view is 8 4 2 1 3, check out the tree-top-view.cpp file for code

void print_left(Node * root) {
    if(root==nullptr)
        return;
    print_left(root->left);
    cout<<root->data<<" ";
}

void print_right(Node * root) {
    if(root==nullptr)
        return;
    cout<<root->data<<" ";
    print_right(root->right);    
}

void topView(Node * root) {

    print_left(root->left);
    cout<<root->data<<" ";
    print_right(root->right);

}