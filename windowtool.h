
struct nhapkytu{
void thanhghi(int &nhay, int x, int y, int nen, int chu, int kieu, int size, nhaplieu nl){
	if(nhay == 50){
		setbkcolor(nen);
		settextstyle(kieu, HORIZ_DIR, size);
		setcolor(chu);
		outtextxy(x, y, nl.text1);
	} 
	if(nhay == 100){
		setbkcolor(nen);
		settextstyle(kieu, HORIZ_DIR, size);
		setcolor(chu);
		outtextxy(x, y, nl.text);
		nhay = 0;
	} 
}

	void luunhaplieuvaoso(nhaplieu nl, int &a){
		nl.text[nl.soluong] = '\0';
		a = atoi(nl.text);
	}
	void luunhaplieuvaokytu(nhaplieu nl, char *a, int limit){
		for(int i=0; i<nl.soluong; i++){
			a[i] = nl.text[i];
		}
		if(nl.soluong<limit) a[nl.soluong] = '\0';
	}

void nhapchu(char a, nhaplieu &nl, int gioihan){
	if(((a<='z'&&a>='a')||(a<='Z'&&a>='A'))&&(nl.soluong < gioihan)){
		a = toupper(a);
		nl.text[nl.soluong] = a;
		nl.text1[nl.soluong] = a;
		nl.text1[++nl.soluong] = '|';
		nl.text[nl.soluong] = ' ';
	}
	return;
}

void daucach(char a, nhaplieu &nl, int gioihan){
	if((a == ' ')&&(nl.text[nl.soluong - 1] != ' ')&&(nl.soluong < gioihan)&&(nl.soluong != 0)) {
		nl.text[nl.soluong] = a;
		nl.text1[nl.soluong] = a;
		nl.text1[++nl.soluong] = '|';
		nl.text[nl.soluong] = ' ';
	}
}

void nhapso(char a, nhaplieu &nl, int gioihan){
	if((a >= '0')&&(a <= '9')&&(nl.soluong< gioihan)){
		nl.text[nl.soluong] = a;
		nl.text1[nl.soluong] = a;
		nl.text1[++nl.soluong] = '|';
		nl.text[nl.soluong] = ' ';
	}
}

void nhapgach(char a, nhaplieu &nl, int gioihan){
	if((a == '-')&&(nl.text[nl.soluong - 1] != '-')&&(nl.soluong < gioihan)&&(nl.soluong != 0)) {
		nl.text[nl.soluong] = a;
		nl.text1[nl.soluong] = a;
		nl.text1[++nl.soluong] = '|';
		nl.text[nl.soluong] = ' ';
	}
}

int xoakytu(char a, nhaplieu &nl, int gioihan){
	if((a == 8) && (nl.soluong< gioihan+1) && (nl.soluong >= 0)) {
		if(nl.soluong == 0){
			nl.text[nl.soluong] = ' ';
			nl.text1[nl.soluong] = '|';
			nl.text[nl.soluong + 1] = ' ';
		}
		else{
			nl.text1[nl.soluong] = ' ';
			nl.text[-- nl.soluong] = ' ';
			nl.text1[nl.soluong] = '|';
		}
		return 1;
	}
	return 0;
}

void nhap(int &nhay, int x, int y, int nen, int chu, int kieu, int size, int chosohaykhong, int gioihan, int chocachhaykhong,int chogachhaykhong, int chochuhaykhong, int &cothuchienhaykhong, nhaplieu &nl){
	cothuchienhaykhong = 0;
	if(kbhit()){
		char a = getch();
		if(chochuhaykhong == 1) nhapchu(a, nl, gioihan);
		if(chocachhaykhong == 1) daucach(a, nl, gioihan);
		if(chosohaykhong == 1) nhapso(a, nl, gioihan);
		if(chogachhaykhong == 1) nhapgach(a, nl, gioihan);
		xoakytu(a, nl, gioihan);
		 
		setbkcolor(nen);
		settextstyle(kieu, HORIZ_DIR, size);
		setcolor(chu);
		outtextxy(x, y, nl.text);
		nhay = 0;
		cothuchienhaykhong = 1;
	}
	nhay++;
	thanhghi(nhay, x, y, nen, chu, kieu, size, nl);
}
void nhapgioitinh(int &nhay, int x, int y, int nen, int chu, int kieu, int size, nhaplieu &nl){

	if(kbhit()){
		char a = getch();
		nhapchu(a, nl, 3);
		if(xoakytu(a, nl, 3)==1 && nl.text[1] == 'A'){
			nl.text[1] = ' ';
			nl.text[3] = ' ';
			nl.text1[1] = '|';
			nl.text1[2] = ' ';
			nl.soluong = 1;
		}
		if(nl.soluong>0){
			if(nl.text[1]!= 'U' && nl.text[1]!= 'A' && nl.text[1]!= ' '){
				nl.soluong --;
				nl.text[1] = ' ';
				nl.text1[1] = '|';
				nl.text[2] = ' ';
				nl.text1[2] = ' ';
			}
			else if(nl.text[1] == 'A'){
				nl.text[2] = 'M';
				nl.text[3] = ' ';
				nl.text1[2] = 'M';
				nl.text[3] = '|';
				nl.soluong=3;
			}
			else if(nl.text[1] == 'U'){
				nl.soluong = 2;
				nl.text[2] = ' ';
				nl.text1[2] = '|';
				nl.text[3] = ' ';
				nl.text1[3] = ' ';
			}
			if(nl.text[0] != 'N' && nl.text[0] != ' '){
				nl.reset();
				nl.text1[1] = ' ';
			}
		}
		
		
		 
		setbkcolor(nen);
		settextstyle(kieu, HORIZ_DIR, size);
		setcolor(chu);
		outtextxy(x, y, nl.text);
		nhay = 0;
	}
	nhay++;
	thanhghi(nhay, x, y, nen, chu, kieu, size, nl);
}
};

nhapkytu nkt;

struct xuatdanhsach{
	int toadoydong1 = 274;
	int trang, tranghientai, soluong, dong, trang1;
	char chair[4], ctrang[4], ctranghientai[3];
	int khoangcachtungdong = 25;
	char number1[4], number2[4], number3[5], number[20], hoten[41];
	int sodong = 12;
	Tree Stack[400];
	Passenger hanhkhach[14];
	NF chuyenbay[14];
	int soluongphantu;
	int toadohaigoc[4]={265, 220, 1280, 570};
	int toadoxdongdau = toadohaigoc[0]+5;
	int toadohaidinhngang[4] = {toadohaigoc[0], 270, toadohaigoc[2], 270};
	int kctoadomaybay[2] = {250, 670};
	int kctoadohanhkhach[3] = {250, 510, 160};
	int kctoadochuyenbay[6] = {230, 200, 250, 80, 160, 30};
	int kctoadodatve[3] = {340, 340, 130};
	int kctoadothongkechuyenbay2[4] = {250, 150, 250, 250};
	int kctoadodanhsachhanhkhach[4] = {50, 70, 250, 550};
	int kctoadothongkechuyenbay = 510;
	int toadoxmaybay[2] = {toadohaigoc[0]+kctoadomaybay[0], toadohaigoc[0]+kctoadomaybay[0]+kctoadomaybay[1]};
	int toadoxhanhkhach[3] = {toadohaigoc[0]+kctoadohanhkhach[0], toadohaigoc[0]+kctoadohanhkhach[0]+kctoadohanhkhach[1], toadohaigoc[0]+kctoadohanhkhach[0]+kctoadohanhkhach[1]+kctoadohanhkhach[2]};
	int toadoxchuyenbay[6] = {toadohaigoc[0]+kctoadochuyenbay[0], toadohaigoc[0]+kctoadochuyenbay[0]+kctoadochuyenbay[1], toadohaigoc[0]+kctoadochuyenbay[0]+kctoadochuyenbay[1]+kctoadochuyenbay[2], toadohaigoc[0]+kctoadochuyenbay[0]+kctoadochuyenbay[1]+kctoadochuyenbay[2]+kctoadochuyenbay[3], toadohaigoc[0]+kctoadochuyenbay[0]+kctoadochuyenbay[1]+kctoadochuyenbay[2]+kctoadochuyenbay[3]+kctoadochuyenbay[4], toadohaigoc[0]+kctoadochuyenbay[0]+kctoadochuyenbay[1]+kctoadochuyenbay[2]+kctoadochuyenbay[3]+kctoadochuyenbay[4]+kctoadochuyenbay[5]};
	int toadoxdatve[3] = {toadohaigoc[0]+kctoadodatve[0], toadohaigoc[0]+kctoadodatve[0]+kctoadodatve[1], toadohaigoc[0]+kctoadodatve[0]+kctoadodatve[1]+kctoadodatve[2]};
	int toadoxthongkechuyenbay = toadohaigoc[0]+kctoadothongkechuyenbay;
	int toadoxthongkechuyenbay2[4] = {toadohaigoc[0]+kctoadothongkechuyenbay2[0], toadohaigoc[0]+kctoadothongkechuyenbay2[0]+kctoadothongkechuyenbay2[1], toadohaigoc[0]+kctoadothongkechuyenbay2[0]+kctoadothongkechuyenbay2[1]+kctoadothongkechuyenbay2[2], toadohaigoc[0]+kctoadothongkechuyenbay2[0]+kctoadothongkechuyenbay2[1]+kctoadothongkechuyenbay2[2]+kctoadothongkechuyenbay2[3]};
	int toadoxdanhsachhanhkhach[4] = {toadohaigoc[0]+kctoadodanhsachhanhkhach[0], toadohaigoc[0]+kctoadodanhsachhanhkhach[0]+kctoadodanhsachhanhkhach[1], toadohaigoc[0]+kctoadodanhsachhanhkhach[0]+kctoadodanhsachhanhkhach[1]+kctoadodanhsachhanhkhach[2], toadohaigoc[0]+kctoadodanhsachhanhkhach[0]+kctoadodanhsachhanhkhach[1]+kctoadodanhsachhanhkhach[2]+kctoadodanhsachhanhkhach[3]};
	int toadoxuatmaybay[4]={toadoydong1, toadoxdongdau, toadoxmaybay[0]+5, toadoxmaybay[1]+5};
	int toadoxuathanhkhach[5] = {toadoydong1, toadoxdongdau, toadoxhanhkhach[0]+5, toadoxhanhkhach[1]+5, toadoxhanhkhach[2]+5};
	int toadoxuatchuyenbay[8] = {toadoydong1, toadoxdongdau, toadoxchuyenbay[0]+5, toadoxchuyenbay[1]+5, toadoxchuyenbay[2], toadoxchuyenbay[3]+5, toadoxchuyenbay[4]+5, toadoxchuyenbay[5]+5};
	int toadoxuatdatve[5] = {toadoydong1, toadoxdongdau, toadoxdatve[0]+5, toadoxdatve[1]+5, toadoxdatve[2]+5};
	int toadoxuatthongkechuyenbay[3] = {toadoydong1, toadoxdongdau, toadoxthongkechuyenbay+5};
	int toadoxuatthongkechuyenbay2[6] = {toadoydong1, toadoxdongdau, toadoxthongkechuyenbay2[0]+5, toadoxthongkechuyenbay2[1]+5, toadoxthongkechuyenbay2[2]+5, toadoxthongkechuyenbay2[3]+5};
	int toadoxuatdanhsachhanhkhach[6] = {toadoydong1, toadoxdongdau, toadoxdanhsachhanhkhach[0]+5, toadoxdanhsachhanhkhach[1]+5, toadoxdanhsachhanhkhach[2]+5, toadoxdanhsachhanhkhach[3]+5};
	int toadomoctrang[2] = {650, 620};
	int toadotrang[2] = {800, 620};
	int toadoxuatchuthich[8] = {300, 600, 300, 630, 1000, 600, 1000, 630};
	int sove;
	int sothutu;
	int toadotranghientai[2] = {740, 620};
	int tamgiac1[6] = {640, 624, 640, 639, 615, 632};
	int tamgiac2[6] = {887, 624, 913, 632, 887, 639};
	int tieudehang1[4] = {400, 60, 1100, 120};
	int tieudehang2[4] = {400, 120, 1100, 150};
	int tieudehang3[4] = {400, 160, 1100, 200};
	Airplane *xapl;
	void tieude(int thutu){
		char tieude[100];
		char so[5];
		memset(tieude, 0, 100);
		if(thutu == LFL){
			xuatkytu(tieudehang1[0], tieudehang1[1], tieudehang1[2], tieudehang1[3], "DANH SACH CHUYEN BAY DA DAT VE", 9, 4, YELLOW, BLACK);
			strcat(tieude, "Hanh Khach: "); strcat(tieude, psg.lastName); strcat(tieude, " ");  strcat(tieude, psg.firstName); 
			xuatkytu(tieudehang2[0], tieudehang2[1], tieudehang2[2], tieudehang2[3], tieude, 0, 3, CYAN, BLACK);
			memset(tieude, 0, 100);
			strcat(tieude, "CMND: "); strcat(tieude, psg.id);
			xuatkytu(tieudehang3[0], tieudehang3[1], tieudehang3[2], tieudehang3[3], tieude, 0, 3, CYAN, BLACK);
		}
		else if(thutu == LPSG){
			xuatkytu(tieudehang1[0], tieudehang1[1], tieudehang1[2], tieudehang1[3], "DANH SACH HANH KHACH", 9, 4, YELLOW, BLACK);
			strcat(tieude, "Chuyen Bay: "); strcat(tieude, fl.MaCB);
			if(fl.tt == huy_chuyen){
				xuatkytu(tieudehang2[0], tieudehang2[1], tieudehang2[2], tieudehang2[3], tieude, 0, 3, CYAN, BLACK); 
				memset(tieude, 0, 100);
				strcat(tieude, "Chuyen bay da bi huy");
				xuatkytu(tieudehang3[0], tieudehang3[1], tieudehang3[2], tieudehang3[3], tieude, 0, 3, CYAN, BLACK);
			}
			else{
				strcat(tieude, "   Luc: "); itoa(fl.dt.h, so, 10); strcat(tieude, so); strcat(tieude, ":"); itoa(fl.dt.mi, so, 10); if(fl.dt.mi<10) strcat(tieude, "0");  strcat(tieude, so);
				strcat(tieude, "  ");itoa(fl.dt.d, so, 10); strcat(tieude, so); strcat(tieude, "/"); itoa(fl.dt.m, so, 10); strcat(tieude, so); strcat(tieude, "/"); itoa(fl.dt.y, so, 10); strcat(tieude, so);
				xuatkytu(tieudehang2[0], tieudehang2[1], tieudehang2[2], tieudehang2[3], tieude, 0, 3, CYAN, BLACK); 
				memset(tieude, 0, 100);
//				strcat(tieude, "Thoi gian: "); itoa(fl.dt.h, so, 10); strcat(tieude, so); strcat(tieude, ":"); itoa(fl.dt.mi, so, 10); if(fl.dt.mi<10) strcat(tieude, "0");  strcat(tieude, so);
//				strcat(tieude, "  ");itoa(fl.dt.d, so, 10); strcat(tieude, so); strcat(tieude, "/"); itoa(fl.dt.m, so, 10); strcat(tieude, so); strcat(tieude, "/"); itoa(fl.dt.y, so, 10); strcat(tieude, so);
				strcat(tieude, "Noi den: "); strcat(tieude, fl.SanBD);
				xuatkytu(tieudehang3[0], tieudehang3[1], tieudehang3[2], tieudehang3[3], tieude, 0, 3, CYAN, BLACK);
			}

		}
	}
	
	void velaikhung(int thutu){
		setlinestyle(0, 1, 3);
		setcolor(15);
		rectangle(toadohaigoc[0],toadohaigoc[1],toadohaigoc[2],toadohaigoc[3]);
		line(toadohaidinhngang[0], toadohaidinhngang[1], toadohaidinhngang[2], toadohaidinhngang[3]);
		if(thutu == APL){
			line(toadoxmaybay[0], toadohaigoc[1], toadoxmaybay[0], toadohaigoc[3]);
			line(toadoxmaybay[1], toadohaigoc[1], toadoxmaybay[1], toadohaigoc[3]);
		}
		else if(thutu == FL){
			line(toadoxchuyenbay[0], toadohaigoc[1], toadoxchuyenbay[0], toadohaigoc[3]);
			line(toadoxchuyenbay[1], toadohaigoc[1], toadoxchuyenbay[1], toadohaigoc[3]);
			line(toadoxchuyenbay[2], toadohaigoc[1], toadoxchuyenbay[2], toadohaigoc[3]);
			line(toadoxchuyenbay[3], toadohaigoc[1], toadoxchuyenbay[3], toadohaigoc[3]);
			line(toadoxchuyenbay[4], toadohaigoc[1], toadoxchuyenbay[4], toadohaigoc[3]);
			line(toadoxchuyenbay[5], toadohaigoc[1], toadoxchuyenbay[5], toadohaigoc[3]);
		}
		else if(thutu == PSG){
			line(toadoxhanhkhach[0], toadohaigoc[1], toadoxhanhkhach[0], toadohaigoc[3]);
			line(toadoxhanhkhach[1], toadohaigoc[1], toadoxhanhkhach[1], toadohaigoc[3]);
			line(toadoxhanhkhach[2], toadohaigoc[1], toadoxhanhkhach[2], toadohaigoc[3]);
		}
		else if(thutu == BK || thutu == LFL){
			line(toadoxdatve[0], toadohaigoc[1], toadoxdatve[0], toadohaigoc[3]);
			line(toadoxdatve[1], toadohaigoc[1], toadoxdatve[1], toadohaigoc[3]);
			line(toadoxdatve[2], toadohaigoc[1], toadoxdatve[2], toadohaigoc[3]);
		}
		else if(thutu == NFL){
			line(toadoxthongkechuyenbay, toadohaigoc[1], toadoxthongkechuyenbay, toadohaigoc[3]);
		}
		else if(thutu == NBK){
			line(toadoxthongkechuyenbay2[0], toadohaigoc[1], toadoxthongkechuyenbay2[0], toadohaigoc[3]);
			line(toadoxthongkechuyenbay2[1], toadohaigoc[1], toadoxthongkechuyenbay2[1], toadohaigoc[3]);
			line(toadoxthongkechuyenbay2[2], toadohaigoc[1], toadoxthongkechuyenbay2[2], toadohaigoc[3]);
			line(toadoxthongkechuyenbay2[3], toadohaigoc[1], toadoxthongkechuyenbay2[3], toadohaigoc[3]);
		}
		else if(thutu == LPSG){
			line(toadoxdanhsachhanhkhach[0], toadohaigoc[1], toadoxdanhsachhanhkhach[0], toadohaigoc[3]);
			line(toadoxdanhsachhanhkhach[1], toadohaigoc[1], toadoxdanhsachhanhkhach[1], toadohaigoc[3]);
			line(toadoxdanhsachhanhkhach[2], toadohaigoc[1], toadoxdanhsachhanhkhach[2], toadohaigoc[3]);
			line(toadoxdanhsachhanhkhach[3], toadohaigoc[1], toadoxdanhsachhanhkhach[3], toadohaigoc[3]);
		}
	}
	
	void border(int thutu){
		setfillstyle(1, BLACK);
		setlinestyle(0, 1, 3);
		setcolor(WHITE);
		setbkcolor(BLACK);
		bar(toadohaigoc[0],toadohaigoc[1],toadohaigoc[2],toadohaigoc[3]);
		setlinestyle(1, 1, 1);
		for(int i=1; i<=12; i++){
			line(toadohaigoc[0], toadohaidinhngang[1]+(i -1)*khoangcachtungdong, toadohaigoc[2], toadohaidinhngang[1]+(i -1)*khoangcachtungdong);
		}
		if(thutu == APL){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxmaybay[0], toadohaidinhngang[1], "Ma may bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxmaybay[0], toadohaigoc[1], toadoxmaybay[1], toadohaidinhngang[1], "Loai may bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxmaybay[1], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "So cho", 10, 3, WHITE, BLACK);
		}
		else if(thutu == PSG){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxhanhkhach[0], toadohaidinhngang[1], "CMND", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxhanhkhach[0], toadohaigoc[1], toadoxhanhkhach[1], toadohaidinhngang[1], "Ho", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxhanhkhach[1], toadohaigoc[1], toadoxhanhkhach[2], toadohaidinhngang[1], "Ten", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxhanhkhach[2], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Phai", 10, 3, WHITE, BLACK);
		}
		else if(thutu == FL){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxchuyenbay[0], toadohaidinhngang[1], "Ma chuyen bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[0], toadohaigoc[1], toadoxchuyenbay[1], toadohaidinhngang[1], "Ma may bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[1], toadohaigoc[1], toadoxchuyenbay[2], toadohaidinhngang[1], "Noi den", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[2], toadohaigoc[1], toadoxchuyenbay[3], toadohaidinhngang[1], "hh:mm", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[3], toadohaigoc[1], toadoxchuyenbay[4], toadohaidinhngang[1], "dd/mm/yyyy", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[4], toadohaigoc[1], toadoxchuyenbay[5], toadohaidinhngang[1], "TT", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxchuyenbay[5], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Cho", 10, 3, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatchuthich[0], toadoxuatchuthich[1], "0 : huy chuyen", 9, 2, CYAN, BLACK);
			xuatkytucanletrai(toadoxuatchuthich[2], toadoxuatchuthich[3], "1 : con ve", 9, 2, CYAN, BLACK);
			xuatkytucanletrai(toadoxuatchuthich[4], toadoxuatchuthich[5], "2 : het ve", 9, 2, CYAN, BLACK);
			xuatkytucanletrai(toadoxuatchuthich[6], toadoxuatchuthich[7], "3 : hoan tat", 9, 2, CYAN, BLACK);
		}
		else if(thutu == BK || thutu == LFL){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxdatve[0], toadohaidinhngang[1], "Ma chuyen bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdatve[0], toadohaigoc[1], toadoxdatve[1], toadohaidinhngang[1], "Noi den", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdatve[1], toadohaigoc[1], toadoxdatve[2], toadohaidinhngang[1], "Gio bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdatve[2], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Ngay bay", 10, 3, WHITE, BLACK);
		}
		else if(thutu == NFL){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxthongkechuyenbay, toadohaidinhngang[1], "Ma may bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxthongkechuyenbay, toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Luot thuc hien", 10, 3, WHITE, BLACK);
		}
		else if(thutu == NBK){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxthongkechuyenbay2[0], toadohaidinhngang[1], "Ma chuyen bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxthongkechuyenbay2[0], toadohaigoc[1], toadoxthongkechuyenbay2[1], toadohaidinhngang[1], "Gio bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxthongkechuyenbay2[1], toadohaigoc[1], toadoxthongkechuyenbay2[2], toadohaidinhngang[1], "Ngay bay", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxthongkechuyenbay2[2], toadohaigoc[1], toadoxthongkechuyenbay2[3], toadohaidinhngang[1], "Noi den", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxthongkechuyenbay2[3], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Ve con", 10, 3, WHITE, BLACK);
		}
		else if(thutu == LPSG){
			xuatkytu(toadohaigoc[0], toadohaigoc[1], toadoxdanhsachhanhkhach[0], toadohaidinhngang[1], "STT", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdanhsachhanhkhach[0], toadohaigoc[1], toadoxdanhsachhanhkhach[1], toadohaidinhngang[1], "So ve", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdanhsachhanhkhach[1], toadohaigoc[1], toadoxdanhsachhanhkhach[2], toadohaidinhngang[1], "CMND", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdanhsachhanhkhach[2], toadohaigoc[1], toadoxdanhsachhanhkhach[3], toadohaidinhngang[1], "Ho Ten", 10, 3, WHITE, BLACK);
			xuatkytu(toadoxdanhsachhanhkhach[3], toadohaigoc[1], toadohaigoc[2], toadohaidinhngang[1], "Phai", 10, 3, WHITE, BLACK);
		}
		velaikhung(thutu);
		setfillstyle(1, LIGHTGRAY);
   		fillpoly(3, tamgiac1);
    	fillpoly(3, tamgiac2);
	}
	
	void maubinhthuong(int thutu){
		if(dong<1 || dong>12) return;
		setfillstyle(1, 0);
		bar(toadohaigoc[0], toadohaidinhngang[1]+ khoangcachtungdong*(dong-1), toadohaigoc[2], toadohaidinhngang[1] + khoangcachtungdong*(dong));
		if(thutu == APL){
			xuatkytucanletrai(toadoxuatmaybay[1], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), xapl->IdMB, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatmaybay[2], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), xapl->Type, 0, 2, WHITE, BLACK);
			itoa(xapl->Chair, chair, 10);
			xuatkytucanletrai(toadoxuatmaybay[3], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), chair, 0, 2, WHITE, BLACK);
		}
		else if(thutu == PSG){
			xuatkytucanletrai(toadoxuathanhkhach[1], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].id, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuathanhkhach[2], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].lastName, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuathanhkhach[3], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].firstName, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuathanhkhach[4], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), gioitinh[hanhkhach[dong].sex], 0, 2, WHITE, BLACK);
		}
		else if(thutu == FL){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatchuyenbay[1], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatchuyenbay[2], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SoHieuMB, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatchuyenbay[3], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SanBD, 0, 2, WHITE, BLACK);
			if(chuyenbay[dong]->Data.dt.mi == 0) {
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10); 
			strcat(number,number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatchuyenbay[4], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number, number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatchuyenbay[5], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			itoa(chuyenbay[dong]->Data.tt, number, 10);
			xuatkytucanletrai(toadoxuatchuyenbay[6], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			itoa(chuyenbay[dong]->Data.Ticket->nTicketTotal, number, 10);
			xuatkytucanletrai(toadoxuatchuyenbay[7], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
		}
		else if(thutu == BK || thutu == LFL){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatdatve[1], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatdatve[2], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SanBD, 0, 2, WHITE, BLACK);
			if(chuyenbay[dong]->Data.dt.mi == 0) {
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10); 
			strcat(number,number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatdatve[3], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number, number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatdatve[4], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
		}
		else if(thutu == NFL){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatthongkechuyenbay[1], toadoxuatthongkechuyenbay[0] + khoangcachtungdong*(dong-1), xapl->IdMB, 0, 2, WHITE, BLACK);
			itoa(xapl->Turn, number, 10);
			xuatkytucanletrai(toadoxuatthongkechuyenbay[2], toadoxuatthongkechuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
		}
		else if(thutu == NBK){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[1], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, WHITE, BLACK);
			if(chuyenbay[dong]->Data.dt.mi == 0){
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10); 
			strcat(number,number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[2], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number, number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[3], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.Ticket->nTicketTotal - chuyenbay[dong]->Data.Ticket->nTicketSold, number, 10);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[5], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[4], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SanBD, 0, 2, WHITE, BLACK);
		}
		else if(thutu == LPSG){
			itoa(sothutu, number, 10);
			xuatkytucanletrai(toadoxuatdanhsachhanhkhach[1], toadoxuatdanhsachhanhkhach[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			itoa(sove, number, 10);
			xuatkytucanletrai(toadoxuatdanhsachhanhkhach[2], toadoxuatdanhsachhanhkhach[0] + khoangcachtungdong*(dong-1), number, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatdanhsachhanhkhach[3], toadoxuatdanhsachhanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].id, 0, 2, WHITE, BLACK);
			memset(hoten, 0, 41);
			strcat(hoten, hanhkhach[dong].lastName); strcat(hoten, " "); strcat(hoten, hanhkhach[dong].firstName);
			xuatkytucanletrai(toadoxuatdanhsachhanhkhach[4], toadoxuatdanhsachhanhkhach[0] + khoangcachtungdong*(dong-1), hoten, 0, 2, WHITE, BLACK);
			xuatkytucanletrai(toadoxuatdanhsachhanhkhach[5], toadoxuatdanhsachhanhkhach[0] + khoangcachtungdong*(dong-1), gioitinh[hanhkhach[dong].sex], 0, 2, WHITE, BLACK);
		}
		velaikhung(thutu);
		if(dong != 1){
			setlinestyle(1, 1, 1);
			setbkcolor(BLACK);
			line(toadohaigoc[0], toadohaidinhngang[1]+(dong -1)*khoangcachtungdong, toadohaigoc[2], toadohaidinhngang[1]+(dong -1)*khoangcachtungdong);
		}
	}
	
	void doimau(int thutu){
		if(dong<1 || dong>12) return;
		setfillstyle(1, LIGHTGREEN);
		bar(toadohaigoc[0]+5, toadohaidinhngang[1]+ khoangcachtungdong*(dong-1), toadohaigoc[2]-5, toadohaidinhngang[1] + khoangcachtungdong*(dong));
		if(thutu == APL){
			xuatkytucanletrai(toadoxuatmaybay[1], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), xapl->IdMB, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuatmaybay[2], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), xapl->Type, 0, 2, LIGHTGREEN, WHITE);
			itoa(xapl->Chair, chair, 10);
			xuatkytucanletrai(toadoxuatmaybay[3], toadoxuatmaybay[0] + khoangcachtungdong*(dong-1), chair, 0, 2, LIGHTGREEN, WHITE);
		}
		else if(thutu == PSG){
			xuatkytucanletrai(toadoxuathanhkhach[1], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].id, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuathanhkhach[2], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].lastName, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuathanhkhach[3], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), hanhkhach[dong].firstName, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuathanhkhach[4], toadoxuathanhkhach[0] + khoangcachtungdong*(dong-1), gioitinh[hanhkhach[dong].sex], 0, 2, LIGHTGREEN, WHITE);
		}
		else if(thutu == FL){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatchuyenbay[1], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuatchuyenbay[2], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SoHieuMB, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuatchuyenbay[3], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SanBD, 0, 2, LIGHTGREEN, WHITE);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10);
			if(chuyenbay[dong]->Data.dt.mi == 0) {
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			strcat(number, number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatchuyenbay[4], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number,number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatchuyenbay[5], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			itoa(chuyenbay[dong]->Data.tt, number, 10);
			xuatkytucanletrai(toadoxuatchuyenbay[6], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			itoa(chuyenbay[dong]->Data.Ticket->nTicketTotal, number, 10);
			xuatkytucanletrai(toadoxuatchuyenbay[7], toadoxuatchuyenbay[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
		}
		else if(thutu == BK || thutu == LFL){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatdatve[1], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, LIGHTGREEN, WHITE);
			xuatkytucanletrai(toadoxuatdatve[2], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.SanBD, 0, 2, LIGHTGREEN, WHITE);
			if(chuyenbay[dong]->Data.dt.mi == 0) {
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10); 
			strcat(number,number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatdatve[3], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number, number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatdatve[4], toadoxuatdatve[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
		}
		else if(thutu == NBK){
			memset(number, 0, 20);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[1], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), chuyenbay[dong]->Data.MaCB, 0, 2, LIGHTGREEN, WHITE);
			if(chuyenbay[dong]->Data.dt.mi == 0) {
				number2[0] = '0';
				number2[1] = '0';
			}
			else itoa(chuyenbay[dong]->Data.dt.mi, number2, 10);
			itoa(chuyenbay[dong]->Data.dt.h, number1, 10); 
			strcat(number,number1); strcat(number, ":"); strcat(number, number2);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[2], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.dt.d, number1, 10); itoa(chuyenbay[dong]->Data.dt.m, number2, 10); itoa(chuyenbay[dong]->Data.dt.y, number3, 10);
			strcat(number, number1); strcat(number, "/"); strcat(number, number2); strcat(number, "/"); strcat(number, number3);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[3], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
			memset(number, 0, 20);
			itoa(chuyenbay[dong]->Data.Ticket->nTicketTotal - chuyenbay[dong]->Data.Ticket->nTicketSold, number, 10);
			xuatkytucanletrai(toadoxuatthongkechuyenbay2[4], toadoxuatthongkechuyenbay2[0] + khoangcachtungdong*(dong-1), number, 0, 2, LIGHTGREEN, WHITE);
		}
		velaikhung(thutu);
		if(dong != 1){
			setlinestyle(1, 1, 1);
			setbkcolor(BLACK);
			line(toadohaigoc[0], toadohaidinhngang[1]+(dong -1)*khoangcachtungdong, toadohaigoc[2], toadohaidinhngang[1]+(dong -1)*khoangcachtungdong);
		}
	}

	
	void capnhattrang(int thutu, int trangchinh){
		xuatkytucanletrai(toadomoctrang[0], toadomoctrang[1], "                                ", 9, 2, 15, 0);
		xuatkytucanletrai(toadomoctrang[0], toadomoctrang[1], "Trang", 9, 2, 15, 0);
		xuatkytucanletrai(toadomoctrang[0]+140, toadomoctrang[1], "/", 9, 2, 15, 0);
		if(trangchinh == 1){
			if(thutu == APL){
				soluongphantu = lapl.sl;
			} 
			else if(thutu == PSG){
				ChangettFlight(nodefl, root);
				soluongphantu = soluonghanhkhach;
			}	
			else if(thutu == FL){
				ChangettFlight(nodefl, root);
				soluongphantu = soluongchuyenbay;
			}
			else if(thutu == BK){
				ChangettFlight(nodefl, root);
				soluongphantu = CountFlightReady(nodefl, nodebk);
			}
			else if(thutu == NFL){
				SortByNumberFlight(lapl);
				soluongphantu = lapl.sl;
			}
			else if(thutu == LPSG) soluongphantu = fl.Ticket->nTicketSold;
			else if(thutu == LFL) soluongphantu = psg.count;
			trang = (soluongphantu - 1) / 12 +1;
			itoa(trang, ctrang, 10);
			itoa(tranghientai, ctranghientai, 10);
		}
		else if(trangchinh == 0){
			trang1 = (soluongphantu - 1) / 12 +1;
			itoa(trang1, ctrang, 10);
			itoa(tranghientai, ctranghientai, 10);
		}
		outtextxy(toadotranghientai[0],toadotranghientai[1], ctranghientai);
		outtextxy(toadotrang[0], toadotrang[1], ctrang);
	}
	
	void xuattheolist(int thutu){
		border(thutu);
		if(thutu == APL){
			for(int i=0 + sodong * (tranghientai-1); i<soluongphantu && i<sodong*tranghientai; i++){
				xapl = lapl.List[i];
				dong = i%sodong+1;
				maubinhthuong(thutu);
			}
		}
		else if(thutu == NFL){
			for(int i=0 + sodong * (tranghientai-1); i<soluongphantu && i<sodong*tranghientai; i++){
				xapl = lapl.List[i];
				dong = i%sodong+1;
				maubinhthuong(thutu);
			}
		}
		else if(thutu == PSG){
			Tree ps = root;
			int sp=-1, dem = 0; dong = 0;
			do{
				while (ps != NULL){
					Stack[++sp]= ps;
					ps= ps->left;
				}
				if (sp != -1){
					ps=Stack[sp--];
					dem++;
					if(dem<=tranghientai *12 && dem>=tranghientai *12-11){
						dong++;
						hanhkhach[dong] = ps->key;
						maubinhthuong(thutu);
					}
					else if(dem>tranghientai *12) break;
					ps=ps->right;
    			}
				else break;
			} while (1);
		}
		else if(thutu == FL){
			chuyenbay[1] = nodefl;
			for(int i=1; i<tranghientai; i++){
				chuyenbay[1] = chuyenbay[1]->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next;
			}
			for(int i = 1; i<13 && i<=(soluongphantu - (tranghientai-1)*12); i++){
				dong = i;
				if(i>1){
					chuyenbay[i] = chuyenbay[i-1]->Next;
				}
				maubinhthuong(thutu);
			}
		}
		else if(thutu == BK){
			chuyenbay[1] = nodebk;
			for(int i=1; i<tranghientai; i++){
				chuyenbay[1] = chuyenbay[1]->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next->Next;
			}
			for(int i = 1; i<13 && i<=(soluongphantu - (tranghientai-1)*12); i++){
				dong = i;
				if(i>1){
					chuyenbay[i] = chuyenbay[i-1]->Next;
				}
				maubinhthuong(thutu);
			}
		}
		else if(thutu == LPSG){
			int j=0; dong = 0;
			for(int i=0; i<fl.Ticket->nTicketTotal && j<soluongphantu; i++){
				if(fl.Ticket->List[i].stt!=-1){
					j++;
					if(j>(tranghientai-1)*12 && j<=tranghientai*12){
						dong++;
						hanhkhach[dong] = FindPassenger(root, fl.Ticket->List[i].idOwner)->key;
						sove = i+1;
						sothutu = j;
						maubinhthuong(thutu);
					}
				}
			}
		}
		else if(thutu == LFL){
			for(int i = 1; i<13 && i<=(soluongphantu - (tranghientai-1)*12); i++){
				dong = i;
				chuyenbay[i] = FindFlight(nodebk, psg.MaFlight[i+(tranghientai-1)*12-1]);
				maubinhthuong(thutu);
			}
		}
	}
	void xulydong(int thutu, int y, int chucnang, int xuatramanhinh){
		dong = (y-toadohaidinhngang[1])/khoangcachtungdong+1;
		if((dong+sodong*(tranghientai-1))<=soluongphantu && !(chucnang == 2 && thutu == BK)){
			if(chucnang == 1){
				if(thutu == APL){
					xapl = lapl.List[dong+sodong*(tranghientai-1)-1];
				}
			}
			else if(chucnang == 3){
				if(thutu == APL){
					xapl = lapl.List[tima[dong+sodong*(tranghientai-1)-1]];
				}
			}
			doimau(thutu);
			if(chonhanhcn(toadohaigoc[0], toadohaidinhngang[1]+khoangcachtungdong*(dong-1), toadohaigoc[2], toadohaidinhngang[1]+khoangcachtungdong*dong)){
				if(thutu == APL){
					apl = xapl;
				}
				else if(thutu == PSG){
					psg = hanhkhach[dong];
					if(xuatramanhinh == 0){
						if(hoi(4) == 1){
							if(BuyTicket(root, nodefl, psg.id, fl.MaCB, vitrighe) == false) baoloikhongdatve();
							windowspecial(BK);
						} 
						else windowtoolextra(PSG);
					}
				}
				else if(thutu == FL || thutu == BK){
					fl = chuyenbay[dong]->Data;
				}
				else if(thutu == LFL){
					if(hoi(2) == 1){
						CancelTicket(nodefl, root, psg.id, chuyenbay[dong]->Data.MaCB);
						psg = FindPassenger(root, psg.id)->key;
						windowtoolextra(LFL);
					} 
					else windowtoolextra(LFL);
				}
				if(thutu == BK) windowspecial(thutu);
				else windowextra(thutu, 0, 1);
			}
			else maubinhthuong(thutu);
		}
	}
	
	void xuattheodiachi(int thutu){
		border(thutu);
		if(thutu == APL){
			for(int i=0 + sodong * (tranghientai-1); i<soluongphantu && i< sodong*tranghientai; i++){
				xapl = lapl.List[tima[i]];
				dong = i%sodong+1;
				maubinhthuong(thutu);
			}
		}
		else if(thutu == PSG || thutu == FL || thutu == BK || NBK){
			for(int i=0 + sodong * (tranghientai-1); i<soluongphantu && i< sodong*tranghientai; i++){
				dong = i%sodong+1;
				if(thutu == PSG) hanhkhach[dong] = spsg.ds[i]->key;
				else if(thutu == FL || thutu == BK || thutu == NBK) chuyenbay[dong] = sfl.ds[i];
				maubinhthuong(thutu);
			}
		}
		
	}
	void capnhattheodiachi(int thutu){
		tranghientai = 1;
		capnhattrang(thutu, 0);
		xuattheodiachi(thutu);
	}
	void capnhatlist(int thutu){
		tranghientai = 1;
		capnhattrang(thutu, 1);
		xuattheolist(thutu);
	}
	int chuotvotamgiac(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y){
		int x1chinh = min(x1, min(x2, x3)), y1chinh = min(y1, min(y2, y3)), x2chinh = max(x1, max(x2, x3)), y2chinh = max(y1, max(y2, y3));
		if(x>x1chinh && x<x2chinh && y>y1chinh && y<y2chinh && getpixel(x,y)!=BLACK){
			if(chonhantamgiac(x1chinh, y1chinh, x2chinh, y2chinh)){
				return 1;
			}
			else return 0;
		}
		return 0;
	}
	void doitrang(int thutu, int chucnang, int x, int y){
		if(chuotvotamgiac(tamgiac1[0], tamgiac1[1], tamgiac1[2], tamgiac1[3], tamgiac1[4], tamgiac1[5], x, y)){
			if(tranghientai > 1){
				tranghientai--;
				if(thutu == APL || thutu == PSG){
					if(chucnang == 1) capnhattrang(thutu, 1);
					else capnhattrang(thutu, 0);
					if(chucnang == 3) xuattheodiachi(thutu);
					if(chucnang == 1) xuattheolist(thutu);
				}
				else if(thutu == FL){
					if(chucnang == 1){
						capnhattrang(thutu, 1);
						xuattheolist(thutu);
					} 
					if(chucnang == 2){
						capnhattrang(NFL, 1);
						xuattheolist(NFL);
					} 
					if(chucnang == 3){
						capnhattrang(thutu, 0);
						xuattheodiachi(thutu);
					} 
				}
				else if(thutu == BK){
					if(chucnang == 1){
						capnhattrang(thutu, 1);
						xuattheolist(thutu);
					}
					if(chucnang == 2){
						capnhattrang(NBK, 0);
						xuattheodiachi(NBK);
					}
					if(chucnang == 3){
						capnhattrang(thutu, 0);
						xuattheodiachi(thutu);
					}
				}
				else if(thutu == LPSG|| LFL){
					capnhattrang(thutu, 1);
					xuattheolist(thutu);
				}
			}
		}
		if(chuotvotamgiac(tamgiac2[0], tamgiac2[1], tamgiac2[2], tamgiac2[3], tamgiac2[4], tamgiac2[5], x, y)){
			if(tranghientai < trang){
				tranghientai++;
				if(thutu == APL || PSG){
					if(chucnang == 1) capnhattrang(thutu, 1);
					else capnhattrang(thutu, 0);
					if(chucnang == 3) xuattheodiachi(thutu);
					if(chucnang == 1) xuattheolist(thutu);
				}
				else if(thutu == FL){
					if(chucnang == 1){
						capnhattrang(thutu, 1);
						xuattheolist(thutu);
					} 
					if(chucnang == 2){
						capnhattrang(NFL, 1);
						xuattheolist(NFL);
					} 
					if(chucnang == 3){
						capnhattrang(thutu, 0);
						xuattheodiachi(thutu);
					} 
				}
				else if(thutu == BK){
					if(chucnang == 1){
						capnhattrang(thutu, 1);
						xuattheolist(thutu);
					}
					if(chucnang == 2){
						capnhattrang(NBK, 0);
						xuattheodiachi(NBK);
					}
					if(chucnang == 3){
						capnhattrang(thutu, 0);
						xuattheodiachi(thutu);
					}
				}
				else if(thutu == LPSG || LFL){
					capnhattrang(thutu, 1);
					xuattheolist(thutu);
				}
			}
		}
	}
};

struct thanhcongcu{
	int hcnfistbar[4] = {330, 60, 600+80, 120};
	int hcnsecondfistbar[4] = {930-80, 60, 1200, 120};
	int hcnsearch[4] = {610, 160, 910, 200};
	int toadoysearch[2] = {130, 170};
	int hcnsearchflight[16] = {460, toadoysearch[0], 515, toadoysearch[1], 545, toadoysearch[0], 600, toadoysearch[1], 630, toadoysearch[0], 720, toadoysearch[1], 870, toadoysearch[0], 1170, toadoysearch[1]};
	int toadoxxuatkytu[4] = {320, 525, 610, 740};
	int hcnbuttonsearch[4] = {675, 175, 825, 210};
	int tamellip[2] = {54, 166};
	int khoangcachellip = 115;
	int thutuellip[6] = {APL, FL, PSG, BK, SV, OT};
	int dorongellip = 170, docaoellip = 50;
	void drawfirstbar(int thutu, int i){
		int nen = 9, chu = 0;
		if(i == 1) {
			nen = 2;
			chu = 15;
		}
		setfillstyle(1, nen);
		bar(hcnfistbar[0], hcnfistbar[1], hcnfistbar[2], hcnfistbar[3]);
		if(thutu == APL)
			xuatkytu(hcnfistbar[0], hcnfistbar[1], hcnfistbar[2], hcnfistbar[3], "Danh sach may bay", 9, 2, chu, nen);
		else if(thutu == PSG)
			xuatkytu(hcnfistbar[0], hcnfistbar[1], hcnfistbar[2], hcnfistbar[3], "Danh sach hanh khach", 9, 2, chu, nen);
		else if(thutu == FL)
			xuatkytu(hcnfistbar[0], hcnfistbar[1], hcnfistbar[2], hcnfistbar[3], "Danh sach chuyen bay", 9, 2, chu, nen);
		else if(thutu == BK)
			xuatkytu(hcnfistbar[0], hcnfistbar[1], hcnfistbar[2], hcnfistbar[3], "Chuyen bay con ve", 9, 2, chu, nen);
	}
	
	void drawsecondbar(int thutu, int i){
		int nen = 9, chu = 0;
		if(i == 1) {
			nen = 2;
			chu = 15;
		}
		setfillstyle(1, nen);
  	 	bar(hcnsecondfistbar[0], hcnsecondfistbar[1], hcnsecondfistbar[2], hcnsecondfistbar[3]);
		if(thutu == APL)
			xuatkytu(hcnsecondfistbar[0], hcnsecondfistbar[1], hcnsecondfistbar[2], hcnsecondfistbar[3], "Them may bay", 9, 2, chu, nen);
		else if(thutu == PSG) 
			xuatkytu(hcnsecondfistbar[0], hcnsecondfistbar[1], hcnsecondfistbar[2], hcnsecondfistbar[3], "Them hanh khach", 9, 2, chu, nen);
		else if(thutu == FL)
			xuatkytu(hcnsecondfistbar[0], hcnsecondfistbar[1], hcnsecondfistbar[2], hcnsecondfistbar[3], "Thong ke CB theo MB", 9, 2, chu, nen);
		else if(thutu == BK)
			xuatkytu(hcnsecondfistbar[0], hcnsecondfistbar[1], hcnsecondfistbar[2], hcnsecondfistbar[3], "Thong ke chuyen bay", 9, 2, chu, nen);
	}
	
	void deletesearchbar(){
		setfillstyle(1, BLACK);
		bar(hcnsearch[0],hcnsearch[1],hcnsearch[2],hcnsearch[3]);
	}
		
	void drawsearchbar(int i){
		setfillstyle(1, 15);
		bar(hcnsearch[0],hcnsearch[1],hcnsearch[2],hcnsearch[3]);
   		if(i == 0)
   			xuatkytu(hcnsearch[0],hcnsearch[1],hcnsearch[2],hcnsearch[3], "Nhap de tim kiem", 1, 1, 8, 15);
	}
	
	void drawsearchflight(){
		setfillstyle(1, 15);
		for(int i=0; i<4; i++)bar(hcnsearchflight[i*4],hcnsearchflight[1 + i*4],hcnsearchflight[2+ i*4],hcnsearchflight[3+ i*4]);
		xuatkytucanletrai(toadoxxuatkytu[0], toadoysearch[0]+10, "Thoi gian", 9, 3, YELLOW, BLACK);
		xuatkytucanletrai(toadoxxuatkytu[1], toadoysearch[0]+10, "/", 9, 3, YELLOW, BLACK);
		xuatkytucanletrai(toadoxxuatkytu[2], toadoysearch[0]+10, "/", 9, 3, YELLOW, BLACK);
		xuatkytucanletrai(toadoxxuatkytu[3], toadoysearch[0]+10, "Noi den", 9, 3, YELLOW, BLACK);
		vekhungchunhat(hcnbuttonsearch[0], hcnbuttonsearch[1], hcnbuttonsearch[2], hcnbuttonsearch[3], "Tim kiem", 9, 1, BLACK, LIGHTGRAY);
		setlinestyle(1, 0, 1);
		rectangle(hcnbuttonsearch[0]+5, hcnbuttonsearch[1]+5, hcnbuttonsearch[2]-5, hcnbuttonsearch[3]-5);
	}
	void deletesearchflight(){
		setfillstyle(1, 0);
		bar(toadoxxuatkytu[0], toadoysearch[0], hcnsearchflight[14], hcnbuttonsearch[3]); 
	}
	void drawellip(int thutu, int vitri, int sang){
		int nen = 7, chu = 6;
		if(sang == 1 && thutu!=OT){
			nen = 2;
			chu = 15;
		}
		else if (sang==1 && thutu==OT){
			nen = LIGHTRED;
			chu = 15;
		}
		setfillstyle(1, nen);
		fillellipse (tamellip[0], tamellip[1]+khoangcachellip*(vitri-1), dorongellip, docaoellip);
		if(thutu == APL){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "May bay", 9, 3, chu, nen);
		}
		else if(thutu == FL){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "Chuyen bay", 9, 3, chu, nen);
		}
		else if(thutu == PSG){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "Hanh khach", 9, 3, chu, nen);
		}
		else if(thutu == BK){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "Dat ve", 9, 3, chu, nen);
		}
		else if(thutu == SV){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "Luu", 9, 3, chu, nen);
		}
		else if(thutu == OT){
			xuatkytucanletrai(tamellip[0]-36, tamellip[1]+khoangcachellip*(vitri-1)-16, "Thoat", 9, 3, chu, nen);
		}
	}
};
xuatdanhsach xds;
thanhcongcu tcc;
void windowtool(int thutu){
	setbkcolor(BLACK);
	cleardevice();
	int vitri = 0;
	int thuchien;
	int chonnhap;
	int chucnang = 1;
	int sang = 1;
	int x,y;
	int chocach, chochu, chogach;
	nhaplieu search, ngay, thang, nam, noiden;
	int nhay = 0; 
	for(int i=0; i<6; i++){
		if(i!=(thutu-1))
			tcc.drawellip(tcc.thutuellip[i], ++vitri, 0);
	}
	xds.capnhatlist(thutu);
	xds.capnhattrang(thutu, 1);
	vitri = 0;
	tcc.drawfirstbar(thutu, 1);
	tcc.drawsecondbar(thutu, 0);
	tcc.drawsearchbar(0);
	while(1){
		x=mousex();
		y=mousey();
		if(x<tcc.tamellip[0]+tcc.dorongellip){
			if(getpixel(x, y) == LIGHTGRAY){
				int vitri = 0;
				while(y>(tcc.tamellip[1]+tcc.docaoellip)){
					vitri++;
					y = y - tcc.khoangcachellip;
				}
				if(vitri+1>=thutu){
					tcc.drawellip(tcc.thutuellip[vitri+1], vitri+1, 1);
					if(chonhanellip(tcc.tamellip[0]-tcc.dorongellip, tcc.tamellip[1]-tcc.docaoellip*tcc.khoangcachellip, tcc.tamellip[0]+tcc.dorongellip, tcc.tamellip[1]+tcc.docaoellip*tcc.khoangcachellip)){
						if(vitri == 4){
							menu();
						}
						else if(vitri == 3){
							luufile();
							baoluu(1);
							windowtool(APL);
						}
						else {
							if(thutu == FL) SortByIdAirplain(lapl);
							windowtool(tcc.thutuellip[vitri+1]);
						}
					}
					else tcc.drawellip(tcc.thutuellip[vitri+1], vitri+1, 0);
				}
				else{
					tcc.drawellip(tcc.thutuellip[vitri], vitri+1, 1);
					if(chonhanellip(tcc.tamellip[0]-tcc.dorongellip, tcc.tamellip[1]-tcc.docaoellip*tcc.khoangcachellip, tcc.tamellip[0]+tcc.dorongellip, tcc.tamellip[1]+tcc.docaoellip*tcc.khoangcachellip)){
						if(thutu == FL) SortByIdAirplain(lapl);
						windowtool(tcc.thutuellip[vitri]);
					}
					else tcc.drawellip(tcc.thutuellip[vitri], vitri+1, 0);
				}
			}
		}
		if(chucnang!=1){
			if(x>tcc.hcnfistbar[0] && x<tcc.hcnfistbar[2] && y>tcc.hcnfistbar[1] && y<tcc.hcnfistbar[3]){
				tcc.drawfirstbar(thutu, 1);
				if(chonhanhcn(tcc.hcnfistbar[0], tcc.hcnfistbar[1], tcc.hcnfistbar[2], tcc.hcnfistbar[3])){
					if(chucnang == 3) tcc.drawsearchbar(0);
					if(chucnang == 2) tcc.drawsecondbar(thutu, 0);
					if(chucnang == 2 && (thutu == FL || thutu == BK)){
						if(thutu == BK){
							tcc.deletesearchflight();
							ngay.reset();
							thang.reset();
							nam.reset();
							noiden.reset();
						} 
						tcc.drawsearchbar(0);
					} 
					chucnang = 1;
					xds.capnhatlist(thutu);
				}
				else tcc.drawfirstbar(thutu, 0);
			}
		}
		if(chucnang!=2){
			if(x>tcc.hcnsecondfistbar[0] && x<tcc.hcnsecondfistbar[2] && y>tcc.hcnsecondfistbar[1] && y<tcc.hcnsecondfistbar[3]){
				tcc.drawsecondbar(thutu, 1);
				if(chonhanhcn(tcc.hcnsecondfistbar[0], tcc.hcnsecondfistbar[1], tcc.hcnsecondfistbar[2], tcc.hcnsecondfistbar[3])){
					if(chucnang == 1) tcc.drawfirstbar(thutu, 0);
					if(chucnang == 3) tcc.drawsearchbar(0);
					chucnang = 2;
					if(thutu == APL || thutu == PSG){
						windowextra(thutu, 1, 1);
					}
					if(thutu == FL){
						tcc.deletesearchbar();
						xds.capnhatlist(NFL);
						xds.capnhattrang(NFL, 1);
					}
					if(thutu == BK){
						search.reset();
						tcc.deletesearchbar();
						tcc.drawsearchflight();
						xds.soluongphantu = 0;
						chonnhap = 0;
						xds.capnhattheodiachi(NBK);
						xds.capnhattrang(NBK, 0);
					}
				}
				else tcc.drawsecondbar(thutu, 0);
			}
		}
		//chuc nang 3 la search
		if(chucnang!=3){
			if(!(chucnang ==2 && thutu == BK))
				if(kbhit()){
					char c = getch();
				}
			if(x>tcc.hcnsearch[0] && x<tcc.hcnsearch[2] && y>tcc.hcnsearch[1] && y<tcc.hcnsearch[3] && !((thutu == FL || thutu == BK) && chucnang == 2)){
				if(chonhanhcn(tcc.hcnsearch[0], tcc.hcnsearch[1], tcc.hcnsearch[2], tcc.hcnsearch[3])){
					tcc.drawsearchbar(1);
					if(chucnang == 1) tcc.drawfirstbar(thutu, 0);
					if(chucnang == 2) tcc.drawsecondbar(thutu, 0);
					search.reset();
					chucnang = 3;
					if(thutu == APL){
						xds.soluongphantu = tim(lapl, "", 0);
					}
					if(thutu == PSG || thutu == FL || thutu == BK) 
						xds.soluongphantu = 0;
					xds.capnhattheodiachi(thutu);
					
				}
			}
		}
		if(x>xds.toadohaigoc[0] && x<xds.toadohaigoc[2] && y>xds.toadohaidinhngang[1] && y<xds.toadohaigoc[3] && !(thutu == FL && chucnang == 2)){
			xds.xulydong(thutu, y, chucnang, 1);
		}
		if(chucnang == 2 && thutu == BK){
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				if(x>tcc.hcnsearchflight[0] && y>tcc.hcnsearchflight[1] && x<tcc.hcnsearchflight[14] && y<tcc.hcnsearchflight[3]){
					if(chonnhap == 1) xuatkytucanletrai(tcc.hcnsearchflight[0]+5, tcc.hcnsearchflight[1]+10, ngay.text, 0, 2, BLACK, WHITE);
					else if(chonnhap == 2) xuatkytucanletrai(tcc.hcnsearchflight[4]+5, tcc.hcnsearchflight[5]+10, thang.text, 0, 2, BLACK, WHITE);
					else if(chonnhap == 3) xuatkytucanletrai(tcc.hcnsearchflight[8]+5, tcc.hcnsearchflight[9]+10, nam.text, 0, 2, BLACK, WHITE);
					else if(chonnhap == 4) xuatkytucanletrai(tcc.hcnsearchflight[12]+5, tcc.hcnsearchflight[13]+10, noiden.text, 0, 2, BLACK, WHITE);
				}
				if(x>tcc.hcnsearchflight[0] && y>tcc.hcnsearchflight[1] && x<tcc.hcnsearchflight[2] && y<tcc.hcnsearchflight[3])
					chonnhap=1;
				if(x>tcc.hcnsearchflight[4] && y>tcc.hcnsearchflight[5] && x<tcc.hcnsearchflight[6] && y<tcc.hcnsearchflight[7])
					chonnhap=2;
				if(x>tcc.hcnsearchflight[8] && y>tcc.hcnsearchflight[9] && x<tcc.hcnsearchflight[10] && y<tcc.hcnsearchflight[11])
					chonnhap=3;
				if(x>tcc.hcnsearchflight[12] && y>tcc.hcnsearchflight[13] && x<tcc.hcnsearchflight[14] && y<tcc.hcnsearchflight[15])
					chonnhap=4;
				if(x>tcc.hcnbuttonsearch[0] && y>tcc.hcnbuttonsearch[1] && x<tcc.hcnbuttonsearch[2] && y<tcc.hcnbuttonsearch[3]){
					if(ngay.soluong>0 && thang.soluong>0 && nam.soluong>0 && noiden.soluong ==0){
						nkt.luunhaplieuvaoso(ngay, dtime.d); nkt.luunhaplieuvaoso(thang, dtime.m); nkt.luunhaplieuvaoso(nam, dtime.y);
						sfl.clear();
						FindCharacterDate(nodefl, sfl, dtime);
						xds.soluongphantu = sfl.n;
						xds.capnhattheodiachi(NBK);
					}
					if(noiden.soluong >0 && (ngay.soluong==0 || thang.soluong==0 || nam.soluong==0)){
						noiden.text[noiden.soluong] = '\0';
						sfl.clear();
						FindCharacterSBD(nodefl, sfl, noiden.text);
						noiden.text[noiden.soluong] = ' ';
						xds.soluongphantu = sfl.n;
						xds.capnhattheodiachi(NBK);
					}
					if(ngay.soluong>0 && thang.soluong>0 && nam.soluong>0 && noiden.soluong > 0){
						sfl.clear();
						nkt.luunhaplieuvaoso(ngay, dtime.d); nkt.luunhaplieuvaoso(thang, dtime.m); nkt.luunhaplieuvaoso(nam, dtime.y);
						noiden.text[noiden.soluong] = '\0';
						FindCharacterDateAndPlace(nodefl, sfl, dtime, noiden.text);
						noiden.text[noiden.soluong] = ' ';
						xds.soluongphantu = sfl.n;
						xds.capnhattheodiachi(NBK);
					}
				}
			}
			if(chonnhap == 1) nkt.nhap(nhay, tcc.hcnsearchflight[0]+5, tcc.hcnsearchflight[1]+10, WHITE, BLACK, 0, 2, 1, 2, 0, 0, 0, thuchien, ngay);
			if(chonnhap == 2) nkt.nhap(nhay, tcc.hcnsearchflight[4]+5, tcc.hcnsearchflight[5]+10, WHITE, BLACK, 0, 2, 1, 2, 0, 0, 0, thuchien, thang);
			if(chonnhap == 3) nkt.nhap(nhay, tcc.hcnsearchflight[8]+5, tcc.hcnsearchflight[9]+10, WHITE, BLACK, 0, 2, 1, 4, 0, 0, 0, thuchien, nam);
			if(chonnhap == 4) nkt.nhap(nhay, tcc.hcnsearchflight[12]+5, tcc.hcnsearchflight[13]+10, WHITE, BLACK, 0, 2, 1, 15, 1, 0, 1, thuchien, noiden);
		}
		if(chucnang == 3){
			if(thutu == PSG) chochu = 0;
			if(thutu != PSG) chochu = 1;
			if(thutu == PSG) chogach = 0;
			if(thutu != PSG) chogach =1;
			nkt.nhap(nhay, tcc.hcnsearch[0]+10, tcc.hcnsearch[1]+10, WHITE, BLACK, 0, 2, 1, 15, 0, chogach, chochu, thuchien, search);
			if(thuchien == 1){
				if(thutu == APL){
					search.text[search.soluong] = '\0';
					xds.soluongphantu = tim(lapl, search.text, search.soluong);
					search.text[search.soluong] = ' ';
				}
				else if(thutu == PSG){
					if(search.soluong>0){
						search.text[search.soluong] = '\0';
						spsg.clear();
						LNR(root, spsg, search.text);
						xds.soluongphantu = spsg.n;
						search.text[search.soluong] = ' ';
					}
					else{
						xds.soluongphantu = 0;
						xds.velaikhung(thutu);
					} 
				}
				else if(thutu == FL){
					if(search.soluong>0){
						search.text[search.soluong] = '\0';
						sfl.clear();
						FindCharacterMCB(nodefl, sfl, search.text);
						xds.soluongphantu = sfl.n;
						search.text[search.soluong] = ' ';
					}
					else{
						xds.soluongphantu = 0;
						xds.velaikhung(thutu);
					} 
				}
				else if(thutu == BK){
					if(search.soluong>0){
						search.text[search.soluong] = '\0';
						sfl.clear();
						FindCharacterMCB(nodebk, sfl, search.text);
						xds.soluongphantu = sfl.n;
						search.text[search.soluong] = ' ';
					}
					else{
						xds.soluongphantu = 0;
						xds.velaikhung(thutu);
					}
				}
				xds.capnhattheodiachi(thutu);
			}
		}
		xds.doitrang(thutu, chucnang, x, y);
		delay(1);
	}
}

void windowtoolextra(int thutu){
	setbkcolor(BLACK);
	cleardevice();
	int vitrithoat[4] = {20, 20, 200, 100};
	int vitri = 0;
	int thuchien;
	int chucnang = 1;
	int sang = 1;
	int x,y;
	nhaplieu search;
	int nhay = 0; 
	xds.capnhatlist(thutu);
	xds.capnhattrang(thutu, 1);
	vitri = 0;
	if(thutu == PSG){
		tcc.drawfirstbar(thutu, 1);
		tcc.drawsecondbar(thutu, 0);
		tcc.drawsearchbar(0);
	}
	xds.tieude(thutu);
	vekhungchunhat(vitrithoat[0], vitrithoat[1], vitrithoat[2], vitrithoat[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
	while(1){
		x=mousex();
		y=mousey();
		if(x>vitrithoat[0] && y>vitrithoat[1] && x<vitrithoat[2] && y<vitrithoat[3]){
			vekhungchunhat(vitrithoat[0], vitrithoat[1], vitrithoat[2], vitrithoat[3], "THOAT", 9, 3, WHITE, LIGHTRED);
			if(chonhanhcn(vitrithoat[0], vitrithoat[1], vitrithoat[2], vitrithoat[3])){
				if(thutu == PSG) windowspecial(BK);
				else if(thutu == LPSG) windowextra(FL, 0, 1);
				else if(thutu == LFL) windowextra(PSG, 0, 1);
			} 
			else vekhungchunhat(vitrithoat[0], vitrithoat[1], vitrithoat[2], vitrithoat[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
		}
		if(chucnang!=1 && thutu == PSG){
			if(x>tcc.hcnfistbar[0] && x<tcc.hcnfistbar[2] && y>tcc.hcnfistbar[1] && y<tcc.hcnfistbar[3]){
				tcc.drawfirstbar(thutu, 1);
				if(chonhanhcn(tcc.hcnfistbar[0], tcc.hcnfistbar[1], tcc.hcnfistbar[2], tcc.hcnfistbar[3])){
					if(chucnang == 3) tcc.drawsearchbar(0);
					if(chucnang == 2) tcc.drawsecondbar(thutu, 0);
					chucnang = 1;
					xds.capnhatlist(thutu);
				}
				else tcc.drawfirstbar(thutu, 0);
			}
		}
		if(chucnang!=2 && thutu == PSG){
			if(x>tcc.hcnsecondfistbar[0] && x<tcc.hcnsecondfistbar[2] && y>tcc.hcnsecondfistbar[1] && y<tcc.hcnsecondfistbar[3]){
				tcc.drawsecondbar(thutu, 1);
				if(chonhanhcn(tcc.hcnsecondfistbar[0], tcc.hcnsecondfistbar[1], tcc.hcnsecondfistbar[2], tcc.hcnsecondfistbar[3])){
					if(chucnang == 1) tcc.drawfirstbar(thutu, 0);
					if(chucnang == 3) tcc.drawsearchbar(0);
					chucnang = 2;
					if(thutu == APL || thutu == PSG){
						windowextra(thutu, 1, 0);
					}
				}
				else tcc.drawsecondbar(thutu, 0);
			}
		}
		//chuc nang 3 la search
		if(chucnang!=3 && thutu == PSG){
			if(kbhit()){
				char c = getch();
			}
			if(x>tcc.hcnsearch[0] && x<tcc.hcnsearch[2] && y>tcc.hcnsearch[1] && y<tcc.hcnsearch[3]){
				if(chonhanhcn(tcc.hcnsearch[0], tcc.hcnsearch[1], tcc.hcnsearch[2], tcc.hcnsearch[3])){
					tcc.drawsearchbar(1);
					if(chucnang == 1) tcc.drawfirstbar(thutu, 0);
					if(chucnang == 2) tcc.drawsecondbar(thutu, 0);
					search.reset();
					chucnang = 3;
					if(thutu == APL){
						xds.soluongphantu = tim(lapl, "", 0);
					}
					if(thutu == PSG) 
						xds.soluongphantu = 0;
					xds.capnhattheodiachi(thutu);
				}
			}
		}
		if(x>xds.toadohaigoc[0] && x<xds.toadohaigoc[2] && y>xds.toadohaidinhngang[1] && y<xds.toadohaigoc[3] && thutu!=LPSG){
			xds.xulydong(thutu, y, chucnang, 0);
		}
		if(chucnang == 3){
			nkt.nhap(nhay, tcc.hcnsearch[0]+10, tcc.hcnsearch[1]+10, WHITE, BLACK, 0, 2, 1, 15, 0, 1, 1, thuchien, search);
			if(thuchien == 1){
				if(thutu == APL){
					search.text[search.soluong] = '\0';
					xds.soluongphantu = tim(lapl, search.text, search.soluong);
					search.text[search.soluong] = ' ';
				}
				else if(thutu == PSG){
					if(search.soluong>0){
						search.text[search.soluong] = '\0';
						spsg.clear();
						LNR(root, spsg, search.text);
						xds.soluongphantu = spsg.n;
						search.text[search.soluong] = ' ';
					}
					else{
						xds.soluongphantu = 0;
						xds.velaikhung(thutu);
					}
				}
				xds.capnhattheodiachi(thutu);
			}
		}
		xds.doitrang(thutu, chucnang, x, y);
		delay(1);
	}
}
