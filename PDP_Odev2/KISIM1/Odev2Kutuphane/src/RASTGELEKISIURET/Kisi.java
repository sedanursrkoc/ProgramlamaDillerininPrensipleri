/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* Kisiye ait isim,kimlik no, yas, telefon ve IMEI no olusturan sınıf
* </p>
*/
package RASTGELEKISIURET;

import java.io.*;
import java.util.Scanner;
import java.util.*;

public class Kisi {
    
    KimlikNo kimlik = new KimlikNo();
    Telefon telefon = new Telefon();
    IMEINo ImeiNo = new IMEINo();
    Rastgele rastgele = new Rastgele();
    
    List<String> Kisi = new ArrayList<String>();

    public Kisi(){
        
        try{
            File myObj = new File("random_isimler.txt");
            Scanner myReader = new Scanner(myObj); 

            do{ //dosyanın okunarak satır satır kişi dizisine atanması
                Kisi.add(myReader.nextLine());
            }while(myReader.hasNextLine()); 
              
        }
        catch(Exception e){ 
            e.printStackTrace();
        }
        
    }
    
    public String KimlikNoDondur(){
    
        return kimlik.KimlikNoOlustur();
    }
    public String IsimDondur(){
    
        return Kisi.get(rastgele.RastgeleSayiUret() % Kisi.size());
    }
    
    public int YasDondur(){
    
        return rastgele.RastgeleSayiUret() % 100;
    }
    
    public String TelefonDondur(){
    
        return telefon.TelefonOlustur();
    }
    
    public String IMEINoDondur(){
    
        return ImeiNo.IMEINoOlustur();
    }
      
}
