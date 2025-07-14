#include "header.h"

string reverseRecu(string str,int len) 
{ 
    if (len < 1)
    {
        return "";
    }
    // Base case
    if (len == 1)
    {
        return string(1, str[0]);
    }
    return str[len - 1] + reverseRecu(str, len - 1);
    //len = 5
    //return str[5-1] + rr("Hello", 5-1) this will decrease the len again
    //the string will remain constant, we just change the value of len each time to output
    //return str[5-1][o] + str[4-1][l] + rr("Hello", 4-1) len decrease again
    //return str[5-1][o] + str[4-1][l] + str[3-1][l] + rr("hello",3-1)
    //return str[5-1][o] + str[3-1][l] + str[3-1][l] + str[2-1][e] + rr("hello",2-1)//base case
    //return str[5-1][o] + str[2-1][l] + str[3-1][l] + rr("hello",1-1)//empty
}

int main(){
    string str = "Hello";
    
    //basic iteration
    cout<<"Iteration: ";
    for(int i = str.length() - 1;i >= 0;i--)
    {
        cout << str[i];  
    }
    cout<<endl;

    //using stack
    stack<char> st;
    for(char c : str){
        st.push(c);
    }

    //empty the original string
    str.clear();

    while(!st.empty()){
        str.push_back(st.top());
        st.pop();
    }
    cout<<"Using stack: "<<str<<endl;

    //using recursive
    cout<<"Recursion: ";
    cout<<reverseRecu(str,str.length())<<endl;
}