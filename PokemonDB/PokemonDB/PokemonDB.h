// Author:	Salvatore Di Fiore
// Date:	10/31/2018
// Updated	5/31/2019

#ifndef PokemonDB_H
#define PokemonDB_H

#include "Source.h"

class PokemonDB
{
private:
	string	m_name;
	string	m_type;
	int		m_number;
public:
	PokemonDB();

	string	GetName();
	string	GetType();
	int		GetNumber();

	void	SetName(string);
	void	SetType(string);
	void	SetNumber(int);

	void	Menu();
	void	Read(string);
	void	Read(int);
	void	Print(PokemonDB);
};

string RemoveSpaces(string&);
string ConvertName(string&);
void SetColor(int);
void ReturnToMenu();

#endif // !PokemonDB_H