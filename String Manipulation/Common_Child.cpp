#include <bits/stdc++.h>
#define MAX 5001
using namespace std;

static int dp[MAX][MAX];

// HERE IS OUR CODE
// TIME COMPLEXITY = O(N*M);

int commonChild(string s1, string s2) {

    int n = s1.size();
    int m = s2.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}
// HACKERRANK JUNK CODE
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

