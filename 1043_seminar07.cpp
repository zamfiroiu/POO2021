//#include<iostream>
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
//	Suc suc2("Fanta", 5.5f, 2021, false, "Albastru");
//	Suc suc4;
//	//operator=
//	suc4 = suc2;//operator=(suc4,suc2) ==> suc4.operator=(suc2)
//
//	Suc suc3;
//	suc3 = (suc4 = suc2); //operator=(suc3,VOID)
//
//	//operator+
//	cout << suc2.getPret() << endl;
//	//suc3 = suc2 + 5.0f;   //1 ==>
//	//suc3 = 6.0f + suc2;   //2 - functie
//	//suc3 = suc2 + suc4;//3
//	cout << suc3.getPret();
//
//	//operator ==
//
//	if (suc4 == suc3) {
//		cout << "sunt egale";
//	}
//	else {
//		cout << "NU sunt egale";
//	}
//	//operator--
//
//	cout << endl<<suc3.getPret() << " " << suc2.getPret() << endl;
//	suc3 = suc2--;
//	cout << suc3.getPret() << " " << suc2.getPret()<<endl;
//	suc3 = --suc2;
//	cout << suc3.getPret() << " " << suc2.getPret() << endl;
//	//operator cast
//
//	float pretFinal = (float)suc2;
//	cout << pretFinal;
//	//operator << si >>
//	cin >> suc2;
//	cout << suc2<<endl;
//
//}
