class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string str: tokens) {
            if(str == "+" || str== "-" || str == "*" || str == "/") {
                int secondNumber = stoi(st.top());
                st.pop();
                int firstNumber = stoi(st.top());
                st.pop();

                if(str == "+") 
                st.push(to_string(firstNumber+secondNumber));
                else if(str == "-") 
                st.push(to_string(firstNumber-secondNumber));
                else if(str == "*") 
                st.push(to_string(firstNumber*secondNumber));
                else 
                st.push(to_string(firstNumber/secondNumber));
                
            }
            else
            st.push(str);
        }

        return stoi(st.top());
        
    }
};
