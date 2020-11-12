/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Telefon numarası oluşturan kaynak dosyası
* </p>
*/
#include "Telefon.h"
#include "Rastgele.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

Telefon TelefonOlustur(){
	
	Telefon this;
	this = (Telefon)malloc(sizeof(struct TELEFON));
	this->TelefonNumarasi = (int*)malloc(sizeof(int)*11);
	this->TelefonC = (char*)malloc(sizeof(char)*11);
	
	
	int AlanKodlari[31] = {501, 505, 506, 507, 551, 552, 553, 554, 555, 559,530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 561, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549};
    
	int k;
	for (k = 0; k < 11; k++) { //Telefon numarası dizisine ilk değer atamalarını yapan döngü
		this->TelefonC[k] = 0;
    }
	
	Rastgele rastgele = RastgeleOlustur();
	
	this->TelefonNumarasi[0] = 0;
	this->TelefonNumarasi[1] = AlanKodlari[rastgele->rastgele(rastgele)% 30];
	
	int j;
	for (j = 3; j > 1; j--) { //Telefon numarasının ilk basamağı ve alan kodu kısmı hariç diğer basamaklara rastgele sayı atanması
        this->TelefonNumarasi[j] = this->TelefonNumarasi[1] % 10 ;
		this->TelefonNumarasi[1] = this->TelefonNumarasi[1] / 10 ;
    }
	
	int i;	
    for (i = 4; i < 11; i++) { //Telefon numarasının ilk basamağı ve alan kodu kısmı hariç diğer basamaklara rastgele sayı atanması
        this->TelefonNumarasi[i] = rastgele->rastgele(rastgele) % 9 ;
    }
	
    this->telefon = &TelefonUret;
    this->yoket = &TelefonYoket;
	
	rastgele->yoket(rastgele);
	
    return this;
}

char* TelefonUret(const Telefon this){
	
	int i;
    for (i = 0; i < 11; i++) { //Telefon numarası için ürettiğimiz sayıları string bir ifadeye atamak için döngü
		sprintf(&this->TelefonC[i],"%d", this->TelefonNumarasi[i]);
    }

    return this->TelefonC; 
}

void TelefonYoket(Telefon this){
    if(this == NULL) return;
	this->TelefonNumarasi = NULL;
	this->TelefonC = NULL;
	free(this->TelefonNumarasi);
	free(this->TelefonC);
    free(this);
}