/*
Day of the Week

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"

Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"

Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"

Constraints:

The given dates are valid dates between the years 1971 and 2100.
*/
class Solution {
public:
    string dayOfTheWeek(int d, int m, int y, int c = 0) {
        vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (m < 3) m += 12, y -= 1;  // m is the month (3 = March, 4 = April, 5 = May, ..., 14 = February)
        c = y / 100, y = y % 100;// c is the zero-based century ; y is the year of the century (year%100)
        // Zeller's congruence
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return days[(w + 7) % 7];
    }
};