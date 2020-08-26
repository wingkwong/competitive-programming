/*
Validate IP Address

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    vector<string> split(string s, char c){
        vector<string> parts;
        string part;
        istringstream iss(s);
        while(getline(iss, part, c)) parts.push_back(part);
        return parts;
    }
    bool isIPv4(string IP){
        // IPv4 contains 3 dots. e.g. 172.16.254.1
        if(count(IP.begin(),IP.end(),'.')!=3) return false;
        vector<string> parts = split(IP,'.');
        // IPv4 has 4 parts
        if(parts.size()!=4) return false; 
        for(string part:parts){
            // avoid empty part, xxxx.xxxx.xxxx.xxxx, and 012.123.123.123 cases
            if(part.empty()||part.size()>3||(part.size()>1&&part[0]=='0')) return false;
            for(char c: part) {
                // abc.abc.abc.abc is invalid
                if(!isdigit(c)) return false;
            }
            // 266.255.255.255 is invalid
            if(stoi(part)>255) return false;
        }
        return true;
    }
    
    bool isIPv6(string IP){
        // IPv6 contains 7 dots. e.g. 2001:0db8:85a3:0:0:8A2E:0370:7334
        if(count(IP.begin(),IP.end(),'.')!=7) return false;
        vector<string> parts = split(IP,'.');
        // IPv4 has 8 parts
        if(parts.size()!=8) return false; 
        for(string part:parts){
            // avoid empty part, 2002222221:0db8:85a3:0:0:8A2E:0370:7334
            if(part.empty()||part.size()>4) return false;
            for(char c: part) {
                // 2001:0db8:85a3:0:0:8A2E:0370:733Z is invalid
                if(!isdigit(c)&& (!isalpha(c)||toupper(c)>'F')) return false;
                // or using isxdigit() function checking whether a character is a hexadecimal digit character (0-9, a-f, A-F) or not
                // if(!isxdigit(c)) return false
            }
        }
        return true;
    }
    
    string validIPAddress(string IP) {
        return isIPv4(IP)?"IPv4":(isIPv6(IP)?"IPv6":"Neither");
    }
};