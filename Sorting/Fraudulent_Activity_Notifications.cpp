#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

float findMedian(int arr[], int d, int med_pos){
   
    int count=0,left=0;
    while(count<med_pos){
        count +=arr[left];
        left++;
    }
    int right = left;
    left--;

    if(count>med_pos||d%2!=0){
        return left;
    }else{
        while(arr[right]==0)
            right++;
        
        return (float)(left+right)/2;
    }

}
// Complete the activityNotifications function below.
int activityNotifications(vector<int> exp, int d) {

    int arr[200];
    int n = exp.size();
    memset(arr,0,200*sizeof(arr[0]));
    for(int i=0;i<d;i++){
        arr[exp[i]]++;
    }
    int j=0;
    int ans=0; 
    int med_pos;

    if(d%2==0){
        med_pos=(d/2);
    }
    else{
        med_pos = (d/2)+1;
    }
    for(int i=d;i<n;i++){
        float median = findMedian(arr,d,med_pos);
        
        if(exp[i] >= median*2)
            ans++;
        
        arr[exp[j]]--;
        arr[exp[i]]++;
        j++;
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

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
