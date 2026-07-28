/*
    Problem: Asteroid Collision 

    Approach:
    - Use a stack (implemented with a vector) to simulate asteroid movements.
    - Push all right-moving (positive) asteroids onto the stack.
    - When a left-moving (negative) asteroid appears, repeatedly remove smaller
      right-moving asteroids that collide with it.
    - If both asteroids have the same size, both are destroyed.
    - If the incoming asteroid survives after all collisions, push it onto the stack.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

// Code :-

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;  
        for(int i=0; i < n; i++) {
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            else {
                while(!st.empty() && st.back() > 0 && 
                      st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                else if(st.empty() ||
                        st.back() < 0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};