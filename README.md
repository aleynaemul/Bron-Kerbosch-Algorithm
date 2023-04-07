# Bron-Kerbosch-Algorithm
Bron-Kerbosch algoritması yönsüz bir graftaki tüm maksimal klikleri bulmak için kullanılır.


Aşağıdaki örneğe göre algoritma ilk çağrıldığında R ve X boş küme olarak ayarlanır ve P graftaki
tüm düğümleri içerir. R geçici sonuçtur, P olası adayların veri setidir ve X dışlanan
veri setini temsil eder. N(v) düğümlerin komşularını gösterir


1. BronKerbosch(R, P, X)

2. Eğer P ve X boşsa

      1. R'yi max klik olarak kaydet.
      
 3. Her bir düğüm için 
 
      1. BronKerbosch(RuV, PnN(V), XnN(V))
      
      2. p <- P\V
      
      3. X <- XuV
      

Bron-Kerbosch algoritmasının en iyi, en kötü ve ortalama çalışma zamanı, girdi olarak verilen grafa ve algoritmanın kullanım şekline bağlıdır.

Ancak, genel olarak Bron-Kerbosch algoritması, düşük yoğunluklu ve küçük grafikler için oldukça etkilidir. Yoğun grafiklerde ise çalışma süresi önemli ölçüde artabilir.



Algoritmanın en iyi durumu, grafın tüm düğümlerinin bir maksimal klik oluşturduğu durumdur. Bu durumda, algoritma tam olarak n! (n faktöriyel) adımda çalışır. Bunun sebebi, algoritmanın tüm olası maksimal klik kombinasyonlarını kontrol etmesi gerektiği ve n düğümün olası maksimal klik sayısının n! olduğudur.


En kötü durumda ise, algoritma tam olarak 3^(n/3) adım gerektirebilir. Bu durum, grafın tamamı tek bir maksimal klik oluşturduğunda gerçekleşir. Bu durumda, her adımda en az bir düğüm kesinlikle bir maksimal klikte yer almaz ve geriye kalan düğümler iki ayrı küme arasında bölünür.


Ortalama durumda, algoritmanın çalışma zamanı, grafın yoğunluğuna, düğüm sayısına ve algoritmanın tam olarak nasıl kullanıldığına bağlıdır. Çalışma zamanı, 3^(n/3) ve n! arasında değişebilir.



