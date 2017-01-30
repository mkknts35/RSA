#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "rsa.h"
#include "pp.h"

using namespace std;

const int PUBLIC_KEY[] = {121, 10677301};
const int PRIVATE_KEY[] = {705481, 10677301};

int main(int argc, char *argv[]){

    regex exp("[+-]?[0-9]+");
    ifstream fin;
    if (argc != 4) {
        cout << "Invalid input." << endl;
        return 0;
    }
    string filename(argv[1]);
    fin.open(filename);
    if (!fin){
        cout << "Cannot open file: " << filename << endl;
        return 0;
    }
    string s_key(argv[2]);
    string s_n(argv[3]);
    if (!regex_match(s_key, exp) || !regex_match(s_n, exp)){
        cout << "Invalid input: (" << s_key << ", " << s_n << ") is not a valid key pair." << endl;
        return 0;
    } 
    int key = stoi(s_key);
    int n = stoi(s_n);
    stringstream buffer;
    buffer << fin.rdbuf();
#if ENCRYPT
    string message = encrypt(buffer.str(), key, n);
    string extension = ".encoded";
#else
    string message = decrypt(buffer, key, n);
    string extension = ".decoded";
#endif
    string outfile = filename.substr(0, filename.find('.')) + extension;
    ofstream fout;
    fout.open(outfile);
    if (!fout) {
        cout << "Cannot create file: " << outfile << endl;
        return 0;
    }
    fout << message;

    return 0;
}

