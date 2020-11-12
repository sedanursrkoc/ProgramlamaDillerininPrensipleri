/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 02.03.2020
* <p>
* Txt dosyasını okuyup sesli harflerin, maillerin, web sitelerinin, kelimelerin ve cümlelerin sayısını bulan program
* </p>
*/
package pdp_odev_1;

import java.io.*;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PDP_Odev_1 {
    
    public static void main(String[] args) {
        try{
            String data= "";
            int SesliHarfSayac = 0;
            int KelimeSayac = 0;
            int CumleSayac = 0;
            int MailSayac = 0;
            int WebSitesiSayac = 0;
            String[] Kelime = {};
            String[] Cumle = {};
            String[] Mail = {};
            String[] WebSitesi = {};

            String sesliler = "AaEeIıİiOoÖöUuÜü";
            
            File myObj = new File("icerik.txt"); //içerik.txt dosyasının tanımlanması 
            Scanner myReader = new Scanner(myObj); //Dosyanın okunması
            do {
                data = myReader.nextLine(); //Dosyanın satırlarının data string değişkenine atanması

                for(int i = 0 ; i<= data.length()-1;i++) //Metnin satırını taramak için döngü
                {
                    for(int j= 0 ; j<=15;j++) //Sesli harfleri bulmak için döngü
                    {
                        if(data.charAt(i) == sesliler.charAt(j)) //Eğer data sesliler isimli stringin herhangi bir elemanına eşitse sayacı bir artır
                        {
                            SesliHarfSayac++;
                        }
                    }       
                    Kelime = data.split(" "); //Satır olarak tutulan datanın boşluğa göre ayrılıp kelime dizisine atanması
                }
                
                KelimeSayac += Kelime.length; //Satırları boşluğa göre kelime olarak dizi şeklinde tuturan Kelime dizisinin eleman sayısının Kelimesayaca'a eklenmesi. Satır satır okuma yaptığımız her satırdaki kelimeleri topladık.
                
                Pattern p1 = Pattern.compile("[/./!/?/]+[ ]"); //Regex kullanılarak cümle için koşul oluşturulması
                Matcher m1 = p1.matcher(data);
                
                while(m1.find()){ //Tanımlanan koşula göre cümlelerin bulunup sayacının artırılması
                    CumleSayac++;
                }
                
                Pattern p2 = Pattern.compile("[a-zA-Z0-9_.]+@[a-zA-Z0-9]+.[a-zA-Z]{2,3}[.] {0,1}[a-zA-Z]+"); //Regex kullanılarak mail için koşul oluşturulması
                Matcher m2 = p2.matcher(data);
                
                while(m2.find()){ //Tanımlanan koşula göre maillerin bulunup sayacının artırılması
                    MailSayac++;
                }
                
                Pattern p3 = Pattern.compile("( )+(http(s)?://)?([\\w-]+\\.)+[\\w-]+(/[\\w- ;,./?%&=]*)?"); //Regex kullanılarak web sitesi için koşul oluşturulması
                Matcher m3 = p3.matcher(data);
                
                while(m3.find()){ //Tanımlanan koşula göre web sitelerinin bulunup sayacının artırılması
                    WebSitesiSayac++;
                }  
                
            }while (myReader.hasNextLine()); //Okunan satırdan sonra satır olduğu sürece döngüye devam et
            
            
            //Bulunanların yazdırılması
            System.out.println("Toplam Sesli Harf Sayisi: " + SesliHarfSayac);
            System.out.println("Toplam Kelime Sayisi: " + KelimeSayac);
            System.out.println("Toplam Cumle Sayisi: " + CumleSayac);
            System.out.println("Toplam Mail Sayisi: " + MailSayac);
            System.out.println("Toplam Web Sitesi Sayisi: " + WebSitesiSayac);
        }
        catch(Exception e){ 
            e.printStackTrace();
        }
    }   
}
