#include <bits/stdc++.h>
using namespace std;

const int MAX=101010;
int N,A[MAX];

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    sort(A+1,A+N+1);

    pair<int,int> ans={A[1],A[2]};
    
    if (A[N]<0) ans={A[N-1],A[N]};
    if (A[1]>0) ans={A[1],A[2]};

    for (int i=1; i<=N; i++) {
        int lb=lower_bound(A+1,A+i,-A[i])-A;

        for (int j=max(1,lb-2); j<=min(i-1,lb+2); j++) {
            if (abs(A[i]+A[j])<abs(ans.first+ans.second)) {
                ans={A[j],A[i]};
            }
        }
    }

    cout<<ans.first<<' '<<ans.second<<'\n';

    return 0;
}