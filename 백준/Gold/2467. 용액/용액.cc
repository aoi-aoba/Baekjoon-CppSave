#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int start = 0, fin = N-1;
    ll left = arr[0], right = arr[N-1];
    ll sum = left + right;

    while(start < fin){
        ll next = arr[start] + arr[fin];
        if(abs(sum) > abs(next)){
            sum = next;
            left = arr[start];
            right = arr[fin];
        }
        if(next <= 0) start++;
        else fin--;
    }

    cout << left << " " << right;
    return 0;
}