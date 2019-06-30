#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>& dest, stack<int>& source){

    while(!source.empty()){

        dest.push(source.top());        
        source.pop();
    }

}

int main(){

    int q;
    cin>>q;

    int t;
    int v;

    stack<int >s1;
    stack<int >s2;

    for(int i=0;i<q;i++){
        cin>>t;

        if(t==1){

            cin>>v;
            s1.push(v);            

        }else{

            //To maintain the order, transfer only when 2nd stack is empty 
            //One element is in one of the stacks at a time
            if(s2.empty()){
                transfer(s2,s1);
            }

            if(t==2){
                s2.pop();
            }else{
                cout<<s2.top()<<endl;
            }

        }               
    }
}