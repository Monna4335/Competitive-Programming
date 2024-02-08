#include<bits/stdc++.h>
using namespace std;
long long n,has[1000005],rev_has[1000005],power[1000005],base=83,mod=1610612741;
string s,rev_s;
void hashing(){
    int i,j;
    for(i=1;i<s.size();i++){
        has[i]=(has[i-1]*base + s[i]-'a'+1)%mod;
    }
}
void reverse_hashing()
{
    int i,j;
    for(i=1;i<s.size();i++){
        rev_has[i]=(rev_has[i-1]*base + rev_s[i]-'a'+1)%mod;
    }
}

inline long long hasH(long long l,long long r){
    long long hs=has[r]-(has[l-1]*power[r-l+1])%mod;
    while(hs<0)hs+=1000*mod;
    hs%=mod;
    return hs;
}
inline long long rev_hasH(long long l,long long r){
    long long hs=rev_has[r]-(rev_has[l-1]*power[r-l+1])%mod;
    while(hs<0)hs+=1000*mod;
    hs%=mod;
    return hs;
}
inline bool palindrome(long long l,long long r){

    long long first_has=hasH(l,r);
    long long second_has=rev_hasH(n-r+1,n-l+1);
    if(first_has==second_has)return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m,i,j,k,l;
    cin>>n>>m;
    power[0]=1;
    for(i=1;i<=n;i++){
        power[i]=(power[i-1]*base)%mod;
    }
    
    cin>>s;rev_s=s;
    reverse(rev_s.begin(),rev_s.end());
    rev_s='s'+rev_s;
    s='s'+s;
    hashing();
    reverse_hashing();
    if(palindrome(3,5))cout<<"palindrome";
}
