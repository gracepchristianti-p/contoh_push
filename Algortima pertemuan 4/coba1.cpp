#include <iostream>
#include <string>
using namespace std;

int main (){
    string NamaDepan;
    string NamaBelakang;

cout << "======================================================" <<endl ;
cout << "Program mengisi data dan tampilkan data" <<endl ;
cout << "======================================================" <<endl ;

cout << "Masukkan Nama Depan : ";
getline (cin, NamaDepan);
   
cout << "Masukkan Nama Belakang : ";
getline (cin, NamaBelakang);

cout << "======================================================" <<endl ;
string hasil = "Halo " + NamaDepan + " " + NamaBelakang + "! Selamat Belajar Algoritma. "; //

cout << hasil << endl; //
cout << "======================================================" <<endl ;

return 0;
}