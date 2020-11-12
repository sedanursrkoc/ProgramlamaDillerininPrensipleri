/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Projemizi test eden program
* (Rastgele kişi üreterek bunları kişiler dosyasına yazar ve bu dosyadaki kişilere ait kimlik no ve IMEI no kontrolünü yapar)
* </p>
*/
#include "KimlikNo.h"
#include "IMEINo.h"
#include "RastgeleKisi.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "Kisi.h"

int main(){
	
	int sec = 0; 
	
	do{ //Çıkış işlemi seçilene kadar programın devam etmesi için koşullu döngü
		printf("[1] Rastgele Kisi Uret \n");
		printf("[2] Uretilmis Dosya Kontrol Et \n");
		printf("[3] Cikis \n");
		printf("Secim:");
	
		
		scanf("%d", &sec);
		FILE *dosya;
		FILE *dosya2;
		
		
		switch(sec){ //Menüden seçilen işleme göre gerekli işlemlerin gerçekleştirilmesi  
            case 1:
			
				dosya = fopen("Kisiler.txt", "w");

                printf("Kac adet kisi uretilecek?: ");

                int KisiSayi = 0;
				scanf("%d", &KisiSayi);
				
				RastgeleKisi rastgelekisi = RastgeleKisiOlustur();
                for (int i = 0; i < KisiSayi; i++) { //Rastgele kişi oluşturarak kişilerin bilgilerini dosyaya yazdırma 
					if(i == KisiSayi - 1) fprintf ( dosya, "%s", rastgelekisi->rastgelekisi(rastgelekisi)); 
					else fprintf ( dosya, "%s\n", rastgelekisi->rastgelekisi(rastgelekisi)); 
                } 
				fclose( dosya );
				rastgelekisi->yoket(rastgelekisi);
            break;
			
            case 2:
				
				if ( ( dosya2 = fopen( "Kisiler.txt", "r" ) ) == NULL ) //Dosya varsa açılıp dosya değişkenine atanır
					printf( "Dosya acilamadi\n" );
				else //Geçerli ve geçersiz kimlik ve imei numaralarının sayılarının bulanarak yazdırılması
				{
					KimlikNo kimlik = KimlikNoOlustur();
					IMEINo imei = IMEINoOlustur();
					char *gecici; char *gecici2;
					gecici = (char*)malloc(sizeof(char)*11);
					gecici2 = (char*)malloc(sizeof(char)*300);
					int i = 0;
					int GecerliKimlikNo = 0;
					int GecerliIMEINo = 0;
					int GecersizKimlikNo = 0;
					int GecersizIMEINo = 0;

					while ( !feof( dosya2 ) ){ //Dosya sonuna sonuna kadar okuma kontrolü
						fscanf(dosya2, "%s %s %s %s %s %s", &gecici[i], &gecici2[i], &gecici2[i], &gecici2[i], &gecici2[i], &gecici2[i]); 
						
						if(strcmp(kimlik->dogrula(gecici),"Gecerli") == 0){ //Geçerli Kimlik numaralarının sayısı bulunur
							GecerliKimlikNo++;
						}
						else GecersizKimlikNo++; //Geçersiz Kimlik numaralarının sayısı bulunur
						
						if(strcmp(imei->dogrula(gecici2),"Gecerli") == 0){ //Geçerli IMEI numaralarının sayısı bulunur
							GecerliIMEINo++;
						}
						else GecersizIMEINo++; //Geçersiz IMEI numaralarının sayısı bulunur
					}
					
					printf("T.C. Kimlik Kontrol\n%d Gecerli\n%d Gecersiz\n\n",GecerliKimlikNo, GecersizKimlikNo); 
					printf("IMEI  Kontrol\n%d Gecerli\n%d Gecersiz\n",GecerliIMEINo, GecersizIMEINo); 
					
					kimlik->yoket(kimlik);
					imei->yoket(imei);
					free(gecici);
					free(gecici2);
				}
            break;
            case 3:
                break;
            default:
                printf("Yanlis tercih!\n");
            break;
        }

    }while(sec != 3);
	
}