class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        stack<int> st;   // a real stack to simulate what would happen
        int j = 0;       // points to the NEXT value we are supposed to pop from `popped`

        // Go through the pushed array in order, like pushing onto a real stack
        for (int x : pushed) {

            st.push(x);  // Step 1: push the current element

            // Step 2: pop as many times as we are allowed to.
            // If the top of the stack equals the value we need to pop next,
            // then popping it right now is always the correct move.
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();   // remove it from the stack
                j++;        // now we wait for the next value in `popped`
            }
        }

        // If the sequence was valid, every element got pushed AND popped,
        // so the stack must be empty. Anything left over means the pop order
        // was impossible.
        return st.empty();
    }
};
