#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

ifstream table("table.txt"), in("input.txt");
ofstream out("output.txt");
int states = 0;
string symbols, tmp;
unordered_map<string, unordered_map<char, string>>transition;
unordered_map<char, string > temp;

void buildtable() {

	while ((table >> tmp) && tmp != "$") symbols += tmp[0];

	while (true) {
		for (int j = 0; j < symbols.length(); j++) {
			table >> tmp;
			if (tmp == "$")return;
			temp[symbols[j]]= tmp;
		}
		transition.emplace("q" + to_string(states), temp);
		states++;
	}

}

int main() {

	buildtable();


	
	table.close();in.close();out.close();
	return 0;
}



//to print the table and check its truth
/*
	for (int j = 0; j < symbols.length(); j++)
			cout << "    " << symbols[j];
	for (auto i : transition) {
		cout << endl << i.first << "  ";
		for (auto j : i.second)
			cout << j.second << "   ";
	}
		cout <<endl<< transition.at("q3").at('+')<<endl;
		cout << transition["q2"]['/'] << endl;

*/





//another implementation with vectors to build table

/*
#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<vector>

using namespace std;

ifstream table("table.txt"), in("input.txt");
ofstream out("output.txt");
int states = 0, curstate = 0;
string symbols,tmp;
vector<map<char, int>>transition;
map<char, int > temp;

void buildtable() {

	while((table >> tmp)&& tmp!="$") symbols += tmp[0];

	while(true){
		for (int j = 0; j < symbols.length(); j++) {
			table >> tmp;
			if (tmp == "$")return;
			temp.emplace(symbols[j],stoi(tmp));	
		}
		
		transition.push_back(temp);
		states++;
		temp.clear();
	}

}

int main() {

	buildtable();

	in.close();
	out.close();
	table.close();
	return 0;
}
*/
