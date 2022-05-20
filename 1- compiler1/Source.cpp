#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
int main() {

	ifstream i("in.txt");
	bool opened = false, coma = false, ftaken = false, staken = false;
	int nums[20] = { 0 }, nds = 0, clr = 0;
	string colors[20], s;
	char ch;

	i >> ch;
	while (!i.eof())
	{
		if (ch == ' ') {}

		else if (ch == '(' && !opened && !coma)
		{
			opened = true;
			coma = true;
			ftaken = false;
			staken = false;
		}

		else if (isdigit(ch) && opened && (!ftaken || !staken))
		{
			s = "";
			while (isdigit(ch))
			{
				s += ch;
				cout << ch;
				i >> ch;
			}
			nums[nds++] = stoi(s);
			(!ftaken) ? (ftaken = true) : (staken = true);
			continue;
		}

		else if (ch == ',' && coma && ftaken)
		{
			coma = false;
		}

		else if (isalpha(ch) && opened && ftaken && !staken)
		{
			s = "";
			while (isalpha(ch))
			{
				s += ch;
				cout << ch;
				i >> ch;
			}
			colors[clr++] = s;
			staken = true;
			continue;
		}

		else if (ch == ')' && opened && staken)
		{
			opened = false;
			coma = true;
		}

		else
		{
			cout << endl << "non-valid input in char \'" << ch << "\'" << endl;
			return 0;
		}

		cout << ch;
		i >> ch;
	}

	sort(nums, nums + nds);
	cout << endl << endl << "Nodes are : " << nums[0] << "  ";
	for (int i = 1; i < nds; i++)
		if (nums[i - 1] != nums[i])
			cout << nums[i] << "  ";

	sort(colors, colors + clr);
	cout << endl << endl << "Colors are : " << colors[0] << "  ";
	for (int i = 1; i < clr; i++)
		if (colors[i - 1] != colors[i])
			cout << colors[i] << "  ";

	cout << endl;
	i.close();
	return 0;
}