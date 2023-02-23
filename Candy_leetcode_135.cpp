#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& ratings)
{
    int ans=0;
    int n=ratings.size();
    vector<int>l(n,1);
    vector<int>r(n,1);
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            l[i]=l[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            r[i]=r[i+1]+1;
        }
    }
    for(int i=0;i<n;i++){
        ans+=max(r[i],l[i]);
    }
    return ans;
}/**

5
0 3 2 1 0

3
0 1 0

*/
int main()
{
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a.push_back(k);
    }

    cout<<solve(a)<<endl;
    return 0;
}
