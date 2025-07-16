using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>

//we need to simplify the emails
//we use hash set because hash only has non duplicates
//email if '.' gets removed so 
class solution{
    public:
    int numUniqueEmailAddress(vector<string>& emails){
    set<string> unique;
    for (auto email : emails)
    {
        string str;
        for (char c : email)
        {
            //question being we need to stop processing after these two characters
            //ignoring everything after +
            //once we hit @ that means the local name is done we move to domain name
            //we move to append directly
            if (c == '+' || c == '@')
            {
                break;
            }
            //we just need to skip and ignore this particular charcter
            //move to parsing the next character
            if (c == '.')
            {
                continue;
            }
            str.push_back(c);
        }
        //Adds the domain part of the email (e.g., @leetcode.com) to the 
        //normalized local name.
        //So if we processed test.email+alex@leetcode.com, str becomes:
        str.append(email.substr(email.find('@')));
        unique.insert(str);
    }
        return unique.size();
    }
};

int main(){ 
    vector<string> newVector = {"test.email+alex@leetcode.com",
                                "test.e.mail+bob.cathy@leetcode.com",
                                "testemail+david@lee.tcode.com"};
    //create an object of the class for reference
    solution emailVector;
    //passing the function and value
    int emailLen = emailVector.numUniqueEmailAddress(newVector);
    cout<< emailLen;
}

/*
Every valid email consists of a local name and a domain name, 
separated by the '@' sign. Besides lowercase letters, 
the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, 
and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local 
name part of an email address,
 mail sent there will be forwarded to the same address 
 without dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the 
same email address.
If you add a plus '+' in the local name, 
everything after the first plus sign will be ignored. 
This allows certain emails to be filtered. Note that 
this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], 
return the number of different addresses that actually receive mails.
*/