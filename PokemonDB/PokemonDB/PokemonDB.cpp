// Author:	Salvatore Di Fiore
// Date:	10/31/2018
// Updated	5/31/2019

#include "PokemonDB.h"

// Constructor; defaults values of member variables.
PokemonDB::PokemonDB()
{
	m_name = "MissingNo";
	m_type = "Null";
	m_number = 0;
}

// This function returns the name of the pokemon.
string PokemonDB::GetName()
{
	return m_name;
}

// This function returns the type of the pokemon.
string PokemonDB::GetType()
{
	return m_type;
}

// This function returns the number of the pokemon.
int	PokemonDB::GetNumber()
{
	return m_number;
}

// This functions assigns a name to the pokemon.
void PokemonDB::SetName(string name)
{
	m_name = name;
}

// This function assigns a type to the pokemon.
void PokemonDB::SetType(string type)
{
	m_type = type;
}

// This function assigns a number to the pokemon.
void PokemonDB::SetNumber(int number)
{
	m_number = number;
}

// This function removes spaces from the user input.
string RemoveSpaces(string& str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	str.erase(remove(str.begin(), str.end(), '\t' ), str.end());
	return str;
}

// This function checks and converts the capitalization of user input.
string ConvertName(string& name)
{
	int i;

	for (i = 0; i < name.length(); i++)
	{
		name[i] = tolower(name[i]);
	}
	i = 0;
	name[i] = toupper(name[i]);
	return name;
}

// This function sets the color of the console output.
void SetColor(int value) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

// This function displays the menu on the console.
void PokemonDB::Menu()
{
	int option;

	do
	{
		system("cls");
		cout << "Welcome to PokemonDB!" << endl;
		cout << "---------------------" << endl;
		cout << "1. Search Pokemon by name" << endl;
		cout << "2. Search Pokemon by number" << endl;
		cout << "3. Exit PokemonDB" << endl;
		cout << "Enter option here: ";
		cin >> option;
		if (option == 1)
		{
			string name;

			cin.ignore();
			cout << "Enter pokemon name: ";
			getline(cin, name);
			RemoveSpaces(name);
			ConvertName(name);
			Read(name);
			break;
		}
		else if (option == 2)
		{
			int number;

			cin.ignore();
			cout << "Enter pokemon number: ";
			cin >> number;
			Read(number);
			break;
		}
		else
		{
			return;
		}
	} while (option != 3);
}

// This function displays the menu if the user presses "1", then "Enter".
void ReturnToMenu()
{
	int option;
	PokemonDB p;

	SetColor(7);				// Default console output color.
	cout << "Press 1, then Enter to return to the main menu." << endl;
	cout << "Press any other key, then Enter to exit PokemonDB." << endl;
	cout << "Enter here: ";
	cin >> option;

	if (option == 1)
	{
		p.Menu();
	}
	else
	{
		return;
	}
}

// This function reads values from the pokedex file.
void PokemonDB::Read(string s)
{
	PokemonDB p;
	string file = "Pokedex.txt";
	ifstream ifile;
	int i = 0;

	ifile.open(file);

	while (i < 151)
	{
		getline(ifile, m_name);
		getline(ifile, m_type);
		ifile >> m_number;
		ifile.ignore();			// Consumes the end of the number line (\n).

		if (s == m_name)
		{
			p.SetName(m_name);
			p.SetType(m_type);
			p.SetNumber(m_number);
			if (m_name == "Pikachu")
			{
				SetColor(14);	// Yellow console output color.
			}
			Print(p);
			if (m_name == "Nidoran")
			{
				p.SetNumber(32);
				Print(p);
			}
			break;				// Exits loop when parameter value equals a string value in ifile
		}
		else if (i == 150)
		{
			Print(p);			// Prints default values if parameter value never equaled an int value in ifile
		}
		i++;
	}
	ifile.close();
	ReturnToMenu();
}

// This function reads values from the pokedex file.
void PokemonDB::Read(int number)
{
	PokemonDB p;
	string file = "Pokedex.txt";
	ifstream ifile;
	int i = 0;

	ifile.open(file);

	while (i < 151)
	{
		getline(ifile, m_name);
		getline(ifile, m_type);
		ifile >> m_number;
		ifile.ignore();			// Consumes the end of the number line (\n).

		if (number == m_number)
		{
			p.SetName(m_name);
			p.SetType(m_type);
			p.SetNumber(m_number);
			if (m_number == 25)
			{
				SetColor(14);	// Yellow console output color.
			}
			Print(p);
			break;				// Exits loop when parameter value equals an int value in ifile
		}
		else if (i == 150)
		{
			Print(p);			// Prints default values if parameter value never equaled an int value in ifile
		}
		i++;
	}
	ifile.close();
	ReturnToMenu();
}

// This function prints values from the pokedex file.
void PokemonDB::Print(PokemonDB p)
{
	cout << "Name: " << p.GetName() << endl;
	cout << "Type: " << p.GetType() << endl;
	cout << "No:  #" << p.GetNumber() << endl;
}