#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    
    map<char, int> m;
    int cnt=0,ans=0;

    for(int i=0;i<a.length();i++)
        m[a[i]]++;

    for(int i=0;i<b.length();i++)
        if(m[b[i]]>0){
            cnt++;
            m[b[i]]--;
        }
    
    ans = a.length() - cnt;
    ans += (b.length() - cnt);

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
