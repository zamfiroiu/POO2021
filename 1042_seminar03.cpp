//#include<iostream>
//
//using namespace std;
//
//enum Status{LaCurier, Livrat, InDepozit, InCursProcesare };
//
//class Colet {
//private:
//protected:
//public:
//	float greutate;
//	string codAWB;
//	Status stareColet;
//	bool deteriorat;
//	char* destinatar;
//
//	Colet() {
//		greutate = 1;
//		codAWB = "AWB123456";
//		stareColet = InCursProcesare;
//		deteriorat = false;
//		destinatar = new char[strlen("Popescu") + 1];
//		strcpy(destinatar, "Popescu");
//	}
//
//	Colet(float greutate, string AWB, const char* destinatar) {
//		this->greutate = greutate;
//		codAWB = AWB;
//		this->destinatar = new char[strlen(destinatar) + 1];
//		strcpy(this->destinatar, destinatar);
//		stareColet = InCursProcesare;
//		deteriorat = false;
//	}
//
//	~Colet() {
//		if (this->destinatar != NULL) {
//			delete[] this->destinatar;
//		}
//	}
//
//	void afisare() {// void afisare(Colet* this);
//		cout << this->greutate << endl;
//		cout << codAWB << endl;
//		cout << this->stareColet << endl;
//		cout << deteriorat << endl;
//		cout << destinatar << endl;
//	}
//
//};
//
//void main() {
//
//		Colet colet;
//	
//	{
//		Colet colet2;
//
//		colet2.greutate = 20;
//		colet2.afisare(); //afisare(&colet);
//		cout << endl;
//		colet2.afisare();
//	}
//
//	Colet colet3(10, "1234AWB", "Georgescu");
//
//	Colet* pc = new Colet(10, "1234AWB", "Georgescu");
//	delete pc;
//}