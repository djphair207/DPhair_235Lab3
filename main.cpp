#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <list>

using namespace std;

int main(int argc, char *argv[]) {
	srand(time(NULL));						//for random num generator
	string baseFileName = argv[1];
  ifstream fin;
	ofstream fout;
	set<string> wordSet;
	vector<string> wordVec;
	map<string, string> wordMap;
	string mapOutFile = baseFileName + "_map.txt";
	string setOutFile = baseFileName + "_set.txt";
	string vecOutFile = baseFileName + "_vector.txt";
	string state;
	
	string next_line;

	fin.open(baseFileName);
	while(getline(fin, next_line)){
		istringstream iss(next_line);
		string word;
		while(iss >> word){
			string notpunc = "";
			for(auto &c : word){
				if(isalpha(c)){
					notpunc += c;
				}
			}
			wordVec.push_back(notpunc);
			wordSet.insert(notpunc);
		}
	}
	fin.close();

	// Print set contents
	fout.open(setOutFile);
	for(set<string>::iterator it = wordSet.begin(); it != wordSet.end(); it++){
		fout << *it << endl;
	}
	fout.close();
	
	// Print vector contents
	fout.open(vecOutFile); 
	for(int i = 0; i < wordVec.size(); i++){
		fout << wordVec[i] << endl;
	}
	fout.close();

	// Create the map
	string last = "";
	for(int i = 0; i < wordVec.size(); i++){
		wordMap[last] = wordVec[i];
		last = wordVec[i];
	}

	// Print map contents
	fout.open(mapOutFile);
	for(map<string, string>::iterator it = wordMap.begin(); it != wordMap.end(); it++){
		fout << it->first << ", " << it->second << endl;
	}
	fout.close();

	// Generate a sermon
	/*
	state = "";
	for(int i = 0; i < 100; i++){
		cout << wordMap[state] << " ";
		state = wordMap[state];
	}
	cout << endl;
	*/

	// Create map w/ string keys and vector contents
	/*
	map<string, vector<string>> wordMapVec;
	state = "";
	for(int i = 0; i < wordVec.size(); i++){
		wordMapVec[state].push_back(wordVec[i]);
		state = wordVec[i];
	}
	

	// Print out the vec contents of a specific key
	int counter = 0;
	for(map<string, vector<string>>::iterator it = wordMapVec.begin(); it != wordMapVec.end(); it++){
		counter++;
		string key = it->first; 
		if (counter == 6){
			for(int i = 0; i < wordMapVec[key].size(); i++){
				cout << wordMapVec[key].at(i) << ", ";
				}
		}
	}
	cout << endl;

	// Print out a new sermon 
	state = "";
	for(int i = 0; i < 100; i++){
		int ind = rand() % wordMapVec[state].size();
		cout << wordMapVec[state][ind] << " ";
		state = wordMapVec[state][ind];
	}
	cout << endl;
	*/

	// Create keys for the map with list-of-strings keys and vector-of-string contents
	map<list<string>, vector<string>> wordMapLV;
	list<string> state2;
	const int M = 3;		// Key list size, higher should give better print results
	for(int i = 0; i < M; i++){
		state2.push_back("");
	}
	// Fill in all the keys
	for(int i = 0; i < wordVec.size(); i++){
		wordMapLV[state2].push_back(wordVec[i]);
		state2.push_back(wordVec[i]);
		state2.pop_front();
	}

	state2.clear();
	for(int i = 0; i < M; i++){
		state2.push_back("");
	}
	
	for(int i = 0; i < 100; i++){
		int ind = rand() % wordMapLV[state2].size();
		cout << wordMapLV[state2][ind] << " ";
		state2.push_back(wordMapLV[state2][ind]);
		state2.pop_front();
		if(wordMapLV[state2].size() == 0){		// If the vector is empty, reset state2 to initial
			for(int j = 0; j < M; j++){
				state2.push_back("");
			}
		}
	}
	cout << endl;
	/*
	cout << wordVec.size() << endl;
	cout << wordSet.size() << endl;
	*/
}