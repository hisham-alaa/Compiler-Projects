#include<iostream>
#include<regex>

using namespace std;
int main()
{
	string s;
	string rejected="(for|int|double|float|if)";
	string id = "[1-9][0-9]*";
	string color = "(red|green|blue|purple|black|brown|yellow|white)";
	
	
	while (true)
	{
		cin >> s;
		//regex e("abc", regex_constants::icase);
		//regex e("abc?", regex_constants::icase);
		//regex e("abc*", regex_constants::icase);
		//regex e("(a|b)c+", regex_constants::icase);
		regex e(id, regex_constants::icase);

		//regex e("(\\b(?!"+rejected+"\\b))[a-z A-Z _]([a-z A-Z _ 0-9])*");
		cout << ( regex_match(s, e)? "Matched" : "Not Matched") << endl;
	}
	return 0;
}