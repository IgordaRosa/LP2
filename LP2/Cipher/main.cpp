#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool mysorterfunction(const pair< size_t, size_t > &p1, const pair< size_t, size_t > &p2)
{
    return (p1.second > p2.second);
}

int main()
{
///////////////////////////////////////

    map< char, int > cipher_freq;
    vector< int > v_ascii;
    char ch;
    string str;

    ifstream freqList("freq.txt");
    if(!freqList.is_open())
    {
        cout << "Error, file not found!" << endl;
        return 1;
    }
    else
    {
        while(getline(freqList, str))
        {
            v_ascii.push_back(stoi(str));
        }
    }

    // abrir arquivo para decodificar
    ifstream cipher("cipher.txt");
    if(!cipher.is_open())
    {
        cout << "Error, file not found!" << endl;
        return 2;
    }
    else
    {
        while(cipher.get(ch))
        {
            if(ch != '\n')
            cipher_freq[ch] += 1;
        }
    }

    cout << "Occurrences:\n" << endl;

    for(auto h : cipher_freq)
    {
        cout << h.first << " -> " << h.second << endl;
    }
    
///////////////////////////////////////

    //reading a manuscript file
    cout << "Cipher:\n" << endl;
    ifstream frManusc("t3.txt");
    stringstream manuscriptStr;
    if(!frManusc.is_open())
    {
        cout << "Error, manuscript file not found" << endl;
        return 2;
    }
    else
    {
        char ch;
        while(frManusc.get(ch))
        {
            manuscriptStr << ch;
        }
    }
    cout << manuscriptStr.str() << endl;
    
    //computing the characters frequency of the manuscript
    //initialize
    vector < pair< size_t, size_t > > frequencyList;
    for(size_t i=0; i<256; i++)
    {
        pair< size_t, size_t > p;
        p.first = i;
        p.second = 0;        
        frequencyList.push_back(p);
    }
    for(size_t i=0; i<manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        frequencyList.at(ch).second++;       
    }
    
    //sort and remove elements with zero frequency
    stable_sort(frequencyList.begin(), frequencyList.end(), mysorterfunction);
    for(size_t i=0; i<frequencyList.size(); i++)
    {
        if(frequencyList.at(i).second == 0)
        {
            frequencyList.erase(frequencyList.begin()+i, frequencyList.end());
        }
    }
    
    /*if(alphabetList.size() < frequencyList.size())
    {
        cout << "Error, alphabet with insufficient characters to encode  themanuscript" << endl;
        return 3;
    }*/


    for(;;){//connecting alphabet and frequency list
    cout << endl << "enter with an alphabet to read: ";
    string pathAlpha;
    cin >> pathAlpha;
    
    //reading an alphabet file
    ifstream frAlpha(pathAlpha);
    vector< char > alphabetList;
    if(pathAlpha == "exit"){
        break;
    }
    if(!frAlpha.is_open())
    {
        cout << "Error, alphabet file not found" << endl;
        return 1;
    }
    else
    {
        string tmp;
        while(getline(frAlpha, tmp))
        {
            alphabetList.push_back(tmp.at(0));
        }
    }

    for(size_t i=0; i<frequencyList.size(); i++)
    {
        frequencyList.at(i).second = alphabetList.at(i);
    }
    
    for(size_t i=0; i<frequencyList.size(); i++)
    {
        cout << frequencyList.at(i).first << " -> " << (char) frequencyList.at(i).first << " " << (char) frequencyList.at(i).second << endl;
    }
    
    //convert manuscript to codes
    for(size_t i=0; i<manuscriptStr.str().size(); i++)
    {
        char ch = manuscriptStr.str().at(i);
        for(size_t j=0; j<frequencyList.size(); j++)
        {
            if(ch == frequencyList.at(j).first)
            {
                cout << (char) frequencyList.at(j).second;
                break;
            }
        }        
    }
    frAlpha.close();
    continue;
    }
    cout << endl;
    
    return 0;
}