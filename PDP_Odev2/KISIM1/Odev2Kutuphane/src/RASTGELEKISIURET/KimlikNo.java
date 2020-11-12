/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* Kimlik no oluşturan ve kimlik no geçerli mi kontrolü yapan sınıf
* </p>
*/
package RASTGELEKISIURET;

public class KimlikNo {
    
    private int[] KimlikNo = new int[11];
    private int tekToplam = 0;
    private int ciftToplam = 0;
    private String KimlikNoS = "";
    
    
    public KimlikNo(){
        
        Rastgele rakam = new Rastgele();
        
        do{ //Kimlik numarasının ilk basamağı 0 olamayacağından ayrı atama yapılır ve 0 sayısından farklı olana kadar atamaya devam edilir
            KimlikNo[0] = rakam.RastgeleSayiUret()% 9 ;
        }while(KimlikNo[0] == 0);
    
        tekToplam += KimlikNo[0];
        
        for (int i = 1; i <= 8; i++) { //Kimlik numarasının 2. basamağından 9. basamağına kadar rastgele sayı ataması yapılır
            
            
            KimlikNo[i] = rakam.RastgeleSayiUret() % 9 ;

            //Kimlik numarası algoritmasını gerçekleştirmek için tek ve çift basamakların toplamları bulunur
            if (i % 2 == 0){
            
                tekToplam += KimlikNo[i];
            }
            else
                ciftToplam += KimlikNo[i];
                    
        }
        
        KimlikNo[9] = ( (tekToplam * 7) + (ciftToplam * 9) ) % 10 ;
        KimlikNo[10] = (tekToplam * 8) % 10 ;
     }
    
    public String KimlikNoOlustur(){
    
        for (int i = 0; i < 11; i++) { //Kimlik no için ürettiğimiz sayıları string bir ifadeye atamak için döngü
            KimlikNoS += KimlikNo[i];
        }
        
        return KimlikNoS;
    }
    
    public String KimlikNoDogrula(String KimlikNo){
        
        int toplam = 0;
        
        int[] basamaklar = new int[11]; 
        
        for (int i = 0; i < 11; i++) { //String olarak aldığımız kimlik numarası sayıya dönüştürülerek diziye atanır
            
            basamaklar[i] = Character.getNumericValue(KimlikNo.charAt(i));
            
            //Son basamağı kontrol etmek için ilk 10 basamağın toplamı bulunur
            if(i < 10){
                toplam += basamaklar[i];
            }
        }
        
        //Gerekli işlemler yapılarak kimlik numarasının geçerli olup olmadığının belirtilmesi
        if(basamaklar[10] == (toplam % 10)){
            return "Gecerli";
        }
        else
            return "Gecersiz";
        
    }
}
