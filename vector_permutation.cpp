#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>>ans;
vector<int>initial_state;

bool solution_found(vector<int>state)
{
    return initial_state.size()==state.size();
}

vector<int>get_candidates(vector<int>state)
{
    map<int,int>taken;
    for(int x : state)
        taken[x]=1;

    vector<int>candidates;
    for(int candidate : initial_state){
        if(taken.count(candidate)==0)
            candidates.push_back(candidate);
    }
    return candidates;
}

void back_track(vector<int>state)
{
    if(solution_found(state)){
        ans.push_back(state);
        return ;
    }

    vector<int>candidates = get_candidates(state);

    for(int x: candidates){
        state.push_back(x);

        back_track(state);

        state.pop_back();
    }
}

int main()
{
    cin>>n;
    vector<int>state;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        initial_state.push_back(a);
    }
    back_track(state);

    for(vector<int>permutation : ans){
        for(int x : permutation){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
