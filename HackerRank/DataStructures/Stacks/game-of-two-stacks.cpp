#include <bits/stdc++.h>
#include<limits>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the twoStacks function below.
 */
int twoStacks(int x, vector<int> a, vector<int> b) {
    /*
     * Write your code here.
     */

    long int curr_max = 0;
    int ans = 0;
    int r = a.size();
    int c = b.size();

    long cumu1[r+1];
    long cumu2[c+1];

    cumu1[0]=0;
    cumu2[0]=0;   

    int e1=r;
    int e2=c; 

    for(int i=0;i<c;i++){
        cumu2[i+1]=b[i]+cumu2[i];
        
        if(cumu2[i+1]>x){
            e2 = i;
            break;
        }

        if(cumu2[i+1]<=x && i+1>ans){
            ans = i+1;
        }
    }

    for(int i=0;i<r;i++){
        cumu1[i+1]=a[i]+cumu1[i];

        if(cumu1[i+1]>x){
            break;
        }

        if(cumu1[i+1]<=x && i+1>ans){
            ans = i+1;
        }

        int f = cumu1[i+1];
        int low = 1;
        int high = e2;
        int mid;
        
        if(f+cumu2[low]<=x)
        {
            while(low<=high){   
                mid = (low+high)/2;                
                if(f+cumu2[mid]<=x && (mid+1>e2 || f+cumu2[mid+1]>x)){                
                    break;
                }else if(f+cumu2[mid]<=x){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        
            if(i+1+mid>ans)
                ans = i+1+mid;

        }
        
            
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string nmx_temp;
        getline(cin, nmx_temp);

        vector<string> nmx = split_string(nmx_temp);

        int n = stoi(nmx[0]);

        int m = stoi(nmx[1]);

        int x = stoi(nmx[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<int> a(n);

        for (int a_itr = 0; a_itr < n; a_itr++) {
            int a_item = stoi(a_temp[a_itr]);

            a[a_itr] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split_string(b_temp_temp);

        vector<int> b(m);

        for (int b_itr = 0; b_itr < m; b_itr++) {
            int b_item = stoi(b_temp[b_itr]);

            b[b_itr] = b_item;
        }

        int result = twoStacks(x, a, b);

        fout << result << "\n";
    }

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
