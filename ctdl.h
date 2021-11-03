struct Airplane{
	char IdMB[MAXIDMB+1];
	char Type[MAXTYPE+1];
	int Chair;
	int Turn;
	Airplane(){
		Turn = 0;
	}
};
typedef struct Airplane AIRPLANE;
typedef struct Airplane* PTR_AIRPLANE;

struct List_Airplane{
	int sl;
 	AIRPLANE *List[MAXLISTAIRPLANE];
 	List_Airplane(){
 		sl = 0;
	 }
	 ~List_Airplane(){
		while (sl > 0){
 	   		delete List[sl-1];
       		sl--;
		}
	}
};
typedef struct List_Airplane LIST_AIRPLANE;

PTR_AIRPLANE apl = new AIRPLANE;
LIST_AIRPLANE lapl;

struct DateTime
{
	int y, m, d, h, mi;
	DateTime(){
		y = 0;
		m = 0;
		d = 0;
		h = 0;
		mi = 0;
	}
};
typedef struct DateTime DATETIME;
DateTime dtime;


struct Ticket{  
	int stt;   //la so ghe ban chon	
	char idOwner[30];   //chua co khach hang dat ve
	Ticket(){
		stt = -1;
	}
};
Ticket tk;
typedef struct Ticket TI;
struct List_Ticket{
	Ticket *List;
  	int nTicketSold;
  	int nTicketTotal;
  	List_Ticket(int size){
	  	nTicketTotal = size;
		nTicketSold = 0;
  		List = new Ticket[size];
  	}
  	List_Ticket(){
	}
  	~List_Ticket(){
  		delete[] List;
	  }
};
typedef struct List_Ticket LI_TI;
LI_TI tic;

enum TrangThai{huy_chuyen = 0, con_ve = 1, het_ve = 2, hoan_tat = 3 };
struct FLIGHT{
 	char MaCB[MACBMAX+1];
	char SanBD[SBDMAX+1];
	DATETIME dt;
	TrangThai tt;
	char SoHieuMB[SHMBMAX+1];
	LI_TI *Ticket;
	FLIGHT(char *MCB, char *SBD, DATETIME d, TrangThai t, char *SHMB, LI_TI *Tic){
		strcpy(MaCB, MCB);
		strcpy(SanBD, SBD);
		dt = d;
		tt = t;
		strcpy(SoHieuMB, SHMB);
		Ticket = Tic;
	}
	FLIGHT(){
	}
};
typedef struct FLIGHT F;
struct NodeFlight{
 	FLIGHT Data;
 	NodeFlight* Next;
};
typedef struct NodeFlight* NF;

NF nodefl;
FLIGHT fl;
NF nodebk = new NodeFlight;
int vitrighe;

struct Passenger
{
	char id[CMNDMAX+1];
	char firstName[FIRSTNAME+1], lastName[LASTNAME+1];
	char MaFlight[20][CMNDMAX+1];
	int booktimes = 0;
	int count = 0;
	int  sex;
};
typedef struct Passenger p;

p psg;
int soluonghanhkhach = 0;
int soluongchuyenbay = 0;

struct NodePassenger
{
	Passenger key;
	NodePassenger* left;
	NodePassenger* right;
	int height;
};
typedef NodePassenger* Tree;
Tree root = NULL;
