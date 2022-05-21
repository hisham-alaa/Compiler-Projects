#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
using namespace std;


enum Token {
	OPEN_BRANTHESES, CLOSE_BARANTHESES, COMMA, ID, COLOR, END_OF_FILE, ERROR
};

string s;
ifstream input("in.txt");
Token current_token;
ofstream output("out.txt");
Token Scanner()
{
	char c;
	s = "";
	input.get(c);
	while (c == ' ')input.get(c);
	if (input.eof()) { s = "$"; return END_OF_FILE; }
	else if (c == '(') { s = c; return OPEN_BRANTHESES; }
	else if (c == ')') { s = c; return CLOSE_BARANTHESES; }
	else if (c == ',') { s = c; return COMMA; }
	else if (isalpha(c))
	{
		s += c;
		input.get(c);
		while (isalpha(c) && !input.eof())
		{
			s += c;
			input.get(c);
		}
		input.putback(c);
		if (s == "red" || s == "green" || s == "blue" || s == "yellow" || s == "white")return COLOR;
	}
	else if (isdigit(c))
	{
		s += c;
		input.get(c);
		while (isdigit(c) && !input.eof())
		{
			s += c;
			input.get(c);
		}
		input.putback(c);
		return ID;
	}
	
	return ERROR;
}

string token_name(Token t)
{
	if (t == OPEN_BRANTHESES) return "< OPEN_BRANTHESES";
	else if (t == CLOSE_BARANTHESES) return "< CLOSE_BARANTHESES";
	else if (t == COMMA) return "< COMMA";
	else if (t == ID) return "< ID";
	else if (t == COLOR) return "< COLOR";
	else if (t == END_OF_FILE) return "< END_OF_FILE";
}

void match(Token t)
{
	if (t == current_token)
	{
		output << token_name(t) << " , " << s << " > is expected\n";
	}
	else
	{
		output << "ERROR" << " , " << s << "  is NOT expected\n";
		return;
	}
	current_token = Scanner();
}

/*
S      = (ID,SECOND) SS
SS     = ,S | e
ID     = NUMBER IID
IID    = ID  | e
NUMBER = 0|1|2|3|4|5|6|7|8|9
SECOND = ID   | COLOR
COLOR  = red | green | blue | yellow | white
*/

void number();
void iid();
void s1();
void ss();
void id1();
void color();
void second();
void start()
{
	current_token == Scanner();
	s1();
	match(END_OF_FILE);
}
void main()
{
	start();
	system("pause");
}

void s1()
{
	match(OPEN_BRANTHESES);
	id1();
	match(COMMA);
	second();
	match(CLOSE_BARANTHESES);
	ss();
}

void ss()
{
	if (current_token == COMMA)
	{
		match(COMMA);
		s1();
	}
}
void id1()
{
	number(); iid();
}
void iid()
{
	if (current_token == ID)
		id1();
}
void number()
{
	match(ID);
}
void color()
{
	match(COLOR);
}
void second()
{
	if (current_token == ID)
		id1();
	else if (current_token == COLOR)
		color();
	else
	{
		output << "ERROR" << " , " << s << "  is NOT expected\n";
		return;
	}

}





/*#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

ifstream in("in.txt");
string tmp, curstate;
unordered_map<string, string> finalstates;

int main(){	

	char ch;
	while (!in.eof())
	{
		ch = in.get();
		ch = (isalpha(ch) ? 'l' : ch);
		ch = (isdigit(ch) ? 'd' : ch);
		cout << ch << endl;
	}

	return 0;
}
*/


//#include <conio.h>
//#include <iostream>
//using namespace std;
//
//#define KEY_UP    72
//#define KEY_LEFT  75
//#define KEY_RIGHT 77
//#define KEY_DOWN  80
//
//int main()
//{
//    int c, ex;
//
//    while (1)
//    {
//        c = _getch();
//
//        if (c && c != 224)
//        {
//            cout << endl << "Not arrow: " << (char)c << endl;
//        }
//        else
//        {
//            switch (ex = _getch())
//            {
//            case KEY_UP     /* H */:
//                cout << endl << "Up" << endl;//key up
//                break;
//            case KEY_DOWN   /* K */:
//                cout << endl << "Down" << endl;   // key down
//                break;
//            case KEY_LEFT   /* M */:
//                cout << endl << "Left" << endl;  // key left
//                break;
//            case KEY_RIGHT: /* P */
//                cout << endl << "Right" << endl;  // key right
//                break;
//            default:
//                cout << endl << (char)ex << endl;  // not arrow
//                break;
//            }
//        }
//    }
//
//    return 0;
//}



//#include<iostream>
//#include<regex>
//#include<string>
//using namespace std;
//int main() 
//{
//	string s = "33";
//	int i = stoi(s);
//
//	cout << i;
//
//
//
//	/*string s, admin, temp = "", company;
//	cin >> s;
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] == '@') {
//			admin = temp;
//			temp = "";
//			continue;
//		}
//		else if (s[i] == '.') {
//			company = temp;
//		}
//		temp += s[i];
//	}
//	cout << admin << endl << company << endl;
//	*/
//	return 0;
//}



/*
#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main()
{
	regex keywords("[^for|if|while|do|switch|goto|int|bool|string]");
	regex words("[a-zA-Z|\_][a-zA-Z|\_|0-9]*");



	string in;
	while (cin >> in) {
		(regex_match(in,keywords)) ? (cout << "Matched \n") : (cout << "not Matched \n");
	}



	return 0;
}



#include<iostream>
using namespace std;
int main()
{
	int res = 0,min;
	bool odd,prime;
	cout << "Enter 1 for yes, 0 for no" << endl << endl;
	
	cout << "is the number greater than 50?" << endl;
	cin >> res;
	(res == 1) ? (min=51):(min=1);
	
	cout << "is it odd ?" << endl;
	cin >> res;
	(res == 1) ? (odd = true) : (odd = false);
	
	if (odd) 
	{
		cout << "is it prime ?" << endl;
		cin >> res;
		(res == 1) ? (prime = true) : (prime = false);
		while()
	}


	return 0;
}*/