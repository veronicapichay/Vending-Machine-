//******************************************************************
//Program Name: Vending Machine 
//Author: Veronica Pichay
//IDE Used: Repl.it
//Created: ‎Friday, ‎July ‎17, ‎2020
//Program description: Inventory Management
//******************************************************************
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 5;
//Comment # 1 Struct var name
struct Beverage
{
//Comment # 2 Members 
string name;
float cost;
int count;

};
//Comment # 3 Fx prototype
void dclre (Beverage&, string , float, int);
int menu(Beverage[]);
void pay(float);

int main()
{
//Comment # 4 Initialization 
int choice;
double rev = 0;
Beverage bev[5];
dclre (bev[0],"Cola", 0.75, 20);
dclre (bev[1],"Root Beer", 0.75, 20);
dclre (bev[2],"Lemon-Lime", 0.75, 20);
dclre (bev[3],"Grade Soda", 0.80, 20);
dclre (bev[4],"Cream Soda", 0.80, 20);
choice = menu (bev);

while(choice != 5) //Comment # 5 Condition of summation and subtraction if user don't exit
{
    pay(bev[choice].cost);
    rev += bev[choice].cost; //Comment # 6 updates earnings amount
    bev[choice].count--; //Comment # 7 Updates inventory amount
    choice = menu(bev);
}
cout<<"Total earning/s $"<< rev <<endl;

return 0;
}

void pay(float p) //Comment # 8 Fx that calculates the user transaction
{
float pay;
    
    cout<<"\t> Price of the beverage is $"  <<fixed <<p <<endl; 
    cout<<"\t> Enter amount of payment -->  ";
    cin>>pay;
    //IVL
    while (pay < 0.75 or pay > 1.00)
    {

        cout<<"\t> ERROR: Pay must be $0.75 to $1.00 only!  --> ";
        cin>>pay;

    }
    cout <<"\t> Don't forget to grab your $" <<fixed << pay - p<<" change!\n";cout <<"\t> Enjoy your beverage!\n";

}
//Comment # 9 Declares shortcut of each members
void dclre (Beverage& d,string n, float c, int count)
{
    d.name = n;
    d.cost = c;
    d.count = count;
}
//Comment # 10 Purchase menu for user interactivity
int menu(Beverage b[])
{ 

int choice;
bool gone = true;

while ((choice < 1 or choice > 6) or gone)
{
    gone = false;
   
    cout << fixed << setprecision(2);
    cout << "\nSoda machine inventory: \n";
    cout << setw(15) << "\n \t> BEVERAGE \t" << setw(14) << "COST \t" << setw(10) << "On Hand \n";
    cout << setw(8) << " \t> --------" << setw(11) << "\t----" << setw(10) << "\t -------\n";

    for (int i = 0; i < SIZE; i++)
        cout << "\t> " <<i + 1 << ". " << left << setw(15) << b[i].name << setw(11) << b[i].cost << left << b[i].count << endl;
        cout<<" \t> 6. Quit\n";

cout<<"\nEnter Choice ";
cin >> choice;

if(choice < 1 or choice > 6) cout<<"Please choose from 1 to 6 only!";

else if (b[choice-1].count == 0)
{
    cout<<"Please select a drink that is instock! \n";
    gone = true;
}
}
return choice-1;
} 