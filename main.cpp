#include <graphics.h>
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node* trai;
    Node* phai;
};
typedef Node* Tree;


void create(Tree &T){
	T = NULL;
}

//hien thi 1
void duyetTruoc(Tree T){
	if(T!= NULL){
		cout << T->data << " ";
		duyetTruoc(T->trai);
		duyetTruoc(T->phai);
	}
}

//hien thi 2
void duyetGiua(Tree T){
	if(T!= NULL ){
		duyetGiua(T->trai);
		cout << T->data << " ";
		duyetGiua(T->phai);
	}
}

//hien thi 3
void duyetSau(Tree T){
	if(T!=NULL){
		duyetSau(T->trai);
		duyetSau(T->phai);
		cout << T->data << " ";
	}
}

//nhap moi mot nut
void nhapMoi(Tree &T, int value){
	if(T){
		if(T->data == value) cout << "Du lieu da co san\n ";
		if(T->data>value) nhapMoi(T->trai,value);
		else if(T->data<value) nhapMoi(T->phai,value);
	}
	if (T==NULL){
		T = new Node;
		T->data = value;
		T->trai = NULL;
		T->phai = NULL;
	}

}

//nhap moi mot cay
void nhap(Tree &T){
	create(T);
	int n;
	cout << "Nhap so luong can nhap vao: ";
	cin >> n;
	cout << endl;
	for(int i=0;i<n;i++){
	int dl;
	cout << "Nhap du lieu cua nut thu " << i+1 << ": ";
	cin >> dl;
	nhapMoi(T,dl);
	}
}

//tim gia tri trái nhat
int leftMostValue(Tree T){
	while(T->trai!=NULL) T = T->trai;
	return T->data;
}


//xoa mot nut bat ki tren cay
void xoa(Tree &T, int x){
	if (T==NULL) {
		cout << "Khong co nut can tim";
		return;
	}
	if (T->data>x) xoa(T->trai,x);
	if (T->data<x) xoa(T->phai,x);

	if (T->data==x){
		if(T->trai == NULL) T = T->phai;
		else if (T->phai == NULL) T = T->trai;
		else {
			T->data = leftMostValue(T->phai);
			xoa(T->phai, T->data);
		}
	}
}


//tim kiem xem thu co mot nut tren cay hay khong
void timKiem(Tree T, int y){
	if (T==NULL) {
		cout << "Khong co nut trong cay";
		return;
	}
	if(T->data == y ) {
		cout << "Nut can tim co trong cay";
		return;
	}
	else if (T->data > y) timKiem(T->trai,y);
	else if (T->data < y) timKiem(T->phai,y);
}

//xoa toan bo cay
void xoaCay(Tree &T){
	if(T!=NULL){
		xoaCay(T->trai);
		xoaCay(T->phai);
		delete(T);
		T = NULL;
	}
}

//In cay ra man hinh theo do hoa
void printTree(int x, int y, Tree T, int index)
{
    //doi nen phong chu thanh mau trang
    setbkcolor(WHITE);


    if (!T)
        return;

    // Đoi kieu du lieu tu int sang string
    ostringstream str1;
    str1 << T->data;

    string str2 = str1.str();
    char* str = &str2[0u];

    // Doi mau vong tron thanh mau DEN
    setcolor(BLACK);

    // Ve hinh trong ban kinh 25
    circle(x, y, 25);
    //floodfill(x, y, BLACK);

    // In gia tri vao ben trong hinh tron
    outtextxy(x - 10, y - 10, str);

    // Line noi cac nut mau red
    setcolor(RED);

    // Vi tri cay ben trai va ben phai
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Ve nut ben trai va ben phai theo de quy
    if (T->trai != NULL) {
            printTree(x - y / (index + 1), y + 50, T->trai, left);
            line(x, y+25, x - y / (index + 1), y + 25);
            }
    if (T->phai!= NULL) {
            printTree(x + y / (index + 1), y + 50, T->phai, right);
             line(x, y+25, x + y / (index + 1), y + 25);}

    return;

}

//Tim kiem mot  phan tu cua cay bang do hoa
void findNodeByGraphic(int x, int y, Tree T,int index, int k,bool findorNot){

    //doi nen phong chu thanh mau trang
    setbkcolor(WHITE);


    if (!T)
        return;

    // Đoi kieu du lieu tu int sang string
    ostringstream str1;
    str1 << T->data;

    string str2 = str1.str();
    char* str = &str2[0u];

    //Neu nut day la nut can tim thi chuyen sang mau vang, khong phai thi mau den
    if(T->data == k) {
            findorNot = true;
            setcolor(YELLOW);
    }
    else setcolor(BLACK);

    // Ve hinh tron ban kinh 25
    circle(x, y, 25);
    //if(T->data ==k) floodfill(x, y, YELLOW);
    //else floodfill(x, y, BLACK);

    // In gia tri vao ben trong hinh tron
    outtextxy(x - 10, y - 10, str);

    // Line noi cac nut mau red
    setcolor(RED);

    // Vi tri cay ben trai va ben phai
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Ve nut ben trai va ben phai theo de quy
    if (T->trai != NULL) {
            findNodeByGraphic(x - y / (index + 1), y + 50, T->trai, left,k, findorNot);
            line(x, y+25, x - y / (index + 1), y + 25);
            }
    if (T->phai!= NULL) {
            findNodeByGraphic(x + y / (index + 1), y + 50, T->phai, right,k,findorNot);
            line(x, y+25, x + y / (index + 1), y + 25);
            }

    if (findorNot) return; //neu da tim ra thi return

    else if (findorNot!=true && x==300 && y==100){
        cout << "Khong co nut can tim";
        return;
    }
    else return;

}


int main(){
    char cmd[6];
	Tree T;
	create(T);
	int cv = -1;
	int data;
	do{
		cout << endl << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Nhap 1 de nhap moi cay" << endl;
		cout << "Nhap 2 de hien thi cay theo kieu Duyet Truoc" << endl;
		cout << "Nhap 3 de hien thi cay theo kieu Duyet Giua" << endl;
		cout << "Nhap 4 de hien thi cay theo kieu Duyet Sau" << endl;
		cout << "Nhap 5 de nhap them mot nut vao cay" << endl;
		cout << "Nhap 6 de xoa mot nut" << endl;
		cout << "Nhap 7 de tim mot nut" << endl;
		cout << "Nhap 8 de xoa cay" << endl;
		cout << "Nhap 9 de bieu dien cay nhi phan bang hinh anh" << endl;
		cout << "Nhap 10 de tim kiem mot nut bang do hoa" << endl;
		cout << "Nhap 0 de thoat" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "Nhap cong viec: ";
		cin >> cv;
		cout << endl;
		switch(cv){
			case 1:{
				nhap(T);
				break;
			}

			case 2:{
				if (!T) cout << "Khong co du lieu de hien thi" << endl;
				else{
				duyetTruoc(T);
				}
				break;
			}

			case 3:{
				if (!T) cout << "Khong co du lieu de hien thi" << endl;
				else{
				duyetGiua(T);
				}
				break;
			}

			case 4:{
				if (!T) cout << "Khong co du lieu de hien thi" << endl;
				else{
				duyetSau(T);
				}
				break;
			}

			case 5:{
				int dl;
				cout << "Nhap du lieu cua nut: ";
				cin >> dl;
				nhapMoi(T,dl);
				break;
			}

			case 6:{
				int x;
				cout << "Nhap nut can xoa: ";
				cin >> x;
				xoa(T,x);
				break;
			}

			case 7:{
				int y;
				cout << "Nhap nut can tim: ";
				cin >> y;
				timKiem(T,y);
				break;
			}

			case 8:{
				xoaCay(T);
				break;
			}
			case 9:{
                int gd = DETECT, gm;
                initgraph(&gd, &gm, "None");
                setbkcolor(WHITE);
                cleardevice();
                printTree(300,100,T,0);
                break;
		}
            case 10:{
                int y;
				cout << "Nhap nut can tim: ";
				cin >> y;
                int gd = DETECT, gm;
                initgraph(&gd, &gm, "None");
                setbkcolor(WHITE);
                cleardevice();
                findNodeByGraphic(300,100,T,0,y,false);
                break;
		}
			default:{
			    closegraph();
				break;
			}
		}

	}while(cv!=0);
}
