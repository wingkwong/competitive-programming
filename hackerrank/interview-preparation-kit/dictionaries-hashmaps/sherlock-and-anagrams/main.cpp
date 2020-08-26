#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int ans=0;
    unordered_map<string, int> m;
    for(int i=0;i<s.size();i++){
        for(int j=0;j+i<=s.size();j++){
            string str = s.substr(i,j);
            if(str.size()){
                sort(str.begin(),str.end());
                if(m.count(str)) {
                    ans+=m[str];
                    m[str]++;
                }
                else m[str]=1;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
