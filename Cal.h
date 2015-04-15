#pragma once

#include "Piece.h"

class Cal : public Piece
{
	//private:
	public:
		Cal(Position position, int color)
		{
			this->position = position;
			this->priority = CAL_PRIORITATE;
			this->color = color;
		}

		vector<Move>* move(vector<Piece*> *against, vector<Piece*> *own, int (*table)[8][8])
		{
			vector<Move> *moves = new vector<Move>();
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color  =  getColor();

			Position next;
			Position prev;
			prev.x = x;
			prev.y = y;

			Move *m = new Move();
			m->coef = -1;
			m->x1 = 0;
			m->x2 = 0;
			m->y1 = 0;
			m->y2 = 0;

			

			//ataca top left
			if (x - 2 > -1 && y - 1 > -1 && (*table)[x-2][y-1] * color < 0)
			{	
					int mem = (*table)[x-2][y-1];
					(*table)[x-2][y-1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 2;
					next.y = y - 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 2;
						m->y2 = y - 1;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-2][y-1];
					(*table)[x-2][y-1] = mem;
				
			}

			//ataca top right
			if (x - 2 > -1 && y + 1 < 8 && (*table)[x-2][y+1] * color < 0)
			{
					int mem = (*table)[x-2][y+1];
					(*table)[x-2][y+1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 2;
					next.y = y + 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 2;
						m->y2 = y + 1;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-2][y+1];
					(*table)[x-2][y+1] = mem;
				
			}

			//ataca left top
			if (x - 1 > -1 && y - 2 > -1 && (*table)[x-1][y-2] * color < 0)
			{
				
					int mem = (*table)[x-1][y-2];
					(*table)[x-1][y-2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 1;
					next.y = y - 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y - 2;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-1][y-2];
					(*table)[x-1][y-2] = mem;			
			}

			//ataca right top 
			if (x - 1 > -1 && y + 2 < 8 && (*table)[x-1][y+2] * color < 0)
			{
					
					int mem = (*table)[x-1][y+2];
					(*table)[x-1][y+2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 1;
					next.y = y + 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y + 2;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-1][y+2];
					(*table)[x-1][y+2] = mem;

			}

			//ataca left bottom
			if (x + 1 < 8 && y - 2 > -1 && (*table)[x+1][y-2] * color < 0)
			{
					int mem = (*table)[x+1][y-2];
					(*table)[x+1][y-2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 1;
					next.y = y - 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y - 2;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+1][y-2];
					(*table)[x+1][y-2] = mem;
	
			}

			//ataca right bottom
			if (x + 1 < 8 && y + 2 < 8 && (*table)[x+1][y+2] * color < 0)
			{
					int mem = (*table)[x+1][y+2];
					(*table)[x+1][y+2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 1;
					next.y = y + 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y + 2;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+1][y+2];
					(*table)[x+1][y+2] = mem;
			}

			//ataca bottom right
			if (x + 2 < 8 && y + 1 < 8 && (*table)[x+2][y+1] * color < 0)
			{
					int mem = (*table)[x+2][y+1];
					(*table)[x+2][y+1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 2;
					next.y = y + 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 2;
						m->y2 = y + 1;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+2][y+1];
					(*table)[x+2][y+1] = mem;
		
			}
				
			//ataca bottom left
			if (x + 2 < 8 && y - 1 < 8 && (*table)[x+2][y-1] * color < 0)
			{
					
					int mem = (*table)[x+2][y-1];
					(*table)[x+2][y-1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 2;
					next.y = y - 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 2;
						m->y2 = y - 1;
						m->coef = -color * mem;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+2][y-1];
					(*table)[x+2][y-1] = mem;
	
			}

			//muta top left
			if (x - 2 > -1 && y - 1 > -1 && (*table)[x-2][y-1] == 0)
			{
					int mem = (*table)[x-2][y-1];
					(*table)[x-2][y-1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 2;
					next.y = y - 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 2;
						m->y2 = y - 1;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-2][y-1];
					(*table)[x-2][y-1] = mem;

			}

			//muta top right
			if (x - 2 > -1 && y + 1 < 8 && (*table)[x-2][y+1] == 0)
			{
					int mem = (*table)[x-2][y+1];
					(*table)[x-2][y+1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 2;
					next.y = y + 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 2;
						m->y2 = y + 1;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-2][y+1];
					(*table)[x-2][y+1] = mem;
			}

			//muta left top
			if (x - 1 > -1 && y - 2 > -1 && (*table)[x-1][y-2] == 0)
			{
					int mem = (*table)[x-1][y-2];
					(*table)[x-1][y-2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 1;
					next.y = y - 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y - 2;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-1][y-2];
					(*table)[x-1][y-2] = mem;
				
			}

			//muta right top 
			if (x - 1 > -1 && y + 2 < 8 && (*table)[x-1][y+2] == 0)
			{
					int mem = (*table)[x-1][y+2];
					(*table)[x-1][y+2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x - 1;
					next.y = y + 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y + 2;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x-1][y+2];
					(*table)[x-1][y+2] = mem;
		
			}

			//muta left bottom
			if (x + 1 < 8 && y - 2 > -1 && (*table)[x+1][y-2] == 0)
			{
					int mem = (*table)[x+1][y-2];
					(*table)[x+1][y-2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 1;
					next.y = y - 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y - 2;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+1][y-2];
					(*table)[x+1][y-2] = mem;
	
			}

			//muta right bottom
			if (x + 1 < 8 && y + 2 < 8 && (*table)[x+1][y+2] == 0)
			{
					int mem = (*table)[x+1][y+2];
					(*table)[x+1][y+2] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 1;
					next.y = y - 2;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y + 2;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+1][y+2];
					(*table)[x+1][y+2] = mem;

			}

			//muta bottom right
			if (x + 2 < 8 && y + 1 < 8 && (*table)[x+2][y+1] == 0)
			{
					int mem = (*table)[x+2][y+1];
					(*table)[x+2][y+1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 2;
					next.y = y + 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 2;
						m->y2 = y + 1;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+2][y+1];
					(*table)[x+2][y+1] = mem;

			}
				
			//muta bottom left
			if (x + 2 < 8 && y - 1 < 8 && (*table)[x+2][y-1] == 0)
			{
					int mem = (*table)[x+2][y-1];
					(*table)[x+2][y-1] = (*table)[x][y];
					(*table)[x][y] = 0;
					next.x = x + 2;
					next.y = y - 1;
					setPosition(next);
					if (!isInCheck(against, own, table))
					{
						setPosition(prev);
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 2;
						m->y2 = y - 1;
						m->coef = 0;
						moves->push_back(*m);
					}
					setPosition(prev);
					(*table)[x][y] = (*table)[x+2][y-1];
					(*table)[x+2][y-1] = mem;
			
			}
			cout << getPosition()->x << " " << getPosition()->y << " "<< "Cal: " << m->coef << "\n" ;
			return moves;
		}

		Move* check_move(vector<Piece*> *against, int (*table)[8][8])
		{
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color  =  getColor();

			Move *m = new Move();
			m->coef = -1;
			m->x1 = 0;
			m->x2 = 0;
			m->y1 = 0;
			m->y2 = 0;

			

			//ataca top left
			if (x - 2 > -1 && y - 1 > -1 && (*table)[x-2][y-1] * color < 0)
			{				
				if (m->coef < -color * (*table)[x-2][y-1])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 2;
					m->y2 = y - 1;
					m->coef = -color * (*table)[x-2][y-1];
				}
			}

			//ataca top right
			if (x - 2 > -1 && y + 1 < 8 && (*table)[x-2][y+1] * color < 0)
			{
				if (m->coef < -color * (*table)[x-2][y+1])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 2;
					m->y2 = y + 1;
					m->coef = -color * (*table)[x-2][y+1];
				}
			}

			//ataca left top
			if (x - 1 > -1 && y - 2 > -1 && (*table)[x-1][y-2] * color < 0)
			{
				if (m->coef < -color * (*table)[x-1][y-2])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 1;
					m->y2 = y - 2;
					m->coef = -color * (*table)[x-1][y-2];
				}
			}

			//ataca right top 
			if (x - 1 > -1 && y + 2 < 8 && (*table)[x-1][y+2] * color < 0)
			{
				if (m->coef < -color * (*table)[x-1][y+2])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 1;
					m->y2 = y + 2;
					m->coef = -color * (*table)[x-1][y+2];
				}
			}

			//ataca left bottom
			if (x + 1 < 8 && y - 2 > -1 && (*table)[x+1][y-2] * color < 0)
			{
				if (m->coef < -color * (*table)[x+1][y-2])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 1;
					m->y2 = y - 2;
					m->coef = -color * (*table)[x+1][y-2];
				}
			}

			//ataca right bottom
			if (x + 1 < 8 && y + 2 < 8 && (*table)[x+1][y+2] * color < 0)
			{
				if (m->coef < -color * (*table)[x+1][y+2])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 1;
					m->y2 = y + 2;
					m->coef = -color * (*table)[x+1][y+2];
				}
			}

			//ataca bottom right
			if (x + 2 < 8 && y + 1 < 8 && (*table)[x+2][y+1] * color < 0)
			{
				if (m->coef < -color * (*table)[x+2][y+1])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 2;
					m->y2 = y + 1;
					m->coef = -color * (*table)[x+2][y+1];
				}
			}
				
			//ataca bottom left
			if (x + 2 < 8 && y - 1 < 8 && (*table)[x+2][y-1] * color < 0)
			{
				if (m->coef < -color * (*table)[x+2][y-1])
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 2;
					m->y2 = y - 1;
					m->coef = -color * (*table)[x+2][y-1];
				}
			}

			//muta top left
			if (x - 2 > -1 && y - 1 > -1 && (*table)[x-2][y-1] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 2;
					m->y2 = y - 1;
					m->coef = 0;
				}
			}

			//muta top right
			if (x - 2 > -1 && y + 1 < 8 && (*table)[x-2][y+1] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 2;
					m->y2 = y + 1;
					m->coef = 0;
				}
			}

			//muta left top
			if (x - 1 > -1 && y - 2 > -1 && (*table)[x-1][y-2] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 1;
					m->y2 = y - 2;
					m->coef = 0;
				}
			}

			//muta right top 
			if (x - 1 > -1 && y + 2 < 8 && (*table)[x-1][y+2] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x - 1;
					m->y2 = y + 2;
					m->coef = 0;
				}
			}

			//muta left bottom
			if (x + 1 < 8 && y - 2 > -1 && (*table)[x+1][y-2] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 1;
					m->y2 = y - 2;
					m->coef = 0;
				}
			}

			//muta right bottom
			if (x + 1 < 8 && y + 2 < 8 && (*table)[x+1][y+2] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 1;
					m->y2 = y + 2;
					m->coef = 0;
				}
			}

			//muta bottom right
			if (x + 2 < 8 && y + 1 < 8 && (*table)[x+2][y+1] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 2;
					m->y2 = y + 1;
					m->coef = 0;
				}
			}
				
			//muta bottom left
			if (x + 2 < 8 && y - 1 < 8 && (*table)[x+2][y-1] == 0)
			{
				if (m->coef < 0)
				{
					m->x1 = x;
					m->y1 = y;
					m->x2 = x + 2;
					m->y2 = y - 1;
					m->coef = 0;
				}
			}
			
				//cout << m->coef << '\n';
			return m;
		}
};