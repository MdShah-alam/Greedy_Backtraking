#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&vec,int m)
{
    int n=vec.size();
    if(m==0) return 0;

    int ans=0;
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) { return b[1] < a[1];});
    for(int i=0;i<n;i++){
        if(m==0)
            break;
        if(m>=vec[i][0]){
            ans=ans+vec[i][0]*vec[i][1];
            m=m-vec[i][0];
        }
        else{
            ans=ans+m*vec[i][1];
            m=m-m;
        }
    }
    return ans;
}

/**
4 10

5 10
2 5
4 7
3 9
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>vec;
    for(int i=0;i<n;i++){
            vector<int>v;
        for(int j=0;j<2;j++){
            int a;
            cin>>a;
            v.push_back(a);
        }
        vec.push_back(v);
    }
    cout<<solve(vec,m)<<endl;
    return 0;
}
