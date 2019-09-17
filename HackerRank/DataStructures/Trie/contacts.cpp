#include <bits/stdc++.h>

using namespace std;

struct trieNode{
    trieNode* child[26];
    int isEnd;
    int count;
};

trieNode* getNode(){
    trieNode* temp = new trieNode;
    temp->isEnd = temp->count = 0;
    for(int i=0;i<26;i++){
        temp->child[i]=0;
    }
    return temp;
}

void add(trieNode* root, string s){
    int l = s.length();
    int i = 0;
    trieNode* temp = root;

    while(i<l){
        int ch = s[i]-'a';
        if(temp->child[ch]==0){
            temp->child[ch]=getNode();
        }
        temp->child[ch]->count++;
        temp=temp->child[ch];
        i++;
    }
    temp->isEnd = 1;
}

int find(trieNode* root, string s){
    int l = s.length();
    int i=0;
    trieNode* temp = root;

    while(i<l){
        int ch = s[i]-'a';
        if(temp->child[ch]==0){
            return 0;
        }
        temp=temp->child[ch];
        i++;
    }
    return temp->count;
}

vector<int> contacts(vector<vector<string>> queries) {
    trieNode* root = new trieNode;
    int l = queries.size();
    vector<int> ans;

    for(int i=0;i<l;i++){
        string op = queries[i][0];
        string s = queries[i][1];

        if(op.compare("add")==0){
            add(root,s);
        }else{
            ans.push_back(find(root,s));
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
