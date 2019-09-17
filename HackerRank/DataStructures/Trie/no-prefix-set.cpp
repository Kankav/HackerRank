#include <bits/stdc++.h>

using namespace std;

struct trieNode{
    trieNode* child[10];
    int isEnd;
};

trieNode* getNode(){
    trieNode* temp = new trieNode;
    temp->isEnd = 0;
    for(int i=0;i<10;i++){
        temp->child[i]=0;
    }
    return temp;
}

bool search(trieNode* root, string s){
    int l = s.length();
    int i = 0;
    trieNode* temp = root;

    while(i<l){
        int ch = s[i]-'a';
        if(temp->child[ch]==0){
            temp->child[ch]=getNode();
        }else{
            if(temp->child[ch]->isEnd == 1){
                return true;
            }
        }
        temp=temp->child[ch];
        i++;
    }

    if(temp->isEnd == 1){
        return false;
    }
    
    for(int i=0;i<10;i++){
        if(temp->child[i]!=0)
            return true;
    }

    temp->isEnd = 1;
    return false;
}

int main()
{
    int n;
    cin>>n;
    string s;
    trieNode* root = getNode();
    bool bad = false;

    for(int i=0;i<n;i++){
        cin>>s;
        if(search(root,s))
        {
            cout<<"BAD SET"<<endl;
            cout<<s<<endl;
            bad = true;
            break;
        }
    }
    if(!bad)
        cout<<"GOOD SET"<<endl;
    return 0;
}
