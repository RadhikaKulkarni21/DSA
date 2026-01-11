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

/*
stack removes elements which was last added
for loop to print 0 to 4, 0 1 2 3 4
stack will store it as 4 3 2 1 0
stack.top is 4
stack pop will remove 4 first

working:
for = '0' to '3'
st = ""
first for loop runs
st =
a
[
3
run into ] goes to else

curr_str = " "
first while runs, curr_str = a
st.pop = 'a' st = 3[
second pop removes [ st = 3

curr_str = a st = 3
num =  " ", curr_size = 0

second while num = 3 st = " "

times(3)
for(0) curr_str(0) = a st = a, for ends times(2)
for(1) curr_str(0) = a st = aa, for ends times(1)
for(2) curr_str(0) = a st = aaa, for ends times(0)

st = aaa2[bc]
for runs again

st = "aaa"
first for loop runs
st = a a a 2 [ b c
run into ] goes to else

curr_str = " "
first while runs, curr_str = c,
st.pop = 'c' st = aaa2[b
curr_str = bc st = aaa2[
second pop removes [ st = aaa2

curr_str = bc st = aaa2
num =  " ", curr_size = 2

second while num = 2 st = "aaa"

times(2)
for(0) curr_str(0) = b st = aaab
for(0) curr_str(1) = c st = aaabc for ends times(1)
for(0) curr_str(0) = b st = aaabcb
for(0) curr_str(0) = c st = aaabcbc for ends times(0)
*/