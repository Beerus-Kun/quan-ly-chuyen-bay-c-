struct xulychongoi{
	int toadoxuatghe[4] = {50, 20, 1300, 600};
	int toadothoat[4];
	int toadomin = 20;
	int toadomax = 100;
	int chieudaihinhvuong;
	int khoangcach = 10;
	int toadoout[4] = {500, 610, 700, 680};
	int cochu;
	int cot;
	int hang;
	char so[4];
	void xuatghe(FLIGHT fl){
		int a = ceil(sqrt(fl.Ticket->nTicketTotal / 2.0));
		int count = 0;
		int nen, chu;
		int doc = 1;
		char vitri[4];
		cot = 1; hang = 1;
		chieudaihinhvuong = floor((toadoxuatghe[3] - toadoxuatghe[1]-khoangcach*(a-1))/(a));
		if(chieudaihinhvuong>toadomax) chieudaihinhvuong = toadomax;
		if(chieudaihinhvuong<toadomin) chieudaihinhvuong = toadomin;
		int x1 = toadoxuatghe[0], x2 = toadoxuatghe[0]+chieudaihinhvuong, y1 = toadoxuatghe[1], y2 = toadoxuatghe[1]+chieudaihinhvuong;
		cochu = 3;
		if(fl.Ticket->nTicketTotal>100) cochu =2;
		if(fl.Ticket->nTicketTotal>190) cochu =1;
		do{
			count++;
			itoa(count, vitri, 10);
			if(fl.Ticket->List[count-1].stt == -1) {
				nen = LIGHTGRAY;
				chu = BLACK;
			}
			if(fl.Ticket->List[count-1].stt != -1){
				nen = LIGHTRED;
				chu = WHITE;
			}
			vekhungchunhat(x1, y1, x2, y2, vitri, 0, cochu, chu, nen);
			if(x2+chieudaihinhvuong+khoangcach<=toadoxuatghe[2]){
				x1 = x1 + chieudaihinhvuong + khoangcach;
				x2 = x2 + chieudaihinhvuong + khoangcach;
				doc ++;
			}
			else{
				x1 = toadoxuatghe[0]; x2 = toadoxuatghe[0]+chieudaihinhvuong;
				y1 = y1 + chieudaihinhvuong+khoangcach, y2 = y2+chieudaihinhvuong+khoangcach;
				if(doc>cot) cot = doc;
				doc = 0;
				hang++;
			}
		}
		while(count < fl.Ticket->nTicketTotal);
		vekhungchunhat(toadoout[0], toadoout[1], toadoout[2], toadoout[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
	}
	int xethang(int y){
		for(int i=0; i<hang; i++){
			if(y>(toadoxuatghe[1]+i*chieudaihinhvuong+i*khoangcach) && y<(toadoxuatghe[1]+(i+1)*chieudaihinhvuong+i*khoangcach))
				return i+1;
		}
	}
	int xetcot(int x){
		for(int i=0; i<cot; i++){
			if(x>(toadoxuatghe[0]+i*chieudaihinhvuong+i*khoangcach) && x<(toadoxuatghe[0]+(i+1)*chieudaihinhvuong+i*khoangcach))
				return i+1;
		}
	}
	void xetchongoi(int x, int y){
		int hanghientai, cothientai;
		int vitrichongoi;
		char vitri[4];
		if(getpixel(x, y) == LIGHTGRAY && !(x>toadoout[0] && y>toadoout[1] && x<toadoout[2] && y<toadoout[3])){
			hanghientai = xethang(y);
			cothientai = xetcot(x);
			vitrichongoi = (hanghientai-1)*cot  + cothientai;
			if(vitrichongoi<=fl.Ticket->nTicketTotal && vitrichongoi>0){
				itoa(vitrichongoi, vitri, 10);
				vekhungchunhat(toadoxuatghe[0]+(cothientai-1)*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+(hanghientai-1)*chieudaihinhvuong+(hanghientai-1)*khoangcach, toadoxuatghe[0]+cothientai*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+hanghientai*chieudaihinhvuong+(hanghientai-1)*khoangcach, vitri, 0, cochu, WHITE, LIGHTGREEN);
				if(chonhanhcn(toadoxuatghe[0]+(cothientai-1)*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+(hanghientai-1)*chieudaihinhvuong+(hanghientai-1)*khoangcach, toadoxuatghe[0]+cothientai*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+hanghientai*chieudaihinhvuong+(hanghientai-1)*khoangcach) == 1){
					vitrighe = vitrichongoi;
					windowtoolextra(PSG);
				}
				else vekhungchunhat(toadoxuatghe[0]+(cothientai-1)*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+(hanghientai-1)*chieudaihinhvuong+(hanghientai-1)*khoangcach, toadoxuatghe[0]+cothientai*chieudaihinhvuong+(cothientai-1)*khoangcach, toadoxuatghe[1]+hanghientai*chieudaihinhvuong+(hanghientai-1)*khoangcach, vitri, 0, cochu, BLACK, LIGHTGRAY);
			}
		}
	}
	void thoat(int x, int y){
		if(x>toadoout[0] && y>toadoout[1] && x<toadoout[2] && y<toadoout[3]){
			vekhungchunhat(toadoout[0], toadoout[1], toadoout[2], toadoout[3], "THOAT", 9, 3, WHITE, LIGHTRED);
			if(chonhanhcn(toadoout[0] , toadoout[1] , toadoout[2] , toadoout[3])){
				windowtool(BK);
			}
			else vekhungchunhat(toadoout[0], toadoout[1], toadoout[2], toadoout[3], "THOAT", 9, 3, BLACK, LIGHTGRAY);
		}
	}
};
xulychongoi xlcn;

void windowspecial(int thutu){
	setbkcolor(BLACK);
	cleardevice();
	int x, y;
	xlcn.xuatghe(fl);
	while(1){
		x = mousex();
		y = mousey();
		xlcn.xetchongoi(x, y);
		xlcn.thoat(x,y);
		delay(1);
	}
}
