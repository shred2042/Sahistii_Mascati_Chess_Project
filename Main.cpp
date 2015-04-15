#include "stdafx.h"


using namespace std;

#define DEPTH 1

/**
	*   In main preluam comenzile de la xboard/winboard 
	*	Comenzile vin pe rand cu getline, dupa care le interpretam
	*conform interfetei
**/
int main(int argc, char *argv[])
{
	string command;
	PlayTable *MyTable = new PlayTable();	


	/** Luam comenzile pana cand se primeste o comanda de exit **/
	while (true)
	{
		
		getline(cin, command);

		if (command == "test")
		{
			MyTable->test();
		}
		
		/** XBOARD **/
		if (command == "xboard")
		{
			//prima comanda de xboard
		
		}

		/** NEW **/
		/**
			* Creeaza tabla de joc si aseaza piesele la locul lor
		**/
		if (command == "new")
		{
			delete MyTable;
			MyTable = new PlayTable();
			//MyTable->print();
		}
		
		/** FORCE **/
		if (command == "force")
		{
			//aici lasam comanda jucatorului uman, deci asteptam alte comenzi
		}
	
		/** GO **/
		if (command == "go")
		{
			if (MyTable->getColor() == 1)
			{
				MyTable->moveWhite(DEPTH);
			}
			else
			{
				MyTable->moveBlack(DEPTH);
			}	
			//MyTable->print();
		}

		/** WHITE **/
		if (command == "white")
		{			
			MyTable->setColor(1);			
		}

		/** BLACK **/
		if (command == "black")
		{			
			MyTable->setColor(0);		
		}

		/** QUIT **/
		if (command == "quit")
		{
			return 0;
		}

		/** RESIGN **/
		if (command == "resign")
		{
			cout << "resign\n";			
		}		

		/** IF valid MOVE **/
		if (command.size() == 4)
		{
			if (command[0] >= 'a' && command[0] <= 'h' &&
				command[1] >= '0' && command[1] <= '8' &&
				command[2] >= 'a' && command[2] <= 'h' &&
				command[3] >= '0' && command[3] <= '8')
			{
				MyTable->move(8 - (command[1] - '0'), command[0] - 'a', 8 - (command[3] - '0'), command[2] - 'a');
				if (MyTable->getColor() == 0)
				{
					MyTable->moveBlack(DEPTH);
				}
				else if (MyTable->getColor() == 1)
				{
					MyTable->moveWhite(DEPTH);
				}	
			}
			//MyTable->print();
		}		
	}
	return 0;
}