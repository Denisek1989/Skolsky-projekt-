// Ruleta beta versia.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
#include <iostream>

using namespace std;

//Ak vyhra
int vyhra(int stavka, int sanca, int konto)
{
	
	return konto + (stavka * sanca);
}

//Ak prehra
int prehra(int stavka, int konto)
{
	
	return konto - stavka;
}

//Ak padne jackpot = 0 alebo zelena
int jackpot(int stavka, int konto)
{
	return konto + stavka * 10;
}


int ruleta()
{
	srand(time(0));
	return 1 + (rand() % 36);
}

//MAIN
int main()
{
	
	int hracskeKonto = 250, hratZnova = 1, staveneCislo = 0, mnozstvoStavky = 0, sancaStavky = 35, randomCislo = 0,
		typStavky = 0;
	string moznostStavky[3] = { "Cislo od 0-35", "Parne alebo Neparne", "Cervena, Cierna alebo Zelena" };
	int vyberStavky[3] = { 1, 2, 3, };
	int cervena[17] = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34 };
	int cierna[18] = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };
	int zelena[1] = { 0 };
	bool farba = false;

	

	while (hratZnova == 1)
	{
		
		system("cls");
		cout << "!XD Vitaj v kasinovej rulete XD!" << endl;
		
		//Peniaze na učte
		cout << endl << "Na svojom konte mas " << hracskeKonto << " $. Prajem prijemnu zabavu!" << endl << endl;

		//Typ
		cout << endl << "Na vyber mas z 3 typov ako mozes stavit na ruletu!" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "." << moznostStavky[i] << " - " << vyberStavky[i] << endl;
		}

		//Vyber typu
		do
		{
			cout << endl << "Vyber si typ stavky(od 1 po 3)! ";

			cin >> typStavky;
		} while (typStavky < 1 || typStavky > 3);

		cout << "Vybral si si " << moznostStavky[typStavky - 1] << "." << endl;

		
		// Možnosti stávok
		//Od 0 do 35
	    switch (typStavky)
		{
		case 1:
			do
			{
				cout << endl << "Vyber si cislo na ktore chces stavit (od 0 do 35):";
				cin >> staveneCislo;
			} while (staveneCislo < 0 || staveneCislo > 35);

			//Kolko chces stavit 
			do
			{
				cout << endl << "Kolko chces $ staviť na svoje cislo " << staveneCislo << "(na ucte mas" << hracskeKonto
					<< ")? ";
				cin >> mnozstvoStavky;
			} while (mnozstvoStavky < 1 || mnozstvoStavky > hracskeKonto);

			randomCislo = ruleta();

			cout << endl << "Lopticka skoncila na cisle " << randomCislo << " !";


			if (staveneCislo == randomCislo)
			{
				hracskeKonto = vyhra(mnozstvoStavky, sancaStavky, hracskeKonto);
				cout << endl << "Gratulujem vyhral si! Na svojom ucte mas " << hracskeKonto << " $!" << endl;
			}
			else
			{
				hracskeKonto = prehra(mnozstvoStavky, hracskeKonto);
				cout << endl << "Ups! Nemal si asi moc stastia. Prehral si! Na svojom ucte mas " << hracskeKonto << " $"
					<< endl;
			}
			if (randomCislo == 0)
			{
				hracskeKonto = jackpot(mnozstvoStavky, hracskeKonto);
				cout << endl << "Gratulujem vyhral si Jackpot! Na svojom ucte mas" << hracskeKonto << " $!" << endl;
				break; 
			}

			break;
			// parne neparne
		case 2:
			do
			{
				cout << endl << "Vyber si typ cisla na ktore si chces stavit:";
				cout << endl << "Daj 1 ak chces neparne cislo alebo daj 2 ak chces parne cislo: ";
				cin >> staveneCislo;
			} while (staveneCislo != 1 && staveneCislo != 2);

			if (staveneCislo == 1)
			{
				cout << endl << "Kolko $ chces stavit na neparne cislo ? ";
				cin >> mnozstvoStavky;
			}
			else if (staveneCislo == 2)
			{
				cout << endl << "Kolko $ chces stavit na parne cislo ? ";
				cin >> mnozstvoStavky;
			}


			while (mnozstvoStavky < 1 || mnozstvoStavky > hracskeKonto)
			{
				cout << endl << "Na svojom ucte mas" << hracskeKonto << "$";
				cin >> mnozstvoStavky;
			}


			randomCislo = ruleta();

			cout << endl << "Lopticka skoncila na cisle " << randomCislo << "!";


			if (staveneCislo == 1 && randomCislo % 2 != 0 || staveneCislo == 2 && randomCislo % 2 == 0)
			{
				hracskeKonto = vyhra(mnozstvoStavky, sancaStavky, hracskeKonto);
				cout << endl << "Gratulujem vyhral si! Na svojom ucte mas" << hracskeKonto << "$!" << endl;
			}
			else
			{
				hracskeKonto = prehra(mnozstvoStavky, hracskeKonto);
				cout << endl << "Ups! Nemal si asi moc stastia. Prehral si! Na svojom ucte mas" << hracskeKonto << "$!"
					<< endl;
			}

			break;
			//cervena,cierna alebo zelena
		case 3:
			do
			{
				cout << endl << "Vyber si farbu cisla na ktore si chces stavit:";
				cout << endl <<
					"Daj 1 ak chces stavit na cervenu, 2 ak chces stavit na ciernu alebo 3 ak chces skusit stastie a stavit na zelenu:";
				cin >> staveneCislo;
			} while (staveneCislo < 1 || staveneCislo > 3);

			if (staveneCislo == 1)
			{
				cout << endl << "Kolko $ chces stavit na cervenu? ";
				cin >> mnozstvoStavky;
			}
			else if (staveneCislo == 2)
			{
				cout << endl << "Kolko $ chces stavit na ciernu? ";
				cin >> mnozstvoStavky;
			}
			else if (staveneCislo == 3)
			{
				cout << endl << "Kolko $ chces stavit na zelenu? ";
				cin >> mnozstvoStavky;
			}


			while (mnozstvoStavky < 1 || mnozstvoStavky > hracskeKonto)
			{
				cout << endl << "Na svojom konte mas" << hracskeKonto << "$!";
				cin >> mnozstvoStavky;
			}


			randomCislo = ruleta();

			cout << endl << "Lopticka skoncila na cisle" << randomCislo << "!";

			
			if (randomCislo == 0)
			{
				hracskeKonto = jackpot(mnozstvoStavky, hracskeKonto);
				cout << endl << "Gratulujem vyhral si Jackpot! Na svojom ucte mas" << hracskeKonto << "$!" << endl;
				break; 
			}


			for (int a = 0; a < 18; a++)
			{
				farba = false;

				if (staveneCislo == 1 && randomCislo == cervena[a] || staveneCislo == 2 && randomCislo == cierna[a])
				{
					hracskeKonto = vyhra(mnozstvoStavky, sancaStavky, hracskeKonto);
					cout << endl << "Gratulujem vyhral si! Na svojom ucte mas" << hracskeKonto << "$!" << endl;
					farba = true;
					a = 18;
				}
			}

			if (farba == false)
			{
				hracskeKonto = prehra(mnozstvoStavky, hracskeKonto);
				cout << endl << "Ups! Nemal si asi moc stastia. Prehral si! Na svojom ucte mas" << hracskeKonto << "$!"
					<< endl;
			}

			break;
		}

		//ak ma hrac malo penazi / hrat znova alebo nie
		if (hracskeKonto == 0)
		{
			hratZnova = 0;
			break;
		}

		if (hracskeKonto < 50)
		{
			cout << endl << "Na tvojom konte je celkom malo penazi!" << endl;
		}

		cout << endl << "Chces hrat znova? Alebo chces uz opustit kasino?" << endl;
		cout << endl << "Daj 1 ak chces hrat znovu alebo daj 0 ak chces skoncit s ruletou" << endl;
		cin >> hratZnova;


		while (hratZnova != 0 && hratZnova != 1)
		{
			cout << endl << "Prosim daj 1 ak chces hrat znovu alebo daj 0 ak chces skoncit s ruletou!";
			cin >> hratZnova;
		}
	}
	//konto po ukonceni
	if (hracskeKonto > 250)
	{
		cout << endl << "Zarobil si si" << hracskeKonto - 250 << "$!" << endl;
	}
	else if (hracskeKonto < 250)
	{
		cout << endl << "Prehral si" << 250 - hracskeKonto << "$!" << endl;
	}
	else
	{
		cout << endl << "Na svojom ucte mas stale 250$" << endl;
	}

	cout << endl << "Už opustas kasino?" << endl;
	cout << endl << "Tak dovidenia a prid znova!" << endl;
	system("pause");
	return 0;
}
