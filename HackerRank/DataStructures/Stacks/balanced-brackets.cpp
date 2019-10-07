#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> stk;
    int l = s.length();

    string bal = "YES";
    string unbal = "NO";

    for(int i=0;i<l;i++){
        if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(stk.size()==0)
                return unbal;

            char ch = stk.top();
            
            if(!((s[i]==')' && ch == '(')||(s[i]==']' && ch == '[')||(s[i]=='}' && ch == '{'))){
                return unbal;
            }else{
                stk.pop();
            }

        }else{
            stk.push(s[i]);
        }
    }

    if(stk.size()==0){
        return bal;
    }else{
        return unbal;
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
