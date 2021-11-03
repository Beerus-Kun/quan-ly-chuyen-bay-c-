void xuatkytu(int x1, int y1, int x2, int y2,char *kytu, int kieu, int cochu, int mauchu, int maunen);
void xuatkytucanletrai(int x, int y, char *kytu, int kieu, int cochu, int mauchu, int maunen);
int chonhanhcn(int x1, int y1, int x2, int y2);
int chonhanellip(int x1, int y1, int x2, int y2);
int chonhantamgiac(int x1, int y1, int x2, int y2);
void menu();
void vekhungchunhat(int x1, int y1, int x2, int y2, char *kytu, int kieu, int cochu, int chu, int nen);
void windowextra(int thutu, int manhinhthem, int xuatramanhinh);
void windowtool(int thutu);
int hoi(int thoatkhong);
void windowtoolextra(int thutu);
void baoloikhongdatve();
void baoloitrangthai(int huy);
char gioitinh[2][4] = {"NU", "NAM"};
void baoluu(int manhinhthem);
struct nhaplieu{
	char text[43], text1[43];
	int soluong;
	nhaplieu(){
		reset();
	}
	void reset(){
		soluong = 0;
		memset(text ,0, 43);
		memset(text1 ,0, 43);
		text1[0] = '|';
		text[0] = ' ';
	}
};
void windowspecial(int thutu);
void docfile();

