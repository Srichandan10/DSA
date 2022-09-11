/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        int index=0;
        vector<vector<int>> merged;
        
        for(int i=0;i<intervals.size();i++){
            
            if(merged.size()==0 || intervals[i][0]>merged[merged.size()-1][1]){
                vector<int> temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                
                merged.push_back(temp);
            }
            else{
                
                merged[merged.size()-1][1]=max(merged[merged.size()-1][1],intervals[i][1]);
            
            }
        }
        
        return merged;
        
    }
};