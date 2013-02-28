#include <iostream>
using namespace std;
int main() {
for(int i = 1; i <= 20; i++) {
if(i != 20) cout << i << " " << 1 << " " << i+1 << " " << 1 << endl;
for(int j = 1; j < 20; j++) {
cout << i << " " << j << " " << i << " " << j+1 << endl;
}
}
return 0;
}