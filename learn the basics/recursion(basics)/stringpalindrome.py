def ispalindrome(i, s):
    if i >= len(s): 
        return True
    if s[i] != s[len(s) - i - 1]:
        return False
    return ispalindrome(i + 1, s)

def iscomplexpalindrome1(start, end, s):
    if start >= end: 
        return True
    if not s[start].isalnum():
        return iscomplexpalindrome1(start + 1, end, s)
    if not s[end].isalnum():
        return iscomplexpalindrome1(start, end - 1, s)
    if s[start].lower() != s[end].lower():
        return False
    return iscomplexpalindrome1(start + 1, end - 1, s)

def isPalindromeoptimal(s):
    start = 0
    end = len(s) - 1
    while start < end:
        if not s[start].isalnum():
            start += 1
        elif not s[end].isalnum():
            end -= 1
        else:
            if s[start].lower() != s[end].lower():
                return False
            start += 1
            end -= 1
    return True
