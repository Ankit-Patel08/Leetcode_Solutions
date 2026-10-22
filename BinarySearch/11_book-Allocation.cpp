/* link -> https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/
*/



class Solution {
    private:
     int studCount(vector<int>&arr, long long minStud){
         int count = 1;    // 
         long long currStud = 0;
         for(int i = 0; i < arr.size(); i++){
             if(currStud+arr[i] <= minStud){
                 currStud += arr[i];
             }else{
                 count++;
                 currStud = arr[i];
             }
         }
         return count;
     }
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        
        long long high = accumulate(arr.begin(), arr.end(),0LL);     // maximum number of pages can be sum of all the pages in the array
        
        long long low = *max_element(arr.begin(), arr.end());   // minimum number of pages can be the maximum element in the array because then only we will be able to allocate atleast one book to each student otherwise maxnumberpage book will not be allocated to any student if taken less than max element in the array
        
        long long ans = 0;       
        
        while(low <= high){
            long long mid = low+(high-low)/2;
            
            if(studCount(arr, mid) <= k){                     // if the number of students required to allocate the books is less than or equal to k then we can try to minimize the number of pages allocated to each student by reducing the high value
                ans = mid;
                high = mid-1;
            }else{
                low =  mid+1;
            }
        }
        return (int)ans;
    }
};