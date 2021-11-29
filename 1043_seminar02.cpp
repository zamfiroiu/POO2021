//#include<iostream>
//
//using namespace std;
//
//enum Marime{small, medium, large};
//
//struct Cafea {
//	string aroma;
//	Marime marime;
//	float pret;
//	bool cuZahar;
//};
//
//Cafea initializareCafea(string aroma, Marime marime, float pret, bool cuZahar) {
//	Cafea c;
//	c.aroma = aroma;
//	c.marime = marime;
//	c.pret = pret;
//	c.cuZahar = cuZahar;
//	return c;
//}
//
//void afisareCafea(Cafea c) {
//	cout << "Aroma:" << c.aroma << endl;
//	cout << "Marime:" << c.marime << endl;
//	cout << "Pret:" << c.pret << endl;
//	cout << ((c.cuZahar==true)?"cu zahar":"fara zahar")<<endl;
//}
//
//void main() {
//	Cafea cafea;
//	cafea = initializareCafea("Caramel", medium, 15, false);
//	afisareCafea(cafea);
//
//	Cafea* pCafea;
//	pCafea = &cafea;
//
//	Cafea* p;
//	p = new Cafea();
//	p->aroma = "vanilie";
//	p->marime = small;
//	p->cuZahar = true;
//	p->pret = 10;
//
//	afisareCafea(*p);
//
//	Cafea* v;
//	int nrCafele = 3;
//	v = new Cafea[nrCafele];
//	for (int i = 0;i < nrCafele;i++) {
//		v[i] = initializareCafea("scortisoara", small, 5 *( i + 1), true);
//	}
//
//	cout << "Vector de cafele" << endl;
//	for (int i = 0;i < nrCafele;i++) {
//		afisareCafea(v[i]);
//	} 
//
//	if (p) {
//		delete p;
//		p = NULL;
//	}
//	if (v) {
//		delete[]v;
//		v = NULL;
//	}
//}