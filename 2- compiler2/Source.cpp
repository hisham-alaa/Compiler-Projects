#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {

	ifstream i("in.txt");
	ofstream o("out.txt");
	int curchar = 0,x=0;
	string s,all="", vari = " ", vtype = " ";
	bool fortaken = false, assign = true, vardeclared = false, open = false, fsemi = false, ssemi = false;

	getline(i, all, '\0');

	while (curchar < all.length())
	{
	up:
		if ((int)all[curchar] == 32|| all[curchar]=='\n' || all[curchar] == '\t') { curchar++; continue; }

		if (isalpha(all[curchar]) || isdigit(all[curchar]) || all[curchar] == '_')
		{
			s = "";
			while ((isalpha(all[curchar]) || isdigit(all[curchar]) || all[curchar] == '_') && curchar < all.length())
			{
				s += all[curchar];
				curchar++;
			}

			if (s == "for" && !fortaken && !open)
			{
				o << "for_iteration" << endl;
				fortaken = true;
				goto up;
			}

			else if ((s == "int" || s == "double" || s == "float" || s == "bool") && vtype == " " && !fsemi)
			{
				vtype = s;
				o << "Data_type ," << vtype << endl;
				goto up;
			}
			else if ((isalpha(s[0]) || s[0] == '_'))
			{
				x = 1;
				if (fsemi && s != vari)
					goto er;

				vari = s;
				o << "identifier ," << vari << endl;
				goto up;
			}
			else if (isdigit(s[0]))
			{
				assign = true;
				o << "value ," << s << endl;
				goto up;
			}
			else
				goto er;
		}

		else if (all[curchar] == '(' && !open && fortaken) {
			o << "open_paranthesis" << endl;
			open = true;
		}

		else if (all[curchar] == '=' && all[curchar + 1] != '=' && vari != " ") {
			assign = false;
			o << "assignment_operator" << endl;
		}

		else if (all[curchar] == '>' && fsemi && !ssemi && x == 1)
			o << "GT_operator" << endl;

		else if (all[curchar] == '<' && fsemi && !ssemi && x == 1)
			o << "LT_operator" << endl;

		else if (all[curchar] == '{' && fsemi && ssemi && x == 1)
		{
			o << "open_curly_parenthesis" << endl;
			open = false;
			fortaken = false;
			fsemi = false;
			ssemi = false;
			vari = " ";
			vtype = " ";
			vardeclared = false;
		}

		else if (all[curchar] == '}')
			o << "close_curly_parenthesis" << endl;

		else if (all[curchar] == '=' && all[curchar + 1] == '=' && fsemi && x == 1)
		{
			o << "equality_operator" << endl;
			curchar++;
		}

		else if (all[curchar] == '+' && fsemi && x == 1)
		{
			o << "increment_operator +" << endl;
			curchar++;
			goto up;
		}

		else if (all[curchar] == '!' && all[curchar+1] == '=' &&fsemi && !ssemi && x == 1)
			o << "notEqual_operator" << endl;

		else if (all[curchar] == ';' && vari != " " && assign && open) {
			if (!fsemi)
			{
				fsemi = true;
				o << "semi_colon" << endl;
			}
			else if (!ssemi){
				ssemi = true;
				o << "semi_colon" << endl;
			}
			
			else
				goto er;
		}

		else if (all[curchar] == ')'){
			o << "close_paranthesis" << endl;
			open = false;
		}

		else {
			er: 
			cout << endl << "non-valid input" << endl;
			return 0;
		}
		
		curchar++;
	}

	cout << endl;
	return 0;
}