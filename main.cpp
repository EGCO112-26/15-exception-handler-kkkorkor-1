#include<iostream>
using namespace std;

void check0(int);

int main(){
	int x,y,a;
	double d;
	do{
		a=0;
		try{
			int i;
			double * myarray;
			for(i=0;i<100000;i++){
				cout<< "Allocating memory number "<<i<<endl;
				myarray= new double[50000000];
			}


		cout<<"Enter 2 Numbers: ";
		cin>>x>>y;

		//Curated Exception Handling
		if(cin.fail()) throw 101; //throw string
		if(abs(x)>1000 ||abs(y)>1000) throw "Value out of range"; //throw string
		//if(y==0) throw "Error divide by zero";
		check0(y);

		/*Normal Code*/
		d=(double) x/y;
		cout<< "The result is " <<d<<endl;
	
		}
		catch(const char* error){ /*ถ้าไม่มี const compile ไม่ผ่านเพราะ throw เป็น string*/
			cerr<<error<<endl;
			a=1;
			cin.clear();
			cin.ignore(50,'\n');
		}
		catch(int e){
			switch(e){
				case 101: cerr<<"Incorrect numbers "<<endl; break;
				case 0: cerr<< "Error divide by zero" <<endl; break;;
			}
			a=1;
			cin.clear();
			cin.ignore(50,'\n');

		}

		catch(...){
			cout<<"Memory Leaked!!!"<<endl;
		}

	}while(a);
	//catch(int x)
	return 0;
}

void check0(int x){
	if(x==0) throw(x);
}
