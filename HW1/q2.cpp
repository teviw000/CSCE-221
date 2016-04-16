//Kyle Loyka

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void test(string in){
bool is_pal = true;
for (int i = 0; i< in.size()/2; ++i){
	if (in[i] != in[in.size()-1-i]) is_pal = false;
	}
if (in.size() == 0) is_pal = false;
if (is_pal) cout << in <<" is palindrome"<<endl;
else cout <<in <<" is NOT palindrome"<<endl;
}


int main(){

string in;
cout<<"testing emtpy string \n";
test(in);

in = "racecar";
test(in);

in = "gohangasalamiimalasagnahog";
test(in);

in = "dad";
test(in);

in = "daad";
test(in);

in = "texas";
test(in);

in = "computer";
test(in);

return 0;
}
