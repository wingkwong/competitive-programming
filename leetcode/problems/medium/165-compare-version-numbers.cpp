class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1), is2(version2);
        int num1=0, num2=0;
        char c;
        while(bool(is1>>num1)+bool(is2>>num2)){
            if(num1>num2) return 1;
            if(num1<num2) return -1;
            is1>>c, is2>>c;
            num1=num2=0;
        }
        if(num1==num2) return 0;
        return 0;
    }
};