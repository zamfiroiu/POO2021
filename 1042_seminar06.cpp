//#include<iostream>
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
//		return nrPagini;
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
//		return nrCapitole;
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
//	string getISBN() const{
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
//void main() {
//
////operator =
//	// operator +
//	// operator < > ==!= <= >=
//	//operator de cast
//	//operator << >>
//	//operator unar ++ --
//
//	Carte c;
//	Carte c1;
//	Carte c2;
//	
//	//c2 = c;
//
//	//c = c1 = c2;
//	cout << c.getNrPagini();
//	c = c1 + c2;
//	cout << c.getNrPagini();
//	//c = c1 + 56.7f;
//	//c=56.7f+c1;
//
//	c += c1;//c=c+c1;
//
//}