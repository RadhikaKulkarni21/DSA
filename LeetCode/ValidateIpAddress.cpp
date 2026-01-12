#include "R:\C++\Project1\lcHeader.h"

class Solution
{
public:
    string validIpAddress(string queryIP)
    {
        string num;
        istringstream ss(queryIP);

        if(count(begin(queryIP), end(queryIP), '.') == 3){
            for(int i = 0;i < 4; i++){
                if(!getline(ss, num, '.') || !isIPv4(num))
                    return "Neither";
            }
            return "IPv4";
        }

        else if(count(begin(queryIP), end(queryIP), ':') == 7){
            for(int i = 0; i < 8;i++){
                if(!getline(ss, num, ':') || !isIPv6(num))
                    return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }

private:
    static inline string validCharacters = "0123456789abcdefABCDEF";
    //we need inline bc we are using string stream
    
    bool isIPv4(string& query){
        if(query.empty() || query.size() > 3){
            //size less than 4 not valid
            return false;
        }
        for(char q : query){
            if(q < '0' || q > '9') return false;
            //avoiding
        }

        //not have 0 infront of number or after number
        if(query.size() > 1 && (query[0] == '0' && query[1] != '1' || query[0] == '0' && query[1] == '0')){
            return false;
        }

        int num = stoi(query);
        return 0 <= num && num <= 255;
    }

    bool isIPv6(string& query){
        if(query.empty() || query.size() > 4){
            return false;
        }
        for(char q : query){
            if(validCharacters.find(q) == string::npos){
                return false;
            }
        }
        return true;
    }
};

int main()
{   
    string queryIP = "172.16.254.1";
    string query = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    Solution s;

    cout<< s.validIpAddress(queryIP)<<endl;
    cout<< s.validIpAddress(query);
}