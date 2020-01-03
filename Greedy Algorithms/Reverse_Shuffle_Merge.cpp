#include <bits/stdc++.h>

using namespace std;

// HERE IS OUR CODE


static int sol_count[26] = {};
static int rem_count[26] = {};
static int word_count[26] = {};
static char sol[10001];
// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {

    int n = s.size();

    for(int i=0;i<n;i++){

        rem_count[s[i]-'a']++;

    }
    for(int i=0;i<26;i++){

        word_count[i] = rem_count[i]/2;
    }

    int j=0,char_idx;
    
    for(int i=n-1;i>=0;i--){

        char_idx = s[i]-'a';
        if(i==n-1){

            sol[j] = s[i];
            j++;
            rem_count[char_idx]--;
            sol_count[char_idx]++;
            continue;
        }

        if(sol_count[char_idx] < word_count[char_idx]){

            if(s[i] >= sol[j-1]){

                sol[j] = s[i];
                j++;
                rem_count[char_idx]--;
                sol_count[char_idx]++;
            }
            else{

                while(j>0 && (s[i] < sol[j-1]) && sol_count[sol[j-1]-'a']+rem_count[sol[j-1]-'a']-1 >= (word_count[sol[j-1]-'a']))
                    sol_count[sol[--j]-'a']--;

                sol[j] = s[i];
                j++;
                sol_count[char_idx]++;
                rem_count[char_idx]--;
            }
        }else
            rem_count[char_idx]--;

    }
    sol[j] = '\0';

    string ans(sol);
        
    return ans;

}


// HACKERRANK JUNK
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
