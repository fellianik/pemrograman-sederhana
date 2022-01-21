#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 100

#define harga_terios 400000
#define harga_avanza 300000
#define harga_pajero 500000
#define harga_innova 350000

// Struct Mobil
typedef struct Mobil {
  char kode[10];
  char merk[10];
  int harga;
} Mobil;

// Struct Pelanggan
typedef struct Pelanggan {
  char nama[50];
  int lama_sewa;
  char mobil_sewa[10];
  int total;
  int bayar;
  int refund;
  char telp[15];
} Pelanggan;

// Pemanggilan Fungsi
void print_mobil(); // fungsi menampilkan menu mobil
void sort_harga_murah(); // fungsi sort mobil dari harga termurah (ascending)
void sort_harga_mahal(); // fungsi sort mobil dari harga termahal (descending)
void input_data(); // fungsi inputan data pelanggan
void transaksi(); // fungsi menampilkan transaksi pelanggan
void pembayaran(); // fungsi pembayaran pelanggan
void search_mobil(); // fungsi search berdasarkan mobil
void search_nama(); // fungsi search berdasarkan nama penyewa


// Program utama
int main(){
  int pilihan, pilihan_search, pilihan_sort, pilihan_sort_2, opsi_sort;
  Mobil mobil[4] = {
    {"MS01", "Terios", harga_terios},
    {"MS02", "Avanza", harga_avanza},
    {"MS03", "Pajero", harga_pajero},
    {"MS04", "Innova", harga_innova}
  };
  Pelanggan pelanggan[MAX];
  
  int n;
  n = sizeof(mobil) / sizeof(mobil[0]);

  printf(" sizeof mobil = %d\n", sizeof(mobil));
  printf(" sizeof mobil[0] = %d\n", sizeof(mobil[0]));
  printf(" sizeof n = %d\n", n);
  printf(" sizeof mobil kode = %d\n", sizeof(mobil[0].kode));
  printf(" sizeof mobil harga = %d\n", sizeof(mobil[0].harga));
  printf(" sizeof mobil merk = %d\n", sizeof(mobil[0].merk));


  do{
    printf("|===============================|\n");
    printf("|\tProgram Sewa Mobil\t|\n");
    printf("|===============================|\n");
    printf("|\tMENU PELANGGAN\t|\n");
    printf("|-------------------------------|\n");
    printf("|1. Melihat Harga Mobil\t\t|\n");
    printf("|2. Sewa Mobil\t\t\t|\n");
    printf("|3. Melihat Data Transaksi\t|\n");
    printf("|4. Pembayaran\t\t|\n");
    printf("|5. Pencarian\t\t|\n");
    printf("|6. Keluar\t\t\t|\n");
    printf("|===============================|\n");
    
    printf("\n");
    printf("Masukkan Pilihan: ");
    scanf("%d", &pilihan);
    
    switch(pilihan){
      case 1:
        printf("\nMelihat Harga Mobil:\n");
        printf("1. Berdasarkan Kode Mobil\n");
        printf("2. Berdasarkan Harga Sewa Mobil\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan_sort);

        if (pilihan_sort == 1){
          printf("\n");
          print_mobil(mobil);
          printf("\n");
        }

        else if (pilihan_sort == 2){
          printf("\nMelihat Harga Sewa Mobil:\n");
          printf("1. Berdasarkan Harga Termurah\n");
          printf("2. Berdasarkan Harga Termahal\n");
          printf("Masukkan Pilihan: ");
          scanf("%d", &opsi_sort);
          if (opsi_sort == 1){
            printf("\n");
            sort_harga_murah(mobil, n);
          }
          else if (opsi_sort == 2){
            printf("\n");
            sort_harga_mahal(mobil,n);
          }
          else{
            printf("Masukkan Salah!");
          }
        }

        getch();
        break;

      case 2:
        input_data(pelanggan);
        getch();
        break;

      case 3:
        transaksi(pelanggan, mobil);
        getch();
        break;

      case 4:
        pembayaran(pelanggan, mobil);
        getch();
        break;

      case 5:
        printf("|-------------------------------|\n");
        printf("|\tPencarian\t|\n");
        printf("|-------------------------------|\n");
        printf("|1. Berdasarkan Nama Mobil\t|\n");
        printf("|2. Berdasarkan Nama Penyewa\t|\n");
        printf("|-------------------------------|\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan_search);
        if (pilihan_search == 1){
          search_mobil(pelanggan, mobil);
        }
        else if(pilihan_search == 2){
          search_nama(pelanggan, mobil);
        }
        break;
     
      case 6:
        exit(0);
        break;

      default:
        printf("Pilihan Salah\n\n");
        break;
    }
  } while (pilihan != 6);
}

void print_mobil(Mobil mobil[]){
  int i;
  
  printf("|=======================================================|\n");
  printf("|\t\t\tPILIHAN MOBIL\t\t\t|\n");
  printf("|=======================================================|\n");
  printf("| No\t| Kode Mobil\t| Merk Mobil\t|Harga Sewa/Hari|\n");
  printf("|-------|---------------|---------------|---------------|\n");
  for (i = 0; i < 4; i++){  	
    printf("| %d\t| %s\t\t| %s\t| Rp. %d\t|\n", i+1, mobil[i].kode, mobil[i].merk, mobil[i].harga);
  }
  printf("|=======================================================|\n");
  
  printf("\n");
  printf("Sewa Mobil Bisa dilakukan di Menu Ke-2\n");
}

void sort_harga_murah(Mobil mobil[], int n){
  int i, j;
  struct Mobil temp;
  
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (mobil[j].harga > mobil[j+1].harga){
				temp = mobil[j];
				mobil[j] = mobil[j+1];
				mobil[j+1] = temp;
			}
		}
	}
	print_mobil(mobil);
}

void sort_harga_mahal(Mobil mobil[], int n){
  int i, j;
  struct Mobil temp;

  for(i = 0; i< n-1; i++){
    for(j = 0; j < n-i-1; j++){
      if(mobil[j].harga < mobil[j+1].harga){
        temp = mobil[j];
        mobil[j] = mobil[j+1];
        mobil[j+1] = temp;
      }
    }
  }
  print_mobil(mobil);
}

void input_data(Pelanggan pelanggan){
  int i;
  
  printf("DATA PELANGGAN\n");
  printf("Masukkan Data Diri Anda\n");
  printf("---------------------------------\n");

  printf("Nama\t\t\t: ");
  fflush(stdin); gets(pelanggan.nama);
  printf("No. Telepon\t\t: ");
  scanf("%s", pelanggan.telp);
  printf("Lama Sewa\t\t: ");
  scanf("%d", &pelanggan.lama_sewa);
  printf("Kode Mobil yang disewa\t: ");
  scanf("%s", pelanggan.mobil_sewa);
  
  printf("\n");
  printf("---------------------------------\n");
  printf("Pesanan anda sukses!\n");
  printf("TRANSAKSI BISA DILIHAT DI MENU KE-3\n");
  
  printf("\n");
  
}

void transaksi(Pelanggan pelanggan, Mobil mobil[4]){
  int i;
  
  printf("Data Transaksi\n");
  printf("---------------------------------\n");
  
  printf("Nama\t\t: %s\n", pelanggan.nama);
  printf("No. Telp\t: %s\n", pelanggan.telp);
  printf("Lama Sewa\t: %d\n", pelanggan.lama_sewa);
  printf("Mobil yang di Sewa: \n");
  
  for (i = 0; i < 4; i++){
  if (strcmp(pelanggan.mobil_sewa, mobil[i].kode) == 0){
      printf("\tKode Mobil\t\t: %s\n", mobil[i].kode);
      printf("\tMerk Mobil\t\t: %s\n", mobil[i].merk);
      printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[i].harga);
    }
  }

  for (i = 0; i < 4; i++){
		if (strcmp(pelanggan.mobil_sewa, mobil[i].kode) == 0){
			pelanggan.total = pelanggan.lama_sewa * mobil[i].harga;
		}
	}
  printf("Biaya yang di bayar\t: Rp. %d\n", pelanggan.total);
  
  printf("---------------------------------\n");
  printf("\n");
  printf("Lakukan Pembayaran!\n");
  printf("PEMBAYARAN DILAKUKAN DI MENU KE-4\n");
}

void pembayaran(Pelanggan pelanggan, Mobil mobil[]){
	int i;
	
	for (i = 0; i < 4; i++){
		if (strcmp(pelanggan.mobil_sewa, mobil[i].kode) == 0){
			pelanggan.total = pelanggan.lama_sewa * mobil[i].harga;
		}
	}
	
	printf("Pembayaran:\n");
	printf("Biaya yang di bayar\t: Rp. %d\n", pelanggan.total);
	printf("Uang yang dibayarkan\t: Rp. ");
	scanf("%d", &pelanggan.bayar);
	pelanggan.refund = pelanggan.bayar - pelanggan.total;
	printf("Uang kembalian\t\t: Rp. %d\n", pelanggan.refund);
}

void search_mobil(Pelanggan pelanggan[], Mobil mobil[]){
  char str_mobil[10];
  int i, j;

  printf("Masukkan Nama Mobil: ");
  scanf("%s", str_mobil);

  for (i = 0; i < 4; i++){
    if(strcmpi(str_mobil, mobil[i].merk) == 0){
      printf("\tKode Mobil\t\t: %s\n", mobil[i].kode);
      printf("\tMerk Mobil\t\t: %s\n", mobil[i].merk);
      printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[i].harga);
      for (j = 0; j < MAX; j++){
        if(strcmpi(pelanggan[j].mobil_sewa, mobil[i].kode) == 0){
          printf("Nama\t\t: %s\n", pelanggan[j].nama);
          printf("No. Telp\t: %s\n", pelanggan[j].telp);
          printf("Lama Sewa\t: %d\n", pelanggan[j].lama_sewa);
          printf("Total\t: Rp. %d\n", pelanggan[j].total);
        }
      }
  	}
  }
}

void search_nama(Pelanggan pelanggan[], Mobil mobil[]){
  char str_nama[50];
  int i, j;

  printf("Masukkan Nama Penyewa: ");
  fflush(stdin); gets(str_nama);

  for (i = 0; i < MAX; i++){
    if(strcmpi(str_nama, pelanggan[i].nama) == 0){
      printf("Nama\t\t: %s\n", pelanggan[i].nama);
      printf("No. Telp\t: %s\n", pelanggan[i].telp);
      printf("Lama Sewa\t: %d\n", pelanggan[i].lama_sewa);
      printf("Mobil yang di Sewa: \n");
      for (j = 0; j < 4; j++){
        if (strcmp(pelanggan[i].mobil_sewa, mobil[j].kode) == 0){
          printf("\tKode Mobil\t\t: %s\n", mobil[j].kode);
          printf("\tMerk Mobil\t\t: %s\n", mobil[j].merk);
          printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[j].harga);
        }
      }
      printf("Total Keseluruhan\t: Rp. %d\n", pelanggan[i].total);
    }
  }
}

