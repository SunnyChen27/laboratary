#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
using namespace std;
class Book{
	private:
		int state;//1���� 0��û��  2���쳣 
		int number;
		int ISBN;
		char name[30];
	    char publisher[30];
		char writer[20];
		int dianzi;//1�ǵ��� 0�� ʵ���� 	
        char address[50];
	public:
		Book(int state,int number,int ISBN,char *name,char *publisher,char *writer,int dianzi,char *address);
	    ~Book(){} 
	    int getstate(){
			return state;
		}
		void setstate(int st){
			state=st;
		};//�Ƿ��ڿ� 
		int getnumber(){
			return number;
		}
		void setnumber(int num){
			number=num;
		}//��� 
		int getISBN(){
			return ISBN;
		}
		void setISBN(int isbn){
			ISBN=isbn;
		}//ISBN
		char *getname(){
			return name; 
		}
		void setnanme(char na[]){
			strcpy(name,na);
		}//���� 
	    char *getpublisher(){
	    	return publisher;
		}
		void setpublisher(char pub[]){
			strcpy(publisher,pub);
		}//������ 
		char *getwriter(){
			return writer;
		}
		void setwriter(char wr[]){
			strcpy(writer,wr);
		}//���� 
		char *getaddress(){
			return address;
		}
		void setaddress(char addr[]){
			strcpy(address,addr);
		}//���λ�� 
		int getdianzi(){
			return dianzi;
		}
		void setdianzi(int dz){
			dianzi=dz;
		}//�Ƿ������ 
};
Book::Book(int st,int nu,int IS,char*na,char*pub,char*wr,int dian,char*add){
	state=st;
	number=nu;
	ISBN=IS;
	*name=*na; 
	*publisher=*pub;
	*writer=*wr;
	dianzi=dian;
	*address=*add;
} 
class Paper{
	private:
	int number;
	char headline[50];
	char writer[20];
	char book[30];
	char time[15];
	char address[50];
public:
    Paper(int number,char*headline,char*writer,char*book,char*time,char*address);
	~Paper(){}
	int getnumber(){
		return number;
	}
	void setnumber(int num){
		number=num;
	}//��� 
	char*getheadline(){
		return headline;
	}
	void setheadline(char hl[]){
		strcpy(headline,hl);
	}//���� 
	char*getwriter(){
		return writer;
	};
	void setwriter(char wri[]){
		strcpy(writer,wri);
	};//���ߣ������ 
	char*getbook(){
		return book;
	}
	void setbook(char bo[]){
		strcpy(book,bo);
	}//���� 
	char*gettime(){
		return time;
	}
	void settime(char ti[]){
		strcpy(time,ti);
	}//ʱ�� 
	char*getaddress(){
		return address;
	}
	void setaddress(char addr[]){
		strcpy(address,addr);
	}//���λ�� 
};
Paper::Paper(int nu,char*hl,char*wr,char*bo,char*ti,char*add){
	number=nu;
	*headline=*hl;
	*writer=*wr;
	*book=*bo;
	*time=*ti;
	*address=*add;
}
class Moi{
private:
	char address[30];
public:
	Moi(char*add);
	~Moi(){}
	void inputbook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi);
	void updatebook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi);
	void deletebook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi);
	void viewbook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi);
	void searchbook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi);
}; 
    Moi::Moi(char*add){
	*address=*add;};
    void Moi::inputbook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi){
	    string path8;
	    string newbook;
	    cin >> newbook;
	    path8="D:\\"+name+".txt";
	    ofstream inputbook(path8.c_str());
	    inputbook <<state<<" "<<number<<" "<<ISBN<<" "<<name<<" "<<publisher<<" "<<writer<<" "<<address<<" "<<dianzi;
	    inputbook.close();
	    cout << endl;
	}
	void Moi::viewbook(int state,int number,int ISBN,string name,string publisher,string writer,string address,int dianzi){
	    string path7;
	    char buf1[100];
	    path7="D:\\"+name+".txt";
	    ifstream openfile(path7.c_str());
	    while(!openfile.eof()){
	        openfile.getline(buf1,100);
	        cout << buf1 << endl;
	    }
	}
class User{
private:
    char name[10];
    char password[15];
	int role;//0�ǹ���Ա 1���û�
public:
    User(char *name,char *password,int role);
    ~User(){}
    char*getname(){
    	return name;
	}
	void setname(char na[]){
		strcpy(name,na);
	}//�û��� 
	char*getpassword(){
		return password;
	}
	void setpassword(char pw[]){
		strcpy(password,pw);
	}//���� 
	void borrowbook(string book1,string name1);
	void returnbook(string book2,string name2);
};
User::User(char *na,char *pass,int ro){
	*name=*na;
	*password=*pass;
	role=ro;};
    void User::borrowbook(string book1,string name1){
    	string path1,path2;
	    path1="D:\\"+book1+".txt";
        if(!remove(path1.c_str())){
        cout << "you have borrowed the book." << endl;
    }
	    path2="D:\\"+name1+".txt";
	    ofstream openfile1(path2.c_str(),ios::ate);
	    openfile1 << "you have borrowed" << book1;
	    openfile1.close();
	    cout << endl;
	}
	void User::returnbook(string book2,string name2){
		string path3,path4;
		path3="D:\\"+book2+".txt";
        path4="D:\\"+name2+".txt";
	    ofstream setfile(path3.c_str());
	    setfile << "this is a shiti book.";
	    setfile.close();
	    cout << endl;
	    setfile.close();
	    ofstream openfile2(path4.c_str(),ios::ate);
	    openfile2 << "you have returned" << book2;	
	    openfile2.close();
	    cout << endl;
	}
class Mou{
public:
	Mou();
	~Mou(){}
	void addUser(string name,string password);
	void updateUser(string name,string password);
	void deleteUser(string name);
	int setUserRole (int role){
		cout<<"Are you a user?"<<" "<<"If so,please enter yes."<<endl;
		string command;
		cin>>command;
		string a="yes";
		if(command==a){
			role=1;
			return 1;
		}
		else{
			role=0;
			return 0;
		}
		
	}
};
    Mou::Mou(){};
    void Mou::addUser(string name,string password){
	   	string path5;
	    path5="D:\\"+name+".txt";
	    ofstream setup(path5.c_str());
	    setup << name<<" "<<password;
	    setup.close();
   }
    void Mou::deleteUser(string name){
       string path6;
	   path6 ="D:\\"+name+".txt";
	   if(!remove(path6.c_str())){
		       cout << "Delete successfully!" << endl;
		   }
		}
	int main(){
		Mou mou;	
		int choice;
		cout<<"��ѡ�����Ա���û���ݣ�����Ա������0���û�������1"<<endl;
		cin>>choice;
		if(choice==0){
			char address[30];
			cin>>address;
			Moi moi(address);
			int choice2;
			cout<<"��ͨ����������ѡ����"<<endl;
			cout<<"1.���ͼ��"<<endl;
			cout<<"2.����ͼ��"<<endl;
			cout<<"3.ɾ��ͼ��"<<endl;
			cout<<"4.����ͼ��"<<endl; 
			cin>>choice2;
			int state;int number;int ISBN;string name;string publisher;string writer;string aaddress;int dianzi;
				if(choice2==1){
					cout<<"������ͼ��״̬"<<endl;
					cin>>state;
					cout<<"������ͼ�����"<<endl;
					cin>>number;
					cout<<"������ͼ��ISBN��"<<endl;
					cin>>ISBN;
					cout<<"������ͼ������"<<endl; 
					cin>>name;
					cout<<"���������������"<<endl; 
					cin>>publisher;
					cout<<"����������"<<endl;
					cin>>writer;
					cout<<"������ͼ��λ��"<<endl;
					cin>>aaddress;
					cout<<"�������鼮����"<<endl;
					cin>>dianzi; 
					moi.inputbook( state, number,ISBN, name, publisher, writer, address, dianzi);
					cout<<"��ӳɹ�"<<endl; 
				}
				/*if(choice2==2){
					moi.updatebook(state, number,ISBN, name, publisher, writer, address, dianzi);
				}
				if(choice2==3){
					moi.deletebook(state, number,ISBN, name, publisher, writer, address, dianzi);
				}
				if(choice2==4){
					moi.searchbook(state, number,ISBN, name, publisher, writer, address, dianzi);
				}*///��Щ����������δʵ�� 
			
		} 
	    if(choice==1){	
			char*name;
			char*password;
			int choice4; 
	        cout<<"��ͨ����������ѡ����"<<endl;
			cout<<"1.��¼"<<endl;
			cout<<"2.ע��"<<endl;
			cin>>choice4;
			if(choice4==1){
	    	cout<<"�������û���"<<endl; 
	    	cin>>name;
	    	cout<<"����������"<<endl; 
	    	cin>>password;
			User u(name,password,choice);
	    	int choice3;
	    	cout<<"��ͨ����������ѡ����"<<endl;
			cout<<"1.����ͼ��"<<endl;
			cout<<"2.�˻�ͼ��"<<endl;
			cout<<"3.�޸�����"<<endl;
			cout<<"4.����ͼ��"<<endl;
			int state;int number;int ISBN;string nname;string publisher;string writer;string address;int dianzi;
			cin>>choice3;{
			string book;
			string username;
			cin>>book;
			cin>>username;
			if(choice3==1){
				u.borrowbook( book,name);
			}
			if(choice3==2){
				u.returnbook( book, name);
			}
		/*	if(choice3==3){
				mou.updateUser(name,password); 
			}
			if(choice3==4){
				cin>>state>>number>>ISBN>>name>>publisher>>writer>>address>>dianzi; 
				moi.searchbook(state, number,ISBN, name, publisher, writer, address, dianzi);
			}*/
		}}
		if(choice4==2){
			string username;
			string userpassword;
			cout<<"�������û���"<<endl; 
	    	cin>>username;
	    	cout<<"����������"<<endl; 
	    	cin>>userpassword;
			mou.addUser( username, userpassword);
			cout<<"ע��ɹ�"<<endl; 
		}
		}
		return 0;
		}
	   
