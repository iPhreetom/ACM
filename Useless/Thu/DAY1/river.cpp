#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<string> ans;
bool findit = 0;

bool check(vector<int> v) {
	if (v[0] == 1 && v[2] == 1) {
		return false;
	}
	if (v[1] == 1 && v[2] == 1) {

	}
}

void dfs(vector<int> record, bool right) {
	if (findit) return;
	if (right) {
		for (int i=0; i<record.size(); i++){
			if (i == 0) {
				ans.push_back("H");
				dfs(record,!right);
				ans.pop_back();
			}
		    if (!record[i]) {
				if (!check(record)){
					record[i] = 1;
					continue;
				}
				record[i] = 1;
				if (i == 0) ans.push_back("HW");
				if (i == 1) ans.push_back("HV");
				if (i == 1) ans.push_back("HS");
				dfs(record,!right);
				record[i] = 0;
				ans.pop_back();
			}
		}
	}
	else {
		for (int i=0; i<record.size(); i++){
		    if (record[i]) {
				record[i] = 0;
				if (!check(record)){
					record[i] = 1;
					continue;
				}
				if (i == 0) ans.push_back("HW");
				if (i == 1) ans.push_back("HV");
				if (i == 1) ans.push_back("HS");
				if ((record[0] == record[1]) && (record[1] == record[2]) && (record[2] == 0)) {
					for (int i=0; i<ans.size(); i++){
						if(i == 0) {
							cout << ans[i];
						}
						else {
							cout << ' ' << ans[i];
						}
					}
					findit = true;
					return ;
				}
				dfs(record,!right);
				record[i] = 1;
			}
		}
	}
}

int main () {
	vector<int> record(3,1);
	dfs(record, 0);
	return 0;
}
