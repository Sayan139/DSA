#include <iostream>
using namespace std;
// this is the question to check wheather the string is palindrome or not(recursive approach)
bool ispalindrome(int i,string s){
	if(i>=s.size()) return true;
	if(s[i] != s[s.size()-i-1]) return false;
	return ispalindrome(i+1,s);
}
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//Given a string s, return true if it is a palindrome, or false otherwise.
//going for the recursive approach
bool iscomplexpalindrome1(int start,int end,string s){
	if(start >= end) return false;
	if(!isalnum(s[start])){
		return iscomplexpalindrome1(start+1,end,s);
	}
	if(!isalnum(s[end])){
		return iscomplexpalindrome1(start,end-1,s);
	}
	if(tolower(s[start])!=tolower(s[end])) return false;
	return iscomplexpalindrome1(start+1,end-1,s);
}// this solution not gonna work for bigger inputs so we have to use the iterative mehtod
//(reeason behind is this gonna throw the memory error it  might get full so we have to use terative method)
bool isPalindromeoptimal(string s) {// this is the most optimal one 
    int start =0,end =s.size()-1;
    while(start < end){
        if(!isalnum(s[start])) start++;
        else if(!isalnum(s[end])) end--;
        else{
            if(tolower(s[start])!=tolower(s[end])) return false;
            start++;
            end--;
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Enter the number of test cases: ";
    cin >> n;
    cin.ignore();
    
    while (n--) {
        string s;
        cout << "Enter the value of the string: ";
        getline(cin, s);
        
        if (isPalindromeoptimal(s)) {
            cout << "The string is a palindrome!" << endl;
        } else {
            cout << "The string is not a palindrome!" << endl;
        }
    }
    return 0;
}