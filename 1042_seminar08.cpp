//#include<iostream>
//#include<fstream>
//
//using namespace std;
//class Carte {
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
//void main() {
//
//	ofstream fisier("fisier.txt", ios::out);
//	Carte carte("Autor3", 230, "Titlu3", 17, "1234", 2, new string[2]{ "Introducere","Concluzii" });
//	Carte carte2("Autor4", 430, "Titlu4", 17, "1234", 3, new string[3]{ "Cuprins","Introducere","Concluzii" });
//	fisier << carte;
//	fisier << carte2;
//	//
//	fisier.close();
//
//	ifstream fisierInput("fisier.txt", ios::in);
//	Carte c;
//	fisierInput >> c;
//	cout << c;
//}