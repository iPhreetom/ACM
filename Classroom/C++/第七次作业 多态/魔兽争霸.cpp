#include<bits/stdc++.h>
using namespace std;


class hero {
protected:
	int color = 0;
	int number = 0;
	int position = 0;
	int hp = 0;
	int ad = 0;
	string name = "";
	int weapon[3];
public:
	hero(){}
	hero(int number, int position, int hp, int ad){
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
	}
	~hero(){}
	void forward() {

	}
	int attack() {

	}
	int counterattact() {

	}
	void bigboom() {

	}
};

class city {
protected:
	int flag_color = 0;
	int life = 0;
	int create_number = 0;
	int continue_kill = 0;
	int city_number = 0;
public:
	friend class hero;
	queue <hero> que;
	void init(int number);
	void create_hero();
};

int m, n, r, k, t, hour;
int dragon_hp,ninja_hp,iceman_hp,lion_hp,wolf_hp; //  每个武士的生命值
int dragon_ad,ninja_ad,iceman_ad,lion_ad,wolf_ad; //  每个武士的攻击力
int hp_blue_army[6]; // 按顺序制造武士的花费
int hp_red_army[6]; // 按顺序制造武士的花费
int ad_blue_army[6]; // 按顺序制造武士的攻击力
int ad_red_army[6]; // 按顺序制造武士的攻击力
string name_blue_army[6]; // 按顺序武士的名字
string name_red_army[6]; // 按顺序武士的名字
string name_weapon[3]; // 按顺序武器的名字
int cnt_blue_army[6]; // 按顺序武士的数量
int cnt_red_army[6]; // 按顺序武士的数量
int index_blue = 0; // 顺序指针
int index_red = 0; // 顺序指针
int count_blue = 0; // 制造武士的数量
int count_red = 0; // 制造武士的数量
vector<city> v; // 城市的编号

void city::init(int number) {
	city_number = number;
	if (number == n || number == 0){
		life = m;
	}
}

void city::create_hero() {
	if (city_number == 0) {
		if (hp_red_army[index_red] <= life) {
			hero one(count_red, 0, hp_red_army[index_red], ad_red_army[index_red]);
			life -= hp_red_army[index_red];

			cout<<setw(3)<<setfill('0')<<hour<<":00"
				<<" red "<<name_red_army[index_red]<<" "<<count_red+1<<" born"<<endl;

			// dragon
			if(index_red == 4){
				one.
				cout<<fixed<<setprecision(2)
					<<"It has a "<<name_weapon[(count_red+1)%3]
					<<",and it's morale is "
					<<(double)life/(double)hp_red_army[index_red]<<endl;
			}
			// lion
			if(index_red == 1){
				cout<<"It's loyalty is "<<life<<endl;
			}
			// iceman
			if(index_red == 0){
				cout<<"It has a "<<name_weapon[(count_red+1)%3]<<endl;
			}
			// ninjia
			if(index_red == 3){
				cout<<"It has a "<<name_weapon[(count_red+1)%3]<<" and a "<<name_weapon[(count_red+2)%3]<<endl;
			}

			index_red++;
		}
		index_red %=5;
	}
	if (city_number == n+1) {

	}
}

void create_hero() {
	v[0].create_hero();
	v[n+1].create_hero();
}

void War(){
	// red one go first
	for (hour=0; hour<=t; hour++) {
		create_hero();
		// lion_skip();
		// hero_forward();
		// hero_with_arrow();
		// hero_with_bomb();
		// hero_fight();
		// hero_refight();
		// hero_die();
		// hero_cheer();
		// flag_raise();
		// if (city_taken()) break;
		// city_report();
		// hero_report();
	}
}

void init() {
	cin >> m >> n >> r >> k >> t;
	v.resize(n+2);

	for (int i=0; i<=n+1; i++){
		v[i].init(i);
	}

	memset(cnt_red_army,0,sizeof(cnt_red_army));
	memset(cnt_blue_army,0,sizeof(cnt_blue_army));

	hp_blue_army[0] = lion_hp;
	hp_blue_army[1] = dragon_hp;
	hp_blue_army[2] = ninja_hp;
	hp_blue_army[3] = iceman_hp;
	hp_blue_army[4] = wolf_hp;

	hp_red_army[0] = iceman_hp;
	hp_red_army[1] = lion_hp;
	hp_red_army[2] = wolf_hp;
	hp_red_army[3] = ninja_hp;
	hp_red_army[4] = dragon_hp;

	ad_blue_army[0] = lion_ad;
	ad_blue_army[1] = dragon_ad;
	ad_blue_army[2] = ninja_ad;
	ad_blue_army[3] = iceman_ad;
	ad_blue_army[4] = wolf_ad;

	ad_red_army[0] = iceman_ad;
	ad_red_army[1] = lion_ad;
	ad_red_army[2] = wolf_ad;
	ad_red_army[3] = ninja_ad;
	ad_red_army[4] = dragon_ad;

	name_blue_army[0] = "lion";
	name_blue_army[1] = "dragon";
	name_blue_army[2] = "ninja";
	name_blue_army[3] = "iceman";
	name_blue_army[4] = "wolf";

	name_red_army[0] = "iceman";
	name_red_army[1] = "lion";
	name_red_army[2] = "wolf";
	name_red_army[3] = "ninja";
	name_red_army[4] = "dragon";

	name_weapon[0] = "sword";
	name_weapon[1] = "bomb";
	name_weapon[2] = "arrow";
}

int main() {
	int case_number;
	cin>>case_number;
	for (int i=1; i<=case_number; i++){
		cout<<"Case "<<case_number<<":\n";
		init();
		War();
	}
	return 0;
}
