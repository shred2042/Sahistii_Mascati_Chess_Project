#pragma once

#include "Piece.h"

class Nebun : public Piece
{		
	public:
		Nebun(Position position, int color)
		{
			this->position = position;
			priority = NEBUN_PRIORITATE;
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

			//ia stanga sus
			for (int i = 1; i <= x && i <= y; i++)
			{
				if ( (x - i >= 0) && (y - i >= 0) )
				{
					if ((*table)[x-i][y-i] * color < 0)
					{
						if (m->coef < -color * (*table)[x-i][y-i])
						{
							int mem = (*table)[x-i][y-i];
							(*table)[x-i][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y - i;
							setPosition(next);	
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y - i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y-i];
							(*table)[x-i][y-i] = mem;
							
						}
						break;
					}
					if ((*table)[x-i][y-i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x-i][y-i];
							(*table)[x-i][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y - i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y - i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y-i];
							(*table)[x-i][y-i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}
			
			//ia dreapta sus
			for (int i = 1; i <= x && i < 8-y; i++)
			{
				if ( (x - i >= 0) && (y + i < 8) )
				{
					if ((*table)[x-i][y+i] * color < 0)
					{
						if (m->coef < -color * (*table)[x-i][y+i])
						{
							int mem = (*table)[x-i][y+i];
							(*table)[x-i][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y + i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y+i];
							(*table)[x-i][y+i] = mem;
						}
						break;
					}
					if ((*table)[x-i][y+i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x-i][y+i];
							(*table)[x-i][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y + i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y+i];
							(*table)[x-i][y+i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}
			
			//ia dreapta jos
			for (int i = 1; i < 8 - x && i < 8-y; i++)
			{
				if ( (x + i < 8) && (y + i < 8) )
				{
					if ((*table)[x+i][y+i] * color < 0)
					{
						if (m->coef < -color * (*table)[x+i][y+i])
						{
							int mem = (*table)[x+i][y+i];
							(*table)[x+i][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y + i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y+i];
							(*table)[x+i][y+i] = mem;
						}
						break;
					}
					if ((*table)[x+i][y+i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x+i][y+i];
							(*table)[x+i][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y + i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y+i];
							(*table)[x+i][y+i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}

			//ia stanga jos
			for (int i = 1; i < 8 - x && i <= y; i++)
			{
				if ( (x + i < 8) && (y - i >= 0) )
				{
					if ((*table)[x+i][y-i] * color < 0)
					{
						if (m->coef < -color * (*table)[x+i][y-i])
						{
							int mem = (*table)[x+i][y-i];
							(*table)[x+i][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y - i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y - i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y-i];
							(*table)[x+i][y-i] = mem;
						}
						break;
					}
					if ((*table)[x+i][y-i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x+i][y-i];
							(*table)[x+i][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y - i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y - i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y-i];
							(*table)[x+i][y-i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}
			cout << getPosition()->x << " " << getPosition()->y << " " << "Nebun: " << m->coef << "\n" ;
			return moves;
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

			//ia stanga sus
			for (int i = 1; i <= x && i <= y; i++)
			{
				if ( (x - i >= 0) && (y - i >= 0) )
				{
					if ((*table)[x-i][y-i] * color < 0)
					{
						if (m->coef < -color * (*table)[x-i][y-i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - i;
							m->y2 = y - i;
							m->coef = -color * (*table)[x-i][y-i];
						}
						break;
					}
					if ((*table)[x-i][y-i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - i;
							m->y2 = y - i;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}
			
			//ia dreapta sus
			for (int i = 1; i <= x && i < 8-y; i++)
			{
				if ( (x - i >= 0) && (y + i < 8) )
				{
					if ((*table)[x-i][y+i] * color < 0)
					{
						if (m->coef < -color * (*table)[x-i][y+i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - i;
							m->y2 = y + i;
							m->coef = -color * (*table)[x-i][y+i];
						}
						break;
					}
					if ((*table)[x-i][y+i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - i;
							m->y2 = y + i;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}
			
			//ia dreapta jos
			for (int i = 1; i < 8 - x && i < 8-y; i++)
			{
				if ( (x + i < 8) && (y + i < 8) )
				{
					if ((*table)[x+i][y+i] * color < 0)
					{
						if (m->coef < -color * (*table)[x+i][y+i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + i;
							m->y2 = y + i;
							m->coef = -color * (*table)[x+i][y+i];
						}
						break;
					}
					if ((*table)[x+i][y+i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + i;
							m->y2 = y + i;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}

			//ia stanga jos
			for (int i = 1; i < 8 - x && i <= y; i++)
			{
				if ( (x + i < 8) && (y - i >= 0) )
				{
					if ((*table)[x+i][y-i] * color < 0)
					{
						if (m->coef < -color * (*table)[x+i][y-i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + i;
							m->y2 = y - i;
							m->coef = -color * (*table)[x+i][y-i];
						}
						break;
					}
					if ((*table)[x+i][y-i] * color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + i;
							m->y2 = y - i;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}
			
				//cout << m->coef << '\n';
			return m;
		}
};
