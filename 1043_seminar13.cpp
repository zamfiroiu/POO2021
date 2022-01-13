//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<set>
//
//using namespace std;
//
//class SucAbstract {
//public:
//	virtual void descrieSuc() = 0;
//	virtual ~SucAbstract(){
//	}
//};
//
//class Suc :public SucAbstract {
//	char* denumire;
//	float pret;
//	int anProducere;
//	bool areZahar;
//	const string culoare;
//	static int nrObiecteSuc;
//	static int TVA;
//
//public:
//
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
//	Suc(const Suc& suc) :culoare(suc.culoare) {
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
//	const Suc& operator=(const Suc& suc) {
//		if (this != &suc) {
//			if (suc.denumire != NULL) {
//				if (this->denumire != NULL) {
//					delete[]this->denumire;
//				}
//				this->denumire = new char[strlen(suc.denumire) + 1];
//				strcpy_s(this->denumire, strlen(suc.denumire) + 1, suc.denumire);
//			}
//			else {
//				this->denumire = NULL;
//			}
//			this->pret = suc.pret;
//			this->anProducere = suc.anProducere;
//			this->areZahar = suc.areZahar;
//		}
//		return *this;
//	}
//
//
//	~Suc() {
//		if (this->denumire) {
//			delete[]this->denumire;
//		}
//	}
//
//	char* getDenumire() const {
//		return this->denumire;
//	}
//
//	void setDenumire(const char* denumire) {
//		if (denumire && strlen(denumire) > 2) {
//			if (this->denumire) {
//				delete[]this->denumire;
//			}
//			this->denumire = new char[strlen(denumire) + 1];
//			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
//		}
//	}
//
//	float getPret() const {
//		return this->pret;
//	}
//	string getCuloare() const {
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
//	int getAnProductie() const {
//		return anProducere;
//	}
//
//	void setAnProducere(int anProductie) {
//		if (anProductie > 2020) {
//			this->anProducere = anProducere;
//		}
//	}
//
//	bool getAreZahar() const {
//		return areZahar;
//	}
//
//	void setAreZahar(bool areZahar) {
//		this->areZahar = areZahar;
//	}
//
//	Suc operator+(float val) {
//		Suc aux = *this;
//		aux.pret = this->pret + val;
//		return aux;
//	}
//
//	bool operator==(const Suc& suc) {
//		if (this->pret != suc.pret) {
//			return false;
//		}
//		if (this->areZahar != suc.areZahar) {
//			return false;
//		}
//		if (this->culoare.compare(suc.culoare) != 0) {
//			return false;
//		}
//
//		return true;
//	}
//
//	bool operator<(const Suc& suc) const {
//		return this->pret < suc.pret;
//	}
//
//	Suc operator--() {
//		this->pret--;
//		return *this;
//	}
//
//	Suc operator--(int) {
//		Suc aux = *this;
//		this->pret--;
//		return aux;
//	}
//
//	explicit operator float() {
//		return (1 + TVA / 100.0f) * this->pret;
//	}
//
//	friend istream& operator>>(istream& c, Suc& s) {
//		char aux[20];
//		c >> aux;
//		if (s.denumire != NULL) {
//			delete[]s.denumire;
//		}
//		s.denumire = new char[strlen(aux) + 1];
//		strcpy_s(s.denumire, strlen(aux) + 1, aux);
//
//		c >> s.pret;
//		c >> s.anProducere;
//		c >> s.areZahar;
//
//		return c;
//	}
//
//	friend ifstream& operator>>(ifstream& c, Suc& s) {
//		char aux[20];
//		c >> aux;
//		if (s.denumire != NULL) {
//			delete[]s.denumire;
//		}
//		s.denumire = new char[strlen(aux) + 1];
//		strcpy_s(s.denumire, strlen(aux) + 1, aux);
//
//		c >> s.pret;
//		c >> s.anProducere;
//		c >> s.areZahar;
//
//		c >> aux;
//		return c;
//	}
//
//	friend ofstream& operator<<(ofstream& o, const Suc& s) {
//		o << s.denumire << " ";
//		o << s.pret << " ";
//		o << s.anProducere << " ";
//		o << s.areZahar << " ";
//		o << s.culoare << endl;
//		return o;
//	}
//
//	void salvareInCSV(ofstream& o, char caracter) {
//		o << this->denumire << caracter;
//		o << this->pret << caracter;
//		o << this->anProducere << caracter;
//		o << this->areZahar << caracter;
//		o << this->culoare << endl;
//	}
//
//	void scriereFisierBinar(fstream& f) {
//		int lungime = strlen(this->denumire);
//		f.write((char*)&lungime, sizeof(lungime));
//		f.write((char*)this->denumire, lungime);
//		f.write((char*)&this->pret, sizeof(this->pret));
//		f.write((char*)&this->anProducere, sizeof(this->anProducere));
//		f.write((char*)&this->areZahar, sizeof(this->areZahar));
//
//	}
//
//	void citireDinFisierBinar(fstream& f) {
//		int lungime = 0;
//		f.read((char*)&lungime, sizeof(lungime));
//		if (this->denumire) {
//			delete[]this->denumire;
//		}
//		this->denumire = new char[lungime + 1];
//		f.read((char*)this->denumire, lungime);
//		this->denumire[lungime] = '\0';
//		f.read((char*)&this->pret, sizeof(this->pret));
//		f.read((char*)&this->anProducere, sizeof(this->anProducere));
//		f.read((char*)&this->areZahar, sizeof(this->areZahar));
//
//	}
//
//	virtual void printareDescriere() {
//		if (this->denumire)
//			cout << this->denumire << " costa " << this->pret << " Lei." << endl;
//		else
//			cout << "Sucul costa " << this->pret << " Lei." << endl;
//	}
//
//	void descrieSuc() {
//		printareDescriere();
//	}
//
//};
//int Suc::nrObiecteSuc = 0;
//int Suc::TVA = 9;
//
//Suc operator+(float val, const Suc& suc) {
//	Suc aux = suc;
//	aux.setPret(suc.getPret() + val);
//	return aux;
//}
//
//ostream& operator<<(ostream& o, const Suc& s) {
//	if (s.getDenumire() != NULL)
//		o << "Denumire: " << s.getDenumire() << endl;
//	else
//		o << "Nu are denumire" << endl;
//	o << "Pret: " << s.getPret() << endl;
//	o << "An producere: " << s.getAnProductie() << endl;
//	o << (s.getAreZahar() ? "Are" : "Nu are") << " zahar." << endl;
//	o << "Culoare: " << s.getCuloare() << endl;
//	return o;
//}
//
//class SucNatural : public Suc {
//	int nrFructe;
//	string* denumireFructe;
//	float* cantitateFructe;
//public:
//	SucNatural() :Suc() {
//		this->setAreZahar(false);
//		this->nrFructe = 2;
//		this->cantitateFructe = new float[this->nrFructe]{ 3,2.3 };
//		this->denumireFructe = new string[this->nrFructe]{ "N/A","N/A" };
//	}
//	SucNatural(int nrFructe, string* denumireFructe, float* cantitateFructe, const char* denumire, float pret, int anProducere, bool areZahar, string newCuloar) :Suc(denumire, pret, anProducere, areZahar, newCuloar) {
//		this->nrFructe = nrFructe;
//		this->denumireFructe = new string[this->nrFructe];
//		this->cantitateFructe = new float[this->nrFructe];
//		for (int i = 0;i < this->nrFructe;i++) {
//			this->cantitateFructe[i] = cantitateFructe[i];
//			this->denumireFructe[i] = denumireFructe[i];
//		}
//	}
//
//	SucNatural(int nrFructe, string* denumireFructe, float* cantitateFructe) :Suc("SucNatural", 7.6, 2021, false, "Galben") {
//		this->nrFructe = nrFructe;
//		this->denumireFructe = new string[this->nrFructe];
//		this->cantitateFructe = new float[this->nrFructe];
//		for (int i = 0;i < this->nrFructe;i++) {
//			this->cantitateFructe[i] = cantitateFructe[i];
//			this->denumireFructe[i] = denumireFructe[i];
//		}
//	}
//
//	~SucNatural() {
//		if (this->cantitateFructe)
//			delete[]this->cantitateFructe;
//		if (this->denumireFructe)
//			delete[]this->denumireFructe;
//	}
//
//	SucNatural(const SucNatural& sn) :Suc(sn) {
//		this->nrFructe = sn.nrFructe;
//		this->denumireFructe = new string[this->nrFructe];
//		this->cantitateFructe = new float[this->nrFructe];
//		for (int i = 0;i < this->nrFructe;i++) {
//			this->cantitateFructe[i] = sn.cantitateFructe[i];
//			this->denumireFructe[i] = sn.denumireFructe[i];
//		}
//	}
//
//	const SucNatural& operator=(const SucNatural& sn) {
//		if (this != &sn) {
//			(Suc&)*this = (Suc&)sn;
//			this->nrFructe = sn.nrFructe;
//
//			if (this->cantitateFructe)
//				delete[]this->cantitateFructe;
//			if (this->denumireFructe)
//				delete[]this->denumireFructe;
//			if (this->nrFructe != 0) {
//				this->denumireFructe = new string[this->nrFructe];
//				this->cantitateFructe = new float[this->nrFructe];
//				for (int i = 0;i < this->nrFructe;i++) {
//					this->cantitateFructe[i] = sn.cantitateFructe[i];
//					this->denumireFructe[i] = sn.denumireFructe[i];
//				}
//			}
//			else {
//				this->denumireFructe = NULL;
//				this->cantitateFructe = NULL;
//			}
//		}
//		return *this;
//	}
//
//	friend istream& operator>>(istream& in, SucNatural& sn) {
//		in >> (Suc&)sn;
//
//	}
//
//	friend ostream& operator<<(ostream& o, const SucNatural& sn) {
//		o << (Suc&)sn;
//		o << "Numar fructe:" << sn.nrFructe;
//		for (int i = 0;i < sn.nrFructe;i++) {
//			o << sn.denumireFructe[i] << " - " << sn.cantitateFructe[i] << "gr" << endl;
//		}
//		o << endl;
//
//		return o;
//	}
//
//	float calcularePretMediuPerGram() {
//		float gramajTotal = 0;
//		for (int i = 0;i < this->nrFructe;i++) {
//			gramajTotal += this->cantitateFructe[i];
//		}
//		//pret/gramaj
//		if (gramajTotal != 0) {
//			return this->getPret() / gramajTotal;
//		}
//		else {
//			return 0;
//		}
//	}
//
//	void printareDescriere() {
//		if (this->getDenumire())
//			cout << this->getDenumire() << " costa " << this->getPret() << " Lei si contine " << this->nrFructe << " fructe." << endl;
//		else
//			cout << "Sucul costa " << this->getPret() << " Lei si contine " << this->nrFructe << " fructe." << endl;
//
//	}
//
//	void descrieSuc() {
//		printareDescriere();
//	}
//};
//
//class CosDeCumparaturi {
//public:
//	int nrSucuri;
//	Suc** sucuri;
//	float costTotal;
//public:
//	CosDeCumparaturi() {
//		this->nrSucuri = 0;
//		this->sucuri = NULL;
//		this->costTotal = 0;
//	}
//
//	CosDeCumparaturi(int nrSucuri, Suc** sucuri, float pretTotal) {
//		this->nrSucuri = nrSucuri;
//		if (nrSucuri > 0) {
//			this->sucuri = new Suc * [nrSucuri];
//			for (int i = 0;i < nrSucuri;i++) {
//				this->sucuri[i] = sucuri[i];//shallow copy
//			}
//		}
//		else {
//			this->sucuri = NULL;
//		}
//		this->costTotal = pretTotal;
//	}
//
//	CosDeCumparaturi(const CosDeCumparaturi& cc) {
//		this->nrSucuri = cc.nrSucuri;
//		if (cc.nrSucuri > 0) {
//			this->sucuri = new Suc * [cc.nrSucuri];
//			for (int i = 0;i < cc.nrSucuri;i++) {
//				this->sucuri[i] = cc.sucuri[i];//shallow copy
//			}
//		}
//		else {
//			this->sucuri = NULL;
//		}
//		this->costTotal = cc.costTotal;
//	}
//
//	CosDeCumparaturi& operator=(const CosDeCumparaturi& cc) {
//		if (this != &cc) {
//			if (this->sucuri != NULL) {
//				delete[]this->sucuri;
//			}
//			if (cc.nrSucuri > 0) {
//
//				this->nrSucuri = cc.nrSucuri;
//				this->sucuri = new Suc * [cc.nrSucuri];
//				for (int i = 0;i < cc.nrSucuri;i++) {
//					this->sucuri[i] = new Suc();
//					*(this->sucuri[i]) = *(cc.sucuri[i]);
//				}
//			}
//			else {
//				this->nrSucuri = 0;
//				this->sucuri = NULL;
//			}
//			this->costTotal = cc.costTotal;
//		}
//
//		return *this;
//	}
//
//	~CosDeCumparaturi() {
//		if (this->sucuri != NULL) {
//			delete[]this->sucuri;
//		}
//	}
//
//	void scanareSucuri() {
//		if (nrSucuri <= 0) {
//			throw 404;
//		}
//		for (int i = 0;i < nrSucuri;i++) {
//			this->sucuri[i]->printareDescriere();
//		}
//	}
//
//};
//
//template<typename T>
//bool areEqual(T p1, T p2) {
//	return p1 == p2;
//}
//
//template<class T>
//class Bar {
//	T* bautura;
//public:
//	Bar() {
//		this->bautura = new T();
//	}
//	Bar(T p) {
//		this->bautura = new T(p);
//	}
//	~Bar() {
//		delete this->bautura;
//	}
//	Bar(const Bar& b) {
//		this->bautura = new T(b.bautura);
//	}
//	Bar operator=(const Bar& b) {
//		if (this != &b) {
//			if (this->bautura) {
//				delete this->bautura;
//			}
//			this->bautura = new T(b.bautura);
//		}
//		return *this;
//	}
//
//	void afisareBautura() {
//		cout << *this->bautura;
//	}
//};
//
//void main() {
//	//destructor virtual
//	//SucAbstract* sa;
//	//sa = new Suc("Suc",30,2022,true,"Galben");
//	//sa->descrieSuc();
//	//delete sa;
//	//
//	//sa = new SucNatural(2, new string[2]{ "mar", "portocala" }, new float[2]{ 50,50 }, "Suc", 30, 2022, true, "Galben");
//	//sa->descrieSuc();
//	//delete sa;
//	
//	
//
//	
//	//template
//	int a = 2;
//	int b = 8;
//	if (areEqual(a, b)) {
//		cout << "sunt egale";
//	}
//	else {
//		cout << "NU sunt egale";
//	}
//
//	Suc s1("Suc1", 25, 2021, false, "Rosu");
//	Suc s2("Suc2", 30, 2022, true, "Galben");
//	if(areEqual(s1, s2)) {
//		cout << "sunt egale";
//	}
//	else {
//		cout << "NU sunt egale";
//	}
//
//	Bar<Suc> bar(s1);
//	bar.afisareBautura();
//	//stl
//
//	vector<Suc> sucuri;
//	sucuri.push_back(s1);
//	sucuri.push_back(s2);
//	//for (int i = 0;i < sucuri.size();i++) {
//	//	cout << sucuri[i] << endl;
//	//}
//
//	vector<Suc>::iterator it;
//	for (it = sucuri.begin();it != sucuri.end();it++) {
//		cout << *it << endl;
//	}
//
//	set<Suc> setSucuri;
//	setSucuri.insert(s1);
//	setSucuri.insert(s2);
//	for (set<Suc>::iterator it = setSucuri.begin();it != setSucuri.end();it++) {
//		cout << *it << endl;
//	}
//
//}
