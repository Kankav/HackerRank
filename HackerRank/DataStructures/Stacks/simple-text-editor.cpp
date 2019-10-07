#include <cmath>
#include <cstdio>
#include <String>
#include <Stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int q,t,k,n=0;
    cin>>q;

    vector<char > str;
    Stack< pair<int, String > s;    

    while(q--){
        cin>>t;
        if(t==1){
            String w;
            cin>>w;
            int l = w.length();
            for(int i=0;i<l;i++){
                str.push_back(w[i]);
                n++;
            }
            s.push(make_pair(1,w));
        }else if(t==2){
            cin>>k;
            String w;
            for(int i=k;i>0;i--){
                w[k-i]=str[n-1];
                str[n-1]='\0';
                n--;
            }
            s.push(make_pair(2,w));
        }else if(t==3){
            cout<<str[k-1]<<endl;
        }else{
            pair<int, String> p = s.top();
            s.pop();
            if(p.first == 1){
                int k2 = p.second;
                for(int i=k2;i>0;i--){
                    str[n-1]='\0';
                    n--;
                }
            }else{
                String w2 = p.second;
                for(int i=0;w2[i]!='\0';i++){
                    str.push_back(w2[i]);
                    n++;
                }
            }
        }
    }
    return 0;
}
