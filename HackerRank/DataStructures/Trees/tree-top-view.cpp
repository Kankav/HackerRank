// If tree is as shown below
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
//Top view is 8 4 2 1 3

//Think of the tree as a 2-D matrix. every node will have a row number & a column number
//For every column if we print it's first row element we will get the top view of the tree
//So in recursion we will pass the row number & column number associated with every node
//Note that a left node's column is 1 less than its parent's
//whereas a right node's column is 1 greater than its parent's
//every child's row is 1 greater than its parent's row
//row is equivalent to height
//column is equivalent to horizontal distance from root

//for every column, we store the node with lowest row number
map<int, pair<int,int > >m;

void top_view_util(Node* root, int hd, int h){

    if(root==nullptr)
    return;

    if(m.find(hd)==m.end()){
        m[hd]=make_pair(root->data,h);
    }
    else{
        if(m[hd].second > h){
            m[hd]=make_pair(root->data,h);
        }
    }

    top_view_util(root->left, hd-1, h+1);
    top_view_util(root->right, hd+1, h+1);
}

void topView(Node * root)
{
    //assuming root is at (0,0)
   top_view_util(root,0,0);
   
   map<int, pair<int,int > > :: iterator itr;

   for(itr=m.begin();itr!=m.end();itr++){
       cout<<itr->second.first<<" ";
   }

}