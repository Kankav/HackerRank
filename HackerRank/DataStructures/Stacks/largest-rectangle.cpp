#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {

    h.push_back(0);
    int l = h.size();
    stack<pair<int, int> > left;
    long max_area=0,curr_area=0;

    pair<int,int> t_prev;

    vector<int> si(l);
    for(int i=0;i<l;i++){
        if(left.empty()){
            left.push(make_pair(h[i],i));
        }else{
            pair<int,int> top = left.top();
            //If n blocks of same height h having blocks of height >h in between them,
            //then their largest areas will be same but
            //area of only the last one will be calculated correctly(as per this implementation)
            while(top.first>=h[i]){                            
                left.pop();
                if(left.size()==0){
                    curr_area = i*(top.first);
                    max_area = max(max_area,curr_area);
                    break;
                }else{
                    t_prev = left.top();
                    curr_area = (i - t_prev.second - 1)*(top.first);
                    max_area = max(max_area,curr_area);
                    top = t_prev;
                }
            }            
            left.push(make_pair(h[i],i));             
        }        
    }

    return max_area;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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
