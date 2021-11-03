//struct List_Ticket{
//	Ticket *List;
//  int nTicketSold;
//  	int totalticket;
//  	List_Ticket(int size){
//	  	totalticket = size;
//		nTicketSold = 0;
//  		List = new Ticket[size];
//  	}
//  	List_Ticket(){
//	  }
////  	~List_Ticket(){
////  		delete[] List;
////	  }
//};
//typedef struct List_Ticket LI_TI;
//string mess;
//void TicketBooking(Tree &L, p &key, NF &nodefl, char MCB[], int n){
//	mess = "Nhap CMND";
//	// neu CMND nay chua co trong danh sach thi yeu cau nhap vao
//	if(CheckIdIsExisted(L, key.id) == false){
////		mess = "Nhap thong tin hanh khach ";
//		
//	}
//	mess = "Chon MaCB";
//	BuyTicket(nodefl, key.id, MCB, n);
//
//}
//bool CancelTicketBooking(Tree &L, p &key, char CMND[], char MCB[]){
//	if(CheckIdIsExisted(L, CMND) == false){
//		mess = "Hanh khach chua dat ve";
//		return false;
//	}
//	CancelTicket(nodefl, CMND, MCB);
//	return true;
//}

void docfile(){
	LoadAirplane(lapl);
	LoadPassenger(root);
	soluonghanhkhach = count(root);
	LoadFlight(nodefl);
	ChangettFlight(nodefl, root);
	soluongchuyenbay = Quantity(nodefl);
	CountFlightReady(nodefl, nodebk);
}
void luufile(){
	SaveFlight(nodefl);
	SavePassenger(root);
	SaveAirplane(lapl);
}
void xoatoanbo(){
	ClearListPassenger(root);
	ClearListFlight(nodefl);
	ClearListFlight(nodebk);
}
