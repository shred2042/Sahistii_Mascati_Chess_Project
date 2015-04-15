#pragma once

#include "Util.h"
#include <vector>
using namespace std;
#ifndef PIECE_H
#define PIECE_H

class Piece
{
	protected:
		Position position;
		int priority;
		int color;
	
	public:
		Piece()
		{
			/*this->position.x = 0;
			this->position.y = 0;*/
			this->priority = 0;
		}

		Piece(Position p)
		{
			this->position = p;			
		}

		Position* getPosition()
		{
			Position *p = new Position;
			p->x = position.x;
			p->y = position.y;
			return p;
		}

		void setPosition(Position position)
		{
			this->position = position;
		}

		int getPriority()
		{
			return priority;
		}

		void setPriority(int priority)
		{
			this->priority = priority;
		}

		int getColor()
		{
			return color;
		}

		bool isInCheck(vector<Piece*> *against, vector<Piece*> *own, int (*table)[8][8])
		{
			Move *max = new Move();
			max->coef = -1;
			for (unsigned int i = 0; i < against->size(); i++)
			{
				Move *temp;
				temp = (*against)[i]->check_move(own, table);
				if (temp->coef > max->coef)
				{
					max->coef = temp->coef;					
				}
			}
			Position *p = getPosition();
			//cout << p->x << " " << p->y << " " << max->coef << "\n";
			return max->coef == REGE_PRIORITATE;
		}

		//move returneaza toate mutarile posibile pentru o piesa
		virtual vector<Move>* move(vector<Piece*> *against, vector<Piece*> *own, int (*table)[8][8]) = 0;	

		virtual Move* check_move(vector<Piece*> *against, int (*table)[8][8]) = 0;
		
};
#endif