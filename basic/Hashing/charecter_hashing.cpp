#include <iostream>
using namespace std;
int main(){
    string s = "SayaNbiswas";
    // for the case where there is the combination of both upper and lower cases 
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){
            hash[s[i]]++;
        }
    }
    for(int i=0; i<256; i++){
        if(hash[i] > 0){
            cout << (char)i << " : " << hash[i] << endl;
        }
    }

    // for string having only capital or small letters 
    string s1 = "HELLO";
    vector<int> hash1(26,0);
    for(int i=0; i<s1.size(); i++){
        hash[s1[i]-'A']++; // you can use 'a' also if the char are in small letter
    }
    cout << "Second part : " << endl;
    for(int i=0; i<hash1.size(); i++){
        if(hash[i] > 0){
            cout << (char)(i+'A') << " : " << hash[i] << endl;
        }
    }cout << endl;
};