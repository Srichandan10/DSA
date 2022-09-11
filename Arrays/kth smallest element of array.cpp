//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
/*
Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
*/
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        priority_queue<int> maxh; //maxheap;
        
        for(int i=l;i<=r;i++){
            maxh.push(arr[i]);
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        return maxh.top();
        
    }
};
