#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<iostream>

#define MAX 100
using namespace std;
struct SinhVien{
	char Hoten[30];
	char MSSV[30];
	char ngaysinh[30];
	float diemtoan;
	float diemly;
	float diemhoa;
	float diemTB;
};

typedef SinhVien SV;
void nhapsv(SV arrSV[], int&n);
void hienthi(SV arrSV[], int n);
void timkiemmssv(SV arrSV[], int n);
void timkiemten(SV arrSV[], int n);
void xoamssv(SV arrSV[], int n);
void sapxepdiem(SV arrSV[], int n);
float tinhdiemTB(SV arrSV[], int n);

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition; 
void gotoxy(int x, int y){ //vi tri 
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(Console,CursorPosition);
}

void Setcursor(bool visible,DWORD size){ //cung cap vs bang phan tich cua chuc nang thanh phan , nay để xóa con tror nhấp nháy trên màn hình để cho màn hình đẹp hơn 
	if(size==0)
	   size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(Console,&lpCursor);
}

int main(){
	Setcursor(0,0);
	start:
	system("cls");
    SV arrSV[MAX];
    int key;
    int choice;
    char x;
    while(true){
    	cout<<"\e[103m                                                             \e[0m"<<endl;
        cout<<"\e[103m                                                             \e[0m"<<endl;
		cout<<"\e[103m                \e[103m\e[5mHE THONG QUAN LI SINH VIEN\e[0m\e[0m\e\e[103m                   \e[0m"<<endl;
		cout<<"\e[103m                                                             \e[0m"<<endl;
		cout<<"\e[103m                                                             \e[0m"<<endl;
		cout<<"\e[107m                                                             \e[0m"<<endl;
		cout<<"\e[107m           \e[30m1. NHAP THONG TIN SINH VIEN\e[0m\e[107m                       \e[0m"<<endl;
		cout<<"\e[107m           \e[30m2. HIEN THI THONG TIN SINH VIEN\e[0m\e[107m                   \e[0m"<<endl;
		cout<<"\e[107m           \e[30m3. TIEM KIEM SINH VIEN THEO MSSV\e[0m\e[107m                  \e[0m"<<endl;
		cout<<"\e[107m           \e[30m4. XOA SINH VIEN THEO MSSV\e[0m\e[107m                        \e[0m"<<endl;
		cout<<"\e[107m           \e[30m5. TIM KIEM SINH VIEN THEO TEN\e[0m\e[107m                    \e[0m"<<endl;
		cout<<"\e[107m           \e[30m6. SAP XEP THEO DIEM\e[0m\e[107m                              \e[0m"<<endl;
		cout<<"\e[107m           \e[30m7. THOAT\e[0m\e[107m                                          \e[0m"<<endl;
		cout<<"\e[107m                                                             \e[0m"<<endl;
		cout<<"\e[107m                                                             \e[0m"<<endl;
		cout<<endl;
		cout<<" ----------------~~~~~~~~~---------------- "<<endl;
		cout<<"\e[91mNhap tuy chon cua ban:\e[0m\e[92m";
		cin>>choice;
		cout<<endl;
		switch(choice){
		case 1:{
			do{
			    system("cls");
				nhapsv(arrSV,key);
				gotoxy(45,18);cout<<"--> Them Sinh Vien (y/n): ";
    		    cin>>x;
		        }while(x=='Y'||x=='y');
				system("cls");
				break;
			}
			case 2:{
				system("cls");
				hienthi(arrSV,key);
				break;
			}
			case 3:{
				system("cls");
				timkiemmssv(arrSV,key);
				break;
			}
			case 4:{
				system("cls");
				xoamssv(arrSV,key);
				break;
			}
			case 5:{
				system("cls");
				timkiemten(arrSV,key); 
				break;
	      	}
		 	case 6:{
				system("cls");
				sapxepdiem(arrSV,key);
				hienthi(arrSV,key);
				break;
			}
			default:{
				system("cls");
			}return 0;
			}
		}
		getch();
	return 0;
}


void nhapsv(SV arrSV[], int&n){
    gotoxy(30,1); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;	
    gotoxy(43,2); cout<<"\e[103m\e[33m  |  THEM THONG TIN SINH VIEN  |  \e[0m\e[0m" <<endl;
    gotoxy(30,3); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;

    gotoxy(45,5); cout<<"\e[91mNhap ma so sinh vien:\e[0m "; fflush(stdin); gets(arrSV[n].MSSV);
    gotoxy(45,6); cout<<"\e[91mNhap Ho va Ten:\e[0m "; fflush(stdin); gets(arrSV[n].Hoten);
    gotoxy(45,7); cout<<"\e[91mNhap ngay sinh:\e[0m "; cin>>arrSV[n].ngaysinh;
    
    gotoxy(35,9); cout<<"\e[33m-----------------------------------------------\e[0m"<<endl;	
    gotoxy(45,10);cout<<"\e[107m\e[30m |  NHAP DIEM SO SINH VIEN  |  \e[0m\e[0m"<<endl;
    gotoxy(35,11);cout<<"\e[33m-----------------------------------------------\e[0m"<<endl;
    gotoxy(45,13);cout<<"--> \e[91mNhap diem toan: \e[0m"; cin>>arrSV[n].diemtoan;
    gotoxy(45,14);cout<<"--> \e[91mNhap diem hoa: \e[0m"; cin>>arrSV[n].diemhoa;
    gotoxy(45,15);cout<<"--> \e[91mNhap diem ly: \e[0m"; cin>>arrSV[n].diemly;
    n++;
    cout<<endl;
    tinhdiemTB(arrSV, n);
    gotoxy(43,17); cout<<"\e[96mBan da them sinh vien thanh cong!\e[0m";
    cout<<endl;
}

void hienthi(SV arrSV[], int n){
	gotoxy(30,1); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;	
    gotoxy(43,2); cout<<"\e[103m\e[33m  | DANH SACH THONG TIN SINH VIEN |  \e[0m\e[0m" <<endl;
    gotoxy(30,3); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
    cout<<endl;
    cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
    cout<<" | "<<setw(5)<<"MSSV"<<setw(10)<<" | "<<setw(10)<<"Hoten"<<setw(10)<<" | "<<setw(10)<<"NGAYSINH"<<setw(10)<<" | "<<setw(10)<<"DIEMTOAN"<<setw(10)<<" | "<<setw(10)<<"DIEMHOA"<<setw(10)<<" | "<<setw(10)<<"DIEMLY"<<setw(10)<<" | "<<setw(10)<<"DIEMTB"<<setw(10)<<" | "<<endl;		
	cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;	
    for(int i = 0; i<n; i++){
   	cout<<"|"<<setw(5)<<arrSV[i].MSSV<<setw(5)<<"|"<<setw(5)<<arrSV[i].Hoten<<setw(10)<<"|"<<setw(10)<<arrSV[i].ngaysinh<<setw(10)<<" | "<<setw(10)<<arrSV[i].diemtoan<<setw(10)<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemhoa<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemly<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemTB<<setw(10)<<"|"<<endl;
    cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
    cout<<endl;
   }
   cout<<endl;                                                                                                                  
}

void xoamssv(SV arrSV[], int n){                                                                                                                   
    gotoxy(30,1); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;	
    gotoxy(43,2); cout<<"\e[103m\e[33m   | MA SO SINH VIEN CAN XOA |   \e[0m\e[0m" <<endl;
    gotoxy(30,3); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
    char MSSV[30];
    gotoxy(42,5); cout<<"Nhap ma so sinh vien can xoa:  \e[92m";
	fflush(stdin); gets(MSSV);
	bool check = false;
	for(int i = 0; i<n; i++){
		if(strcmp(arrSV[i].MSSV,MSSV)==0){
			check = true;
			arrSV[i]=arrSV[i+1];
			n--;
		}
	}
	if(check==false)
		cout<<"\e[91mSinh vien khong ton tai!\e[0m"<<endl;
}

void timkiemmssv(SV arrSV[], int n){
	gotoxy(30,1); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;	
    gotoxy(43,2); cout<<"\e[103m\e[33m  | TIM KIEM THEO MA SO SINH VIEN |  \e[0m\e[0m" <<endl;
    gotoxy(30,3); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
	char MSSV[30];
	gotoxy(45,5); cout<<"Nhap msnv can tim:  \e[92m";
	fflush(stdin); gets(MSSV);
	bool check = false;
	for(int i = 0; i<n; i++){
		if(strcmp(arrSV[i].MSSV,MSSV)==0){
		check = true;
		gotoxy(30,7); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
		gotoxy(44,8);cout<<"\e[107m\e[30mTHONG TIN SINH VIEN CO MA SO \e[0m\e[0m"<<MSSV<<endl;
		gotoxy(30,9); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
		
		
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
        cout<<"|"<<setw(5)<<"Hoten"<<setw(10)<<"|"<<setw(10)<<"NGAYSINH"<<setw(10)<<"|"<<setw(10)<<"DIEMTOAN"<<setw(10)<<"|"<<setw(10)<<"DIEMHOA"<<setw(10)<<"|"<<setw(10)<<"DIEMLY"<<setw(10)<<"|"<<setw(10)<<"DIEMTB"<<setw(10)<<"|"<<endl;			
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
   	    cout<<"|"<<setw(10)<<arrSV[i].Hoten<<setw(10)<<"|"<<setw(10)<<arrSV[i].ngaysinh<<setw(10)<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemtoan<<setw(10)<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemhoa<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemly<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemTB<<setw(10)<<"|"<<endl;
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
		}
	}
	if(check==false)
		cout<<"\e[91mSinh vien khong ton tai!\e[0m"<<endl;
}

void timkiemten(SV arrSV[], int n){
	gotoxy(30,1); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;	
    gotoxy(43,2); cout<<"\e[103m\e[33m  | TIM KIEM SINH VIEN THEO TEN |  \e[0m\e[0m" <<endl;
    gotoxy(30,3); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
	char Hoten[30];
	gotoxy(45,5); cout<<"Nhap Ho va Ten can tim:  \e[92m";
	fflush(stdin); gets(Hoten);
	bool check = false;
	for(int i = 0; i<n; i++){
		if(strcmp(arrSV[i].Hoten,Hoten)==0)
		{
		check = true;
		gotoxy(30,7); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
		gotoxy(44,8); cout<<"\e[107m\e[30mTHONG TIN SINH VIEN CO TEN \e[0m\e[0m"<<Hoten<<endl;
		gotoxy(30,9); cout<<"\e[33m------------------------------------------------------------\e[0m"<<endl;
		
		
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
        cout<<"|"<<setw(5)<<"MSSV"<<setw(10)<<"|"<<setw(10)<<"NGAYSINH"<<setw(10)<<"|"<<setw(10)<<"DIEMTOAN"<<setw(10)<<"|"<<setw(10)<<"DIEMHOA"<<setw(10)<<"|"<<setw(10)<<"DIEMLY"<<setw(10)<<"|"<<setw(10)<<"DIEMTB"<<setw(10)<<"|"<<endl;			
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
   	    cout<<"|"<<setw(10)<<arrSV[i].MSSV<<setw(10)<<"|"<<setw(10)<<arrSV[i].ngaysinh<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemtoan<<setw(10)<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemhoa<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemly<<setw(10)<<"|"<<setw(10)<<arrSV[i].diemTB<<setw(10)<<"|"<<endl;
		cout<<"\e[93m---------------------------------------------------------------------------------------------------------------------------------------\e[0m"<<endl;
		}
	}
	if(check==false)
		cout<<"\e[91mSinh vien khong ton tai!\e[0m"<<endl;
}

float tinhdiemTB(SV arrSV[], int n){
	float diem;
	for(int i=0; i<n;i++){
	    arrSV[i].diemTB=(float)(arrSV[i].diemtoan+arrSV[i].diemhoa+arrSV[i].diemly)/3.0;
	    diem=arrSV[i].diemTB;
	}
	return diem;
}

void sapxepdiem(SV arrSV[], int n){
    for(int i = 0; i<n-1; i++){
	    for(int j = i+1; j<n; j++){
		    if(arrSV[i].diemTB>arrSV[j].diemTB)	{
			    SV temp;
			    temp = arrSV[i];
			    arrSV[i] = arrSV[j];
			    arrSV[j] = temp;
		}
	}
}
}