//struct Airplane{
//	char IdMB[MAXIDMB];
//	char Type[MAXTYPE];
//	int Chair;
//};
//typedef struct Airplane AIRPLANE;
//typedef struct Airplane* PTR_AIRPLANE;
//
//struct List_Airplane{
//	int sl;
// 	AIRPLANE *List[MAXLISTAIRPLANE];
// 	List_Airplane(){
// 		sl = 0;
//	 }
//};
//typedef struct List_Airplane LIST_AIRPLANE;
//
//Airplane *apl = new Airplane;
//LIST_AIRPLANE lapl;

int FindIndexAirplane(LIST_AIRPLANE &l, char *id)
{
	if (l.sl < 0) return -1;
	for (int i = 0; i < l.sl; i++)
		if (strcmp(l.List[i]->IdMB, id) == 0) return i;
	return -1;
}
int Find(LIST_AIRPLANE &l, AIRPLANE *mb) {
  	for (int i =0; i < l.sl ; i++)
     	if (strcmp(mb->IdMB ,l.List[i]->IdMB) == 0)  return i;
  	return -1;
}
PTR_AIRPLANE FindAirplane(LIST_AIRPLANE &l, char *id)
{
	if (l.sl < 0) return NULL;
	for (int i = 0; i < l.sl; i++)
		if (strcmp(l.List[i]->IdMB, id) == 0) return l.List[i];
	return NULL;
}
void DeleteMemory(LIST_AIRPLANE &l){
	while(l.sl > 0){
		delete l.List[l.sl-1];
		l.sl--;
	}
}
string mess;
void SortByIdAirplain(LIST_AIRPLANE &l);
bool InsertAirplane(LIST_AIRPLANE &l, Airplane *mb){
//	Airplane *p = new Airplane;
//	strcpy(p->IdMB , mb->IdMB);
//	strcpy(p->Type , mb->Type);
//	p->Chair = mb.Chair;
//	p->Turn = mb.Turn;
//	if(l.sl >= MAXLISTAIRPLANE){
//		mess = "Danh sach MB da day !!!";
//		return false;
//	}
//	if(FindIndexAirplane(l, mb->IdMB) != -1){
//		mess = "So hieu may bay da co trong danh sach";
//		return false;
//	}
//	if(mb->Chair < 20){
//		mess = "So ghe >= 20";
//		return false;
//	}
	l.List[l.sl] = mb;
	l.sl++;
	mess = "Da luu vao danh sach";
	SortByIdAirplain(l);
	return true;
}
int tima[300];
int tim(LIST_AIRPLANE &l, char *id, int n){
	int index = 0;
	for(int i = 0; i < l.sl; i++){
		if(strncmp(l.List[i]->IdMB, id, strlen(id)) == 0 ){
				tima[index++] = i;
		}
	}
	return index;
}
//void xuata(int n){
//	for(int i=0; i<n; i++){
//		cout << tima[i] <<endl;
//	}
//}
//NF Search_Flight(NF &L, char id[]){
//	if(L == NULL) return NULL;
//	else { 
//		for(NF P = L; P != NULL; P=P->Next){
//			if (strcmp(P->Data.SoHieuMB , id) == 0){
//				return P;
//			}
//		}
//	}
//	return NULL;
//}
bool DeleteAiplane(LIST_AIRPLANE &l, char id[]){
	int i = FindIndexAirplane(l, id);
	if(l.List[i]->Turn > 0){
		mess = "May bay nay da len chuyen bay";
		return false;
	}
	if( i == -1 ){
	mess = "Khong tim thay may bay trong danh sach";
	return false;
	}
	
		delete l.List[i];
		for (i; i < l.sl - 1; i++) 
			l.List[i] = l.List[i + 1];
	 	
		l.sl--;
		
		mess = "Xoa thanh cong";
	return true;
}
void SwapAirplane(AIRPLANE &a, AIRPLANE &b)
{
	AIRPLANE temp = a;
	a = b;
	b = temp;
}
void SortByIdAirplain(LIST_AIRPLANE &l){
	for (int i = 0; i < l.sl-1; i++){
		for (int j = i + 1; j < l.sl; j++){
			if (strcmp(l.List[i]->IdMB, l.List[j]->IdMB) > 0)
				SwapAirplane(*l.List[i], *l.List[j]);
		}
	}
}
void SortByNumberFlight(LIST_AIRPLANE &l){
	for (int i = 0; i < l.sl-1; i++){
		for (int j = i + 1; j < l.sl; j++){
			if (l.List[i]->Turn < l.List[j]->Turn)
				SwapAirplane(*l.List[i], *l.List[j]);
		}
	}
}
void LoadAirplane(LIST_AIRPLANE &l) {
	int n;
	l.sl = 0;
	fstream f;
	f.open("dsmaybay.txt", ios::in);
	f >> n;
	for(int i = 0; i < n; i++){
		AIRPLANE *mb = new AIRPLANE;
		f.ignore();
		f.getline(mb->IdMB, MAXIDMB);
		f.getline(mb->Type, MAXTYPE);
		f >> mb->Chair;
		f >> mb->Turn;
		InsertAirplane(l, mb);
	}
	mess = "loadap";
	f.close();
}
void SaveAirplane(LIST_AIRPLANE &l){ 
	fstream f;
	f.open("dsmaybay.txt", ios::out);
	f << l.sl << endl;
	if (l.sl != 0) {
		for (int i = 0; i < l.sl; i++) {
			f << l.List[i]->IdMB << endl;
			f << l.List[i]->Type << endl;
			f << l.List[i]->Chair << endl;
			f << l.List[i]->Turn << endl;
		}
	}
	f.close();
}
bool correction(LIST_AIRPLANE &l, AIRPLANE *mb){
	int i = FindIndexAirplane(l, mb->IdMB);
	if(l.List[i]->Turn > 0){
		mess = "May bay nay da len chuyen bay";
		return false;
	}
	if( i == -1 ){
		mess = "Khong tim thay so hieu may bay";
		return false;
 	}
 	strcpy(l.List[i]->Type, mb->Type);
	l.List[i]->Chair = mb->Chair;
 	return true;
}

          
