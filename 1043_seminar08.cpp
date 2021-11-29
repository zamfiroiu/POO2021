//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//class Suc {
//	char* denumire;
//	float pret;
//	int anProducere;
//	bool areZahar;
//	const string culoare;
//	static int nrObiecteSuc;
//	static int TVA;
//
//public:
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
//	int getAnProductie() const{
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
//		return (1 + TVA / 100.0f)* this->pret;
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
//		o << s.pret<< " ";
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
//	o << "Denumire: " << s.getDenumire()<<endl;
//	o << "Pret: " << s.getPret() << endl;
//	o << "An producere: " << s.getAnProductie() << endl;
//	o << (s.getAreZahar()?"Are":"Nu are")<<" zahar." << endl;
//	o << "Culoare: " << s.getCuloare() << endl;
//	return o;
//}
////
////tipReturnat numeFunctie(listaParametri) {
////
////}
//
//void main() {
//
//	ofstream file("fisier1043.txt", ios::app);
//	Suc suc("Suc", 20, 2021, true, "Galben");
//	Suc suc1("Cola", 15, 2020, false, "Negru");
//
//	file << suc1;//operator<<(ofstream, Suc) ==> operator<<(ostream, Suc);
//	file.close();
//
//	ifstream fileIn("fisier1043.txt", ios :: in);
//
//	Suc suc3;
//	fileIn >> suc3;
//	cout << suc3;
//
//	fileIn.close();
//
//	ofstream f("fisier1043.csv", ios::app);
//
//	cout << "Va rog introduceti caracterul despartitor:";
//	char a;
//	cin >> a;
//	suc.salvareInCSV(f,a);
//	suc1.salvareInCSV(f,a);
//	suc.salvareInCSV(f,a);
//	f.close();
//
//}
