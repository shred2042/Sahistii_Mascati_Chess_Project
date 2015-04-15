#pragma once

#include "Piece.h"
class Pion : public Piece
{
	
	public:
		Pion(Position position, int color)
		{
			this->position  = position;
			this->priority = PION_PRIORITATE;
			this->color = color;
		}

		vector<Move>* move(vector<Piece*> *against, vector<Piece*> *own, int (*table)[8][8])
		{
			
			vector<Move> *moves = new vector<Move>();
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color = getColor();
			Move *m = new Move();
			Position next;
			Position prev;
			prev.x = x;
			prev.y = y;
			m->coef = -1;
			m->x1 = 0;
			m->x2 = 0;
			m->y1 = 0;
			m->y2 = 0;
			
			if (color < 0)
			{
				//incearca sa ia la stanga
				if ((x - 1 >= 0) && ((y - 1) >= 0) && ((*table)[x-1][y-1] > 0))
				{					
					if (m->coef < -color * (*table)[x-1][y-1])
					{
						int mem = (*table)[x-1][y-1];
						(*table)[x-1][y-1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x - 1;
						next.y = y - 1;
						setPosition(next);						
						if (!isInCheck(against, own, table))
						{							
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - 1;
							m->y2 = y - 1;
							m->coef = -color * mem;
						}						
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y-1];
						(*table)[x-1][y-1] = mem;
					}
				}
				//incearca sa ia piesa la dreapta
				if ((x - 1 >= 0) && ((y + 1) >= 0) && (*table)[x-1][y+1] > 0)
				{
					if (m->coef < -color * (*table)[x-1][y+1])
					{
						int mem = (*table)[x-1][y+1];
						(*table)[x-1][y+1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x - 1;
						next.y = y + 1;
						setPosition(next);						
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - 1;
							m->y2 = y + 1;
							m->coef = -color * mem;							
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y+1];
						(*table)[x-1][y+1] = mem;
					}					
				}
				//inainte
				if ( (x - 1 >= 0) && ((*table)[x - 1][y] == 0) )
				{
					if (m->coef < 0)
					{
						int mem = (*table)[x-1][y];
						(*table)[x-1][y] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x - 1;
						next.y = y;
						setPosition(next);
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - 1;
							m->y2 = y;
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y];
						(*table)[x-1][y] = mem;
					}
				}
				cout << getPosition()->x << " " << getPosition()->y << " "<< "Pion: " << m->coef << "\n" ;
				return moves;				
			}
			//negru
			else
			{
				//incearca sa ia la stanga (dupa tabla)
				if ((x + 1 <= 7) && ((y - 1) >= 0) && ((*table)[x+1][y-1] < 0))
				{
					if (m->coef < -color * (*table)[x+1][y-1])
					{
						int mem = (*table)[x+1][y-1];
						(*table)[x+1][y-1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x + 1;
						next.y = y - 1;
						setPosition(next);						
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + 1;
							m->y2 = y - 1;
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y-1];
						(*table)[x+1][y-1] = mem;
					}
				}
				//incearca sa ia la dreapta (dupa tabla)
				if ((x + 1 <= 7) && ((y + 1) <= 7) && ((*table)[x+1][y+1] < 0))
				{
					if (m->coef < -color * (*table)[x+1][y+1])
					{
						int mem = (*table)[x+1][y+1];
						(*table)[x+1][y+1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x + 1;
						next.y = y + 1;
						setPosition(next);						
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + 1;
							m->y2 = y + 1;
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y+1];
						(*table)[x+1][y+1] = mem;
					}
				}
				if ( (x + 1 <= 7) && ((*table)[x + 1][y] == 0))
				{
					if (m->coef < 0)
					{
						int mem = (*table)[x+1][y];
						(*table)[x+1][y] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x + 1;
						next.y = y;
						setPosition(next);						
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + 1;
							m->y2 = y;
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y];
						(*table)[x+1][y] = mem;
					}
				}
				cout << getPosition()->x << " " << getPosition()->y << " "<< "Pion: " << m->coef << "\n" ;
				return moves;				
			}
		}

		
		Move* check_move(vector<Piece*> *against, int (*table)[8][8])
		{
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color = getColor();
			Move *m = new Move();
			m->coef = -1;
			m->x1 = 0;
			m->x2 = 0;
			m->y1 = 0;
			m->y2 = 0;
			
			if (color < 0)
			{
				//incearca sa ia la stanga
				if ((x - 1 >= 0) && ((y - 1) >= 0) && ((*table)[x-1][y-1] > 0))
				{					
					if (m->coef < -color * (*table)[x-1][y-1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y - 1;
						m->coef = -color * (*table)[x-1][y-1];
					}
				}
				//incearca sa ia piesa la dreapta
				if ((x - 1 >= 0) && ((y + 1) >= 0) && (*table)[x-1][y+1] > 0)
				{
					if (m->coef < -color * (*table)[x-1][y+1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y + 1;
						m->coef = -color * (*table)[x-1][y+1];
					}					
				}
				//inainte
				if ( (x - 1 >= 0) && ((*table)[x - 1][y] == 0) )
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y;
						m->coef = 0;
					}
				}
				
				//cout << m->coef << '\n';
				return m;				
			}
			//negru
			else
			{
				//incearca sa ia la stanga (dupa tabla)
				if ((x + 1 <= 7) && ((y - 1) >= 0) && ((*table)[x+1][y-1] < 0))
				{
					if (m->coef < -color * (*table)[x+1][y-1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y - 1;
						m->coef = -color * (*table)[x+1][y-1];
					}
				}
				//incearca sa ia la dreapta (dupa tabla)
				if ((x + 1 <= 7) && ((y + 1) <= 7) && ((*table)[x+1][y+1] < 0))
				{
					if (m->coef < -color * (*table)[x+1][y+1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y + 1;
						m->coef = -color * (*table)[x+1][y+1];
					}
				}
				if ( (x + 1 <= 7) && ((*table)[x + 1][y] == 0))
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y;
						m->coef = 0;
					}
				}
				//cout << m->coef << '\n';
				return m;				
			}
		}
};