# so_long

  Ecol42 projelerinden biri olan so_long da bizden 2d bir oyun yapmamız isteniyor. Oyunda karakterimizin toplanabilir tüm nesneleri topladıktan sonra
oyunu çıkış noktasından terk edebilmelidir.

<img width="768" alt="Screen Shot 2023-03-09 at 12 57 30" src="https://user-images.githubusercontent.com/115617420/223987356-cd2143ad-f123-4008-8b34-d0ce856f8c92.png">

Uymamız Gereken Kurallar:
- Minilibix kütüphanesini kullanmalıyız
- Haritada olması gereken bileşenler:
  - oyuncu ( P )
  - boş alan ( 0 )
  - duvarlar ( 1 )
  - toplanabilir nesne ( C )
  - cıkış noktası ( E )
- Harita duvarlarla çevrili olmalı ve oyuncu duvarda hareket edemez
- oyuncu tüm toplanabilir nesneleri toplamadan oyunu çıkış noktasından terk edemez
- Her hareketten sonra güncel hareket sayısı ekrana bastırılmalıdır
- Eğer map tamamlanamaz durumdaysa oyunu başlatamaz( çıkış yolu duvarlarla kaplıysa veya toplanabilir nesnelerin hepsi toplanamaz durumdaysa)
  
Geçerli bir harita örneği:
<img width="374" alt="Screen Shot 2023-03-09 at 13 17 42" src="https://user-images.githubusercontent.com/115617420/223992731-f2edfa41-4103-488d-ab9e-da50eda75416.png">


Oyunu Nasıl Çalıştırabilirim
  "make" yaptıktan sonra "./so_long maps.map1.ber" ile oyunu çalıştırabilirsin 
