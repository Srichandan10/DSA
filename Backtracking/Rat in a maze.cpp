#include<bits/stdc++.h>
using namespace std;
#define N 4

bool solveMazerec(int maze[N][N],int i,int j,int sol[N][N]){
	if(i==N-1 && j==N-1){
		sol[i][j]=1;
		return true;
	}
	// safe function
	if(i<0 || j<0 || i>=N || j>=N || sol[i][j]==1 || maze[i][j]==0){
		return false;
	}
	sol[i][j]=1;
	if(solveMazerec(maze,i,j+1,sol))
		return true;
	if(solveMazerec(maze,i+1,j,sol)){
		return true;
	}
	if(solveMazerec(maze,i-1,j,sol)){
		return true;
	}
	if(solveMazerec(maze,i,j-1,sol)){
		return true;
	}
	sol[i][j]=0;
	return false;
}
void solveMaze(int maze[N][N]){
	int sol[N][N];
	memset(sol,0,sizeof(sol));

	if(solveMazerec(maze,0,0,sol)==false){
		cout<<"NO path available"<<endl;
	}
	else{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
int main(){
	int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze);    
    return 0;  
}
