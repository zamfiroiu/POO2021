//#include<iostream>
//
//using namespace std;
//
//enum ModDesfasurareOre {Online, Fizic, Mixt};
//
//class Facultate{
//private:
//
//protected:
//
//public:
//	string nume;
//	char* domeniu;
//	int nrStudenti;
//	ModDesfasurareOre modDesfasurare;
//
//	//Facultate() {
//	//	nume = "CSIE";
//	//	domeniu = new char[strlen("Economic") + 1];
//	//	strcpy(domeniu, "Economic");
//	//	nrStudenti = 2000;
//	//	modDesfasurare = Online;
//	//}
//
//	Facultate(string nume, int nrStudentiInmatriculati, ModDesfasurareOre modDesfasurare) {
//		this->nume = nume;
//		nrStudenti = nrStudentiInmatriculati;
//		this->modDesfasurare = modDesfasurare;
//		domeniu = new char[strlen("Economic") + 1];
//		strcpy(domeniu, "Economic");
//	}
//
//	void afisare() { //afisare(Facultate* this)
//		cout << this->nume << endl;
//		cout << domeniu << endl;
//		cout << nrStudenti << endl;
//		cout << modDesfasurare << endl;
//	}
//
//
//};
//
//void main() {
//
//	Facultate csie("CSIE",2000,Online);
//	csie.afisare(); //afisare(&csie);
//	Facultate fabiz("FABIZ",1500,Mixt);
//	//fabiz.nume = "FABIZ";
//	//fabiz.nrStudenti = 1500;
//	fabiz.afisare();
//	Facultate cig("CIG", 1600, Fizic);
//	cig.afisare();
//
//	//Facultate* vector = new Facultate[14];
//
//
//}