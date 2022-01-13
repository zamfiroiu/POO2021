//#include<iostream>
//#include<fstream>
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
//	Spital() :nrSpital(12) {
//		this->nrPacienti = 45;
//		this->nume = "Floreasca";
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = 10 + i;
//		}
//		nrObiecteSpital++;
//	}
//	Spital(int nrPacienti, string nume, const int* varstePacienti, int newNrSpital) :nrSpital(newNrSpital) {
//		this->nrPacienti = nrPacienti;
//		this->nume = nume;
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = varstePacienti[i];
//		}
//		nrObiecteSpital++;
//	}
//
//	Spital(const Spital& s) :nrSpital(s.nrSpital) {
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
//	const Spital& operator=(const Spital& s) {
//		if (this != &s) {
//			this->nrPacienti = s.nrPacienti;
//			this->nume = s.nume;
//			if (this->varstePacienti) {
//				delete[]this->varstePacienti;
//			}
//			this->varstePacienti = new int[s.nrPacienti];
//			for (int i = 0;i < s.nrPacienti;i++) {
//				this->varstePacienti[i] = s.varstePacienti[i];
//			}
//		}
//		return *this;
//	}
//
//	int getNrPacienti()const {
//		return this->nrPacienti;
//	}
//
//	int getNrSpital()const {
//		return nrSpital;
//	}
//	static int getNrObiecteSpital() {
//		return nrObiecteSpital;
//	}
//	static int getReducereCAS() {
//		return reducereCAS;
//	}
//	string getNume() const {
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
//	int* getVarstePacienti() const {
//		return this->varstePacienti;
//	}
//
//	int getVarstaPacient(int pozitie) const {
//		if (pozitie >= 0 && pozitie < nrPacienti) {
//			return this->varstePacienti[pozitie];
//		}
//	}
//
//	Spital operator+(const Spital& s) {
//		Spital aux = *this;
//		aux.nrPacienti = this->nrPacienti + s.nrPacienti;
//		if (aux.varstePacienti) {
//			delete[]aux.varstePacienti;
//		}
//		aux.varstePacienti = new int[aux.nrPacienti];
//		for (int i = 0;i < this->nrPacienti;i++)
//		{
//			aux.varstePacienti[i] = this->varstePacienti[i];
//		}
//		for (int i = this->nrPacienti;i < aux.nrPacienti;i++) {
//			aux.varstePacienti[i] = s.varstePacienti[i - this->nrPacienti];
//		}
//
//		//o alta varianta
//		for (int i = 0;i < s.nrPacienti;i++) {
//			aux.varstePacienti[this->nrPacienti + i] = s.varstePacienti[i];
//		}
//
//		return aux;
//	}
//
//	bool operator!=(const Spital& s) {
//		if (this->nrPacienti == s.nrPacienti) {
//			return false;
//		}
//		if (this->nume.compare(s.nume) == 0) {
//			return false;
//		}
//		return true;
//	}
//
//	const Spital& operator--() {
//		if (this->nrPacienti >= 0) {
//			this->nrPacienti--;
//			int* v = new int[this->nrPacienti];
//			if (varstePacienti != NULL) {
//
//				for (int i = 0;i < this->nrPacienti;i++) {
//					v[i] = varstePacienti[i];
//				}
//				delete[]this->varstePacienti;
//				this->varstePacienti = v;
//			}
//		}
//		else {
//			this->varstePacienti = NULL;
//		}
//		return *this;
//	}
//
//	Spital operator--(int) {
//		Spital copie = *this;
//		if (this->nrPacienti >= 0) {
//			this->nrPacienti--;
//			int* v = new int[this->nrPacienti];
//			if (this->varstePacienti != NULL) {
//
//				for (int i = 0;i < this->nrPacienti;i++) {
//					v[i] = this->varstePacienti[i];
//				}
//				delete[]this->varstePacienti;
//				this->varstePacienti = v;
//			}
//		}
//		else {
//			this->varstePacienti = NULL;
//		}
//		return copie;
//	}
//
//	explicit operator float() {
//		float sumaVarste = 0;
//		for (int i = 0;i < this->nrPacienti;i++) {
//			sumaVarste += this->varstePacienti[i];
//		}
//		if (this->nrPacienti > 0) {
//			return sumaVarste / this->nrPacienti;
//		}
//		else { return 0; }
//	}
//	friend istream& operator>>(istream& input, Spital& s) {
//		cout << "Numele spitalului:";
//		input >> s.nume;
//		cout << "Numar pacienti:";
//		input >> s.nrPacienti;
//		if (s.varstePacienti != NULL) {
//			delete[]s.varstePacienti;
//		}
//		if (s.nrPacienti > 0) {
//			s.varstePacienti = new int[s.nrPacienti];
//			for (int i = 0;i < s.nrPacienti;i++) {
//				cout << "Varsta pacientului " << (i + 1) << ":";
//				input >> s.varstePacienti[i];
//			}
//		}
//		else {
//			s.varstePacienti = NULL;
//		}
//		return input;
//	}
//
//	friend ifstream& operator>>(ifstream& input, Spital& s) {
//		input >> s.nume;
//		int aux;
//		input >> aux;
//		input >> s.nrPacienti;
//		if (s.varstePacienti != NULL) {
//			delete[]s.varstePacienti;
//		}
//		if (s.nrPacienti > 0) {
//			s.varstePacienti = new int[s.nrPacienti];
//			for (int i = 0;i < s.nrPacienti;i++) {
//				input >> s.varstePacienti[i];
//			}
//		}
//		else {
//			s.varstePacienti = NULL;
//		}
//		return input;
//	}
//
//	friend ofstream& operator<<(ofstream& o, const Spital& sp) {
//		o << sp.nume << " ";
//		o << sp.nrSpital << " ";
//		o << sp.nrPacienti << " ";
//		for (int i = 0;i < sp.nrPacienti;i++) {
//			o << sp.varstePacienti[i] << " ";
//		}
//		o << endl;
//		return o;
//	}
//
//	void scrieInCSV(ofstream& f) {
//		f << this->nume << ",";
//		f << this->nrSpital << ",";
//		f << this->nrPacienti << ",";
//		for (int i = 0;i < this->nrPacienti;i++) {
//			f << this->varstePacienti[i] << ",";
//		}
//		f << endl;
//	}
//
//	void scrieInFisierBinar(ofstream& file) {
//		int lungime = nume.length();
//		file.write((char*)&lungime, sizeof(lungime));
//		file.write((char*)nume.c_str(), lungime);
//
//		file.write((char*)&this->nrPacienti, sizeof(this->nrPacienti));
//		for (int i = 0;i < this->nrPacienti;i++) {
//			file.write((char*)&this->varstePacienti[i], sizeof(this->varstePacienti[i]));
//		}
//
//	}
//
//	void citesteDinFisierBinar(fstream& file) {
//		int lungime = 0;
//		file.read((char*)&lungime, sizeof(lungime));
//		nume.resize(lungime);
//		file.read((char*)nume.c_str(), lungime);
//		
//		file.read((char*)&this->nrPacienti, sizeof(this->nrPacienti));
//		if (this->varstePacienti) {
//			delete[]this->varstePacienti;
//		}
//		this->varstePacienti = new int[this->nrPacienti];
//		for (int i = 0;i < this->nrPacienti;i++) {
//			file.read((char*)&this->varstePacienti[i], sizeof(this->varstePacienti[i]));
//		}
//		
//	}
//
//};
//
//int Spital::nrObiecteSpital = 0;
//int Spital::reducereCAS = 12;
//
//Spital operator+ (int varsta, const Spital& s) {
//	Spital aux = s;
//	int* v = new int[aux.getNrPacienti() + 1];
//	for (int i = 0;i < aux.getNrPacienti();i++) {
//		v[i] = aux.getVarstaPacient(i);
//	}
//	v[aux.getNrPacienti()] = varsta;
//	aux.setVarstePacienti(aux.getNrPacienti() + 1, v);
//	delete[]v;
//	return aux;
//}
//
//ostream& operator<<(ostream& o, const Spital& sp) {
//	o << "Nume:" << sp.getNume() << endl;
//	o << "nr paienti: " << sp.getNrPacienti() << endl;
//	o << "Nr. spital:" << sp.getNrSpital() << endl;
//	for (int i = 0;i < sp.getNrPacienti();i++) {
//		o << sp.getVarstaPacient(i) << " ";
//	}
//	return o;
//}
//
//class SpitalPediatric : public Spital {
//	char* adresa;
//	string tipVaccinRealizat;
//
//public:
//	SpitalPediatric() :Spital(5, "Militar", new int[5]{10,12,14,7,9},3) {
//		this->adresa = new char[strlen("Bucuresti") + 1];
//		strcpy(this->adresa, "Bucuresti");
//		this->tipVaccinRealizat = "Pojar";
//	}
//
//	SpitalPediatric(const char* adresa, string tipVaccin) :Spital() {
//		this->setVarstePacienti(3, new int[3]{ 10,12,3 });
//		this->adresa = new char[strlen(adresa) + 1];
//		strcpy(this->adresa, adresa);
//		this->tipVaccinRealizat = tipVaccin;
//	}
//
//	SpitalPediatric(const char* adresa, string tipVaccin, int nrPacienti, string nume, const int* varstePacienti, int newNrSpital) 
//		:Spital(nrPacienti, nume, varstePacienti, newNrSpital),tipVaccinRealizat(tipVaccin) {
//		this->adresa = new char[strlen(adresa) + 1];
//		strcpy(this->adresa, adresa);
//	}
//
//	~SpitalPediatric() {
//		if (this->adresa) {
//			delete[]this->adresa;
//		}
//	}
//
//	const SpitalPediatric& operator=(const SpitalPediatric& sp) {
//		(Spital)*this = (Spital)sp;
//		Spital::operator=(sp);
//		if (this->adresa) {
//			delete[]this->adresa;
//		}
//		this->adresa = new char[strlen(sp.adresa) + 1];
//		strcpy(this->adresa, sp.adresa);
//		this->tipVaccinRealizat = sp.tipVaccinRealizat;
//		return *this;
//	}
//
//	SpitalPediatric(const SpitalPediatric& sp):Spital(sp) {
//		this->adresa = new char[strlen(sp.adresa) + 1];
//		strcpy(this->adresa, sp.adresa);
//		this->tipVaccinRealizat = sp.tipVaccinRealizat;
//	}
//
//	friend ostream& operator<<(ostream& o, const SpitalPediatric& sp) {
//		o << (Spital)sp;
//		o << sp.adresa<<endl;
//		o << sp.tipVaccinRealizat<<endl;
//
//		return o;
//	}
//
//};
//
//void main() {
//	SpitalPediatric sp1;
//	SpitalPediatric sp2("Adresa", "Pojar", 2, "Spital", new int[2]{ 7,5 }, 1);
//	SpitalPediatric sp3("Adresa", "Pojar");
//	SpitalPediatric sp4 = sp3;
//	sp2 = sp3;
//
//
//	cout << sp2<<sp1;
//
//}