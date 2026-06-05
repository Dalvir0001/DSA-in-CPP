/*
LeetCode 65 - Valid Number

Problem:
Determine whether a given string represents a valid number.

Concepts Used:
- String Traversal
- Character Validation
- State Tracking
- Edge Case Handling

Approach:
- Traverse the string once.
- Track whether a digit, decimal point, or exponent has been seen.
- Ensure signs appear only at valid positions.
- Verify that digits exist where required.

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isNumber(string s) {
        bool digitSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool digitAfterE = true;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                digitSeen = true;
                digitAfterE = true;
            }

            else if (ch == '.') {
                if (dotSeen || eSeen)
                    return false;
                dotSeen = true;
            }

            else if (ch == 'e' || ch == 'E') {
                if (eSeen || !digitSeen)
                    return false;

                eSeen = true;
                digitAfterE = false;
            }

            else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            else {
                return false;
            }
        }

        return digitSeen && digitAfterE;
    }
};
