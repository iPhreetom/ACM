#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
using namespace std;

class HugeInt{
private:
	string val;

	string string_add(string a,string b){
		string ret;
		int add = 0;
		int short_len = min(a.size(),b.size());
		int long_len = max(a.size(),b.size());
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		for (int i=0; i<short_len; i++){
			int num_a = a[i]-'0';
			int num_b = b[i]-'0';
			int digit = (num_a + num_b + add)%10;
			add = (num_a + num_b + add)/10;
			ret.push_back(digit+'0');
		}
		for (int i=short_len; i<long_len; i++){
			int num_a;
			if(a.size() > b.size()){
				num_a = a[i]-'0';
			}
			else{
				num_a = b[i]-'0';
			}
			int digit = (num_a + add)%10;
			add = (num_a + add)/10;
			ret.push_back(digit+'0');
		}
		if(add){
			ret.push_back(add+'0');
		}

		reverse(ret.begin(),ret.end());
		return ret;
	}
	string string_sub(string a,string b){
		string ret;
		int add = 0;
		int short_len = min(a.size(),b.size());
		int long_len = max(a.size(),b.size());
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		for (int i=0; i<short_len; i++){
			int num_a = a[i]-'0';
			int num_b = b[i]-'0';
			int digit = (num_a + add - num_b + 20)%10;
			add = (num_a + add - num_b)/10;
			ret.push_back(digit+'0');
		}
		for(int i=short_len; i<long_len; i++){
			int num_a = a[i]-'0';
			int digit = (num_a + add + 20)%10;
			add = (num_a + add)/10;
			ret.push_back(digit+'0');
		}
		while(ret.size() > 1 && ret.back() == '0'){
			ret.pop_back();
		}

		reverse(ret.begin(),ret.end());
		return ret;
	}
	string string_mul(string a,string b){
		string ret = "0";
		int add = 0;
		int short_len = min(a.size(),b.size());
		int long_len = max(a.size(),b.size());
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());

		if(a != "0" && b != "0"){
			for (int i=0; i<a.size(); i++){
				string temp;
				int num_a = a[i]-'0';

				for (int j=0; j<i; j++){
					temp.push_back('0');
				}
				for (int j=0; j<b.size(); j++){
					int num_b = b[j]-'0';
					int digit = (num_a*num_b + add)%10;
					add = (num_a*num_b + add)/10;
					temp.push_back(digit+'0');
				}
				if(add){
					temp.push_back(add+'0');
					add = 0;
				}
				reverse(temp.begin(),temp.end());
				ret = string_add(ret,temp);
			}
		}

		return ret;
	}
	string string_div(string a,string b){
		string ret = "0";
		int add = 0;
		int cnt = 0;
		int short_len = min(a.size(),b.size());
		int long_len = max(a.size(),b.size());
		int b_len = b.size();

		assert(b != "0");
		if(b.size() >= a.size() && b > a){
			return "0";
		}
		if(b == a){
			return "1";
		}

		while(b.size() < a.size()){
			cnt++;
			b.push_back('0');
		}

		while(1){
			bool sub = 0;
			string temp ;
			int add = 0;
			if(b.size() > a.size() || (a.size() == b.size() && b > a)){
				if(b.size() == b_len)break;
				cnt--;
				b.pop_back();
			}
			while(a.size() > b.size() || (a.size() == b.size() && a >= b)){
				a = string_sub(a,b);
				add++;
				sub = 1;
			}
			if(sub){
				temp.push_back(add+'0');
				for (int i=0; i<cnt; i++){
					temp.push_back('0');
				}
				ret = string_add(ret,temp);
			}
			if(!sub)break;
		}
		return ret;
	}
    string int_to_string(int anthor){
        string ret;
		bool negtive = 0;

		if(anthor < 0)negtive = 1;
        if(anthor == 0){
            ret = "0";
        }
        else{
            while(anthor){
				ret.push_back(anthor%10 + '0');
				anthor/=10;
            }
			if(negtive){
				ret.push_back('0');
			}
        }
		reverse(ret.begin(),ret.end());
		return ret;
    }
	string long_long_to_string(int anthor){
		string ret;
		bool negtive = 0;
		if(anthor < 0)negtive = 1;
        if(!anthor){
            ret = "0";
        }
        else{
            while(anthor){
				ret.push_back(anthor%10 + '0');
				anthor/=10;
            }
			if(negtive){
				ret.push_back('0');
			}
        }
		reverse(ret.begin(),ret.end());
		return ret;
	}

public:
    HugeInt(){};
	HugeInt(string s):val(s){};
	HugeInt(const HugeInt& anthor){
		this->val = anthor.val;
	};
	HugeInt(int s){
		this->val = int_to_string(s);
	};
	HugeInt(long long s){
		this->val = long_long_to_string(s);
	};
	~HugeInt(){};

	HugeInt operator+ (const HugeInt& anthor){
		HugeInt ret;
		int add = 0;
		string a = this->val;
		string b = anthor.val;

		assert(!a.empty() && !b.empty());
		if(a[0] =='-'){
			if(b[0] == '-'){
				a.erase(0,1);
				b.erase(0,1);
				ret.val = string_add(a,b);
				reverse(ret.val.begin(),ret.val.end());
				ret.val.push_back('-');
				reverse(ret.val.begin(),ret.val.end());
			}
			else{
				a.erase(0,1);
				if(b.size() > a.size()  || (b.size() == a.size()  && b>=a)){
					ret.val = string_sub(b,a);
				}
				else{
					ret.val = string_sub(a,b);
					reverse(ret.val.begin(),ret.val.end());
					ret.val.push_back('-');
					reverse(ret.val.begin(),ret.val.end());
				}
			}
		}
		else{
			if(b[0] == '-'){
				swap(a,b);
				a.erase(0,1);
				if(b.size() > a.size()  || (b.size() == a.size()  && b>=a)){
					ret.val = string_sub(b,a);
				}
				else{
					ret.val = string_sub(a,b);
					reverse(ret.val.begin(),ret.val.end());
					ret.val.push_back('-');
					reverse(ret.val.begin(),ret.val.end());
				}
			}
			else{
				ret.val = string_add(a,b);
			}
		}
		return ret;
	}
	HugeInt operator+ (const int& anthor){
		HugeInt ret;
		ret.val = int_to_string(anthor);
		ret = *this + ret;
		return ret;
	}
	HugeInt operator+ (const long long& anthor){
		HugeInt ret;
		ret.val = long_long_to_string(anthor);
		ret = *this + ret;
		return ret;
	}
	HugeInt operator+ (const string& anthor){
		HugeInt ret;
		ret.val = anthor;
		ret = *this + ret;
		return ret;
	}
	HugeInt &operator+= (const HugeInt& anthor){
		HugeInt ret = *this;
		ret = ret + anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator+= (const int& anthor){
		HugeInt ret = *this;
		ret = ret + anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator+= (const long long& anthor){
		HugeInt ret = *this;
		ret = ret + anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator+= (const string& anthor){
		HugeInt ret = *this;
		ret = ret + anthor;
		this->val = ret.val;
		return *this;
	}

	HugeInt operator- (){
		assert(!this->val.empty());
		if(this->val[0] == '-'){
			reverse(this->val.begin(),this->val.end());
			this->val.pop_back();
			reverse(this->val.begin(),this->val.end());
		}
		else{
			reverse(this->val.begin(),this->val.end());
			this->val.push_back('-');
			reverse(this->val.begin(),this->val.end());
		}
		return *this;
	}
	HugeInt operator- (const HugeInt& anthor){
		HugeInt ret;
		int add = 0;
		string a = this->val;
		string b = anthor.val;

		assert(!a.empty() && !b.empty());
		if(a[0] =='-'){
			if(b[0] == '-') {//
				a.erase(0,1);
				if(b.size() > a.size()  || (b.size() == a.size()  && b>=a)){
					ret.val = string_sub(b,a);
				}
				else{
					ret.val = string_sub(a,b);
					reverse(ret.val.begin(),ret.val.end());
					ret.val.push_back('-');
					reverse(ret.val.begin(),ret.val.end());
				}
			}
			else {
				a.erase(0,1);
				b.erase(0,1);
				ret.val = string_add(a,b);
				reverse(ret.val.begin(),ret.val.end());
				ret.val.push_back('-');
				reverse(ret.val.begin(),ret.val.end());
			}
		}
		else{
			if(b[0] == '-'){
				ret.val = string_add(a,b);
			}
			else{
				swap(a,b);
				a.erase(0,1);
				if(b.size() > a.size()  || (b.size() == a.size()  && b>=a)){
					ret.val = string_sub(b,a);
				}
				else{
					ret.val = string_sub(a,b);
					reverse(ret.val.begin(),ret.val.end());
					ret.val.push_back('-');
					reverse(ret.val.begin(),ret.val.end());
				}
			}
		}
		return ret;
	}
	HugeInt operator- (const int& anthor){
		HugeInt ret;
		ret.val = int_to_string(anthor);
		ret = *this - ret;
		return ret;
	}
	HugeInt operator- (const long long& anthor){
		HugeInt ret;
		ret.val = long_long_to_string(anthor);
		ret = *this - ret;
		return ret;
	}
	HugeInt operator- (const string& anthor){
		HugeInt ret;
		ret.val = anthor;
		ret = *this - ret;
		return ret;
	}
	HugeInt &operator-= (const HugeInt& anthor){
		HugeInt ret = *this;
		ret = ret - anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator-= (const int& anthor){
		HugeInt ret = *this;
		ret = ret - anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator-= (const long long& anthor){
		HugeInt ret = *this;
		ret = ret - anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator-= (const string& anthor){
		HugeInt ret = *this;
		ret = ret - anthor;
		this->val = ret.val;
		return *this;
	}

	HugeInt operator* (const HugeInt& anthor){
		HugeInt ret;
		string a = this->val;
		string b = anthor.val;
		assert(!a.empty() && !b.empty());
		bool negtive = 0;
		if(a[0] == '-'){
			a.erase(0,1);
			negtive = !negtive;
		}
		if(b[0] == '-'){
			b.erase(0,1);
			negtive = !negtive;
		}
		ret.val = string_mul(a,b);
		if(negtive && ret.val != "0"){
			reverse(ret.val.begin(),ret.val.end());
			ret.val.push_back('-');
			reverse(ret.val.begin(),ret.val.end());
		}
		return ret;
	}
	HugeInt operator* (const int& anthor){
		HugeInt ret;
		ret.val = int_to_string(anthor);
		ret = *this * ret;
		return ret;
	}
	HugeInt operator* (const long long& anthor){
		HugeInt ret;
		ret.val = long_long_to_string(anthor);
		ret = *this * ret;
		return ret;
	}
	HugeInt operator* (const string& anthor){
		HugeInt ret;
		ret.val = anthor;
		ret = *this * ret;
		return ret;
	}
	HugeInt &operator*= (const HugeInt& anthor){
		HugeInt ret = *this;
		ret = ret * anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator*= (const int& anthor){
		HugeInt ret = *this;
		ret = ret * anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator*= (const long long& anthor){
		HugeInt ret = *this;
		ret = ret * anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator*= (const string& anthor){
		HugeInt ret = *this;
		ret = ret * anthor;
		this->val = ret.val;
		return *this;
	}

	HugeInt operator/ (const HugeInt& anthor){
		HugeInt ret;
		string a = this->val;
		string b = anthor.val;
		assert(b != "0");
		assert(!a.empty() && !b.empty());

		bool negtive = 0;
		if(a[0] == '-'){
			a.erase(0,1);
			negtive = !negtive;
		}
		if(b[0] == '-'){
			b.erase(0,1);
			negtive = !negtive;
		}
		ret.val = string_div(a,b);
		if(negtive && ret.val != "0"){
			reverse(ret.val.begin(),ret.val.end());
			ret.val.push_back('-');
			reverse(ret.val.begin(),ret.val.end());
		}
		return ret;
	}
	HugeInt operator/ (const int& anthor){
		HugeInt ret;
		ret.val = int_to_string(anthor);
		ret = *this / ret;
		return ret;
	}
	HugeInt operator/ (const long long& anthor){
		HugeInt ret;
		ret.val = long_long_to_string(anthor);
		ret = *this / ret;
		return ret;
	}
	HugeInt operator/ (const string& anthor){
		HugeInt ret;
		ret.val = anthor;
		ret = *this / ret;
		return ret;
	}
	HugeInt &operator/= (const HugeInt& anthor){
		HugeInt ret = *this;
		ret = ret / anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator/= (const int& anthor){
		HugeInt ret = *this;
		ret = ret / anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator/= (const long long& anthor){
		HugeInt ret = *this;
		ret = ret / anthor;
		this->val = ret.val;
		return *this;
	}
	HugeInt &operator/= (const string& anthor){
		HugeInt ret = *this;
		ret = ret / anthor;
		this->val = ret.val;
		return *this;
	}

	friend istream& operator>>(istream &in, HugeInt &one){
		string s;
		in >> s;
		one.val = s;
		return in;
	}
	friend ostream& operator<<(ostream &out, const HugeInt &one){
		string s = one.val;
		out << s;
        return out;
    }
};

int mp[212][212];
HugeInt dp[212][212];


signed main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i=1; i<=n; i++) {

	}
	return 0;
}
