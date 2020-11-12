/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Kimlik no oluşturan ve kimlik no geçerli mi kontrolü yapan kaynak dosyası
* </p>
*/
#include "Rastgele.h"
#include "KimlikNo.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
 
 
KimlikNo KimlikNoOlustur(){
 
	KimlikNo this;
	this = (KimlikNo)malloc(sizeof(struct KIMLIKNO));
	this->KimlikNoDizi = (int*)malloc(sizeof(int)*11);
	this->KimlikNoC = (char*)malloc(sizeof(char)*11);
	
	this->tekToplam = 0;
    this->ciftToplam = 0;
	
	Rastgele rastgele = RastgeleOlustur();
	
	do{ //Kimlik numarasının ilk basamağı 0 olamayacağından ayrı atama yapılır ve 0 sayısından farklı olana kadar atamaya devam edilir
        this->KimlikNoDizi[0] = rastgele->rastgele(rastgele) % 9 ;
    }while(this->KimlikNoDizi[0] == 0);
	
	
	this->tekToplam += this->KimlikNoDizi[0];
	
	int i;
	for (i = 1; i <= 8; i++) { //Kimlik numarasının 2. basamağından 9. basamağına kadar rastgele sayı ataması yapılır
            
            
        this->KimlikNoDizi[i] = rastgele->rastgele(rastgele) % 9 ;

            //Kimlik numarası algoritmasını gerçekleştirmek için tek ve çift basamakların toplamları bulunur
        if (i % 2 == 0){
            
            this->tekToplam += this->KimlikNoDizi[i];
        }
        else
            this->ciftToplam += this->KimlikNoDizi[i];
                    
    }
	
	this->KimlikNoDizi[9] = ( (this->tekToplam * 7) + (this->ciftToplam * 9) ) % 10 ;
    this->KimlikNoDizi[10] = (this->tekToplam * 8) % 10 ;
	
	this->kimlik = &KimlikNoUret;
	this->dogrula = &KimlikNoDogrula;
    this->yoket = &KimlikNoYoket;
	
	rastgele->yoket(rastgele);
	
	return this;
} 
    
 
char* KimlikNoUret(const KimlikNo this){
    
	int i;
    for (i = 0; i < 11; i++) { //Kimlik numarası için ürettiğimiz sayıları string bir ifadeye atamak için döngü
		sprintf(&this->KimlikNoC[i],"%d", this->KimlikNoDizi[i]);
    }

    return this->KimlikNoC; 

}

char* KimlikNoDogrula(char* KimlikNo){
	int toplam = 0;
    int *basamaklar; 
	basamaklar = (int*)malloc(sizeof(int)*11);
        
    for (int i = 0; i < 11; i++) { //String olarak aldığımız kimlik numarası sayıya dönüştürülerek diziye atanır
        basamaklar[i] = KimlikNo[i] - '0';
            
        //Son basamağı kontrol etmek için ilk 10 basamağın toplamı bulunur
        if(i < 10){
            toplam += basamaklar[i];
        }
    }
    //Gerekli işlemler yapılarak kimlik numarasının geçerli olup olmadığının belirtilmesi
    if(basamaklar[10] == (toplam % 10)){
        return "Gecerli";
		free(basamaklar);
    }
    else{
        return "Gecersiz";
		free(basamaklar);
	}
}

void KimlikNoYoket(KimlikNo this){
    if(this == NULL) return;
	this->KimlikNoDizi = NULL;
	this->KimlikNoC = NULL;
	free(this->KimlikNoDizi);
	free(this->KimlikNoC);
    free(this);
}

