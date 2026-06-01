/*
Problem: Isomorphic Strings
Platform: LeetCode
Topic: Strings, HashMap
Approach: Two HashMaps
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if(m1.count(c1)) {
                if(m1[c1] != c2) return false;
            } else {
                m1[c1] = c2;
            }
            if(m2.count(c2)) {
                if(m2[c2] != c1) return false;
            } else {
                m2[c2] = c1;
            }
        }
        return true;
    }
};
