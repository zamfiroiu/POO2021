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
//	Suc():culoare("Portocaliu"){
//		this->denumire = NULL;
//		this->pret = 6.5f;
//		this->anProducere = 2021;
//		this->areZahar = true;
//		nrObiecteSuc++;
//	}
//	Suc(const char* denumire, float pret, int anProducere, bool areZahar, string newCuloare) : culoare(newCuloare) {
//		this->denumire = new char[strlen(denumire)+1];
//		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
//		this->pret = pret;
//		this->anProducere = anProducere;
//		this->areZahar = areZahar;
//		nrObiecteSuc++;
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
//	void setPret(float pret){
//		this->pret = pret;
//	}
//
//	static void setTVA(int TVANou) {
//		if (TVANou > 0) {
//			TVA = TVANou;
//		}
//	}
//
//
//};
//
//int Suc::nrObiecteSuc = 0;
//int Suc::TVA = 9;
//
//void main() {
//	cout << Suc::getNrObiecte()<<endl;
//
//	Suc suc1;
//	Suc suc2("Fanta", 5.5f, 2021, false, "Albastru");
//
//	cout << suc2.getPret();
//	cout << suc2.getCuloare();
//	cout << suc2.getNrObiecte();
//}
