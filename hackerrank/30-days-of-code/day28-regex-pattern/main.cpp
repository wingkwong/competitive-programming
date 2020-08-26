#include <set>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
    int N;
    cin >> N;
    regex e(".+@gmail\\.com$");
    multiset<string> ms;
    for(int i=0; i<N; i++)
    {
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        if(regex_match(emailID,e)) ms.insert(firstName);
    }
    for(auto& it : ms) cout << it << endl; 
    return 0;
}