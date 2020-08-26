#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void f(int n, int k){
    /*
    S – Set of numbers from 1 to N [Eg: 1,2,3…N]

    N – The last number in the set

    K – Threshold number [i.e limit for the answer to be obtained] and this value can be K <= N

    Since our answer should be < K, the possible answer would be <= K-1.

    We know that while doing an AND operation between 2 numbers, the answer would be <= LOWEST NUMBER of those 2 numbers. And we need to find this LOWEST NUMBER which is <= K-1

    So we need to find an AND pair which would result with our required answer.

    STEP 1: Since K-1 is the highest possible answer, we will take it as one of the 2 numbers. The other number should be > K-1 due to the AND property and it would be >= K. It’s best to take a number whose binary equivalent is similar to K-1’s binary value. So K would be the best choice.

    Note: By doing an OR operation between 2 numbers, the answer would be >= HIGHEST NUMBER of the 2 numbers.

    STEP 2: To find the other number we perform OR operation between the highest possible answer and the immediate larger number to it.

    i.e [(K-1) OR (K-1)+1] which is nothing but [(K-1) OR K] and its result would be >= K.

    STEP 3: Now we got the AND pair which are K-1 and K (minimum possible result of the above OR operation) and our AND result would be <= K-1.

    For most cases we will get the final answer as K-1 itself but not for all cases.

    a) When K is odd, the final answer will definitely be K-1 because if K is odd, K-1 will be even. Here only the LSB of the binary equivalent will be different. Eg: K=5(0101) ; K-1=4(0100)

    b) When K is even, K-1 will be odd and both number's binary values might not be similar. Eg: K=8(1000) ; K-1=7(0111)

    c) K-1 will be the answer only when the result of OR operation is <= N. If its > N, we would end up using a number which is not in the given number set for the AND operation which might result in a wrong final answer.

    So these cases occur when {(K-1 OR K) > N} and when K is even.

    For these scenarios, the highest possible answer would not be K-1 and it'll be the next lesser number K-2. The AND pairs for such scenarios would be K-2 and K-1 resulting with a final answer K-2.

    For the above cases, K-1 cannot be the highest possible answer so we take next the lesser number K-2 as the highest possible answer and we start again from STEP 1 replacing K-1 with K-2 and K with K-1.   
    */
    if(((k-1)|k)>n&&k%2==0) cout << k-2 << "\n";
    else cout << k-1 << "\n";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        f(n,k);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
