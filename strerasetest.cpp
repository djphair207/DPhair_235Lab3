#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	string str1 = "taylor.txt";
	string ext = ".txt";

	str1 = str1.substr(0, str1.size() - ext.size());

	cout << str1 << endl;
}