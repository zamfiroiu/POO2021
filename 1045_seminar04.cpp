//#include<iostream>
//
//using namespace std;
//
//
//class Spital {
//	string nume;
//	int nrPacienti;
//	int* varstePacienti;
//	const int nrSpital;
//	static int nrObiecteSpital;
//	static int reducereCAS;
//public:
//	Spital():nrSpital(12){
//		this->nrPacienti = 45;
//		this->nume = "Floreasca";
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = 10 + i;
//		}
//		nrObiecteSpital++;
//	}
//	Spital(int nrPacienti, string nume, const int* varstePacienti, int newNrSpital):nrSpital(newNrSpital) {
//		this->nrPacienti = nrPacienti;
//		this->nume = nume;
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = varstePacienti[i];
//		}
//		nrObiecteSpital++;
//	}
//
//	int getNrPacienti() {
//		return this->nrPacienti;
//	}
//
//	int getNrSpital() {
//		return nrSpital;
//	}
//	static int getNrObiecteSpital() {
//		return nrObiecteSpital;
//	}	
//	static int getReducereCAS() {
//		return reducereCAS;
//	}
//	string getNume() {
//		return this->nume;
//	}
//	void setNume(string nume) {
//		if (nume.length() > 2) {
//			this->nume = nume;
//		}
//	}
//
//	static void setReducereCAS(int reducere) {
//		if (reducere > 0 && reducere <= 100) {
//			reducereCAS = reducere;
//		}
//	}
//};
//
//int Spital::nrObiecteSpital = 0;
//int Spital::reducereCAS = 12;
//
//void main() {
//	Spital::getNrObiecteSpital();
//	Spital spital1;
//	Spital spital2(5, "Universitar", new int[5]{ 23,45,34,18,38 }, 1);
//	spital1.getNrObiecteSpital();
//
//
//	cout << spital2.getNume() << endl;
//	spital2.setNume("Militar");
//	cout << spital2.getNume() << endl;
//
//	Spital::setReducereCAS(15);
//	cout << Spital::getReducereCAS();
//
//}