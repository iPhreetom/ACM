#include<bits/stdc++.h>
using namespace std;

string from_int_to_string(int a){
	string s;
	while(a){
		s.push_back(a%10+'0');
		a/=10;
	}
	return s;
}
int main(){
	#define int long long
	ifstream fin;
	ofstream fout;

	// 11 - 3
	fout.open("test1.txt");
	fout<<"已成功写入文件!"<<endl;
	fout.close();

	// 11 - 6
	class dog{
	public:
		int age;
		int weight;
		dog(){}
		dog(int age,int weight){
			this->age = age;
			this->weight = weight;
		}
	};
	dog dog1(10,5);
	dog dog2;

	fout.open("dog1.txt");
	fout<<dog1.age<<' '<<dog1.weight<<endl;
	fout.close();
	fin.open("dog1.txt");
	fin>>dog2.age>>dog2.weight;
	fin.close();

	fout.open("dog1.dat",ios::binary);
	fout<<dog1.age<<' '<<dog1.weight<<endl;
	fout.close();
	fin.open("dog1.dat",ios::binary);
	fin>>dog2.age>>dog2.weight;
	fin.close();


	// 11 - 8
	cout<<"Input a decimal number please: ";
	int num; cin>>num;
	int num_8 = num;
	int num_16 = num;
	string oct;
	oct.resize(87);
	fill(oct.begin(),oct.end(),'0');
	string hex;
	hex.resize(49);
	fill(hex.begin(),hex.end(),'0');

	while(num_8){
		for (int i=1; i<=86; i++){
			if(pow(8,i) > num_8){
				oct[i-1] = num_8/(int)pow(8,i-1) + '0';
				num_8 -= (int)(num_8/(int)pow(8,i-1))*(int)pow(8,i-1);
				break;
			}
		}
	}
	while(oct.back() == '0' && oct.size() != 1){
		oct.pop_back();
	}
	while(num_16){
		for (int i=1; i<=48; i++){
			if(pow(16,i) > num_16){
				hex[i-1] = num_16/(int)pow(16,i-1) + '0' <= '9' ? num_16/(int)pow(16,i-1) + '0' : num_16/(int)pow(16,i-1) + 'A' - 10;
				num_16 -= (int)(num_16/(int)pow(16,i-1))*pow(16,i-1);
				break;
			}
		}
	}
	while(hex.back() == '0' && hex.size() != 1){
		hex.pop_back();
	}
	reverse(hex.begin(),hex.end());
	reverse(oct.begin(),oct.end());
	cout<<"Octonary: "<<oct<<endl;
	cout<<"Decimal: "<<num<<endl;
	cout<<"Hexadecimal: "<<hex<<endl;

	// 11 - 9
	string name = "Maybe.txt";
	fin.open(name);
	string s;
	string txt;
	int cnt = 0;
	while(getline(fin,s)){
		reverse(s.begin(),s.end());
		s += " :";
		s += from_int_to_string(++cnt);
		reverse(s.begin(),s.end());
		s += '\n';
		txt += s;
	}
	fin.close();
	cout<<endl<<name<<endl<<txt;
	return 0;
}
