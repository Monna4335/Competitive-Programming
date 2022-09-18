#include<bits/stdc++.h>
using namespace std;
string s;
long long d,P,dp[2001][2][2001],mod=1000000007;
long long ok(long long ind,long long bound,long long md){
	if(ind==s.size()){
		if(md==0)return 1;
		else return 0;
	}
	if(dp[ind][bound][md]!=-1)return dp[ind][bound][md];
	long long ans=0,k;
	if(bound){
		k=s[ind]-'0';
		if(ind%2){
			if(d>k)return 0;
			else if(k==d){
				ans=ok(ind+1,bound,(md*10+d)%P);
			}
			else{
				ans=ok(ind+1,0,(md*10+d)%P);
				ans%=mod;
			}
		}
		else{
			for(int i=0;i<=k;i++){
				if(i!=d)ans+=ok(ind+1,(i==k),(md*10+(i))%P);
				ans%=mod;
			}
		}
	}
	else{
		if(ind%2){
			ans=ok(ind+1,0,(md*10+d)%P);
		}
		else{
			for(int i=0;i<=9;i++){
				if(i!=d)ans+=ok(ind+1,0,(md*10+(i))%P);
				ans%=mod;
			}
		}
	}
	return dp[ind][bound][md]=ans%mod;
}
bool huhh(){
	long long mmd=0;
	for(int i=0;i<s.size();i++){
		if(i%2==1 && (s[i]-'0')!=d){return 0;}
		else if(i%2==0 && (s[i]-'0')==d)return 0;
		mmd*=10;
		mmd+=(s[i]-'0');
		mmd%=P;
	}
	return mmd==0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>P>>d;
	cin>>s;
	long long ans;
	memset(dp,-1,sizeof dp);
	long long cnt1=ok(0,1,0);
	int huh=huhh();
	cin>>s;
	memset(dp,-1,sizeof dp);
	long long cnt2=ok(0,1,0);
	ans=cnt2-cnt1+huh+mod;
	ans%=mod;
	cout<<ans;


}
