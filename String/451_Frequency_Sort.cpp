/*
LeetCode 451 - Sort Characters By Frequency

Problem:
Given a string s, sort it in decreasing order based on the frequency of characters.

Approach:
1. Count the frequency of each character using an unordered_map.
2. Store {frequency, character} pairs in a max heap (priority_queue).
3. Repeatedly extract the character with the highest frequency.
4. Append the character frequency times to the answer string.

Time Complexity: O(n + k log k)
Space Complexity: O(k)

Where:
n = length of the string
k = number of distinct characters
*/

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char ch : s)
            freq[ch]++;

        priority_queue<pair<int,char>> pq;

        for(auto &p : freq)
            pq.push({p.second,p.first});

        string ans;

        while(!pq.empty())
        {
            auto [count,ch] = pq.top();
            pq.pop();

            ans.append(count,ch);
        }

        return ans;
    }
};
