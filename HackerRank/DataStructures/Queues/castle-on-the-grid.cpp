#include <bits/stdc++.h>

using namespace std;

struct ele{
    int i;
    int j;
    int par_dir;
    int my_dir;
    int path;

    ele(int a,int b,int c,int d,int p){
        i = a;
        j = b;
        par_dir = c;
        my_dir = d;
        path = p;
    }
        
};

// Complete the minimumMoves function below.
int minimumMoves(int n, int grid[], int startX, int startY, int goalX, int goalY) {

    bool visited[n][n];

    int path[n][n];

    for (int i = 0; i < n; i++) {
        for(int j=0; j<n; j++){
            if(grid[i*n+j]==1){
                visited[i][j]=false;
                path[i][j]=0;
            }
            else{
                visited[i][j]=true;
                path[i][j]=0;
            }            
        }
    }

    queue<ele* > q;

    q.push(new ele(startX,startY,0,0,0));
    visited[startX][startY]=true;
    cout<<"pushing: "<<startX<<" "<<startY<<endl;
    int dis = 0;

    while(!q.empty()){

        ele* e = q.front();
        q.pop();

        int i = e->i;
        int j = e->j;
        //cout<<"popped: "<<i<<" "<<j<<endl;
        

        int par_dir = e->par_dir;
        int my_dir = e->my_dir;
        int p = e->path + 1; //1:H 2:V

        bool bool1=false,bool2=false;

        if(my_dir != par_dir){
            bool1 = true;
        }

        if(i==goalX && j==goalY){
            if(bool1)
            {
                dis++;
            }
            return dis+1;
        }

        par_dir = my_dir;

        if(i-1>=0 && ((!visited[i-1][j]) || path[i-1][j]>=p)){
            bool2 = true;
            my_dir = 2;
            if(par_dir == 0){
                par_dir = my_dir;
            }
            q.push(new ele(i-1,j,par_dir,my_dir,p));
            visited[i-1][j]=true;
            //cout<<"pushing: "<<i-1<<" "<<j<<endl;
        }

        if(j-1>=0 && ((!visited[i][j-1]) || path[i][j-1]>=p)){
            bool2 = true;
            my_dir = 1;
            if(par_dir == 0){
                par_dir = my_dir;
            }
            q.push(new ele(i,j-1,par_dir,my_dir,p));
            visited[i][j-1]=true;
            //cout<<"pushing: "<<i<<" "<<j-1<<endl;
        }

        if(i+1<n && ((!visited[i+1][j]) || path[i+1][j]>=p)){
            bool2 = true;
            my_dir = 2;
            if(par_dir == 0){
                par_dir = my_dir;
            }
            q.push(new ele(i+1,j,par_dir,my_dir,p));
            visited[i+1][j]=true;
            //cout<<"pushing: "<<i+1<<" "<<j<<endl;
        }

        if(j+1<n && ((!visited[i][j+1]) || path[i][j+1]>=p)){
            bool2 = true;
            my_dir = 1;
            if(par_dir == 0){
                par_dir = my_dir;
            }
            q.push(new ele(i,j+1,par_dir,my_dir,p));
            visited[i][j+1]=true;
            //cout<<"pushing: "<<i<<" "<<j+1<<endl;
        }

        if(bool1 && bool2)
        {
            dis++;
            //cout<<"dis++ for i,j"<<i<<" "<<j<<endl;
        }
        
    }

    return dis+1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int grid[n*n];
    char x;

    for (int i = 0; i < n; i++) {
        for(int j=0;j<n;j++){
            cin>>x;
            if(x=='.'){
                grid[i*n+j]=1;
            }else{
                grid[i*n+j]=-1;
            }
        }
    }

    
    int startX ;

    int startY;

    int goalX ;

    int goalY ;

    cin>>startX>>startY>>goalX>>goalY;

    int result = minimumMoves(n, grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

