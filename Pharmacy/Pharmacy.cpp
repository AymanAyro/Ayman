// Ayman Saber Gad // Mohamed Fathi Mohamed Mohamed Ali //Fourth Level
#include<iostream>
#include<string>
#include"pharmacy_h.h"
using namespace std;
int main(){
Pharmacy_DoubleList ph;
//Checking if the list is empty
if (ph.Is_Empty())
{
    cout<<"The list is empty \n";
}

// //Inserting drugs
ph.Insert(100000,"Effegad 75mg",10,7);
ph.Insert(113021,"Dogmatil Fort 200mg",3,0);
ph.Insert(103554,"Paroxedep CR 15mg",7,5);
ph.Insert(103555,"Paroxedep CR 25mg",8.8,4);

// //Display the list
ph.Display();

// //Modify
ph.Modify(103554,"Paroxedep CR 35mg",10,3);

// //Removing
ph.Remove(100000);
ph.Display();

// //Checking the stock
ph.AutoCheck();

// //Knowing the location of a certain drug in the list
ph.Location(103555);

// //Generating bill
ph.GenerateBill(103555,4);

return 0;
}