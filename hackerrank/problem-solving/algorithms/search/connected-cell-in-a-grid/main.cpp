#include <bits/stdc++.h>

using namespace std;

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    int m = (int) matrix.size(), n = (int) matrix[0].size(), ans = 0;
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int k = 0;
    function<void(int,int)> dfs = [&](int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] == 0) return;
        k++;
        matrix[i][j] = 0;
        for(int d = 0; d < 8; d++) {
            dfs(i + dx[d], j + dy[d]);
            ans = max(ans, k);
        }
    };
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j]) {
                k = 0;
                dfs(i, j);
                ans = max(ans, k);
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
