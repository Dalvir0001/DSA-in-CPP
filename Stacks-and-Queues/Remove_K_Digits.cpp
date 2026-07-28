/*
    Remove K Digits

    Approach:
    - Use a monotonic increasing stack to construct the smallest possible number.
    - While traversing the digits, remove larger previous digits if the current
      digit is smaller and removals (k) are still available.
    - If removals remain after traversal, remove digits from the end of the stack.
    - Build the answer from the stack, remove leading zeros, and return "0"
      if the resulting number is empty.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string ans;
        stack <char> st;
        int i=0;
        while(i<n)
        {
            if(st.empty())
            {
                st.push(num[i]);
                i++;
            }
            else{
                while(!st.empty() && st.top() > num[i] && k > 0)
                {
                    st.pop();
                    k--;
                }

                st.push(num[i]);
                i++;
            }
        }
        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        for(int i=ans.size()-1 ; i>0 ; i--)
        {
            if(ans[i] == '0')
            {
                ans.pop_back();
            }
            else break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};