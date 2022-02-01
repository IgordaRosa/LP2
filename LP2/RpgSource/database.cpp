#include "database.hpp"

vector<Char> LoadDatabase()
{
	vector<Char> Dat;

	return Dat;
}

void SaveDatabase(vector<Char> C)
{
	ofstream Database;
	Database.open("Saves.dat");
	if(Database.is_open())
	{
		for(size_t i = 0; i < C.size(); i++)
		{
			Database << C.at(i).GetCharName() << ".dat" << endl;
		}
	}


/*		for(size_t i = 0; i < C.size(); i++)
		{
			Database << C.at(i).GetCharName() << endl;
			Database << C.at(i).GetCharAltura() << endl;
			Database << C.at(i).GetCharCabelo() << endl;
			Database << C.at(i).GetCharCcabelo() << endl;
			Database << C.at(i).GetCharCpele() << endl;
			Database << C.at(i).GetCharGenero() << endl;
			Database << C.at(i).GetCharLevel() << endl;
			Database << C.at(i).GetCharDin() << endl;
			Database << C.at(i).GetCharATK()<< endl;
			Database << C.at(i).GetCharDEF() << endl;
			Database << C.at(i).GetCharVEL() << endl;
		}
 */
}
