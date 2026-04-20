#include<iostream>
#include <exception>
using namespace std;

void check0(int);
class div0:public exception{ //Class จัดการ ตัวหารเป็น 0
	public:
	virtual const char* what() const throw(){
		return "Divided by zero";
	}
};

class my_cin:public exception{
	virtual const char* what() const throw(){
		cin.clear();
		cin.ignore(50,'\n');
		return "Stupid it's not a number";
	}
}f;

int main(){
	int x,y,a;
	double d;
	do{
		a=0;
		try{
			cout<<"Enter 2 Numbers: ";
			cin>>x>>y;

			//Curated Exception Handling
			/*----------*/
			if(cin.fail()) throw f; //throw string
			if(abs(x)>1000 ||abs(y)>1000) throw "Value out of range"; //throw string
			//if(y==0) throw "Error divide by zero";
			check0(y);
			a=0;

			/*Normal Code*/
			d=(double) x/y;
			cout<< "The result is " <<d<<endl;
	
			int i;
			double * myarray;
			for(i=0;i<100000000000;i++){
				cout<< "Allocating memory .... "<<i<<endl;
				myarray= new double[50000000];
			}
			a=0;

		}
			
		
	/*
		catch(const char* error){ //ถ้าไม่มี const compile ไม่ผ่านเพราะ throw เป็น string
			cerr<<error<<endl;
			a=1;
			cin.clear();
			cin.ignore(50,'\n');
		}
		catch(const int e){
			switch(e){
				case 101: cerr<< "Incorrect numbers "<<endl; break;
				case 0: cerr<< "Error divide by zero" <<endl; break;;
			}
			a=1;
			cin.clear();
			cin.ignore(50,'\n');

		}

		catch(...){
			cout<<"Memory Leaked!!!"<<endl;
			a=0;
		}
	*/
	
		catch(exception &e){
			cout<< e.what() <<endl;
		}

	}while(a);
	//catch(int x)
	return 0;
}

void check0(int x){
	div0 e;
	if(x==0) throw(e);
}
