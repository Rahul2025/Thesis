#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char ch;
	ifstream file("stats");
	ofstream file1("temp");
	if( file.is_open() )
	{
		while(file >> noskipws >> ch)
		{
			if( ch == ' ')
				file1 << ",";
			else if( ch == '\n')
				file1 << ",";
			else if( ch == '\t')
				file1 << ",";
			else
				file1 << ch;
		}
		file1 << "\n";
		file.close();
		file1.close();
	}
	else
		cout << "Error in opening file...";
	

	return 0;
}