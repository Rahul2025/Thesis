#include <iostream>
#include <set>

using namespace std;

typedef set<int> int_set;

int main(int argc, char** argv) {
	int_set input;
	int_set mod_set;
	int v = 0;
	
	for (int i = 0; i < 10; i++) {
		input.clear();
		for (int j = 0; j < 10; j++) {
			cin >> v;
			input.insert(v);
		}
		
		mod_set.clear();
		for (int_set::iterator i = input.begin(); i != input.end(); i++) {
			mod_set.insert(*i % 42);
		}
		
		cout << mod_set.size() << endl;
	}
}