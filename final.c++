/*
by Muhammad Magdy
mail/mosmagdysror@live.com
phone/+2-01125424928
date/24-6-2018
*/
#include<iostream>                                 //input output lib
#include<string>                                  //lib to handle strings
#include<sstream>                                //lib to convert float to string
#include<cstdlib>                               //lib to convert string to float
using namespace std;

int n;                                      //num of equations
string array [100];                        //array of strings (equations)
int num_of_variables[100];                //array to hold num of variables in all equations
float  coefficients_array[100][100];     //array to hold all coefficients


int num_vars_func();                  //function to calculate number of variables
void num_vars_func_output();         //function to print number of variables

void proper_form_func();           //function to put equations in proper form and convert it to array of float numbers


int main(){                     //main function of code
    cin>>n;                    //enter the number of equations


    //loop to put equations to array of strings
    for(int i = 0;i<n;i++){
        cin>>array[i];       //enter n equations as strings
    }

    //while(true) to make infinite loop to enter many commands
    while(true){


        //input commands as string
        string command;
        string quit = "quit";
        string num_vars = "num_vars";
        string D = "D";


        //enter the command of the wanted operation
        cin >> command;

        //string1.compare(string2) boolen function to compare two strings
        //if the input of the wanted operation so call its function

        //commands
        if           (command.compare(num_vars) == 0){num_vars_func_output();}
        else if      (command.compare(D) == 0){proper_form_func();}



        //if the input is quit so break the while loop and exit from program
        else if      (command.compare(quit) == 0){break;}

    }
    return 0;
    /*
    //loop to print equations and length of every one
    for(int i = 0;i<n;i++){
    cout<<array[i] <<"\n";
    cout<<array[i].size()<<"\n";
    }
    cout<<"finshed" <<"\n";
    */

}


/***************************************************************************/


//function to calculate number of variables
int num_vars_func(){

string equation_n;          //string to hold one equation
string x = "x";    // string to compare
int max_num_of_variables = 0; //integer to hold maximum number of variables in all equa
for(int i = 0;i<n;i++){
    equation_n = array[i];     //store the equation from array

    int counter = 0;   //counter to count num of x

    //count how many "x" in one string (equation)
    for (int j = 0;j<equation_n.size();j++){
        string current_str; //string to hold one char of equation

        //to move along the string and for every x counter will increase by 1 so we can count how many x
        current_str = equation_n.at(j);
        if (current_str.compare(x) == 0){counter++;}
    }
    num_of_variables[i] = counter; //store every equation number of variables

    //to calculate the max num of var of all equations
    if(num_of_variables[i] >= max_num_of_variables){
        max_num_of_variables = num_of_variables[i];}
}
return max_num_of_variables; //return its value
}


 //function to print number of variables
void num_vars_func_output(){
cout << num_vars_func() <<"\n"; //print the max num of var
}



/***************************************************************************/


//function to put equations in proper form and convert it to array of float numbers
void proper_form_func(){

int max_num_of_var;
max_num_of_var = num_vars_func();  //call the prev function to have max num of var of all equations



for (int i = 0;i<n;i++)  {

    string equation_n;          //string to hold one equation
    equation_n = array[i];     //store the equation from array
    int num_of_var;
    num_of_var = num_of_variables[i];
    size_t pos_end_array[num_of_var];
    size_t pos_start_array[num_of_var];
    string sub_string[num_of_var];
    for(int j = 0;j < num_of_var;j++){
        string  str2;
        string  str3;
        ostringstream  ss;
        ss << j+1;
        str2 = ss.str();
        str3 = "x" + str2;
        size_t pos = equation_n.find(str3);
        pos_end_array[j] = pos;
        for (int k = pos_end_array[j];k>=0;k-- ){
            string sub;
            sub = equation_n.at(k);
            if (sub.compare("+") == 0){
                pos_start_array[j] =  k;
                break;
            }
            else if(sub.compare("-") == 0){
                pos_start_array[j] =  k;
                break;
            }
            else if (k == 0){
                pos_start_array[j] =  0;
            }
        }
    }
    for(int j = 0;j<num_of_var;j++){
        size_t pos_start = pos_start_array[j];
        size_t pos_end   = pos_end_array[j];
        size_t idx       = pos_end - pos_start;
        if (idx == 0){sub_string[j] = "1";}
        else if (idx == 1){
            string sub;
            sub = equation_n.at(pos_start);
            if (sub.compare("+") == 0){

                sub_string[j] = equation_n.substr(pos_start,idx)+"1";
            }
            else if (sub.compare("-") == 0){

                sub_string[j] = equation_n.substr(pos_start,idx)+"1";
            }
            else {
                sub_string[j] = equation_n.substr(pos_start,idx);
            }


        }
        else {sub_string[j] = equation_n.substr(pos_start,idx);}
        string sub_string_string = sub_string[j];
        coefficients_array[i][j] = atof(sub_string_string.c_str());

        }

}
for (int i = 0;i<n;i++){
    for(int j=0;j<max_num_of_var;j++){
        cout<<coefficients_array[i][j] <<"    ";

    }
cout<<"\n";
}
}
