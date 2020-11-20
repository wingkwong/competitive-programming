bool solve(string s) {
    int a = 0;
    for(char c : s){
        if(c == '(') a++;
        else {
            if(a == 0) return false; 
            a--;
        }
    }
    return a == 0;
}