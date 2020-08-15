#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;




vector<vector<int>> ans;

vector<ll> curr;

vector<vector<int>> final;

void helper2( vector<bool> ar, int i, vector<ll>  arr){

    if(i==ans.size()){
        for(int j=0;j<ar.size();j++){
            // cout<<j<<" "<<ar[j]<<" ";
            if(!ar[j]){
                // cout<<endl;
                return;
            } 
        }
    

        for(auto i:final){
            for(auto j:i){
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
        return;

    }

    helper2(ar, i+1, arr);

    final.push_back(ans[i]);
    int q=0;
    for(auto& j:ans[i]){
        // cout<<j<<" ";
        if(!ar[j]) ar[j]=true;
        else{
            q=j;
            break;
        }
    }
    
    for(auto& k:ans[i]){
        if(q==k)break;
        else ar[k]=false;
    }

    // for(auto j=0;j<arr.size();j++){
    //     cout<< ar[j]<<" ";
    // }
    // cout<<endl;
    helper2(ar, i+1, arr);

}


void helper(ll equi, vector<ll>& arr,vector<ll> curr,ll ind, int sum)
{
	if(ind== arr.size()){
        if( sum == equi ){
            vector<int> temp;
            for(auto& i:curr){
                temp.push_back(i);
                // cout<<i<<" ";
            }
            ans.push_back(temp);
            // cout<<endl;
        }
        return;
    }

    helper(equi, arr, curr, ind+1, sum);
    curr.push_back(ind);
    helper(equi, arr, curr, ind+1, sum+=arr[ind]);

}
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	ll n_bags;
	ll bags;
    
	cin>>bags;
	n_bags=bags;

	vector<ll> arr;
	ll total=0;
	while(bags--)
	{
		ll goods;
		cin>>goods;
		while(goods--)
		{
			ll inp;
			cin>>inp;
			arr.push_back(inp);
			total+=inp;
		}
	}
	sort(arr.begin(),arr.end());
	ll equi = total/n_bags;
	// cout<<total<<" "<<n_bags<<endl;
	// cout<<equi<<endl;
	vector<ll> curr;
    int sum=0;
    
	helper(equi,arr,curr,0, sum);

    // for(auto i:ans){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<bool> ar(arr.size(), false);
    vector<vector<int>> final;
    helper2( ar, 0,arr);

	// cout<<ans.size();
	// for(ll i=0;i<ans.size();i++)
	// {
	// 	for(ll j=0;j<ans[i].size();j++)
	// 	{
	// 		cout<<ans[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}