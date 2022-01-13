#include<iostream>
#include<fstream>
#include<vector>
#include<set>

using namespace std;


class SpitalAbstract {
public:
	virtual void descrieSpital() = 0;
	virtual ~SpitalAbstract() {

	}
};

class Spital : public SpitalAbstract {
	string nume;
	int nrPacienti;
	int* varstePacienti;
	const int nrSpital;
	static int nrObiecteSpital;
	static int reducereCAS;
public:
	Spital() :SpitalAbstract(), nrSpital(12) {
		this->nrPacienti = 45;
		this->nume = "Floreasca";
		this->varstePacienti = new int[nrPacienti];
		for (int i = 0;i < nrPacienti;i++) {
			this->varstePacienti[i] = 10 + i;
		}
		nrObiecteSpital++;
	}
	Spital(int nrPacienti, string nume, const int* varstePacienti, int newNrSpital) :SpitalAbstract(), nrSpital(newNrSpital) {
		this->nrPacienti = nrPacienti;
		this->nume = nume;
		this->varstePacienti = new int[nrPacienti];
		for (int i = 0;i < nrPacienti;i++) {
			this->varstePacienti[i] = varstePacienti[i];
		}
		nrObiecteSpital++;
	}

	Spital(const Spital& s) :SpitalAbstract(), nrSpital(s.nrSpital) {
		this->nrPacienti = s.nrPacienti;
		this->nume = s.nume;
		this->varstePacienti = new int[s.nrPacienti];
		for (int i = 0;i < s.nrPacienti;i++) {
			this->varstePacienti[i] = s.varstePacienti[i];
		}
		nrObiecteSpital++;
	}
	~Spital() {
		nrObiecteSpital--;
		if (this->varstePacienti) {
			delete[]this->varstePacienti;
		}
	}

	const Spital& operator=(const Spital& s) {
		if (this != &s) {
			this->nrPacienti = s.nrPacienti;
			this->nume = s.nume;
			if (this->varstePacienti) {
				delete[]this->varstePacienti;
			}
			this->varstePacienti = new int[s.nrPacienti];
			for (int i = 0;i < s.nrPacienti;i++) {
				this->varstePacienti[i] = s.varstePacienti[i];
			}
		}
		return *this;
	}

	int getNrPacienti()const {
		return this->nrPacienti;
	}

	int getNrSpital()const {
		return nrSpital;
	}
	static int getNrObiecteSpital() {
		return nrObiecteSpital;
	}
	static int getReducereCAS() {
		return reducereCAS;
	}
	string getNume() const {
		return this->nume;
	}
	void setNume(string nume) {
		if (nume.length() > 2) {
			this->nume = nume;
		}
	}

	static void setReducereCAS(int reducere) {
		if (reducere > 0 && reducere <= 100) {
			reducereCAS = reducere;
		}
	}

	void setVarstePacienti(int nrPacienti, int* varste) {
		if (nrPacienti > 0 && varste != NULL) {
			this->nrPacienti = nrPacienti;
			if (this->varstePacienti != NULL) {
				delete[]this->varstePacienti;
			}
			this->varstePacienti = new int[nrPacienti];
			for (int i = 0;i < nrPacienti;i++) {
				this->varstePacienti[i] = varste[i];
			}

		}
	}

	int* getVarstePacienti() const {
		return this->varstePacienti;
	}

	int getVarstaPacient(int pozitie) const {
		if (pozitie >= 0 && pozitie < nrPacienti) {
			return this->varstePacienti[pozitie];
		}
	}

	Spital operator+(const Spital& s) {
		Spital aux = *this;
		aux.nrPacienti = this->nrPacienti + s.nrPacienti;
		if (aux.varstePacienti) {
			delete[]aux.varstePacienti;
		}
		aux.varstePacienti = new int[aux.nrPacienti];
		for (int i = 0;i < this->nrPacienti;i++)
		{
			aux.varstePacienti[i] = this->varstePacienti[i];
		}
		for (int i = this->nrPacienti;i < aux.nrPacienti;i++) {
			aux.varstePacienti[i] = s.varstePacienti[i - this->nrPacienti];
		}

		//o alta varianta
		for (int i = 0;i < s.nrPacienti;i++) {
			aux.varstePacienti[this->nrPacienti + i] = s.varstePacienti[i];
		}

		return aux;
	}

	bool operator!=(const Spital& s) {
		if (this->nrPacienti == s.nrPacienti) {
			return false;
		}
		if (this->nume.compare(s.nume) == 0) {
			return false;
		}
		return true;
	}
	bool operator==(const Spital& s) {
		return this->nume.compare(s.nume) == 0;
	}

	bool operator< (const Spital& s) const {
		return this->nrSpital < s.nrSpital;
	}

	const Spital& operator--() {
		if (this->nrPacienti >= 0) {
			this->nrPacienti--;
			int* v = new int[this->nrPacienti];
			if (varstePacienti != NULL) {

				for (int i = 0;i < this->nrPacienti;i++) {
					v[i] = varstePacienti[i];
				}
				delete[]this->varstePacienti;
				this->varstePacienti = v;
			}
		}
		else {
			this->varstePacienti = NULL;
		}
		return *this;
	}

	Spital operator--(int) {
		Spital copie = *this;
		if (this->nrPacienti >= 0) {
			this->nrPacienti--;
			int* v = new int[this->nrPacienti];
			if (this->varstePacienti != NULL) {

				for (int i = 0;i < this->nrPacienti;i++) {
					v[i] = this->varstePacienti[i];
				}
				delete[]this->varstePacienti;
				this->varstePacienti = v;
			}
		}
		else {
			this->varstePacienti = NULL;
		}
		return copie;
	}

	explicit operator float() {
		float sumaVarste = 0;
		for (int i = 0;i < this->nrPacienti;i++) {
			sumaVarste += this->varstePacienti[i];
		}
		if (this->nrPacienti > 0) {
			return sumaVarste / this->nrPacienti;
		}
		else { return 0; }
	}
	friend istream& operator>>(istream& input, Spital& s) {
		cout << "Numele spitalului:";
		input >> s.nume;
		cout << "Numar pacienti:";
		input >> s.nrPacienti;
		if (s.varstePacienti != NULL) {
			delete[]s.varstePacienti;
		}
		if (s.nrPacienti > 0) {
			s.varstePacienti = new int[s.nrPacienti];
			for (int i = 0;i < s.nrPacienti;i++) {
				cout << "Varsta pacientului " << (i + 1) << ":";
				input >> s.varstePacienti[i];
			}
		}
		else {
			s.varstePacienti = NULL;
		}
		return input;
	}

	friend ifstream& operator>>(ifstream& input, Spital& s) {
		input >> s.nume;
		int aux;
		input >> aux;
		input >> s.nrPacienti;
		if (s.varstePacienti != NULL) {
			delete[]s.varstePacienti;
		}
		if (s.nrPacienti > 0) {
			s.varstePacienti = new int[s.nrPacienti];
			for (int i = 0;i < s.nrPacienti;i++) {
				input >> s.varstePacienti[i];
			}
		}
		else {
			s.varstePacienti = NULL;
		}
		return input;
	}

	friend ofstream& operator<<(ofstream& o, const Spital& sp) {
		o << sp.nume << " ";
		o << sp.nrSpital << " ";
		o << sp.nrPacienti << " ";
		for (int i = 0;i < sp.nrPacienti;i++) {
			o << sp.varstePacienti[i] << " ";
		}
		o << endl;
		return o;
	}

	void scrieInCSV(ofstream& f) {
		f << this->nume << ",";
		f << this->nrSpital << ",";
		f << this->nrPacienti << ",";
		for (int i = 0;i < this->nrPacienti;i++) {
			f << this->varstePacienti[i] << ",";
		}
		f << endl;
	}

	void scrieInFisierBinar(ofstream& file) {
		int lungime = nume.length();
		file.write((char*)&lungime, sizeof(lungime));
		file.write(nume.c_str(), lungime);

		file.write((char*)&this->nrPacienti, sizeof(this->nrPacienti));
		for (int i = 0;i < this->nrPacienti;i++) {
			file.write((char*)&this->varstePacienti[i], sizeof(this->varstePacienti[i]));
		}

	}

	//scriere la consola - op<<ostream
	//scrire fiserBInar - op<<fstream sau metoda scrieBinar
	//citire Fisier BInar - 

	void citesteDinFisierBinar(fstream& file) {
		int lungime = 0;
		file.read((char*)&lungime, sizeof(lungime));
		nume.resize(lungime);
		file.read((char*)nume.c_str(), lungime);

		file.read((char*)&this->nrPacienti, sizeof(this->nrPacienti));
		if (this->varstePacienti) {
			delete[]this->varstePacienti;
		}
		this->varstePacienti = new int[this->nrPacienti];
		for (int i = 0;i < this->nrPacienti;i++) {
			file.read((char*)&this->varstePacienti[i], sizeof(this->varstePacienti[i]));
		}

	}
	friend ostream& operator<<(ostream& o, const Spital& sp);

	virtual void afiseazaDescriere() {
		cout << *this << endl << endl;
		//operator<<(cout, *this)<<endl<<endl;
	}

	void descrieSpital() {
		afiseazaDescriere();
	}

};

int Spital::nrObiecteSpital = 0;
int Spital::reducereCAS = 12;

Spital operator+ (int varsta, const Spital& s) {
	Spital aux = s;
	int* v = new int[aux.getNrPacienti() + 1];
	for (int i = 0;i < aux.getNrPacienti();i++) {
		v[i] = aux.getVarstaPacient(i);
	}
	v[aux.getNrPacienti()] = varsta;
	aux.setVarstePacienti(aux.getNrPacienti() + 1, v);
	delete[]v;
	return aux;
}

ostream& operator<<(ostream& o, const Spital& sp) {
	o << "Nume:" << sp.getNume() << endl;
	o << "nr paienti: " << sp.getNrPacienti() << endl;
	o << "Nr. spital:" << sp.getNrSpital() << endl;
	for (int i = 0;i < sp.getNrPacienti();i++) {
		o << sp.getVarstaPacient(i) << " ";
	}
	return o;
}

class SpitalPediatric : public Spital {
	char* adresa;
	string tipVaccinRealizat;

public:
	SpitalPediatric() :Spital(5, "Militar", new int[5]{ 10,12,14,7,9 }, 3) {
		this->adresa = new char[strlen("Bucuresti") + 1];
		strcpy(this->adresa, "Bucuresti");
		this->tipVaccinRealizat = "Pojar";
	}

	SpitalPediatric(const char* adresa, string tipVaccin) :Spital() {
		this->setVarstePacienti(3, new int[3]{ 10,12,3 });
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->tipVaccinRealizat = tipVaccin;
	}

	SpitalPediatric(const char* adresa, string tipVaccin, int nrPacienti, string nume, const int* varstePacienti, int newNrSpital)
		:Spital(nrPacienti, nume, varstePacienti, newNrSpital), tipVaccinRealizat(tipVaccin) {
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
	}

	~SpitalPediatric() {
		if (this->adresa) {
			delete[]this->adresa;
		}
	}

	const SpitalPediatric& operator=(const SpitalPediatric& sp) {
		(Spital)*this = (Spital)sp;
		Spital::operator=(sp);
		if (this->adresa) {
			delete[]this->adresa;
		}
		this->adresa = new char[strlen(sp.adresa) + 1];
		strcpy(this->adresa, sp.adresa);
		this->tipVaccinRealizat = sp.tipVaccinRealizat;
		return *this;
	}

	SpitalPediatric(const SpitalPediatric& sp) :Spital(sp) {
		this->adresa = new char[strlen(sp.adresa) + 1];
		strcpy(this->adresa, sp.adresa);
		this->tipVaccinRealizat = sp.tipVaccinRealizat;
	}

	friend ostream& operator<<(ostream& o, const SpitalPediatric& sp) {
		o << (Spital)sp;
		o << "Adresa" << sp.adresa << endl;
		o << "Tip vaccin" << sp.tipVaccinRealizat << endl;

		return o;
	}

	void afiseazaDescriere() {
		cout << *this << endl << endl;
	}
	void descrieSpital() {
		afiseazaDescriere();
	}

};

class OrasCuSpitale {

	string numeOras;
	int nrSpitale;
	Spital** spitale;
public:
	//acest seter este gresit
	void setNrSpitale(int nr) {
		this->nrSpitale = nr;
	}
	int getNrSpitale() {
		return this->nrSpitale;
	}
	Spital** getSpitale() {
		return this->spitale;
	}
	OrasCuSpitale() {
		this->numeOras = "";
		this->nrSpitale = 0;
		this->spitale = NULL;
	}

	OrasCuSpitale(string numeOras, int nrSpitale, Spital** spitale) {
		this->numeOras = numeOras;
		if (nrSpitale > 0) {
			this->nrSpitale = nrSpitale;
			this->spitale = new Spital * [nrSpitale];
			for (int i = 0;i < nrSpitale;i++) {
				this->spitale[i] = spitale[i];
			}
		}
		else {
			this->nrSpitale = 0;
			this->spitale = NULL;
		}
	}

	OrasCuSpitale(const OrasCuSpitale& os) {
		this->numeOras = os.numeOras;
		if (os.nrSpitale > 0) {
			this->nrSpitale = os.nrSpitale;
			this->spitale = new Spital * [os.nrSpitale];
			for (int i = 0;i < os.nrSpitale;i++) {
				this->spitale[i] = os.spitale[i];
			}
		}
		else {
			this->nrSpitale = 0;
			this->spitale = NULL;
		}
	}

	const OrasCuSpitale& operator=(const OrasCuSpitale& os) {
		if (this != &os) {
			this->numeOras = os.numeOras;
			if (this->spitale) {
				delete[]this->spitale;
			}
			if (os.nrSpitale > 0) {
				this->nrSpitale = os.nrSpitale;
				this->spitale = new Spital * [os.nrSpitale];
				for (int i = 0;i < os.nrSpitale;i++) {
					this->spitale[i] = os.spitale[i];
				}
			}
			else {
				this->nrSpitale = 0;
				this->spitale = NULL;
			}
		}
		return *this;
	}

	~OrasCuSpitale() {
		if (this->spitale) {
			delete[]this->spitale;
		}
	}

	void raportareSpitale() {
		if (this->nrSpitale <= 0) {
			throw new exception();
		}
		for (int i = 0;i < nrSpitale;i++) {
			if (spitale[i] != NULL) {
				spitale[i]->descrieSpital();
			}
			else {
				throw 307;
			}
		}

	}

};

template<typename T>
bool suntEgale(T p1, T p2) {
	return p1 == p2;
}

void main() {

	//template

	if (suntEgale(3, 3)) {
		cout << "Egale" << endl;
	}
	else {
		cout << "Nu sunt egale"<<endl;
	}
	Spital s1(2, "spital", new int[2]{ 23,45 }, 100);
	Spital s2(3, "Spital 2", new int[3]{ 43,45,52 }, 45);
	if (suntEgale(s1, s2)) {
		cout << "Egale" << endl;
	}
	else {
		cout << "Nu sunt egale" << endl;
	}

	//detructor virtual
	SpitalAbstract* ps;
	ps = new Spital();
	ps->descrieSpital();
	delete ps;

	ps = new SpitalPediatric();
	ps->descrieSpital();
	delete ps;

	//stl
	vector<int> valori;
	valori.push_back(5);
	valori.push_back(8);
	valori.push_back(2);

	cout << endl << endl;
	for (int i = 0;i < valori.size();i++) {
		cout << valori[i] << endl;
	}

	for (vector<int>::iterator it = valori.begin();it != valori.end();it++) {
		cout << *it;
	}

	set<Spital> spitale;
	spitale.insert(s1);
	spitale.insert(s2);
	spitale.insert(Spital(2, "SPital nou", new int[] {45,47},89));

	set<Spital>::iterator it = spitale.begin();
	while (it != spitale.end()) {
		cout << *it;
		it++;
	}







}