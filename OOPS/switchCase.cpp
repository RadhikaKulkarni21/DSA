#include<iostream>
using namespace std;

int switchCase(int n){
    switch(n){
        case 1:
        cout<<"day 1"<<endl;
        break;

        case 2:
        cout<<"day 2"<<endl;
        break;

        default:
        cout<<"No day"<<endl;
        break;
    }
    return 0;
}

int main(){
    int n = 2;
    switchCase(8);
    //switchCase(n);
}