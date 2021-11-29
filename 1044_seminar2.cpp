//#include<iostream>
//
//using namespace std;
//
//struct Firma {
//	string nume;
//	char* domeniuActivitate;
//	int anInfiintare;
//	int nrAngajati;
//};
//void afisareFirma(Firma f) {
//	cout << "Nume:" << f.nume << endl;
//	cout << "Domeniu:" << f.domeniuActivitate << endl;
//	cout << "An infiintare:" << f.anInfiintare << endl;
//	cout << "Numar angajati:" << f.nrAngajati<<endl;
//}
//
//void main() {
//	Firma firma;
//	firma.nume = "Firma mea"; 
//	//domeniu=IT
//	//HORECA
//	//firma.domeniuActivitate =(char*) malloc((strlen("IT") + 1) * sizeof(char));
//	firma.domeniuActivitate = new char[strlen("IT") + 1];
//	strcpy(firma.domeniuActivitate, "IT");
//	firma.anInfiintare = 2021;
//	firma.nrAngajati = 2;
//	afisareFirma(firma);
//
//	Firma* pFirma;
//	Firma* vFirme;
//	pFirma = new Firma();
//	int nrFirme = 6;
//	vFirme = new Firma[nrFirme];
//
//	(*pFirma).nume = "Alta firma";
//	pFirma->domeniuActivitate = new char[strlen("HORECA") + 1];
//	strcpy(pFirma->domeniuActivitate, "HORECA");
//	pFirma->anInfiintare = 2020;
//	pFirma->nrAngajati = 7;
//	afisareFirma(*pFirma);
//
//	////vFirma->nume = "Nume firma";
//	//(*(vFirma+0)).nume = "Prima firma";
//	//(*(vFirma + 1)).nume = "A doua firma";
//	//(*(vFirma+2)).nume = "A treia firma"; //deplasare+dereferentiere+accesare
//
//	//vFirma[0].nume = "Prima firma";
//
//	//(vFirma + 1)->nume = "a doua firma";
//
//	//	//. - accesare
//	//	//* - dereferentiere
//	//	//+ - deplasare
//	//	//-> - dereferentiere + accesare
//	//	//[] - deplasare+ dereferentiere 
//
//	for (int i = 0;i < nrFirme;i++) {
//		vFirme[i].nume = "FIRMA";
//		vFirme[i].domeniuActivitate = new char[strlen("IT") + 1];
//		strcpy(vFirme[i].domeniuActivitate, "IT");
//		vFirme[i].anInfiintare = 2000 + i;
//		vFirme[i].nrAngajati = 10 + i;
//	}
//
//	for (int i = 0;i < nrFirme;i++) {
//		cout << "Firma de pe pozitia: " << i + 1 << ": " << endl;
//		afisareFirma(vFirme[i]);
//		cout << endl;
//	}
//}