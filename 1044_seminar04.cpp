//#include<iostream>
//using namespace std;
//
//class Cafenea {
//	string denumire;
//	int nrProduse;
//	float* preturi;
//	const int anInfiintare;
//	static int TVA;
//	static int nrCafenele;
//public:
//	Cafenea():anInfiintare(2010) {
//		denumire = "Cafeneaua mea";
//		nrProduse = 8;
//		preturi = new float[nrProduse];
//		for (int i = 0;i < nrProduse;i++) {
//			preturi[i] = 5;
//		}
//		nrCafenele += 1;
//	}
//
//	Cafenea(string denumire, int nrProduse, float* preturi, int pAnInfiintare) :anInfiintare(pAnInfiintare) {
//		this->denumire = denumire;
//		this->nrProduse = nrProduse;
//		this->preturi = new float[nrProduse];
//		nrCafenele++;
//		for (int i=0;i < this->nrProduse;i++) {
//			this->preturi[i] = preturi[i];
//		}
//	}
//	string getDenumire() {
//		return this->denumire;
//	}
//	const int getAnInfiintare() {
//		return this->anInfiintare;
//	}
//	static int getTVA() {
//		return TVA;
//	}
//
//	void setDenumire(string denumire) {
//		if (denumire.length() >= 3) {
//			this->denumire = denumire;
//		}
//	}
//
//	static void setTVA(int pTVA) {
//		if (pTVA >= 0 && pTVA <= 100) {
//			TVA = pTVA;
//		}
//	}
//};
//
//int Cafenea::TVA = 5;
//int Cafenea::nrCafenele = 0;
//
//void main() {
//	Cafenea cafenea1;
//	Cafenea cafenea2("Cafeneaua ta", 3, new float[3]{ 5,7,9 }, 2021);
//	cout << cafenea2.getDenumire();
//}