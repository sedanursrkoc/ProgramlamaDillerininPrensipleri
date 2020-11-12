/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Kişi bilgilerini derleyerek rastgele kişi oluşturan kaynak dosyası
* </p>
*/
#include "Kisi.h"
#include "RastgeleKisi.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"


RastgeleKisi RastgeleKisiOlustur(){
	
	RastgeleKisi this;
	this = (RastgeleKisi)malloc(sizeof(struct RASTGELEKISI));
	this->RastgeleKisiBilgileri = (char*)malloc(sizeof(char)*1000);
	
	this->rastgelekisi = &RastgeleKisiDondur;
    this->yoket = &RastgeleKisiYoket;
		
	return this;
}

char* RastgeleKisiDondur(const RastgeleKisi this){  
	Kisi kisi = KisiOlustur();
	sprintf(&this->RastgeleKisiBilgileri[0],"%s %s %d %s %s%s%s", kisi->kimlik(kisi), kisi->isim(kisi), kisi->yas(kisi), kisi->telefon(kisi), "(", kisi->imei(kisi), ")");
	kisi->yoket(kisi);
	return this->RastgeleKisiBilgileri; 
}

void RastgeleKisiYoket(RastgeleKisi this){
    if(this == NULL) return;
	this->RastgeleKisiBilgileri = NULL;
	free(this->RastgeleKisiBilgileri);
    free(this);
}
