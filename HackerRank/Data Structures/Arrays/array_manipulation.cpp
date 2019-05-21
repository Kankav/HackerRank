#include <bits/stdc++.h>

using namespace std;

vector<long> arr;

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {

    int q = queries.size();

    for(int i=0;i<q;i++){

        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a-1]+=k;
        arr[b]-=k;
    }

    long ans=arr[0];
    long x = ans;

    for(int i=1;i<n+1;i++)
    {
        x = x + arr[i];
        ans = max(ans, x);
    }
    return ans;
}

int main()
{
    int n,m;

    cin>>n>>m;

    for (int i = 0; i < n+1; i++) {
        arr.push_back(0);
    }

    vector<vector<int>> queries(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

    }

    long result = arrayManipulation(n, queries);

    cout << result << "\n";

    return 0;
}
