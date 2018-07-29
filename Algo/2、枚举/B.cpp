#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;


vector<int> arr;


string mul(string num1, string num2)
{
    string rs(num1.length()+num2.length(), '0');

    for (int i = num1.length()-1, d = rs.length()-1; i >= 0; i--, d--)
    {
	    int carry = 0, k = d;
	    for (int j = num2.length()-1; j >= 0; j--, k--)
	    {
		    int a = num1[i] - '0';
		    int b = num2[j] - '0';
		    a = a*b+carry + (rs[k]-'0');
		    carry = a/10;
		    rs[k] = a%10 + '0';
	    }
	    while (carry)
	    {
		    int sum = carry + (rs[k]-'0');
		    carry = sum / 10;
		    rs[k--] = sum % 10 + '0';
	    }
    }
    while (rs.size() > 1 && rs[0] == '0') rs.erase(rs.begin());
    return rs;
}

int n;
string lis;
string a[105][4];

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


	cin>>n;
	cin>>lis;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			cin>>a[i][j];
			string tp ;
			for(int k=0;k<a[i][j].size()-1;k++){
				tp.push_back(a[i][j][k]);
			}
			a[i][j] = tp;
			// cout<<tp<<endl;
		}
	}

	bool all = 1;
	string ans = "1";
	for(int i=0;i<n;i++){
		if(a[i][lis[i]-'A'] != "100")all = 0;
		if(a[i][lis[i]-'A'] == "0"){
			cout<<0<<endl;
			return 0;
		}

		ans = mul(ans,a[i][lis[i]-'A']);
	}

	int zero = n*2-ans.size();

	int len = ans.size();
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i] != '0'){
			len = i;
			break;
		}
	}

	if(all){
		cout<<1<<endl;
		return 0;
	}
	cout<<"0.";
	for(int i=0;i<zero;i++){
		cout<<'0';
	}
	for(int i=0;i<=len;i++){
		cout<<ans[i];
	}
	cout<<endl;


	return 0;
}
// ..``..............................  ...`':;:`````:::::''''``:;!||%%%%|!!!!!!!!%$&&$%%%$$&$|!!!!!;'''``............`::::::::;:'```''```':::'''::;;;::;|&&&$%||||!
// .`'''````..````.....................':''::'`';;'``''::::::'.`';!!|||%%|!!!!!!!|%&&&&&$%%%%$$$|;;::::''`````...```....`:::'`....``':;;:;;;:```````'':!!:'';|$&&$|
// .........````.`:'``'`.......... ......':::;;;::'``':;;!!|!!;`.`'''';|||!;;!!!!!|%&&$$$&&&%||||%%|!!;;::::;;;:'..          .'``...`'''''::::`....``''```'::::'';!
//               ...  .':::'`........  ..':;;;::''::'';!|%%%%||!;`.`''':!!!!;;;!!!|%$&@@&$%%$&&%|!!;!|!:'::::`.                 `'`':::''''::'`...........````'::;!
// :::'``'''```...       .`:;::::'`.....   `':'':;;;!!:!%%%$$%|;'`....`':;!!;::;;!||%$&&&&@&$%%%||:``'''::'.     .          ..   .''''':::`.........````''''`.```';
// .:;;;'`:;;;;;;;;;;:'`......:;;;;;;::```..   `:;!|%%%!!%$%|!:''```....``':;:'::;!!|%&@@&&$&&&|:;!;!!;;;:..  .`.      ..   `!%;. `''''''`........`:::''::'`....``:
//   .:;!;'`''':!!!!!!!!!!!;:`...':;!!;;:''`. .    '!%%%%!;;;:'`''::``::'`.``':''::;!|%&@@@@&$|!|!!;;!!;:'`..``.      .`     `!|!!|%%|:...........``''''''::'`....:
//     .';;:`.';!!!!!!;:'':;;!!!;'``:;:::;;;!!:.      .:;:'''':;%$$$!';`  `''`.`'::::;!|$&&%|%$%!;;;;;;:'```''...  .```.  .. `!%%%|!!%|'...``...`'::'''''''''`....'
//        .':;'.'!||!!!!;':::!|%%|!;:'':;!!||%%%%!`     .:%$$$$$$$$!``.  `;:'::'..``':;;|$$&&&$|!!;;!;:'```````....`'''`.`` .'!!!|%|!;`   .`.....```':::'`. ......:
// .         `;!;`.';!!!!;;!||||||!!!|||!!|%%%$$$$%%%$$$$$&&&&&$$$$%!;!||%|;:;!||!:...`':!||%|!|!:;;;;:'':%$;`....`````..```:'..'';|:.     ''``.....`'''..........'
// ...   `';;!!!!!!!!!!!!!!!|||||||||||||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%;::;|%%|!!;` ..`'';;'``'':''::`:%%:....`'::'```':`  `';!'..    .`::'````............. .:
// :.';!!!!!!!!!!!!!!!!||||||||||||||||||||%%%%%%%%%%%$$$$$%%%%%%%%%%%%%%$&%;'::;|||!!||!:. ..```..`'::'. `:`       ;%%$&%;:` `''|;`.  ...`:;!:`'''`````........`';
// ||;;!!!!!!!!!!!!||||||||||||||||||%%%%%%%%%%%%%%%%%%$$$$$$$$$%%%%%%$$$$%%;.    ..``'``...    ..```...           .:|%:''  :;:!;::  `''``';!;;;;:''''``````....`':
// %%%%|!!!!!!||||||||||||||||||%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$$%%%%%%%%$$|'... .`'':'''`......   ..``.                  ..`'!!;:'::'''':!|!;;;;;;!;:':'```.....'
// %%%%%%|!!|||||||||||||||||%%%%%%%%%%%%%%%%%%%%%%$$$$$$$$$$$$$$$$%%%%%%%$$%!'`.`````'::::'':::::'`.   .``'.            `':::;:':!!:```:!!;|||%%|!!|%|;;:'''`````:
// `...`';!||||||||||||||%%%%%%%%%%%%%%%%%%$$$$$$&&&&$$$$$$$$$$$$&&&&&$%%$$%%%!````.....`:!||!;'`. .````....`'`  .`'`  .`''';!;!;;!;::;|%%||||!!!|$$$$%!;;;;;:''``:
// %%|!!!;;!||||||||||||%%%%%%%%%%%%%$$$$$$$$$$&&&&&&@&%%$$$$$$&&&&&&&&$$$$%%%$||%%$%|%$&&&&&$&%' `';%||!!;:'. .''`::``. .'::''''';%$%|!!|%$$$|!;;;!%$$$$|!;;!!||;;
// :!!!;;;;!!||||||%%%%%%%%%%%%$$$$$$$$$$$$$$&&&&&&&@&$$$$$$$&&&&&&&&&&$$&&&$%%|!||%$$&&&&$$%%$;. ';`;%%%!;||;'':;;;:::;::`''` ..`:!%$$$%||%$%%%%|!|%%|!|%$$$%|%|;;
// !!;;;;;!!;!|%%%%%%%%%%$$$$$$$$$$$$$$$$$$$&&&&&&&@@$%%%$$$$$&&&&&&&&&&&&$$%|!;;:::':||%$$$!';!`..::'%&$%:    .`..':;;;:':;;:`.  ';!!!!|$&$$%!!!|$&&$|!;;!|%$$$%!!
// !!!!;;!!!;;!|%$$$$$$$$$$$$$$$$$$%|!:'`.       ..``;|%%%%%$&&$$&&$%%%%%%%%|!!|!:'''''':!|%$!'::....'|%%!`            .':;;:::::;;:::;;::;!%$$|!!!|$$&&$|!!!|%%%%|
// ||||||||||||%%%%$$$$$$$%|:`                    ..`;%$$$%%%$$$$$%%%%%%%%%%%%|||||!:'::::!$&&&;..`;%%%%%;.            .```. `:;;;::::;;;;;;;;;|$$$$$%||%$&&$%$%!!!
// !!!!!!!!!|||||%%%!'.                          ..'!|%%%%%$$&&$%%%$%%%%%%%%%%%%%|!!!!;:::%@&&&$!!%%%%%%%;`   .        `'''`   `` `;;;;:::::;'':;|%%$$%||||%$&&$|!!
// !!!!!!!!!!!|!:.                            .:|||%%%%%$$&&&@@$%%$%%%%%%%%%%$$$%%%%||%%!|&@@@&&$$$%%%%%%;`           .''''`..`;|'`;!!;::;;;;:!%$$%$$%$&&$%|%$$%$&%
// |||||!!!!||;`                                            .`;|%%$$$$&&$%%%%%%%%%%$%%$$%$@@@&$$$$%%%%%$$%%%!`.      `''`'''. `:!;'!$%||;;!|%%|%%$&@&%||%$&@&&$|||!
// ||||||||%%|'                                                .'!$&&&&&&%%$$$%%%$$$$$$$$&&$$$$$$$$$$%%$$$%%%%|:```.'::'`'':` .:!|::|$&&$||$&&&@&&&&&&&%|%%$&&@&$%|
// ||||||||||;.                                                  .`';|$@&$%%$$$$$%|!!%$$$$$$$$$$$$$$%%$$&&$%%%$%;  .:::'``':`  :!||;:|%%$$%$&&&&&@@@&$$$|%&&&&$$$&%
// |||||||%%|;.                                                   ..```''!%%%$&&$$%:.`!$&&$$$$$$$$$%$%$$$&&&&&$$$!`  `'```'::` '|%%|!!|||||%&@@&&&@@@@@&%|%&@@&$$%|
// |||||||||||:.      .......                                       .```:!%%$$$$$%$%;'|&&&&$$$$$$$$$$$$$%$$%%%%%%%!'`''````';: .!%$$$||||||||$&@@@&&&@@@@$%$&&&@@@%
// |||||%%%|||%|'......``''''.                                       .``;%$$$$&&$%%$||%&&&&$$$$$$$$$$$$$%$&&&$$$$%%!'''````'!|' ;&$$$$$%%|!!|||%$&@@@&&&&&$%$&&&&&%
// ||||!;;!|%%%%%$!'`````````.     ..........                        ..'!$$$$$&&&&$&$$$&&&&&$$$$$$$$$&&$$$$&&$$%|%%:'''````'!%!`'%&@@&&$$$|!!|||||%$&@@@&&$%|$@@@@%
// ||||||:...'!||%$&&!`....`!|'...........```........                .`;%$$$%$$$$&&&&&$&&&&&&&$$$$$$$&&&$$$&&&%!%$!'::``````!$%:`!$&&@@&$$%||%||||||%%$&@@@$|%&&@@$
// $||||%%%%;`...`:|$&$%!;|$$&$;......        ..``.........          .:|$%%%$%;':|&&&$$&&&&&&&&$$$$$$$&&&&$&@@%%%!::;'```..`:|$|':%$&&&&&&%!|$$$$%%|%%%%%$&&$|%$&&%
// %%||||%%%$$|;'``.````:!||!|$&$;.....         ..`'``...............`!$$$&&|:'':%&&$$&&&&&&&&&&&&$$$$&&&&&&&&$%|::;:'``````:!||:'|$$$&&&&&||&$&&&$$%%%%%%%%$%|&@&%
// .'||!|||%%$$|:;;;::''''''':::!$&!`......      .:%%!'```````.......`!%%%%$&%!!$@@&$$&@&&&&&&&&&@@@&&&&&&%!!|%|;:!!'``````':!!|;`:%&&&$$&&&||&@&&&&&&$%%%%%%%%$&@$
// '`..`:!||%%$$%|!!!!|%%|;:;;;;!!!%&|'......   .'|%$&@@@&%;`````````'!%%%%%$&@@@@&$$$&@@@@@@@@@@@@@@&|::::::::::;:'``````'':!|!;``;!%$@&$$$$!!$&@@&&&&&&$%%%%$$$$%
// ''''```.`;|%%$|;:;;;!%$&$%%%%||!!|%$%:......`!%%%$$&@@@@@@@@@@@&$%%$$%$$&&@@@@@$$$&&&&&&&&&@@@@@@@$!:::::::':;;'``````''';;!!;' '!|||%&@&$%!;%&&@@@&&&&&$$$$$$$|
// `''''':'`````:!|;;!;;!%$$$%%%%%$%$$$$$%:`'!||%%%%%$&@@@@@@@@@@@@@@@@&&&&&@@@@@&$$$&&&&&&&&&&&@@@@@$!::;;!!::;;;:`````':'':;;;;'..:!!|||%&@&$!;%$&&&@@@&&&&&$$$$|
// .`''````````'':::::;;;;|$$$%|%;..'!;```:!%%%|;!%%%$$$@@@@@@@@@@@@@@@&&&@@@@@@&$$$$&&&&&&&&&&&@@@@&$!:;!!!;;!||;'````''''::;;;;:. `;!!!|%%$$$&!:|%$$&&&@@@&&&&&$|
//   ';:'`````````````''''''':!|||!'.;%!:;;'':::|%%%%%$$&&@@@@@&&&&@@@&&@@@@@@@&$$$$$&&&&&&&&&&&@&&&&$!::;;;;|%%|:`````''''::;;:::. .';!||!|%%|!|:;%%%$$&&&&@@&&&&%
// `  `::;!:''```````````````'``:|%%;:|%!'''''''!%|!;|%$$&&%%$@@@@@@@@@@@@@@@&&$$$$$$&&&&&&&&&&&&&&&$$|;;;:;!||!:'```'''''':::::::`  `;;;!!!!!!!!;';%$%%%$$$&&&@@&%
// `.   `'';|!;;::'''''''''`'::```'!%%|;::;;!!;;;!:`:|$$$$&&$|!%&&&&&@@&&&&&&&$$$$$$$&&&&&&&&$&&&&&&$$|!||||%%|;:''''`':;'''::::::`  .::;;;::::::;:':!|%%%%%%$$&&&%
// '..   .:'`'':;!!!!!;:''::::::'';||;;;;;;;;;;;;;;!|%|!%$$$$&$%||$&&&&&&&&&&&&&$$$$&&&&&&&$$$&&&&&$$$$$$$$&$$|:''''`'':;;:''':::'`  .'::::''''''''`':::!|%|||%%$$%
// ;'..   ..'':!;;:'':;!|!::;;;:'`'':::::::::::::;;:::';%$$$$$||&&!'!$$&&&&&&&&$$$$$&&&&&$$%$$$$$$$$$$|;'!$$$%!::'''':!;;;;:``''''`   `''''''```````.`''::;!!|||%%|
// '::'.......``';!!!!!|!;;:'':::;!!|!!!!!!!!!;;;::;;::!%%|!:'!$$|'`';!$&&&&&$$$$$$$&&&$$%%%$$$$$$$$$$%%||!!!!;:'''':;;!|||;'`''''.   .```````.........````'':!|%%|
// ..``'`.......```:!!!|||||;:!!!!||%%%|!|||%%%%$$$$%;::::``:|$%;``';;|$$$&$$$$$$$$$$$$$%%%%$$$$$$$$$$$%|;::;;::''':!;;|%$%|:''''`.   .````......   ..  ...``'':!%|
