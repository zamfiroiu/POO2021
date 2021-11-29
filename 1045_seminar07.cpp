//#include<iostream>
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
//	Spital():nrSpital(12){
//		this->nrPacienti = 45;
//		this->nume = "Floreasca";
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = 10 + i;
//		}
//		nrObiecteSpital++;
//	}
//	Spital(int nrPacienti, string nume, const int* varstePacienti, int newNrSpital):nrSpital(newNrSpital) {
//		this->nrPacienti = nrPacienti;
//		this->nume = nume;
//		this->varstePacienti = new int[nrPacienti];
//		for (int i = 0;i < nrPacienti;i++) {
//			this->varstePacienti[i] = varstePacienti[i];
//		}
//		nrObiecteSpital++;
//	}
//
//	Spital(const Spital& s):nrSpital(s.nrSpital) {
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
// 		return *this;
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
//	string getNume() const{
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
//	int getVarstaPacient(int pozitie) const{
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
//		////o alta varianta
//		//for (int i = 0;i < s.nrPacienti;i++) {
//		//	aux.varstePacienti[this->nrPacienti + i] = s.varstePacienti[i];
//		//}
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
//	 Spital operator--(int) {
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
//	 operator float() {
//		 float sumaVarste = 0;
//		 for (int i = 0;i < this->nrPacienti;i++) {
//			 sumaVarste += this->varstePacienti[i];
//		 }
//		 if (this->nrPacienti > 0) {
//			 return sumaVarste / this->nrPacienti;
//		 }
//		 else { return 0; }
//	 }
//	 friend istream& operator>>(istream& input, Spital& s) {
//		 cout << "Numele spitalului:";
//		 input >> s.nume;
//		 cout << "Numar pacienti:";
//		 input >> s.nrPacienti;
//		 if (s.varstePacienti != NULL) {
//			 delete[]s.varstePacienti;
//		 }
//		 if (s.nrPacienti > 0) {
//			 s.varstePacienti = new int[s.nrPacienti];
//			 for (int i = 0;i < s.nrPacienti;i++) {
//				 cout << "Varsta pacientului " << (i + 1) << ":";
//				 input >> s.varstePacienti[i];
//			 }
//		 }
//		 else {
//			 s.varstePacienti = NULL;
//		 }
//		 return input;
//	 }
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
//	o << sp.getNume() << endl;
//	o << sp.getNrPacienti() << endl;
//	o << sp.getNrSpital() << endl;
//	for (int i = 0;i < sp.getNrPacienti();i++) {
//		o << sp.getVarstaPacient(i) << " ";
//	}
//	return o;
//}
//
//void main() {
//	Spital::getNrObiecteSpital();
//	Spital spital1;
//	Spital spital2(5, "Universitar", new int[5]{ 23,45,34,18,38 }, 1);
//	spital1.getNrObiecteSpital();
//
//
//	cout << spital2.getNume() << endl;
//	spital2.setNume("Militar");
//	cout << spital2.getNume() << endl;
//
//	Spital::setReducereCAS(15);
//	cout << Spital::getReducereCAS();
//	Spital spital3;
//
//	spital1 = spital2;
//
//	cout<< endl<<endl<< spital2.getVarstaPacient(1);
//	//operator+
//
//	spital3 = spital2 + spital1; //1
//	//spital3 = spital2 + 67; //2
//	spital3 = 67 + spital2; //3 - functie
//	cout << endl << endl << spital3.getVarstaPacient(5);
//
//	//operator!=
//	if (spital2 != spital3) {
//		cout << "Sunt diferite";
//	}
//	else {
//		cout << "Sunt la fel";
//	}
//
//	//operator--
//
//	cout << spital1.getNrPacienti() << " " << spital2.getNrPacienti()<<endl;
//	spital1 = spital2--;
//	cout << spital1.getNrPacienti() << " " << spital2.getNrPacienti() << endl;
//	spital1 = --spital2;
//	cout << spital1.getNrPacienti() << " " << spital2.getNrPacienti() << endl;
//	//operator cast
//
//	float varstaMedie = spital1;
//	cout << varstaMedie;
//	//operator<< si >>
//
//	cout << endl << endl;
//	cin >> spital1;
//	cout << spital1;
//
//
//
//}