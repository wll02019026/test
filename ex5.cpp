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
	cout<< "  1. �s�W�ǥ͸��" <<endl;
	cout<< "  2. �R�����"     <<endl; 
	cout<< "  3. �d�߸��"     <<endl;
	cout<< "  4. �C�L���"     <<endl; 
	cout<< "  0. ���}"         <<endl; 
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
				cout<< "�Ш̷Ӯy���B�m�W�B���ɦ��Z�B�������Z�B�������Z���ǿ�J" <<endl;
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
				cout<< "�п�J�ݧR�����y��"<<endl;
				cin>> search;
				if(head == NULL){
					cout<< "�|����J������" <<endl; 
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
						cout<< "����Ƥ��s�b" <<endl;
					}
					else{
						if(x == NULL){
							head = y->ptr;
						}
						else{
							x->ptr = y->ptr;
						}
						delete y;
						cout<< "�R������" <<endl; 
					}
				}
				break;
			case 3:
				cout<< "�п�J�ݬd�ߪ��y��" <<endl;
				cin>> search;
				if(head == NULL){
					cout<< "�|����J������" <<endl; 
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
						cout<< "����Ƥ��s�b" <<endl;
					}
					else{
						cout<< "�y�� �m�W    ���� ���� ����" <<endl; 
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
				cout<< "�y�� �m�W    ���� ���� ����" <<endl; 
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
				cout<<"��J���~�A�Э��s��J"<<endl; 
		}
	}

} 
