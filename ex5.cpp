#include <iostream>
using namespace std;

class st{
public:
	int number;
	char name[10];
	int general;
	int midterm;
	int final;
	st *ptr;
};

int menu(){
	int i;
	cout<< "     menu"         <<endl;
	cout<< "  1. 新增學生資料" <<endl;
	cout<< "  2. 刪除資料"     <<endl; 
	cout<< "  3. 查詢資料"     <<endl;
	cout<< "  4. 列印資料"     <<endl; 
	cout<< "  0. 離開"         <<endl; 
	cin>>i;
	return i;
}

int main(){
	st *head;
	st *p;
	st *x;
	st *y;
	int select=0;
	int search=0;
	int skip=0;
	head=NULL;
	while(select=menu()){
		switch(select){
			case 1:
				cout<< "請依照座號、姓名、平時成績、期中成績、期末成績順序輸入" <<endl;
				p = new st;
				cin>> p->number;
				cin.get();
				cin.getline(p->name,10);
				cin>> p->general;
				cin>> p->midterm;
				cin>> p->final;
				if(head == NULL){
					p->ptr = head;
					head = p;
				}
				else{
					x=head;
					while(x->ptr != NULL){
						if(x->ptr->number > p->number){
							break;
						}
						x = x->ptr;
					}
					if(x->number > p->number){
						p->ptr = x;
						head = p;
					}
					else{
						p->ptr = x->ptr;
						x->ptr = p;
					}
				}
				break; 
			case 2:
				cout<< "請輸入需刪除的座號"<<endl;
				cin>> search;
				if(head == NULL){
					cout<< "尚未輸入任何資料" <<endl; 
				}
				else{
					x=NULL;
					y=head;
					skip=0;
					while(y && y->number != search){
						if(y->number > search){
							skip=1;
							break;
						}
						x = y;
						y = y->ptr;
					}
					if(skip ==1 || y == NULL){
						cout<< "此資料不存在" <<endl;
					}
					else{
						if(x == NULL){
							head = y->ptr;
						}
						else{
							x->ptr = y->ptr;
						}
						delete y;
						cout<< "刪除完成" <<endl; 
					}
				}
				break;
			case 3:
				cout<< "請輸入需查詢的座號" <<endl;
				cin>> search;
				if(head == NULL){
					cout<< "尚未輸入任何資料" <<endl; 
				}
				else{
					y = head;
					skip = 0;
					while(y && y->number != search){
						if(y->number > search){
							skip = 1;
							break;
						}
						y = y->ptr;
					}
					if(skip ==1 || y == NULL){
						cout<< "此資料不存在" <<endl;
					}
					else{
						cout<< "座號 姓名    平時 期中 期末" <<endl; 
						cout<< y->number  <<"    ";
						cout<< y->name    <<"    ";
						cout<< y->general <<"   ";
						cout<< y->midterm <<"   ";
						cout<< y->final   <<endl;
					}
				}
				break;
			case 4:
				p=head;
				cout<< "座號 姓名    平時 期中 期末" <<endl; 
				while(p != NULL){
					cout<< p->number  <<"    ";
					cout<< p->name    <<"    ";
					cout<< p->general <<"   ";
					cout<< p->midterm <<"   ";
					cout<< p->final   <<endl;
					p = p->ptr;
				}
				break;
			default:
				cout<<"輸入錯誤，請重新輸入"<<endl; 
		}
	}

} 
