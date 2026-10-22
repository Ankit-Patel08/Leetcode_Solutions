#include<iostream>
using namespace std;

// brute force approach
string repeatingString1(string s){
    string result = "";
     for(int i= 0; i<s.length(); i++){
        for(int j = i+1; j<s.length(); j++){
            if(s[i] == s[j]){
                result = s[i];
                return result;
            }
        }
     }
     return result;
}


// but this will give the frist repaeting character from alphabetical order
string repeatingString2(string s){
    string result = "-1";
    for(int i = 0; i<256; i++){
        int count = 0;
        for(int j = 0; j<s.length(); j++){
            if(s[j] == char(i)){
            count++;
            result = s[j];
            if(count >1){
                return result;
            }
        }

        }
    }
    return result;
}


// this will give the first repeating character from the string
string repeatingString3(string s){
    string result = "-1";
    int hasp_map[256] = {0};
    for(int i = 0; i<s.length(); i++){
        unsigned char index = s[i];     // to avoid negative index
        hasp_map[index]++;
        if(hasp_map[index] > 1){
            result = string(1, s[i]);      // converting char to string
            return result;
        }
    }
    return result;
}

int main(){
    string ch;
    cout<< "Enter a string: ";
    cin>> ch;
    cout<< repeatingString1(ch)<<endl;
   cout<< repeatingString2(ch)<<endl;
    cout<< repeatingString3(ch)<<endl;
    return 0;
}