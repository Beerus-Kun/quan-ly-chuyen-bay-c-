int DayInLadder[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
int Presentday(){
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_mday;
}
int Presentmonth(){
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1+tg->tm_mon;
}
int Presentyear() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1900+tg->tm_year;
}
int Presenthour() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_hour;
}
int Presentmin() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_min;
}
bool DateTime(DATETIME &dt)
{
	if(dt.h < 0 || dt.h >= 24) return false;
	if(dt.mi < 0 || dt.mi >= 60) return false;
	if(dt.m <= 0  || dt.m > 12) return false;
	DayInLadder[2] = 28;
	if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))
		DayInLadder[2] = 29;
	if (dt.d > DayInLadder[dt.m] || dt.d <= 0) return false;
	return true;
}
bool DateTimeValue(DATETIME &dt)
{
	if (!DateTime(dt)) return false;
	DayInLadder[2] = 28;
	if (dt.y < Presentyear()) return false;
	if ((dt.y == Presentyear()) && (dt.m < Presentmonth()))  return false;
	if ((dt.y % 400 == 0) || (dt.y % 4 == 0 && dt.y % 100 != 0))
		DayInLadder[2] = 29;
	if (dt.y == Presentyear() && dt.m == Presentmonth() && dt.d < Presentday()) return false;
	if (dt.y == Presentyear() && dt.m == Presentmonth() && dt.d == Presentday() && dt.h < Presenthour()) return false;
	if (dt.y == Presentyear() && dt.m == Presentmonth() && dt.d == Presentday() && dt.h == Presenthour() && dt.mi <= Presentmin()) return false;
	return true;
}
void CurrentTime(DATETIME &dt) {
	dt.d = Presentday();
	dt.m = Presentmonth();
	dt.y = Presentyear();
	dt.h = Presenthour();
	dt.mi = Presentmin();
}
bool CompareDate(DATETIME &a, DATETIME &b){
	if((a.mi == b.mi) && (a.h == b.h) && (a.d == b.d) && (a.m == b.m) && (a.y == b.y)) return true;
	return false;
}
