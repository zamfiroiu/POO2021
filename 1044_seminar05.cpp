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
//	Cafenea() :anInfiintare(2010) {
//		denumire = "Cafeneaua mea";
//		nrProduse = 0;
//		preturi = NULL;
//		nrCafenele += 1;
//	}
//
//	Cafenea(string denumire, int nrProduse, float* preturi, int pAnInfiintare) :anInfiintare(pAnInfiintare) {
//		this->denumire = denumire;
//		this->nrProduse = nrProduse;
//		this->preturi = new float[nrProduse];
//		nrCafenele++;
//		for (int i = 0;i < this->nrProduse;i++) {
//			this->preturi[i] = preturi[i];
//		}
//	}
//
//	Cafenea(const Cafenea& c) :anInfiintare(c.anInfiintare) {
//		nrCafenele++;
//		this->denumire = c.denumire;
//		this->nrProduse = c.nrProduse;
//		if (c.preturi != NULL && c.nrProduse>0) {
//			this->preturi = new float[c.nrProduse];
//			for (int i = 0;i < this->nrProduse;i++) {
//				this->preturi[i] = c.preturi[i];
//			}
//		}
//		else {
//			this->preturi = NULL;
//		}
//	}
//
//
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
//
//	void setPreturiProduse(float* preturi, int nrProduse) {
//		if (nrProduse > 0 && preturi !=NULL) {
//			this->nrProduse = nrProduse;
//			if (this->preturi != NULL) {
//				delete[]this->preturi;
//			}
//
//			this->preturi = new float[nrProduse];
//			for (int i = 0;i < nrProduse;i++) {
//				if (preturi[i] > 0) {
//					this->preturi[i] = preturi[i];
//				}
//				else {
//					this->preturi[i] = 0.1f;
//				}
//			}
//		}
//	}
//
//	int getNrProduse() {
//		return nrProduse;
//	}
//	float* getPreturi() {
//		return this->preturi;
//	}
//	float getPret(int pozitie) {
//		if (pozitie >= 0 && pozitie < this->nrProduse) {
//			return this->preturi[pozitie];
//		}
//	}
//	static int getNrCafenele() {
//		return nrCafenele;
//	}
//
//	~Cafenea() {
//		if (this->preturi) {
//			delete[]this->preturi;
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
//	//cout << cafenea2.getDenumire();
//
//	cout << cafenea2.getPreturi()[1]<<endl;
//	cout << cafenea2.getPret(1);
//
//	Cafenea c;
//	Cafenea c4 = c;
//
//}