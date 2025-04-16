// #include <iostream>
// using namespace std;

// void cekPointer(int *arr) {
//     cout << "Pointer p menunjuk ke array yang diterima" << arr[87] << endl;
// }

// int main() {
    
//     int array[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
//                     41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
//                     61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
//                     80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
//     cekPointer(array); // Pointer p menunjuk ke array yang diterima

//     // int a = 10;
//     // int *b = &a;

//     // cout << "Nilai a: " << a << endl; // Output: 10
//     // cout << "Alamat a: " << &a << endl; // Output: Alamat dari a

// }

// passByValue.cpp
// # include <iostream>
// using namespace std;
// struct Address{
//     string kota;
//     string provinsi;
//     string negara;
// };

// int main(){
//     // deklarasi variabel dengan struct
//     Address address1, address2;

//     // mengisi value address1
//     address1.kota = "Samarinda";
//     address1.provinsi = "Kalimantan Timur";
//     address1.negara = "Indonesia";

//     // mengcopy value address1 ke address2
//     address2 = address1;
//     // mengganti property kota dari samarinda ke ikn
//     address2.kota = "ikn";
//     // value address1
//     cout<< address1.kota<<endl;
//     // value address2
//     cout<< address2.kota;

// return 0;
// }

#include <iostream>

int main() {
  int angka[] = {10, 25, 5, 12, 8, 30, 15};
  int angkaCari;
  int* pointerAngka;
  int lokasi = -1;

  // Meminta input dari pengguna
  std::cout << "Masukkan angka yang ingin dicari: ";
  std::cin >> angkaCari;

  // Mencari angka menggunakan pointer
  for (int i = 0; i < sizeof(angka) / sizeof(angka[0]); ++i) {
    pointerAngka = &angka[i];
    if (*pointerAngka == angkaCari) {
      lokasi = i;
      break;
    }
  }

  // Menampilkan hasil
  if (lokasi != -1) {
    std::cout << "Angka " << angkaCari << " ditemukan di lokasi: " << lokasi << std::endl;
  } else {
    std::cout << "Angka " << angkaCari << " tidak ditemukan." << std::endl;
  }

  return 0;
}