class Solution {
public:
    bool isAlphanumeric(char ch) {
        int asciiValue = (int)tolower(ch);
        if((asciiValue>=48 && asciiValue<=57) || (asciiValue>=65 && asciiValue<=90) || (asciiValue>=97 && asciiValue<=122)) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {

        const int n=s.size();
        int left=0, right= n-1;

        while(left<right) {
            while(left<right && !isAlphanumeric(s[left]))
            left++;
            while(left<right && !isAlphanumeric(s[right]))
            right--;

             if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;

        }
        return true;
    }
};
