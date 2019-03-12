auto getNext = [&](auto &v) {
	if(v.size() <= 1)return;
	next[0] = -1;
	next[1] = 0;
	int cnt = 0;
	int pos = 2;
	while(pos < next.size()) {
		if(v[pos-1] == v[cnt]) {
			next[pos++] = ++cnt;
		}
		else if(cnt > 0) {
			cnt = next[cnt];
		}
		else {
			next[pos++] = 0;
		}
	}
};
auto findnum = [&](auto &a,auto &b) -> int{
	getNext(b);
	int j = 0;
	int ans = 0;
	for (int i=0; i<a.size(); i++){
		while(j && b[j] != a[i])j = next[j];
		if(b[j] == a[i])j++;
		if(j == b.size())return i-j+2;
	}
	return -1;
};
