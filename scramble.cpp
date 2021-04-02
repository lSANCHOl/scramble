#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;


string readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

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
	string input;
	string output;
	string filename;
	string chooser;
		
	int len;
	cout <<"[f]ile to encode  |  [t]ype to encode: ";
	cin >> chooser;

	if (chooser == "t") {
		cout<<"ENCODE: ";
		cin.ignore(80, '\n');
		getline(cin,input);
	}
	
	else if (chooser == "f") {
		cout << "name of file: ";
		cin >> filename;
		input = readFileIntoString(filename);

	}

	
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

string encode(string key) {
	string input;
	string output;
	string filename;
	string chooser;
		
	int len;
	cout <<"[f]ile to encode  |  [t]ype to encode: ";
	cin >> chooser;

	if (chooser == "t") {
		cout<<"ENCODE: ";
		cin.ignore(80, '\n');
		getline(cin,input);
	}
	
	else if (chooser == "f") {
		cout << "name of file: ";
		cin >> filename;
		input = readFileIntoString(filename);

	}


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
	string chooser1;
	string filename;
	int loc21;
	int loc31;
	int len1;
	for(int z=0; z<95; z++) {
		loc11 = ckey[z];
		loc21 = key.find(loc11);
		dkey += ckey[loc21];		
	}	

	cout <<"[f]ile to decode  |  [t]ype to decode: ";
	cin >> chooser1;

	if (chooser1 == "t") {
		cout<<"DECODE: ";
		cin.ignore(80, '\n');
		getline(cin,input1);
	}
	
	else if (chooser1 == "f") {
		cout << "name of file: ";
		cin >> filename;
		input1 = readFileIntoString(filename);
	}


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
string filename;
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
			ofstream keyfile;
			keyfile.open("KEY");
			keyfile<< keyg <<endl;
			keyfile.close();
		
			string write;
			cout << "[w]rite output to file  |  [p]rint output: ";
			cin >> write;	
			
			if (write == "p") {
				cout<< gencode(keyg) <<endl;
			}
			
			else if (write == "w") {
				ofstream encoded;
				string message;
				encoded.open("encoded.txt");
				message = gencode(keyg);
				encoded<< message << endl;
				encoded.close();
				cout << message << endl;
			}	
		}
		
		else if (FileOrGen == "f") {
			cout << "Name of key file";
			cin >> filename;
    			string file_contents;
			file_contents = readFileIntoString(filename);
    			cout << file_contents;
						
			string write;
			cout << "[w]rite output to file  |  [p]rint output: ";
			cin >> write;	
			
			if (write == "p") {
				cout << encode(file_contents) << endl;
			}
			
			else if (write == "w") {
				ofstream encoded;
				string message;
				encoded.open("encoded.txt");
				message = encode(file_contents);
				encoded<< message << endl;
				encoded.close();
				cout << message << endl;
			}
		}
	
		else if (FileOrGen == "p") {
			cout <<"Input key: ";
			string pastekey;
			cin.ignore(80, '\n');
			getline(cin,pastekey);	
						
			string write;
			cout << "[w]rite output to file  |  [p]rint output: ";
			cin >> write;	
			
			
			if (write == "p") {
				cout<< encode(pastekey) <<endl;
			}
			
			else if (write == "w") {
				ofstream encoded;
				string message;
				encoded.open("encoded.txt");
				message = encode(pastekey);
				encoded<< message << endl;
				encoded.close();
				cout << message << endl;
			}
		}
	}
	
	else if (choose == "d") {
		string choice;
		cout<< "[f]ile used as key | [p]aste key in: ";
		cin>> choice;
		if (choice == "f") {
			cout << "Name of key file";
			cin >> filename;
    			string file_contents;
			file_contents = readFileIntoString(filename);
    			cout << file_contents;
				
							
			string write;
			cout << "[w]rite output to file  |  [p]rint output: ";
			cin >> write;	
			
			
			if (write == "p") {
				cout << decode(file_contents) << endl;
			}
			
			else if (write == "w") {
				ofstream decoded;
				string message;
				decoded.open("decoded.txt");
				message = decode(file_contents);
				decoded<< message << endl;
				decoded.close();
				cout << message << endl;
			}	
		}
	
		else if (choice == "p") {
			cout <<"Input key: ";
			string pastekey;
			cin.ignore(80, '\n');
			getline(cin,pastekey);	
			cout<< decode(pastekey) <<endl;
						
			string write;
			cout << "[w]rite output to file  |  [p]rint output: ";
			cin >> write;	
			
			
			if (write == "p") {
				cout << decode(pastekey) << endl;
			}
			
			else if (write == "w") {
				ofstream decoded;
				string message;
				decoded.open("decoded.txt");
				message = decode(pastekey);
				decoded<< message << endl;
				decoded.close();
				cout << message << endl;
			}
		}
	}
}
}
