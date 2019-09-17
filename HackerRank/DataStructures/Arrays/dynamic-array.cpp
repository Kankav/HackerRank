#include <bits/stdc++.h>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {

    vector<int> result;

    //Store all the sequences
    vector<vector<int>> seq_list(n);

    int lastAnswer = 0;

    int Q = queries.size();

    for(int i = 0 ; i < Q ; i++){

        int query_type = queries[i][0];

        int x = queries[i][1];

        int y = queries[i][2];

        int index  = (x^lastAnswer)%n ;

        if(query_type==1){

            seq_list[index].push_back(y);

        }
        else{

            int size_ = seq_list[index].size();
            lastAnswer = seq_list[index][y % size_];
            result.push_back(lastAnswer);

        }        
        
    }

    return result;

}

int main()
{
    int n, q;
    cin>>n>>q;

    //Store all the queries
    vector<vector<int>> queries(q,vector<int>(3));

    for (int i = 0; i < q; i++) {

        for (int j = 0; j < 3; j++) {

            cin >> queries[i][j] ;

        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (int i = 0; i < result.size(); i++) {

        cout << result[i] << endl;

    }

    return 0;

}

