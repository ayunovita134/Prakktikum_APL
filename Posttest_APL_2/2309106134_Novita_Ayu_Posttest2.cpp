#include <iostream>
#include <string>
using namespace std;

string nama_benar = "Novita";
string NIM_benar = "2309106134";

bool login() {
    int i = 0;
    string nama, NIM;

    while (i < 3) {
        cout << "Masukkan nama: ";
        cin >> nama;
        cout << "Masukkan NIM: ";
        cin >> NIM;

        if (nama == nama_benar && NIM == NIM_benar) {
            cout << "Selamat, login berhasil!" << endl;
            return true;
        } else {
            cout << "Maaf, login gagal." << endl;
            i++;
        }
    }

    cout << "Anda telah mencapai batas percobaan login. Program berhenti." << endl;
    return false;
}

string nama[100], nomor_identifikasi[100], jenis_kejahatan[100], tanggal_masuk_penjara[100], jangka_waktu_hukuman[100], status_kesehatan[100];
string loop;
int pos = 0;


void display() {
  cout << endl << "=== Daftar Narapidana ===" << endl;
  for (int i = 0; i < pos; i++) {
    cout << "Nama: " << nama[i] << endl;
    cout << "Nomor Identifikasi: " << nomor_identifikasi[i] << endl;
    cout << "Jenis Kejahatan: " << jenis_kejahatan[i] << endl;
    cout << "Tanggal Masuk Penjara: " << tanggal_masuk_penjara[i] << endl;
    cout << "Jangka Waktu Hukuman: " << jangka_waktu_hukuman[i] << endl;
    cout << "Status Kesehatan: " << status_kesehatan[i] << endl;
    cout << endl;
  }
}

void add() {
  int max = 100;
  char loop;
  do {
    display();
    if (pos < max) {
      cin.ignore(); 
      cout << "Masukkan nama narapidana: ";
      getline(cin, nama[pos]);
      cout << "Masukkan nomor identifikasi narapidana: ";
      getline(cin, nomor_identifikasi[pos]);
      cout << "Masukkan jenis kejahatan: ";
      getline(cin, jenis_kejahatan[pos]);
      cout << "Masukkan tanggal masuk penjara: ";
      getline(cin, tanggal_masuk_penjara[pos]);
      cout << "Masukkan jangka waktu hukuman: ";
      getline(cin, jangka_waktu_hukuman[pos]);
      cout << "Masukkan status kesehatan: ";
      getline(cin, status_kesehatan[pos]);

      pos++;
      cout << "Tambahkan data narapidana baru (y/t): ";
      cin >> loop;
    }
  } while (loop == 'y');
}

void edit() {
  int y;
  do {
    cin.ignore();
    display();
    cout << "Masukkan nomor narapidana yang ingin diubah: ";
    cin >> y;

    if (y >= 1 && y <= pos) {
      cout << "Masukkan nama narapidana baru: ";
      getline(cin, nama[y - 1]);
      cout << "Masukkan nomor identifikasi narapidana baru: ";
      getline(cin, nomor_identifikasi[y - 1]);
      cout << "Masukkan jenis kejahatan narapidana baru: ";
      getline(cin, jenis_kejahatan[y - 1]);
      cout << "Masukkan tanggal masuk penjara narapidana baru: ";
      getline(cin, tanggal_masuk_penjara[y - 1]);
      cout << "Masukkan jangka waktu hukuman narapidana baru: ";
      getline(cin, jangka_waktu_hukuman[y - 1]);
      cout << "Masukkan status kesehatan narapidana baru: ";
      getline(cin, status_kesehatan[y - 1]);

      display();
      cout << "Ubah data narapidana lain (y/t): ";
      cin >> loop;
    } else {
      cout << "Nomor narapidana tidak valid." << endl;
    }
  } while (loop == "y");
}

void del() {
	int index;
	do {
		display();
		if (pos > 0) {
			cout << "Hapus data ke: ";
			cin >> index;
			cin.ignore();  

			if (index >= 1 && index <= pos) {
				for (int i = index; i < pos; i++) {
					nama[i - 1] = nama[i];
					nomor_identifikasi[i - 1] = nomor_identifikasi[i];
					jenis_kejahatan[i - 1] = jenis_kejahatan[i];
					tanggal_masuk_penjara[i - 1] = tanggal_masuk_penjara[i];
					jangka_waktu_hukuman[i - 1] = jangka_waktu_hukuman[i];
					status_kesehatan[i - 1] = status_kesehatan[i];
				}
				pos--;
				display();
				cout << "Hapus data narapidana lain (y/t): ";
				cin >> loop;
			} else {
				cout << "Nomor narapidana tidak valid." << endl;
				cout << "Hapus data narapidana lain (y/t): ";
				cin >> loop;
			}
		} else {
			cout << "Data kosong. Isikan t: ";
			cin >> loop;
		}
	} while (loop == "y");
}

int main() {
    if (!login()) {
        cout << "Login gagal. Program berhenti." << endl;
        return 0;
    }

    int pilihan;
    do {
        cout << "::: DATA NARAPIDANA :::" << endl;
        cout << "-----------------------" << endl;

        cout << "[1]. Tambahkan data narapidana " << endl;
        cout << "[2]. Tampilkan data narapidana " << endl;
        cout << "[3]. Ubah data narapidana " << endl;
        cout << "[4]. Hapus data narapidana " << endl;
        cout << "[5]. Keluar" << endl;

        cout << "Pilih Menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1 :
                add() ;
                break ;
            case 2 :
                display() ;
                break;
            case 3 :
                edit() ;
                break ;
            case 4 :
                del() ;
                break ;
            case 5 :
                cout << "Keluar. " << endl ;
                break ;
            default :
                cout << "Pilihan tidak valid." << endl ;
                break ;
        }
    } while (pilihan != 5) ;

    cout << "PROGRAM SELESAI..." << endl;
    return 0;
}

