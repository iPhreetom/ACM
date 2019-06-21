	#include<bits/stdc++.h>
using namespace std;

void flash() {
	cout << endl;
	cout << "\t :";
	system("pause");
	system("cls");
}

void println(const string &s) {
	cout << s << endl;
}

struct line_hash_map {
	int lis[20];
	int cnt[20];
	bool push(int s) {
		int num = 1;
		int val = s%20;
		while (lis[val] != 0) {
			if (lis[val] == s) {
				cout << "Exist" << endl;
				return false;
			}
			num ++;
			val ++;
			val %= 20;
		}
		lis[val] = s;
		cnt[val] = num;
		return true;
	}
	bool find(int s) {
		int val = s%20;
		while (!lis[val]) {
			if (s == lis[val]) return true;
			else {
				val ++;
				val %= 20;
			}
		}
		return false;
	}
	void report() {
		for (int i=0; i<20; i++){
		    cout<<lis[i]<<' ';
		}cout<<endl;
		for (int i=0; i<20; i++){
		    cout<<cnt[i]<<' ';
		}cout<<endl;
	}
	void report2() {
		int sum = 0;
		int sum_sub = 0;
		for (int i=0; i<17; i++){
			sum += cnt[i];
			if (cnt[i] != 0) sum_sub++;
		}
		cout << "The average length of successful find is " << sum << '/' << sum_sub << endl;

		sum = 0;
		// sum_sub = 17;
		for (int i=0; i<17; i++){
			for (int j=i; j<17; j++){
				if (!lis[j]) sum++;
			}
		}
		cout << "The average length of failure find is " << sum << '/' << sum_sub << endl;
	}
};


int main() {
	while (true) {
		line_hash_map mpa;
		memset(mpa.cnt,0,sizeof(mpa.cnt));
		memset(mpa.lis,0,sizeof(mpa.lis));
		int chose=1;
		// flash();
		println("Input the element your want to insert");
		println("Input the word [END] to end the input");
		if (chose == 1) {
			while (true) {
				int s;
				cin >> s;
				if (mpa.push(s) ) {
					cout << "OK, insert" << endl;
				}
				mpa.report();
				cout << endl;
				cout << endl;
			}
		}
		else {
			continue;
		}
		flash();
	}
}
// Jan
// Feb
// Mar
// Apr
// May
// June
// July
// Aug
// Sep
// Oct
// Nov
// Dec

// 78 33 10 41 6 15 64 27 14
