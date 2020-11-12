/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* IMEI no oluşturan ve IMEI no geçerli mi kontrolü yapan sınıf
* </p>
*/
package RASTGELEKISIURET;

public class IMEINo {
    
    private int[] IMEINo = new int[15];
    private int tekToplam = 0;
    private int ciftToplam = 0;
    private String IMEINoS = "";
    
    
    public IMEINo(){
    
        Rastgele rakam = new Rastgele();
        
        int[] IMEIKodlari = {00, 01, 02, 9, 10, 30, 33, 35, 44, 45, 49, 50, 51, 52, 53, 54, 86, 91, 98, 99};
	
	IMEINo[1] = IMEIKodlari[rakam.RastgeleSayiUret() % 19];
	IMEINo[0] = IMEINo[1] / 10;
	IMEINo[1] = IMEINo[1] % 10;
        
        tekToplam += IMEINo[0];
        ciftToplam += ((IMEINo[1] * 2) / 10) + ((IMEINo[1] * 2) % 10);
        
        for (int i = 2; i < 14; i++) { //IMEI no 3.basamaktan 14. basamağa kadar atama yapmak için döngü
            
        IMEINo[i] = rakam.RastgeleSayiUret() % 9;
            
        //Son basamağı bulmak için tek ve çif basamaklarla ilgili işlemler ihtiyacımız olan toplamlar bulunur 
        if (i % 2 == 0){ 
            
            tekToplam += IMEINo[i];
        }
        else
            ciftToplam += ((IMEINo[i] * 2) / 10) + ((IMEINo[i] * 2) % 10);
            
        }
        
        //IMEI algoritmasına göre son basamağa değer atanması için kontrol    
        if ((tekToplam + ciftToplam) % 10 == 0) { 
            IMEINo[14] = 0;
        }
        else
            IMEINo[14] = 10 - ((tekToplam + ciftToplam) % 10);
                 
    }
    
    public String IMEINoOlustur(){
    
        for (int i = 0; i < 15; i++) { //Imei no için ürettiğimiz sayıları string bir ifadeye atamak için döngü
            IMEINoS += IMEINo[i];
        }
        
        return IMEINoS; 
    }
    
    public String IMEIKontrol(String imei){
        
        int[] basamaklar = new int[17]; 
        int toplam = 0;
        int toplam2 = 0;
    
        for (int i = 1; i < 16; i++) { //Strin olarak alınan IMEI no sayıya çevir ve IMEI algoritmasına göre kontrol yapan döngü
            
            basamaklar[i] = Character.getNumericValue(imei.charAt(i));
            
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
        }
        else
            return "Gecersiz";
    }
    
}
