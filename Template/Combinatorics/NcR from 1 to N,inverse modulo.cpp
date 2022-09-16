#include<bits/stdc++.h>
using namespace std;
long long inverse[1000006],fact[1000006],mod=1000000007;
void fac(){
	fact[0]=1;
	for(int i=1;i<=1000006;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
}
void inve(){
	inverse[0]=1;
	inverse[1]=1;
	for(int i=2;i<=1000000;i++){
		inverse[i]=(inverse[mod%i]*(mod-(mod/i)))%mod;
		inverse[i]%=mod;
	}
	for(int i=1;i<=1000000;i++){
		inverse[i]=(inverse[i-1]*inverse[i])%mod;
	}
}
long long ncr(long long n,long long r){
	return ((inverse[n-r]*inverse[r])%mod * fact[n])%mod;
}

long long bgmd(long long a,long long b){
	if(b==0)return 1;
	if(b%2){
		return (a*bgmd(a,b-1))%mod;
	}
	else{
		long long x=bgmd(a,b/2);
		x*=x;
		x%=mod;
		return x;
	}
}
int main()
{
	inve();
	fac();
	long long n,a,b,d;
	while(cin>>n>>a>>b>>d){
		long long nr=ncr(n,a);
		long long bd=ncr(b,d);
		bd=bgmd(bd,a);
		nr*=bd;
		nr%=mod;
		cout<<nr<<"\n";
	}
	


}
