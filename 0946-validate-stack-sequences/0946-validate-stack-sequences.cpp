class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        stack<int> st;
        while(i != pushed.size()){
            if(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            } else {
                st.push(pushed[i]);
                i++;
            }
        }
        while(!st.empty() && st.top() == popped[j]){
            st.pop();
            j++;
        }
        if(st.empty()) return true;
        return false;
    }
};