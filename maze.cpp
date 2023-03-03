#include <bits/stdc++.h> 

bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n, vector<vector<bool>> &vis){

if((newx>=0 && newy<n) && (newx<n && newy>=0) && (vis[newx][newy]!=1) && (arr[newx][newy]==1)){
    return true;
}
else {
    return false;
}


}


void solve(vector<vector<int>> &arr, int n,  vector<string> &ans, vector<vector<bool>> &vis, string path, int x, int y){
 
//base case

if(x==n-1 && y==n-1){
    ans.push_back(path);
    return;
}

//4 movement allowed D,L,R,U

//down 

if(isSafe(x+1,y,arr,n,vis)){
vis[x][y]=1;
solve(arr,n, ans, vis, path + 'D', x+1, y);
vis[x][y] = 0;
}

//left

if(isSafe(x,y-1,arr,n,vis)){
vis[x][y]=1;
solve(arr,n, ans, vis, path + 'L', x, y-1);
vis[x][y] = 0;
}

//right

if(isSafe(x,y+1,arr,n,vis)){
vis[x][y]=1;
solve(arr,n, ans, vis, path + 'R', x, y=1);
vis[x][y] = 0;
}


//up

if (isSafe(x - 1, y, arr, n, vis)) {
vis[x][y]=1;
  solve(arr, n, ans, vis, path + 'U', x - 1, y);
  vis[x][y] = 0;
}


}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
     vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path= "";

    if (arr[0][0]== 0){
        return ans;
    }

    solve(arr,n, ans, visited, path, 0, 0);
    return ans;
}
