/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Kisiye ait isim,kimlik no, yas, telefon ve IMEI no olusturan kaynak dosyası
* </p>
*/
#include "Kisi.h"
#include "Rastgele.h"
#include "KimlikNo.h"
#include "Telefon.h"
#include "IMEINo.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

struct Dugum{
    char isim[100];
    struct Dugum *sonraki;
};


Kisi KisiOlustur(){
	
	Kisi this;

	this = (Kisi)malloc(sizeof(struct KISI));
	this->kisiIsim = (char*)malloc(sizeof(char)*1000);
	this->KimlikNoString = (char*)malloc(sizeof(char)*11);
	this->TelefonString = (char*)malloc(sizeof(char)*11);
	this->IMEINoString = (char*)malloc(sizeof(char)*17);
	
	int kisiSayisi = 0;
	
	struct Dugum* baslangic = (struct Dugum*)malloc(sizeof(struct Dugum));
	struct Dugum* geciciDegisken;
	struct Dugum* temp = baslangic;
	temp->sonraki = NULL;
	
	
	if ( ( this->dosya = fopen( "random_isimler.txt", "r" ) ) == NULL ) //Dosya varsa açılıp dosya değişkenine atanır
				printf( "Dosya acilamadi\n" );
	else //Dosyayı okuyup isimlerden her bir isim için düğüm oluşturularak bağlı liste elde edilir
	{	

		while(!feof(this->dosya)){  //Dosya sonuna sonuna kadar okuma kontrolü
		    fgets (temp->isim, 1000, this->dosya);
			temp->isim[strlen(temp->isim) - 1] = 0;
			temp->sonraki = (struct Dugum*)malloc(sizeof(struct Dugum));
			temp=temp->sonraki;
			temp->sonraki=NULL;
			kisiSayisi++;
		} 
		
		fclose( this->dosya );
	}

	this->kimlik = &KimlikNoDondur;
    this->isim = &IsimDondur;
    this->yas = &YasDondur;
    this->telefon = &TelefonDondur;
    this->imei = &IMEINoDondur;
    this->yoket = &KisiYoket;
	
	Rastgele rastgele = RastgeleOlustur();
	
	kisiSayisi = rastgele->rastgele(rastgele) % kisiSayisi;
	int temp2 = 0;
	
	geciciDegisken = baslangic;
	while(kisiSayisi != temp2) //Bağlı listeden rastgele düğüm seçimi
	{
		geciciDegisken = geciciDegisken->sonraki; 
		temp2++;
	}
	
	this->kisiIsim = geciciDegisken->isim;
	
	geciciDegisken = NULL;
	temp = NULL;
	baslangic = NULL;
	free(geciciDegisken);
	free(temp);
	free(baslangic);
	
	
	this->kimlikNesne = KimlikNoOlustur();
	this->KimlikNoString = this->kimlikNesne->kimlik(this->kimlikNesne);
	
	
	this->telefonNesne = TelefonOlustur();
	this->TelefonString = this->telefonNesne->telefon(this->telefonNesne);
	
	
	this->imeiNesne = IMEINoOlustur();
	this->IMEINoString = this->imeiNesne->imei(this->imeiNesne);
	
	rastgele->yoket(rastgele);
	
	return this;
}	

char* KimlikNoDondur(const Kisi this){
    return this->KimlikNoString;
}

char* IsimDondur(const Kisi this){  
	return this->kisiIsim; 
}

int YasDondur(){
    Rastgele rastgele = RastgeleOlustur();
	int yas = rastgele->rastgele(rastgele) % 100;
	rastgele->yoket(rastgele);
    return yas; 
}

char* TelefonDondur(const Kisi this){
    return this->TelefonString;
}

char* IMEINoDondur(const Kisi this){
    return this->IMEINoString;
}

void KisiYoket(Kisi this){
    if(this == NULL) return;
	this->kimlikNesne->yoket(this->kimlikNesne);
	this->telefonNesne->yoket(this->telefonNesne);
	this->imeiNesne->yoket(this->imeiNesne);
	this->KimlikNoString = NULL;
	this->TelefonString = NULL;
	this->IMEINoString = NULL;
	free(this->kisiIsim);
	free(this->KimlikNoString);
	free(this->TelefonString);
	free(this->IMEINoString);
	free(this->dosya);
    free(this);
}