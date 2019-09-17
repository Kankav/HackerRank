#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){

    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    queue<int > q1;
    queue<int > q2;
    queue<int > q3;

    int x,s1=0,s2=0,s3=0;

    for(int i=0;i<n1;i++){
        cin>>x;
        s1+=x;
        q1.push(x);
    }

    for(int i=0;i<n2;i++){
        cin>>x;
        s2+=x;
        q2.push(x);
    }

    for(int i=0;i<n3;i++){
        cin>>x;
        s3+=x;
        q3.push(x);
    }

    while(s1!=s2 || s2!=s3 || s1!=s3 ){

        if(s1>=s2 && s1>=s3){
            s1-=q1.front();
            q1.pop();
        }
        else if(s2>=s1 && s2>=s3){
            s2-=q2.front();
            q2.pop();
        }else{
            s3-=q3.front();
            q3.pop();
        }
        
        if(s1==0 || s2==0 || s3==0){
            cout<<0<<endl;
            return 0;
        }
    }

    cout << s1 << "\n";

}