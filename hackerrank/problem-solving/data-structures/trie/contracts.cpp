#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
    vector<int> ans;
    unordered_map<string, int> m;
    for(auto q : queries) {
        if(q[0] == "add") {
            string data = q[1];
            for(int i = 1; i <= data.size(); i++) {
                string s = data.substr(0, i);
                if(m.count(s)) m[s]++;
                else m[s] = 1;
            }
        } else {
            string data = q[1];
            if(m.count(data)) ans.push_back(m[data]);
            else ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
