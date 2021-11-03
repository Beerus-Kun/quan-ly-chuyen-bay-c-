Tree FindPassenger(Tree &t, char idPassenger[]);
struct SeachCharacterFlight{
	int n;
	NF *ds = new NF[300]; 
	SeachCharacterFlight(){
		n = 0;
	}
	~SeachCharacterFlight(){
		delete[] ds;
	}
	void clear(){
		n = 0;
	}
};
typedef struct SeachCharacterFlight SCF;
SCF sfl;

void InIt(NF &l) {
 	l = NULL;
}
bool IsEmpty(NF &l) {
 	if (l == NULL) return true;
 	return false;
}
int Quantity(NF &l) {
	int dem = 0;
 	for(NF M = l; M != NULL; M = M->Next){
 		 dem++;
 	}
 	return dem;
}
NF AddNode(FLIGHT &f) {
	 NF p = (NF)malloc(sizeof(NodeFlight));
	 p->Data = f;
	 p->Next = NULL;
	 return p;
}
void InsertHead(NF &l, FLIGHT &f) {
 	NF p = AddNode(f);
 	if (IsEmpty(l)) l = p;
 	else {
  		p->Next = l;
  		l = p;
 	}
}

void InsertTail(NF &l, FLIGHT &f) {
  	NF p = AddNode(f);
  	if (IsEmpty(l)) l = p;
 	else {
  		NF M = l;
  		while (M->Next != NULL) {
   		M = M->Next;
  		}
  		M->Next = p;
  		p->Next = NULL;
 	}
}
void DeleteHead(NF &l) {
 	l = l->Next;
}
void DeleteTail(NF &l) {
 	NF M = l;
 	while (M->Next->Next != NULL) {
  		M = M->Next;
 	}
 	M->Next = M->Next = NULL;
}
//bool ClearListFlight(NF &l)
//{
//	if(l == NULL) return false;
//	NF temp;
//	while (l != NULL)
//	{
//		temp = l;
//		l = l->Next;
//		delete temp;
//	}
//	return true;
//}
int TrungMaCB(NF &l, char id[]){
	if(l == NULL) return 0;
	else {
		for(NF p = l; p != NULL; p=p->Next){
			if (strcmp(p->Data.MaCB, id) == 0)
				return 1;
		}
	}
	return 0;
}
NF Seach(NF &l, char id[]){
	if(l == NULL) return NULL;
	else { 
		for(NF p = l; p != NULL; p=p->Next){
			if (strcmp(p->Data.MaCB, id) == 0){
//				for(int i=0; i<P->Data.ticket.totalticket; i++) cout << P->Data.ticket.List[i].stt << ", ";
				return p;
			}
		}
	}
	return NULL;
}
bool TrungDate(NF &l, FLIGHT &f){
	NF p;
   	p = AddNode(f);
	if(l == NULL) return false;
	else {
		for(p = l; p != NULL; p=p->Next){
			if (CompareDate(p->Data.dt, f.dt) == true)
				return true;
		}
	}
	return false;
}
bool a(NF &l, NF &k){
//	NF p;
//   	p = AddNode(f);
	if(l == NULL) return false;
	else {
		for(NF p = l; p != NULL; p=p->Next){
			if (CompareDate(p->Data.dt, k->Data.dt) == true)
				return true;
		}
	}
	return false;
}

void UpdateFlightOfPassenger(Tree &root, char *idowner, char *idfl){
	Tree ps;
	ps = FindPassenger(root, idowner);
	ps->key.count--;
	for(int j = 0; j < ps->key.count; j++){
		if(strcmp(ps->key.MaFlight[j], idfl) == 0){
			for(int k=j; k < ps->key.count; k++)
				strcpy(ps->key.MaFlight[k], ps->key.MaFlight[k+1]);
			break;
		}
	}
}

void ChangettFlight(NF &l, Tree &root)
{	
	int j = 0;
	for (NF p = l ; p != NULL; p = p->Next)
		if (!DateTimeValue(p->Data.dt) && p->Data.tt != huy_chuyen && p->Data.tt != hoan_tat){
			p->Data.tt = hoan_tat;
			for(int i=0; i<p->Data.Ticket->nTicketTotal && j<p->Data.Ticket->nTicketSold; i++){
				if(p->Data.Ticket->List[i].stt!=-1){
					j++;
					UpdateFlightOfPassenger(root, p->Data.Ticket->List[i].idOwner, p->Data.MaCB);
				}
			}
			
		}
}
void AutoChangeTtTicket(NF &l){
	if((l->Data.Ticket->nTicketTotal - l->Data.Ticket->nTicketSold) == 0){
		l->Data.tt = het_ve;
	}
}
void AutoChangeTTTicket(NF &l){
	if((l->Data.Ticket->nTicketTotal - l->Data.Ticket->nTicketSold) != 0){
		l->Data.tt = con_ve;
	}
}
NF FindFlight(NF &l, char *MaCB)
{
	if (l == NULL) return NULL;
	for (NF p = l; p != NULL; p = p->Next)
		if (strcmp(p->Data.MaCB, MaCB) == 0)
			return p;
	return NULL;
}
//string mess;
bool SeachAirplane(NF &l, char *SoHMB){
	if(l == NULL) return false;
	else { 
		for(NF p = l; p != NULL; p=p->Next){
			if (strcmp(p->Data.SoHieuMB, SoHMB) == 0)
				return true;
		}
	}
	return false;
}


//bool timAirplane(NF &l, char *id){
////	Node* p = AddNode(f);
//	if(l == NULL) return false;
//	else{
//		for(NF p = l; p != NULL; p=p->Next){
//		if(strcmp(l->Data.SoHieuMB, id) == 0) 
//			return true;
//		}
//	}
//	return false;
//}

//bool TrungSBD(LinkList& l, char *sbd){
//	if(l == NULL) return false;
//	else{
//		for(Node* p = l; p!=NULL; p=p->Next){
//		if(strcmp(l->Data.SanBD, sbd) == 0) 
//			return true;
//		}
//	}
//}
string messs;

bool ChangeTT(NF &L, FLIGHT &f, LIST_AIRPLANE &l){
//	int count = 0;
//	for(NF p = L; p != NULL; p=p->Next){
//		if(L->Data.tt == huy_chuyen || L->Data.tt == hoan_tat)
//		count++;
//	}
//	if(count == Quantity(L)){
//		mess == "Khong co chuyen bay nao hieu chinh duoc";
//		return false;
//	}
//	NF p = AddNode(f);
//	p = FindFlight(L, f.MaCB);
//	if(p->Data.tt == huy_chuyen || p->Data.tt == hoan_tat){
//		mess = "Chuyen bay nay da bi huy hoac da hoan tat khong the xoa";
//		return false;
//	}
//	mess = "Ban co that su muon thay doi trang thai khong";
	NF p = FindFlight(L, f.MaCB);
	int i = FindIndexAirplane(l, f.SoHieuMB);
	p->Data.tt = huy_chuyen;
	l.List[i]->Turn--;
	return true;
}
//sap xep theo MaCB
bool SelectionSortId(NF &l){
	NF p, q, pmin;
	FLIGHT min;
	if(l == NULL){
		mess = "Khong the sap xep";
		return false;
	} 
	for(p = l; p->Next != NULL; p=p->Next){
		min = p->Data;
		pmin = p;
		for(q = p->Next; q != NULL; q=q->Next){
			if(strcmp(min.MaCB, q->Data.MaCB) > 0){
				min = q->Data;
				pmin = q;
			}
		}
		pmin->Data = p->Data;
		p->Data = min;
	}
	mess = "Sap xep thanh cong";
	return true;
}
//sap xep theo ngay gioi khoi hanh 
//neu ngay thang nam bang nhau thi sap xep theo MaCB
bool SelectionSortDate(NF &l){
	NF p, q, pmin;
	FLIGHT min;
	if(l == NULL){
		mess = "Khong the sap xep";
		return false;
	} 
	for(p = l; p->Next != NULL; p=p->Next){
		min = p->Data;
		pmin = p;
		for(q = p->Next; q != NULL; q=q->Next){
//			if((min.dt.y == q->Data.dt.y) && (min.dt.m == q->Data.dt.m) && (min.dt.d == q->Data.dt.d) && (min.dt.h == q->Data.dt.h) && (min.dt.mi == q->Data.dt.mi)){
//				SelectionSortId(l);
////				return true;	
//			}
			if(((min.dt.y == q->Data.dt.y) && (min.dt.m == q->Data.dt.m) && (min.dt.d == q->Data.dt.d) && (min.dt.h == q->Data.dt.h) && (min.dt.mi == q->Data.dt.mi) && strcmp(min.MaCB, q->Data.MaCB) > 0)
			|| (min.dt.y > q->Data.dt.y) || ((min.dt.y == q->Data.dt.y) && (min.dt.m > q->Data.dt.m)) || 
			((min.dt.y == q->Data.dt.y) && (min.dt.m == q->Data.dt.m) && (min.dt.d > q->Data.dt.d)) ||   
			((min.dt.y == q->Data.dt.y) && (min.dt.m == q->Data.dt.m) && (min.dt.d == q->Data.dt.d) && (min.dt.h > q->Data.dt.h)) ||
			((min.dt.y == q->Data.dt.y) && (min.dt.m == q->Data.dt.m) && (min.dt.d == q->Data.dt.d) && (min.dt.h == q->Data.dt.h) && (min.dt.mi > q->Data.dt.mi))
			){
				min = q->Data;
				pmin = q;
			}
		}
		pmin->Data = p->Data;
		p->Data = min;
	}
	mess = "Sap xep thanh cong";
	return true;
}
bool CorrestionDate(NF &l, FLIGHT &f){
	int count = 0;
	for(NF p = l; p != NULL; p=p->Next){
		if(l->Data.tt == huy_chuyen || l->Data.tt == hoan_tat)
		count++;
	}
	if(count == Quantity(l)){
		mess == "Khong co chuyen bay nao hieu chinh duoc";
		return false;
	}
	NF p = AddNode(f);
//	do{
//		mess = "Nhap ma chuyen bay muon hieu chinh";
//		p = FindFlight(l, f.MaCB);
//		if(p == NULL){
//			mess = "Khong tim thay ma chuyen bay";
//			return false;
//		}
//		if(l->Data.tt == huy_chuyen || l->Data.tt == hoan_tat){
//			mess = "Chuyen bay nay da bi huy hoac da hoan tat khong the xoa";
//			return false;
//		}
//		
//	}while(l->Data.tt == huy_chuyen || l->Data.tt == hoan_tat);
	p = FindFlight(l, f.MaCB);
//		if(p == NULL){
//			mess = "Khong tim thay ma chuyen bay";
//			return false;
//		}
	if(l->Data.tt == huy_chuyen || l->Data.tt == hoan_tat){
		mess = "Chuyen bay nay da bi huy hoac da hoan tat khong thay doi";
		return false;
	}
	if(SeachAirplane(l, f.SoHieuMB) == true && TrungDate(l , f) == true){
//		messs = "khong the vua trung SoHieuMB vua trung thoi gian duoc";
		return false;
	}
	p->Data.dt.h = f.dt.h;
	p->Data.dt.mi = f.dt.mi;
	p->Data.dt.d = f.dt.d;
	p->Data.dt.m = f.dt.m;
	p->Data.dt.y = f.dt.y;
	SelectionSortDate(l);
	return true;
}
bool InsertFlight(NF &L, FLIGHT &f, LIST_AIRPLANE &l){
	int i = FindIndexAirplane(l, f.SoHieuMB);
	for(NF k = L; k != NULL; k = k->Next){
		if(SeachAirplane(k, f.SoHieuMB) == true && CompareDate(k->Data.dt , f.dt) == true){
		messs = "khong the vua trung SoHieuMB vua trung thoi gian duoc";
		return false;
		}
	}
	if(i == -1){
		messs = "So hieu may bay phai co trong danh sach may bay";
		return false;
	}
	l.List[i]->Turn++;
	InsertHead(L, f);
	SelectionSortDate(L);
	soluongchuyenbay++;
	return true;
}

bool BuyTicket(Tree &root, NF &l, char CMND[], char Macb[], int n) {
	NF cb = Seach(l, Macb);
	Tree t = FindPassenger(root, CMND);

	if(cb->Data.tt == hoan_tat || cb->Data.tt == het_ve){
		return false;
	}
	for(int i = 0; i < t->key.count; i++){
		NF cbb = Seach(l, t->key.MaFlight[i]);
		if(t->key.count != 0 && CompareDate(cb->Data.dt, cbb->Data.dt) == true){
			return false;
		}
	}
	for (int i = 0; i < cb->Data.Ticket->nTicketTotal; i++) {
		if (strcmp(CMND, cb->Data.Ticket->List[i].idOwner) == 0){
				mess = "Moi hanh khach chi mua duoc 1 ve";
				return false;
			}
	}
	if(cb->Data.Ticket->List[n-1].stt != -1){
		mess = "Ghe nay da co chu";
		return false;
	}
	if(n <= cb->Data.Ticket->nTicketTotal + 1){
		t->key.booktimes++;
		cb->Data.Ticket->List[n-1].stt = n;
		strcpy(cb->Data.Ticket->List[n-1].idOwner, CMND);
		cb->Data.Ticket->nTicketSold++;
		strcpy(t->key.MaFlight[t->key.count], cb->Data.MaCB);
		t->key.count++;
		AutoChangeTtTicket(cb);
		return true;
	}
	return false;
}
int FindIndexTicket(NF &l ,char CMND[])
{
	if (l->Data.Ticket->nTicketTotal <= 0) return -1;
	for (int i = 0; i < l->Data.Ticket->nTicketTotal; i++){
		if (strcmp(CMND, l->Data.Ticket->List[i].idOwner) == 0) return i;
	}
	return -1;
}
int CountFlightReady(NF &nodefl, NF &nodebk){
	int count = 0;
	NF q = nodebk;
	for(NF p = nodefl; p != NULL; p=p->Next){
		if(p->Data.tt == con_ve){
			count++;
			q->Data.dt.d = p->Data.dt.d; q->Data.dt.m = p->Data.dt.m; q->Data.dt.mi = p->Data.dt.mi;
			q->Data.dt.h = p->Data.dt.h; q->Data.dt.y = p->Data.dt.y;
			strcpy(q->Data.MaCB, p->Data.MaCB);
			strcpy(q->Data.SanBD, p->Data.SanBD);
			q->Data.Ticket = p->Data.Ticket;
			if(q->Next == NULL){
				NF a = new NodeFlight;
				q->Next = a;
				a->Next = NULL;
			}
			q = q->Next;
		} 
	}
	return count;
}
bool CancelTicket(NF &l , Tree &root, char CMND[], char *Macb){
	NF cb = Seach(l, Macb);
	if(cb->Data.tt == hoan_tat){
		return false;
	}
	UpdateFlightOfPassenger(root, CMND, Macb);
	Tree ps = FindPassenger(root, CMND);
	ps->key.booktimes--;
	int i = FindIndexTicket(cb, CMND);
	if(i != -1){
		cb->Data.Ticket->List[i].stt = -1;
		strcpy(cb->Data.Ticket->List[i].idOwner, "");
		cb->Data.Ticket->nTicketSold--;
		AutoChangeTTTicket(cb);
		return true;
	}		
	return false;
}
void FindCharacterMCB(NF &l, SCF &k, char *id){
	for(NF p = l; p != NULL; p = p->Next){
		if(strncmp(p->Data.MaCB, id, strlen(id)) == 0){
				k.ds[k.n++] = p;
		}
	}	
}
void FindCharacterSBD(NF &l, SCF &k, char *id){
	for(NF p = l; p != NULL; p = p->Next){
		if(strncmp(p->Data.SanBD, id, strlen(id)) == 0){
				k.ds[k.n++] = p;
		}
	}	
}
void FindCharacterDate(NF &l, SCF &k, DATETIME &time){
	for(NF p = l; p != NULL; p = p->Next){
		if(p->Data.dt.d == time.d && p->Data.dt.m == time.m && p->Data.dt.y == time.y){
			k.ds[k.n++] = p;
		}
	}
}
void FindCharacterDateAndPlace(NF &l, SCF &k, DATETIME &time, char *id){
	for(NF p = l; p != NULL; p = p->Next){
		if(strncmp(p->Data.SanBD, id, strlen(id)) == 0 && p->Data.dt.d == time.d && p->Data.dt.m == time.m && p->Data.dt.y == time.y){
				k.ds[k.n++] = p;
		}
	}
}
void SaveFlight(NF &l){
	fstream f;
	f.open("dschuyenbay.txt", ios::out);
	f << Quantity(l) << endl;
	if(Quantity(l) != 0){
		for (NF tam = l; tam != NULL; tam = tam->Next) {
			f << tam->Data.MaCB << endl;
			f << tam->Data.SoHieuMB << endl;
			f << tam->Data.SanBD << endl;
			f << tam->Data.dt.d << " ";
			f << tam->Data.dt.m << " ";
			f << tam->Data.dt.y << " ";
			f << tam->Data.dt.h << " ";
			f << tam->Data.dt.mi << endl;
			f << tam->Data.tt << endl;
			f << tam->Data.Ticket->nTicketTotal << endl;
			f << tam->Data.Ticket->nTicketSold << endl;
			for(int i = 0; i < tam->Data.Ticket->nTicketTotal; i++){
				if(tam->Data.Ticket->List[i].stt != -1){
					f << i+1 << endl;
					f << tam->Data.Ticket->List[i].idOwner << endl;
				}
				
			}
		}
	}
	mess = "Save thanh cong";
	f.close();
}
void Clearlist(NF &First)
{  
   NF p;  
  while(First != NULL)
   {
      p = First;
      First = First->Next;
      delete p;
   }
}

void LoadFlight(NF &l){
	int n;
	int tt;
	int vitri; 
	char CMND[15];
	FLIGHT t;
	int soluong;
	int soluongveban;
	fstream file("dschuyenbay.txt", ios::in);
	file >> n;
	file.ignore();
	for(int i = 0; i < n; i++){
		file.getline(t.MaCB, MACBMAX);
		file.getline(t.SoHieuMB, SHMBMAX);
		file.getline(t.SanBD, SBDMAX);
		file >> t.dt.d;
		file >> t.dt.m;
		file >> t.dt.y;
		file >> t.dt.h;
		file >> t.dt.mi;
		file >> tt;
		file >> soluong;
		file >> soluongveban;
		LI_TI *ve = new LI_TI(soluong);
		t.Ticket = ve;
		ve->nTicketTotal = soluong;
		ve->nTicketSold = soluongveban;
		if(soluongveban == 0) file.ignore();
		for(int j = 0; j < soluongveban; j++){
			file >> vitri;
			file.ignore();
			file.getline(CMND, 15); 
			ve->List[vitri-1].stt = vitri;
			strcpy(ve->List[vitri-1].idOwner, CMND);
		}
		if(tt == 1) t.tt = con_ve;
		else if(tt == 0) t.tt = huy_chuyen;
		else if(tt == 2) t.tt = het_ve;
		else t.tt = hoan_tat;
		InsertHead(l, t);
	}
	mess = "Load thanh cong";	
	SelectionSortDate(l);
	file.close();
}
void ClearListFlight(NF &First)
{  
   	NF p;  
  	while(First != NULL){
      	p = First;
      	First = First->Next;
      	delete p;
   	}
}
