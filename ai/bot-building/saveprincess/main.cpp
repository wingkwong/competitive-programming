#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    string h,v;
    
    // top-left
    if(grid[0][0]=='p'){
        h="LEFT";
    }
    // top-right
    else if(grid[0][n-1]=='p'){
        v="UP"; h="RIGHT";
    }
    // bottom-left
    else if(grid[n-1][0]=='p') {
        v="DOWN"; h="LEFT";
    }
    // bottom-right
    else if(grid[n-1][n-1]=='p'){
         v="DOWN"; h="RIGHT";
    }
    
    for(int i=0;i<n/2;i++) cout << v << "\n";
    for(int i=0;i<n/2;i++) cout << h << "\n";
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}