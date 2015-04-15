#pragma once

#include "Piece.h"
class Regina : public Piece
{
	public:
		Regina(Position position, int color)
		{
			this->position = position;
			this->priority = REGINA_PRIORITATE;
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
			for (int i = 1; i < 8 - x; i++)
			{
				if (x + i < 8)
				{
					if ((*table)[x+i][y]*color < 0)
					{		
						if (m->coef < -color * (*table)[x+i][y])
						{
							int mem = (*table)[x+i][y];
							(*table)[x+i][y] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y;
							setPosition(next);		
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y;
								m->coef = -color * mem;							
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y];
							(*table)[x+i][y] = mem;
						}
						break;
					}
					if ((*table)[x+i][y]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x+i][y];
							(*table)[x+i][y] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x + i;
							next.y = y;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x + i;
								m->y2 = y;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x+i][y];
							(*table)[x+i][y] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}

			//jos
			for (int i = 1; i <= x; i++)
			{
				if (x - i > -1)
				{
					if ((*table)[x-i][y]*color < 0)
					{		
						if (m->coef < -color * (*table)[x-i][y])
						{
							int mem = (*table)[x-i][y];
							(*table)[x-i][y] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y];
							(*table)[x-i][y] = mem;
						}
						break;
					}
					if ((*table)[x-i][y]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x-i][y];
							(*table)[x-i][y] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x - i;
							next.y = y;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x - i;
								m->y2 = y;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x-i][y];
							(*table)[x-i][y] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}
			

			//ataca stanga
			for (int i = 1; i <= y; i++)
			{
				if (y - i > -1)
				{
					if ((*table)[x][y-i]*color < 0)
					{		
						if (m->coef < -color * (*table)[x][y-i])
						{
							int mem = (*table)[x][y-i];
							(*table)[x][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x;
							next.y = y - i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x;
								m->y2 = y - i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x][y-i];
							(*table)[x][y-i] = mem;
						}
						break;
					}
					if ((*table)[x][y-i]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							
							int mem = (*table)[x][y-i];
							(*table)[x][y-i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x;
							next.y = y - i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x;
								m->y2 = y - i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x][y-i];
							(*table)[x][y-i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}
			
			//dreapta
			for (int i = 1; i < 8 - y; i++)
			{
				if (y + i < 8)
				{
					if ((*table)[x][y+i]*color < 0)
					{		
						if (m->coef < -color * (*table)[x][y+i])
						{
							int mem = (*table)[x][y+i];
							(*table)[x][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x;
								m->y2 = y + i;
								m->coef = -color * mem;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x][y+i];
							(*table)[x][y+i] = mem;
						}
						break;
					}
					if ((*table)[x][y+i]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							int mem = (*table)[x][y+i];
							(*table)[x][y+i] = (*table)[x][y];
							(*table)[x][y] = 0;
							next.x = x;
							next.y = y + i;
							setPosition(next);
							if (!isInCheck(against, own, table))
							{
								setPosition(prev);
								m->x1 = x;
								m->y1 = y;
								m->x2 = x;
								m->y2 = y + i;
								m->coef = 0;
							}
							setPosition(prev);
							(*table)[x][y] = (*table)[x][y+i];
							(*table)[x][y+i] = mem;
						}
					}
				}
				else
				{
					break;
				}
			}			

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
			cout << getPosition()->x << " " << getPosition()->y << " "<< "Regina: " << m->coef << "\n" ;
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
			for (int i = 1; i < 8 - x; i++)
			{
				if (x + i < 8)
				{
					if ((*table)[x+i][y]*color < 0)
					{		
						if (m->coef < -color * (*table)[x+i][y])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x + i;
							m->y2 = y;
							m->coef = -color * (*table)[x+i][y];
						}
						break;
					}
					if ((*table)[x+i][y]*color > 0)
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
							m->y2 = y;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}

			//jos
			for (int i = 1; i <= x; i++)
			{
				if (x - i > -1)
				{
					if ((*table)[x-i][y]*color < 0)
					{		
						if (m->coef < -color * (*table)[x-i][y])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x - i;
							m->y2 = y;
							m->coef = -color * (*table)[x-i][y];
						}
						break;
					}
					if ((*table)[x-i][y]*color > 0)
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
							m->y2 = y;
							m->coef = 0;
						}
					}
				}
				else
				{
					break;
				}
			}
			

			//ataca stanga
			for (int i = 1; i <= y; i++)
			{
				if (y - i > -1)
				{
					if ((*table)[x][y-i]*color < 0)
					{		
						if (m->coef < -color * (*table)[x][y-i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y - i;
							m->coef = -color * (*table)[x][y-i];
						}
						break;
					}
					if ((*table)[x][y-i]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
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
			
			//dreapta
			for (int i = 1; i < 8 - y; i++)
			{
				if (y + i < 8)
				{
					if ((*table)[x][y+i]*color < 0)
					{		
						if (m->coef < -color * (*table)[x][y+i])
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
							m->y2 = y + i;
							m->coef = -color * (*table)[x][y+i];
						}
						break;
					}
					if ((*table)[x][y+i]*color > 0)
					{
						break;
					}
					else
					{
						if (m->coef < 0)
						{
							m->x1 = x;
							m->y1 = y;
							m->x2 = x;
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
