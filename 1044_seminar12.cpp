//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//
//class CafeneaAbstrata {
//	char* adresa;
//public:
//	CafeneaAbstrata() {
//		this->adresa = new char[strlen("Bucuresti") + 1];
//		strcpy(this->adresa, "Bucuresti");
//	}
//	CafeneaAbstrata(const char * adresa) {
//		this->adresa = new char[strlen(adresa) + 1];
//		strcpy(this->adresa, adresa);
//	}
//	CafeneaAbstrata(const CafeneaAbstrata& c) {
//		this->adresa = new char[strlen(c.adresa) + 1];
//		strcpy(this->adresa, c.adresa);
//	}
//
//	CafeneaAbstrata& operator=(const CafeneaAbstrata& c) {
//		if (this != &c) {
//			if (this->adresa) {
//				delete[]this->adresa;
//			}
//			this->adresa = new char[strlen(c.adresa) + 1];
//			strcpy(this->adresa, c.adresa);
//		}
//		return *this;
//	}
//
//	virtual ~CafeneaAbstrata() {
//		if (this->adresa) {
//			delete[]this->adresa;
//		}
//	}
//
//	virtual void printeazaDescriere() = 0;
//};
//
//class Cafenea: public CafeneaAbstrata {
//	string denumire;
//	int nrProduse;
//	float* preturi;
//	
//	const int anInfiintare;
//	static int TVA;
//	static int nrCafenele;
//public:
//
//	virtual void afiseazaDescriere() {
//		cout << "Cafeneaua " << denumire << " va asteapta cu o gama de " << nrProduse << " produse"<<endl;
//	}
//
//	void printeazaDescriere() {
//		cout << "Cafeneaua " << denumire << " va asteapta cu o gama de " << nrProduse << " produse" << endl;
//	}
//
//	Cafenea() :CafeneaAbstrata(), anInfiintare(2010) {
//		denumire = "Cafeneaua mea";
//		nrProduse = 0;
//		preturi = NULL;
//		nrCafenele += 1;
//	}
//
//	Cafenea(string denumire, int nrProduse, float* preturi, int pAnInfiintare) :CafeneaAbstrata("Romana"), anInfiintare(pAnInfiintare) {
//		this->denumire = denumire;
//		this->nrProduse = nrProduse;
//		this->preturi = new float[nrProduse];
//		nrCafenele++;
//		for (int i = 0;i < this->nrProduse;i++) {
//			this->preturi[i] = preturi[i];
//		}
//	}
//
//	Cafenea(const Cafenea& c) :CafeneaAbstrata(c), anInfiintare(c.anInfiintare) {
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
//			CafeneaAbstrata::operator=(c);
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
//	void afiseazaDescriere() {
//		cout << "Cafeneau cu prajituri va asteapta cu " << this->getNrProduse() 
//			<< " cafele si " << nrPrajituri << " prajituri"<<endl;
//	}
//
//	void printeazaDescriere() {
//		cout << "Cafeneau cu prajituri va asteapta cu " << this->getNrProduse()
//			<< " cafele si " << nrPrajituri << " prajituri" << endl;
//	}
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
//class Mall {
//	int nrCafenele;
//	Cafenea** cafenele;
//	char* numeMall;
//public:
//	Mall() {
//		this->nrCafenele = 0;
//		this->cafenele = NULL;
//		this->numeMall = new char[strlen("Mall") + 1];
//		strcpy(this->numeMall, "Mall");
//	}
//	Mall(int nrCafenele, Cafenea** cafenele, const char* numeMall) {
//		if (nrCafenele > 0) {
//			this->nrCafenele = nrCafenele;
//		}
//		else {
//			this->nrCafenele = 0;
//		}
//		
//		if (cafenele != NULL) {
//			this->cafenele = new Cafenea * [nrCafenele];
//			for (int i = 0;i < nrCafenele;i++) {
//				this->cafenele[i] = cafenele[i];//shallow copy- atribuire de adrese
//			}
//		}
//		else {
//			this->cafenele = NULL;
//		}
//		
//		if (numeMall != NULL) {
//			this->numeMall = new char[strlen(numeMall) + 1];
//			strcpy_s(this->numeMall,strlen(numeMall)+1, numeMall);
//		}
//		else {
//			this->numeMall = NULL;
//		}
//	}
//
//
//	Mall(const Mall& mall) {
//		if (mall.nrCafenele > 0) {
//			this->nrCafenele = mall.nrCafenele;
//		}
//		else {
//			this->nrCafenele = 0;
//		}
//
//		if (mall.cafenele != NULL) {
//			this->cafenele = new Cafenea * [this->nrCafenele];
//			for (int i = 0;i < this->nrCafenele;i++) {
//				this->cafenele[i] = mall.cafenele[i];//shallow copy- atribuire de adrese
//			}
//		}
//		else {
//			this->cafenele = NULL;
//		}
//
//		if (mall.numeMall != NULL) {
//			this->numeMall = new char[strlen(mall.numeMall) + 1];
//			strcpy_s(this->numeMall, strlen(mall.numeMall) + 1, mall.numeMall);
//		}
//		else {
//			this->numeMall = NULL;
//		}
//	}
//	Mall operator=(const Mall& mall) {
//		if (this != &mall) {
//			if (mall.nrCafenele > 0) {
//				this->nrCafenele = mall.nrCafenele;
//			}
//			else {
//				this->nrCafenele = 0;
//			}
//
//			if (mall.cafenele != NULL) {
//				if (this->cafenele != NULL) {
//					delete[]cafenele;
//				}
//				this->cafenele = new Cafenea * [this->nrCafenele];
//				for (int i = 0;i < this->nrCafenele;i++) {
//					this->cafenele[i] = mall.cafenele[i];//shallow copy- atribuire de adrese
//				}
//			}
//			else {
//				this->cafenele = NULL;
//			}
//
//			if (mall.numeMall != NULL) {
//				if (this->numeMall != NULL) {
//					delete[]this->numeMall;
//				}
//				this->numeMall = new char[strlen(mall.numeMall) + 1];
//				strcpy_s(this->numeMall, strlen(mall.numeMall) + 1, mall.numeMall);
//			}
//			else {
//				this->numeMall = NULL;
//			}
//		}
//		return *this;
//	}
//
//	~Mall() {
//		if (this->cafenele != NULL) {
//			delete[]cafenele;
//		}
//		if (this->numeMall != NULL) {
//			delete[]this->numeMall;
//		}
//	}
//	
//	void prezentareCafenele() {
//		for (int i = 0;i < this->nrCafenele;i++) {
//			this->cafenele[i]->afiseazaDescriere();
//		}
//	}
//};
//
//
//
////int suma(int a, int b){
////	return a + b;
////}
////
////float suma(float a, float b) {
////	return a + b;
////}
////
////string suma(string a, string b) {
////	return a + b;
////}
////
////Cafenea suma(Cafenea a, Cafenea b) {
////	return a + b;
////}
//
//template<class tipGeneral>
//tipGeneral suma(tipGeneral a, tipGeneral b) {
//	return a + b;
//}
//
//template<class Tip>
//class ClasaTemplate {
//	int numar;
//	Tip atribut;
//public:
//	ClasaTemplate(int numar, Tip param) {
//		this->numar = numar;
//		this->atribut = param;
//	}
//	Tip getAtribut() {
//		return this->atribut;
//	}
//
//	void setAtribut(Tip param) {
//		this->atribut = param;
//	}
//};
//
//void main() {
//
//	//CafeneaAbstrata* ca;
//		//ca = new Cafenea("Cafenea", 2, new float[2]{ 5.7,4.8 }, 2022);
//	//ca->printeazaDescriere();
//	//delete ca;
//		//ca = new CafeneaCuPrajituri(2, new Tip[2]{ vegan, Vegetarian }, new float[2]{ 20.5,25.7 });
//	//ca->printeazaDescriere();
//	//delete ca;
//
//	/*int a = 7;
//	int b = 8;
//	cout << suma(a, b) << endl;
//
//	float x = 3.7;
//	float y = 5.6;
//	cout << suma<float>(x, b) << endl;
//
//	string m = "Ana ";
//	string n = "are mere";
//	cout << suma(m, n);*/
//	Cafenea c1;
//	Cafenea c2;
//	//cout << suma(c1, c2);
//
//	ClasaTemplate<int>obiectTemplate(5, 7);
//	ClasaTemplate<Cafenea>obiectCafenea(3, c1);
//
//	cout << obiectCafenea.getAtribut();
//}