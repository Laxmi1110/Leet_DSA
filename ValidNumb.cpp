class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        
        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;
        
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            if (isdigit(ch)) {
                numSeen = true;
                numAfterE = true;
            } 
            else if (ch == '+' || ch == '-') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            } 
            else if (ch == '.') {
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                if (eSeen || !numSeen)
                    return false;
                eSeen = true;
                numAfterE = false;
            } 
            else {
                return false;
            }
        }
        
        return numSeen && numAfterE; 
    }
};
