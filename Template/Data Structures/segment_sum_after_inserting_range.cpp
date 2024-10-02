
long long sum=0;
set<pair<long long,long long>>st;
void add(long long x,long long y)
{
    
	if(stt.size()==0){
		ans+=(y-x+1);
		stt.insert({x,y});
		return;
	}
	
	auto t=stt.lower_bound({x,0});
	if(t==stt.end()){
		t--;
		if(t->second <x){
			ans += (y-x+1);
			stt.insert({x,y});
		}
		else if(t->second<=y){
			ans += (y - t->second);
			long long fr = t->first;
			stt.erase(t);
			stt.insert({fr,y});
		}

	}
	else{
		
			if(t!=stt.begin())t--;
			if(t->second<x)t++;
			vector<pair<long long,long long>>rem;
			while(t!=stt.end()){
				if((t->second >= x) && (t->first)<=y){
					rem.push_back({t->first,t->second});
					t++;
				}
				else break;
			}
			long long cur_sum=0;
			for(auto t:rem){
				cur_sum += (t.second-t.first+1);
				stt.erase(stt.find({t.first,t.second}));
				x=min(x,t.first);
				y=max(y,t.second);
			}
			ans += (y-x+1) - cur_sum;
			stt.insert({x,y});
	}

}
