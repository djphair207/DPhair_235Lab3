//	This program is for formatting the lyrics. It will remove all text
//  between brackets. 
//	TASKS:
//	1. Fix the output file naming. Right now there's a double '.txt'
//	2. Make the read-in a function
//	3. Make the deletion a function

#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

//Print to new file
void PrintFile(string fileName,queue<char> printList){
	ofstream fout;
	fout.open(fileName);
	while(!printList.empty()){
		fout << printList.front();
		printList.pop();
	}
	fout.close();
}

int main(int argc, char *argv[]){
	ifstream fin;
	string fileName = argv[1];
	string printFile = fileName + "2.txt";	//Need to clean this up
	char in;
	queue<char> charsIn;
	queue<char> charsCorrected;
	set<char> deleteChars = {'[',']','{','}','(',')'};	
	set<char>::iterator findit;

	fin.open(fileName);
	for(in; fin.get(in);){
		charsIn.push(in);
	}

	while(!charsIn.empty()){
		//cout << "in while loop" << endl;
		findit = deleteChars.find(charsIn.front());
		if(findit != deleteChars.end()){ // true from this statement means that the top of the queue conatins a grouping character
			//cout << "made it into the 'if' statement" << endl;
			charsIn.pop();
			findit = deleteChars.find(charsIn.front());
			while(findit == deleteChars.end()){
				//cout << "in nested while loop" << endl;
				charsIn.pop();
				findit = deleteChars.find(charsIn.front());
			}
			charsIn.pop();
			charsIn.pop();
		}
		cout << charsIn.front();
		charsCorrected.push(charsIn.front());
		charsIn.pop();
	}
	//cout << endl;
	PrintFile(printFile, charsCorrected);
	
	
	//DEBUG: loop to print out set
	/*
	for(set<char>::iterator it = deleteChars.begin(); it != deleteChars.end(); it++){
		cout << *it << ", ";
	}
	cout << endl;
	*/
	
	cout << endl;

	
}

