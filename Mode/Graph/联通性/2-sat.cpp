all_tarjin(n*2);
for (int i=1; i<=n; i++){
	if(belong[2*i] == belong[2*i-1]){
		cout << "NO" << endl;
		break;
	}
	if(i == n)cout << "YES" << endl;
}

2-sat 主要注意建图跑tarjin
选谁后，必须选谁？—— 然后对所有点跑一遍tarjin
