class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i, lineLength = 0;

            // Step 1: pick words for one line
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            int spaces = maxWidth - lineLength;
            int gaps = j - i - 1;
            string line = "";

            // Step 2: Last line or single word
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                // Step 3: fully justify
                int evenSpaces = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaceToApply = evenSpaces + (extraSpaces-- > 0 ? 1 : 0);
                        line += string(spaceToApply, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
