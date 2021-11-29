//#include<iostream>
//
//using namespace std;
//
//class Suc {
//	char* denumire;
//	float pret;
//	int anProducere;
//	bool areZahar;
//	const string culoare;
//	static int nrObiecteSuc;
//	static int TVA;
//
//public:
//	Suc() :culoare("Portocaliu") {
//		this->denumire = NULL;
//		this->pret = 6.5f;
//		this->anProducere = 2021;
//		this->areZahar = true;
//		nrObiecteSuc++;
//	}
//	Suc(const char* denumire, float pret, int anProducere, bool areZahar, string newCuloare) : culoare(newCuloare) {
//		this->denumire = new char[strlen(denumire) + 1];
//		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
//		this->pret = pret;
//		this->anProducere = anProducere;
//		this->areZahar = areZahar;
//		nrObiecteSuc++;
//	}
//
//	Suc(const Suc& suc):culoare(suc.culoare) {
//		if (suc.denumire) {
//			this->denumire = new char[strlen(suc.denumire) + 1];
//			strcpy_s(this->denumire, strlen(suc.denumire) + 1, suc.denumire);
//		}
//		else {
//			this->denumire = NULL;
//		}
//		this->pret = suc.pret;
//		this->anProducere = suc.anProducere;
//		this->areZahar = suc.areZahar;
//		nrObiecteSuc++;
//	}
//
//	~Suc() {
//		if (this->denumire) {
//			delete[]this->denumire;
//		}
//	}
//
//	char* getDenumire() {
//		return denumire;
//	}
//
//	void setDenumire(const char* denumire) {
//		if (denumire && strlen(denumire)>2) {
//			if (this->denumire) {
//				delete[]this->denumire;
//			}
//			this->denumire = new char[strlen(denumire) + 1];
//			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
//		}
//	}
//
//	float getPret() {
//		return this->pret;
//	}
//	string getCuloare() {
//		return this->culoare;
//	}
//
//	static int getNrObiecte() {
//		return nrObiecteSuc;
//	}
//
//	static int getTVA() {
//		return TVA;
//	}
//
//	void setPret(float pret) {
//		if (pret > 0) {
//			this->pret = pret;
//		}
//	}
//
//	static void setTVA(int TVANou) {
//		if (TVANou > 0) {
//			TVA = TVANou;
//		}
//	}
//
//	int getAnProductie() {
//		return anProducere;
//	}
//
//	void setAnProducere(int anProductie) {
//		if (anProductie > 2020) {
//			this->anProducere = anProducere;
//		}
//	}
//
//
//	bool getAreZahar() {
//		return areZahar;
//	}
//
//	void setAreZahar(bool areZahar) {
//		this->areZahar = areZahar;
//	}
//
//
//};
//
//int Suc::nrObiecteSuc = 0;
//int Suc::TVA = 9;
//
//void main() {
//	cout << Suc::getNrObiecte() << endl;
//
//	Suc suc1;
//	Suc suc2("Fanta", 5.5f, 2021, false, "Albastru");
//
//	cout << suc2.getPret();
//	cout << suc2.getCuloare();
//	cout << suc2.getNrObiecte();
//
//	Suc suc3 = suc2;
//
//	Suc suc4;
//
//	suc4 = suc2;
//
//}
