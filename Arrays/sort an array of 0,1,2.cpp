/*
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // Your code goes here
        int l=0;
        int m=0;
        int h=n-1;
        
        while(m<=h){
            if(a[m]==0){
                swap(a[m++],a[l++]);
            }
            else if(a[m]==1){
                m++;
            }
            else{
                swap(a[h--],a[m]);
            }
        }
    }
    
};