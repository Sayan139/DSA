'''we need to check the string is palindrome
'''
#first the recursive method
def ispalindrome(i,s):
    if i>=len(s): 
        return True
    if s[i] != s[len(s)-i-1]:
        return False
    return ispalindrome(i+1,s)
def complexpalindrome(start,end,s):
    if start >= end:
        return True
    if not s[start].isalnum():
        return complexpalindrome(start+1,end,s)
    if not s[end].isalnum():
        return complexpalindrome(start,end-1,s)
    if s[start].lower() != s[end].lower():
        return False
    return complexpalindrome(start+1,end-1,s)
# now the iterative method
def ispalindromeoptimal(s):
    start = 0
    end = len(s)-1
    while start < end:
        if not s[start].isalnum(): # the .isalnum check whether its alphabet or num if it is its true but we using not thats why it will give just opposite
            start+=1
        elif not s[end].isalnum():
            end-=1
        else:
            if s[start].lower() != s[end].lower(): # here this convert the whole letter to lower case and we can use .upper for upper case
                return False
            start+=1
            end-=1
    return True
s1 = "A man, a plan, a canal: Panama"
s2 = "race a car"
s3 = "No 'x' in Nixon"
print("Test 1: ", ispalindromeoptimal(s1))  
print("Test 2: ", ispalindromeoptimal(s2))  
print("Test 3: ", ispalindromeoptimal(s3))  
 