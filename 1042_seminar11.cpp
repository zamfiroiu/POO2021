//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//
//
//class Carte {
//private:
//	char* autor;
//	int nrPagini;
//	string titlu;
//	const string ISBN;
//	static int nrCarti;
//	float pret;
//	static int TVA;
//	int nrCapitole;
//	string* capitole;
//public:
//	Carte() :ISBN("1234") {
//		nrCarti++;
//		//autor = NULL;
//		autor = new char[strlen("Tom") + 1];
//		strcpy_s(autor, strlen("Tom") + 1, "Tom");
//		nrPagini = 120;
//		pret = 34.5;
//		titlu = "Carte";
//		this->nrCapitole = 0;
//		this->capitole = NULL;
//	}
//
//	Carte(const char* autor, int nrPagini, string titlu, float pret, string newISBN, int nrCapitole, string* capitole) : ISBN(newISBN) {
//		this->autor = new char[strlen(autor) + 1];
//		strcpy_s(this->autor, strlen(autor) + 1, autor);
//		this->nrPagini = nrPagini;
//		this->titlu = titlu;
//		this->pret = pret;
//
//		this->nrCapitole = nrCapitole;
//		this->capitole = new string[nrCapitole];
//		for (int i = 0;i < nrCapitole;i++) {
//			this->capitole[i] = capitole[i];
//		}
//		nrCarti++;
//	}
//
//	Carte(const Carte& c) :ISBN(c.ISBN) {
//		if (c.autor != NULL) {
//			this->autor = new char[strlen(c.autor) + 1];
//			strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);
//		}
//		else {
//			this->autor = NULL;
//		}
//		this->nrPagini = c.nrPagini;
//		this->titlu = c.titlu;
//		this->pret = c.pret;
//		if (c.nrCapitole > 0 && c.capitole != NULL) {
//			this->nrCapitole = c.nrCapitole;
//			this->capitole = new string[c.nrCapitole];
//			for (int i = 0;i < c.nrCapitole;i++) {
//				this->capitole[i] = c.capitole[i];
//			}
//		}
//		else {
//			this->nrCapitole = 0;
//			this->capitole = NULL;
//		}
//		nrCarti++;
//	}
//
//	const Carte& operator=(const Carte& c) {
//		if (this != &c) {
//			if (this->autor)
//				delete[] this->autor;
//			this->autor = new char[strlen(c.autor) + 1];
//			strcpy_s(this->autor, strlen(c.autor) + 1, c.autor);
//			if (this->capitole) {
//				delete[]this->capitole;
//			}
//			this->capitole = new string[c.nrCapitole];
//			for (int i = 0;i < c.nrCapitole;i++) {
//				this->capitole[i] = c.capitole[i];
//			}
//			this->nrCapitole = c.nrCapitole;
//			this->nrPagini = c.nrPagini;
//			this->titlu = c.titlu;
//			this->pret = c.pret;
//
//		}
//		return *this;
//	}
//
//	int getNrPagini()const {
//		return this->nrPagini;
//	}
//
//	char* getAutor()const {
//		return this->autor;
//	}
//	string getTitlu()const {
//		return this->titlu;
//	}
//
//	~Carte() {
//		nrCarti--;
//		if (autor) {
//			delete[] autor;
//		}
//		if (capitole) {
//			delete[]capitole;
//		}
//	}
//
//	int getNrCapitole() {
//		return this->nrCapitole;
//	}
//
//	void setCapitole(int nrCapitole, string* capitole) {
//		if (this->capitole) {
//			delete[]this->capitole;
//		}
//		this->nrCapitole = nrCapitole;
//		this->capitole = new string[nrCapitole];
//		for (int i = 0;i < nrCapitole;i++) {
//			this->capitole[i] = capitole[i];
//		}
//	}
//
//	string* getCapitole() {
//		return this->capitole;
//	}
//
//	string getCapitol(int index) {
//		if (index >= 0 && index < this->nrCapitole) {
//			return this->capitole[index];
//		}
//	}
//
//	string getTitlu() {
//		return this->titlu;
//	}
//	string getISBN() const {
//		return this->ISBN;
//	}
//	float getPret() {
//		return this->pret;
//	}
//
//	void setAutor(const char* autor) {
//		if (strlen(autor) >= 3) {
//			if (this->autor) {
//				delete[]this->autor;
//			}
//			this->autor = new char[strlen(autor) + 1];
//			strcpy_s(this->autor, strlen(autor) + 1, autor);
//		}
//	}
//
//	char* getAutor() {
//		return this->autor;
//	}
//
//	void setTitlu(string titlu) {
//		if (titlu.length() >= 3) {
//			this->titlu = titlu;
//		}
//	}
//
//
//
//	static int getNrCarti() {
//		return nrCarti;
//	}
//	int getNrPagini() {
//		return nrPagini;
//	}
//
//	static void setTVA(int tva) {
//		if (tva > 0) {
//			TVA = tva;
//		}
//	}
//
//	void setNrPagini(int nrPagini) {
//		if (nrPagini > 0) {
//			this->nrPagini = nrPagini;
//		}
//	}
//
//	void setPret(int pret) {
//		if (pret > 0) {
//			this->pret = pret;
//		}
//	}
//
//
//	static int getTVA() {
//		return TVA;
//	}
//	//Carte operator+( const Carte& c2) const{
//	//	Carte c = *this;
//	//	c.setNrPagini(this->getNrPagini() + c2.getNrPagini());
//	//	return c;
//	//}
//	Carte operator+=(const Carte& c2) {
//
//		this->setNrPagini(this->getNrPagini() + c2.getNrPagini());
//		return *this;
//	}
//
//	bool operator< (const Carte& c) {
//		return this->nrPagini < c.nrPagini;
//	}
//
//	explicit operator int() {
//		return this->nrPagini;
//	}
//
//	const Carte& operator--() {
//		this->pret--;
//		return *this;
//	}
//
//	const Carte& operator--(int) {
//		Carte c = *this;
//		this->pret--;
//		return c;
//	}
//
//	friend istream& operator>>(istream& in, Carte& c) {
//		cout << "Nr pagini:";
//		int nrPagini;
//		in >> nrPagini;
//		c.setNrPagini(nrPagini);
//
//		cout << "titlu:";
//		in >> c.titlu;
//
//		cout << "Pret:";
//		in >> c.pret;
//		cout << "nr capitole";
//		in >> c.nrCapitole;
//		if (c.nrCapitole > 0) {
//			cout << "Numele capitole";
//			if (c.capitole) {
//				delete[]c.capitole;
//			}
//			c.capitole = new string[c.nrCapitole];
//			for (int i = 0;i < c.nrCapitole;i++) {
//				in >> c.capitole[i];
//			}
//		}
//		if (c.autor)
//			delete[]c.autor;
//		char aux[50];
//		cout << "Autor:";
//		in >> aux;
//		c.autor = new char[strlen(aux) + 1];
//		strcpy_s(c.autor, strlen(aux) + 1, aux);
//
//		return in;
//	}
//
//	friend ofstream& operator<<(ofstream& fisier, const Carte& c) {
//		if(c.autor)
//			fisier << c.autor << " ";
//		fisier << c.ISBN << " ";
//		fisier << c.titlu << " ";
//		fisier << c.nrPagini << " ";
//		fisier << c.pret << " ";
//		fisier << c.TVA << " ";
//		fisier << c.nrCapitole << " ";
//		if (c.capitole) {
//			for (int i = 0;i < c.nrCapitole;i++) {
//				fisier << c.capitole[i] << " ";
//			}
//		}
//
//		fisier << endl;
//		return fisier;
//	}
//
//	friend ifstream& operator>>(ifstream& fisier, Carte& c) {
//		if (c.autor) {
//			delete[] c.autor;
//		}
//		char aux[50];
//		fisier >> aux;
//		c.autor = new char[strlen(aux) + 1];
//		strcpy(c.autor, aux);
//		char aux2[50];
//		fisier >> aux2;
//		fisier >> c.titlu;
//		fisier >> c.nrPagini;
//		fisier >> c.pret;
//		int aux3 = 0;
//		fisier >> aux3; ;
//		fisier >> c.nrCapitole;
//		if (c.capitole){
//			delete[]c.capitole;
//		}
//		c.capitole = new string[c.nrCapitole];
//		for (int i = 0;i < c.nrCapitole;i++) {
//			fisier >> c.capitole[i];
//		}
//
//
//		return fisier;
//	}
//
//	void scriereFisierBinar(fstream& f) {
//		int lungime = this->titlu.length();
//		f.write((char*)&lungime, sizeof(lungime));
//		f.write((char*)this->titlu.c_str(), lungime);
//
//		f.write((char*)&this->nrPagini, sizeof(this->nrPagini));
//		f.write((char*)&this->pret, sizeof(this->pret));
//		f.write((char*)&this->nrCapitole, sizeof(this->nrCapitole));
//		for (int i = 0;i < this->nrCapitole;i++) {
//			lungime = this->capitole[i].length();
//			f.write((char*)&lungime, sizeof(lungime));
//			f.write((char*)this->capitole[i].c_str(), lungime);
//		}
//		lungime = strlen(this->autor);
//
//		f.write((char*)&lungime, sizeof(lungime));
//		f.write(this->autor, lungime);
//		char aux = '\0';
//		f.write((char*)&aux, sizeof(char));
//
//	}
//
//	void citesteFisierBinar(fstream& f) {
//		int lungime = 0;
//		f.read((char*)&lungime, sizeof(lungime));
//		this->titlu.resize(lungime);
//		f.read((char*)this->titlu.c_str(), lungime);
//
//		f.read((char*)&this->nrPagini, sizeof(this->nrPagini));
//		f.read((char*)&this->pret, sizeof(this->pret));
//		f.read((char*)&this->nrCapitole, sizeof(this->nrCapitole));
//		
//		if (this->capitole) {
//			delete[]this->capitole;
//		}
//		this->capitole = new string[this->nrCapitole];
//
//		for (int i = 0;i < this->nrCapitole;i++) {
//			f.read((char*)&lungime, sizeof(lungime));
//			this->capitole[i].resize(lungime);
//			f.read((char*)this->capitole[i].c_str(), lungime);
//		}
//
//		f.read((char*)&lungime, sizeof(lungime));
//		if (this->autor) {
//			delete[]this->autor;
//		}
//		this->autor = new char[lungime + 1];
//		f.read(this->autor, lungime+1);
//		//this->autor[lungime] = '\0';
//
//
//	}
//
//	virtual void afiseazaDescrire() {
//		cout << "Aceasta carte costa " << this->pret << ", are titlu " << this->titlu << " si are " << this->nrCapitole << " capitole" << endl;
//	}
//};
//
//int Carte::nrCarti = 0;
//int Carte::TVA = 5;
//
//Carte operator+(const Carte& c1, const Carte& c2) {
//	Carte c = c1;
//	c.setNrPagini(c1.getNrPagini() + c2.getNrPagini());
//	return c;
//}
//
//
//Carte operator+(const Carte& c1, int nrPagini) {
//	Carte c = c1;
//	c.setNrPagini(c1.getNrPagini() + nrPagini);
//	return c;
//}
//
//ostream& operator<<(ostream& out, const Carte& c) {
//	out << "ISBN:" << c.getISBN() << endl;
//	out << "Nr.pagini:" << c.getNrPagini() << endl;
//	if (c.getAutor()) {
//		out << "Autor:" << c.getAutor() << endl;
//	}
//	out << "Titlu:" << c.getTitlu() << endl;
//	out << "TVA:" << c.getTVA() << endl;
//	//geteri pentru capitole
//	return out;
//}
//
//
//
//class CartePentruCopii : public Carte {
//private:
//	bool areIlustratii;
//	int varstaRecomandata;
//	int nrPersonaje;
//	string* personaje;
//
//public:
//	void afiseazaDescrire() {
//		cout << "Aceasta carte pentru copii este recomandata copiilor cu varsta peste " 
//			<< this->varstaRecomandata << " ani si are " << this->nrPersonaje << " personaje" << endl;
//	}
//	CartePentruCopii() :Carte("Ion Creanga", 12, "Punguta cu doi bani", 23, "ISNBRO1234", 3, new string[3]{ "cap 1","cap 2", "cap 3" }) {
//		this->areIlustratii = true;
//		this->varstaRecomandata = 5;
//		this->nrPersonaje = 4;
//		this->personaje = new string[this->nrPersonaje];
//		this->personaje[0] = "Andrei";
//		this->personaje[1] = "Ioana";
//		this->personaje[2] = "Alex";
//		this->personaje[3] = "Flavia";
//
//	}
//
//	CartePentruCopii(bool areIlustratii, int varstaRecomandata, int nrPersonaje, const string* persoanje): Carte() {
//		this->areIlustratii = areIlustratii;
//		this->varstaRecomandata = varstaRecomandata;
//		this->nrPersonaje = nrPersonaje;
//		this->personaje = new string[this->nrPersonaje];
//		for (int i = 0;i < this->nrPersonaje;i++) {
//			this->personaje[i] = persoanje[i];
//		}
//	}
//
//	CartePentruCopii(const char* autor, int nrPagini, string titlu, float pret, string newISBN, int nrCapitole, string* capitole, bool areIlustratii, int varstaRecomandataPrimita, int nrPersonaje, const string* persoanje) 
//		: Carte(autor, nrPagini, titlu, pret, newISBN, nrCapitole, capitole), varstaRecomandata(varstaRecomandataPrimita)
//	
//	{		
//		this->areIlustratii = areIlustratii;
//		this->nrPersonaje = nrPersonaje;
//		this->personaje = new string[this->nrPersonaje];
//		for (int i = 0;i < this->nrPersonaje;i++) {
//			this->personaje[i] = persoanje[i];
//		}
//	}
//	CartePentruCopii(const CartePentruCopii& cc) :Carte(cc) {
//		this->areIlustratii = cc.areIlustratii;
//		this->varstaRecomandata = cc.varstaRecomandata;
//		if (cc.nrPersonaje > 0) {
//			this->nrPersonaje = cc.nrPersonaje;
//			this->personaje = new string[this->nrPersonaje];
//			for (int i = 0;i < this->nrPersonaje;i++) {
//				this->personaje[i] = cc.personaje[i];
//			}
//		}
//		else {
//			this->personaje = NULL;
//			this->nrPersonaje = 0;
//		}
//	}
//
//	const CartePentruCopii& operator=(const CartePentruCopii& cc) {
//		if (this != &cc) {
//			Carte::operator=(cc);
//			this->areIlustratii = cc.areIlustratii;
//			this->varstaRecomandata = cc.varstaRecomandata;
//			if (this->personaje) {
//				delete[]this->personaje;
//			}
//			if (cc.nrPersonaje > 0) {
//				this->nrPersonaje = cc.nrPersonaje;
//				this->personaje = new string[this->nrPersonaje];
//				for (int i = 0;i < this->nrPersonaje;i++) {
//					this->personaje[i] = cc.personaje[i];
//				}
//			}
//			else {
//				this->personaje = NULL;
//				this->nrPersonaje = 0;
//			}
//		}
//		return *this;
//	}
//
//	~CartePentruCopii(){
//		if (this->personaje) {
//			delete[]this->personaje;
//		}
//	}
//	friend ostream& operator<<(ostream& o, const CartePentruCopii& cc) {
//		o << (Carte)cc;
//		o << "Are ilustratii" << cc.areIlustratii << endl;
//		o << "Varsta recomandata" << cc.varstaRecomandata << endl;
//		o << "Numarul de personaje" << cc.nrPersonaje << endl;
//		if (cc.nrPersonaje > 0) {
//			for (int i = 0;i < cc.nrPersonaje;i++) {
//				o << cc.personaje[i] << " ";
//			}
//			cout << endl;
//		}
//		return o;
//	}
//};
//
//class Librarie {
//private:
//	int nrCarti;
//	Carte** carti;
//	string nume;
//public:
//	Librarie() {
//		this->nrCarti = 0;
//		this->carti = NULL;
//		this->nume = "Librarie";
//	}
//	Librarie(int pNrCarti, Carte** pCarti,string pNume) {
//		this->nrCarti = pNrCarti;
//		this->carti = new Carte * [pNrCarti];
//			for (int i = 0;i < pNrCarti;i++) {
//				this->carti[i] = pCarti[i];//shallow copy
//		}
//		this->nume = pNume;
//	}
//	Librarie(const Librarie& p) {
//		this->nrCarti = p.nrCarti;
//		if (p.carti) {
//			this->carti = new Carte * [p.nrCarti];
//			for (int i = 0;i < p.nrCarti;i++) {
//				this->carti[i] = p.carti[i];//shallow copy
//			}
//		}
//		else {
//			this->carti = NULL;
//		}
//		this->nume = p.nume;
//	}
//	Librarie operator=(const Librarie& p) {
//		if (this != &p) {
//			this->nrCarti = p.nrCarti;
//			if (p.carti) {
//				if (this->carti) {
//					delete[]this->carti;//nu stergem pointerii deoarece am facut shallow copy
//				}
//				this->carti = new Carte * [p.nrCarti];
//				for (int i = 0;i < p.nrCarti;i++) {
//					this->carti[i] = p.carti[i];//shallow copy
//				}
//			}
//			else {
//				this->carti = NULL;
//			}
//			this->nume = p.nume;
//		}
//		return *this;
//	}
//
//	~Librarie() {
//		if (this->carti) {
//			delete[]this->carti;
//		}
//	}
//	void prezintaCarti() {
//		for (int i = 0;i < nrCarti;i++) {
//			this->carti[i]->afiseazaDescrire();
//		}
//	}
//
//};
//
//
//void main() {
//
//	int nrCarti = 2;
//	Carte** carti = new Carte * [nrCarti];
//	carti[0] = new Carte("Autor", 3, "carte", 23, "ISN1234", 3, new string[3]{ "Cap1", "cap2","cap3"});
//	carti[1] = new CartePentruCopii(true, 12, 2, new string[2]{"Personaj 1","Persoanj 2"});
//	string nume = "Librarie Noua";
//	Librarie librarie(nrCarti, carti, nume);
//	Librarie l2 = librarie;
//	Librarie l3;
//	l3 = l2;
//	
//	librarie.prezintaCarti();
//	
//	
//	if (carti!=NULL) {
//		for (int i = 0;i < nrCarti;i++) {
//			if (carti[i]) {
//				delete carti[i];
//			}
//		}
//		delete[]carti;
//	}
//}