/*
Hack the Interview IV (Asia Pacific) - Arrange Students
https://www.hackerrank.com/contests/hack-the-interview-iv-apac/challenges/arrange-students
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrangeStudents' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

string arrangeStudents(vector<int> a, vector<int> b) {
    // the order must be [b1,g1,b2,g2...] or [g1,b1,g2,b2...]
    // sort them first in ascending order
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    // I realise that m is actually equal to n ... 
    int m = (int)a.size();
    int n = (int)b.size();
    // default turn
    bool turn=a[0]<b[0]?1:0; //1:boy //2:girl
    int i=0,j=0,k,x;
    
    // correct the turn as they can have the same height 
    // locate one with different height
    for(int y=0;y<m;y++){
        if(a[y]==b[y]) continue;
        turn=a[y]<b[y]?1:0; 
        break;
    }
    
    i=0;j=0;
    // make a queue, select one person from each line 
    // compare their heights 
    // update the pointer 
    queue<int> q;
    while(i<m||j<n){
        x=turn?a[i]:b[j];
        if(q.empty()) q.push(x);
        else{
            k=q.front();
            q.pop();
            if(x<k) return "NO";
            q.push(x);
        }
        
        turn?i++:j++;
        turn=!turn;
    }
    return "YES";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        string result = arrangeStudents(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
