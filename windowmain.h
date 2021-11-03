
void xuatkytu(int x1, int y1, int x2, int y2,char *kytu, int kieu, int cochu, int mauchu, int maunen){
	settextstyle(kieu, HORIZ_DIR, cochu);
	setcolor(mauchu);
	setbkcolor(maunen);
	outtextxy((x1+x2)/2-textwidth(kytu)/2, (y1+y2)/2 - textheight(kytu)/2 , kytu);
}

void xuatkytucanletrai(int x, int y, char *kytu, int kieu, int cochu, int mauchu, int maunen){
	settextstyle(kieu, HORIZ_DIR, cochu);
	setcolor(mauchu);
	setbkcolor(maunen);
	outtextxy(x, y, kytu);
}

int chonhanellip(int x1, int y1, int x2, int y2){
	int x,y;
	clearmouseclick(WM_LBUTTONDOWN);
	while(1){
		x = mousex();
		y = mousey();
		if(ismouseclick(WM_LBUTTONDOWN)){
			clearmouseclick(WM_LBUTTONDOWN);
			return 1;
		}
		if(x<x1 || x>x2 || y<y1 || y>y2 || getpixel(x,y) == BLACK) return 0;
		delay(1);
	}
}

int chonhanhcn(int x1, int y1, int x2, int y2){
	int x,y;
	clearmouseclick(WM_LBUTTONDOWN);
	while(1){
		x = mousex();
		y = mousey();
		if(ismouseclick(WM_LBUTTONDOWN)){
			clearmouseclick(WM_LBUTTONDOWN);
			return 1;
		}
		if(x<x1 || x>x2 || y<y1 || y>y2 ) return 0;
		delay(1);
	}
}

int chonhantamgiac(int x1, int y1, int x2, int y2){
	int x,y;
	clearmouseclick(WM_LBUTTONDOWN);
	while(1){
		x = mousex();
		y = mousey();
		if(ismouseclick(WM_LBUTTONDOWN)){
			clearmouseclick(WM_LBUTTONDOWN);
			return 1;
		}
		if(x<x1 || x>x2 || y<y1 || y>y2 || getpixel(x,y) == BLACK) return 0;
		delay(1);
	}
}

void vekhungchunhat(int x1, int y1, int x2, int y2, char *kytu, int kieu, int cochu, int chu, int nen){
	setfillstyle(1, nen);
	bar(x1, y1, x2, y2);
	xuatkytu(x1, y1, x2, y2, kytu, kieu, cochu, chu, nen);		
}

struct drawinmain{
	int cloud1[80] = {148, 187, 150, 180, 154, 174, 162, 170, 171, 166, 181, 164, 192, 162 ,207, 161, 221, 161, 228, 164, 227, 156, 237, 148 ,251, 144 ,301, 143, 313, 148, 326, 143, 373, 142, 390, 147, 398, 149, 402, 155, 421, 159, 437, 168, 443, 180, 437, 190, 424, 200, 404, 204, 374, 205, 363, 201, 353, 212, 334, 220, 316, 223, 278, 222 ,260, 218, 247, 214, 239, 205, 220, 211, 194, 211, 173, 207, 161, 201, 151, 196 };
	int cloud2[72] = {719, 61, 729, 50, 746, 44, 764, 42, 784, 44, 799, 47, 811, 40, 826, 36, 843, 37, 856, 43, 868, 54, 887, 54 ,902, 57, 915, 62, 924, 70, 926, 78, 917, 89, 909, 92, 901, 95, 909, 100, 913, 106, 912, 112, 900, 120, 885, 123, 869, 123, 851, 117, 822, 121, 807, 117, 793, 112, 782, 108, 773, 101, 772, 93, 752, 93, 737, 89, 736, 77, 722, 70};
	int cloud3[68] = {898, 319, 901, 313, 910, 307, 919, 304, 937, 304, 949, 308, 955, 301, 967, 297, 983, 296, 994, 300, 1003, 306, 1011, 303, 1029, 303, 1040, 308, 1046, 310, 1050, 318, 1057, 321, 1065, 327, 1068, 335, 1064, 343, 1051, 350, 1038, 352, 1030, 351, 1018, 346, 1007, 353, 996, 356, 991, 357, 977, 357, 965, 355, 956, 352, 945, 341, 928, 341, 915, 337, 903, 333};
	int star1[20] = {320, 70, 326, 79, 346, 79, 331, 85, 336, 96, 322, 90, 306 ,97, 310, 87, 295, 80, 315, 79 };
	int star5[20] = {378, 243, 393, 251, 407, 246, 402, 254, 414, 262, 397, 262, 390, 273, 385, 261, 365, 260, 381, 253 };
	int star3[20] = {660, 88, 676, 90, 686, 84, 687, 95, 698, 99, 685, 102, 682, 113, 675, 104, 657 ,104 ,668, 97};
	int star4[20] = {807, 319, 811, 329, 828, 330, 816, 336, 818, 347, 805, 341, 788 ,347, 795, 337, 780, 328, 800, 329};
	int star2[20] = {938, 172, 938, 183, 952, 188, 937, 191, 934, 203, 924, 194, 909, 194, 917 ,186, 911, 175, 926, 179 };
	int bodyplane[50] = {958, 256, 954, 263, 944, 268, 926, 273, 907, 275, 878, 277, 850, 276, 708, 265, 601, 255, 536, 234, 498, 217 ,459 ,176 ,507, 172, 553, 210, 552, 205, 577 ,204 ,602 ,203 ,629 ,206 ,858 ,221 ,891 ,225 ,915 ,228 ,922 ,235 ,932 ,238 ,952 ,246 ,956 ,250 };
	int wing1[8] = {754, 216, 760, 153, 739, 152, 680, 210 };
	int wing2[12] = {602, 256, 669, 254, 704, 259, 706, 265, 438, 337, 409, 337 };
	int tailplane1[8] = {546, 203, 562, 184, 541, 184, 532, 192 };
	int tailplane2[10] = {536, 208, 458, 224, 446, 223, 491, 208, 533, 205};
	int cowling1[8] = {755 ,203, 773 ,206, 768, 215, 756, 215 };
	int cowling2[16] = {643, 283, 683 ,271 ,699 ,271 ,707 ,274 ,703 ,294 ,687 ,295 ,675 ,294 ,666 ,292};
	int jetengine1[14] = {772, 205, 778, 207, 780, 211, 779, 216, 774, 217, 768, 215 ,769, 209 };
	int jetengine2[18] = {705, 272 ,695 ,277 ,693 ,283 ,695 ,289 ,702 ,294, 708, 292, 712 ,287 ,712, 278, 710 ,275 };
	int deck[24] = {922, 233 ,932 ,238 ,931 ,247 ,926 ,251, 918, 256 ,904 ,259 ,882 ,258 ,886 ,249 ,896, 250 ,908 ,249, 916, 244, 922, 241 };
	int angoai[22] = {466, 86, 472, 85, 485, 117, 484, 119, 483, 120, 480, 120, 476, 112, 462, 112, 458, 119, 454, 120, 452, 117};
	int atrong[6] = {468, 94, 473, 107, 464, 107};
	int bngoai[26] = {770, 139, 789, 139, 795, 142, 797, 145, 797, 150, 795, 153, 793, 155, 797 ,158 ,799 ,161 ,798, 166 ,796 ,170, 792 ,172, 770 ,173 };
	int btrong1[12] = {777, 144, 787, 144, 790, 146, 790, 150, 787, 153 ,777, 153 };
	int btrong2[12] = {777, 158, 789, 158, 791, 161, 791, 165 ,788 ,168 ,777 ,168 };
	int c[68] = {496, 147, 499, 148, 501, 145, 500, 143 ,498, 140, 494, 137, 490, 136, 481, 136, 476 ,138 ,473, 141, 470, 145, 469, 148, 469, 158, 471, 162, 474, 166, 478, 169 ,481, 170, 490, 170, 496 ,167 ,499 ,163 ,501, 160, 499, 156, 495, 157 ,493 ,160 ,491 ,164 ,488 ,165, 483, 165 ,480, 163 ,477, 158, 477, 148, 479, 144, 484, 140, 489, 140, 492, 143 };
	int e[24] = {612, 136, 638, 136, 638, 141, 620, 141, 620 ,150, 637, 150, 637 ,154, 620, 155, 620, 165, 639, 166, 639, 170, 612, 170};
	int h[24] = {507, 136, 515, 136, 515, 149, 530, 149, 529, 136, 537, 136, 537, 170 ,529 ,170 ,529 ,155, 515 ,155, 515, 170, 507, 170};
	int l[12] = {540, 86, 548, 85, 548, 115, 565, 115, 565 ,119 ,540 ,120 };
	int n[20] = {490, 86, 498, 86 ,512, 107, 513, 86, 520 ,86 ,520 ,120, 514 ,120 ,498 ,98 ,497 ,120 ,490 ,120 };
	int qngoai[40] = {388, 85, 399, 85, 404, 87, 407, 90 ,410, 93 ,411 ,98 ,411 ,108 ,409 ,112, 407 ,115 ,413 ,119 ,410 ,123 ,402, 118 ,399 ,120 ,389 ,120, 384 ,117 ,379 ,113 ,377, 108 ,377 ,97 ,380 ,92, 383, 88 };
	int qtrong[28] = {392, 90, 397 ,90 ,399 ,92 ,403 ,97 ,403, 107, 401 ,111 ,394 ,108 ,391, 110 ,398, 114, 392 ,115 ,387, 112, 385, 107, 385, 98 ,387, 94 };
	int u[36] = {417, 85, 425, 85, 425, 108, 426, 113, 429 ,115, 435 ,115 ,438 ,113 ,439 ,110 ,439 ,85 ,447 ,85 ,447 ,112 ,444, 116 ,442, 117 ,438 ,120 ,427 ,120 ,423 ,118 ,420 ,115 ,417 ,112};
	int yy[22] = {570 ,85 ,573 ,85 ,582 ,99 ,591, 85 ,595 ,85 ,597, 88 ,586, 104, 586, 120 ,578 ,120, 578, 104 ,567, 88 };
	int window1[2] = {844, 250};
	int window2[2] = {806 ,247};
	int window3[2] = {760 ,243};
	int window4[2] = {714 ,238};
	int window5[2] = {666 ,231};
	int tamellip1[2]={490, 410};
	int tamellip2[2]={tamellip1[0]+460, tamellip1[1]};
	int tamellip3[2]={tamellip1[0], tamellip1[1]+100};
	int tamellip4[2]={tamellip2[0], tamellip2[1]+100};
	int tamellip5[2]={tamellip3[0], tamellip3[1]+100};
	int tamellip6[2]={tamellip4[0], tamellip4[1]+100};
	int tamellip[12]={tamellip1[0], tamellip1[1], tamellip2[0], tamellip2[1], tamellip3[0], tamellip3[1], tamellip4[0], tamellip4[1], tamellip5[0], tamellip5[1], tamellip6[0], tamellip6[1]};
	int dorongellip = 140;
	int docaoellip = 30;
	
void printworda(int x, int y){
	int chenhx = angoai[0] - x, chenhy = angoai[1] - y;
	if(chenhx !=0 && chenhy != 0){
		for(int i=0; i< 22; i++){
			if(i % 2 == 0) {
				if(i<6) atrong[i] = atrong[i] - chenhx;
				angoai[i] = angoai[i] - chenhx;
			}
			else{
				if(i<6) atrong[i] = atrong[i] - chenhy;
				angoai[i] = angoai[i] - chenhy;
			}
		}
	}
	setfillstyle(11, 2);
    fillpoly(11, angoai);
    setfillstyle(11, 0);
    fillpoly(3, atrong);
    return;
}

void printwordb(){
	
	setfillstyle(11, 2);
    fillpoly(13, bngoai);
    setfillstyle(11, 0);
    fillpoly(6, btrong1);
    fillpoly(6, btrong2);
    return;
}

void printwordc(){
	
	setfillstyle(11, 2);
    fillpoly(34, c);
}

void printworde(){
	
	setfillstyle(11, 2);
    fillpoly(12, e);
}

void printwordh(){
	
	setfillstyle(11, 2);
    fillpoly(12, h);
}

void printwordl(){
	
	setfillstyle(11, 2);
    fillpoly(6, l);
}

void printwordn(int x, int y){
	int chenhx = n[0] - x, chenhy = n[1] - y;
	if(chenhx !=0 && chenhy != 0){
		for(int i=0; i< 22; i++){
			if(i % 2 == 0) {
				n[i] = n[i] - chenhx;
			}
			else{
				n[i] = n[i] - chenhy;
			}
		}
	}
	setfillstyle(11, 2);
    fillpoly(10, n);
    return;
}

void printwordq(){	
	setfillstyle(11, 2);
    fillpoly(20, qngoai);
    setfillstyle(11, 0);
    fillpoly(14, qtrong);
    return;
}

void printwordu(int x, int y){
	
	int chenhx = u[0] - x, chenhy = u[1] - y;
	if(chenhx !=0 && chenhy != 0){
		for(int i=0; i< 36; i++){
			if(i % 2 == 0) {
				u[i] = u[i] - chenhx;
			}
			else{
				u[i] = u[i] - chenhy;
			}
		}
	}
	setfillstyle(11, 2);
    fillpoly(18, u);
    return;
}

void printwordy(int x, int y){
	
	int chenhx = yy[0] - x, chenhy = yy[1] - y;
	if(chenhx !=0 && chenhy != 0){
		for(int i=0; i< 22; i++){
			if(i % 2 == 0) {
				yy[i] = yy[i] - chenhx;
			}
			else{
				yy[i] = yy[i] - chenhy;
			}
		}
	}
	setfillstyle(11, 2);
    fillpoly(11, yy);
    return;
}

void printword(){
	printworda(466, 86 );
    printworda(817, 138 );
    printwordb();
    printwordc();
    printworde();
    printwordh();
    printwordl();
    printwordn(645, 136);
    printwordn(490, 86);
    printwordq();
    printwordu(544, 136);
    printwordu(417, 85);
    printwordy(581,136);
    printwordy(570, 85);
    printwordy(841, 138);
    return;
}

void drawellipplane(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 2;
		chu = 15;
	}
	
	setfillstyle(1, nen);
	fillellipse (tamellip1[0], tamellip1[1], dorongellip, docaoellip);
	xuatkytu(tamellip1[0]- dorongellip, tamellip1[1]-docaoellip, tamellip1[0]+ dorongellip, tamellip1[1] + docaoellip, "May bay", 9, 3, chu, nen);
	return;
}

void drawellipflight(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 2;
		chu = 15;
	}
	
	setfillstyle(1, nen);
	fillellipse (tamellip2[0], tamellip2[1], dorongellip, docaoellip);
	xuatkytu(tamellip2[0]- dorongellip, tamellip2[1]-docaoellip, tamellip2[0]+ dorongellip, tamellip2[1] + docaoellip, "Chuyen bay", 9, 3, chu, nen);
	return;
}

void drawellippassenger(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 2;
		chu = 15;
	}
	
	setfillstyle(1, nen);
	fillellipse (tamellip3[0], tamellip3[1], dorongellip, docaoellip);
	xuatkytu(tamellip3[0]- dorongellip, tamellip3[1]-docaoellip, tamellip3[0]+ dorongellip, tamellip3[1] + docaoellip, "Hanh khach", 9, 3, chu, nen);
	return;
}

void drawellipbook(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 2;
		chu = 15;
	}
	
	char msg[10];
	setfillstyle(1, nen);
	fillellipse (tamellip4[0], tamellip4[1], dorongellip, docaoellip);
	xuatkytu(tamellip4[0]- dorongellip, tamellip4[1]-docaoellip, tamellip4[0]+ dorongellip, tamellip4[1] + docaoellip, "Dat ve", 9, 3, chu, nen);
	return;
}

void drawellipsave(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 2;
		chu = 15;
	}
	
	char msg[10];
	setfillstyle(1, nen);
	fillellipse (tamellip5[0], tamellip5[1], dorongellip, docaoellip);
	xuatkytu(tamellip5[0]- dorongellip, tamellip5[1]-docaoellip, tamellip5[0]+ dorongellip, tamellip5[1] + docaoellip, "Luu", 9, 3, chu, nen);
	return;
}

void drawellipout(int i){
	int nen = 7, chu = 6;
	if(i == 1) {
		nen = 12;
		chu = 15;
	}
	
	char msg[10];
	setfillstyle(1, nen);
	fillellipse (tamellip6[0], tamellip6[1], dorongellip, docaoellip);
	xuatkytu(tamellip6[0]- dorongellip, tamellip6[1]-docaoellip, tamellip6[0]+ dorongellip, tamellip6[1] + docaoellip, "Thoat", 9, 3, chu, nen);
	return;
}

void printwindow(int x, int y){
	int wd[8] = {844, 250, 851, 250, 851, 256, 844, 256};
	int chenhx = wd[0] - x, chenhy = wd[1] - y;
	if(chenhx !=0 && chenhy != 0){
		for(int i=0; i< 8; i++){
			if(i % 2 == 0) {
				wd[i] = wd[i] - chenhx;
			}
			else{
				wd[i] = wd[i] - chenhy;
			}
		}
	}
	setfillstyle(1, 7);
    fillpoly(4, wd);
    return;
}
};

drawinmain dim;

void menu(){
	setbkcolor(BLACK);
	cleardevice();
	setlinestyle(0, 1, 1);
	setfillstyle(11, 3);
	fillpoly(40, dim.cloud1);
	fillpoly(36, dim.cloud2);
	fillpoly(34, dim.cloud3);
      
    setfillstyle(1, 7);
    fillpoly(10, dim.star1);
    
    setfillstyle(1, 15);
    fillpoly(10, dim.star2);
      
    setfillstyle(1, 14);
    fillpoly(10, dim.star3);
    fillpoly(10, dim.star4);
    fillpoly(10, dim.star5);
      
    setfillstyle(11, 1);
    fillpoly(4, dim.cowling1);
    fillpoly(8, dim.cowling2);
    fillpoly(25, dim.bodyplane);
      
    setfillstyle(11, 8);
    fillpoly(7, dim.jetengine1);
    fillpoly(9, dim.jetengine2);
      
    setfillstyle(11, 9);
    fillpoly(4, dim.wing1);
    fillpoly(6, dim.wing2);
    fillpoly(4, dim.tailplane1);
    fillpoly(5, dim.tailplane2);
      
    setfillstyle(1, 7);
    fillpoly(12, dim.deck);
    
    dim.printwindow(dim.window1[0], dim.window1[1]);
    dim.printwindow(dim.window2[0], dim.window2[1]);
    dim.printwindow(dim.window3[0], dim.window3[1]);
    dim.printwindow(dim.window4[0], dim.window4[1]);
    dim.printwindow(dim.window5[0], dim.window5[1]);
    
    dim.printword();
    
    int present =0 ;
    int x, y, thutu = 0;
	dim.drawellipplane(present);
	dim.drawellippassenger(present);
	dim.drawellipflight(present);
	dim.drawellipbook(present);
	dim.drawellipout(present);
	dim.drawellipsave(present);
	
	while(1){
		x = mousex();
		y = mousey();
		if(getpixel(x,y) == LIGHTGRAY && y>((dim.tamellip1[1]-dim.docaoellip))){
			if(x>(dim.tamellip1[0]- dim.dorongellip)&&x<(dim.tamellip1[0]+ dim.dorongellip) && y>(dim.tamellip1[1]-dim.docaoellip) && y<(dim.tamellip1[1] + dim.docaoellip)){
				dim.drawellipplane(1);
				if(chonhanellip(dim.tamellip1[0]- dim.dorongellip, dim.tamellip1[1]-dim.docaoellip, dim.tamellip1[0]+ dim.dorongellip, dim.tamellip1[1] + dim.docaoellip)) windowtool(APL);
				else dim.drawellipplane(0);
			}
			if(x>(dim.tamellip2[0]- dim.dorongellip)&&x<(dim.tamellip2[0]+ dim.dorongellip) && y>(dim.tamellip2[1]-dim.docaoellip) && y<(dim.tamellip2[1] + dim.docaoellip)){
				dim.drawellipflight(1);
				if(chonhanellip(dim.tamellip2[0]- dim.dorongellip, dim.tamellip2[1]-dim.docaoellip, dim.tamellip2[0]+ dim.dorongellip, dim.tamellip2[1] + dim.docaoellip)) windowtool(FL);
				else dim.drawellipflight(0);
			}
			if(x>(dim.tamellip3[0]- dim.dorongellip)&&x<(dim.tamellip3[0]+ dim.dorongellip) && y>(dim.tamellip3[1]-dim.docaoellip) && y<(dim.tamellip3[1] + dim.docaoellip)){
				dim.drawellippassenger(1);
				if(chonhanellip(dim.tamellip3[0]- dim.dorongellip, dim.tamellip3[1]-dim.docaoellip, dim.tamellip3[0]+ dim.dorongellip, dim.tamellip3[1] + dim.docaoellip)) windowtool(PSG);
				else dim.drawellippassenger(0);
			}
			if(x>(dim.tamellip4[0]- dim.dorongellip)&&x<(dim.tamellip4[0]+ dim.dorongellip) && y>(dim.tamellip4[1]-dim.docaoellip) && y<(dim.tamellip4[1] + dim.docaoellip)){
				dim.drawellipbook(1);
				if(chonhanellip(dim.tamellip4[0]- dim.dorongellip, dim.tamellip4[1]-dim.docaoellip, dim.tamellip4[0]+ dim.dorongellip, dim.tamellip4[1] + dim.docaoellip)) windowtool(BK);
				else dim.drawellipbook(0);
			}
			if(x>(dim.tamellip5[0]- dim.dorongellip)&&x<(dim.tamellip5[0]+ dim.dorongellip) && y>(dim.tamellip5[1]-dim.docaoellip) && y<(dim.tamellip5[1] + dim.docaoellip)){
				dim.drawellipsave(1);
				if(chonhanellip(dim.tamellip5[0]- dim.dorongellip, dim.tamellip5[1]-dim.docaoellip, dim.tamellip5[0]+ dim.dorongellip, dim.tamellip5[1] + dim.docaoellip)) {
					luufile();
					baoluu(1);
					menu();
				}
				else dim.drawellipsave(0);
			}
			if(x>(dim.tamellip6[0]- dim.dorongellip)&&x<(dim.tamellip6[0]+ dim.dorongellip) && y>(dim.tamellip6[1]-dim.docaoellip) && y<(dim.tamellip6[1] + dim.docaoellip)){
				dim.drawellipout(1);
				if(chonhanellip(dim.tamellip6[0]- dim.dorongellip, dim.tamellip6[1]-dim.docaoellip, dim.tamellip6[0]+ dim.dorongellip, dim.tamellip6[1] + dim.docaoellip)){
					if(hoi(1)) {
						xoatoanbo();
						exit(1);
					}
					else menu();
				}
				else dim.drawellipout(0);
			}
		}
		delay(1);
	}
}
