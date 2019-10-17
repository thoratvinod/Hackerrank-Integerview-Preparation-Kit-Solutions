#include <iostream>

using namespace std;
// HERE IS OUR CODE
// TIME COMPLEXITY : O(2^N)
int fibonacci(int n) {

    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);

}
// HACKERRANK CODE JUNK
int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}


