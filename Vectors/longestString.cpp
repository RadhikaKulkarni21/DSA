using namespace std;
#include <iostream>
#include <vector>

void printString(const vector<string>& strings){
    cout<<"[";
    for (const auto& str : strings) {
        cout << "\"" << str << "\" ";
    }
    cout << "]"<<endl;
}

string longestStringFunction(vector<string>& stringList){
    string longestString = "";
    for(string str: stringList){
        if(str.length() > longestString.length()){
            longestString = str;
        }
    }
    return longestString;
}


int main(){
    vector<string> stringList = {"elephant", "cow", "rhino"};
    printString(stringList);
    string result = longestStringFunction(stringList);
    cout<<result;
}
