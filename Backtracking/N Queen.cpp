#include<bits/stdc++.h>
using namespace std;


bool is_safe(int row,int col,vector<vector<int>> &sol,int n){
	for(int i=0;i<n;i++){
		if(sol[row][i]==1)
			return false;
	}
	for(int i=row,j=col;i<n&&j<n;i++,j++){
		if(sol[i][j]==1){
			return false;
		}
	}
	for(int i=row,j=col;i>=0&&j>=0;i--,j--){
		if(sol[i][j]==1){
			return false;
		}
	}
	for(int i=row,j=col;i<n && j>=0;i++,j--){
		if(sol[i][j]==1){
			return false;
		}
	}
	for(int i=row,j=col;i>=0 && j<n;i--,j++){
		if(sol[i][j]==1){
			return false;
		}
	}
	return true;
}
bool helper(int col,vector<vector<int>> &sol,int n){
	if(col==n){
		return true;
	}
	for(int row=0;row<n;row++){
		if(is_safe(row,col,sol,n)){
			sol[row][col]=1;
			if(helper(col+1,sol,n))
				return true;
			sol[row][col]=0;
		}
	}
	return false;
}
void printsol(vector<vector<int>> &sol,int N){
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << sol[row][col] << " "; 
		cout << endl; 
	} 
}
void solve(int n){
	vector<vector<int>> sol(n,vector<int> (n,0));
	if(helper(0,sol,n)){
		printsol(sol,n);
	}
	else {
		cout<<"NOT POSSIBLE"<<endl;
	}
}
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}
int main(){
	file_i_o();
	int n;
	cin>>n;
	solve(n);
	return 0;
}
