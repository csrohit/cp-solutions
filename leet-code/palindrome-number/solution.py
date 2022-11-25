class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return false
        rev = 0;
        while x>rev:
            rev = rev*10 + x%10
            x //=10
            
        return x == rev || x== rev/10
        
        