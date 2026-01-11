#include "R:\C++\Project1\lcHeader.h"

class Solution{
    public:
    string decodeString(string s){
        int n = s.size();
        if(n == 0) return "";

        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] != ']'){//pushing everything in stack expect [
                st.push(s[i]);
            }
            else{//when we encounter a num or char
                string curr_str = "";

                while(st.top() != '['){
                    curr_str = st.top() + curr_str;//adding whatever is stack top num or char
                    st.pop();//removing the added letter from stack
                }
                st.pop();//removing the [

                //separating the number into another string
                string num = "";

                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                //number of times the char needs to be repeated
                int times = stoi(num);

                while(times--){
                    //this will repeat the char in stack
                    for(int j = 0; j < curr_str.size(); j++){
                        st.push(curr_str[j]);
                    }
                }
            }
        }

        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};

int main(){
    string s = "3[a]2[bc]";
    Solution* strg = new Solution();

    cout<<strg->decodeString(s);//expected OP: aaabcbc

    delete strg;
}