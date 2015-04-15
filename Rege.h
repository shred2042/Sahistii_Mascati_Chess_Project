#pragma once

#include "Piece.h"
class Rege :public Piece
{
	public:
		Rege(Position position, int color)
		{
			this->position = position;
			this->priority = REGE_PRIORITATE;
			this->color = color;
		}

		vector<Move>* move(vector<Piece*> *against, vector<Piece*> *own, int (*table)[8][8])
		{
			
			vector<Move> *moves = new vector<Move>();
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color =  getColor();

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

			//sus
			if ( x - 1 > -1 )
			{
				if ((*table)[x-1][y] * color < 0)
				{
					if (m->coef < -color * (*table)[x-1][y])
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
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y];
						(*table)[x-1][y] = mem;
					}
				}
				else if ((*table)[x-1][y] * color == 0)
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
							m->x2 = x -1;
							m->y2 = y;
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y];
						(*table)[x-1][y] = mem;
					}
				}
			}

			//jos
			if ( x + 1 < 8 )
			{
				if ((*table)[x+1][y] * color < 0)
				{
					if (m->coef < -color * (*table)[x+1][y])
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
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y];
						(*table)[x+1][y] = mem;
					}
				}
				else if ((*table)[x+1][y] * color == 0)
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
			}

			//stanga
			if ( y - 1 > -1 )
			{
				if ((*table)[x][y-1] * color < 0)
				{
					if (m->coef < -color * (*table)[x][y-1])
					{
						int mem = (*table)[x][y-1];
						(*table)[x][y-1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x;
						next.y = y - 1;
						setPosition(next);	
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y - 1;
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x][y-1];
						(*table)[x][y-1] = mem;
					}
				}
				else if ((*table)[x][y - 1] * color == 0)
				{
					if (m->coef < 0)
					{
						int mem = (*table)[x][y-1];
						(*table)[x][y-1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x;
						next.y = y - 1;
						setPosition(next);	
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y - 1;
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x][y-1];
						(*table)[x][y-1] = mem;
					}
				}
			}

			//dreapta
			if ( y + 1 < 8 )
			{
				if ((*table)[x][y+1] * color < 0)
				{
					if (m->coef < -color * (*table)[x][y+1])
					{
						int mem = (*table)[x][y+1];
						(*table)[x][y+1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x;
						next.y = y + 1;
						setPosition(next);	
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y + 1;
							m->coef = -color * mem;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x][y+1];
						(*table)[x][y+1] = mem;
					}
				}
				else if ((*table)[x][y + 1] * color == 0)
				{
					if (m->coef < 0)
					{
						int mem = (*table)[x][y+1];
						(*table)[x][y+1] = (*table)[x][y];
						(*table)[x][y] = 0;
						next.x = x;
						next.y = y + 1;
						setPosition(next);	
						if (!isInCheck(against, own, table))
						{
							setPosition(prev);
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y + 1;
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x][y+1];
						(*table)[x][y+1] = mem;
					}
				}
			}

			//dreapta sus
			if ( y + 1 < 8 && x - 1 > -1)
			{
				if ((*table)[x-1][y+1] * color < 0)
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
				else if ((*table)[x-1][y + 1] * color == 0)
				{
					if (m->coef < 0)
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
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y+1];
						(*table)[x-1][y+1] = mem;
					}
				}
			}

			//stanga sus
			if ( y - 1 > -1 && x - 1 > -1)
			{
				if ((*table)[x-1][y-1] * color < 0)
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
				else if ((*table)[x-1][y - 1] * color == 0)
				{
					if (m->coef < 0)
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
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x-1][y-1];
						(*table)[x-1][y-1] = mem;
					}
				}
			}

			//stanga jos
			if ( y - 1 > -1 && x + 1 < 8)
			{
				if ((*table)[x+1][y-1] * color < 0)
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
				else if ((*table)[x+1][y-1] * color == 0)
				{
					if (m->coef < 0)
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
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y-1];
						(*table)[x+1][y-1] = mem;
					}
				}
			}

			//dreapta jos
			if ( y + 1 < 8 && x + 1 < 8)
			{
				if ((*table)[x+1][y+1] * color < 0)
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
				else if ((*table)[x+1][y+1] * color == 0)
				{
					if (m->coef < 0)
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
							m->coef = 0;
						}
						setPosition(prev);
						(*table)[x][y] = (*table)[x+1][y+1];
						(*table)[x+1][y+1] = mem;
					}
				}
			}
			
			cout << getPosition()->x << " " << getPosition()->y << " "<< "Rege: " << m->coef << "\n" ;
			return moves;
		}

		Move* check_move(vector<Piece*> *against, int (*table)[8][8])
		{
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			int x, y;
			x = getPosition()->x;
			y = getPosition()->y;
			int color =  getColor();

			Move *m = new Move();
			m->coef = -1;
			m->x1 = 0;
			m->x2 = 0;
			m->y1 = 0;
			m->y2 = 0;

			//sus
			if ( x - 1 > -1 )
			{
				if ((*table)[x-1][y] * color < 0)
				{
					if (m->coef < -color * (*table)[x-1][y])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y;
						m->coef = -color * (*table)[x-1][y];
					}
				}
				else if ((*table)[x-1][y] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x -1;
						m->y2 = y;
						m->coef = 0;
					}
				}
			}

			//jos
			if ( x + 1 < 8 )
			{
				if ((*table)[x+1][y] * color < 0)
				{
					if (m->coef < -color * (*table)[x+1][y])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y;
						m->coef = -color * (*table)[x+1][y];
					}
				}
				else if ((*table)[x+1][y] * color == 0)
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
			}

			//stanga
			if ( y - 1 > -1 )
			{
				if ((*table)[x][y-1] * color < 0)
				{
					if (m->coef < -color * (*table)[x][y-1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x;
						m->y2 = y - 1;
						m->coef = -color * (*table)[x][y - 1];
					}
				}
				else if ((*table)[x][y - 1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x;
						m->y2 = y - 1;
						m->coef = 0;
					}
				}
			}

			//dreapta
			if ( y + 1 < 8 )
			{
				if ((*table)[x][y+1] * color < 0)
				{
					if (m->coef < -color * (*table)[x][y+1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x;
						m->y2 = y + 1;
						m->coef = -color * (*table)[x][y + 1];
					}
				}
				else if ((*table)[x][y + 1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x;
						m->y2 = y + 1;
						m->coef = 0;
					}
				}
			}

			//dreapta sus
			if ( y + 1 < 8 && x - 1 > -1)
			{
				if ((*table)[x-1][y+1] * color < 0)
				{
					if (m->coef < -color * (*table)[x-1][y+1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y + 1;
						m->coef = -color * (*table)[x-1][y + 1];
					}
				}
				else if ((*table)[x-1][y + 1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y + 1;
						m->coef = 0;
					}
				}
			}

			//stanga sus
			if ( y - 1 > -1 && x - 1 > -1)
			{
				if ((*table)[x-1][y-1] * color < 0)
				{
					if (m->coef < -color * (*table)[x-1][y-1])
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y - 1;
						m->coef = -color * (*table)[x-1][y - 1];
					}
				}
				else if ((*table)[x-1][y - 1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x - 1;
						m->y2 = y - 1;
						m->coef = 0;
					}
				}
			}

			//stanga jos
			if ( y - 1 > -1 && x + 1 < 8)
			{
				if ((*table)[x+1][y-1] * color < 0)
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
				else if ((*table)[x+1][y-1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y - 1;
						m->coef = 0;
					}
				}
			}

			//dreapta jos
			if ( y + 1 < 8 && x + 1 < 8)
			{
				if ((*table)[x+1][y+1] * color < 0)
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
				else if ((*table)[x+1][y+1] * color == 0)
				{
					if (m->coef < 0)
					{
						m->x1 = x;
						m->y1 = y;
						m->x2 = x + 1;
						m->y2 = y + 1;
						m->coef = 0;
					}
				}
			}
			
				//cout << m->coef << '\n';
			return m;
		}
};
