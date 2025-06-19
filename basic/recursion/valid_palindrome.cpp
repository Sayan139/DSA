#include <iostream>
using namespace std;
void palindrome_checker(string s,int start,int end,bool &res){
    if(start >= end) return;
    while(start < end && !isalnum(s[start])) start++;
    while(start < end && !isalnum(s[end])) end--;
    if(tolower(s[start]) != tolower(s[end])){
        res = false;
        return;
    }
    palindrome_checker(s,start+1,end-1,res);
}
int main(){
    string s = "A man, a plan, a canal: Panama";
    bool res = true;
    palindrome_checker(s,0,s.size(),res);
    if(res) cout << "true";
    else cout << "false";
}