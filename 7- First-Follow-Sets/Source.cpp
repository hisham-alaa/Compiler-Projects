#include<iostream>
#include<string>
#include<fstream>
#include<set>
#include<vector>
#include<map>
using namespace std;

ifstream in("Grammar.txt");
set<string> nonterminals ,tmpset;
vector<string> tmpvector;
map<string, vector<vector<string>>> productions;
vector<vector<string>> tmpvector2 ;
map<string , vector<vector<string>>>::iterator itr;

map<string, set<string>>allfirst,allfollow ;
string nonterminal,tmp,start;

void getproductions() 
{
	while (!in.eof()) 
	{

		in >> nonterminal; //terminal

		if (productions.empty()) {
			start = nonterminal;
			tmpset.insert("$");
			allfollow.emplace(nonterminal, tmpset);
		}
		in >> tmp;		//equal	
		in >> tmp;		//first non or terminal
		while (tmp != "$")
		{
			tmpvector.push_back(tmp);
			in >> tmp;
		}

		if (productions.find(nonterminal) != productions.end())
		{
			itr = productions.find(nonterminal);
			tmpvector2 = itr->second;
			tmpvector2.push_back(tmpvector);
			itr->second = tmpvector2;
		}
		
		else
		{
			tmpvector2.push_back(tmpvector);
			productions.emplace(nonterminal, tmpvector2);
		}

		nonterminals.insert(nonterminal);
		tmpvector.clear();
		tmpvector2.clear();
		nonterminal = "";
		tmp = "";
	}
	
	for (auto i : productions)
	{
		for (auto j : i.second)
			for (auto k : j)
				if (productions.find(k) == productions.end()
					&& allfirst.find(k) == allfirst.end())
				{
					tmpset.insert(k);
					allfirst.emplace(k, tmpset);
					tmpset.clear();
				}
	}
}

set<string>first(string s)
{
	set<string> res;
	if (allfirst.find(s) != allfirst.end())
		return allfirst.at(s);

	int i = 0;
	for (auto j : productions.at(s))
	{
		for (auto k : j)
		{
			i++;
			tmpset = first(k);
			res.insert(tmpset.begin(), tmpset.end());
			
			if ((tmpset.find("e") == tmpset.end())
				||(tmpset.find("e") != tmpset.end() && i == j.size())
				||(nonterminals.find(k)==nonterminals.end()))
				break;

			res.erase("e");
			tmpset.clear();
		}
	}
	
	tmpset.clear();
	allfirst.emplace(s, res);
	return res;
}

set<string>follow(string s)
{
	set<string>res;
	bool found=false;
	int count = 0;
	if (allfollow.find(s)!=allfollow.end())
		return allfollow.at(s);
	
	
	for (auto i : productions)
		for (auto j : i.second)
		{
			found = false;
			count = 0;
			for (auto k : j)
			{
				count++;
				if (k == s) 
				{
					found = true;
					if (i.first == start && count == j.size())
					{
						tmpset = follow(i.first);
						tmpset = follow(i.first);
						res.insert(tmpset.begin(), tmpset.end());
						res.erase("e");
						tmpset.clear();
					}
				}
				if (found && k != s)
				{
					tmpset = first(k);
					if (tmpset.find("e") == tmpset.end())
						break;
					res.insert(tmpset.begin(), tmpset.end());
					res.erase("e");
					tmpset.clear();
					if (count == j.size())
					{
						tmpset = follow(i.first);
						res.insert(tmpset.begin(), tmpset.end());
						res.erase("e");
						tmpset.clear();
					}
				}
			}
		}

	tmpset.clear();
	allfollow.emplace(s, res);
	return res;

}

int main()
{
	getproductions();

	string n;
	cin >> n;
	tmpset = follow(n);
	cout << n;
	for (auto i : tmpset)
		cout << " -> " << i << endl;
	cout << endl;
	
	/*for (auto i : allfirst)
	{
		cout << i.first ;
		for (auto j : i.second)
			cout << " -> " << j << endl;
		cout << endl;
	}
		*/	
	/*for (auto i : productions)
		for(auto j:i.second)
			cout << i.first <<" = " << j << endl;
	*/


	nonterminals.clear();tmpset.clear();tmpvector.clear();
	tmpvector2.clear();productions.clear();allfirst.clear();
	allfollow.clear();
	in.close();
	return 0;
}