/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* IMEI no oluşturan ve IMEI no geçerli mi kontrolü yapan kaynak dosyası
* </p>
*/
#include "IMEINo.h"
#include "Rastgele.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


IMEINo IMEINoOlustur(){
	
	IMEINo this;
	this = (IMEINo)malloc(sizeof(struct IMEINO));
	this->IMEINoDizi = (int*)malloc(sizeof(int)*15);
	this->IMEINoC = (char*)malloc(sizeof(char)*15);
	
	this->tekToplam = 0;
    this->ciftToplam = 0;
	
	int IMEIKodlari[20] = {00, 01, 02, 9, 10, 30, 33, 35, 44, 45, 49, 50, 51, 52, 53, 54, 86, 91, 98, 99};
	
	Rastgele rastgele = RastgeleOlustur();
	
	this->IMEINoDizi[1] = IMEIKodlari[rastgele->rastgele(rastgele)% 19];
	this->IMEINoDizi[0] = this->IMEINoDizi[1] / 10;
	this->IMEINoDizi[1] = this->IMEINoDizi[1] % 10;
	
	this->tekToplam += this->IMEINoDizi[0];
	this->ciftToplam += ((this->IMEINoDizi[1] * 2) / 10) + ((this->IMEINoDizi[1] * 2) % 10);
	
	int i;
	for (i = 2; i < 14; i++) { //IMEI no 3.basamaktan 14. basamağa kadar atama yapmak için döngü
            
        this->IMEINoDizi[i] = rastgele->rastgele(rastgele) % 9;
            
        //Son basamağı bulmak için tek ve çif basamaklarla ilgili işlemler ihtiyacımız olan toplamlar bulunur 
        if (i % 2 == 0){ 
            
            this->tekToplam += this->IMEINoDizi[i];
        }
        else
            this->ciftToplam += ((this->IMEINoDizi[i] * 2) / 10) + ((this->IMEINoDizi[i] * 2) % 10);
    }       
	
	//IMEI algoritmasına göre son basamağa değer atanması için kontrol    
    if ((this->tekToplam + this->ciftToplam) % 10 == 0) { 
        this->IMEINoDizi[14] = 0;
    }
    else
        this->IMEINoDizi[14] = 10 - ((this->tekToplam + this->ciftToplam) % 10);
	
	this->imei = &IMEINoUret;
	this->dogrula = &IMEINoDogrula;
    this->yoket = &IMEINoYoket;
	
	rastgele->yoket(rastgele);
	
	return this;
}

char* IMEINoUret(const IMEINo this){
    
	int i;
    for (i = 0; i < 15; i++) { //Kimlik numarası için ürettiğimiz sayıları string bir ifadeye atamak için döngü
		sprintf(&this->IMEINoC[i],"%d", this->IMEINoDizi[i]);
    }

    return this->IMEINoC; 

}

char* IMEINoDogrula(char* IMEINo){
	int *basamaklar;
	basamaklar = (int*)malloc(sizeof(int)*17);
    int toplam = 0;
    int toplam2 = 0;
    
    for (int i = 1; i < 16; i++) { //String olarak alınan IMEI no sayıya çevir ve IMEI algoritmasına göre kontrol yapan döngü
            
        basamaklar[i] = IMEINo[i] - '0';
            
        //Son basamağı kontrol etmek için tek ve çif basamaklarla ilgili işlemler ihtiyacımız olan toplamlar bulunur 
        if (i % 2 == 0){
                
            toplam2 += ((basamaklar[i] * 2) / 10) + ((basamaklar[i] * 2) % 10);
        }
        else if (i == 15) {
            i++;
        }
        else
            toplam += basamaklar[i];
            
    }
        
    //Gerekli işlemler yapılarak IMEI numarasının geçerli olup olmadığının belirtilmesi
    if ((basamaklar[15] == 10 - ((toplam2 + toplam) % 10)) || ((toplam + toplam2) % 10 == 0 && basamaklar[15] == 0)) {
        return "Gecerli";
		free(basamaklar);
    }
    else{
        return "Gecersiz";
		free(basamaklar);
	}
}

void IMEINoYoket(IMEINo this){
    if(this == NULL) return;
	this->IMEINoDizi = NULL;
	this->IMEINoC = NULL;
	free(this->IMEINoDizi);
	free(this->IMEINoC);
    free(this);
}