#include "solution.hpp"
using namespace std;


class Solution {
    public:
    vector<string> solve(vector<string>& book, int page, int page_size) {
        vector<string> ans;
        int n = book.size();
        for(int i=page*page_size; i<n && i<(page+1)*page_size; i++)
            ans.push_back(book[i]);
        return ans;
    }
};
