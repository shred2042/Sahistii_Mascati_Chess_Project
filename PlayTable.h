/**
	* Tabla propriu-zisa de sah	
**/
#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "Util.h"
#include "Pion.h"
#include "Cal.h"
#include "Nebun.h"
#include "Tura.h"
#include "Rege.h"
#include "Regina.h"


struct Save
{
	int x1, y1, x2, y2;
	int taken;
	int moved;
	bool taken_color_is_white;
};



class PlayTable
{	
	private:
		int table[8][8];
		vector<Piece*> white;
		vector<Piece*> black;
		int color;
		
	public:
		PlayTable()
		{
			cout << "feature colors=1\n";
			color = 2;
			/** Umple cu 0 **/
			for (int i = 2 ; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					table[i][j] = 0;
				}

			}
			/** Umplem cu pioni **/
			for (int i = 0;  i < 8; i++)
			{
				table[1][i] = PION_PRIORITATE;
				table[6][i] = -PION_PRIORITATE;
			}
			/** BAGAM manual piesele **/
			/** TURELE **/
			table[0][0] = TURA_PRIORITATE;
			table[0][7] = TURA_PRIORITATE;
			table[7][0] = -TURA_PRIORITATE;
			table[7][7] = -TURA_PRIORITATE;		

	
			/** CAII **/
			table[0][1] = CAL_PRIORITATE;
			table[0][6] = CAL_PRIORITATE;
			table[7][1] = -CAL_PRIORITATE;
			table[7][6] = -CAL_PRIORITATE;		

			/** DEZAXATII **/
			table[0][2] = NEBUN_PRIORITATE;
			table[0][5] = NEBUN_PRIORITATE;
			table[7][2] = -NEBUN_PRIORITATE;
			table[7][5] = -NEBUN_PRIORITATE;

			/** Regina **/
			table[0][3] = REGINA_PRIORITATE;
			table[7][3] = -REGINA_PRIORITATE;

			/** Rege **/
			table[0][4] = REGE_PRIORITATE;
			table[7][4] = -REGE_PRIORITATE;

			/** Formam vectorii de piese **/

			/** White **/
			Position p;
			p.x = 6;
			p.y = 0;				
			white.push_back(new Pion(p, WHITE));
			
			p.y = 1;			
			white.push_back(new Pion(p, WHITE));

			p.y = 2;
			white.push_back(new Pion(p, WHITE));

			p.y = 3;
			white.push_back(new Pion(p, WHITE));

			p.y = 4;
			white.push_back(new Pion(p, WHITE));

			p.y = 5;
			white.push_back(new Pion(p, WHITE));

			p.y = 6;
			white.push_back(new Pion(p, WHITE));

			p.y = 7;
			white.push_back(new Pion(p, WHITE));

			//Setam Turele albe
			p.x = 7;
			p.y = 0;
			white.push_back(new Tura(p, WHITE));

			p.y = 7;
			white.push_back(new Tura(p, WHITE));

			//Setam Caii albi
			p.y = 1;
			white.push_back(new Cal(p, WHITE));

			p.y = 6;
			white.push_back(new Cal(p, WHITE));

			//Setam Nebunii albi
			p.y = 2;
			white.push_back(new Nebun(p, WHITE));

			p.y = 5;
			white.push_back(new Nebun(p, WHITE));

			//Setam Regina
			p.y = 3;
			white.push_back(new Regina(p, WHITE));

			//Setam Regele
			p.y = 4;
			white.push_back(new Rege(p, WHITE));


			
			/** Black **/
			/*p.x = 0;
			p.y = 0;
			black.push_back(new Tura(p, BLACK));

			p.x = 0;
			p.y = 2;
			black.push_back(new Nebun(p, BLACK));

			p.x = 1;
			p.y = 0;
			black.push_back(new Pion(p, BLACK));

			p.y = 1;
			black.push_back(new Pion(p, BLACK));

			p.y = 2;
			black.push_back(new Pion(p, BLACK));*/

			p.x = 1;
			p.y = 0;
			black.push_back(new Pion(p, BLACK));

			p.y = 1;
			black.push_back(new Pion(p, BLACK));

			p.y = 2;
			black.push_back(new Pion(p, BLACK));

			p.y = 3;
			black.push_back(new Pion(p, BLACK));

			p.y = 4;
			black.push_back(new Pion(p, BLACK));

			p.y = 5;
			black.push_back(new Pion(p, BLACK));

			p.y = 6;
			black.push_back(new Pion(p, BLACK));

			p.y = 7;
			black.push_back(new Pion(p, BLACK));

			//Setam Turele negre
			p.x = 0;
			p.y = 0;
			black.push_back(new Tura(p, BLACK));

			p.y = 7;
			black.push_back(new Tura(p, BLACK));

			//Setam Caii negri
			p.y = 1;
			black.push_back(new Cal(p, BLACK));

			p.y = 6;
			black.push_back(new Cal(p, BLACK));

			//Setam Nebunii negri
			p.y = 2;
			black.push_back(new Nebun(p, BLACK));

			p.y = 5;
			black.push_back(new Nebun(p, BLACK));

			//Setam Regina neagra
			p.y = 3;
			black.push_back(new Regina(p, BLACK));

			//Setam Regele negru
			p.y = 4;
			black.push_back(new Rege(p, BLACK));

			/*cout << "WHITES:\n";
			for (unsigned int i = 0; i < white.size(); i++)
			{
				cout << i << ": "<< white[i]->getPosition()->x << " " << white[i]->getPosition()->y << " with priority " << white[i]->getPriority() << "\n";
			}

			cout << "BLACKS:\n";
			for (unsigned int i = 0; i < black.size(); i++)
			{
				cout << i << ": "<< black[i]->getPosition()->x << " " << black[i]->getPosition()->y << " with priority " << black[i]->getPriority() << "\n";
			}*/

		}

		void print_pieces()
		{
			cout << "WHITES:\n";
			for (unsigned int i = 0; i < white.size(); i++)
			{
				cout << i << ": "<< white[i]->getPosition()->x << " " << white[i]->getPosition()->y << " with priority " << white[i]->getPriority() << "\n";
			}

			cout << "BLACKS:\n";
			for (unsigned int i = 0; i < black.size(); i++)
			{
				cout << i << ": "<< black[i]->getPosition()->x << " " << black[i]->getPosition()->y << " with priority " << black[i]->getPriority() << "\n";
			}
		}

		void update(vector<Piece*> *v, int x1, int y1, int x2, int y2)
		{
			for (unsigned int i = 0; i < v->size(); i++)
			{
				if ((*v)[i]->getPosition()->x == x1 && (*v)[i]->getPosition()->y == y1)
				{
					Position p;
					p.x = x2;
					p.y = y2;
					(*v)[i]->setPosition(p);
					return;
				}
			}
		}

		void restore_vector(vector<Piece*> *v, int priority, bool color, Position p, bool add, Position old)
		{
			if (add)
			{
				if (priority == PION_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Pion(p, WHITE));
					}
					else
					{
						v->push_back(new Pion(p, BLACK));
					}
				}
				if (priority == CAL_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Cal(p, WHITE));
					}
					else
					{
						v->push_back(new Cal(p, BLACK));
					}
				}
				if (priority == NEBUN_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Nebun(p, WHITE));
					}
					else
					{
						v->push_back(new Nebun(p, BLACK));
					}
				}
				if (priority == TURA_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Tura(p, WHITE));
					}
					else
					{
						v->push_back(new Tura(p, BLACK));
					}
				}
				if (priority == REGE_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Rege(p, WHITE));
					}
					else
					{
						v->push_back(new Rege(p, BLACK));
					}
				}
				if (priority == REGINA_PRIORITATE)
				{
					if (color)
					{
						v->push_back(new Regina(p, WHITE));
					}
					else
					{
						v->push_back(new Regina(p, BLACK));
					}
				}
			}
			else
			{
				for (unsigned int i = 0; i < v->size(); i++)
				{
					if ((*v)[i]->getPosition()->x == p.x && (*v)[i]->getPosition()->y == p.y)
					{
						(*v)[i]->setPosition(old);
						//cout << s.moved->getColor() << ' ' << s.moved->getPosition() << '\n';
						break;
					}
				}
			}
		}

		//functia de evaluare 
		//se bazeaza pe suma valorilor pieselor (stiu, stiu...nu puteam gasi ceva mai simplu...)
		Move eval(bool is_white)
		{
			int coef = 0;
			if (is_white)
			{
				for (unsigned int i = 0; i < white.size(); i++)
				{
					coef += white[i]->getPriority();
				}
				for (unsigned int i = 0; i < black.size(); i++)
				{
					coef -= black[i]->getPriority();
				}
			}
			else
			{
				for (unsigned int i = 0; i < white.size(); i++)
				{
					coef -= white[i]->getPriority();
				}
				for (unsigned int i = 0; i < black.size(); i++)
				{
					coef += black[i]->getPriority();
				}
			}
			Move m;
			m.coef = coef;
			return m;
		}

		//algoritmul alfa beta
		Move alfa_beta_max(bool is_white, int alfa, int beta, int depth) 
		{
			Move m;
			if (depth == 0) 
			{
				return eval(true);
			}
			if (is_white)
			{
				for (unsigned int i = 0; i < white.size(); i++) 
				{
					vector<Move> *moves = white[i]->move(&black, &white, &table);
					for (unsigned int j = 0; j < moves->size(); j++)
					{
						//make move
						Save save;
						save = store(&((*moves)[j]));

						//recurse
						m = alfa_beta_min(!is_white, alfa, beta, depth - 1 );
						restore(save);
						if( m.coef >= beta )
						{
							m.coef = beta;
							return m;  
						}
						if( m.coef > alfa )
						{
							alfa = m.coef; 
						}
					}
				}
			}
			else
			{
				for (unsigned int i = 0; i < black.size(); i++) 
				{
					vector<Move> *moves = black[i]->move(&white, &black, &table);
					for (unsigned int j = 0; j < moves->size(); j++)
					{
						//make move
						Save save;
						save = store(&((*moves)[j]));

						//recurse
						m = alfa_beta_min(!is_white, alfa, beta, depth - 1 );
						restore(save);
						if( m.coef >= beta )
						{
							Move m;
							m.coef = beta;
							return m;  
						}
						if( m.coef > alfa )
						{
							alfa = m.coef; 
						}
					}
				}
			}
			m.coef = alfa;
			return m;
		}

		Move alfa_beta_min(bool is_white, int alfa, int beta, int depth) 
		{
			Move m;
			if (depth == 0) 
			{
				m = eval(true);
				m.coef = -m.coef;
				return m;
			}
			if (is_white)
			{
				for (unsigned int i = 0; i < white.size(); i++) 
				{
					vector<Move> *moves = white[i]->move(&black, &white, &table);
					for (unsigned int j = 0; j < moves->size(); j++)
					{
						//make move
						Save save;
						save = store(&((*moves)[j]));

						//recurse
						m = alfa_beta_max(!is_white, alfa, beta, depth - 1 );
						restore(save);
						if( m.coef <= alfa )
						{
							m.coef = alfa;
							return m;  
						}
						if( m.coef < beta )
						{
							beta = m.coef; 
						}
					}
				}
			}
			else
			{
				for (unsigned int i = 0; i < black.size(); i++) 
				{
					vector<Move> *moves = black[i]->move(&white, &black, &table);
					for (unsigned int j = 0; j < moves->size(); j++)
					{
						//make move
						Save save;
						save = store(&((*moves)[j]));

						//recurse
						m = alfa_beta_max(!is_white, alfa, beta, depth - 1 );
						restore(save);
						if( m.coef <= alfa )
						{
							m.coef = alfa;
							return m;  
						}
						if( m.coef < beta )
						{
							beta = m.coef; 
						}
					}
				}
			}
			m.coef = beta;
			return m;  
		}
 

		Save store(Move* m)
		{
			//cout << "storing started...\n";
			Save s;
			s.x1 = m->x1;
			s.x2 = m->x2;
			s.y1 = m->y1;
			s.y2 = m->y2;
			s.taken = 0;			

			if (table[s.x1][s.y1] < 0)
			{
				for (unsigned int i = 0; i < white.size(); i++)
				{
					if (white[i]->getPosition()->x == s.x1 && white[i]->getPosition()->y == s.y1)
					{
						s.moved = -white[i]->getPriority();
						//cout << s.moved->getColor() << ' ' << s.moved->getPosition() << '\n';
						break;
					}
				}
			}
			else
			{
				for (unsigned int i = 0; i < black.size(); i++)
				{
					if (black[i]->getPosition()->x == s.x1 && black[i]->getPosition()->y == s.y1)
					{
						s.moved = black[i]->getPriority();
						break;
					}
				}
			}

			//daca miscarea duce la micsorarea numarului de piese
			if (table[s.x2][s.y2] != 0)
			{
				if (table[s.x2][s.y2] < 0)
				{
					for (unsigned int i = 0; i < white.size(); i++)
					{
						if (white[i]->getPosition()->x == s.x2 && white[i]->getPosition()->y == s.y2)
						{
							s.taken_color_is_white = true;
							//s.taken = new Piece();
							s.taken = -white[i]->getPriority();
							//white.erase(white.begin() + i);
							break;
						}
					}
				}
				else
				{
					for (unsigned int i = 0; i < black.size(); i++)
					{
						if (black[i]->getPosition()->x == s.x2 && black[i]->getPosition()->y == s.y2)
						{
							s.taken_color_is_white = false;
							s.taken = black[i]->getPriority();
							//black.erase(black.begin() + i);
							break;
						}
					}
				}
			}
			//facem miscarea propriu-zisa
			//cout << "storing ended...\n";
			move(m->x1, m->y1, m->x2, m->y2);
			return s;
		}

		void restore(Save s)
		{
			Position p;
			//cout << "Restoring started...\n";
			if (s.taken != 0)
			{				
				cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
				//cout << "There was a piece taken. Restoring it...\n";
				if (s.taken_color_is_white)
				{
					p.x = s.x2;
					p.y = s.y2;
					restore_vector(&white, s.taken, true, p, true, p);
					Position old;
					old.x = s.x1;
					old.y = s.y1;
					restore_vector(&black, s.moved, false, p, false, old);
				}
				else
				{
					p.x = s.x2;
					p.y = s.y2;
					restore_vector(&black, s.taken, false, p, true, p);
					Position old;
					old.x = s.x1;
					old.y = s.y1;
					restore_vector(&white, s.moved, true, p, false, old);
				}
				table[s.x1][s.y1] = s.moved;
				table[s.x2][s.y2] = s.taken;
				
			}
			else
			{
				//cout << "There were no pieces taken...\n";
				table[s.x1][s.y1] = s.moved;
				table[s.x2][s.y2] = 0;
				p.x = s.x2;
				p.y = s.y2;		
				Position old;
				old.x = s.x1;
				old.y = s.y1;
				if (s.moved < 0)
				{
					restore_vector(&white, s.moved, true, p, false, old);
				}
				else
				{
					restore_vector(&black, s.moved, false, p, false, old);
				}
				/*if (s.taken != NULL)
				{
					p.x = s.x2;
					p.y = s.y2;
					s.taken->setPosition(p);
				}*/
				//cout << "Restored table!\n";
			}			
			//cout << "Restoring started...\n";
		}

		Move* maxWhite(int depth, bool add)
		{
			Move *m = &alfa_beta_max(true, INF, -INF, depth);
			return m;
			/*Move *max = new Move();
			if (depth != 0)
			{
				max->coef = -1;
				for (unsigned int i = 0; i < white.size(); i++)
				{				
					Move *temp;
					Move *adv_move;
					Save save;
					temp = white[i]->move(&black, &white, &table);					
					if (temp->coef != -1)
					{
						save = store(temp);
						adv_move = maxBlack(depth - 1, !add);
						if (add)
						{
							temp->coef += adv_move->coef;
						}
						else
						{
							temp->coef -= adv_move->coef;
						}
						restore(save);
					}
				

					if (temp->coef > max->coef)
					{
						max->coef = temp->coef;
						max->x1 = temp->x1;
						max->x2 = temp->x2;
						max->y1 = temp->y1;
						max->y2 = temp->y2;
					}
				}
				if (max->coef == -1)
				{
					max->coef = -INF;
				}				
			}
			else
			{
				max->coef = 0;
			}
			return max;*/
		}
		
		//functia ce ia mutarea cea mai buna de la negru (foloseste negamax)
		Move* maxBlack(int depth, bool add)
		{		
			Move *m = &alfa_beta_max(false, INF, -INF, depth);
			return m;
			/*Move *max = new Move();
			if (depth != 0)
			{
				max->coef = -1;
				for (unsigned int i = 0; i < black.size(); i++)
				{				
					Move *temp;
					Move *adv_move;
					Save save;
					temp = black[i]->move(&white, &black, &table);
					if (temp->coef != -1)
					{
						save = store(temp);
						adv_move = maxWhite(depth - 1, !add);
						if (add)
						{
							temp->coef += adv_move->coef;
						}
						else
						{
							temp->coef -= adv_move->coef;
						}
						restore(save);
					}
				

					if (temp->coef > max->coef)
					{
						max->coef = temp->coef;
						max->x1 = temp->x1;
						max->x2 = temp->x2;
						max->y1 = temp->y1;
						max->y2 = temp->y2;
					}
				}
				if (max->coef == -1)
				{
					max->coef = -INF;
				}				
			}
			else
			{
				max->coef = 0;
			}
			return max;*/
		}

		void moveWhite(int depth)
		{			
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			if (white.empty())
			{
				cout << "resign\n";
			}
			Move *max;// = new Move();
			
			/*for (unsigned int i = 0; i < white.size(); i++)
			{				
				Move *temp;
				temp = white[i]->move(&black, &white, &table);

				if (temp->coef > max->coef)
				{
					max->coef = temp->coef;
					max->x1 = temp->x1;
					max->x2 = temp->x2;
					max->y1 = temp->y1;
					max->y2 = temp->y2;
				}
			}*/
			max = maxWhite(depth, true);
			if (max->coef <= -INF)
			{
				cout << "resign\n";
			}
			else
			{
				move(max->x1, max->y1, max->x2, max->y2);
				cout << "move " << litere[max->y1] << 8 - max->x1 << litere[max->y2] << 8 - max->x2 << "\n";
			}
			print();
		}

		void moveBlack(int depth)
		{			
			char litere[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
			if (black.empty())
			{
				cout << "resign\n";
			}
			Move *max;// = new Move();
			
			/*for (unsigned int i = 0; i < white.size(); i++)
			{				
				Move *temp;
				temp = white[i]->move(&black, &white, &table);

				if (temp->coef > max->coef)
				{
					max->coef = temp->coef;
					max->x1 = temp->x1;
					max->x2 = temp->x2;
					max->y1 = temp->y1;
					max->y2 = temp->y2;
				}
			}*/
			max = maxBlack(depth, true);
			if (max->coef <= -INF)
			{
				cout << "resign\n";
			}
			else
			{
				move(max->x1, max->y1, max->x2, max->y2);
				cout << "move " << litere[max->y1] << 8 - max->x1 << litere[max->y2] << 8 - max->x2 << "\n";
			}
			print();
		}

		void del(vector<Piece*> *v, int x, int y)
		{
			for (unsigned int i = 0; i < v->size(); i++)
			{
				if ((*v)[i]->getPosition()->x == x && (*v)[i]->getPosition()->y == y)
				{
					v->erase(v->begin() + i);
					break;
				}
			}
		}

		void move(int x1, int y1, int x2, int y2)
		{
			//cout << x1 << " " << y1 << "    " << x2 << " " << y2 << "\n";
			if (table[x2][y2] * table[x1][y1] == 0)
			{
				if (table[x1][y1] < 0)
				{
					update(&white, x1, y1, x2, y2);
				}
				else
				{
					update(&black, x1, y1, x2, y2);
				}
				table[x2][y2] = table[x1][y1];
				table[x1][y1] = 0;
			}
			else if (table[x2][y2] * table[x1][y1] < 0)
			{
				//cout << "wat\n";
				if (table[x1][y1] < 0)
				{
					//sterge elementul din vector
					del(&black, x2, y2);
					update(&white, x1, y1, x2, y2);
					table[x2][y2] = table[x1][y1];
					table[x1][y1] = 0;
					//print_pieces();
				}
				else
				{
					del(&white, x2, y2);					
					update(&black, x1, y1, x2, y2);
					table[x2][y2] = table[x1][y1];
					table[x1][y1] = 0;
					//print_pieces();
				}
			}
		}

		void setColor(int x)
		{
			color = x;
		}

		int getColor()
		{
			return color;
		}


		void print()
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << table[i][j] << " ";
				}
				cout << "\n";
			}
		}

		void setTable(int **m)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					table[i][j] = m[i][j];
				}
			}
		}

		void testNebun()
		{
			int **m;
			m = new int*[8];
			for (int i = 0; i < 8; i++)
			{
				m[i] = new int[8];
			}
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					m[i][j] = 0;
				}
			}
			//TEST TABLA GOALA
			/*white.clear();
			black.clear();
			setTable(m);
			moveWhite();
			setTable(m);
			moveBlack();

			Position p;
			//TEST NEBUN

			//test diagonala principala
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 3;
			p.y = 3;
			black.push_back(new Nebun(p, BLACK));
			m[4][4] = -NEBUN_PRIORITATE;
			m[3][3] = NEBUN_PRIORITATE;
			setTable(m);
			moveWhite();			
			white.clear();
			black.clear();
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 3;
			p.y = 3;
			m[4][4] = -NEBUN_PRIORITATE;
			m[3][3] = NEBUN_PRIORITATE;
			black.push_back(new Nebun(p, BLACK));
			setTable(m);
			moveBlack();
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[3][3] = 0;

			//test diagonala secundara
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 5;
			p.y = 3;
			black.push_back(new Nebun(p, BLACK));
			m[4][4] = -NEBUN_PRIORITATE;
			m[5][3] = NEBUN_PRIORITATE;
			setTable(m);
			moveWhite();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[5][3] = 0;
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 5;
			p.y = 3;
			m[4][4] = -NEBUN_PRIORITATE;
			m[5][3] = NEBUN_PRIORITATE;
			black.push_back(new Nebun(p, BLACK));
			setTable(m);
			moveBlack();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[5][3] = 0;

			//distanta mai mare diag sec
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 6;
			p.y = 2;
			black.push_back(new Nebun(p, BLACK));
			m[4][4] = -NEBUN_PRIORITATE;
			m[6][2] = NEBUN_PRIORITATE;
			setTable(m);
			moveWhite();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[6][2] = 0;
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 6;
			p.y = 2;
			m[4][4] = -NEBUN_PRIORITATE;
			m[6][2] = NEBUN_PRIORITATE;
			black.push_back(new Nebun(p, BLACK));
			setTable(m);
			moveBlack();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[6][2] = 0;

			//distanta mai mare diag princ
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 2;
			p.y = 2;
			black.push_back(new Nebun(p, BLACK));
			m[4][4] = -NEBUN_PRIORITATE;
			m[2][2] = NEBUN_PRIORITATE;
			setTable(m);
			moveWhite();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[2][2] = 0;
			p.x = 4;
			p.y = 4;
			white.push_back(new Nebun(p, WHITE));
			p.x = 2;
			p.y = 2;
			m[4][4] = -NEBUN_PRIORITATE;
			m[2][2] = NEBUN_PRIORITATE;
			black.push_back(new Nebun(p, BLACK));
			setTable(m);
			moveBlack();			
			white.clear();
			black.clear();
			m[4][4] = 0;
			m[2][2] = 0;*/


			for (int i = 0; i < 8; i++)
			{
				delete m[i];
			}
			delete m;
		}

		void testSah()
		{
			int **m;
			m = new int*[8];
			for (int i = 0; i < 8; i++)
			{
				m[i] = new int[8];
			}
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					m[i][j] = 0;
				}
			}
			Position p;
			clearTable();
			//TEST TABLA GOALA
			/*white.clear();
			black.clear();
			setTable(m);
			moveWhite();
			setTable(m);
			moveBlack();

			
			//WHITE REGE
			p.x = 4;
			p.y = 4;
			white.push_back(new Rege(p, WHITE));
			p.x = 2;
			p.y = 4;
			black.push_back(new Tura(p,BLACK));
			table[4][4] = -REGE_PRIORITATE;
			table[2][4] = TURA_PRIORITATE;
			moveWhite();
			clearTable();

			p.x = 4;
			p.y = 4;
			white.push_back(new Rege(p, WHITE));
			p.x = 4;
			p.y = 2;
			black.push_back(new Tura(p,BLACK));
			table[4][4] = -REGE_PRIORITATE;
			table[4][2] = TURA_PRIORITATE;
			moveWhite();			
			clearTable();

			p.x = 4;
			p.y = 4;
			white.push_back(new Rege(p, WHITE));
			p.x = 4;
			p.y = 2;
			black.push_back(new Tura(p,BLACK));
			p.x = 2;
			p.y = 4;
			black.push_back(new Tura(p, BLACK));
			table[2][4] = TURA_PRIORITATE;
			table[4][4] = -REGE_PRIORITATE;
			table[4][2] = TURA_PRIORITATE;
			moveWhite();			
			clearTable();

			//BLACK REGE
			p.x = 4;
			p.y = 4;
			black.push_back(new Rege(p, BLACK));
			p.x = 2;
			p.y = 4;
			white.push_back(new Tura(p,WHITE));
			table[4][4] = REGE_PRIORITATE;
			table[2][4] = -TURA_PRIORITATE;
			moveBlack();
			clearTable();

			p.x = 4;
			p.y = 4;
			black.push_back(new Rege(p, BLACK));
			p.x = 4;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));
			table[4][4] = REGE_PRIORITATE;
			table[4][2] = -TURA_PRIORITATE;
			moveBlack();			
			clearTable();

			p.x = 4;
			p.y = 4;
			black.push_back(new Rege(p, BLACK));
			p.x = 4;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));
			p.x = 2;
			p.y = 4;
			white.push_back(new Tura(p, WHITE));
			table[2][4] = -TURA_PRIORITATE;
			table[4][4] = REGE_PRIORITATE;
			table[4][2] = -TURA_PRIORITATE;
			moveBlack();			
			clearTable();

			//MAT
			p.x = 4;
			p.y = 4;
			black.push_back(new Rege(p, BLACK));
			p.x = 4;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));
			p.x = 3;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));
			p.x = 5;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));
			table[3][2] = -TURA_PRIORITATE;
			table[4][4] = REGE_PRIORITATE;
			table[4][2] = -TURA_PRIORITATE;			
			table[5][2] = -TURA_PRIORITATE;
			moveBlack();			
			clearTable();

			p.x = 4;
			p.y = 4;
			white.push_back(new Rege(p, WHITE));
			p.x = 4;
			p.y = 2;
			black.push_back(new Tura(p, BLACK));
			p.x = 3;
			p.y = 2;
			black.push_back(new Tura(p, BLACK));
			p.x = 5;
			p.y = 2;
			black.push_back(new Tura(p, BLACK));
			table[3][2] = TURA_PRIORITATE;
			table[4][4] = -REGE_PRIORITATE;
			table[4][2] = TURA_PRIORITATE;			
			table[5][2] = TURA_PRIORITATE;
			moveWhite();			
			clearTable();


			//CU PIESE ADITIONALE
			//cu nebun
			p.x = 4;
			p.y = 3;
			black.push_back(new Nebun(p, BLACK));
			p.x = 4;
			p.y = 4;
			black.push_back(new Rege(p, BLACK));
			p.x = 4;
			p.y = 2;
			white.push_back(new Tura(p, WHITE));			
			table[4][2] = -TURA_PRIORITATE;
			table[4][4] = REGE_PRIORITATE;
			table[4][3] = NEBUN_PRIORITATE;
			moveBlack();			
			clearTable();*/

			//pierde piesa ca sa iesi din sah
			/*p.x = 7;
			p.y = 2;
			white.push_back(new Pion(p, WHITE));
			p.x = 7;
			p.y = 3;
			white.push_back(new Rege(p, WHITE));
			p.x = 7;
			p.y = 4;
			white.push_back(new Pion(p, WHITE));
			p.x = 6;
			p.y = 3;
			white.push_back(new Pion(p, WHITE));
			p.x = 6;
			p.y = 2;
			white.push_back(new Pion(p, WHITE));
			p.x = 5;
			p.y = 5;
			black.push_back(new Nebun(p, BLACK));			
			table[7][2] = -NEBUN_PRIORITATE;
			table[7][4] = -PION_PRIORITATE;
			table[7][3] = -REGE_PRIORITATE;			
			table[6][3] = -PION_PRIORITATE;			
			table[6][2] = -PION_PRIORITATE;
			table[5][5] = NEBUN_PRIORITATE;
			moveWhite();			*/
			clearTable();
		}

		void test()
		{
			//testNebun();
			testSah();
		}

		void clearTable()
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					table[i][j] = 0;
				}
			}
			white.clear();
			black.clear();
		}
};

