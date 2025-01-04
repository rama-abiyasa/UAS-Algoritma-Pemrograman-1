#include <iostream>
#include <string>
using namespace std;

int main() {
    float saldo, totalPengeluaran = 0, jumlahPengeluaran;
    string kategori;
    
    // Meminta pengguna untuk memasukkan saldo awal
    cout << "Selamat datang di Aplikasi Keuangan Harian!" << endl;
    cout << "Masukkan saldo awal Anda: ";
    cin >> saldo;

    while (true) {
        // Menampilkan menu utama
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Pengeluaran" << endl;
        cout << "2. Tampilkan Total Pengeluaran" << endl;
        cout << "3. Tampilkan Sisa Saldo" << endl;
        cout << "4. Keluar" << endl;

        // Meminta pengguna memilih opsi
        int pilihan;
        cout << "Pilih opsi (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Menambah pengeluaran
            cout << "Masukkan nama kategori pengeluaran: ";
            cin.ignore();  // Mengabaikan karakter newline yang tersisa
            getline(cin, kategori);
            cout << "Masukkan jumlah pengeluaran: ";
            cin >> jumlahPengeluaran;
            totalPengeluaran += jumlahPengeluaran;
            saldo -= jumlahPengeluaran;
            cout << "Pengeluaran berhasil ditambahkan!" << endl;
        }
        else if (pilihan == 2) {
            // Menampilkan total pengeluaran
            cout << "Total pengeluaran Anda: " << totalPengeluaran << endl;
        }
        else if (pilihan == 3) {
            // Menampilkan sisa saldo
            cout << "Sisa saldo Anda: " << saldo << endl;
        }
        else if (pilihan == 4) {
            // Keluar dari aplikasi
            cout << "Terima kasih telah menggunakan Aplikasi Keuangan Harian!" << endl;
            break;
        }
        else {
            cout << "Opsi tidak valid. Silakan pilih opsi yang benar." << endl;
        }
    }

    return 0;
}
