#include<bits/stdc++.h>
using namespace std;

class MIN_HEAP {
    private:
    vector<int>h; // this will create a Dynamic array when the object of this class will be created
    public: 

    void insert (int x){ 
        h.push_back(x); // first pushing in the last to maintain the complete binary tree structure 
        int  child =  h.size()-1;
        while(child > 0 && h[(child-1)/2] > h[child] ){
            swap(h[(child-1)/2], h[child]);
            child = (child-1)/2;
        } 
    }

    // In the poping  -> we will first remove the first element and replce that with the last element of he heap array
    // then compare with the sibling and we wil swap with the greater sibling 

    void pop(){

        if(h.empty()) return;
    
        swap(h[0],h[h.size()-1]);
        h.pop_back();        // here removed the root now time to bring the root to it's correct position

        int i = 0;
        while(2*i+1 < h.size()){  
           
            int left = 2*i+1;
         
            int right = 2*i+2;
            
            int smallest = left;
           if(right < h.size() && h[right] < h[left])
                 smallest = right;    
                
           if(h[i] <= h[smallest]) break;;

           swap(h[i], h[smallest]);
           i = smallest;     
    }
    }
    void print(){
        for(int i = 0; i<h.size(); i++){
            cout<<h[i]<<" ";
        }
    }
};


int main(){
    MIN_HEAP min_heap;
    min_heap.insert(5);
    min_heap.insert(10);
    min_heap.insert(5);
    min_heap.insert(28);
    min_heap.insert(27);
    min_heap.insert(8);

    min_heap.pop();

    min_heap.print();


}