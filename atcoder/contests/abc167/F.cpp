#include <bits/stdc++.h>
using namespace std; 

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)

bool isValid(string s) {
    stack<char> st;
    map<char,char> m;
    m.insert({')', '('});
    for(char c:s){
        if(c==')'){
            char t = st.empty()?'*':st.top();
            if(m[c]!=t) return false; 
            st.pop();
        } else{
            st.push(c);
        }
    }
    return st.empty();
}

int main()  
{ 
    FAST_INP;
    int n; 
    cin >> n;
    string s="";
    while(n--){
        string ss;
        cin >> ss;
        s+=ss; 
    }

    if(count(s.begin(),s.end(),'(') != count(s.begin(),s.end(),'(')) cout << "No\n";
    
    cout << (isValid(s)?"Yes":"No")<<"\n";
    return 0;
} 