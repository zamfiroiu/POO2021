//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//class Cafenea {
//	string denumire;
//	int nrProduse;
//	float* preturi;
//	
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
//	void scriereInFisierBinar(fstream& f) {
//		int lungime = this->denumire.length();
//		f.write((char*)&lungime, sizeof(lungime));
//		f.write((char*)this->denumire.c_str(), lungime);
//		f.write((char*)&nrProduse, sizeof(nrProduse));
//		for (int i = 0;i < this->nrProduse;i++) {
//			f.write((char*)&this->preturi[i], sizeof(this->preturi[i]));
//		}
//	}
//
//	void citesteDinFisierBInar(fstream& f) {
//		int lungime =0;
//		f.read((char*)&lungime, sizeof(lungime));
//		this->denumire.resize(lungime);
//		f.read((char*)this->denumire.c_str(), lungime);
//		f.read((char*)&nrProduse, sizeof(nrProduse));
//
//		if (this->preturi) {
//			delete[]this->preturi;
//		}
//		this->preturi = new float[this->nrProduse];
//
//		for (int i = 0;i < this->nrProduse;i++) {
//			f.read((char*)&this->preturi[i], sizeof(this->preturi[i]));
//		}
//	}
//
//};
//
//int Cafenea::TVA = 5;
//int Cafenea::nrCafenele = 0;
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
//enum Tip{vegan, rawVegan, Vegetarian, Normal};
//class CafeneaCuPrajituri : public Cafenea {
//private:
//	int nrPrajituri;
//	Tip* specificPrajituri;
//	float* preturiPrajituri;
//public:
//	CafeneaCuPrajituri() :Cafenea("Cafenea cu prajturi", 2, new float[2]{15,22},2021) {
//		nrPrajituri = 0;
//		specificPrajituri = NULL;
//		preturiPrajituri = NULL;
//	}
//
//	CafeneaCuPrajituri(int nrPrajituri, Tip* specificPrajituri, float* preturiPrajituri) :Cafenea() {
//		this->nrPrajituri = nrPrajituri;
//		if (this->nrPrajituri > 0) {
//			this->specificPrajituri = new Tip[this->nrPrajituri];
//			this->preturiPrajituri = new float[this->nrPrajituri];
//			for (int i = 0;i < this->nrPrajituri;i++) {
//				this->specificPrajituri[i] = specificPrajituri[i];
//				this->preturiPrajituri[i] = preturiPrajituri[i];
//			}
//		}
//	}
//
//	CafeneaCuPrajituri(string denumire, int nrProduse, float* preturi, int pAnInfiintare, int nrPrajituri, Tip* specificPrajituri, float* preturiPrajituri) 
//		:Cafenea(denumire, nrProduse, preturi, pAnInfiintare) {
//		this->nrPrajituri = nrPrajituri;
//		if (this->nrPrajituri > 0) {
//			this->specificPrajituri = new Tip[this->nrPrajituri];
//			this->preturiPrajituri = new float[this->nrPrajituri];
//			for (int i = 0;i < this->nrPrajituri;i++) {
//				this->specificPrajituri[i] = specificPrajituri[i];
//				this->preturiPrajituri[i] = preturiPrajituri[i];
//			}
//		}	
//	}
//	CafeneaCuPrajituri(const CafeneaCuPrajituri& cp):Cafenea(cp) {
//		this->nrPrajituri = cp.nrPrajituri;
//		if (this->nrPrajituri > 0) {
//			this->specificPrajituri = new Tip[this->nrPrajituri];
//			this->preturiPrajituri = new float[this->nrPrajituri];
//			for (int i = 0;i < this->nrPrajituri;i++) {
//				this->specificPrajituri[i] = cp.specificPrajituri[i];
//				this->preturiPrajituri[i] = cp.preturiPrajituri[i];
//			}
//		}
//		else {
//
//			this->specificPrajituri = NULL;
//			this->preturiPrajituri = NULL;
//		}
//	}
//
//	const CafeneaCuPrajituri& operator=(const CafeneaCuPrajituri& cp) {
//		if (this != &cp) {
//			(Cafenea)*this = (Cafenea)cp;
//			this->nrPrajituri = cp.nrPrajituri;
//			if (this->specificPrajituri != NULL) {
//				delete[]this->specificPrajituri;
//			}
//			if (this->preturiPrajituri != NULL) {
//				delete[]this->preturiPrajituri;
//			}
//
//			if (this->nrPrajituri > 0) {				
//				this->specificPrajituri = new Tip[this->nrPrajituri];
//				this->preturiPrajituri = new float[this->nrPrajituri];
//				for (int i = 0;i < this->nrPrajituri;i++) {
//					this->specificPrajituri[i] = cp.specificPrajituri[i];
//					this->preturiPrajituri[i] = cp.preturiPrajituri[i];
//				}
//			}
//			else {
//				this->specificPrajituri = NULL;
//				this->preturiPrajituri = NULL;
//			}
//		}
//		return *this;
//	}
//
//	~CafeneaCuPrajituri() {
//		if (this->specificPrajituri != NULL) {
//			delete[]this->specificPrajituri;
//		}
//		if (this->preturiPrajituri != NULL) {
//			delete[]this->preturiPrajituri;
//		}
//	}
//
//	friend ostream& operator<<(ostream& o, const CafeneaCuPrajituri& cp) {
//		o << (Cafenea)cp;
//		o << "numar prajituri:" << cp.nrPrajituri<<endl;
//		for (int i = 0;i < cp.nrPrajituri;i++) {
//			o << cp.specificPrajituri[i] << " - " << cp.preturiPrajituri[i] << endl;
//		}
//		return o;
//	}
//};
//
//void main() {
//
//	CafeneaCuPrajituri cp("Cafenea", 2, new float[2]{ 10,15 }, 2021, 3, new Tip[3]{ vegan,vegan,rawVegan }, new float[3]{ 20,22,27 });
//	cout << cp;
//}