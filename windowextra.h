
int hoi(int thoatkhong){
	int khungthoat[4] = {450, 200, 850, 400};
	int x, y;
	int co[4] = {525, 320, 625, 360};
	int khong[4] = {675,320 , 775, 360};
	int toadoxuatkytu[2] = {487, 250};
	setfillstyle(1, 7);
	bar(khungthoat[0], khungthoat[1], khungthoat[2], khungthoat[3]);
	if(thoatkhong == 1)
		xuatkytucanletrai(toadoxuatkytu[0], toadoxuatkytu[1], "Ban co muon thoat khong?", 9, 2, BLACK, 7);
	else if(thoatkhong == 2)
		xuatkytucanletrai(toadoxuatkytu[0], toadoxuatkytu[1], "Ban co muon huy khong?", 9, 2, BLACK, 7);
	else if(thoatkhong == 4)
		xuatkytucanletrai(toadoxuatkytu[0], toadoxuatkytu[1], "Ban co muon dat khong?", 9, 2, BLACK, 7);
	else
		xuatkytucanletrai(toadoxuatkytu[0], toadoxuatkytu[1], "Ban co muon xoa khong?", 9, 2, BLACK, 7);
	vekhungchunhat(co[0], co[1], co[2], co[3], "Co", 9, 2, BLACK, 8);
	vekhungchunhat(khong[0], khong[1], khong[2], khong[3], "Khong", 9, 2, BLACK, 8);
	while(1){
		x = mousex();
		y = mousey();
		if(x>co[0] && y>co[1] && x<co[2] && y<co[3]){
			vekhungchunhat(co[0], co[1], co[2], co[3], "Co", 9, 2, WHITE, GREEN);
			if(chonhanhcn(co[0], co[1], co[2], co[3])){
				return 1;
			}
			else vekhungchunhat(co[0], co[1], co[2], co[3], "Co", 9, 2, BLACK, 8);
		}
		if(x>khong[0] && y>khong[1] && x<khong[2] && y<khong[3]){
			vekhungchunhat(khong[0], khong[1], khong[2], khong[3], "Khong", 9, 2, WHITE, LIGHTRED);
			if(chonhanhcn(khong[0], khong[1], khong[2], khong[3])){
				return 0;
			}
			else vekhungchunhat(khong[0], khong[1], khong[2], khong[3], "Khong", 9, 2, BLACK, 8);
		}
		delay(1);
	}
}
void baoluu(int manhinhthem){
	int khungbao[4] = {475, 250, 825, 400};
	int vien = 25;
	if(manhinhthem == 1){
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "LUU THANH CONG", 9, 2, GREEN, LIGHTGREEN);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "LUU THANH CONG", 9, 2, WHITE, GREEN);
	}
	else{
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "SUA THANH CONG", 9, 2, GREEN, LIGHTGREEN);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "SUA THANH CONG", 9, 2, WHITE, GREEN);
	}
	delay(1000);
	if(kbhit()) char c = getch();
	return;
}
void baoxoa(int thutu){
	int khungbao[4] = {475, 250, 825, 400};
	int vien = 25;
	if(thutu == FL){
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "HUY THANH CONG", 9, 2, GREEN, LIGHTRED);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "HUY THANH CONG", 9, 2, WHITE, RED);
	}
	else{
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "XOA THANH CONG", 9, 2, GREEN, LIGHTRED);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "XOA THANH CONG", 9, 2, WHITE, RED);
	}
	delay(1000);
	if(kbhit()) char c = getch();
	return;
}
void baoloikhongdatve(){
	int khungbao[4] = {475, 250, 825, 400};
	int vien = 25;
	vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "KHONG DAT VE DUOC", 9, 2, GREEN, LIGHTRED);
	vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "KHONG DAT VE DUOC", 9, 2, WHITE, RED);

	delay(1000);
	if(kbhit()) char c = getch();
	return;
}
void baoloitrangthai(int huy){
	int khungbao[4] = {475, 250, 825, 400};
	int vien = 25;
	if(huy == 1){
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "KHONG HUY DUOC", 9, 2, GREEN, LIGHTRED);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "KHONG HUY DUOC", 9, 2, WHITE, RED);
	}
	else if(huy == 2){
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "KHONG XOA DUOC", 9, 2, GREEN, LIGHTRED);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "KHONG XOA DUOC", 9, 2, WHITE, RED);
	}
	else{
		vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "KHONG DOI DUOC", 9, 2, GREEN, LIGHTRED);
		vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "KHONG DOI DUOC", 9, 2, WHITE, RED);
	}
	delay(1000);
	if(kbhit()) char c = getch();
	return;
}
void baoloithemchuyenbay(){
	int khungbao[4] = {450, 250, 950, 400};
	int vien = 25;
	vekhungchunhat(khungbao[0], khungbao[1], khungbao[2], khungbao[3], "MAY BAY DA DUOC SU DUNG", 9, 2, GREEN, LIGHTRED);
	vekhungchunhat(khungbao[0] + vien, khungbao[1] + vien, khungbao[2] - vien, khungbao[3] - vien, "MAY BAY DA DUOC SU DUNG", 9, 2, WHITE, RED);
	delay(1000);
	if(kbhit()) char c = getch();
	return;
}
void baoloi(int thutu, int hang, int hienloi);
int sosanhsonhapvoigioihan(nhaplieu nl, int number){
	nl.text[nl.soluong] = '\0';
	int solieu = atoi(nl.text);
	nl.text[nl.soluong] = ' ';
	if(solieu < number) return -1;
	else if(solieu > number) return 1;
	else return 0;
}
struct xulygiaodienchucnang{
	int cho;
	int toadotieude[2] = {100, 100};
	int toadodongdau[2] = {200, 200};
	int toadokhoangtrangdau[4] = {490, 170+20, 1200, 210+20};
	int toadokhoangtrangdau2[4] = {490, 170+20, 770, 210+20};
	int toadokhoangtrangdau3[4] = {950, 170+20, 1100, 210+20};
	int toadodongdau2[2] = {toadokhoangtrangdau[0]+300, 200};
	int khoangcach3hang = 100;
	int khoangcach4hang = 75;
	int toadokhoangtranggio[8] = {590, toadokhoangtrangdau[1]+75*3, 650, toadokhoangtrangdau[3]+75*3, 680, toadokhoangtrangdau[1]+75*3, 740, toadokhoangtrangdau[3]+75*3};
	int toadokhoangtrangngay[12] = {920, toadokhoangtrangdau[1]+75*3, 980, toadokhoangtrangdau[3]+75*3, 1020, toadokhoangtrangdau[1]+75*3, 1080, toadokhoangtrangdau[3]+75*3, 1110, toadokhoangtrangdau[1]+75*3, 1205, toadokhoangtrangdau[3]+75*3};
	int toadodau2cham[2] = {toadokhoangtranggio[2]+5, toadokhoangtranggio[1]+10};
	int toadodaugachcheo[4] = {toadokhoangtrangngay[2]+5, toadokhoangtrangngay[1]+10, toadokhoangtrangngay[6]+5, toadokhoangtrangngay[1]+10};
	int toadoluu1[4] = {200+150, 170+200+20+50+100, 500+150, 170+200+20+50+50+100};
	int toadoluu2[4] = {550, 170+200+20+50+100, 850, 170+200+20+50+50+100};
	int toadothoat1[4] = {500+150+150, 170+200+20+50+100, 800+150+150, 170+200+20+50+50+100};
	int toadothoat2[4] = {900, 170+200+20+50+100, 1200, 170+200+20+50+50+100};
	int toadoxoa[4] = {850, 100, 1150, 150};
	int toadochinhsua[4] = {200, 170+200+20+50+100, 500, 170+200+20+50+50+100};
	void vethanhnhap(int thutu){
		setfillstyle(1, 15);
		if(thutu == APL){
			for(int i=0; i<3; i++) bar(toadokhoangtrangdau[0], toadokhoangtrangdau[1]+khoangcach3hang*i, toadokhoangtrangdau[2], toadokhoangtrangdau[3]+khoangcach3hang*i);
		}
		else if(thutu == PSG){
			for(int i=0; i<4; i++) bar(toadokhoangtrangdau[0], toadokhoangtrangdau[1]+khoangcach4hang*i, toadokhoangtrangdau[2], toadokhoangtrangdau[3]+khoangcach4hang*i);
		}
		else if(thutu == FL){
			for(int i=1; i<3; i++) bar(toadokhoangtrangdau[0], toadokhoangtrangdau[1]+khoangcach4hang*i, toadokhoangtrangdau[2], toadokhoangtrangdau[3]+khoangcach4hang*i);
			bar(toadokhoangtrangdau2[0], toadokhoangtrangdau2[1], toadokhoangtrangdau2[2], toadokhoangtrangdau2[3]);
			bar(toadokhoangtrangdau3[0], toadokhoangtrangdau3[1], toadokhoangtrangdau3[2], toadokhoangtrangdau3[3]);
			for(int i =0; i<2; i++) bar(toadokhoangtranggio[0+i*4], toadokhoangtranggio[1+i*4], toadokhoangtranggio[2+i*4], toadokhoangtranggio[3+i*4]);
			for(int i =0; i<3; i++) bar(toadokhoangtrangngay[0+i*4], toadokhoangtrangngay[1+i*4], toadokhoangtrangngay[2+i*4], toadokhoangtrangngay[3+i*4]);
			xuatkytucanletrai(toadodau2cham[0], toadodau2cham[1], ":", 0, 3, WHITE, BLACK);
			for(int i =0; i<2; i++) xuatkytucanletrai(toadodaugachcheo[0+i*2], toadodaugachcheo[1+i*2], "/", 0, 3, WHITE, BLACK);
		}
	}
	void vehinhchunhat(int thutu, int manhinhthem){
		vethanhnhap(thutu);
		if(manhinhthem == 1){
			if(thutu == APL || thutu == PSG || thutu == FL){
				vekhungchunhat(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3], "LUU", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadothoat1[0], toadothoat1[1], toadothoat1[2], toadothoat1[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
			}
		}
		else{
			if(thutu == APL || thutu == PSG){
				if(thutu == APL)
					vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "THEM CB", 9, 3, BLACK, LIGHTGRAY);
				if(thutu == PSG)
					vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "HUY VE", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadothoat2[0], toadothoat2[1], toadothoat2[2], toadothoat2[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadochinhsua[0], toadochinhsua[1], toadochinhsua[2], toadochinhsua[3], "CHINH SUA", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "XOA", 9, 3, BLACK, LIGHTGRAY);
			}
			else if(thutu == FL){
				vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "HUY CB", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "DS HANH KHACH", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadochinhsua[0], toadochinhsua[1], toadochinhsua[2], toadochinhsua[3], "CHINH SUA", 9, 3, BLACK, LIGHTGRAY);
				vekhungchunhat(toadothoat2[0], toadothoat2[1], toadothoat2[2], toadothoat2[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
			}
		}
	}
	void xuatgiaodien(int thutu, int manhinhthem){
		vehinhchunhat(thutu, manhinhthem);
		if(thutu == APL){
			if(manhinhthem == 0) xuatkytucanletrai(toadotieude[0], toadotieude[1], "CHINH SUA MAY BAY", 9, 5, 14, BLACK);
			else xuatkytucanletrai(toadotieude[0], toadotieude[1], "THEM MAY BAY", 9, 5, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1], "MA MAY BAY: ", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach3hang, "LOAI MAY BAY:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach3hang*2, "SO CHO:", 9, 3, 14, BLACK);
		}
		else if(thutu == PSG){
			if(manhinhthem == 0) xuatkytucanletrai(toadotieude[0], toadotieude[1], "CHINH SUA HK", 9, 5, 14, BLACK);
			else xuatkytucanletrai(toadotieude[0], toadotieude[1], "THEM HANH KHACH", 9, 5, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1], "CMND: ", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang, "HO:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang*2, "TEN:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang*3, "GIOI TINH:", 9, 3, 14, BLACK);
		}
		else if(thutu == FL){
			if(manhinhthem == 0) xuatkytucanletrai(toadotieude[0], toadotieude[1], "CHINH SUA CB", 9, 5, 14, BLACK);
			else xuatkytucanletrai(toadotieude[0], toadotieude[1], "THEM CHUYEN BAY", 9, 5, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1], "MA MAY BAY: ", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau2[0], toadodongdau2[1], "SO CHO:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang, "MA CB:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang*2, "NOI DEN:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau[0], toadodongdau[1]+khoangcach4hang*3, "THOI GIAN:", 9, 3, 14, BLACK);
			xuatkytucanletrai(toadokhoangtrangdau[0], toadodongdau[1]+khoangcach4hang*3, "Gio:", 0, 3, 14, BLACK);
			xuatkytucanletrai(toadodongdau2[0], toadodongdau[1]+khoangcach4hang*3, "Ngay:", 0, 3, 14, BLACK);
		}
	}
	int xulychucnang(int thutu, int manhinhthem, int x, int y, int *loi, int xuatramanhinh){
		if((thutu == APL || thutu == PSG || thutu == FL) && manhinhthem == 0){
			if(x>toadoluu2[0] && y>toadoluu2[1] && x<toadoluu2[2] && y<toadoluu2[3]){
				if(thutu == APL){
					vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "THEM CB", 9, 3, WHITE, GREEN);
					if(chonhanhcn(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3])){
						windowextra(FL, 1, 1);
					}
					else 
						vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "THEM CB", 9, 3, BLACK, LIGHTGRAY);
				}
				else if(thutu == PSG){
					vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "HUY VE", 9, 3, WHITE, LIGHTRED);
					if(chonhanhcn(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3])){
						windowtoolextra(LFL);
					}
					else 
						vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "HUY VE", 9, 3, BLACK, LIGHTGRAY);
				}
				else if(thutu == FL){
					vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "DS HANH KHACH", 9, 3, WHITE, GREEN);
					if(chonhanhcn(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3])){
						windowtoolextra(LPSG);
					}
					else 
						vekhungchunhat(toadoluu2[0], toadoluu2[1], toadoluu2[2], toadoluu2[3], "DS HANH KHACH", 9, 3, BLACK, LIGHTGRAY);
				}
			}
			if(x>toadochinhsua[0] && y>toadochinhsua[1] && x<toadochinhsua[2] && y<toadochinhsua[3]){
				vekhungchunhat(toadochinhsua[0], toadochinhsua[1], toadochinhsua[2], toadochinhsua[3], "CHINH SUA", 9, 3, WHITE, GREEN);
				if(chonhanhcn(toadochinhsua[0], toadochinhsua[1], toadochinhsua[2], toadochinhsua[3])){
					for(int i=0; i<5; i++) if(loi[i] == 1){
						baoloi(thutu, 0, 1);
						return 0;
					}
					return 1;
				}
				else 
					vekhungchunhat(toadochinhsua[0], toadochinhsua[1], toadochinhsua[2], toadochinhsua[3], "CHINH SUA", 9, 3, BLACK, LIGHTGRAY);
			}
			if(x>toadoxoa[0] && y>toadoxoa[1] && x<toadoxoa[2] && y<toadoxoa[3]){
				if(thutu != FL)vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "XOA", 9, 3, WHITE, LIGHTRED);
				if(thutu == FL)vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "HUY CB", 9, 3, WHITE, LIGHTRED);
				if(chonhanhcn(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3])){
					int hoi1;
					if(thutu == FL) hoi1 = 2;
					if(thutu != FL) hoi1 = 0;
					if((thutu == PSG && psg.booktimes>0) || (thutu == APL && apl->Turn>0)){
						baoloitrangthai(2);
						windowextra(thutu, manhinhthem, 1);
					}
					if(thutu == FL && (fl.tt == huy_chuyen || fl.tt == hoan_tat)){
						baoloitrangthai(1);
						windowextra(thutu, manhinhthem, 1);
					}
					if(hoi(hoi1) == 1) return -1;
					else{
						windowextra(thutu, manhinhthem, 1);
					}
				}
				else{
					if(thutu == FL) vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "HUY CB", 9, 3, BLACK, LIGHTGRAY);
					else vekhungchunhat(toadoxoa[0], toadoxoa[1], toadoxoa[2], toadoxoa[3], "XOA", 9, 3, BLACK, LIGHTGRAY);
				}
			}
			if(x>toadothoat2[0] && y>toadothoat2[1] && x<toadothoat2[2] && y<toadothoat2[3]){
				vekhungchunhat(toadothoat2[0], toadothoat2[1], toadothoat2[2], toadothoat2[3], "THOAT", 9, 3, WHITE, LIGHTRED);
				if(chonhanhcn(toadothoat2[0], toadothoat2[1], toadothoat2[2], toadothoat2[3])){
					windowtool(thutu);
				}
				else 
					vekhungchunhat(toadothoat2[0], toadothoat2[1], toadothoat2[2], toadothoat2[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
			}
		}
		else{
			if(x>toadoluu1[0] && y>toadoluu1[1] && x<toadoluu1[2] && y<toadoluu1[3]){
				if(manhinhthem == 1)
					vekhungchunhat(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3], "LUU", 9, 3, WHITE, GREEN);
				if(manhinhthem == 0)
					vekhungchunhat(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3], "CHINH SUA", 9, 3, WHITE, GREEN);
				if(chonhanhcn(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3])){
					if(manhinhthem == 0){
					}
					else{
						if(thutu == APL || thutu == PSG || thutu == FL){
							for(int i=0; i<5; i++) 
								if(loi[i] == 1){
									baoloi(thutu, 0, 1);
									return 0;
								}
							return 1;
						}
					}
				}
				else{
					if(manhinhthem == 1)
						vekhungchunhat(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3], "LUU", 9, 3, BLACK, LIGHTGRAY);
					else 
						vekhungchunhat(toadoluu1[0], toadoluu1[1], toadoluu1[2], toadoluu1[3], "CHINH SUA", 9, 3, BLACK, LIGHTGRAY);
				} 
			}
			if(x>toadothoat1[0] && y>toadothoat1[1] && x<toadothoat1[2] && y<toadothoat1[3]){
				vekhungchunhat(toadothoat1[0], toadothoat1[1], toadothoat1[2], toadothoat1[3], "THOAT", 9, 3, WHITE, LIGHTRED);
				if(chonhanhcn(toadothoat1[0], toadothoat1[1], toadothoat1[2], toadothoat1[3])){
					if(thutu == PSG && xuatramanhinh == 0) windowspecial(PSG);
					else windowtool(thutu);
				}
				else vekhungchunhat(toadothoat1[0], toadothoat1[1], toadothoat1[2], toadothoat1[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
			}
		}
		return -2;
	}
	int xulytheohang(int thutu, int x, int y, int manhinhthem){
		if(ismouseclick(WM_LBUTTONDOWN)){
			clearmouseclick(WM_LBUTTONDOWN);
			if(thutu == APL){
				if(x>toadokhoangtrangdau[0] && y>toadokhoangtrangdau[1] && x<toadokhoangtrangdau[2] && y<toadokhoangtrangdau[3] && manhinhthem == 1) return 1;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach3hang) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach3hang)) return 2;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach3hang*2) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach3hang*2)) return 3;
			}
			else if(thutu == PSG){
				if(x>toadokhoangtrangdau[0] && y>toadokhoangtrangdau[1] && x<toadokhoangtrangdau[2] && y<toadokhoangtrangdau[3] && manhinhthem == 1) return 1;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach4hang) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach4hang)) return 2;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach4hang*2) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach4hang*2)) return 3;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach4hang*3) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach4hang*3)) return 4;
			}
			else if(thutu == FL){
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach4hang) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach4hang) && manhinhthem == 1) return 2;
				if(x>toadokhoangtrangdau[0] && y>(toadokhoangtrangdau[1]+khoangcach4hang*2) && x<toadokhoangtrangdau[2] && y<(toadokhoangtrangdau[3]+khoangcach4hang*2) && manhinhthem == 1) return 3;
				if(x>toadokhoangtranggio[0] && y>toadokhoangtranggio[1] && x<toadokhoangtranggio[2] && y<toadokhoangtranggio[3]) return 4;
				if(x>toadokhoangtranggio[4] && y>toadokhoangtranggio[5] && x<toadokhoangtranggio[6] && y<toadokhoangtranggio[7]) return 5;
				if(x>toadokhoangtrangngay[0] && y>toadokhoangtrangngay[1] && x<toadokhoangtrangngay[2] && y<toadokhoangtrangngay[3]) return 6;
				if(x>toadokhoangtrangngay[4] && y>toadokhoangtrangngay[5] && x<toadokhoangtrangngay[6] && y<toadokhoangtrangngay[7]) return 7;
				if(x>toadokhoangtrangngay[8] && y>toadokhoangtrangngay[9] && x<toadokhoangtrangngay[10] && y<toadokhoangtrangngay[11]) return 8;
			}
		}
		return 0;
	}
};

xulygiaodienchucnang xldd;


struct xulynhaptheohang{
	int hang;
	nhaplieu hang1, hang1_2, hang2, hang3, hang4, hang4_2, hang4_3, hang4_4, hang4_5;
	int toadoxuathang1[2] = {xldd.toadokhoangtrangdau[0]+10, xldd.toadokhoangtrangdau[1]+10};
	int toadoxuatgio[4] = {xldd.toadokhoangtranggio[0]+10, xldd.toadokhoangtranggio[1]+10, xldd.toadokhoangtranggio[4]+10, xldd.toadokhoangtranggio[5]+10};
	int toadoxuatngay[6] = {xldd.toadokhoangtrangngay[0]+10, xldd.toadokhoangtrangngay[1]+10, xldd.toadokhoangtrangngay[4]+10, xldd.toadokhoangtrangngay[5]+10, xldd.toadokhoangtrangngay[8]+10, xldd.toadokhoangtrangngay[9]+10};
	int toadoxuathang1_2[2] = {xldd.toadokhoangtrangdau3[0]+10, xldd.toadokhoangtrangdau3[1]+10};
	int khoangcach3hang = 100;
	int khoangcach4hang = 75;
	int bientam;
	void reset(){
		hang1.reset();
		hang2.reset();
		hang3.reset();
		hang4.reset();
		hang1_2.reset();
		hang4_2.reset();
		hang4_3.reset();
		hang4_4.reset();
		hang4_5.reset();
	}
	void resetbien(int thutu){
		if(thutu == APL){
			memset(apl->IdMB ,0, 15);
			memset(apl->Type ,0, 40);
		}
	}
	void luunhaplieuvaoso(nhaplieu nl, int &a){
		nl.text[nl.soluong] = '\0';
		a = atoi(nl.text);
	}
	void xulybiennhapvao(nhaplieu &nl){
		nl.text[nl.soluong] = '\0';
		if(nl.text[nl.soluong-1]== '-' || nl.text[nl.soluong-1]== ' '){
			nl.text[nl.soluong-1] = '\0';
			nl.soluong --;
		} 
	}
	void luunhaplieuvaokytu(nhaplieu nl, char *a, int limit){
		xulybiennhapvao(nl);
		for(int i=0; i<nl.soluong; i++){
			a[i] = nl.text[i];
		}
		a[nl.soluong] = '\0';
	}
	int luu(int thutu, int manhinhthem){
		if(thutu == APL){
			if(manhinhthem == 1){
				Airplane *ap = new Airplane;
				luunhaplieuvaokytu(hang1, ap->IdMB, MAXIDMB);
				luunhaplieuvaokytu(hang2, ap->Type, MAXTYPE);
				luunhaplieuvaoso(hang3, ap->Chair);
				InsertAirplane(lapl, ap);
			} 
			else{
				luunhaplieuvaokytu(hang1, apl->IdMB, MAXIDMB);
				luunhaplieuvaokytu(hang2, apl->Type, MAXTYPE);
				luunhaplieuvaoso(hang3, apl->Chair);
				if(correction(lapl, apl) == false) return 0;
				else return 1;
			} 
		}
		else if(thutu == PSG){
			luunhaplieuvaokytu(hang1, psg.id, sizeCMND_max);
			luunhaplieuvaokytu(hang2, psg.lastName, sizeho_max);
			luunhaplieuvaokytu(hang3, psg.firstName, sizeten_max);
			if(hang4.text[1] == 'U') psg.sex = 0;
			else if(hang4.text[1] == 'A') psg.sex = 1;
			if(manhinhthem == 1) InsertPassenger(root, psg);
			else if(manhinhthem == 0) EditPassenger(root, psg);
		}
		else if(thutu == FL){
			luunhaplieuvaokytu(hang1, fl.SoHieuMB, MAXIDMB);
			luunhaplieuvaokytu(hang2, fl.MaCB, sizema_max);
			luunhaplieuvaokytu(hang3, fl.SanBD, size_diemden);
			fl.dt = dtime;
			if(manhinhthem == 1){
				LI_TI *listve = new LI_TI(lapl.List[FindIndexAirplane(lapl, fl.SoHieuMB)]->Chair);
				FLIGHT f(fl.MaCB, fl.SanBD, fl.dt, con_ve, apl->IdMB, listve);
				if(InsertFlight(nodefl, f, lapl) == false) return 0;
			} 
			else if(manhinhthem == 0)
				if(CorrestionDate(nodefl, fl) == false) return 0;
		}
		return 1;
	}
	void xoa(int thutu){
		if(thutu == APL){
			xulybiennhapvao(hang1);
			DeleteAiplane(lapl, hang1.text);
		}
		else if(thutu == PSG){
			xulybiennhapvao(hang1);
			DeletePassenger(root, hang1.text);
		}
		else if(thutu == FL){
			ChangeTT(nodefl, fl, lapl);
		}
	}
	void luukytuvaonhaplieu(nhaplieu &nl, char *kytu){
		int i=0;
		while(kytu[i] != '\0'){
			nl.text[i] = kytu[i];
			nl.text1[i] = kytu[i];
			i++;
		}
		nl.soluong = i;
		nl.text[i] = ' ';
		nl.text1[i] = '|';
	}
	void luusovaonhaplieu(nhaplieu &nl, int number){
		itoa(number, nl.text, 10);
		itoa(number, nl.text1, 10);
		int i=0;
		if(number == 0){
			for(int j=0; j<2; j++){
				nl.text[j] = '0';
				nl.text1[j] = '0';
			}
			i = 2;
		}
		else{
			while(number != 0){
				number = number /10;
				i++;
			}
		}
		
		nl.soluong = i;
		nl.text[i] = ' ';
		nl.text1[i] = '|';
	}
	void xuat(int thutu){
		if(thutu == APL){
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1], hang1.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach3hang, hang2.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach3hang*2, hang3.text, 0, 2, BLACK, WHITE);
		}
		else if(thutu == PSG){
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1], hang1.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang, hang2.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*2, hang3.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*3, hang4.text, 0, 2, BLACK, WHITE);
		}
		else if(thutu == FL){
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1], hang1.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1_2[0], toadoxuathang1_2[1], hang1_2.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang, hang2.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*2, hang3.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuatgio[0], toadoxuatgio[1], hang4.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuatgio[2], toadoxuatgio[3], hang4_2.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuatngay[0], toadoxuatngay[1], hang4_3.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuatngay[2], toadoxuatngay[3], hang4_4.text, 0, 2, BLACK, WHITE);
			xuatkytucanletrai(toadoxuatngay[4], toadoxuatngay[5], hang4_5.text, 0, 2, BLACK, WHITE);
		}
	}
	int xulyloitrungma(int thutu, nhaplieu nl){
		if(nl.soluong == 0) return 0;
		int vitri;
		nl.text[nl.soluong] = '\0';
		if(thutu == APL) vitri = FindIndexAirplane(lapl, nl.text);
		if(thutu == PSG) vitri = CheckIdIsExisted(root, nl.text) -1;
		if(thutu == FL) vitri = TrungMaCB(nodefl, nl.text)-1;
		nl.text[nl.soluong] = ' ';
		if(vitri > -1) return 1;
		return 0;
	}
	void xoa1kytunhaplieu(nhaplieu &nl){
		nl.text[nl.soluong] = '\0';
		nl.text1[nl.soluong] = '\0';
		nl.text[--nl.soluong] = ' ';
		nl.text1[nl.soluong] = '|';
	}
	void them1kytunhaplieu(nhaplieu &nl, char c){
		nl.text[nl.soluong] = c;
		nl.text1[nl.soluong] = c;
		nl.text[++nl.soluong] = ' ';
		nl.text1[nl.soluong] = '|';
	}
	void xuattheohang(int thutu, int hang, int &nhay, int&loi){
		int thuchien = 0;
		int soluongcu;
		if(thutu == APL){
			if(hang == 1) {
				nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1], WHITE, BLACK, 0, 2, 1, sizesohieu_max, 0, 1, 1, thuchien, hang1);
				if(thuchien == 1){
					if(xulyloitrungma(thutu, hang1) == 1) loi = 1;
					else loi = -1;
				}
			}
			if(hang == 2) nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach3hang, WHITE, BLACK, 0, 2, 1, sizeloai_max, 1, 1, 1, thuchien, hang2);
			if(hang == 3){
				nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach3hang*2, WHITE, BLACK, 0, 2, 1, sizecho_max, 0, 0, 0, thuchien, hang3);
				if(thuchien == 1){
					if(sosanhsonhapvoigioihan(hang3, sochotoithieu)==-1) loi = 3;
					else loi = -1;
				}
			} 
		}
		else if(thutu == PSG){
			if(hang == 1){
				nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1], WHITE, BLACK, 0, 2, 1, sizesohieu_max, 0, 0, 0, thuchien, hang1);
				if(xulyloitrungma(thutu, hang1) == 1) loi =1;
				else loi = -1;
			}
			if(hang == 2) nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang, WHITE, BLACK, 0, 2, 0, sizeho_max, 1, 0, 1, thuchien, hang2);
			if(hang == 3) nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*2, WHITE, BLACK, 0, 2, 0, sizeten_max, 0, 0, 1, thuchien, hang3);
			if(hang == 4) {
				nkt.nhapgioitinh(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*3, WHITE, BLACK, 0, 2, hang4);
				if(hang4.text[1] == 'A' || hang4.text[1] == 'U') loi = -1;
				else loi = 4;
			}
		}
		else if(thutu == FL){
			if(hang == 2){
				nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1]+ xldd.khoangcach4hang, WHITE, BLACK, 0, 2, 1, sizesohieu_max, 0, 1, 1, thuchien, hang2);
				if(xulyloitrungma(thutu, hang2) == 1) loi =1;
				else loi = -1;
			}
			if(hang == 3) nkt.nhap(nhay, toadoxuathang1[0], toadoxuathang1[1] + xldd.khoangcach4hang*2, WHITE, BLACK, 0, 2, 0, size_diemden, 1, 0, 1, thuchien, hang3);
			if((hang==4 || hang==5 || hang==6 || hang==7 || hang==8)){
				if(hang == 4) nkt.nhap(nhay, toadoxuatgio[0], toadoxuatgio[1], WHITE, BLACK, 0, 2, 1, sokituthoigian, 0, 0, 0, thuchien, hang4);
				if(hang == 5) nkt.nhap(nhay, toadoxuatgio[2], toadoxuatgio[3], WHITE, BLACK, 0, 2, 1, sokituthoigian, 0, 0, 0, thuchien, hang4_2);
				if(hang == 6) nkt.nhap(nhay, toadoxuatngay[0], toadoxuatngay[1], WHITE, BLACK, 0, 2, 1, sokituthoigian, 0, 0, 0, thuchien, hang4_3);
				if(hang == 7) nkt.nhap(nhay, toadoxuatngay[2], toadoxuatngay[3], WHITE, BLACK, 0, 2, 1, sokituthoigian, 0, 0, 0, thuchien, hang4_4);
				if(hang == 8) nkt.nhap(nhay, toadoxuatngay[4], toadoxuatngay[5], WHITE, BLACK, 0, 2, 1, sokitunam, 0, 0, 0, thuchien, hang4_5);
				loi = -1;
				if(hang4.soluong>0 && hang4_2.soluong>0 && hang4_3.soluong>0 && hang4_4.soluong>0 && hang4_5.soluong>0){
					luunhaplieuvaoso(hang4, dtime.h);
					luunhaplieuvaoso(hang4_2, dtime.mi);
					luunhaplieuvaoso(hang4_3, dtime.d);
					luunhaplieuvaoso(hang4_4, dtime.m);
					luunhaplieuvaoso(hang4_5, dtime.y);
					if(DateTimeValue(dtime) == false) loi = 4;
					else loi = -1;
				}
			}
		}
	}
	int xulyloitrungtam(int thutu){
		if(thutu == APL && (hang1.soluong == 0 || hang2.soluong == 0 || hang3.soluong == 0)) return 1;
		else if(thutu == PSG && (hang1.soluong == 0 || hang2.soluong == 0 || hang3.soluong == 0 || hang4.soluong<2)) return 1;
		else if(thutu == FL && (hang2.soluong == 0 || hang3.soluong == 0 || hang4.soluong==0 || hang4_2.soluong==0 || hang4_3.soluong==0 || hang4_4.soluong==0 || hang4_5.soluong==0)) return 1;
		return 0;
	}
};
xulynhaptheohang xln;

void baoloi(int thutu, int hang, int hienloi){
	int toadoloi[2] = {500, 160};
	int toadoloitrungtam[2] = {490, 490};
	char xoaloi[70] = "                                                                     ";
	if(thutu == APL){
		if(hienloi == 1){
			if(hang==1) xuatkytucanletrai(toadoloi[0], toadoloi[1], "MA BI TRUNG", 0, 2, RED, BLACK);
			else if(hang == 3) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach3hang*2, "SO PHAI LON HON 20", 0, 2, RED, BLACK);
			else if(hang == 0)xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], "VUI LONG NHAP DU THONG TIN", 0, 2, RED, BLACK);
		}
		else{
			if(hang == 1 || hang == 3) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach3hang*(hang-1), xoaloi, 9, 3, RED, BLACK);
			else xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], xoaloi, 9, 3, RED, BLACK);
		}
	}
	else if(thutu == PSG){
		if(hienloi == 1){
			if(hang==1) xuatkytucanletrai(toadoloi[0], toadoloi[1], "CMND BI TRUNG", 0, 2, RED, BLACK);
			if(hang == 4) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang*3, "DIEN NAM HOAC NU", 0, 2, RED, BLACK);
			else if(hang == 0)xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], "VUI LONG NHAP DU THONG TIN", 0, 2, RED, BLACK);
		}
		else{
			if(hang == 1 || hang == 4) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang*(hang-1), xoaloi, 9, 3, RED, BLACK);
			else xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], xoaloi, 9, 3, RED, BLACK);
		}
	}
	else if(thutu == FL){
		if(hienloi == 1){
			if(hang==2) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang, "MA MAY BAY BI TRUNG", 9, 3, RED, BLACK);
			else if(hang>3) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang*3, "VUI LONG NHAP DUNG THONG TIN", 9, 3, RED, BLACK);
			else if(hang == 0) xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], "VUI LONG NHAP DU THONG TIN", 0, 2, RED, BLACK);
		}
		else{
			if(hang == 2) xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang, xoaloi, 9, 3, RED, BLACK);
			else if(hang>3){
				xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang*3, xoaloi, 9, 3, RED, BLACK);
				xuatkytucanletrai(toadoloi[0], toadoloi[1]+xldd.khoangcach4hang*3, "GIO: hh:mm        NGAY: dd/mm/yyyy", 9, 3, RED, BLACK);
			} 
			else xuatkytucanletrai(toadoloitrungtam[0], toadoloitrungtam[1], xoaloi, 9, 3, RED, BLACK);
		}
	}
}

void windowextra(int thutu, int manhinhthem, int xuatramanhinh){
	setbkcolor(BLACK);
	cleardevice();
	int x,y;
	char c;
	int nhay = 0;
	int hang = 0, hang1 = 0;
	int loi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int tam=-1;
	int xuly;
	xldd.xuatgiaodien(thutu, manhinhthem);
	xln.reset();
	if(manhinhthem == 0){
		if(thutu == APL){
			xln.luukytuvaonhaplieu(xln.hang1, apl->IdMB);
			xln.luukytuvaonhaplieu(xln.hang2, apl->Type);
			xln.luusovaonhaplieu(xln.hang3, apl->Chair);
		}
		else if(thutu == PSG){
			xln.luukytuvaonhaplieu(xln.hang1, psg.id);
			xln.luukytuvaonhaplieu(xln.hang2, psg.lastName);
			xln.luukytuvaonhaplieu(xln.hang3, psg.firstName);
			xln.luukytuvaonhaplieu(xln.hang4, gioitinh[psg.sex]);
		}
		else if(thutu == FL){
			xln.luukytuvaonhaplieu(xln.hang1, fl.SoHieuMB);
			xln.hang1.text[xln.hang1.soluong] = '\0';
			xln.luusovaonhaplieu(xln.hang1_2, lapl.List[FindIndexAirplane(lapl, fl.SoHieuMB)]->Chair);
			xln.luukytuvaonhaplieu(xln.hang2, fl.MaCB);
			xln.luukytuvaonhaplieu(xln.hang3, fl.SanBD);
			xln.luusovaonhaplieu(xln.hang4, fl.dt.h);
			xln.luusovaonhaplieu(xln.hang4_2, fl.dt.mi);
			xln.luusovaonhaplieu(xln.hang4_3, fl.dt.d);
			xln.luusovaonhaplieu(xln.hang4_4, fl.dt.m);
			xln.luusovaonhaplieu(xln.hang4_5, fl.dt.y);
			dtime =fl.dt;
		}
	}
	if(manhinhthem == 1 && thutu == FL){
		xln.luukytuvaonhaplieu(xln.hang1, apl->IdMB);
		xln.hang1.text[xln.hang1.soluong] = '\0';
		xln.luusovaonhaplieu(xln.hang1_2, apl->Chair);
	}
	xln.xuat(thutu);
	if(thutu==FL){
		baoloi(thutu, 4, 0);
	}
	while(1){
		x = mousex();
		y = mousey();
		xuly = xldd.xulychucnang(thutu, manhinhthem, x, y, loi, xuatramanhinh);
		if(manhinhthem==1 && xuly == 1){
			if(xln.luu(thutu, manhinhthem) == 1){
				baoluu(manhinhthem);
			} 
			else{
				baoloithemchuyenbay();
			}
			
			if(xuatramanhinh == 0 && thutu == PSG){
				if(BuyTicket(root, nodefl, psg.id, fl.MaCB, vitrighe)==false) baoloikhongdatve();
				windowspecial(BK);
			} 
			if(xuatramanhinh != 0) windowextra(thutu, 1, 1);
		}
		if(manhinhthem == 0){
			if(xuly == 1){
				if(xln.luu(thutu, manhinhthem) == 1){
					baoluu(manhinhthem);
				} 
				else{
					baoloithemchuyenbay();
				}
				windowtool(thutu);
			}
			else if(xuly == -1) {
				xln.xoa(thutu);
				baoxoa(thutu);
				windowtool(thutu);
			}
		}
		hang = xldd.xulytheohang(thutu, x, y, manhinhthem);
		if(hang!=0 && hang1!=hang){
			xln.xuat(thutu);
			hang1 = hang;
			if(loi[hang1] == 0) tam = -1;
			else tam = 0;
		}
		if(hang1 != 0){
			xln.xuattheohang(thutu, hang1, nhay, tam);
		}
		if(tam != -1 && loi[hang1] == 0){
			baoloi(thutu, hang1, 1);
			loi[hang1] = 1;
			if(thutu==FL && hang1>3 && hang1<9){
				for(int i=4; i<9; i++) loi[i] = 1;
			}
		}
		if(tam == -1 && loi[hang1] == 1){
			baoloi(thutu, hang1, 0);
			loi[hang1] = 0;
			if(thutu==FL && hang1>3 && hang1<9){
				for(int i=4; i<9; i++) loi[i] = 0;
			}
		}
		loi[0] = xln.xulyloitrungtam(thutu);
		if(kbhit()) c=getch();
		delay(1);
	}
}
