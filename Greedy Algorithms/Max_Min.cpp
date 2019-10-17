#include <bits/stdc++.h>

using namespace std;

// HERE IS OUR CODE
// TIME COMPLEXITY : O(N*LOG(N))
int maxMin(int k, vector<int> arr) {

    sort(arr.begin(),arr.end());
    int n = arr.size();
    int i=0,j=k-1;
    int _min = INT_MAX;
    while(j<n){
        _min = min(_min,arr[j]-arr[i]);
        i++;j++;
    }
    return _min;

}

// HACKERRANK JUNK CODE
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

