#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums)
{
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int ans=nums[n-1];
    if(n==3){
        return ans=nums[0]*nums[1]*nums[2];
    }
    int ans1=nums[0];
    if(nums[0]<0 && nums[1]<0){
        ans1=nums[0]*nums[1]*nums[n-1];
    }
    ans=nums[n-1]*nums[n-2]*nums[n-3];
    return max(ans,ans1);
}

int main()
{
    int n;
    cin>>n;
    vector<int>num;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        num.push_back(a);
    }
    cout<<solve(num)<<endl;
    return 0;
}
