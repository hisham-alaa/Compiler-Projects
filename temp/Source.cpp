#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main() {

	int n;
	cin >> n;
	map<string, int>largest;
	string temp;

	for (int i = 0; i < n; i++){
		cin >> temp;
		largest.emplace(temp, 0);
		largest.at(temp) = largest.at(temp) + 1;
	}
	auto max= std::max_element(largest.begin(), largest.end(), [](const auto& x, const auto& y)
		{ return x.second < y.second; });
	cout << max->first;
	return 0;
}



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