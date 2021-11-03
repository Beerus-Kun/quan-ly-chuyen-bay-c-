
using namespace std;
#include "include.h"

int main(){
	int dai = GetSystemMetrics(SM_CXSCREEN);
	int rong = GetSystemMetrics(SM_CYSCREEN);
	initwindow(dai, rong);
	int errorcode = graphresult();
	if (errorcode != grOk) {
		printf("Loi man hinh do hoa: %s\n", grapherrormsg(errorcode));
		printf("An phim bat ki de thoat:");
		getch();
		exit(1);
   }
   	docfile();
   	menu();
	getch();
}
