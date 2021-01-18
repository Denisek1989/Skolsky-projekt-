// RULETA BETA.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.

#include <iostream>
using namespace std;

//Ak vyhra
int vyhra(int stavka, int sanca, int konto) {
	int novyBank = 0;
	int staryBank = konto;
	novyBank = staryBank + (stavka * sanca);
	return novyBank;
}

//Ak prehra
int prehra(int stavka, int konto) {
	int novyBank = 0;
	int staryBank = konto;
	novyBank = staryBank - stavka;
	return novyBank;
}

//Ak padne jackpot 0 alebo zelena
int jackpot(int stavka, int konto, int jackpot) {
	int novyBank = 0;
	int staryBank = konto;
	novyBank = staryBank * 10;
	return novyBank;
}
//MAIN
int main() {
	int Hracskekonto = 250, Hratznova = 1, Stavenecislo = 0, Mnozstvostavky = 0, Sancastavky = 35, Randomcislo = 0, Typstavky = 0;
	string Moznoststavky[1] = { "Cislo od 1-36"};
	int Vyberstavky;
	cout << "!XD Vitaj v kasinovej rulete XD!" << endl;

	while (Hratznova == 1) {
		//Peniaze na učte
		cout << endl << "Na svojom konte mas " << Hracskekonto << " $. Prajem prijemnu zabavu!" << endl << endl;

		cout << "Zaciname" << endl;
		cout << endl << "Vyber si cislo na ktore chces stavit:";

		while (Stavenecislo < 1 || Stavenecislo > 36) {
	
	            cout << endl << "Cislo musi byt jedine od 1 do 36!" << endl;
				
				cin >> Stavenecislo;
		}

			//Kolko chces stavit
			cout << endl << "Kolko chces $ staviť na svoje cislo " << Stavenecislo << "?";
			cin >> Mnozstvostavky;


			while (Mnozstvostavky < 1 || Mnozstvostavky > Hracskekonto) {
				cout << endl << "Na svojom konte mas " << Hracskekonto << " $";
				cin >> Mnozstvostavky;
			}


			srand(time(0));
			Randomcislo = 1 + (rand() % 36);

			cout << endl << "Lopticka skoncila na cisle " << Randomcislo << " !";


			if (Stavenecislo == Randomcislo) {
				Hracskekonto = vyhra(Mnozstvostavky, Sancastavky, Hracskekonto);
				cout << endl << "Gratulujem vyhral si! Na svojom ucte mas" << Hracskekonto << "$!" << endl;
			}
			else {
				Hracskekonto = prehra(Mnozstvostavky, Hracskekonto);
				cout << endl << "Ups! Nemal si asi moc stastia. Prehral si! Na svojom ucte mas" << Hracskekonto << "$" << endl;
			}

			if (Hracskekonto == 0) {
				Hratznova = 0;
			}
			
			else {
				cout << endl << "Chces hrat znova? Alebo chces uz opustit kasino?" << endl;
				cout << endl << "Daj 1 ak chces hrat znovu alebo daj 0 ak chces skoncit s ruletou" << endl;
				cin >> Hratznova;
			}


			while (Hratznova != 0 && Hratznova != 1) {
				cout << endl << "Prosim daj 1 ak chces hrat znovu alebo daj 0 ak chces skoncit s ruletou!";
				cin >> Hratznova;
			}
	}

	if (Hracskekonto > 250) {
		cout << endl << "Zarobil si si" << Hracskekonto - 250 << "$!" << endl;
	}
	else if (Hracskekonto < 250) {
		cout << endl << "Prehral si" << 250 - Hracskekonto << "$!" << endl;
	}
	else {
		cout << endl << "Na svojom ucte mas stale 250$" << endl;
	}

	cout << endl << "Už opustas kasino?" << endl;
	cout << endl << "Tak dovidenia a prid znova!" << endl;
	system("pause");
	return 0;
}

		