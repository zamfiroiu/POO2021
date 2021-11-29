//#include<iostream>
//using namespace std;
//
//enum FormaGeometrica{rotunda, patrata, dreptunghiulara};
//
//struct Prajitura {
//	FormaGeometrica forma;
//	int nrIngrediente;
//	bool esteVegana;
//	string denumire;
//};
//
//Prajitura initializarePrajitura(FormaGeometrica forma, int nrIngrediente, bool esteVegana, string denumire) {
//	Prajitura p;
//	p.forma = forma;
//	p.nrIngrediente = nrIngrediente;
//	p.esteVegana = esteVegana;
//	p.denumire = denumire;
//	return p;
//}
//
//void afisarePrajtura(Prajitura pr) {
//	cout << "Denumire:" << pr.denumire << endl;
//	cout << "Forma:" << pr.forma << endl;
//	cout << "Numar ingrediente:" << pr.nrIngrediente << endl;
//	cout << (pr.esteVegana?"Este vegana": "Nu este vegana") << endl<<endl;
//}
//
//void main() {
//	Prajitura p;
//	p = initializarePrajitura(rotunda, 4, true, "Amandina");
//	afisarePrajtura(p);
//
//	Prajitura* pPrajitura;
//	pPrajitura = &p;
//
//	Prajitura* pp;
//    pp = new Prajitura();
//	*pp = initializarePrajitura(patrata, 7, false, "Tiramisu");
//	afisarePrajtura(*pp);
//	
//
//	Prajitura* v;
//	int nrPrajituri = 3;
//	v = new Prajitura[nrPrajituri];
//
//	for (int i = 0;i < nrPrajituri;i++) {
//		v[i] = initializarePrajitura(patrata, 5 + i, true, "Savarina");
//	}
//	cout <<endl<< "Vector prajituri:" << endl;
//	for (int i = 0;i < nrPrajituri;i++) {
//		afisarePrajtura(v[i]);
//	}
//
//	Prajitura** pointeri;
//	pointeri = new Prajitura * [3];
//
//	pointeri[0] = new Prajitura();
//	*(pointeri[0]) = initializarePrajitura(dreptunghiulara, 8, true, "Ecler");
//	
//	pointeri[1] = new Prajitura[2];
//	pointeri[1][0] = initializarePrajitura(dreptunghiulara, 8, true, "Ecler");
//	pointeri[1][1] = initializarePrajitura(rotunda, 3, true, "Amandina");
//
//	pointeri[2] = pp;
//
//	if (pp) {
//		delete pp;
//		pp = NULL;
//	}
//	delete[]v;
//
//	delete pointeri[0];
//	delete[]pointeri[1];
//	//delete pointeri[2];
//	if (pp) {
//		delete pp;
//		pp = NULL;
//	}
//}