#include <bits/stdc++.h>
#include <queue>

using namespace std;

struct node{
    node* left;
    node* right;
    int data;
    node(int i){
        right = left = nullptr;
        data = i;
    }
};

void print_inorder(node* node_ptr, vector<int> &v, int* i){
    if(node_ptr==nullptr){
        return;
    }
    print_inorder(node_ptr->left, v, i);
    v[(*i)++] = node_ptr->data;
    print_inorder(node_ptr->right, v, i);
}

void do_swap(int k, node* node_ptr, int level){
    if(node_ptr!=nullptr){
        if(level%k==0){
            node* temp = node_ptr->left;
            node_ptr->left = node_ptr->right;
            node_ptr->right = temp;
        }
        do_swap(k,node_ptr->left,level+1);
        do_swap(k,node_ptr->right,level+1);
    }
}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {    

    int n = indexes.size();
    int t = queries.size();
    vector< vector<int> > v(t,vector<int> (n));

    //construct a tree from given indexes matrix
    int c = 0;
    node* root = new node(1);
    node* curr;
    queue<node* > q;
    q.push(root);    

    while(!q.empty() || c<n){
        curr = q.front();
        q.pop();

        if(indexes[c][0]!=-1){
            curr->left = new node(indexes[c][0]);
            q.push(curr->left);
        }
            
        if(indexes[c][1]!=-1){
            curr->right = new node(indexes[c][1]);
            q.push(curr->right);
        }           

        c++; 
    }

    //Run queries one by one
    for(int i=0 ; i<t ; i++){
        int k = queries[i];
        do_swap(k, root, 1); //each do_swap involves floor(height/k) swaps         
        //Print inorder after completing each query
        int a=0;
        print_inorder(root,v[i],&a);
    }

    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
