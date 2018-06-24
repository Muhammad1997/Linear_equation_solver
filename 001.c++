/*
by Muhammad Magdy
mail/mosmagdysror@live.com
phone/+2-01125424928
date/23-6-2018
*/

#include<iostream>
#include<string>
using namespace std;

int n;               //num of equations
string array [100];  //array of strings (equations)
int num_of_variables[100]; //array to hold num of variables in all equations

void num_vars_func();


int main(){
cin>>n;             //enter the num of equations


//loop to put equations to array
for(int i = 0;i<n;i++){
cin>>array[i];
}


while(true){
string command;
string quit = "quit";
string num_vars = "num_vars";
cin >> command;
if      (command.compare(quit) == 0){break;}
else if (command.compare(num_vars) == 0){num_vars_func();}
}
cout<<"finshed" <<"\n";
/*
//loop to print equations and length of every one
for(int i = 0;i<n;i++){
cout<<array[i] <<"\n";
cout<<array[i].size()<<"\n";
}

*/

}

void num_vars_func(){
string equation_n;          //string to hold one equation
string x = "x";    // string to compare
int max_num_of_variables = 0; //integer to hold maximum number of variables in all equa
for(int i = 0;i<n;i++){
    equation_n = array[i];     //store the equation from array

    int counter = 0;   //counter to count num of x

    //count how many "x" in one string (equation)
    for (int j = 0;j<equation_n.size();j++){
        string current_str; //string to hold one char of equation
        current_str = equation_n.at(j);
        if (current_str.compare(x) == 0){counter++;}
    }
    //cout<<counter << "\n";
    num_of_variables[i] = counter;
    if(num_of_variables[i] >= max_num_of_variables){
        max_num_of_variables = num_of_variables[i];}
}
cout << max_num_of_variables <<"\n"; //print the max num of var
}
