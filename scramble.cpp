#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// lenght = 95
string ckey = "abcdefghijklmnopqrstuvwxyz1234567890!$%^&*()-_=+[{]};:'@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\"']";

string keygen() 
{
	string ukey = "abcdefghijklmnopqrstuvwxyz1234567890!$%^&*()-_=+[{]};:'@#~|,<.>/? ABCDEFGHIJKLMNOPQRSTUVWXYZ\"']";
	srand(time(0));
	
	int x = ukey.length();
    	for(int y = x; y > 0; y--) { 
        	int pos = rand()%x;
        	char tmp = ukey[y-1];
        	ukey[y-1] = ukey[pos];
        	ukey[pos] = tmp;
    	}
	
	return ukey;	

}		


string gencode(string key) {
	cout<< "[KEY] " << key <<" [KEY]" <<endl;		
	string input2;
	string output2;
	int len2;	
	cout<<"ENCODE: ";
	cin.ignore(80, '\n');
	getline(cin,input2);
	len2 = input2.length();
	for(int i=0; i<len2; i++) {
		for(int j=0; j<95; j++) {
			if(input2[i]==ckey[j]) {
				output2 += key[j];	
			}		
		}	
	}		
	return output2;
}



string encode(string key) {
	string input;
	string output;
	int len;	
	cout<<"ENCODE: ";
	getline(cin,input);
	len = input.length();
	for(int a=0; a<len; a++) {
		for(int b=0; b<95; b++) {
			if(input[a]==ckey[b]) {
				output += key[b];	
			}		
		}	
	}		
	return output;
}


string decode(string key) {
	string input1;
	string output1;
	string dkey;
	string loc11;
	int loc21;
	int loc31;
	int len1;
	for(int z=0; z<95; z++) {
		loc11 = ckey[z];
		loc21 = key.find(loc11);
		dkey += ckey[loc21];		
	}	
	cout<<"DECODE: ";
	getline(cin,input1);
	len1 = input1.length();
	for(int k=0; k<len1; k++) {
		for(int p=0; p<95; p++) {
			if(input1[k]==ckey[p]) {
				output1 += dkey[p];	
			}		
		}	
	}		
	return output1;

}



int main()
{

while(true) {	
	cout<< endl;
	string choose;
	cout<< "[e]ncode | [d]ecode | [g]enerate key: ";
	cin >> choose;

	if (choose == "g") {
		string PrintOrSave;	
		cout<< "[p]rint key | [s]ave key to file: ";
		cin>> PrintOrSave;
	
		if (PrintOrSave == "p") {
			cout<< "[KEY] " << keygen() <<" [KEY]" <<endl;		
			
		}	
		
		else if (PrintOrSave == "s") {
			ofstream keyfile;
			keyfile.open("KEY");
			keyfile<< keygen() <<endl;
			keyfile.close();
				
		}
	}
	else if (choose == "e") {
		string FileOrGen;
		cout<< "[f]ile used as key | [g]enerate new key to use | [p]aste key in: ";
		cin>> FileOrGen;
		
		if (FileOrGen == "g") {
			string keyg;
			keyg = keygen();
			cout<< gencode(keyg) <<endl;
		}
		
		else if (FileOrGen == "f") {
			encode("Still Need to finish this");
		}
	
		else if (FileOrGen == "p") {
			cout <<"Input key: ";
			string pastekey;
			cin.ignore(80, '\n');
			getline(cin,pastekey);	
			cout<< encode(pastekey) <<endl;
			
		}
	}
	
	else if (choose == "d") {
		string choice;
		cout<< "[f]ile used as key | [p]aste key in: ";
		cin>> choice;
		if (choice == "f") {
		cout << "Finish This!"<<endl;
		}
	
		else if (choice == "p") {
			cout <<"Input key: ";
			string pastekey;
			cin.ignore(80, '\n');
			getline(cin,pastekey);	
			cout<< decode(pastekey) <<endl;
		}
	
	}
}
}



