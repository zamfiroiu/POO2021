//#include<iostream>
//
//using namespace std;
//
//enum TipMicDejun{English, Romanesc, Italian, Frantuzesc, Chinezesc};
//enum TipGust {Sarat, Dulce, Acrisor};
//
//class MicDejun {
//public:
//	TipMicDejun tip;
//	TipGust gust;
//	bool esteSanatos;
//	float gramaj;
//	int oraServire;
//	char* descriere;
//
//	MicDejun() {
//		this->tip = Romanesc;
//		gust = Sarat;
//		esteSanatos = true;
//		gramaj = 400.5f;
//		oraServire = 7;
//		descriere = new char[strlen("menu") + 1];
//		strcpy_s(descriere, strlen("menu") + 1, "menu");
//	}
//
//	MicDejun(float gramaj, int ora, const char* descriere) {
//		this->gramaj = gramaj;
//		this->oraServire = ora;
//		this->descriere = new char[strlen(descriere) + 1];
//		strcpy(this->descriere, descriere);
//		this->tip = Italian;
//		gust = Dulce;
//		esteSanatos = false;
//	}
//
//
//	void afisare() {//this -- afisare(MicDejun*this;)
//		cout << this->tip << endl;
//		cout << this->gust << endl;
//		cout << esteSanatos << endl;
//		cout << this->gramaj << endl;
//		cout << oraServire << endl;
//		cout << descriere << endl;
//	}
//};
//
//
//void main() {
//	MicDejun micDejun1;
//	micDejun1.afisare();
//
//	MicDejun micDejun2;
//	micDejun2.gramaj = 200;
//	micDejun2.oraServire = 8;
//	micDejun2.afisare();
//
//	MicDejun micDejun3(300, 9, "Restaurant");
//	micDejun3.afisare();
//
//}
