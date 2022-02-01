#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

bool LoadDictionary(string path, vector< string > &wordlist);
bool SearchWord(const vector< string > &wordlist, string query);
vector< string > SearchSubstrings(const vector< string > &wordlist, string query);
