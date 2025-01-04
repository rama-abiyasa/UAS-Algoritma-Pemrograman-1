#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float nilaiAkhir;
};

// Fungsi untuk menambahkan data mahasiswa
void tambahData(vector<Mahasiswa>& data) {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        Mahasiswa mhs;
        cout << "Masukkan NIM Mahasiswa ke-" << i + 1 << ": ";
        cin >> mhs.nim;
        cout << "Masukkan Nama Mahasiswa ke-" << i + 1 << ": ";
        cin.ignore(); // Mengabaikan karakter newline
        getline(cin, mhs.nama);
        cout << "Masukkan Nilai Akhir Mahasiswa ke-" << i + 1 << ": ";
        cin >> mhs.nilaiAkhir;
        data.push_back(mhs);
    }
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilkanData(const vector<Mahasiswa>& data) {
    cout << "\nDaftar Data Mahasiswa:" << endl;
    for (const auto& mhs : data) {
        cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilaiAkhir << endl;
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariData(const vector<Mahasiswa>& data) {
    string nimCari;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    bool ditemukan = false;
    for (const auto& mhs : data) {
        if (mhs.nim == nimCari) {
            cout << "Data ditemukan:\n";
            cout << "NIM: " << mhs.nim << ", Nama: " << mhs.nama << ", Nilai Akhir: " << mhs.nilaiAkhir << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk mengurutkan data mahasiswa berdasarkan Nilai Akhir secara menurun
void urutkanData(vector<Mahasiswa>& data) {
    sort(data.begin(), data.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.nilaiAkhir > b.nilaiAkhir;
    });
    cout << "Data berhasil diurutkan berdasarkan Nilai Akhir (descending)." << endl;
}

// Fungsi untuk menyimpan data mahasiswa ke berkas
void simpanDataKeBerkas(const vector<Mahasiswa>& data) {
    ofstream file("data_mahasiswa.txt");
    if (file.is_open()) {
        for (const auto& mhs : data) {
            file << mhs.nim << "," << mhs.nama << "," << mhs.nilaiAkhir << endl;
        }
        file.close();
        cout << "Data berhasil disimpan ke berkas!" << endl;
    } else {
        cout << "Gagal membuka berkas!" << endl;
    }
}

// Fungsi untuk membaca data mahasiswa dari berkas
void bacaDataDariBerkas(vector<Mahasiswa>& data) {
    ifstream file("data_mahasiswa.txt");
    if (file.is_open()) {
        data.clear(); // Membersihkan data lama
        string line;
        while (getline(file, line)) {
            Mahasiswa mhs;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            mhs.nim = line.substr(0, pos1);
            mhs.nama = line.substr(pos1 + 1, pos2 - pos1 - 1);
            mhs.nilaiAkhir = stof(line.substr(pos2 + 1));
            data.push_back(mhs);
        }
        file.close();
        cout << "Data berhasil dibaca dari berkas!" << endl;
    } else {
        cout << "Gagal membuka berkas!" << endl;
    }
}

int main() {
    vector<Mahasiswa> dataMahasiswa;
    int pilihan;

    while (true) {
        // Menampilkan menu utama
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Data" << endl;
        cout << "3. Cari Data Mahasiswa" << endl;
        cout << "4. Urutkan Data" << endl;
        cout << "5. Simpan Data ke Berkas" << endl;
        cout << "6. Baca Data dari Berkas" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih opsi (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(dataMahasiswa);
                break;
            case 2:
                tampilkanData(dataMahasiswa);
                break;
            case 3:
                cariData(dataMahasiswa);
                break;
            case 4:
                urutkanData(dataMahasiswa);
                break;
            case 5:
                simpanDataKeBerkas(dataMahasiswa);
                break;
            case 6:
                bacaDataDariBerkas(dataMahasiswa);
                break;
            case 7:
                cout << "Terima kasih! Program selesai." << endl;
                return 0;
            default:
                cout << "Opsi tidak valid. Silakan pilih opsi yang benar." << endl;
        }
    }
}
