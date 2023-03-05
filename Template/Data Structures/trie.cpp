#include<bits/stdc++.h>
using namespace std;
long long prefix_xor[500005],prefix_max_xor[500005],a[500005],suffix_xor[500005],suffix_max_xor[500005];
struct trie{
	trie *l,*r;

	trie(){
		l=NULL;
		r=NULL;
	}
}*root;
void insert(long long p){
	trie* cur=root;
	for(int i=30;i>=0;i--){
		if((1ll<<i & p)){
			if(cur->l==NULL){
				cur->l=new trie();
			}
			cur=cur->l;
		}
		else{
			if(cur->r==NULL){
				cur->r=new trie();
			}
			cur=cur->r;
		}
	}
}
long long ok(long long p){
	trie* cur=root;
	long long ans=0;
	for(int i=30;i>=0;i--){
		if((1ll<<i & p)){
			if(cur->r!=NULL){
				cur=cur->r;
				ans+=(1ll<<i);
			}else
			cur=cur->l;
		}
		else{
			if(cur->l!=NULL){
				cur=cur->l;
				ans+=(1ll<<i);
			}
			else
			cur=cur->r;
		}
	}
	return ans;
}
void deleete(trie * cur){
	if(cur->l!=NULL){
		deleete(cur->l);
	}
	if(cur->r!=NULL)deleete(cur->r);
	delete(cur);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	root=new trie();
	long long n,m,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	insert(0);
	for(i=1;i<=n;i++){
		prefix_xor[i]=prefix_xor[i-1]^a[i];
	}
	for(i=1;i<=n;i++){
		insert(prefix_xor[i]);
		prefix_max_xor[i]=max(prefix_max_xor[i-1],ok(prefix_xor[i]));
		

	}
	deleete(root);


	root=new trie();
	insert(0);
	for(i=n;i>=1;i--){
		suffix_xor[i]=suffix_xor[i+1]^a[i];
	}
	for(i=n;i>=1;i--){
		insert(suffix_xor[i]);
		suffix_max_xor[i]=max(suffix_max_xor[i+1],ok(suffix_xor[i]));
		

	}
	long long ans=0;
	for(i=1;i<n;i++){
		ans=max(ans,prefix_max_xor[i]+suffix_max_xor[i+1]);
	}
	cout<<ans<<endl;

}
