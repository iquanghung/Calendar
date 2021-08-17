#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include<MMsystem.h>
#include<Math.h>
//supportFuntion
int numOfuser = 2, placePass = 0, placeUser = 0, placeFull = 0, placeValipass = 0, keyUser, checkThird, saveRowOfThird, saveColumnOfThird, saveEnd, saveRowToday, saveColumnToday, numOfNotes, haveLove = 0; 
int checkHoliday[100][100];
struct userID {
	char fullName[500];
	char userName[500];
	char password[50];
	int key;
}user1, user2;
struct Remainder{
    int dd;
    int mm;
    char note[50];
    int key;
    int year;
};
void countNote(int dd);
void showNote(int dd);
void frameChooseInNote();
void coverFrame();
void addNote(int day);
void deleteNote();
int checkNote(char tmp[500]);
void chooseBeorCa();
void checkHave();
void beenTogether();
void changeColorHeart();
void exitBeen();
struct Remainder R;
struct userID user[500];
char fullName[500], userName[500], password[500], valipass[500];
char uid[500], pwd[500];
void hidePassword(char pwd[500]);
void inputPassword(char pwd[500]);
void inputValipass(char pwd[500]);
void countNote(int dd);
struct love {
	int key;
	char lover[500];
	int day;
	int month;
	int year;
};
struct love L, Ex;
void loginFrame();
int day, month, year, dayIs, saveMonth, saveYear, dayOne, monthOne, yearOne, checkInvalid, hours, minutes, seconds, check, isFound, numOfNote;
char ch; 
void showCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}	

void gotoxy(int x, int y){
	 HANDLE Manipulador;
	 COORD Coordenadas;
	 Manipulador = GetStdHandle(STD_OUTPUT_HANDLE);
	 Coordenadas.X = x;
	 Coordenadas.Y = y;
	 SetConsoleCursorPosition(Manipulador,Coordenadas);
}
void changeColore(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Calender
int day, month, year, dayIs, saveMonth, saveYear, dayOne, monthOne, yearOne, checkInvalid, hours, minutes, seconds, saveDay[1000][1000], checkDoneStr;
char ch, str[100];
void textColor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau,x);
}
void nowIs()
{
    gotoxy(130, 2);
    printf("Now is: ");
    gotoxy(138, 2);
    if (hours < 12)    // before midday
        printf("%02d:%02d am\n", hours, minutes);
    else    // after midday
        printf("%02d:%02d pm\n", hours - 12, minutes);
}
void checkTheDayIsHoliday()
{
	for (int i=1; i<=99; i++)
	   for (int j = 1; j <= 99; j++)
	       checkHoliday[i][j]==0;
	checkHoliday[1][1] = 1;
    checkHoliday[14][2] = 1;
	checkHoliday[27][2] = 1;
	checkHoliday[8][3] = 1;
	checkHoliday[26][3] = 1;
	checkHoliday[1][4] = 1;
	checkHoliday[30][4] = 1;
	checkHoliday[1][5] = 1;
	checkHoliday[7][5] = 1;
	checkHoliday[13][5] = 1;
	checkHoliday[19][5] = 1;
	checkHoliday[1][6] = 1;
	checkHoliday[17][6] = 1;
	checkHoliday[28][6] = 1;
	checkHoliday[27][7] = 1;
	checkHoliday[2][9] = 1;
	checkHoliday[20][10] = 1;
	checkHoliday[31][10] = 1;
	checkHoliday[20][11] = 1;
	checkHoliday[1][12] = 1;
	checkHoliday[24][12] = 1;
	checkHoliday[22][12] = 1;
}
char *getHoliday(int dayHoliday, int monHoliday)
{
    monHoliday = dayHoliday * monHoliday;
    switch(monHoliday)
    {
      case 1 :return("   New Year");
      case 28 :return("  Valentine");
      case 54 :return("  VN Doctor");
      case 24 :return(" Women's day");
      case 78 :return(" TNCS HCM ");
      case 4 :return(" April Fool");
      case 120 :return("S.revolution");
      case 5 :return("   Labor");
      case 35 :return(" DBP victory");
      case 65 :return("  Mom's day");
      case 95 :return("HCM birthday");
      case 6 :return("Children's day");
      case 102 :return("  Dad's day");
      case 168 :return("  VN family");
      case 189 :return("   Invalids");
      case 18 :return(" National Day");
      case 200 :return("   VN Women");
      case 310 :return("  Halloween");
      case 220 :return(" VN Teachers");
      case 12 :return("   No AIDS");
      case 288 :return("   Christmas");
      case 264 :return("National Army");
   }
}
void drawDay()
{
    for (int i = 1; i <= 164; i++)
        {
            gotoxy(i,1);
            printf("%c", 223);
            gotoxy(i,42);
            printf("%c", 220);
        }
    for (int i = 1; i <= 42; i++)
        {
            gotoxy(1,i);
            printf("%c", 222);
            gotoxy(164,i);
            printf("%c", 221);
        }
}
void drawCalendar()
{
    for(int save = 11; save < 40; save = save + 5)
    {
        int horizontal = 4;
        int horizontalCheck = horizontal + 15;
        for(int num = 1; num < 8; num++)
           {
                for(horizontal; horizontal < horizontalCheck; horizontal++)
                    {
                        gotoxy(horizontal, save);
                        printf("%c", 223);
                        gotoxy(horizontal, save + 4);
                        printf("%c", 220);
                    }
                    horizontal = horizontal + 1;
                    horizontalCheck = horizontalCheck + 16;
            }
    }
    for(int num = 3; num < 116; num++)
        {
            gotoxy(num, 41);
            printf("%c", 223);
        }
    for(int save = 3; save < 117; save = save + 16)
        {
            int num = 7;
            for(num; num < 41; num++)
                {
                    gotoxy(save, num);
                    printf("%c", 219);
                }
        }
    int num = 4;
    int check = 19;
    for(num; num < 115; num++)
        {
            if(num == check)
                {
                    num = num + 1;
                    check = check + 16;
                }
            gotoxy(num, 10);
            printf("%c", 220);
        }
    for(int num = 3; num < 116; num++)
        {
            gotoxy(num, 7);
            printf("%c", 220);
        }
}
char *getMonth(int mon)
{
    mon = mon % 12;
    switch(mon)
    {
      case 1 :return("January");
      case 2 :return("February");
      case 3 :return("March");
      case 4 :return("April");
      case 5 :return("May");
      case 6 :return("June");
      case 7 :return("July");
      case 8 :return("August");
      case 9 :return("September");
      case 10 :return("October");
      case 11 :return("November");
      case 0 :return("December");
   }
}

char *getDay(int day)   // tra ve ten cua ngay do
{
    day = day % 7;
    switch(day)
    {
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
   }
}
int checkMon(int mont)   // kiem tra de thang do co 30 hay 31 ngay
{
    if ( (mont == 1) || (mont == 3) || (mont == 5) || (mont == 7) || (mont == 8) || (mont == 10) || (mont == 12) )
        return 1;
    if ( (mont == 4) || (mont == 6) || (mont == 9) || (mont == 11) )
        return 0;
}
int leapYear(int yea)   // kiem tra nam nhuan, = 1 la nhuan, = 0 la khong phai nam nhuan
{
    if (yea % 4 == 0)
        return 1;
    else
        return 0;
}
int countDay(int dayFirst, int monthFirst, int yearFirst, int daySecond, int monthSecond, int yearSecond)
{
    int sum, save = monthFirst, j;
    sum = 0;
    yearSecond = yearSecond - 1;
    for (int i = yearFirst ; i <= yearSecond; i++)
    {
        j = save;
        for (j; j<= 12; j++)
        {
            if ( (j == 2) && (leapYear(i) == 1) )
                sum = sum + 29;
            else if ( (j == 2) && (leapYear(i) == 0) )
                sum = sum + 28;
            else if (checkMon(j) == 1)
                sum = sum + 31;
            else
                sum = sum + 30;
            save = 1;
         }
    }
    yearSecond = yearSecond + 1;
    if ( (monthFirst == 2) && (leapYear(yearFirst) == 1) )  // tru di so ngay cua thang dau tien tinh
        sum = sum - dayFirst + 1;
    else if ( (monthFirst == 2) && (leapYear(yearFirst) == 0) )
        sum = sum - dayFirst + 1;
    else if (checkMon(monthFirst) == 1)
        sum = sum - dayFirst + 1;
    else if (checkMon(monthFirst) == 0)
        sum = sum - dayFirst + 1;
    for (int i = 1; i <= monthSecond; i++)
    {
        if ( (i == 2) && (leapYear(yearSecond) == 1) )
            sum = sum + 29;
        else if ( (i == 2) && (leapYear(yearSecond) == 0) )
            sum = sum + 28;
        else if (checkMon(i) == 1)
            sum = sum + 31;
        else if (checkMon(i) == 0)
            sum = sum + 30;
    }
    if ( (monthSecond == 2) && (leapYear(yearSecond) == 1) )
        sum = sum - 29 + daySecond;
    else if ( (monthSecond == 2) && (leapYear(yearSecond) == 0) )
        sum = sum - 28 + daySecond;
    else if (checkMon(monthSecond) == 1)
        sum = sum - 31 + daySecond;
    else if (checkMon(monthSecond) == 0)
        sum = sum - 30 + daySecond;
    return sum;
}
void printfT()
{
    printf("\t\t\t");
}
void printfN()
{
    printf("\n\n");
}
void printfMenu()
{
    gotoxy(122,6);
    textColor(0);
    printf("About our menu: ");
    gotoxy(124,7);
    printf("- Press 'q' to go back.");
    gotoxy(124,8);
    printf("- Press 'n' to see next month.");
    gotoxy(124,9);
    printf("- Press 'p' to see previous month.");
    gotoxy(124,10);
    printf("- Press '1' to find the day in lunar.");
    gotoxy(124,11);
    printf("- Press '2' to find out the day.");
    gotoxy(124,12);
    printf("- Press '3' to see all day of the month.");
    gotoxy(124,13);
    printf("- And please type anything: a");
    textColor(15);
    gotoxy(122,6);
    printf("About our menu: ");
    gotoxy(124,7);
    printf("- Press 'q' to go back.");
    gotoxy(124,8);
    printf("- Press 'n' to see next month.");
    gotoxy(124,9);
    printf("- Press 'p' to see previous month.");
    gotoxy(124,10);
    printf("- Press '1' to find the day in lunar.");
    gotoxy(124,11);
    printf("- Press '2' to find out the day.");
    gotoxy(124,12);
    printf("- Press '3' to see all day of the month.");
    gotoxy(124,13);
    printf("- And please type anything: ");
}
void printfMonth(int mon, int yea)
{
    textColor(0);
    gotoxy(48,5);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    textColor(15);
    gotoxy(48,5);
    printf("This month is: %s, %d", getMonth(mon), yea);
    saveMonth = mon;
    saveYear = yea;
    int days = countDay(2,1,1,1,mon,yea), start, end, i;
    days = days % 7;
    start = 1;
    if ( (mon == 2) && (leapYear(yea) == 1) )
        end = 29;
    else if ( (mon == 2) && (leapYear(yea) == 0) )
        end = 28;
    else if (checkMon(mon) == 1)
        end = 31;
    else if (checkMon(mon) == 0)
        end = 30;
    saveEnd = end; 
    int column = 12, row = 11, saveRow;
    saveRow = row;
    int before = 1;
    while (before <= 6)
    {
    for (int i = 0; i <= 6; i++)
        {
            gotoxy(row,column);
            saveDay[row][column]=0;
            textColor(0);
            printf("  ");
            gotoxy(row - 6, column + 2);
            printf("       ");
            gotoxy(row-6,column+1);
            printf("aaaaaaaaaaaaaa");
            row = row + 16;
        }
    row = 11;
    column = column + 5;
    before = before + 1;
    }
    row = 11;
    column = 12;
    textColor(15);
    while (start <= end)
    {
        if ( ( start == 1 ) && (days != 0) )
            {
                for (i = 0; i<= days -1 ;i++)
                    row = row + 16;
            }
        for (i = days; i <= 6; i++)
            {
                gotoxy(row,column);
                saveDay[row][column] = start;
                printf("%d", start);
                if ( (start == day) && (saveMonth == month) && (saveYear == year) )
                {
                	saveRowToday = row;
					saveColumnToday = column; 
				}
                if ( ( start == dayOne ) && (checkThird == 1) )
                {
                	saveRowOfThird = row;
                	saveColumnOfThird = column;
				}
				if (checkHoliday[start][saveMonth] == 1)
				{
					gotoxy(row-6, column+1);
					printf("%s", getHoliday(start,saveMonth));
				}
                countNote(start);
                if (isFound = 1) {
               	gotoxy(row - 6, column + 2);
               	if (numOfNote == 1) {
				   printf("%d note", 1); 
				   } else if (numOfNote != 0) printf("%d notes", numOfNote);
				}
                row = row + 16;
                start = start +1;
                if (start > end)
                    break;
            }
        column = column + 5;
        row = saveRow;
        days = 0;
    }
}
void printfSTR()
{
    checkDoneStr = 0; // neu = 1 thi sai, thoat luon, neu van bang 0 thi dung
    int lenth, check = 0, save = 0, s;
    monthOne=0; dayOne=0; yearOne=0;
    lenth = strlen(str);
    for (int i = 0; i < lenth; i++)
    {
        if ( (!( (str[i]>='0')&&(str[i]<='9'))) && (str[i] != ' ') )
            {
                checkDoneStr = 1;
                return;
            }
    }
    int thuTu = 0;
    for (int i = 0; i < lenth; i++)
    {
        if ( str[i] >= '0' && str[i] <= '9' )
            {
                s = str[i];
                s = s - 48;
                save = save * 10 + s;
                check = 1;
                
            }
        if ( (str[i] == ' ') && ( thuTu == 0 ) && (check == 1) )
          {
                dayOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
        else if ( (str[i] == ' ') && ( thuTu == 1 ) && (check == 1) )
          {
                monthOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
        else if ( (str[i] == ' ') && ( thuTu == 2 ) && (check == 1) )
          {
                yearOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
         if (thuTu == 3)
           break;
    }
    yearOne = save;
}
void printfValid()
{
    checkInvalid = 0;
    if (checkDoneStr == 1)
        {
                gotoxy(118,18);
               printf("Please press number.");
               checkInvalid = 1;
            return ;
        }
    else if ( (monthOne < 1) || (monthOne > 12) )
        {
            
            gotoxy(118,18);
            printf("Invalid month. Please press 1 <= month <= 12.");
            checkInvalid = 1;
            return ;
        }
    else if (dayOne <= 0)
        {
            gotoxy(118,18);
            printf("Invalid day. Please press 1 <= day <= 31.");
            checkInvalid = 1;
            return;
        }
    else if (yearOne <= 0)
        {
            gotoxy(118,18);
            printf("Invalid year. Please press year again.");
            checkInvalid = 1;
            return;
        }
    else if (dayOne > 31)
        {
            gotoxy(118,18);
            printf("Invalid day. Please press 1 <= day <= 31.");
            checkInvalid = 1;
            return;
        }
    else if ( (leapYear(yearOne) == 1) && (monthOne == 2) && ( dayOne > 29 ) )
       {
               gotoxy(120,18);
            printf("Leap Year have 29 days one February.");
               checkInvalid = 1;
            return ;
       }
    else if ( (leapYear(yearOne) == 0) && (monthOne == 2) && ( dayOne > 28 ) )
       {
               gotoxy(120,18);
               printf("If is not leap year, February have 28 days.");
               checkInvalid = 1;
            return ;
       }
    else if ( ( checkMon(monthOne) == 0) && ( dayOne > 30 ) )
       {
               gotoxy(119,18);
               printf("April, June, September, November have 30 days");
               checkInvalid = 1;
            return ;
        }
}

//Chuyen doi ngay
//Lay Ngáy Julius
long getJulius(int intNgay, int intThang, int intNam)
{
    int a, y, m, jd;
    a = (int)((14 - intThang) / 12);
    y = intNam + 4800 - a;
    m = intThang + 12 * a - 3;
    jd = intNgay + (int)((153 * m + 2) / 5) + 365 * y + (int)(y / 4)  - (int)(y / 100) + (int)(y / 400) - 32045;
    if (jd < 2299161)
    {
        jd = intNgay + (int)((153 * m + 2) / 5) + 365 * y + (int)(y / 4)  - 32083;
    }
    return jd;
}
 
// Tinh ngay Soc
int getNewMoonDay(int k)
{
    float PI = 3.14159265358979323846;
    double T, T2, T3, dr, Jd1, M, Mpr, F, C1, deltat, JdNew;
    T = k / 1236.85;
    T2 = T * T;
    T3 = T2 * T;
    dr = PI / 180;
    double timeZone = 7.0;
    Jd1 = 2415020.75933 + 29.53058868 * k + 0.0001178 * T2 - 0.000000155 * T3;
    // Mean new moon
    Jd1 = Jd1 + 0.00033 * sin((166.56 + 132.87 * T - 0.009173 * T2) * dr);
    // Sun's mean anomaly
    M = 359.2242 + 29.10535608 * k - 0.0000333 * T2 - 0.00000347 * T3;
    // Moon's mean anomaly
    Mpr = 306.0253 + 385.81691806 * k + 0.0107306 * T2 + 0.00001236 * T3;
    // Moon's argument of latitude
    F = 21.2964 + 390.67050646 * k - 0.0016528 * T2 - 0.00000239 * T3;
    C1 = (0.1734 - 0.000393 * T) * sin(M * dr) + 0.0021 * sin(2 * dr * M);
    C1 = C1 - 0.4068 * sin(Mpr * dr) + 0.0161 * sin(dr * 2 * Mpr);
    C1 = C1 - 0.0004 * sin(dr * 3 * Mpr);
    C1 = C1 + 0.0104 * sin(dr * 2 * F) - 0.0051 * sin(dr * (M + Mpr));
    C1 = C1 - 0.0074 * sin(dr * (M - Mpr)) + 0.0004 * sin(dr * (2 * F + M));
    C1 = C1 - 0.0004 * sin(dr * (2 * F - M)) - 0.0006 * sin(dr * (2 * F + Mpr));
    C1 = C1 + 0.0010 * sin(dr * (2 * F - Mpr)) + 0.0005 * sin(dr * (2 * Mpr + M));
    if (T < -11)
    {
        deltat = 0.001 + 0.000839 * T + 0.0002261 * T2 - 0.00000845 * T3 - 0.000000081 * T * T3;
    }
    else
    {
        deltat = -0.000278 + 0.000265 * T + 0.000262 * T2;
    }
    JdNew = Jd1 + C1 - deltat;
    return (int)(JdNew + 0.5 + timeZone / 24);
}
//TÃnh toa do mat troi
int getSunLongitude(int jdn)
{
    double timeZone = 7.0;
    float PI = 3.14159265358979323846;
    double T, T2, dr, M, L0, DL, L;
    // Time in Julian centuries from 2000-01-01 12:00:00 GMT
    T = (jdn - 2451545.5 - timeZone / 24) / 36525;
    T2 = T * T;
    // degree to radian
    dr = PI / 180;
    // mean anomaly, degree
    M = 357.52910 + 35999.05030 * T - 0.0001559 * T2 - 0.00000048 * T * T2;
    // mean longitude, degree
    L0 = 280.46645 + 36000.76983 * T + 0.0003032 * T2;
    DL = (1.914600 - 0.004817 * T - 0.000014 * T2) * sin(dr * M);
    DL = DL + (0.019993 - 0.000101 * T) * sin(dr * 2 * M) + 0.000290 * sin(dr * 3 * M);
    L = L0 + DL; // true longitude, degree
    L = L * dr;
    // Normalize to (0, 2*PI)
    L = L - PI * 2 * (int)(L / (PI * 2));
    return (int)(L / PI * 6);
}
// Tœm ngáy bat dau th?ng 11 am lich
int getLunarMonthll(int intNam)
{
    double k, off, nm, sunLong;
    off = getJulius(31, 12, intNam) - 2415021;
    k = (int)(off / 29.530588853);
    nm = getNewMoonDay((int)k);
    // sun longitude at local midnight
    sunLong = getSunLongitude((int)nm);
    if (sunLong >= 9)
    {
        nm = getNewMoonDay((int)k - 1);
    }
    return (int)nm;
}
//X?c dinh thang nhuan
int getLeapMonthOffset(double a11)
{
    double last, arc;
    int k, i;
    k = (int)((a11 - 2415021.076998695) / 29.530588853 + 0.5);
    last = 0;
    // We start with the month following lunar month 11
    i = 1;
    arc = getSunLongitude((int)getNewMoonDay((int)(k + i)));
    do
    {
        last = arc;
        i++;
        arc = getSunLongitude((int)getNewMoonDay((int)(k + i)));
    } while (arc != last && i < 14);
    return i - 1;
}
//Doi ra ngay am-duong
int convertSolar2Lunar(int intNgay, int intThang, int intNam)
{
    double dayNumber, monthStart, a11, b11, lunarDay, lunarMonth, lunarYear;
    //double lunarLeap;
    int k, diff;
    dayNumber = getJulius(intNgay,intThang,intNam);
    k = (int)((dayNumber - 2415021.076998695) / 29.530588853);
    monthStart = getNewMoonDay(k + 1);
    if (monthStart > dayNumber)
    {
        monthStart = getNewMoonDay(k);
    }
    a11 = getLunarMonthll(intNam);
    b11 = a11;
    if (a11 >= monthStart)
    {
        lunarYear = intNam;
        a11 = getLunarMonthll(intNam - 1);
    }
    else
    {
        lunarYear = intNam + 1;
        b11 = getLunarMonthll(intNam + 1);
    }
    lunarDay = dayNumber - monthStart + 1;
    diff = (int)((monthStart - a11) / 29);
    //lunarLeap = 0;
    lunarMonth = diff + 11;
    if (b11 - a11 > 365)
    {
        int leapMonthDiff = getLeapMonthOffset(a11);
        if (diff >= leapMonthDiff)
        {
            lunarMonth = diff + 10;
            if (diff == leapMonthDiff)
            {
            //lunarLeap = 1;
            }
        }
    }
    if (lunarMonth > 12)
    {
        lunarMonth = lunarMonth - 12;
    }
    if (lunarMonth >= 11 && diff < 4)
    {
        lunarYear -= 1;
    }
    int Ngay = lunarDay;
    int Thang = lunarMonth;
    int Nam = lunarYear;
     if ( Ngay > 0)
    {
    return printf("The day in lunar calendar is: %d %d %d",Ngay, Thang, Nam);
    }
	else
	return printf("It is before Christ.");
}
int getMonthLunar(int intNgay, int intThang, int intNam)
{
    double dayNumber, monthStart, a11, b11, lunarDay, lunarMonth, lunarYear;
    //double lunarLeap;
    int k, diff;
    dayNumber = getJulius(intNgay,intThang,intNam);
    k = (int)((dayNumber - 2415021.076998695) / 29.530588853);
    monthStart = getNewMoonDay(k + 1);
    if (monthStart > dayNumber)
    {
        monthStart = getNewMoonDay(k);
    }
    a11 = getLunarMonthll(intNam);
    b11 = a11;
    if (a11 >= monthStart)
    {
        lunarYear = intNam;
        a11 = getLunarMonthll(intNam - 1);
    }
    else
    {
        lunarYear = intNam + 1;
        b11 = getLunarMonthll(intNam + 1);
    }
    lunarDay = dayNumber - monthStart + 1;
    diff = (int)((monthStart - a11) / 29);
    //lunarLeap = 0;
    lunarMonth = diff + 11;
    if (b11 - a11 > 365)
    {
        int leapMonthDiff = getLeapMonthOffset(a11);
        if (diff >= leapMonthDiff)
        {
            lunarMonth = diff + 10;
            if (diff == leapMonthDiff)
            {
            //lunarLeap = 1;
            }
        }
    }
    if (lunarMonth > 12)
    {
        lunarMonth = lunarMonth - 12;
    }
    if (lunarMonth >= 11 && diff < 4)
    {
        lunarYear -= 1;
    }
    int Ngay = lunarDay;
    int Thang = lunarMonth;
    int Nam = lunarYear;
    if (Ngay > 0)
    {
    return printf("%d/%d",Ngay, Thang);
	}
	else if (Nam > 1900)
	return printf("B.C");
}
void findDayInLunarCalendar()
{
	int checkESC = 0;
    gotoxy(125,15);
    printf("Please press the day (DD MM YYYY): ");
    gotoxy(125,16);
    fflush(stdin);
    scanf("%[^\n]s", &str);
    printfSTR();
    printfValid();
    while (checkInvalid == 1)
        {
            gotoxy(119,20);
            printf("Press any key for again or press ESC to quit.");
            textColor(0);
            gotoxy(125,16);
            printf("                                     ");
            textColor(15);
            gotoxy(125,16);
            char sa;
            fflush(stdin);
            Nocursortype();
            sa = getch();
            if (sa == 27)
                {
                	checkESC = 1;
				    break;
			    }
			else
			{
			showCursor();
            fflush(stdin);
            gotoxy(125,16);
            scanf("%[^\n]s", &str);
            printfSTR();
            printfValid();
            }
        }
    textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,19);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(119,20);
    printf("Press any key to continue...                 ");
    textColor(15);
    if ( checkESC == 0)
    {
    gotoxy(124,18);
    convertSolar2Lunar(dayOne,monthOne,yearOne);
    gotoxy(124,20);
    printf("Press any key to continue... ");
    getch();
    }
    textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(119,20);
    printf("Press any key to continue...                 ");
    textColor(15);
    printfMonth(saveMonth, saveYear);
    printfMenu();
}
void printfOutDay()
{
	int checkESC = 0;
    gotoxy(125,15);
    printf("Please press the day (DD MM YYYY): ");
    gotoxy(125,16);
    fflush(stdin);
    scanf("%[^\n]s", &str);
    printfSTR();
    printfValid();
    while (checkInvalid == 1)
        {
            gotoxy(119,20);
            printf("Press any key for again or press ESC to quit.");
            textColor(0);
            gotoxy(125,16);
            printf("                                     ");
            textColor(15);
            gotoxy(125,16);
            char sa;
            fflush(stdin);
            Nocursortype();
            sa = getch();
            if (sa == 27)
                {
                	checkESC = 1;
				    break;
			    }
			else
			{
			showCursor();
            fflush(stdin);
            gotoxy(125,16);
            scanf("%[^\n]s", &str);
            printfSTR();
            printfValid();
            }
        }
    textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	gotoxy(120,19);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(119,20);
    printf("Press any key to continue...                 ");
    textColor(15);
    if (checkESC == 0)
    {
    gotoxy(124,18);
    printf("The day is %s !!!", getDay(countDay(2,1,1,dayOne,monthOne,yearOne)));
    gotoxy(124,20);
    printf("Press any key to continue... ");
    getch();
    }
    textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	gotoxy(119,20);
    printf("Press any key to continue...                 ");
    textColor(15);
    printfMonth(saveMonth,saveYear);
    printfMenu();
}
void showDayInMonth()
{
	int checkESC = 0;
    gotoxy(125,15);
    printf("Please press out the day (DD MM YYYY): ");
    gotoxy(125,16);
    fflush(stdin);
    scanf("%[^\n]s", &str);
    printfSTR();
    printfValid();
    while (checkInvalid == 1)
        {
            gotoxy(119,20);
            printf("Press any key for again or press ESC to quit.");
            textColor(0);
            gotoxy(125,16);
            printf("                                     ");
            textColor(15);
            gotoxy(125,16);
            char sa;
            fflush(stdin);
            Nocursortype();
            sa = getch();
            if (sa == 27)
                {
                	checkESC = 1;
				    break;
			    }
			else
			{
			showCursor();
            fflush(stdin);
            gotoxy(125,16);
            scanf("%[^\n]s", &str);
            printfSTR();
            printfValid();
            }
        }
	textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	gotoxy(120,19);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(119,20);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    if (checkESC == 0)
    {
	checkThird = 1; // =1 la co su dung cai so 3, bang 0 la ko su dung
    printfMonth(monthOne,yearOne);
	}          
}
void printfNextMonth()
{
    if (saveMonth == 12)
        {
        	saveMonth = 1; ++saveYear;
            printfMonth(1, saveYear );
            printfMenu();
        }
    else
        {
        	++saveMonth;
            printfMonth(saveMonth , saveYear);
            printfMenu();
        }
}
void printfPreviousMonth()
{
    if (saveMonth == 1)
        {
        	if (saveYear == 0) 
        	    return;
            printfMonth(12, saveYear - 1);
            printfMenu();
        }
    else
        {
            printfMonth(saveMonth - 1, saveYear);
            printfMenu();
        }
}
void printfStart()
{
    drawDay();
    drawCalendar();
    checkTheDayIsHoliday();
   // nowIs();
    gotoxy(3,2);
    printf("Welcomeback to calendar");
    gotoxy(48,2);
    printf("Today is: %s %d, %d", getMonth(month), day, year);
    gotoxy(8, 9);
    printf("Sunday");
    gotoxy(25, 9);
    printf("Monday");
    gotoxy(39, 9);
    printf("Tuesday");
    gotoxy(55, 9);
    printf("Wednesday");
    gotoxy(72, 9);
    printf("Thursday");
    gotoxy(89, 9);
    printf("Friday");
    gotoxy(104, 9);
    printf("Satuday");
    printfMonth(month, year);
    ch = 'a';
    printfMenu();
    int hang = saveRowToday-6;
    int cot = saveColumnToday;
    int saveCot;
    saveCot = cot;
    for(int num = 0; num < 3; num++)
    {
        textColor(226);
        gotoxy(hang, cot);
        printf("             ");
        cot = cot + 1;
    }
    cot = saveCot;
    textColor(226);
    gotoxy(saveRowToday,saveColumnToday);
    if (saveDay[saveRowToday][saveColumnToday] > 0)
        {
		    printf("%d",saveDay[saveRowToday][saveColumnToday]);
		    textColor(228);
		    gotoxy(saveRowToday+3,saveColumnToday+2);
		    getMonthLunar(saveDay[saveRowToday][saveColumnToday],saveMonth,saveYear);
		}
    while (1)
        {
            ch=getch();
             gotoxy(123,12);
            textColor(0);
            printf("a");
            gotoxy(145,14);
            saveCot = cot;
            textColor(15);
            checkThird = 0;
            for(int num = 0; num < 3; num++)
                {
                    gotoxy(hang, cot);
                    printf("              ");
                    cot = cot + 1;
                }
            cot = saveCot;
            textColor(15);
            if (saveDay[hang+6][cot] > 0)
                {
                    gotoxy(hang+6,cot);
                    printf("%d",saveDay[hang+6][cot]);
                    countNote(saveDay[hang+6][cot]);
                if (isFound = 1) {
               	gotoxy(hang , cot + 2);
               	if (numOfNote == 1) {
				   printf("%d note", 1); 
				   } else if (numOfNote != 0) printf("%d notes", numOfNote);
				}
				if (checkHoliday[saveDay[hang+6][cot]][saveMonth] == 1)
            {
            	    gotoxy(hang, cot + 1);
            	    printf("%s", getHoliday(saveDay[hang+6][cot],saveMonth));
			}
                }
         			if (ch == 13) 
		{
		 	// addNote(saveDay[hang + 6,cot], saveMonth);
			// addNote(saveDay[hang + 6][cot]);//add note
			 showNote(saveDay[hang + 6][cot]);//Show note
			 break;
		} else	
		 if (ch == 'q'){
			 	system("cls");
				chooseBeorCa();
				break;
		}
            else if (ch == 'p')
                {
                    printfPreviousMonth();
                }
            else if (ch == 'n')
                {
                    printfNextMonth();
                }
            else if (ch == '2')
                {
                	showCursor();
                    printfOutDay();
                    Nocursortype();
                }
            else if (ch == '1')
                {
                	showCursor();
                    findDayInLunarCalendar();
                    Nocursortype();
                }
            else if (ch == '3')
               {
               	    showCursor();
               	    showDayInMonth();
               	    Nocursortype();
			   }
            if (ch == 72)
                {
                    if(cot != 12)
                          {
                          if (saveDay[hang+6][cot-5] > 0) {
                    cot = cot - 5;
                    }
                }
          }
        else if(ch == 80) {
            if(cot != 37) {
                if (saveDay[hang+6][cot+5] > 0) {
            cot = cot + 5;
              }
            }
        }
        else if(ch == 77) {
        	if (saveDay[hang+6][cot] == saveEnd)
			   printfNextMonth(); 
            else
			{
			if(hang != 101) {
                if (saveDay[hang+22][cot] > 0) {
                hang = hang + 16;
                }
            } else {
                if (saveDay[11][cot+5] > 0) {
                hang = 5;
                cot = cot + 5; 
                }
            }
           }
        }
        else if(ch == 75) {
        	if (saveDay[hang+6][cot] == 1)
			   printfPreviousMonth(); 
            else 
			{ if(hang != 5) {
                 if (saveDay[hang+6-16][cot] > 0) {
                hang = hang - 16;
                }
            } else {
                if (saveDay[107][cot-5] > 0) {
                hang = 101;
                cot = cot - 5; 
                }
            }
        }
        }
        textColor(0);
        gotoxy(145,14); printf("."); textColor(15);
        if (checkThird == 1)
        {
             cot = saveColumnOfThird;
			 hang = saveRowOfThird - 6; 	
		}
        textColor(226);
        saveCot = cot;
        for(int num = 0; num < 3; num++) {
            gotoxy(hang, cot);
            printf("             ");
            cot = cot + 1;
        }
        cot = saveCot;
        textColor(226);
        if (saveDay[hang+6][cot] > 0)
            {
                gotoxy(hang+6,cot);
                printf("%d",saveDay[hang+6][cot]);
                textColor(228);
                countNote(saveDay[hang+6][cot]);
                if (isFound = 1) {
               	gotoxy(hang , cot + 2);
               	if (numOfNote == 1) {
				   printf("%d note", 1); 
				   } else if (numOfNote != 0) printf("%d notes", numOfNote);
				}
                gotoxy(hang+8,cot+2);
		        getMonthLunar(saveDay[hang+6][cot],saveMonth,saveYear);
            }
        }
    
}
void findDate()
{    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    day = local->tm_mday;
    month = local->tm_mon + 1;
    year = local->tm_year + 1900;
    hours = local->tm_hour;
    minutes = local->tm_min;
    seconds = local->tm_sec;
}
//Addnote
int thisDay;
void printNoteChoice() {
	frameChooseInNote();
	Nocursortype();
	gotoxy(120, 22);
	changeColore(2);
	printf("  ADD NOTE  ");
	gotoxy(120, 26);
	changeColore(7);
	printf("DELETE NOTE ");
	gotoxy(120, 30);
	printf("   BACK ");
}

void controlNote() {
	int checkKey = 0;
	while(1) {
		char key = getch();
		if(key == 27) { // For ESC
            break;
    	}
		if(key == 72) {
			checkKey = checkKey - 1;
		}
		if(key == 80) {
			checkKey = checkKey + 1;
		}
		if(checkKey < 0) {
			checkKey = 0;
		}
		if(checkKey > 2) {
			checkKey = 2;
		}
		if(key == 13) {
    		switch(checkKey) {
    			case 0:
    				system("cls");
   			 		coverFrame();
   			 		showCursor();
    				addNote(thisDay);
    				break;
    			case 1:
    				showCursor();
    				deleteNote();
    				break;	
    			case 2:
					system("cls");
					
					 Nocursortype();
    				findDate();
    				printfStart();
    				break;
			}
			break;
		} else { 
			if(checkKey == 0) {
				gotoxy(120, 22);
				changeColore(2);
				printf("  ADD NOTE  ");
				gotoxy(120, 26);
				changeColore(7);
				printf("DELETE NOTE ");
				gotoxy(120, 30);
				printf("   BACK ");	
			}
			if(checkKey == 1) {
				gotoxy(120, 26);
				changeColore(2);
				printf("DELETE NOTE ");
				gotoxy(120, 22);
 				changeColore(7);
				printf("  ADD NOTE  ");
				gotoxy(120, 30);
				printf("   BACK ");	
			}
			if(checkKey == 2) {		
				gotoxy(120, 30);
				changeColore(2);
				printf("   BACK ");	
				gotoxy(120, 22);
				changeColore(7);
				printf("  ADD NOTE  ");
				gotoxy(120, 26);
				printf("DELETE NOTE ");
			}
		} 	
	}
}
struct todayNote{
	char num[500];
};
struct todayNote ghichu[100], P;
void deleteNote(){
	FILE *fp;
    fp = fopen("trash.dat","ab+");
	 int input, temp, status;
	 
	int  numOfScan;
	char endChar;
	do{
		gotoxy(90,10);
		printf("                                               ");
		gotoxy(90,10);
		printf("Choose the note you want to delete: ");
		fflush(stdin);
	 	numOfScan = scanf("%d%c", &input, &endChar);
	} while(numOfScan != 2 || endChar != '\n' || input < 1 || input > numOfNote);
	 strcpy(P.num, ghichu[input - 1].num);
	 fwrite(&P, sizeof(P),1,fp);
	 gotoxy(90,11);
	 printf("Successful");
	 fclose(fp);
	 showNote(thisDay);
     printNoteChoice();
	controlNote();
   
	 
}
struct Remainder note[500];
void inputNote() {
	 FILE *fp;
	 int i = 0;
	  fp = fopen("Notes.dat","rb");
    while(fread(&R,sizeof(R),1,fp) == 1){
    	note[i].dd = R.dd;
    	note[i].mm = R.mm;
    	strcpy(note[i].note, R.note);
    	note[i].key = R.key;
    	note[i].year = R.year;
    	i++;
	}
	numOfNotes = i + 1;
	fclose(fp);
}
void countNote(int dd){
	 FILE *fp;
    int i = 0; 
	isFound = 0; numOfNote = 0;
    fp = fopen("Notes.dat","rb");
    while(fread(&R,sizeof(R),1,fp) == 1){
        if((R.mm == saveMonth) && (R.key == keyUser) && (R.dd == dd) && (R.year == saveYear) && (checkNote(R.note) != 1)){
            isFound = 1;
            i++;
        }
    }
    fclose(fp);
    numOfNote = i;
}
void addNote(int day){
    FILE *fp;
    fp = fopen("Notes.dat","ab+");
    gotoxy(5,8);
    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf("%[^\n]",R.note);
    R.dd = day;
    R.mm = saveMonth;
    R.year = saveYear;
    R.key = keyUser;
    if(fwrite(&R,sizeof(R),1,fp)){
        gotoxy(5,12);
        puts("Note is saved sucessfully");
        fclose(fp);
    }else{
        gotoxy(5,12);
      
        puts("\aFail to save!!\a");

    }
    gotoxy(5,20);
   
   getch();
    fclose(fp);
    //coverFrame();
    showNote(thisDay);
     printNoteChoice();
	controlNote();
}
int checkNote(char tmp[500]){
	FILE *fp;
	 fp = fopen("trash.dat","rb");
	 while(fread(&P, sizeof(P),1 ,fp) == 1){
	 	if (strcmp(P.num,tmp) == 0) return 1;
	 }
	 return 0;
}
void showNote(int dd){
    FILE *fp;
    thisDay = dd;
    int i = 0, found = 0;
    system("cls");
    fp = fopen("Notes.dat","rb");
    if(fp == NULL){
        printf("Error in opening the file");
    }
    while(fread(&R,sizeof(R),1,fp) == 1){
        if((R.mm == saveMonth) && (R.key == keyUser) && (R.dd == dd) && (R.year == saveYear) && (checkNote(R.note) != 1)){
        	strcpy(ghichu[i].num, R.note); 
            gotoxy(10,10+i);
            printf("Note %d Day = %d: %s", i+1, R.dd,  R.note);
            found = 1;
            i++;
        }
    }
    if(found == 0){
        gotoxy(10,10);
        printf("This day contains no note");
    }
    gotoxy(10,11+i);
     coverFrame();				
	 printNoteChoice();
 	 controlNote();
 
  //   findDate();
  // printfStart();
}


//Account processing

void processing(char ch[500]){
    char tmp[10] = "*||*";
    strcat(ch, tmp);
}
void inputUsername(char uid[500]);
void inputFullname(char uid[500]){
	int ch;
	int flag = 0;
	char tmp[] = "";
	while(1)
	{
	    ch = getch();
	    if ( placeFull > 27  )
		{	 
			 gotoxy(60, 20);
			 printf("Your name must be length from 5 - 30 characters.");
			 gotoxy(placeFull + 83, 18);
			 flag = 1;
		}
		else if (flag == 1)
		{
				gotoxy(60, 20);
			 printf("                                                 ");
			 gotoxy(placeFull + 83, 18);
			 flag = 0;
 	 }
	    if(ch == 13 || ch == 9)
	    {
	    		if (strcmp(uid,tmp) == 0) {
	    			gotoxy(83, 20);
					changeColore(4);
					printf("Your name must not be blank!!!");
					changeColore(7);
					gotoxy(83 + placeFull, 18);
					inputFullname(fullName);
					break;
			} else 
			{
			  	   gotoxy(83,20);
			  	   printf("                                        ");
	    	gotoxy(83 + placeUser, 22);
	    	inputUsername(userName);
	 	    break;}
	    
		}	
	    else if(ch == 8)
	    {       if(placeFull != 0) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	            placeFull--;
	            uid[placeFull] = '\0';
	        }
	        else
	        continue;
	    }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 80) 
			{
			   gotoxy(83 + placeUser, 22);
			   inputUsername(userName);
			   break;
            }
	    	ch = 224;
		}
	    else if (((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch == 32)) && (placeFull < 30))
	    {
		    putchar(ch);/* char - '*' will be printed instead of the character */
		    uid[placeFull] = ch;
		    placeFull++;
	    }
	}
	uid[placeFull] = '\0';
}
void inputUsername(char uid[500]){
	int ch;
	int flag = 0;
	char tmp[] = "";
	while(1)
	{
	    ch = getch();
	    if (placeUser > 27  )
		{	 
			 gotoxy(60, 24);
			 printf("Your username must be length from 5 - 30 characters.");
			 gotoxy(placeUser + 83, 22);
			 flag = 1;
		}
		else if (flag == 1)
		{
		 	 gotoxy(60, 24);
			 printf("                                                    ");
			 gotoxy(placeUser + 83, 22);
			 flag = 0;
 	 }
	    if(ch == 13 || ch == 9)
	    {
	    	if (strcmp(uid,tmp) == 0) {
	    			gotoxy(83, 24);
					changeColore(4);
					printf("Username must not be blank!!!");
					changeColore(7);
					gotoxy(83 + placeUser, 22);
					inputUsername(userName);
					break;
			} else 
	    	for (int i = 0; i < numOfuser; i++)
			{	
				if (strcmp(uid,user[i].userName) == 0){
					gotoxy(83, 24);
					changeColore(4);
					printf("Username already exists!!!");
					changeColore(7);
					gotoxy(83 + placeUser, 22);
					inputUsername(userName);
					break;
				} else {
					gotoxy(83, 24);
					printf("                                     ");
				}
			}
			if (placePass < 30)
	    	gotoxy(83 + placePass, 26); else gotoxy(113,26);
	    	inputPassword(password);
	 	    break;
	    
		}	
	    else if(ch == 8)
	    {       if(placeUser != 0) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	            placeUser--;
	            uid[placeUser] = '\0';
	        }
	        else
	        continue;
	    }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 80) 
			{
			 	if (placePass < 30)
	    	gotoxy(83 + placePass, 26); else gotoxy(113,26);
			   inputPassword(password);
			   break;
            }
            else if (ch == 72) 
			{
			   gotoxy(83 + placeFull, 18);
			   inputFullname(fullName);
			   break;
            }
	    	ch = 224;
		}
	    else if (((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 43 && ch < 59)) && (placeUser < 30))
	    {
		    putchar(ch);/* char - '*' will be printed instead of the character */
		    uid[placeUser] = ch;
		    placeUser++;
	    }
	}
	uid[placeUser] = '\0';
}
void inputPassword(char pwd[500]){
	int ch;
	char tmp[] = "";
	while(1)
	{
	    ch = getch();
	    if(ch == 13){
	    fflush(stdin);	
	        if (strcmp(pwd,tmp) == 0) {
	        	gotoxy(83,28);
	        	changeColore(4);
	        	printf("Password must not be blank!!");
	        	changeColore(7);
	        	gotoxy(83,26);
	        	inputPassword(pwd);
	        	break;
			} 
			else 
			{
			gotoxy(83,28);
			printf("                                     ");
		}
	     	if (placeValipass < 30)
	    	gotoxy(83 + placeValipass, 30); else gotoxy(113,30);
			   inputValipass(valipass);
			   break;
	}
	    else if(ch == 8)
	    {       if(placePass != 0 ) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	        	if (placePass < 31)
	        	{
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	        }
	            placePass--;
	            pwd[placePass] = '\0';
	        }
 
	    }
	    else if (ch == 9) 
			{
				 if (strcmp(pwd,tmp) == 0) {
	        	gotoxy(83,28);
	        	changeColore(4);
	        	printf("Password must not be blank!!");
	        	changeColore(7);
	        	gotoxy(83,26);
	        	inputPassword(pwd);
	        	break;
			} 
			else 
			{
			gotoxy(83,28);
			printf("                                     ");
		}
			   	if (placeValipass < 30)
	    	gotoxy(83 + placeValipass, 30); else gotoxy(113,30);
			   inputValipass(valipass);
			   break;
            }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 72) 
			{
			   gotoxy(placeUser + 83, 22);
			   inputUsername(userName);
			   break;
            } else if (ch == 80) 
			{
					 if (strcmp(pwd,tmp) == 0) {
	        	gotoxy(83,28);
	        	changeColore(4);
	        	printf("Password must not be blank!!");
	        	changeColore(7);
	        	gotoxy(83,26);
	        	inputPassword(pwd);
	        	break;
			} 
			else 
			{
			gotoxy(83,28);
			printf("                                     ");}
			 	if (placeValipass < 30)
	    	gotoxy(83 + placeValipass, 30); else gotoxy(113,30);
			   inputValipass(valipass);
			   break;
            }
	    	ch = 224;
		}
	    else if (ch != 224)
	    {
	    	if (placePass < 30)
		    putchar('*');/* char - '*' will be printed instead of the character */
		    pwd[placePass] = ch;
		    placePass++;
	    }
	}
	pwd[placePass] = '\0';
}
void inputValipass(char pwd[500]){
	int ch;
	while(1)
	{
	    ch = getch();
	    if(ch == 13){
	    fflush(stdin);
		if (strcmp(valipass, password) != 0)
  		{
			  gotoxy(83,32);
			  changeColore(4);
			  printf("Your password must be the same!!");
			  	if (placePass < 30)
	    	gotoxy(83 + placePass, 26); else gotoxy(113,26);
			  changeColore(7);
			  inputPassword(password);
		}
	    break;
	}
	    else if(ch == 8)
	    {       if(placeValipass != 0 ) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	        	if (placeValipass < 31)
	        	{
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	        }
	            placeValipass--;
	            pwd[placeValipass] = '\0';
	        }
 
	    }
	    else if (ch == 9) 
			{
			   	if (placePass < 30)
	    	gotoxy(83 + placePass, 26); else gotoxy(113,26);
			   inputPassword(password);
			   break;
            }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 13) 
			{
 		
				break;
			}
	    	if (ch == 72) 
			{
			  	if (placePass < 30)
	    	gotoxy(83 + placePass, 26); else gotoxy(113,26);
			   inputPassword(password);
			   break;
            }
	    	ch = 224;
		}
	    else if (ch != 224)
	    {
	    	if (placeValipass < 30)
		    putchar('*');/* char - '*' will be printed instead of the character */
		    pwd[placeValipass] = ch;
		    placeValipass++;
	    }
	}
	pwd[placeValipass] = '\0';
}
void inputUser(char uid[500]){
	int ch;
	int flag = 0;
	while(1)
	{
	    ch = getch();
	    if (placeUser > 27  )
		{	 
			 gotoxy(60, 24);
			 printf("Your username must be length from 5 - 30 characters.");
			 gotoxy(placeUser + 77, 22);
			 flag = 1;
		}
		else if (flag == 1)
		{
				gotoxy(60, 24);
			 printf("                                                    ");
			 gotoxy(placeUser + 77, 22);
			 flag = 0;
 	 }
	    if(ch == 13 || ch == 9)
	    {
	    	if (placePass < 30)
	    	gotoxy(77 + placePass, 26); 
	    	else gotoxy(107, 26);
	    	hidePassword(pwd);
	 	    break;
	    
		}	
	    else if(ch == 8)
	    {       if(placeUser != 0) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	            placeUser--;
	            uid[placeUser] = '\0';
	        }
	        else
	        continue;
	    }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 80) 
			{
			   if (placePass < 30)
			   gotoxy(77 + placePass, 26);
			   else gotoxy(107, 26);
			   hidePassword(pwd);
			   break;
            }
	    	ch = 224;
		}
	    else if (ch != 224 && placeUser < 30)
	    {
		    putchar(ch);/* char - '*' will be printed instead of the character */
		    uid[placeUser] = ch;
		    placeUser++;
	    }
	}
	uid[placeUser] = '\0';
}
void hidePassword(char pwd[500]){
	int ch;
	while(1)
	{
	    ch = getch();
	    if(ch == 13){
	    fflush(stdin);	
	    break;
	}
	    else if(ch == 8)
	    {       if(placePass != 0 ) /*this is for avoiding the ENTER instructions getting deleted */
	        {
	        	if (placePass < 31)
	        	{
	            printf("\b");  /*printing backspace to move cursor 1 pos back*/
	            printf("%c",32);/*making the char invisible which is already on console*/
	            printf("\b"); /*printing backspace to move cursor 1 pos back*/
	        }
	            placePass--;
	            pwd[placePass] = '\0';
	        }
 
	    }
	    else if (ch == 9) 
			{
			   gotoxy(placeUser + 77, 22);
			   inputUser(uid);
			   break;
            }
	    else if (ch == 0 || ch == 224) 
 	   {
	    	fflush(stdin);
	    	ch = getch();
	    	if (ch == 13) break;
	    	if (ch == 72) 
			{
			   gotoxy(placeUser + 77, 22);
			   inputUser(uid);
			   break;
            }
	    	ch = 224;
		}
	    else if (ch != 224)
	    {
	    	if (placePass < 30)
		    putchar('*');/* char - '*' will be printed instead of the character */
		    pwd[placePass] = ch;
		    placePass++;
	    }
	}
	pwd[placePass] = '\0';
}
void cutElement(char str[1000], int index){
    const char s[5] = "*||*";
    char *token;
    token = strtok(str, s);
    strcpy(user[index].fullName, token);
    token = strtok(NULL, s);
    strcpy(user[index].userName, token);
    token = strtok(NULL, s);
    strcpy(user[index].password, token);
    token = strtok(NULL, s);
    user[index].key = index;
}
void generateAccount(){
	FILE *fp;
	char tmp[]=" ";
    fp = fopen("User.txt", "a+");
    showCursor();
 	gotoxy(83,18);
    inputFullname(fullName);
    processing(fullName);
    processing(userName);
    processing(password);
   	numOfuser++;
    strcat(fullName, userName);
    strcat(fullName, password);
    fprintf(fp, "%s\n",fullName);
    printf("number of user: %d", numOfuser);
    keyUser = numOfuser - 1;
    findDate();
	printfStart(); 
    fclose(fp);
}
void inputAccount() 
{	
	int i = 0;
	char str[1000], tmp[1000], c;
	FILE *fp = fopen("User.txt", "r");
	while(fgets(tmp,1000,fp))
	 {
	 	strcpy(str,tmp);
	 	cutElement(str, i);
	 	i++;
	 }
	 numOfuser = i + 1;
	fclose(fp);
}
void authentication(char userID[500], char password[100])
{
	int flag = 0;
	for(int i = 0; i < numOfuser; i++)
	{
	    if((strcmp(userID, user[i].userName) == 0) && (strcmp(password, user[i].password) == 0))
	    {
	        flag = 1;
	        keyUser = i;
	        break;
	    }
	}
	fflush(stdin);
	if(flag) {
		system("cls");
		Nocursortype();
		//findDate();
   		//printfStart(); 
   		chooseBeorCa();
	}
	else 
	{
		
		gotoxy(79,29);
		changeColore(4);
		printf("Wrong username or password.");
		changeColore(7);
		if (placePass < 30)
		gotoxy(placePass +77, 26); else gotoxy(107,26);
		hidePassword(pwd);
		fflush(stdin);
		authentication(uid, pwd);
	}
	getch();
}
void login()
{
	int i, counter = 0, flag = 0;
	loginFrame();
	showCursor();
	placePass = 0;
	placeUser = 0;
	pwd[0] ='\0';
	/*dummy character in ch */
	gotoxy(77,22);
	inputUser(uid);
	authentication(uid, pwd);
}
//-------Frame-------
void fCalendar() {

	changeColore(6);
	gotoxy(4, 4);
	printf(" .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------. \n");
	gotoxy(4, 5);
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	gotoxy(4, 6);
	printf("| |     ______   | || |      __      | || |   _____      | || |  _________   | || | ____  _____  | || |  ________    | || |      __      | || |  _______     | |\n");
	gotoxy(4, 7);
	printf("| |   .' ___  |  | || |     /  \\     | || |  |_   _|     | || | |_   ___  |  | || ||_   \\|_   _| | || | |_   ___ `.  | || |     /  \\     | || | |_   __ \\    | |\n");
	gotoxy(4, 8);
	printf("| |  / .'   \\_|  | || |    / /\\ \\    | || |    | |       | || |   | |_  \\_|  | || |  |   \\ | |   | || |   | |   `. \\ | || |    / /\\ \\    | || |   | |__) |   | |\n");
	gotoxy(4, 9);
	printf("| |  | |         | || |   / ____ \\   | || |    | |   _   | || |   |  _|  _   | || |  | |\\ \\| |   | || |   | |    | | | || |   / ____ \\   | || |   |  __ /    | |\n");
	gotoxy(4, 10);
	printf("| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |   _| |__/ |  | || |  _| |___/ |  | || | _| |_\\   |_  | || |  _| |___.' / | || | _/ /    \\ \\_ | || |  _| |  \\\ \\_  | |\n");
	gotoxy(4, 11);
	printf("| |   `._____.'  | || ||____|  |____|| || |  |________|  | || | |_________|  | || ||_____|\\____| | || | |________.'  | || ||____|  |____|| || | |____| |___| | |\n");
	gotoxy(4, 12);
	printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n");
	gotoxy(4, 13);
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	gotoxy(4, 14);
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n ");
	changeColore(6);
}	
void drawAbout(){
	gotoxy(66,17);
	printf("Group 4:");
	gotoxy(66,18);
	printf(" Nguyen Tran Thien Duc a.k.a Kha' Duc'\n");
	gotoxy(66,19);
	printf(" Nguyen Quang Hung     a.k.a Hung Ricardo\n");
	gotoxy(66,20);
	printf(" Phan Thanh Phuc       a.k.a Phuc Phan \n");
	gotoxy(66, 21);
	printf("Mentor:");
	gotoxy(67, 22);
	printf(" Luu Dieu Hoa          a.k.a Bong Hoa  ");
	gotoxy(78, 23);
	printf(" Thank you ");
	fflush(stdin);
	textColor(68);
    gotoxy(35,5);
	printf("          "); 
	textColor(204);
	gotoxy(35,6); 
	printf("          ");
	textColor(17);
	gotoxy(35,7);
	printf("    ");
	textColor(151);
	gotoxy(35,8);
	printf("    ");
	textColor(51);
	gotoxy(35,9);
	printf("        ");
	textColor(187);
	gotoxy(35,10);
	printf("        ");
	textColor(238);
	gotoxy(35,11);
	printf("    ");
	textColor(119);
	gotoxy(35,12);
	printf("    ");
	textColor(258);
	gotoxy(35,13);
	printf("    ");
	textColor(68);
    gotoxy(50,5);
	printf("          "); 
	textColor(204);
	gotoxy(50,6); 
	printf("   ");
	gotoxy(57,6); 
	printf("   ");
	textColor(17);
	gotoxy(50,7);
	printf("   ");
	gotoxy(57,7);
	printf("   ");
	textColor(151);
	gotoxy(50,8);
	printf("   ");
	gotoxy(53,8);
	printf("       ");
	textColor(51);
	gotoxy(50,9);
	printf("   ");
	textColor(187);
	gotoxy(50,10);
	printf("   ");
	textColor(238);
	gotoxy(50,11);
	printf("   ");
	textColor(119);
	gotoxy(50,12);
	printf("   ");
	textColor(258);
	gotoxy(50,13);
	printf("   ");
	textColor(68);
    gotoxy(65,5);
	printf("           "); 
	textColor(204);
	gotoxy(65,6); 
	printf("           ");
	textColor(17);
	gotoxy(69,7);
	printf("   ");
	textColor(151);
	gotoxy(69,8);
	printf("   ");
	textColor(51);
	gotoxy(69,9);
	printf("   ");
	textColor(187);
	gotoxy(69,10);
	printf("   ");
	textColor(238);
	gotoxy(69,11);
	printf("   ");
	textColor(119);
	gotoxy(69,12);
	printf("   ");
	textColor(258);
	gotoxy(69,13);
	printf("   ");
	changeColore(7);
	getch();
	
}
void frameChooseInNote() {
    gotoxy(110, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(110, 22);
	printf("%c                              %c", 179, 179);
	gotoxy(110, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

	gotoxy(110, 25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(110, 26);
	printf("%c                              %c", 179, 179);
	gotoxy(110, 27);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

	gotoxy(110, 29);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(110, 30);
	printf("%c                              %c", 179, 179);
	gotoxy(110, 31);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	

}
void coverFrame() {	
	for(int num = 1; num < 167; num++) {
		gotoxy(num, 0);
		printf("%c", 220);
		gotoxy(num, 43);
		printf("%c", 223);
	}
	for(int num = 1; num < 43; num++) {
		gotoxy(1, num);
		printf("%c", 221);
		gotoxy(166, num);
		printf("%c", 222);
	}
}
void loginFrame() {
	gotoxy(61, 22);
	printf("USERNAME  :");
	gotoxy(61, 26);
	printf("PASSWORD  :");
	gotoxy(76, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(76, 22);
	printf("%c                              %c", 179, 179);
	gotoxy(76, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
    gotoxy(76, 25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(76, 26);
	printf("%c                              %c", 179, 179);
	gotoxy(76, 27);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196,196,196,196,196,196,196,196,196,196,196,196 ,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}
void registration() {
	gotoxy(61, 18);
	printf("   FULLNAME       :");
	gotoxy(61, 22);
	printf("   USERNAME       :");
	gotoxy(61, 26);
	printf("   PASSWORD       :");
	gotoxy(61, 30);
	printf("   PASSWORD AGAIN :");
	
	gotoxy(82, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);	
	gotoxy(82, 18);
	printf("%c                              %c", 179, 179);
	gotoxy(82, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
   
    gotoxy(82, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(82, 22);
	printf("%c                              %c", 179, 179);
	gotoxy(82, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

	gotoxy(82, 25);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(82, 26);
	printf("%c                              %c", 179, 179);
	gotoxy(82, 27);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	gotoxy(82, 29);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(82, 30);
	printf("%c                              %c", 179, 179);
	gotoxy(82, 31);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}
void printStartFrame() {
	fCalendar();
	changeColore(7);
	Nocursortype();
	 gotoxy(68, 19);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(68, 20);
	printf("%c                              %c", 179, 179);
	gotoxy(68, 21);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

	gotoxy(68, 24);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(68, 25);
	printf("%c                              %c", 179, 179);
	gotoxy(68, 26);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);

	gotoxy(68, 29);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196,196,196,196,196,196,196,196,196,196,196, 196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191);
	gotoxy(68, 30);
	printf("%c                              %c", 179, 179);
	gotoxy(68, 31);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196,196,196,196,196,196, 196,196, 196,196,196,196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
	
	gotoxy(77, 20);
	changeColore(2);
	printf("    LOGIN   ");
	gotoxy(77, 25);
	changeColore(7);
	printf(" REGISTRATION");
	gotoxy(77, 30);
	printf("    ABOUT  ");
}

void upDownStartFrame() {
	int checkKey = 0;
	while(1) {
		char key = getch();
		if(key == 27) { // For ESC
            break;
    	}
		if(key == 72) {
			checkKey = checkKey - 1;
		}
		if(key == 80) {
			checkKey = checkKey + 1;
		}
		if(checkKey < 0) {
			checkKey = 0;
		}
		if(checkKey > 2) {
			checkKey = 2;
		}
		if(key == 13) {
    		switch(checkKey) {
    			case 0:
    				system("cls");
   			 		coverFrame();
    				loginFrame();
    				login();
    				break;
    			case 1:
    				system("cls");
    				coverFrame();
    				registration();
    				generateAccount();
    				break;	
    			case 2:
					system("cls");
    				coverFrame();
    				drawAbout();
    			//	sumCalendar();
    				system("cls");
    				coverFrame();
    			    printStartFrame();
					upDownStartFrame();
    				break;
			}
			break;
		} else { 
			if(checkKey == 0) {
				gotoxy(77, 20);
				changeColore(2);
				printf("    LOGIN   ");
				gotoxy(77, 25);
				changeColore(7);
				printf(" REGISTRATION");
				gotoxy(77, 30);
				printf("    ABOUT ");			
			}
			if(checkKey == 1) {
				gotoxy(77, 25);
				changeColore(2);
				printf(" REGISTRATION");
				gotoxy(77, 20);
 				changeColore(7);
				printf("    LOGIN   ");
				gotoxy(77, 30);
				printf("    ABOUT  ");
			}
			if(checkKey == 2) {		
				gotoxy(77, 30);
				changeColore(2);
				printf("    ABOUT  ");
				gotoxy(77, 20);
				changeColore(7);
				printf("    LOGIN   ");
				gotoxy(77, 25);
				printf(" REGISTRATION");
			}
		} 	
	}
}
//-------draw choose-------
void chooseCalendar() {
	gotoxy(60, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(60, 18);
	printf("%c          %c", 221, 222);
	gotoxy(60, 19);
	printf("%c          %c", 221, 222);
	gotoxy(60, 20); 
	printf("%c          %c", 221, 222);
	gotoxy(60, 21);
	printf("%c          %c", 221, 222);
	gotoxy(60, 22);
	printf("%c          %c", 221, 222);
	gotoxy(60, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	
	gotoxy(62, 19);
	printf("%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(62, 20);
	printf("%c%c%c%c%c%c%c%c", 221, 197, 197, 197, 197, 197, 197, 222);
	gotoxy(62, 21);
	printf("%c%c%c%c%c%c%c%c", 221, 197, 197, 197, 197, 197, 197, 222);
	gotoxy(62, 22);
	printf("%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223);
	
	gotoxy(62, 24);
	printf("CALENDAR");
}

void chooseBeenTogether() {
	changeColore(7);
	gotoxy(90, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(90, 18);
	printf("%c          %c", 221, 222);
	gotoxy(90, 19);
	printf("%c          %c", 221, 222);
	gotoxy(90, 20); 
	printf("%c          %c", 221, 222);
	gotoxy(90, 21);
	printf("%c          %c", 221, 222);
	gotoxy(90, 22);
	printf("%c          %c", 221, 222);
	gotoxy(90, 23);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	
	gotoxy(94, 19);
	printf(" %c %c", 42, 42);
	gotoxy(94, 20);
	printf("%c%c%c%c%c", 42, 42, 42, 42, 42);
	gotoxy(94, 21);
	printf(" %c%c%c", 42, 42, 42);
	gotoxy(94, 22);
	printf("  %c", 42);
	
	gotoxy(92, 24);
	printf("  BEEN");
	gotoxy(92, 25);
	printf("TOGETHER");
}

void tutorial() {
	for(int num = 4; num < 42; num++) {
		gotoxy(num, 31);
		printf("%c", 223);
		gotoxy(num, 41);
		printf("%c", 220);
	} 
	for(int num = 31; num < 42; num++) {
		gotoxy(3, num);
		printf("%c", 222);
		gotoxy(41, num);
		printf("%c", 221);
	}
	
	gotoxy(17, 32);
	printf("TUTORIAL");
	gotoxy(7, 34);
	printf("USE KEY FROM KEYBOARD:");
	gotoxy(7, 35);
	printf("  LEFT / RIGHT    -->   MOVE");
	gotoxy(7, 36);
	printf("  ENTER           -->   CHOOSE");
	gotoxy(7, 37);
	printf("  ESC             -->   LOG OUT");

}

void returnTutorial() {
	gotoxy(157, 40);
	printf("%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(157, 41);
	printf("%cRETURN %c", 221, 222);
	gotoxy(157, 42);
	printf("%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223);	
}
int isBreakUp(){
	FILE *fp;
	fp = fopen("Ex.dat", "rb");
	while (fread(&Ex, sizeof(Ex),1,fp) == 1){
		if ( L.key == Ex.key && strcmp(L.lover, Ex.lover) == 0)
		return 1;
	}
	return 0;
}
void breakUp(){
	FILE *fp;
	fp = fopen("Ex.dat","ab+");
 	fwrite(&L, sizeof(L),1,fp);
 	fclose(fp);
}
void isLover(){
	FILE *fp;
	fp = fopen("Lovestory.dat","rb");
	haveLove = 0;
	while(fread(&L,sizeof(L),1,fp) == 1){
		if ((L.key == keyUser) && (isBreakUp() == 0)) {
			haveLove = 1;
			break;
		}
	}
	fclose(fp);
	
}
void moveReturnTutorial() {
	returnTutorial();
	gotoxy(159, 41);
	changeColore(1);
	printf("RETURN");
	while(1) {
		char key = getch();
		if(key == 72 ) {
			changeColore(7);
			system("cls");
			chooseBeorCa();
		}
	}	
}

void moveChooseBeOrCa() {
	changeColore(1);
	for(int num = 58; num < 74; num++) {
		gotoxy(num , 16);
		printf("%c", 220);
		gotoxy(num, 26);
		printf("%c", 223);
	}
	for(int num = 17; num < 26; num++) {
		gotoxy(58 , num);
		printf("%c", 221);
		gotoxy(73, num);
		printf("%c", 222);
	}
	
	int row = 58;
	int check = 0;
	while(1) {
		char key = getch();
		
		if(key == 77) {
			if(row != 88) {
				row = row + 30;
				check = check + 1;
				
				changeColore(0);
				for(int num = row - 30; num < row - 14; num++) {
					gotoxy(num , 16);
					printf("%c", 220);
					gotoxy(num, 26);
			 		printf("%c", 223);
				}
				for(int num = 17; num < 26; num++) {
					gotoxy(row - 30 , num);
					printf("%c", 221);
					gotoxy(row - 15, num);
					printf("%c", 222);
				}				
			} 
		}	
		if(key == 75) {
			if(row != 58) {
				row = row - 30;
				check = check - 1;
			
				changeColore(0);
				for(int num = row + 30; num < row + 46; num++) {
					gotoxy(num , 16);
					printf("%c", 220);
					gotoxy(num, 26);		
 					printf("%c", 223);
				}
				for(int num = 17; num < 26; num++) {
					gotoxy(row + 30 , num);
					printf("%c", 221);
					gotoxy(row + 45, num);
					printf("%c", 222);
				} 
			}
		}
		
		if(check > 1 ) {
			check = 1;
		}
		if(check < 0) {
			check = 0;
		}
		
		if(key == 13) {
			switch(check) {
	            case 0: 
	            	 system("cls");
	            	 changeColore(7);
	            	 findDate();
	 	             printfStart(); 
					 break;
				case 1:
					isLover();
					if (haveLove == 0) {
						checkHave();
					} else {
						system("cls");
						beenTogether();
					}
					break;
			}
		}
		if (key == 27) {
			changeColore(7);
			system("cls");
			coverFrame();
			printStartFrame();
			upDownStartFrame();
			break;
		} 
		changeColore(1);	
		for(int num = row; num < row + 16; num++) {
			gotoxy(num , 16);
			printf("%c", 220);
			gotoxy(num, 26);
			printf("%c", 223);
		}
		for(int num = 17; num < 26; num++) {
			gotoxy(row , num);
			printf("%c", 221);
			gotoxy(row + 15, num);
			printf("%c", 222);
		}	
	}
}

//--------draw heart------
void drawHeart1() {
	gotoxy(68, 12);
	printf("    %c%c%c%c                ", 219, 219, 219, 219);
	gotoxy(68, 13);
	printf("   %c%c%c%c%c%c               ", 219, 219, 219, 219, 219, 219);
	gotoxy(68, 14);
	printf("  %c%c%c%c%c%c%c%c              ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 15);
	printf(" %c%c%c%c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 18);
	printf(" %c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 19);
	printf("  %c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 20);
	printf("   %c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 21);
	printf("    %c%c%c%c%c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 22);
	printf("     %c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219);
	gotoxy(68, 23);
	printf("      %c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219);
	gotoxy(68, 24);
	printf("       %c%c%c%c%c             ", 219, 219, 219, 219, 219);
	gotoxy(68, 25);
	printf("        %c%c%c%c             ", 219, 219, 219, 219);
	gotoxy(68, 26);
	printf("         %c%c%c             ", 219, 219, 219);
	gotoxy(68, 27);
	printf("          %c%c             ", 219, 219);
	gotoxy(68, 28);
	printf("           %c             ", 219);
}

void drawHeart2() {
	gotoxy(80, 12);
	printf("    %c%c%c%c    ", 219, 219, 219, 219);
	gotoxy(80, 13);
	printf("   %c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219);
	gotoxy(80, 14);
	printf("  %c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 15);
	printf(" %c%c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 18);
	printf("%c%c%c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 19);
	printf("%c%c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 20);
	printf("%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 21);
	printf("%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 22);
	printf("%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219);
	gotoxy(80, 23);
	printf("%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219);
	gotoxy(80, 24);
	printf("%c%c%c%c%c      ", 219, 219, 219, 219, 219);
	gotoxy(80, 25);
	printf("%c%c%c%c        ", 219, 219, 219, 219);
	gotoxy(80, 26);  
	printf("%c%c%c         ", 219, 219, 219);
	gotoxy(80, 27);
	printf("%c%c          ", 219, 219);
	gotoxy(80, 28);
	printf("%c           ", 219);
}
//-------edit been together------
void dayBeen() {
	gotoxy(68, 7);
	printf("Memorable day: %d/%d/%d",L.day,L.month,L.year);
	gotoxy(68, 8);
	changeColore(7);
	findDate();
	printf("Been Together: %d days", countDay(L.day, L.month, L.year, day, month, year));
}

void nameBeen() {
	gotoxy(31, 16);
	changeColore(14);
	printf("YOU");
	gotoxy(25, 17);
	changeColore(11);
	printf("%s", user[keyUser].fullName);
	changeColore(14);
	gotoxy(117,16);
	printf("Your Darling");
	changeColore(11);
	gotoxy(115, 17);
	printf("%s", L.lover);
	
}

void moveEdit() {
	gotoxy(116, 17);
	getch();
	char key = getch();
	if(key == 13) {
		system("cls");
		beenTogether();
	}
	if(key == 72) {
		gotoxy(83, 7);
	}
}

void drawFramesChoose() {
	changeColore(7);
	gotoxy(54, 34);
	printf("%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(54, 35);
	printf("%c        %c", 221, 222);
	gotoxy(54, 36);
	printf("%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);

	gotoxy(79, 34);
	printf("%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(79, 35);
	printf("%c        %c", 221, 222);
	gotoxy(79, 36);
	printf("%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);

	gotoxy(104, 34);
	printf("%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(104, 35);
	printf("%c        %c", 221, 222);
	gotoxy(104, 36);
	printf("%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
}

void wordInchoose() {
	gotoxy(55, 35);
	printf("  MUSIC ");
	gotoxy(80, 35);
	printf(" BROKEUP");
	gotoxy(105, 35);
	printf(" RETURN ");
}

void moveChoose() {
	changeColore(7);
	drawFramesChoose();
	changeColore(30);
	gotoxy(54, 34);
	printf("%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(54, 35);
	printf("%c        %c", 221, 222);
	gotoxy(54, 36);
	printf("%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	changeColore(7);
	wordInchoose();
	
	int num = 0;
	int row = 54;
	while(1) {
		char key = getch();
		if(key == 77) {
			if(row != 104) {
				row = row + 25;
				num = num + 1;
			} 
		}
		if(key == 75) {
			if(row != 54) {
			row = row - 25;
			num = num - 1;
			} 
		}
		
		if(num > 2 ) {
			num = 2;
		}
		if(num < 0) {
			num = 0;
		}
		
		if(key == 13) {
			switch(num) {
				case 0: 
					PlaySound(TEXT("beep.wav"),NULL,SND_SYNC);
					break;	
				case 1:
					breakUp();
					fflush(stdin);
					changeColorHeart();
					break;
				case 2:
					exitBeen();
					break;
			}
		}
		
		changeColore(7);
		drawFramesChoose();
		changeColore(30);
		gotoxy(row, 34);
		printf("%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
		gotoxy(row, 35);
		printf("%c        %c", 221, 222);
		gotoxy(row, 36);
		printf("%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
		changeColore(7);
		wordInchoose();	
	}
}

void changeColorHeart() {
changeColore(7);
	drawHeart1();
	drawHeart2();
	
	Sleep(700);
	
	int heart1 = 58;
	gotoxy(heart1, 12);
	printf("    %c%c%c%c                ", 219, 219, 219, 219);
	gotoxy(heart1, 13);
	printf("   %c%c%c%c%c%c               ", 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 14);
	printf("  %c%c%c%c%c%c%c%c              ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 15);
	printf(" %c%c%c%c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 18);
	printf(" %c%c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 19);
	printf("  %c%c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 20);
	printf("   %c%c%c%c%c%c%c%c%c            ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 21);
	printf("    %c%c%c%c%c%c%c%c           ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 22);
	printf("     %c%c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 23);
	printf("      %c%c%c%c%c%c             ", 219, 219, 219, 219, 219, 219);
	gotoxy(heart1, 24);
	printf("       %c%c%c%c%c             ", 219, 219, 219, 219, 219);
	gotoxy(heart1, 25);
	printf("        %c%c%c%c             ", 219, 219, 219, 219);
	gotoxy(heart1, 26);
	printf("         %c%c%c             ", 219, 219, 219);
	gotoxy(heart1, 27);
	printf("          %c%c             ", 219, 219);
	gotoxy(heart1, 28);
	printf("           %c             ", 219);
	changeColore(4);
	int heart2 = 90;
		PlaySound(TEXT("break.wav"),NULL,SND_SYNC);
	gotoxy(heart2, 12);
	printf("    %c%c%c%c    ", 219, 219, 219, 219);
	gotoxy(heart2, 13);
	printf("   %c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 14);
	printf("  %c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 15);
	printf(" %c%c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 16);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 17);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 18);
	printf("%c%c%c%c%c%c%c%c%c%c%c ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 19);
	printf("%c%c%c%c%c%c%c%c%c%c  ", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 20);
	printf("%c%c%c%c%c%c%c%c%c   ", 219, 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 21);
	printf("%c%c%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 22);
	printf("%c%c%c%c%c%c%c     ", 219, 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 23);
	printf("%c%c%c%c%c%c    ", 219, 219, 219, 219, 219, 219);
	gotoxy(heart2, 24);
	printf("%c%c%c%c%c      ", 219, 219, 219, 219, 219);
	gotoxy(heart2, 25);
	printf("%c%c%c%c        ", 219, 219, 219, 219);
	gotoxy(heart2, 26);  
	printf("%c%c%c         ", 219, 219, 219);
	gotoxy(heart2, 27);
	printf("%c%c          ", 219, 219);
	gotoxy(heart2, 28);
	printf("%c           ", 219);
	
	Sleep(200);
	changeColore(7);
	system("cls");
	chooseBeorCa();	
}	
// Do you have boigirl fen
void drawCheckHave() {
	changeColore(1);
	for(int num1 = 50; num1 < 110; num1++) {
		for(int num2 = 15; num2 < 25; num2++) {
			gotoxy(num1, num2);
			printf("%c", 219);
		}
	}
	changeColore(30);
	gotoxy(65, 17);
	printf("DO YOU HAVE BOY OR GIRL FRIEND?");
}

void framesCheckHave() {
	gotoxy(65, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(65, 21);
	printf("%c          %c", 221, 222);
	gotoxy(65, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);

	gotoxy(85, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(85, 21);
	printf("%c          %c", 221, 222);
	gotoxy(85, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
}

void wordInCheckHave() {
	gotoxy(70, 21);
	printf("YES");
	gotoxy(90, 21);
	printf("NO");
}
// input your darling's name and the day you fall in love
void printSTR()
{
    checkDoneStr = 0; // neu = 1 thi sai, thoat luon, neu van bang 0 thi dung
    int lenth, check = 0, save = 0, s;
    monthOne=0; dayOne=0; yearOne=0;
    lenth = strlen(str);
    for (int i = 0; i < lenth; i++)
    {
        if ( (!( (str[i]>='0')&&(str[i]<='9'))) && (str[i] != ' ') )
            {
                checkDoneStr = 1;
                return;
            }
    }
    int thuTu = 0;
    for (int i = 0; i < lenth; i++)
    {
        if ( str[i] >= '0' && str[i] <= '9' )
            {
                s = str[i];
                s = s - 48;
                save = save * 10 + s;
                check = 1;
                
            }
        if ( (str[i] == ' ') && ( thuTu == 0 ) && (check == 1) )
          {
                dayOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
        else if ( (str[i] == ' ') && ( thuTu == 1 ) && (check == 1) )
          {
                monthOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
        else if ( (str[i] == ' ') && ( thuTu == 2 ) && (check == 1) )
          {
                yearOne = save;
                save = 0;
                check = 0;
                thuTu = thuTu + 1;
          }
         if (thuTu == 3)
           break;
    }
    yearOne = save;
}
void printValidLove()
{

    checkInvalid = 0;
    if (checkDoneStr == 1)
        {
                gotoxy(60,14);
               printf("Please press number.");
               checkInvalid = 1;
            return ;
        }
    else if ( (monthOne < 1) || (monthOne > 12) )
        {
            
            gotoxy(60,14);
            printf("Invalid month. Please press 1 <= month <= 12.");
            checkInvalid = 1;
            return ;
        }
    else if (dayOne <= 0)
        {
            gotoxy(60,14);
            printf("Invalid day. Please press 1 <= day <= 31.");
            checkInvalid = 1;
            return;
        }
    else if (yearOne <= 0)
        {
            gotoxy(60,14);
            printf("Invalid year. Please press year again.");
            checkInvalid = 1;
            return;
        }
    else if (dayOne > 31)
        {
            gotoxy(60,14);
            printf("Invalid day. Please press 1 <= day <= 31.");
            checkInvalid = 1;
            return;
        }
    else if ( (leapYear(yearOne) == 1) && (monthOne == 2) && ( dayOne > 29 ) )
       {
               gotoxy(60,14);
            printf("Leap Year have 29 days one February.");
               checkInvalid = 1;
            return ;
       }
    else if ( (leapYear(yearOne) == 0) && (monthOne == 2) && ( dayOne > 28 ) )
       {
               gotoxy(60,14);
               printf("If is not leap year, February have 28 days.");
               checkInvalid = 1;
            return ;
       }
    else if ( ( checkMon(monthOne) == 0) && ( dayOne > 30 ) )
       {
               gotoxy(60,14);
               printf("April, June, September, November have 30 days");
               checkInvalid = 1;
            return ;
        }
}

void loveStory() {
	coverFrame();
	showCursor();
	 FILE *fp;
    fp = fopen("Lovestory.dat","ab+");
	gotoxy(60,11);
	printf("Enter your darling name: ");
	scanf("%[^\n]",L.lover);
	gotoxy(60,12);
	printf("Enter the day you fall in love (DD MM YYYY): ");
    fflush(stdin);
    scanf("%[^\n]s", &str);
    printSTR();
    printValidLove();
     while (checkInvalid == 1)
        {
            gotoxy(60,13);
            printf("Press any key for again or press ESC to quit.");
            textColor(0);
            gotoxy(105,12);
            printf("                                     ");
            textColor(15);
            gotoxy(125,16);
            char sa;
            fflush(stdin);
            Nocursortype();
            sa = getch();
            if (sa == 27)
                {
                	system("cls");
                	chooseBeorCa();
				    break;
			    }
			else
			{
			showCursor();
            fflush(stdin);
            gotoxy(105,12);
            scanf("%[^\n]s", &str);
            printSTR();
            printValidLove();
            }
        }
   L.day = dayOne;
   L.month = monthOne;
   L.year  = yearOne;
   L.key = keyUser;
   fwrite(&L,sizeof(L),1,fp);
	textColor(0);
    gotoxy(118,18);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,16);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(120,15);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	gotoxy(120,19);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    gotoxy(119,20);
    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  	fclose(fp);
    Nocursortype();
	checkThird = 1; // =1 la co su dung cai so 3, bang 0 la ko su dung
	system("cls");
    beenTogether();
	
    
        
	
}
void moveChooseCheckHave() {
	changeColore(30);
	framesCheckHave();
	changeColore(10);
	gotoxy(65, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(65, 21);
	printf("%c          %c", 221, 222);
	gotoxy(65, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	changeColore(30);
	wordInCheckHave();
	
	int num = 0;
	int row = 65;
	while(1) {
		char key = getch();
		if(key == 77) {
			if(row != 85) {
				row = row + 20;
				num = num + 1;
			} 
		}
		if(key == 75) {
			if(row != 65) {
			row = row - 20;
			num = num - 1;
			} 
		}
		
		if(num > 1 ) {
			num = 1;
		}
		if(num < 0) {
			num = 0;
		}
		
		if(key == 13) {
			switch(num) {
				case 0:
					changeColore(7);
					system("cls");
					//beenTogether();
					loveStory();
					break;
				case 1:
					PlaySound(TEXT("co don.wav"),NULL,SND_SYNC);
			        changeColore(7);
					system("cls");
					chooseBeorCa();
					break;
			}
			break;
		}
		changeColore(30);
		framesCheckHave();
		
		changeColore(10);
		gotoxy(row, 20);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
		gotoxy(row, 21);
		printf("%c          %c", 221, 222);
		gotoxy(row, 22);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
		changeColore(30);
		wordInCheckHave();
	}		
}

void checkHave() {
	Nocursortype();
	changeColore(7);
	drawCheckHave();
	framesCheckHave();
	wordInCheckHave();
	moveChooseCheckHave();
}
//---------exit been--------
void drawExitbeen() {
	changeColore(1);
	for(int num1 = 50; num1 < 110; num1++) {
		for(int num2 = 15; num2 < 25; num2++) {
			gotoxy(num1, num2);
			printf("%c", 219);
		}
	}
	changeColore(30);
	gotoxy(72, 17);
	printf("WHAT DO YOU WANT?");
}

void framesExit() {
	gotoxy(57, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(57, 21);
	printf("%c          %c", 221, 222);
	gotoxy(57, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
		
	gotoxy(74, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(74, 21);
	printf("%c          %c", 221, 222);
	gotoxy(74, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);

	gotoxy(91, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(91, 21);
	printf("%c          %c", 221, 222);
	gotoxy(91, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
}

void wordInExitBeen() {
	gotoxy(60, 21);
	printf("LOG OUT");
	gotoxy(77, 21);
	printf("RETURN");
	gotoxy(94, 21);
	printf("CANCEL");
}

void moveChooseExitBeen() {
	changeColore(30);
	framesExit();
	changeColore(10);
	gotoxy(57, 20);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
	gotoxy(57, 21);
	printf("%c          %c", 221, 222);
	gotoxy(57, 22);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
	changeColore(30);
	wordInExitBeen();
	
	int num = 0;
	int row = 57;
	while(1) {
		char key = getch();
		if(key == 77) {
			if(row != 91) {
				row = row + 17;
				num = num + 1;
			} 
		}
		if(key == 75) {
			if(row != 57) {
			row = row - 17;
			num = num - 1;
			} 
		}
		
		if(num > 2 ) {
			num = 2;
		}
		if(num < 0) {
			num = 0;
		}
		
		if(key == 13) {
			switch(num) {
				case 0:
					changeColore(7);
					system("cls");
					coverFrame();
					printStartFrame();
					upDownStartFrame();
					break;
					break;
				case 1:
					changeColore(7);
					system("cls");
					chooseBeorCa();
					break;
				case 2:
					changeColore(7);
					system("cls");
					coverFrame();
					beenTogether();
					break;
			}
		}
		
		changeColore(30);
		framesExit();
		
		changeColore(10);
		gotoxy(row, 20);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c", 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220, 220);
		gotoxy(row, 21);
		printf("%c          %c", 221, 222);
		gotoxy(row, 22);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c", 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223, 223);
		
		changeColore(30);
		wordInExitBeen();
	}		
}

//------sum-----
void chooseBeorCa() {
	coverFrame();
	tutorial();
//	returnTutorial();
	chooseCalendar();
	chooseBeenTogether();
	moveChooseBeOrCa();
}
	
void exitBeen() {
	drawExitbeen();
	moveChooseExitBeen();
}

void beenTogether() {
	changeColore(7);
	coverFrame();
	changeColore(13);
	drawHeart1();
	drawHeart2();
	changeColore(7);
	dayBeen();
	nameBeen();
	moveChoose();
}
int main() 
{
	resizeConsole(1500, 1700);
	coverFrame();
	inputAccount();	
	printStartFrame();
	upDownStartFrame();
	return 0;
}




