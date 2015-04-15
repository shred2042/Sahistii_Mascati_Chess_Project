===========================================================================
    			Sahistii  Mascati 
		       Proiect PA - Etapa 1

	      Facultatea de Automatica si Calculatoare
		   Grupa 323, Seria CA, Anul II

		  Bagas Timur - Capitan de Echipa		
		     Balaban Gabriel Florentin
		      Stoica Tudor Constantin			
		      Udrea Victor-Constantin
			
===========================================================================

Descriere generala:

     Proiectul a fost realizat in limbajul C++, folosind IDE-ul MS Visual
Studio 2012. Etapa intai a constat in implementarea interfetei xboard (in
cazul nostru winboard) pentru engine-ul nostru de sah.


Detalii de implementare:

    In cazul comenzilor xboard si force, n-am luat nicio actiune concreta
deoarece nu cereau raspunsuri din partea engine-ului (xboard fiind prima
comanda data, iar force fiind modul de joc manual, unde comenzile sunt date
de jucatori).

    Comanda new initializeaza tabla de joc (reprezentata ca fiind o matrice
de intregi, unde fiecare intreg semnifica tipul piesei inmultita cu semnul
corespunzator culorii: - pentru alb si + pentru negru). Piesele ca atare
sunt retinute in doi vectori, pentru fiecare culoare.

    Comanda move ia forma unui string de patru caractere parsate de engine
astfel incat modificarile din xboard sa fie oglindite si in reprezentarea
interna a tablei.

    Comanda go, practic da startul mutarilor tinand cont de culoarea data
de comenzile white si black (memorata in clasa PlayTable).

    Comenzile quit si resign aduc sfarsitul jocului (quit termina tot
programul, iar resign trimite comanda corespunzatoare la xboard).


Metodologia abordata:
    
    Pentru aceasta etapa am ales sa mutam un singur pion pana cand acesta
nu mai are miscari valabile, caz in care trimite comanda resign la xboard.
    Pionul va face miscari pana la intalnirea altei piese care ii impiedica
avansul, sau pana la sfarsitul tablei sau daca este capturat. In cazul in 
care are posibilitatea sa captureze o piesa adversa, o va face, continuand
sa avanseze mai departe din pozitia noua.

===========================================================================

Mentiune:

    Fisierele: Cal.h, Nebun.h etc. sunt pentru implementari viitoare, si
au fost incluse pentru ca proiectul sa fie complet, desi deocamdata nu au
o functionalitate anume.