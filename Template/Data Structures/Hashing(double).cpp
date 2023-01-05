#include<bits/stdc++.h>
using namespace std;
string s;
long long prefix[1000005],pw[1000005],mod = 2e9+63, base = 1e9+21,n,prefix2[1000005],pw2[1000005], base2 = 1e9+181;
void make_hash(){
	prefix[0]=0;
	for(int i=1;i<=n*2;i++){
		prefix[i]=((prefix[i-1]*base)%mod+(s[i]-'a'+1))%mod;
		prefix[i]%=mod;
	}
	prefix2[0]=0;
	for(int i=1;i<=n*2;i++){
		prefix2[i]=((prefix2[i-1]*base2)%mod+(s[i]-'a'+1))%mod;
		prefix2[i]%=mod;
	}

}

long long has(long long ind,long long indd){
	long long prehsh=prefix[indd];
	long long pre=(prefix[ind-1]*pw[(indd-ind+1)])%mod;
	prehsh-=pre;
	if(prehsh<0)prehsh+=mod;

	long long prehsh2=prefix2[indd];
	long long pre2=(prefix2[ind-1]*pw2[(indd-ind+1)])%mod;
	prehsh2-=pre2;
	if(prehsh2<0)prehsh2+=mod;


	return (prehsh<<32)|prehsh2;
}
bool com(int p){
	int l2=(n*2)-p+1;
	int l1=1,md,an=0;
	while(l1<=l2){
		md=(l1+l2)/2;
		if(has(1,md)==has(p,p+md-1)){
			an=md;
			l1=md+1;
		}
		else l2=md-1;
	}
	if(an==(n*2)-p+1)return 0;
	l1=1+an;
	p+=an;
	
	if(s[l1]<s[p]){
		return 1;
	}
	else return 0;
}
int main()
{
	long long m,i,j,k,l;

	pw[1]=base;
	pw2[1]=base2;cin>>n>>k;
	for(i=2;i<=n*2;i++){
		pw[i]=pw[i-1]*base;
		pw[i]%=mod;
		pw2[i]=pw2[i-1]*base2;
		pw2[i]%=mod;
	}
	
	int p=n;
	cin>>s;
	s+=s;
	s='0'+s;
	make_hash();
	for(i=2;i<=n;i++){
		l=com(i);
		if(l){
			p=i-1;break;
		}

	}

	i=0;
	while(k--){
		i++;
		i%=(p+1);
		if(i==0){
			i=1;
		}
		cout<<s[i];
	}
	cout<<endl;

}
