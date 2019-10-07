#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the waiter function below.
 */
vector<int> waiter(vector<int> number, int q) {

    //Find all prime numbers till 10005
    bool isPrime[10005];
    for(int i=0;i<10005;i++){
        isPrime[i]=true;
    }

    isPrime[0]=isPrime[1]=false;
    isPrime[2]=true;

    for(int i=2;i*i<10005;i++){
        if(isPrime[i]){
            int j=2;
            while(i*j<10005){
                isPrime[i*j]=false;
                j++;
            }
        }
    }
    
    //store all prime numbers in a vector to get ith prime in O(1)
    vector<int> primes;

    for(int i=0;i<10005;i++){
        if(isPrime[i]){
            primes.push_back(i);            
        }            
    }

    stack<int> B[q];
    //no need to create q stacks of type A
    stack<int> A0;
    stack<int> A1;

    for(int i=0;i<number.size();i++){
        A0.push(number[i]);
    }

    for(int i=1;i<=q;i++){        
        if(i%2==0){
            while(A1.size()!=0){
                int j = A1.top();
                A1.pop();

                if(j%primes[i-1]==0){
                    B[i-1].push(j);
                }else{
                    A0.push(j);
                }
            }
        }else{
            while(A0.size()!=0){
                int j = A0.top();
                A0.pop();

                if(j%primes[i-1]==0){
                    B[i-1].push(j);
                }else{
                    A1.push(j);
                }
            }
        }
    }

    vector<int>ans;
    for(int i=0;i<q;i++){
        while(B[i].size()!=0){
            ans.push_back(B[i].top());
            B[i].pop();
        }        
    }

    if(q%2==0){
        while(A0.size()!=0){
            ans.push_back(A0.top());
            A0.pop();
        }  
    }else{
        while(A1.size()!=0){
            ans.push_back(A1.top());
            A1.pop();
        }  
    }

    return ans;  

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

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

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
