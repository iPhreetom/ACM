#include<bits/stdc++.h>
using namespace std;


int main(){
	int test;
	cin>>test;
	for(int Case=1; Case<=test; Case++){
		cout<<"Case:"<<Case<<endl;

		int M_blue,M_red,M;
		int dragon,ninja,iceman,lion,wolf;
		int arr_blue_army[6];
		int arr_red_army[6];
		string name_blue_army[6];
		string name_red_army[6];
		string name_weapon[3];
		int cnt_blue_army[6];
		int cnt_red_army[6];
		memset(cnt_red_army,0,sizeof(cnt_red_army));
		memset(cnt_blue_army,0,sizeof(cnt_blue_army));

		cin>>M>>dragon>>ninja>>iceman>>lion>>wolf;

		M_red = M_blue = M;

		arr_blue_army[0] = lion;
		arr_blue_army[1] = dragon;
		arr_blue_army[2] = ninja;
		arr_blue_army[3] = iceman;
		arr_blue_army[4] = wolf;

		arr_red_army[0] = iceman;
		arr_red_army[1] = lion;
		arr_red_army[2] = wolf;
		arr_red_army[3] = ninja;
		arr_red_army[4] = dragon;

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


		bool blue_continue = 1,red_continue = 1;
		int count = 0;
		int index_blue = 0;
		int index_red = 0;
		while(blue_continue || red_continue){
			if(red_continue){
				int len = 0;
				while(1){
					if(M_red >= arr_red_army[index_red]){
						M_red -= arr_red_army[index_red];
						cnt_red_army[index_red]++;

						cout<<setw(3)<<setfill('0')<<count<<' ';
						cout<<"red "<<name_red_army[index_red]<<" "<<count+1
							<<" born with strength "<<arr_red_army[index_red]
							<<","<<cnt_red_army[index_red]
							<<" "<<name_red_army[index_red]<<" in red headquarter"<<endl;

							// dragon
							if(index_red == 4){
								cout<<fixed<<setprecision(2)
									<<"It has a "<<name_weapon[(count+1)%3]
									<<",and it's morale is "
									<<(double)M_red/(double)arr_red_army[index_red]<<endl;
							}

							// lion
							if(index_red == 1){
								cout<<"It's loyalty is "<<M_red<<endl;
							}

							// iceman
							if(index_red == 0){
								cout<<"It has a "<<name_weapon[(count+1)%3]<<endl;
							}

							// ninjia
							if(index_red == 3){
								cout<<"It has a "<<name_weapon[(count+1)%3]<<" and a "<<name_weapon[(count+2)%3]<<endl;
							}

						index_red++;
						index_red %= 5;
						break;
					}

					len++;
					index_red++;
					index_red %= 5;
					if(len == 5){
						red_continue = 0;
						cout<<setw(3)<<setfill('0')<<count<<' ';
						cout<<"red headquarter stops making warriors"<<endl;
						break;
					}
				}
			}
			if(blue_continue){
				int len = 0;
				while(1){
					if(M_blue >= arr_blue_army[index_blue]){
						M_blue -= arr_blue_army[index_blue];
						cnt_blue_army[index_blue]++;

						cout<<setw(3)<<setfill('0')<<count<<' ';
						cout<<"blue "<<name_blue_army[index_blue]<<" "<<count+1
							<<" born with strength "<<arr_blue_army[index_blue]
							<<","<<cnt_blue_army[index_blue]
							<<" "<<name_blue_army[index_blue]<<" in blue headquarter"<<endl;

						// dragon
						if(index_blue == 1){
							cout<<fixed<<setprecision(2)
								<<"It has a "<<name_weapon[(count+1)%3]
								<<",and it's morale is "
								<<(double)M_blue/(double)arr_blue_army[index_blue]<<endl;
						}

						// lion
						if(index_blue == 0){
							cout<<"It's loyalty is "<<M_blue<<endl;
						}

						// iceman
						if(index_blue == 3){
							cout<<"It has a "<<name_weapon[(count+1)%3]<<endl;
						}

						// ninjia
						if(index_blue == 2){
							cout<<"It has a "<<name_weapon[(count+1)%3]<<" and a "<<name_weapon[(count+2)%3]<<endl;
						}


						index_blue++;
						index_blue %= 5;
						break;
					}

					len++;
					index_blue++;
					index_blue %= 5;
					if(len == 5){
						blue_continue = 0;
						cout<<setw(3)<<setfill('0')<<count<<' ';
						cout<<"blue headquarter stops making warriors"<<endl;
						break;
					}
				}
			}
			count++;
		}
	}
	return 0;
}
