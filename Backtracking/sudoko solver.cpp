#include<bits/stdc++.h>
using namespace std;
#define N 9

bool is_safe(int row,int col,int grid[N][N],int num){
	for(int i=0;i<9;i++){
		if(grid[row][i]==num || grid[i][col]==num){
			return false;
		}
	}
	int n=sqrt(N);
	row=row-row%n;
	col=col-col%n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[row+i][col+j]==num){
				return false;
			}
		}
	}
	return true;
}
void printGrid(int grid[N][N]){
	for (int row = 0; row < N; row++) 
	{ 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
}
bool solve(int grid[N][N],int n){
	//printGrid(grid);

	int row=-1;
	int col=-1;
	bool flag=false;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j]==0){
				row=i;
				col=j;
				flag=true;
				break;
			}
		}
		if(flag==true){
			break;
		}
	}
	if(flag==false){
		return true;
	}
	for(int k=1;k<=n;k++){
		if(is_safe(row,col,grid,k)){
			grid[row][col]=k;
			if(solve(grid,N)){
				return true;
			}
				
			else{
				grid[row][col]=0;
			}
		}
		
	}
	return false;

}

int main() 
{ 
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (solve(grid,N) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 

