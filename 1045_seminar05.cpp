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
//	Spital(Spital& s):nrSpital(s.nrSpital) {
//		this->nrPacienti = s.nrPacienti;
//		this->nume = s.nume;
//		this->varstePacienti = new int[s.nrPacienti];
//		for (int i = 0;i < s.nrPacienti;i++) {
//			this->varstePacienti[i] = s.varstePacienti[i];
//		}
//		nrObiecteSpital++;
//	}
//	~Spital() {
//		nrObiecteSpital--;
//		if (this->varstePacienti) {
//			delete[]this->varstePacienti;
//		}
//	}
//
//	void operator=(Spital s) {
//		this->nrPacienti = s.nrPacienti;
//		this->nume = s.nume;
//		if (this->varstePacienti) {
//			delete[]this->varstePacienti;
//		}
//		this->varstePacienti = new int[s.nrPacienti];
//		for (int i = 0;i < s.nrPacienti;i++) {
//			this->varstePacienti[i] = s.varstePacienti[i];
//		}
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
//
//	void setVarstePacienti(int nrPacienti, int* varste) {
//		if (nrPacienti > 0 && varste != NULL) {
//			this->nrPacienti = nrPacienti;
//			if (this->varstePacienti != NULL) {
//				delete[]this->varstePacienti;
//			}
//			this->varstePacienti = new int[nrPacienti];
//			for (int i = 0;i < nrPacienti;i++) {
//				this->varstePacienti[i] = varste[i];
//			}
//
//		}
//	}
//
//	int* getVarstePacienti() {
//		return this->varstePacienti;
//	}
//
//	int getVarstaPacient(int pozitie) {
//		if (pozitie >= 0 && pozitie < nrPacienti) {
//			return this->varstePacienti[pozitie];
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