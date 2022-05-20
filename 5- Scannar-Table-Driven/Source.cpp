#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

ifstream table("table.txt"), in("input.txt"),categories("categories.txt");
ofstream out("output.txt");

int states = 0;
char ch;

string symbols, tmp,curstate,finals,token;

unordered_map<string, unordered_map<char, string>>transition;
unordered_map<char, string > temp;
unordered_map<string, string> finalstates;

void buildTable() 
{
	states = 0;
	symbols = "";
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

void buildcategories() 
{
	while (categories >> curstate && categories >> tmp)
		finalstates.emplace(curstate, tmp);
}

int main() {

	buildTable();
	
	buildcategories();

	while (!in.eof()) 
	{
		finals = "no";
		curstate = "q0";
		tmp = "";
		
		ch = in.get();

		while (!in.eof())
		{
			if (symbols.find(ch) == -1)
			{ 
				if (finals == "no")
					out << "token error "<<ch << endl;
				else
				{
					out << "token " + token << " " << tmp << endl;
					out << "token error " << ch << endl;
				}
				break;
			}

			curstate = transition[curstate][ch];

			if (finalstates.find(curstate) != finalstates.end()) 
			{ 
				finals = curstate;
				token = finalstates.find(curstate)->second;
			}

			if (curstate == "qf")
			{
				finals = "no";
				out << "token "+ token << " " << tmp << endl;
				curstate = "q0";
				tmp = "";
				token = "";
				continue;
			}
			
			tmp += ch;
			ch = in.get();	
		}
	}
	if (finals != "no")
		out << "token " + finalstates.find(finals)->second << " " << tmp << endl;

	table.close(); in.close(); out.close(); categories.close();
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
