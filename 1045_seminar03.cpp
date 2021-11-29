//#include<iostream>
//
//using namespace std;
//
//enum GenFilm{Drama, Comedie, Actiune};
//
//class Film {
//public:
//	float durata;
//	int anAparitie;
//	GenFilm gen;
//	char* nume;
//	string regizor;
//
//	Film() {
//		this->durata = 120.2f;
//		anAparitie = 2021;
//		this->gen = Actiune;
//		nume = new char[strlen("Venom") + 1];
//		strcpy(nume, "Venom");
//		regizor = "Regizor";
//	}
//
//	Film(float durata, int an, GenFilm gen, const char* denumire) {
//		this->durata = durata;
//		this->anAparitie = an;
//		this->gen = gen;
//		this->nume = new char[strlen(denumire)+1];
//		strcpy(this->nume, denumire);
//		regizor = "Regizor";
//	}
//
//	void afisare() { 
//		cout << this->nume << endl;
//		cout << durata << endl;
//		cout << anAparitie << endl;
//		cout << gen << endl;
//		cout << regizor << endl;
//	}
//};
//
//
//void main() {
//	Film film1;
//	//cout<<film1.durata;
//	film1.afisare(); //afisare(&film1)
//
//	Film film2;
//	film2.durata = 87;
//	film2.anAparitie = 2020;
//	film2.afisare();
//
//	char* p = new char[11];
//	strcpy(p, "SUperman");
//	Film film3(90, 2021, Comedie, "Superman");
//	strcpy(p, "SpiderMan");
//	film3.afisare();
//
//
//	Film* pf = new Film(180,2007,Drama, "Film vechi");
//
//	cout << endl << endl;
//	pf->afisare();
//}
