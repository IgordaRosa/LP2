#include "biblioteca.hpp"

bool LoadDictionary(string path, vector< string > &wordlist)
{
    ifstream filereader;
    filereader.open(path);

    //checking if file is valid
    if(filereader.is_open() == false)
        return false;

    //reading file and filling a vector
    string tmp;
    while(getline(filereader, tmp))
    {
        wordlist.push_back(tmp);
    }

    //remove first element
    wordlist.erase (wordlist.begin()+0);

    return true;
}

bool SearchWord(const vector< string > &wordlist, string query)
{
    for(size_t i=0; i< wordlist.size(); i++)
    {
        string word = wordlist.at(i);
        for(size_t j=0; j < word.size(); j++){
            if(word.find(query) == j){
                return true;
            }
        }
    }
    return false;
}

vector< string > SearchSubstrings(const vector< string > &wordlist, string query)
{
    vector< string > newsublist;

    for(size_t i=0; i< wordlist.size(); i++)
    {
        string word = wordlist.at(i);
        //size_t pos = word.find(query);
        for(size_t j=0; j < word.size(); j++){
            if(word.find(query)== j)
            {
                newsublist.push_back(word);
            }
        }        
    }
    return newsublist;
}

