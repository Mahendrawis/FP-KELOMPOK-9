#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void inputpenjual();
void ubahrumah();
void close();
void hapusrumah();
void lihatpenjual();
struct rumah{
    int id,tipe;
    char alamat[60];
    int kamar_mandi;
    int kamar_tidur;
    int lantai;
    double harga;
}rmh, cek, hapus;

int main(){
    int pilih;
    menu:

    system("cls");
        printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
        printf("\n[1] Penjual");
        printf("\n[2] Pembeli");
        printf("\n\n ==> Masukkan Pilihan : ");
        scanf("%d", &pilih);
        if(pilih == 1){
            penjual:
            system("cls");
            printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
            printf("\n[1] Input Rumah");
            printf("\n[2] Lihat Rumah");
            printf("\n[3] Ubah Rumah");
            printf("\n[4] Hapus Rumah");
            printf("\n[5] Lihat Urut");
            printf("\n[6] Cari Rumah");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
            if(pilih == 1){
                inputpenjual();
                goto menu;
            }
            else if(pilih == 2){
                lihatpenjual();
            }
            else if(pilih == 3){
                ubahrumah();
            }
            else if(pilih == 4){
                hapusrumah();
            }
            else if(pilih == 5){
                system("cls");
                printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
                printf("\n[1] Urut Tipe");
                printf("\n[2] Urut Alamat");
                printf("\n[3] Urut Kamar Tidur");
                printf("\n[4] Urut Kamar Mandi");
                printf("\n[5] Urut Harga");
                printf("\n[0] Exit");
                printf("\n\n ==> Masukkan Pilihan : ");
                scanf("%d", &pilih);
                if(pilih == 1){
                    //uruttipe();
                }
                else{
                    goto penjual;
                }
            }
            else if(pilih == 0){
                exit(0);
            }
        }
        else if(pilih == 2){
            system("cls");
            printf("\n ======   PERUMAHAN TADIKA MESRA    ======\n");
            printf("\n[1] Lihat Rumah");
            printf("\n[2] Lihat Urut");
            printf("\n[3] Cari Rumah");
            printf("\n[4] Beli Rumah");
            printf("\n[0] Exit");
            printf("\n\n ==> Masukkan Pilihan : ");
            scanf("%d", &pilih);
        }
    
}

void inputpenjual(){
    FILE *fptr, *fptr1;
    int count=0;
    
    fptr=fopen("TADIKAMESRA.txt","a");
    system("cls");
    fptr1=fopen("TADIKAMESRA.txt","r");
    while (fscanf(fptr1,"%d %d %s %d %d %d %lf",&rmh.id,&rmh.tipe,rmh.alamat,&rmh.kamar_tidur,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF)
		{
			rmh.id++;	
		}
		cek.id = rmh.id;
		fclose(fptr1);
		printf ("Masukan tipe  : ");fflush(stdin);
		scanf ("%d", &rmh.tipe);
		printf ("Masukan alamat   : ");fflush(stdin);
		gets(rmh.alamat);
		printf("Masukan jumlah kamar tidur   : ");fflush(stdin);
		scanf("%d", &rmh.kamar_tidur);
        printf("Masukan jumlah kamar mandi    : ");
		scanf("%d", &rmh.kamar_mandi);
        printf("Masukan jumlah lantai   : ");
		scanf("%d", &rmh.lantai);
        printf("Masukan harga   : ");
		scanf("%lf", &rmh.harga);
		fprintf(fptr,"%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
		fclose(fptr);
		printf("\n\nData Telah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': 
				main();
        		break;
        	case '0': 
				close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}

void lihatpenjual(){
    FILE *view;
	int test=0;
	view=fopen("TADIKAMESRA.txt","r");
	printf("%s %s %s %s %s %s %s \n\n", "ID","Tipe Rumah", "Alamat", "Jml. K. Tidur", "Jml. K. Mandi", "Jml. Lantai", "Harga");
	while(fscanf(view,"%d %d %s %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF)
		{
			printf("%d %d %s %d %d %d %.lf \n", rmh.id, rmh.tipe, rmh.alamat, rmh.kamar_tidur ,rmh.kamar_mandi, rmh.lantai, rmh.harga);
			test++;
		}
	printf("\n");
	printf("jumlah banyak data rumah : %d ", test);
	fclose(view);
		if(test==0)
	{
		system("cls");
		printf ("\nData Kosong ! \n");
	}
	list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': main();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}

void close(){
}

void ubahrumah(){
    int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("TADIKAMESRA.txt","r");
	baru = fopen("TADIKABARU.txt","w");
	system("cls");
	printf ("Masukan ID Rumah : ");
	scanf ("%d",&cek.id);
	while(fscanf(lama, "%d %d %s %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF)
	{
		if(rmh.id == cek.id)
		{
			test=1;
			ganti:
				printf("\nNo. ID : %d dimiliki Rumah dengan Tipe : %d Alamat : %s K. Tidur : %d K. Mandi %d Lantai %d dan Harga %.lf", rmh.id, rmh.tipe, rmh.alamat, rmh.kamar_tidur ,rmh.kamar_mandi, rmh.lantai, rmh.harga);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1] Tipe");
				printf("\n[2] Alamat");
				printf("\n[3] Jumlah kamar tidur");
                printf("\n[4] Jumlah kamar mandi");
                printf("\n[5] Jumlah lantai");
                printf("\n[6] Harga Rumah");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				
				if(pilih == 1)
				{
					printf ("\nMasukan Tipe Rumah : ");fflush(stdin);
					scanf ("%d", &cek.tipe);
					rmh.tipe = cek.tipe;
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 2)
				{
					printf("\nMasukan Alamat Rumah : ");fflush(stdin);
					gets(cek.alamat);
					strcpy(rmh.alamat, cek.alamat);
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else if (pilih == 3)
				{
					printf ("\nMasukan Jumlah kamar tidur : ");
					scanf ("%d", &cek.kamar_tidur);
					rmh.kamar_tidur = cek.kamar_tidur;
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
                else if (pilih == 4)
				{
					printf ("\nMasukan Jumlah kamar mandi : ");
					scanf ("%d", &cek.kamar_mandi);
					rmh.kamar_mandi = cek.kamar_mandi;
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
                else if (pilih == 5)
				{
					printf ("\nMasukan Jumlah Lantai : ");
					scanf ("%d", &cek.lantai);
					rmh.kamar_tidur = cek.lantai;
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
                else if (pilih == 6)
				{
					printf ("\nMasukan Harga : ");
					scanf ("%lf", &cek.harga);
					rmh.harga = cek.harga;
					fprintf(baru, "%d %d %s %d %d %d %lf \n",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
					printf ("\nPerubahan Sudah Disimpan !");
				}
				else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}
		else
		{
			fprintf(baru, "%d %d %s %d %d %d %lf",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
		}
	}

	fclose(lama);
	fclose(baru);
	remove("TADIKAMESRA.txt");
	rename("TADIKABARU.txt","TADIKAMESRA.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': ubahrumah();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

void hapusrumah(){
    FILE *lama, *baru;
    int test=0;
    lama = fopen("TADIKAMESRA.txt","r");
	baru = fopen("TADIKABARU.txt","w");
    system("cls");
    printf("Input No.Id Rumah yang mau dihapus : ");
    scanf("%d", &hapus.id);
    while(fscanf(lama,"%d %d %s %d %d %d %lf",&rmh.id, &rmh.tipe, rmh.alamat, &rmh.kamar_tidur ,&rmh.kamar_mandi, &rmh.lantai, &rmh.harga)!=EOF){
        if(rmh.id != hapus.id){
            fprintf(baru,"%d %d %s %d %d %d %lf",rmh.id,rmh.tipe,rmh.alamat,rmh.kamar_tidur,rmh.kamar_mandi,rmh.lantai,rmh.harga);
        }else{
            test++;
            printf("\nData Rumah No ID : %d dengan Alamat : %s\n",rmh.id,rmh.alamat);
			printf("\nBerhasil dihapus dari Daftar !");
        }
    }
    fclose(lama);
	fclose(baru);
	remove("TADIKAMESRA.txt");
	rename("TADIKABARU.txt","TADIKAMESRA.txt");
	if(test==0){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': ubahrumah();
            	break;
            case '1': main();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': main();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}

void uruttipe(){

}




