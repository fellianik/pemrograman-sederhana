#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_CUSTOMER 100

#define harga_terios 400000
#define harga_avanza 300000
#define harga_pajero 500000
#define harga_innova 350000

int jumlah_customer = 0;

typedef struct CARS {
    char kode[10];
    char merk[10];
    int harga;
} CARS;

typedef struct CUSTOMERS{
    char nama[50];
    char telp[15];
    int lama_sewa;
    char mobil_sewa[10];
    int total;
    int bayar;
    int refund;
} CUSTOMERS;


void print_mobil(CARS mobil[]){
    printf("|=======================================================|\n");
    printf("|\t\t\tPILIHAN MOBIL\t\t\t|\n");
    printf("|=======================================================|\n");
    printf("| No\t| Kode Mobil\t| Merk Mobil\t|Harga Sewa/Hari|\n");
    printf("|-------|---------------|---------------|---------------|\n");
    int i;  
    for (i = 0; i < 4; i++){
        printf("| %d\t| %s\t\t| %s\t| Rp. %d\t|\n", i+1, mobil[i].kode, mobil[i].merk, mobil[i].harga);
    }	
    
    printf("|=======================================================|\n");

    printf("\n");
    printf("Sewa Mobil Bisa dilakukan di Menu Ke-2\n");
    printf("\n");
}

void sort_harga_murah(CARS mobil[], int n){
    int i, j;
    CARS temp;
    
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

void sort_harga_mahal(CARS mobil[], int n){
    int i, j;
    CARS temp;

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

CUSTOMERS input_data(){
    CUSTOMERS z_customer;

    printf("DATA PELANGGAN\n");
    printf("Masukkan Data Diri Anda\n");
    printf("---------------------------------\n");

    printf("Nama\t\t\t: ");
    fflush(stdin); gets(z_customer.nama);
    printf("No. Telepon\t\t: ");
    scanf("%s", z_customer.telp);
    printf("Lama Sewa\t\t: ");
    scanf("%d", &z_customer.lama_sewa);
    printf("Kode Mobil yang disewa\t: ");
    scanf("%s", z_customer.mobil_sewa);
    
    printf("\n");
    printf("---------------------------------\n");
    printf("Pesanan anda sukses!\n");
    printf("TRANSAKSI BISA DILIHAT DI MENU KE-3\n");
    
    printf("\n");

    return z_customer;
}

void transaksi(CUSTOMERS pelanggan, CARS mobil[]){
    int i, j;
    
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
            pelanggan.total = pelanggan.lama_sewa * mobil[i].harga;
        }
    }
    printf("TOTAL yang dibayarkan = Rp. %d\n", pelanggan.total);
    
    printf("---------------------------------\n");
    printf("\n");
    printf("Lakukan Pembayaran!\n");
    printf("PEMBAYARAN DILAKUKAN DI MENU KE-4\n");
}

void pembayaran(CUSTOMERS pelanggan, CARS mobil[]){
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

void tampil_data(CUSTOMERS pelanggan[], CARS mobil[]){
    int i,j;

    for (i = 0; i < jumlah_customer; i++){
        printf("Nama\t\t: %s\n", pelanggan[i].nama);
        printf("No. Telp\t: %s\n", pelanggan[i].telp);
        printf("Lama Sewa\t: %d\n", pelanggan[i].lama_sewa);
        printf("Mobil yang di Sewa: \n");
        pelanggan[i].total = 0;
        for (j = 0; j < 4; j++){
            if (strcmp(pelanggan[i].mobil_sewa, mobil[j].kode) == 0){
                printf("\tKode Mobil\t\t: %s\n", mobil[j].kode);
                printf("\tMerk Mobil\t\t: %s\n", mobil[j].merk);
                printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[j].harga);
                pelanggan[i].total = pelanggan[i].total + mobil[j].harga * pelanggan[i].lama_sewa;
            }
        }
        printf("TOTAL = Rp. %d\n", pelanggan[i].total);
        printf("\n\n");
    }
}

void search_mobil(CUSTOMERS pelanggan[], CARS mobil[]){
    char str_mobil[10];
    int i, j;

    printf("Masukkan Nama Mobil: ");
    scanf("%s", str_mobil);

    for (i = 0; i < 4; i++){
        if(strcmpi(str_mobil, mobil[i].merk) == 0){
            printf("\tKode Mobil\t\t: %s\n", mobil[i].kode);
            printf("\tMerk Mobil\t\t: %s\n", mobil[i].merk);
            printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[i].harga);

            for (j = 0; j < jumlah_customer; j++){
                pelanggan[j].total = 0;
                if(strcmpi(pelanggan[j].mobil_sewa, mobil[i].kode) == 0){
                    printf("Nama\t\t: %s\n", pelanggan[j].nama);
                    printf("No. Telp\t: %s\n", pelanggan[j].telp);
                    printf("Lama Sewa\t: %d\n", pelanggan[j].lama_sewa);
                    pelanggan[j].total = pelanggan[j].total + mobil[i].harga * pelanggan[j].lama_sewa;
                    printf("Total\t: Rp. %d\n", pelanggan[j].total);
                }
            }
        }
    }
}

void search_nama(CUSTOMERS pelanggan[], CARS mobil[]){
    char str_nama[50];
    int i, j;

    printf("Masukkan Nama Penyewa: ");
    fflush(stdin); gets(str_nama);

    for (i = 0; i < jumlah_customer; i++){
        if(strcmpi(str_nama, pelanggan[i].nama) == 0){
            printf("Nama\t\t: %s\n", pelanggan[i].nama);
            printf("No. Telp\t: %s\n", pelanggan[i].telp);
            printf("Lama Sewa\t: %d\n", pelanggan[i].lama_sewa);
            printf("Mobil yang di Sewa: \n");

            pelanggan[i].total = 0;
            for (j = 0; j < 4; j++){
                if (strcmp(pelanggan[i].mobil_sewa, mobil[j].kode) == 0){
                    printf("\tKode Mobil\t\t: %s\n", mobil[j].kode);
                    printf("\tMerk Mobil\t\t: %s\n", mobil[j].merk);
                    printf("\tHarga Sewa Mobil\t: Rp. %d\n", mobil[j].harga);
                    pelanggan[i].total = pelanggan[i].total + mobil[j].harga * pelanggan[i].lama_sewa;
                }
            }
            printf("Total Keseluruhan\t: Rp. %d\n", pelanggan[i].total);
        }
    }
}

void sort_total_murah(CUSTOMERS pelanggan[], int n, CARS mobil[]){
    int i, j, k;
    CUSTOMERS temp;

	for (i = 0; i < n-1; i++){
		for (j = 0; j < n-i-1; j++){
			if (pelanggan[j].total > pelanggan[j+1].total){
				temp = pelanggan[j];
				pelanggan[j] = pelanggan[j+1];
				pelanggan[j+1] = temp;
			}
		}
	}
    
    for (i = 0; i < jumlah_customer; i++){
        for(j = 0; j<4; j++){
            if (strcmp(pelanggan[i].mobil_sewa, mobil[j].kode) == 0){
                pelanggan[i].total = pelanggan[i].lama_sewa * mobil[j].harga;
            }
		}
	}

    for ( k = 0; k < jumlah_customer; k++) {
        printf("Nama\t\t: %s\n", pelanggan[k].nama);
        printf("Total Keseluruhan: Rp. %d\n", pelanggan[k].total);
        printf("\n");
    }

}

void sort_total_mahal(CUSTOMERS pelanggan[], int n, CARS mobil[]){
    int i, j, k;
    CUSTOMERS temp;

    for(i = 0; i< n-1; i++){
        for(j = 0; j < n-i-1; j++){
        if(pelanggan[j].total < pelanggan[j+1].total){
                temp = pelanggan[j];
                pelanggan[j] = pelanggan[j+1];
                pelanggan[j+1] = temp;
            }
        }
    }

    for (i = 0; i < jumlah_customer; i++){
        for(j = 0; j<4; j++){
            if (strcmp(pelanggan[i].mobil_sewa, mobil[j].kode) == 0){
                pelanggan[i].total = pelanggan[i].lama_sewa * mobil[j].harga;
            }
		}
	}

    for ( k = 0; k < jumlah_customer; k++) {
        printf("Nama\t\t: %s\n", pelanggan[k].nama);
        printf("Total Keseluruhan: Rp. %d\n", pelanggan[k].total);
        printf("\n");
    }
}


int main(){
    CUSTOMERS customer[MAX_CUSTOMER];

    CARS mobil[4] = {
        {"MS01", "Terios", harga_terios},
        {"MS02", "Avanza", harga_avanza},
        {"MS03", "Pajero", harga_pajero},
        {"MS04", "Innova", harga_innova}
    };

    int pilihan;
    int pilihan_sort;
    int opsi_sort;
    int pilihan_search;
    int pilihan_sort_2;

    int n;
    n = sizeof(mobil) / sizeof(mobil[0]);

    do{
        printf("|=======================================|\n");
        printf("|\tProgram Sewa Mobil\t\t|\n");
        printf("|=======================================|\n");
        printf("|\tMENU PELANGGAN\t\t\t|\n");
        printf("|---------------------------------------|\n");
        printf("|1. Melihat Harga Mobil\t\t\t|\n");
        printf("|2. Sewa Mobil\t\t\t\t|\n");
        printf("|3. Data Transaksi & Pembayaran\t\t|\n");
        printf("|4. Pembayaran\t\t\t\t|\n");
        printf("|5. Tampil Data Pelanggan Keseluruhan\t|\n");
        printf("|6. Pencarian\t\t\t\t|\n");
        printf("|7. Sorting berdasarkan total harga sewa|\n");
        printf("|8. Keluar\t\t\t\t|\n");
        printf("|=======================================|\n");
        printf("\n");
        printf("Masukkan Pilihan: ");
        scanf("%d", &pilihan);

        CUSTOMERS a_customer;

        if (pilihan == 1){
            printf("\nMelihat Harga Mobil:\n");
            printf("1. Berdasarkan Kode Mobil\n");
            printf("2. Berdasarkan Harga Sewa Mobil\n");
            printf("Masukkan Pilihan: ");
            scanf("%d", &pilihan_sort);

            if (pilihan_sort == 1){
                printf("\n");
                print_mobil(mobil);
            }
            else if (pilihan_sort == 2){
                int i;
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
                    sort_harga_mahal(mobil, n);
                }
                else{
                    printf("Masukkan Salah!");
                }
            }
            getch();
        }
        else if (pilihan == 2){
            printf("\n");
            a_customer = input_data();
            customer[jumlah_customer] = a_customer;
            ++jumlah_customer;
            getch();
        } 
        else if (pilihan == 3){
            printf("\n");
            customer[jumlah_customer] = a_customer;
            transaksi(a_customer, mobil);
            printf("Biaya yang di bayar\t: Rp. %d\n", a_customer.total);
            getch();
        }
        else if (pilihan == 4){
            printf("\n");
            customer[jumlah_customer] = a_customer;
            pembayaran(a_customer, mobil);
            getch();
        }
        else if (pilihan == 5){
            printf("\n");
            tampil_data(customer, mobil);
            getch();
        }
        else if (pilihan == 6){
            printf("\n");
            printf("|-------------------------------|\n");
            printf("|\tPencarian\t|\n");
            printf("|-------------------------------|\n");
            printf("|1. Berdasarkan Nama Mobil\t|\n");
            printf("|2. Berdasarkan Nama Penyewa\t|\n");
            printf("|-------------------------------|\n");
            printf("Masukkan Pilihan: ");
            scanf("%d", &pilihan_search);
            if (pilihan_search == 1){
                printf("\n");
                search_mobil(customer, mobil);
                getch();
            }
            else if(pilihan_search == 2){
                printf("\n");
                search_nama(customer, mobil);
                getch();
            }
            else {
                printf("PILIHAN SALAH!\n");
            }
            
		}
        else if (pilihan == 7){
            printf("|-------------------------------|\n");
            printf("|Sorting berdasarkan total harga sewa|\n");
            printf("|-------------------------------|\n");
            printf("|1. Terendah ke Tertinggi\t|\n");
            printf("|2. Tertinggi ke Terendah\t|\n");
            printf("|-------------------------------|\n");
            printf("Masukkan Pilihan: ");
            scanf("%d", &pilihan_sort_2);
            if (pilihan_sort_2 == 1){
                printf("\n");
                sort_total_murah(customer, n, mobil);
                getch();
            }
            else if(pilihan_sort_2 == 2){
                printf("\n");
                sort_total_mahal(customer, n, mobil);
                getch();
            }
        }
        else{
            printf("PILIHAN SALAH!\n");
        }
    } while (pilihan != 8);
}
