//#include<iostream>
//#include<string>
//#include<fstream>
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
//		if (c.preturi != NULL && c.nrProduse > 0) {
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
//	const Cafenea& operator=(const Cafenea& c) {
//		if (this != &c) {
//			this->denumire = c.denumire;
//			this->nrProduse = c.nrProduse;
//			if (this->preturi) {
//				delete[]this->preturi;
//			}
//			if (c.preturi != NULL && c.nrProduse > 0) {
//				this->preturi = new float[c.nrProduse];
//				for (int i = 0;i < this->nrProduse;i++) {
//					this->preturi[i] = c.preturi[i];
//				}
//			}
//			else {
//				this->preturi = NULL;
//			}
//		}
//		return *this;
//	}
//
//	Cafenea operator+(const Cafenea& c) {
//		Cafenea aux = *this;
//		if (aux.preturi != NULL) {
//			delete[]aux.preturi;
//		}
//		aux.preturi = new float[this->nrProduse + c.nrProduse];
//		aux.nrProduse = this->nrProduse + c.nrProduse;
//		for (int i = 0;i < this->nrProduse;i++) {
//			aux.preturi[i] = this->preturi[i];
//		}
//		for (int i = 0;i < c.nrProduse;i++) {
//			aux.preturi[i + this->nrProduse] = c.preturi[i];
//		}
//		return aux;
//	}
//
//
//	string getDenumire()const {
//		return this->denumire;
//	}
//	const int getAnInfiintare()const {
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
//		if (nrProduse > 0 && preturi != NULL) {
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
//	int getNrProduse() const {
//		return nrProduse;
//	}
//	float* getPreturi() const {
//		return this->preturi;
//	}
//	float getPret(int pozitie)const {
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
//
//	explicit operator float() {
//		float suma = 0;
//		for (int i = 0;i < this->nrProduse;i++) {
//			suma += this->preturi[i];
//		}
//		return suma;
//	}
//
//	bool operator>=(const Cafenea& c) {
//		return this->nrProduse >= c.nrProduse;
//	}
//
//	Cafenea operator++() {
//		for (int i = 0;i < this->nrProduse;i++) {
//			this->preturi[i]++;
//		}
//		return *this;
//	}
//
//	Cafenea operator++(int) {
//		Cafenea aux = *this;
//		for (int i = 0;i < this->nrProduse;i++) {
//			this->preturi[i]++;
//		}
//		return aux;
//	}
//
//	friend ofstream& operator<<(ofstream& out, const Cafenea& c) {
//		out << c.denumire << " ";
//		out << c.nrProduse << " ";
//		for (int i = 0;i < c.nrProduse;i++) {
//
//			out << c.preturi[i] << " ";
//		}
//		out << c.anInfiintare << endl;
//		return out;
//	}
//
//	friend  ifstream& operator>>(ifstream& f, Cafenea& c) {
//		f >> c.denumire;
//		f >> c.nrProduse;
//		if (c.preturi != NULL) {
//			delete[]c.preturi;
//		}
//		c.preturi = new float[c.nrProduse];
//		for (int i = 0;i < c.nrProduse;i++) {
//			f >> c.preturi[i];
//		}
//		int aux;
//		f >> aux;
//		return f;
//	}
//
//
//};
//
//ostream& operator<<(ostream& out, const Cafenea& c) {
//	out << "Denumire:" << c.getDenumire() << endl;
//	out << "nr Cafenele:" << c.getNrCafenele() << endl;
//	out << "TVA:" << c.getTVA() << endl;
//	out << "An infiintare:" << c.getAnInfiintare() << endl;
//	out << "nrProduse:" << c.getNrProduse() << endl;
//	for (int i = 0;i < c.getNrProduse();i++) {
//		out << c.getPret(i) << " ";
//	}
//	return out;
//
//}
//
//int Cafenea::TVA = 5;
//int Cafenea::nrCafenele = 0;
//
//
//void main() {
//	//ofstream fisier("fisier1044.txt", ios::app);
//	//Cafenea c("Cafenea4", 4, new float[4]{ 4,5,6,8 }, 2019);
//	//fisier<<c;
//	//fisier.close();
//
//	Cafenea c;
//	ifstream f("fisier1044.txt", ios::in);
//	f >> c;
//	cout << c;
//
//}