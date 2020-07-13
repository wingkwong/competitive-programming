/*
Reformat Date

Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.
MM denotes the 2 digit month.
DD denotes the 2 digit day.
 

Example 1:

Input: date = "20th Oct 2052"
Output: "2052-10-20"
Example 2:

Input: date = "6th Jun 1933"
Output: "1933-06-06"
Example 3:

Input: date = "26th May 1960"
Output: "1960-05-26"
 

Constraints:

The given dates are guaranteed to be valid, so no error handling is necessary.
*/

class Solution {
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string s;
        vector<string> v;
        while(ss>>s) v.push_back(s);
        string day="";
        // extract the day
        for(int i=0;i<v[0].size();i++){
            if(isdigit(v[0][i])){
                day+=v[0][i];
            }
        }
        // e.g. 6 -> 06
        if(day.size()==1) day="0"+day;
        // extract the month
        vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int i=0;
        while(v[1]!=month[i]) i++;
        string m=to_string(i+1);
        if(m.size()==1) m="0"+m;
        return v[2] + "-" + m + "-" + day;
    }
};