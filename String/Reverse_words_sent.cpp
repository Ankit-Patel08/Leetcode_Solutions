#include<bits/stdc++.h>
using namespace std;


// TRIED USING STRING STREAM 
 string reverseWords(string s) {
        stringstream ss(s);
        vector<string> ans;
        string word;
        while(ss >> word){
            ans.push_back(word);
        }
        reverse(ans.begin(), ans.end());
        string ans2;
        int n = ans.size();
       for(int i = 0; i<n; i++){
        if(i != (n-1)){
        ans2 = ans2+ans[i]+" ";
        }

        else{
             ans2 = ans2+ans[i];
        }
       }
        return ans2;
    }

 

int main(){
    cout<<"give input";
    string s;
   getline(cin,s);
    
   string ans = reverseWords(s);
   
   cout<< ans;
   
}