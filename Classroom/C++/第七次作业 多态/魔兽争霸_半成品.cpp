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
	int kind = -1;

	// 武器
	bool bomb = 0;
	int arrow = 0;
	int sword = 0;

	// 武士特有
	double dragon_morale = 0;
	int loyalty = 0;
public:
	hero(){}
	hero(string name, int number, int position, int hp, int ad, int kind){
		this->name = name;
		this->number = number;
		this->position = position;
		this->hp = hp;
		this->ad = ad;
		this->kind = kind;
	}
	~hero(){}

	// get
	string get_name() {
		return name;
	}
	int get_loyalty() {
		return loyalty;
	}
	int get_position() {
		return position;
	}
	double get_dragon_morale() {
		return dragon_morale;
	}
	int get_hp() {
		return hp;
	}
	int get_ad() {
		return ad;
	}
	int get_number() {
		return number;
	}
	int get_damage() {
		return ad + sword;
	}

	// set
	void set_morale(double add) {
		dragon_morale += add;
	}
	void set_loyalty(int add) {

	}
	void set_weapon(int num) {
		if(num == 0) {
			sword = ad/5;
		}
		if(num == 1) {
			bomb = 1;
		}
		if(num == 2) {
			sword = 3;
		}
	}

	// add
	void add_position(int num) {
		position += num;
	}
	void add_hp(int num) {
		hp += num;
	}

	// change
	void change_iceman() {
		if(hp <= 9) hp = 1;
		else hp -= 9;
		ad += 20;
	}

	// using
	bool using_arrow() {
		if(arrow > 0) {
			arrow --;
			return 1;
		}
		return 0;
	}
	bool using_bomb(int damage) {
		if(bomb == 1 && damage >= hp) {
			bomb = 0;
			return 1;
		}
		return 0;
	}

	int attack() {

	}
	int counterattact() {

	}
	void bigbomb() {

	}
};

class city {
protected:
	int flag_color = 0;
	int life = 0;
	int continue_kill = 0;
	int city_number = 0;
public:
	friend class hero;

	int get_city_number() {
		return city_number;
	}
	int get_flag_color() {
		return flag_color;
	}
	int get_continue_kill() {
		return continue_kill;
	}
	int get_life() {
		return life;
	}

	queue <hero> red_que;
	queue <hero> blue_que;
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
int win_number_blue = 0; // 蓝色司令部敌人数量
int win_number_red = 0; // 红色司令部敌人数量
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
			hero one(name_red_army[index_red], count_red, 0, hp_red_army[index_red], ad_red_army[index_red],index_red);
			life -= hp_red_army[index_red];
			cout<<setw(3)<<setfill('0')<<hour<<":00"
				<<" red "<<name_red_army[index_red]<<" "<<count_red+1<<" born"<<endl;

			// dragon
			if(index_red == 4){
				// one
				one.set_morale((double)life/(double)hp_red_army[index_red]);
				one.set_weapon((count_red+1)%3);
				cout<<fixed<<setprecision(2)
					<<"It has a "<<name_weapon[(count_red+1)%3]
					<<",and it's morale is "
					<<(double)life/(double)hp_red_army[index_red]<<endl;
			}
			// lion
			if(index_red == 1){
				cout<<"It's loyalty is "<<life<<endl;
				one.set_loyalty(life);
			}
			// iceman
			if(index_red == 0){
				one.set_weapon((count_red+1)%3);
				cout<<"It has a "<<name_weapon[(count_red+1)%3]<<endl;
			}
			// ninjia
			if(index_red == 3){
				one.set_weapon((count_red+1)%3);
				one.set_weapon((count_red+2)%3);
				cout<<"It has a "<<name_weapon[(count_red+1)%3]<<" and a "<<name_weapon[(count_red+2)%3]<<endl;
			}

			red_que.push(one);
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
void lion_skip() {
	for (int i=0; i<=n+1; i++) {
		if(!v[i].red_que.empty()
			&& v[i].red_que.back().get_name() == "lion"
			&& v[i].red_que.back().get_loyalty() <= 0) {
			hero &one = v[i].red_que.back();
			cout<<setw(3)<<setfill('0')<<hour<<":05"
				<<" red "<<one.get_name()<<" "
				<<one.get_number()<<" ran away"<<endl;
			v[i].red_que.pop();
		}
	}
}
void hero_forward() {
	for (int i=0; i<=n+1; i++) {
		if(!v[i].red_que.empty()) {
			hero &one = v[i].red_que.back();

			if(one.get_name() == "iceman") {
				one.change_iceman();
			}
			cout<<setw(3)<<setfill('0')<<hour<<":10"
				<<" red "<<one.get_name()<<" "
				<<one.get_number()<<" marched to city "
				<<one.get_position()+1<<" with "
				<<one.get_hp()<<" elements and force "
				<<one.get_ad()<<endl;

			if(one.get_position() == n) win_number_red ++; //
			else v[i+1].red_que.push(one);
			v[i].red_que.pop();
		}
	}
}
void hero_with_arrow() {
	for (int i=0; i<=n+1; i++) {
		if(!v[i].red_que.empty()
			&& !v[i+1].blue_que.empty()
			&& i != n) { // change_point

			hero &one = v[i].red_que.back();
			hero &anthor = v[i+1].blue_que.back();

			if(one.using_arrow()) {
				anthor.add_hp(-r);
			}

			if(anthor.get_hp() <= 0) {
				cout<<setw(3)<<setfill('0')<<hour<<":35"
					<<" red "<<one.get_name()<<" "
					<<one.get_number()<<" shot and killed "
					<<"blue "<<anthor.get_name()<<" "
					<<anthor.get_number()<<endl;
			}
		}
	}
}
void hero_with_bomb() {
	for (int i=0; i<=n+1; i++) {
		if(!v[i].red_que.empty() && !v[i].blue_que.empty()) { // change_point

			hero &one = v[i].red_que.back();
			hero &anthor = v[i+1].blue_que.back();

			if(v[i].get_flag_color() == 0) {
				if(i % 2 == 1) {
					if(one.using_bomb(anthor.get_damage())) {
						one.add_hp(-one.get_hp());
						anthor.add_hp(-anthor.get_hp());
					}

					if(anthor.get_hp() <= 0) {
						cout<<setw(3)<<setfill('0')<<hour<<":35"
							<<" red "<<one.get_name()<<" "
							<<one.get_number()<<" used a bomb and killed "
							<<"blue "<<anthor.get_name()<<" "
							<<anthor.get_number()<<endl;
					}
				}
				else {

				}
			}
			if(v[i].get_flag_color() == 1) {
				// red

			}
			if(v[i].get_flag_color() == 2) {
				// blue
			}
		}
	}
}

void War(){
	// red one go first
	for (hour=0; hour<=t; hour++) {
		create_hero();
		lion_skip();
		hero_forward();
		hero_with_arrow();
		hero_with_bomb();
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
