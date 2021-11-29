//#include<iostream>
//
//using namespace std;
//
//struct Magazin {
//	string nume;
//	int numarAngajati;
//	float cifraAfaceri;
//	bool arePaza;
//};
//
//void afisareMagazin(Magazin m) {
//	cout << "Nume:" << m.nume<<endl;
//	cout << "Numar angajati:" << m.numarAngajati << endl;
//	cout << "Cifra afaceri:" << m.cifraAfaceri << endl;
//	cout << ((m.arePaza == true) ? "are paza" : "Nu are paza");
//	cout << endl;
//}
//
//
//void main() {
//	//char variabila = 'a';
//	//char* var2 = (char*)malloc((strlen("a") + 1) * sizeof(char));
//	//char* var3 = new char[strlen("a") + 1];
//	//strcpy(var2, "a");
//
//
//	Magazin magazin;
//	magazin.arePaza = true;
//	magazin.cifraAfaceri = 200;
//	magazin.numarAngajati = 4;
//	magazin.nume = "Magazinul meu";
//
//	afisareMagazin(magazin);
//
//	Magazin magazin2;
//	Magazin* pMagazin = new Magazin();
//	Magazin* vMagazin = new Magazin[3];
//
//	(*pMagazin).arePaza = false;
//	pMagazin->cifraAfaceri = 400;
//	pMagazin->numarAngajati = 3;
//	pMagazin->nume = "Alt magazin";
//
//	afisareMagazin(*pMagazin);
//}