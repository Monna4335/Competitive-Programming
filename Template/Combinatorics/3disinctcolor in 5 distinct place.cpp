long long count(long long place,long long color){
	//need to place 3 distinct color many balls into distinct places
	if(place<color)return 0;
	if(plc[place][color]!=-1)return plc[place][color];
	long long cnt=0,j=0,i;
	for(i=color;i>=1;i--){
		j++;
		if(j%2){
			cnt += ((ncr[color][i]*bigmod(i,place))%mod);
			cnt %= mod;
		}
		else{
			cnt -= ((ncr[color][i]*bigmod(i,place))%mod);
			while(cnt<mod)cnt+=1000*mod;
			cnt %= mod;
		}
	}
	return plc[place][color]=cnt;
}
