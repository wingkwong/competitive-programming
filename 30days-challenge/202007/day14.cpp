/*
Angle Between Hands of a Clock

Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.


Example 1:

Input: hour = 12, minutes = 30
Output: 165
Example 2:

Input: hour = 3, minutes = 30
Output: 75
Example 3:

Input: hour = 3, minutes = 15
Output: 7.5
Example 4:

Input: hour = 4, minutes = 50
Output: 155
Example 5:

Input: hour = 12, minutes = 0
Output: 0
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
Answers within 10^-5 of the actual value will be accepted as correct.
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        // each minute is 6 degree (360/60)
        // each hour is 30 degree (360/12) 
        // echo hour has 60 mins so each min is 0.5 degree (30/60)
        double minute=minutes*6, hr=hour*30+(double)minutes/2, angle=abs(hr-minute);
        // if it is obtuse, make it acute
        return min(angle, 360-angle);
    }
};