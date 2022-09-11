/*

https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

Triplet Sum in Array
MediumAccuracy: 49.0%Submissions: 100k+Points: 4
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13

*/

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A,A+n);
        int l,r;
        
        for(int i=0;i<n;i++){
            
            l=i+1;
            r=n-1;
            while(l<r){
                if(A[i]+A[l]+A[r]==X){
                    return true;
                }
                else if(A[i]+A[l]+A[r]>X){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return false;
    }

};