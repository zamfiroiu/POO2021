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
//public:
//	Carte():ISBN("1234") {
//		nrCarti++;
//		autor = new char[strlen("Tom") + 1];
//		strcpy_s(autor, strlen("Tom") + 1, "Tom");
//		nrPagini = 120;
//		pret = 34.5;
//		titlu = "Carte";
//	}
//
//	Carte(const char* autor, int nrPagini, string titlu, float pret, string newISBN): ISBN(newISBN) {
//		this->autor = new char[strlen(autor) + 1];
//		strcpy_s(this->autor, strlen(autor) + 1, autor);
//		this->nrPagini = nrPagini;
//		this->titlu = titlu;
//		this->pret = pret;
//		nrCarti++;
//	}
//
//	~Carte() {
//		nrCarti--;
//		if (autor) {
//			delete[] autor;
//		}
//	}
//	string getTitlu() {
//		return this->titlu;
//	}
//	string getISBN() {
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
//	string getISBN() {
//		return this->ISBN;
//	}
//
//	static int getNrCarti() {
//		return nrCarti;
//	}
//
//	static void setTVA(int tva) {
//		if (tva > 0) {
//			TVA = tva;
//		}
//	}
//
//	static int getTVA() {
//		return TVA;
//	}
// };
//
//int Carte::nrCarti = 0;
//int Carte::TVA = 5;
//
//void main() {
//
//	Carte c1;
//	Carte c2("Timy", 210, "Povesti", 42.3, "ISBN1234");
//
//	cout << c2.getTitlu()<<endl;
//
//	cout << c2.getAutor();
//	c2.setAutor("Ion Barbu");
//	cout << c2.getAutor();
//
//	cout << Carte::getNrCarti() << endl;
//	cout << c2.getNrCarti();
//
//
//}