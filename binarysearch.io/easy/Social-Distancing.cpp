/*
Social Distancing
https://binarysearch.com/problems/Social-Distancing

You are given a string s and an integer k. Each character in the string is either '.' or 'x', where '.' represents an empty space and 'x' represents a person.

Return whether it's possible to choose a position to stand on such that the distance between you and the closest person to you is at least k. (The distance between each neighbouring indices is 1).
*/

bool solve(string s, int k) {
    int n = (int) s.size(), ok = 0;
    string inner_dots(2 * k - 1, '.'), outer_dots(k, '.');
    if(
        s.find(inner_dots) != string::npos ||
        s.substr(0, k) == outer_dots ||
        s.substr(n - k) == outer_dots
    ) ok = 1;
    return ok;
}