//	This program is for formatting the lyrics. It will remove all text
//  between brackets. 

#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>
#include <set>

using namespace std;

//Read file
void ReadFile(string fileName, char in, queue<char> &chars){
	cout << "Reading file" << endl;
	ifstream fin;
	fin.open(fileName);
	for(in; fin.get(in);){
		chars.push(in);
	}
	fin.close();
}

//Remove brackets and text between brackets
queue<char> DeleteBrackets(queue<char> &chars, set<char> toDelete, set<char>::iterator finder){
	//cout << "Deleting brackets" << endl;
	queue<char> returnQueue;
	/*
	int whileCounter = 1;
	int ifCounter = 1;
	int nestWhileCounter = 1;
	*/	//DEBUG COUNTERS
	//cout << "Made it to while loop" << endl;
	while(!chars.empty()){
		finder = toDelete.find(chars.front());
		if(finder != toDelete.end()){
			/*
			if(ifCounter % 20 == 0){
				cout << ifCounter << "th time thru if" << endl;
			}
			if(ifCounter > 220){
				cout << "ifCounter @ " << ifCounter << endl;
			}
			ifCounter++;
			*/	//DEBUG COUNTERS
			chars.pop();
			finder = toDelete.find(chars.front());
			while(finder == toDelete.end()){
				/*
				if(nestWhileCounter > 20130){
					cout << "nestWhileCounter @ " << nestWhileCounter << endl;
				}
				nestWhileCounter++;
				*/	//DEBUG COUNTERS
				chars.pop();
				finder = toDelete.find(chars.front());
			}
			chars.pop();
		}
		returnQueue.push(chars.front());
		chars.pop();
		//whileCounter++;	//DEBUG COUNTERS
	}
	return returnQueue;
}

//Print to new file
void PrintFile(string fileName,queue<char> printList){
	cout << "Printing to new file" << endl;
	ofstream fout;
	fout.open(fileName);
	while(!printList.empty()){
		fout << printList.front();
		printList.pop();
	}
	fout.close();
}

//Clean up the output file name
string NameOutFile(string fileName){
	string ext = ".txt";
	fileName = fileName.substr(0, fileName.size() - ext.size());
	return fileName;
}

int main(int argc, char *argv[]){
	string fileName = argv[1];
	string printFile = NameOutFile(fileName) + "2.txt";	
	char in;
	
	queue<char> charsIn;
	queue<char> charsCorrected;
	set<char> deleteChars = {'[',']','{','}','(',')'};	
	set<char>::iterator findit;

	ReadFile(fileName, in, charsIn);
	/*	//Replace by the function 'ReadFile'
	fin.open(fileName);
	for(in; fin.get(in);){
		charsIn.push(in);
	}
	*/

	charsCorrected = DeleteBrackets(charsIn, deleteChars, findit);
	/*
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
	*/

	PrintFile(printFile, charsCorrected);
	
	//DEBUG: loop to print out set
	/*
	for(set<char>::iterator it = deleteChars.begin(); it != deleteChars.end(); it++){
		cout << *it << ", ";
	}
	cout << endl;
	*/
	
}

