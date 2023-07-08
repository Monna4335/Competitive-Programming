#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T,null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//order of key means lower bound
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long mx=1429431 + 20;
	ordered_set<long long>s;
	for(int i=1;i<=mx;i+=2){
		s.insert(i);
	}
	vector<long long>v;
	long long f,j;
	for(int ii=2;ii<=100000;ii++){
		if(s.size()<=ii)break;
		f=*s.find_by_order(ii-1);
		for(j=f;j<s.size();j+=f){
			v.push_back(*s.find_by_order(j-1));
		}
		for(auto t:v){
			s.erase(s.find_by_order(s.order_of_key(t)));
		}
		v.clear();
	}
	
	int tc,r=0;
	cin>>tc;
	while(tc--){
		cout<<"Case "<<++r<<": ";
		long long n;
		cin>>n;
		cout<<(*s.find_by_order(n-1))<<"\n";
	}
}
