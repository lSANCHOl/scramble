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


string encode(string key) {
	string input;
	string output;
	int len;	
	cout<<"ENCODE: ";
	getline(cin,input);
	len = input.length();
	for(int i=0; i<len; i++) {
		for(int j=0; j<95; j++) {
			if(input[i]==ckey[j]) {
				output += key[j];	
			}		
		}	
	}		
	return output;
}


string decode(string key) {
	string input;
	string output;
	string dkey;
	string loc1;
	int loc2;
	int loc3;
	int len;
	for(int x=0; x<95; x++) {
		loc1 = ckey[x];
		loc2 = key.find(loc1);
		dkey += ckey[loc2];		
	}	
	cout<<"DECODE: ";
	getline(cin,input);
	len = input.length();
	for(int i=0; i<len; i++) {
		for(int j=0; j<95; j++) {
			if(input[i]==ckey[j]) {
				output += dkey[j];	
			}		
		}	
	}		
	return output;

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
			cout<< encode(keyg) <<endl;
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




