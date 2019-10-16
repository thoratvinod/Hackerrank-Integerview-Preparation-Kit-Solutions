#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {

    map<char,int> m;
    int n = s.length();
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    int cnt=0;
    bool removed_char=false;
    int max_occur=-1;
    for(auto itr=m.begin();itr!=m.end();itr++){
        
        if(max_occur==-1)
            max_occur = itr->second;
        else if(itr->second==max_occur)
            continue;
        else if(!removed_char && ((max_occur + 1 == itr->second)||itr->second==1))
            removed_char = !removed_char;
        else
            return "NO";

    }

   return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
