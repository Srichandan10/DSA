/*
Problem Description

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.
*/



pair<int,int> MinMax(vector<int> &A,int start,int end){
    if(start==end){
        return make_pair(A[start],A[end]);
    }
    
    int mid=(end-start)/2+start;
    
    pair<int,int> p1=MinMax(A,start,mid);
    pair<int,int> p2=MinMax(A,mid+1,end);
    
    int mini=p1.first<p2.first?p1.first:p2.first;
    int maxi=p1.second>p2.second?p1.second:p2.second;
    
    return make_pair(mini,maxi);
    
}

int Solution::solve(vector<int> &A) {
    pair<int,int> p=MinMax(A,0,A.size()-1);
    return p.first+p.second;
}




