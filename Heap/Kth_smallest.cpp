
//method 1 -> by sorting 

//method 2 ->  
/*
step-1 ->  first insert the k element in the max priority queue 
step-2 ->  then after that we will check everytime we are moving to the next element of the given array 
          if the current element is smaller than the top element in the maxHeap then only we can allow to push in the maxHeap
          if greater than the top then that element can't be contributing in kth smallest element 

          and at the last the top  element will be the kth smalles element 


          AND FOR THE Kth greatest we will use the MinHeap (min priority queue);

*/



class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int count = 0;
        priority_queue<int> maxHeap;
        
        while(count < k){
            maxHeap.push(arr[count]);
            count++;
        }
        
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < maxHeap.top()){
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
        return maxHeap.top();
    }
};
