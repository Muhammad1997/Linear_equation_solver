#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
int main()
{
string str = "2x1+0.3x2-x3=16";
size_t pos_end_array[5];
size_t pos_start_array[5];
string sub_string[5];
float  coefficients_array[5];
for(int i = 0;i < 5;i++){
    string  str2;
    string  str3;
    ostringstream  ss;
    ss << i+1;
    str2 = ss.str();
    str3 = "x" + str2;
    size_t pos = str.find(str3);
    pos_end_array[i] = pos;
    for (int j = pos_end_array[i];j>=0;j-- ){
        string sub;
        sub = str.at(j);
        if (sub.compare("+") == 0){
            pos_start_array[i] =  j;
            break;
        }
        else if(sub.compare("-") == 0){
            pos_start_array[i] =  j;
            break;
        }
        else if (j == 0){
            pos_start_array[i] =  0;
        }
    }
}
cout<<"array of coefficients" <<"\n" <<"\n";
for(int i = 0;i<5;i++){
size_t pos_start = pos_start_array[i];
size_t pos_end   = pos_end_array[i];
size_t idx       = pos_end - pos_start;
if (idx == 0){sub_string[i] = "1";}
else if (idx == 1){
    string sub;
    sub = str.at(pos_start);
    if (sub.compare("+") == 0){

        sub_string[i] = str.substr(pos_start,idx)+"1";
    }
    else if (sub.compare("-") == 0){

        sub_string[i] = str.substr(pos_start,idx)+"1";
    }
    else {
        sub_string[i] = str.substr(pos_start,idx);
    }


}
else {sub_string[i] = str.substr(pos_start,idx);}
string sub_string_string = sub_string[i];
coefficients_array[i] = atof(sub_string_string.c_str());
cout<<coefficients_array[i] <<"    ";
}
/*
cout<<"pos_start_array" <<"\n";
for (int i = 0;i < 5;i++){
    cout<<pos_start_array[i] <<" ";
}
cout<<"\n";
cout<<"pos_end_array" <<"\n";
for (int i = 0;i < 5;i++){
    cout<<pos_end_array[i] <<" ";
}
*/

}
