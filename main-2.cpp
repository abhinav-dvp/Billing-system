#include<iostream>  
#include<fstream>  
#include <stdlib.h>  
using namespace std;  
class head  
{  
char Iname[10][10];  

public:  
int totalitems;  
float Qty[1];  
float price[1];  
int vatprice[1];  
int tprice[1];  
void input();  
void output();  
};  
class vat:public head  
{  
float vats;  
public:  
void vatcal();  
void outputs();  
void sum();  
};  

//******************************************************************  
//      INPUT FUNCTION  
//******************************************************************  

void head::input()  
{  
cout<<"\nEnter number of items= ";  
cin>>totalitems;  

for(int i=0; i<totalitems; i++)  
{  
    cout<<"\nEnter name of item "<<i+1<<": ";  
    cin>>Iname[i];  
    cout<<"Enter quantity: ";  
    cin>>Qty[i];  
    cout<<"Enter price of item "<<i+1<<": ";  
    cin>>price[i];  
    tprice[i]=Qty[i]*price[i];  
}  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//     OUTPUT FUNCTION  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
void head::output()  
{  
int a;  

ifstream infile("COUNT.TXT");  
infile>>a;  
cout<<a<<endl;
ofstream outfile("COUNT.TXT");  
a+=1;  
outfile<<a;  
outfile.close();  

{ofstream outfile("HIS.TXT", ios::app);  
outfile<<endl<<"Bill No.:"<<a<<endl;  
outfile<<"------------------------------------------------------------------------"<<endl;  
cout<<"\n";  
cout<<"Name of Item\tQuantity   Price  Total Price\n";  
for(int i=0;i<totalitems;i++)  
{  
    outfile<<"Name: "<<Iname[i]<<" Qty: "<<Qty[i]<<" Price: "<<tprice[i]<<endl;  
    cout<<Iname[i]<<"\t\t"<<Qty[i]<<"\t   "<<price[i]<<"\t   "<<tprice[i]<<'\n';  
}  

outfile<<"------------------------------------------------------------------------"<<endl;  
outfile.close();  
}  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//     VAT CALCULATION  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
void vat::vatcal()  
{  
input();  
for(int i=0;i<totalitems;i++)  
{  
    if(price[i]<=100.00)  
    {  
        vatprice[i]=tprice[i]+(0.03*tprice[i]);  
    }  
    else  
    {  
        vatprice[i]=tprice[i]+(0.1*tprice[i]);  
    }  
}  
}  
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//      VAT OUTPUTS  
//*  * * * * * * * * * * * * * * * * * * * * ** * * * * * * * * * * * * * * * * * * * * * * * * *    
void vat::outputs()  
{  
output();  

float cash=0,sum=0,qty=0,sumt=0;  

for(int i=0;i<totalitems;i++)  
{  
        sumt+=tprice[i];  
        sum+=vatprice[i];  
        qty+=Qty[i];  
}  
cout<<"\nTotal:";  
cout<<"\n------------------------------------------------------------------------------";  
cout<<"\n\tQuantity= "<<qty<<"\t\t Sum= "<<sumt<<"\tWith Vat:"<<sum;  
cout<<"\n------------------------------------------------------------------------------";  

pay:  

cout<<"\n\n\t\t\t * * * * PAYMENT SUMMARY * * * * \n";  
cout<<"\n\t\t\tTotal cash given: ";  
cin>>cash;  

if(cash>=sum)  
    cout<<"\n\t\t\tTotal cash repaid: "<<cash-sum<<'\n';  
        
else  
{   cout<<"\n\t\t\tCash given is less than total amount!!!";  

goto pay;  
}  
}  
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   
//      PROTECTION PASSWORD  
//* * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   

int passwords()  
{  

string p;  

cout<<"\n\n\n\n\n\n\t\t\tENTER THE PASSWORD: ";  

cin>>p; 

if ((p == "cpp"||p == "CPP"))    
    return 1;   
else  
    cout<<"\nWrong password try once more\n";
    passwords();
    return 0;  
}  
//****************************************************************  
//      THE START FUNCTION OF PROGRAM  
//****************************************************************
void start()
{
    vat obj;  
    char opt, ch;    
    ifstream fin;
    cout<<"\n\n\t\t\t------------------------------";  
    cout<<"\n\t\t\tBilling Management System";  
    cout<<"\n\t\t\t------------------------------";  
    cout<<"\n\n\t\t\tWhat you want to do?";  
    cout<<"\n\t\t\t1.\tTo enter new entry\n\t\t\t2.\tTo view previous entries\n\t\t\t3.\tExit\n";  
    cout<<"\n\nEnter your option: ";  
    cin>>opt;  
    switch(opt)  
    {  
    case'1':  
        obj.vatcal();     
        obj.outputs();  
        start();
        
    case'2':     
        fin.open("HIS.TXT", ios::in);  
        while(fin.get(ch))  
        {  
            cout<<ch;  
        }  
        fin.close();       
        start();  
    case'3':  
        exit(0);  
    default:  
        cout<<"\a";  
    }
}
// END of Password.  

//****************************************************************  
//      THE MAIN FUNCTION OF PROGRAM  
//****************************************************************  


int main()  
{  
passwords();  
start();    
}