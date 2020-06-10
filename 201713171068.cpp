/*
*		kodumuz 	https://www.onlinegdb.com/online_c++_compiler 		online compiler da calismaktadir 
*		ayni zamanda Devc++ de de denenebilir 
* 
*		Omer Faruk Tasdemir
*		201713171068 2.Sinif 1.Ogretim
*		Veri yapýlarý Vize Ödevi
*		Projemin ilerleyiþini git hesabýmdan kontrol edebilirsiniz
*		https://github.com/omerfruk/C-Stack-queue-liste-programi.git
*
*/


#include <iostream>
using namespace std;


const int MAX=10;

//
class StackQueueNode
{
public:
	int data;
	StackQueueNode *next; //burada yapacagimiz islem stack yapimizdan boyutsuz olmasini saglayacak.
	//const bir verinin surekli olarak sabit kalmasini saglar
	StackQueueNode(const int &data = 0, StackQueueNode *next = NULL) : data(data), next(next) {}
};

//Stack yapimizi yazalÄ±m.

class Stack
{
	//c++ de public yazilmayan her degisken private dir.
	StackQueueNode *kokDizim;
	int toplam;

public:
	Stack() : kokDizim(NULL) {}
	StackQueueNode *basla() const
	{
		return kokDizim;
	}
	StackQueueNode *son() const // dizimizin sonunun olmasini istemedigimizden son elemanini degismeksizin Null tanimladik.
	{
		return NULL;
	}

	// Stack imizin bos olup olmadigini kontrol eden fonk.
	bool isEmpty()
	{
		if (basla() > 0)
			return false;
		return true;
	}

	//Stack imize verileri ekleme fonk.
	void push(const int &veri)
	{
		// yaptigimiz veri yapisini tutacak olan veri nesnemizi olusturuyoruz
		StackQueueNode *temp = new StackQueueNode(veri, kokDizim);
		// girilen degeri baslangic gonderiyor.
		kokDizim = temp;
	}

	//Stackimizden veri silmek (almak) icin fonk.
	bool pop()
	{
		if (isEmpty()) // Stack bosmu onu kontrol edelim
		{
			cout << "Stack'te veri yok.";
		}
		//gecici bir degisken tanimlayalim
		StackQueueNode *temp = kokDizim;
		kokDizim = temp->next; // son giren ilk cikar mantigini kullaniyoruz.
		delete temp;
	}

	//Stackteki verileri yazdiracak fonk.
	void writeAll()
	{
		StackQueueNode *temp = basla(); // gecici degiskeni baslangica esitledik
		while (temp != son())
		{
			cout << temp->data << endl; //gecici degiskenimizin degerini yazdirdik
			temp = temp->next;
		}
		cout << endl;
	}

	// Stackmimizin boyutunu gosterecek
	int getSize()
	{
		StackQueueNode *temp = basla(); // tekrar gecici bir degisken tanimladik
		toplam = 0;						// toplam degiskenmizide verileri sayicaz
		while (temp != son())			// temp son veriye ulasincaya kadar devam edicek
		{
			toplam++;
			temp = temp->next;
		}
		return toplam; // toplanilan deger geri donuyor
	}

	//tum verileri silme
	void deleteAll()
	{
		while (isEmpty() == false)
		{
			pop(); // Stackimiz bos olmadigi surece verileri silecez 1 bir.
		}
		kokDizim = NULL; // bosalan Stackte baslangici null a esitlicez
	}
};

//Kuyruk sinirimizi burada tanimlayacaz.
class Queue
{
	StackQueueNode *root; //bir degisken olusurduk StackQueueNode turunden
	int size;			  //boyutu olcecek bir degisken tanimladik
public:
	Queue() : root(NULL) {}						  //ilkleme fonk.
	bool isEmpty() const { return root == NULL; } //dizimizin bos olup olmadigini kontrol edicez

	void Add(const int &data) // ekleme fonk.
	{
		if (isEmpty()) // bos olup olmama kontrolu
		{
			root = new StackQueueNode(data); // girilen degeri esitledik
		}
		else
		{
			StackQueueNode *temp = root; //tanimladigimiz gecici degiskene atama yaptik
			while (temp->next != NULL)	 //pointerimiz null olasiya kadar ilerlicez
				temp = temp->next;
			temp->next = new StackQueueNode(data);
		}
	}
	void writeAll() const // tum diziyi yazdiracak fonk
	{
		StackQueueNode *temp = root; //tanimladigimiz gecici degiskene atama yaptik
		while (temp != NULL)		 // gecici degiskenimiz bos olasiya kadar ilerledik
		{
			cout << temp->data << "-"; // degerimizi yazdirdik
			temp = temp->next;
		}
		cout << endl;
	}
	void Delete() // verileri silme fonk
	{
		if (isEmpty()) // bosmu kontrolu
			cout << "kuyruk yapisi bos.";
		StackQueueNode *temp = root; //tanimladigimiz gecici degiskene atama yaptik
		root = temp->next;			 // deger atamasi yapildi
		delete temp;
	}
	int getSize() const // dizimizin boyutunu gosteren fonk
	{
		StackQueueNode *temp = root; //tanimladigimiz gecici degiskene atama yaptik
		int size = 0;				 // baslangic degerimiz
		while (temp != NULL)		 //degiskenimiz 0 olasiya kadar ilerledik
		{
			size++;			   // arttirma
			temp = temp->next; // degiskene atama
		}
		return size;
	}
		
		void deleteAll()// kujyruyktaki verilerin hepsini silmek icin
	{
		while (isEmpty() == false)
		{
			Delete(); // Stackimiz bos olmadigi surece verileri silecez 1 bir.
		}
		root = NULL; // bosalan Stackte baslangici null a esitlicez
	}
	
};
class Node{//Linked List icin dügüm yapisi
	public://Erisim belirleyici
		int data;//Integer türünde data isimli degisken
		Node* next;//Node türünde next isimli pointer
		Node(const int& data = 0, Node* next = NULL) : data(data), next(next) {	}//Dügüm yapisi için kurucu method
};
class LinkedList{//Linked List sinif yapisi
	Node* root;//Node türünde root isimli pointer
	int size;//Integer türünde size isimli degisken
	public://Erisim belirleyici
		LinkedList() : root(NULL){	}//LinkedList sinifi icin kurucu method
		Node* begin()const{return root;}//Listenin nerede basladigini belirten method
		Node* end() const{return NULL;}//Listenin nerede bittigini belirten method
		bool isEmpty()const{return begin()==end();}//Listenin bos olup olmadigi degerini döndüren method
		void push_back(const int& data){//Listeye sondan eleman eklememize yarayan method
			if(isEmpty()){//Listenin bos olup olmadigini kontrol ediyoruz
				root = new Node(data);//Liste bossa baslangic degerine gelen parametreyi data olarak ekliyoruz
			}
			else{//Liste bos degilse
				Node* temp = begin();//Gecici bir pointer olusturup liste baslangicina esitliyoruz
				while(temp->next != end()){//Bütün listeyi dolasiyoruz liste sonuna gelene kadar
					temp = temp->next;//liste sonuna geldigimizde eleman ekleyebilmek için son elemenin next adresine yeni data adresini veriyoruz
				}
				temp->next = new Node(data);//Listenin sonuna parametreden gelen datayi ekliyoruz
			}
		}
		
		void print(){//Listeyi ekrana yazdirdigimiz method
			Node* temp = begin();//Temp isimli gecici bir pointer olusturup liste baslangicina esitliyoruz
			cout<<"List: ('<': Baslangic, '>': Bitis)"<<endl;//Bilgilendirme
			cout<<"<";//Bilgilendirme
			while(temp != end()){//Bütün listeyi dolasiyoruz
				cout<<temp->data<<",";//Listedeki elemanlari tek tek ekrana yazdiriyoruz
				temp = temp->next;//Yazdirdigimiz elemandan bir sonraki elemana geciyoruz
			}
			cout<<">"<<endl;//Bilgilendirme
		}
		void pop_at(Node* pStart, int index){//Belirli bir index numarasindaki elemani listeden çikarmamiza yarayan method
			if(isEmpty())
				throw "listemiz bostur";
			if(index > getSize())
				throw "listemizin boyutunu astiniz";
			for(int i = 0; i<index-2;i++){//Girilen 'index'inci elemandan bir önceki elemani buluyoruz
				pStart = pStart->next;//Çikarilmak istenen elemandan bir önceki elemanin next ile gösterdigi adresi aliyoruz
			}
				Node* temp = pStart->next;//Gecici bir pointer olusturup cikarmak istedigimiz elemanin adresini gösteriyoruz
				pStart->next = pStart->next->next;//Çikarmak istedigimiz elemandan önceki elemanin next adresini, çikarmak istedigimiz elemandan sonraki elemanin adresine esitliyoruz
				cout<<"Silinen eleman degeri: "<<temp->data<<endl;//Bilgilendirme
				delete temp;//Istenilen elemani listeden çikariyoruz ve hafizadan temizliyoruz
		}
		
		void pop_back(){//Listenin sonundaki elemani çikarmamiza yarayan method
			if(isEmpty()){//Listenin bos olup olmadigini kontrol ediyoruz
				throw "listemiz bostur ";//Liste bossa çikarilacak eleman yoktur bir exception firlatiyoruz
			}
			if(begin()->next == end()){//Listede tek eleman olup olmadigini kontrol ediyoruz
				cout<<"Listeden Son Elaman Cikariliyor.."<<endl;
				delete root;//Listede tek eleman varsa baslangic elemanidir. Elemani listeden çikariyoruz ve hafizadan temizliyoruz
				root = NULL;//Liste baslangic adresinin NULL degere esitliyoruz liste bos oldugu icin
			}
			else{//Listede birden fazla eleman varsa
				cout<<"Listeden Son Eleman Cikariliyor.."<<endl;
				Node* temp = begin();//Liste baslangicini gösteren gecici bir pointer olusturuyoruz
				while(temp->next->next != end()){//Listeyi dolasiyoruz
					temp = temp->next;//Liste sonudaki elemani gecici pointera esitliyoruz
				}
				delete temp->next;//Liste sonundaki elemani listeden çikariyoruz ve hafizadan temizliyoruz
				temp->next = NULL;//Listenin son elemanin next ile gösterdigi adresi NULL degere esitliyoruz cunku kendisinden sonra gelen bir eleman yok
			}
		}
		void makeEmpty(){//Listeyi temizlememize yarayan method
			while(!isEmpty()){//Liste bos olana kadar
				pop_back();//Listedeki son elemani çikariyoruz pop_back() methoduyla(Line 160)
			}
			root = NULL;//Liste artik bos oldugu için baslangic adresini NULL degere esitliyoruz
		}
		
		void push_at(Node* pStart,const int& data, int index){//Belirli bir indexe, istenilen datayi eklememize yarayan method
			if(index > getSize())
				throw "listemizin boyutunu astiniz";
			Node* pNew = new Node(data);//Parametre olarak gelen data ile yeni bir Node olusturuyoruz
			for(int i = 0; i<index-2;i++){//Istenilen index degerininden bir önceki elemani buluyoruz
				pStart = pStart->next;//Istenilen indexten bir önceki elemanin gösterdigi next adresini aliyoruz
			}
			pNew->next = pStart->next;//Olusturdugumuz yeni dugumun gösterdigi next adresini önceden ayni indexte olan elemanin adresine esitliyoruz(Eleman kaydirma)
			pStart->next = pNew;//Istenilen indexten bir önceki elemanin next adresini yeni olusturdugumuz dügümün adresine esitliyoruz		
		}
		
		int getSize()const{//Listenin eleman sayisini elde ettigimiz method
			int size = 0;//Liste eleman sayisini tutacak olan Integer türünde size isimli degisken
			Node* temp = begin();//Gecici bir pointer olusturup liste baslangicina esitliyoruz
			while(temp != end()){//Butun listeyi dolasiyoruz
				size++;//Listedeki elemanlari dolastikca sayaci "1" artiriyoruz
				temp = temp->next;//Bir sonraki elemena geciyoruz
			}
			return size;//Eleman sayisi geri döndürüyoruz
		}
};
/*
buradaki algoritmada yapmaya calistigim bir node verisi olusturmak istedigimizde direk olarak degerler atansÄ±n 
ve baglamalarÄ± otomatik olarak yapilsin fakat tam olarak yapamadim
*/

/*void nodeOlustur(){
	node* value[toplam] = new node();
	toplam++;
	if (toplam==0)
		return false;
	else
	{
		for (int i = 1; i <= toplam+1; i++)
		{
			value[toplam]->pNextValue=value[toplam+i];
		}
		
	}
	
}
*/

class IkiliAgac		//binary tree yapimizi yazalim
{
	public:
		struct AgacDugum		//struct yapoýmýzý kuralým 
		{
			int deger;	       	// degerimiz
			AgacDugum *sol;		//sola eklemek icin pointer  
			AgacDugum *sag;		//saga eklemek icin pointer 	
		};
		int toplam = 0;		// elemanlarý saymak icin metod
		bool cikis;		// sayactan cikmak icin 
		AgacDugum *kok;	//baslangýc yerimiz kokumuz
		
		IkiliAgac()	// kurucu fonk
		{
			kok=NULL;
		}
		void dugumEkle(int);
		void DugumAra();
		
		// lazim olacak fonksiyonlar 
		void InOrderDolasim(AgacDugum *dugumPtr);		//dolasmak icin fonk
		void PreOrderDolasim(AgacDugum *dugumPtr);		//dolasmak icin fonk
		void PostOrderDolasim(AgacDugum *dugumPtr);		//dolasmak icin fonk
		
		void DugumGorInOrderYaz()		//dugumu gormek icin
		{	
			InOrderDolasim(kok);		//methodu cagiralim
		}
		void DugumGorPreOrderYaz()	//dugumu gormek icin
		{
			PreOrderDolasim(kok);		//methodu cagiralim
		}
		void DugumGorPostOrderYaz()		//dugumu gormek icin
		{
			PostOrderDolasim(kok);		//methodu cagiralim
		}
		// silme metodlari
		void sil(int sayi);
		void tumunuSil();
		void dugumSil(int,AgacDugum *& );
		void silici(AgacDugum *&);
		void deleteAll (AgacDugum *&);
		
		//Verileri saymak icin metod.
		void sayac()
		{
			
			cout<<""<<toplam<<endl;
		}
};
		//dugumde deger arama icin 		
	void IkiliAgac :: DugumAra()
		{	
			cout<<"Agacta Aranacak Deger: ";
			int aranan;
			cin>>aranan;
			AgacDugum *dugumPtr = kok;		// kok dizimizi dugum pointere atadik 
			while(dugumPtr)		// dugum oldugu surece donecek
			{
				if (dugumPtr-> deger == aranan)		// girlen sayi dgere esitmi ?
				{
					cout<<"aranan deger bulunmustur: "<<aranan<<endl;
					break;	
				}else if(aranan < dugumPtr->deger)		// kokumuz girilen sayidan buyukse 
				{	
					dugumPtr = dugumPtr->sol;		// soldaki degeri pointer atadik
				}else
				{	
					dugumPtr = dugumPtr->sag; //sagdaki degeri atadik
				}
				cout<<"aranan "<<aranan<<" degeri bulunamamistir. "<<endl;
				break;
			}
			cout<<"deger bulunamadi";
		}


void IkiliAgac :: dugumEkle(int sayi)	// dugume ekleme metodumuzu burada yazicaz
{	
	toplam++;		// her dugum eklendiginde bir artsin ki elemanlari sayalim 
	AgacDugum *yeniDugum,*dugumPtr; 	// 2 farkli pointer olusturduk birisi agac ici gezimler icin digeri yeni dugumu isaret edicek
	
	yeniDugum = new AgacDugum;
	yeniDugum->deger=sayi;
	yeniDugum->sol= NULL;
	yeniDugum->sag= NULL;
	
	if(!kok)//kok varmý ?
	{
		kok = yeniDugum;	// yoksa
	}else{	// varsa 
	
		dugumPtr = kok;	// kokun adresini fugumPrt ye atayalim 
		while (dugumPtr != NULL)		// dugum varsa yapilacaklar
		{
			if (sayi < dugumPtr->deger)	// sola ekleme deger kucukse 
			{
				if(dugumPtr->sol)	// solda bir eleman varsa 
				{
				dugumPtr = dugumPtr-> sol;		//ata
				}else{	// sol yoksa
					dugumPtr-> sol = yeniDugum;	// sol kendin ol
					break;
				}
			}else if(sayi > dugumPtr->deger){// sayi büyükse 
				if(dugumPtr->sag){	// sagi varsa 
					dugumPtr = dugumPtr->sag;	//yeni degerimiz sag olsun 
				}else{	//yoksa
					dugumPtr->sag = yeniDugum;	// sag dugum olsun 
					break;
				}
			}else{	//esitse 
				cout<<"Agacta zaten bu deger var "<<endl;
				break;
			} 
		}	
	}
	
	
}
		
		void IkiliAgac :: InOrderDolasim(AgacDugum *dugumPtr)
		{
			// sol -> kok -> sag
			if(dugumPtr){
			InOrderDolasim(dugumPtr->sol);
			cout<<dugumPtr->deger<<endl;
			InOrderDolasim(dugumPtr->sag);	
			}
		}
				
		void IkiliAgac :: PreOrderDolasim(AgacDugum *dugumPtr)	
		{
			// kok -> sol ->sag
			if(dugumPtr){
			cout<<dugumPtr->deger<<endl;		// koku yaz
			PreOrderDolasim(dugumPtr->sol);		//solu al
			PreOrderDolasim(dugumPtr->sag);		//sagi al 
			}
		}
		
		void IkiliAgac :: PostOrderDolasim(AgacDugum *dugumPtr)	
		{
		    // sol -> sag ->kok 
		    if(dugumPtr){
			PostOrderDolasim(dugumPtr->sol);
			PostOrderDolasim(dugumPtr->sag);
			cout<<dugumPtr->deger<<endl;
			}
		}
		/*
				
		dugumPtr == null dugum yok demek
		o zaman agaci temizleme metodumuz buradan cikacak	
		
		*/
	
		//silinecek olan degeri alir ve dugum sile gönderir
		void IkiliAgac ::sil(int sayi)
		{
			toplam--;
			dugumSil(sayi,kok);	// metod içinde metod tanýmladýk
		}
		void IkiliAgac :: tumunuSil()	// metoda parametre gondermek istemedim bu yuzden metodlar yardýmýyla yaptým 
		{
			deleteAll(kok); 		//metodu burda parametresiyle gonderdik
		}
		
		void IkiliAgac :: dugumSil(int sayi, AgacDugum *& dugumPtr )
		{
			if(sayi < dugumPtr->deger )		//sayi soldami
			{
				dugumSil(sayi,dugumPtr->sol);		//metodu tekrar cagiralim 	
			}else if (sayi > dugumPtr->deger)		//sayi sagdami 
			{
				dugumSil(sayi,dugumPtr->sag);		// ayni saekilde metodu tekrar cagiralim
			}
			else
				silici(dugumPtr);	//diger durumlarda koku silecek
			
		}
		
		void IkiliAgac :: silici(AgacDugum *& dugumPtr)
		{
			
			AgacDugum *tempDugumPtr;
			if(dugumPtr == NULL)		// dugum bosmu
			{
				cout<<"dugumy yok"<<endl;	
			}else if (dugumPtr->sag == NULL) 		//dugumun sagi bosmu
			{
				tempDugumPtr = dugumPtr;		// dýugumu kaybetmemek icim 
				dugumPtr = dugumPtr->sol;		// dugum pointerimizi kaybetmemek icin atadýk
				delete tempDugumPtr;		// gecici degiskenimizi sildik
			}else if (dugumPtr->sol == NULL) 		//dugumun solu bosmu
			{
				tempDugumPtr = dugumPtr;		// dýugumu kaybetmemek icim 
				dugumPtr = dugumPtr->sag;		// dugum pointerimizi kaybetmemek icin atadýk
				delete tempDugumPtr;		// gecici degiskenimizi sildik
			}else 
			{
				tempDugumPtr = dugumPtr->sag;		//dugumun sagýna gidelim
				while(tempDugumPtr->sol)			//dugumun solunda ilerliyelim 
				{
					tempDugumPtr = tempDugumPtr->sol;		//soldaki degeri gecici degiskene atayalim 
				}
				tempDugumPtr->sol = dugumPtr->sol;		// silecegimiz elemana ulastikmi bu islem yapilacak sol alt agaci atadik
				tempDugumPtr = dugumPtr; 		// boylelikle veri kaybini engelledik
				
				dugumPtr = dugumPtr->sag;		// sag alt agaci atadik
				delete tempDugumPtr;
			}
			
		}
		
		void IkiliAgac :: deleteAll(AgacDugum *& dugumPtr)
		{	
			if(dugumPtr == NULL){		// bosmu diye kontrol edelim 
				cout<<"Dugum  zaten bostur"<<endl;		// bossa mesaj yazdiralim
			}else	// degilse 	
				dugumPtr = NULL;		//dugumu bosaltalim
			
		}
		
class Dugum{		//hash tablosu icin gerekli class
	public: 
		int Anahtar;		//anahtar adli degerimiz
		Dugum* pSonraki;		//dugum tipinde pointeimiz
		
		Dugum(int Anahtar)		// kurucu fonksiyonumuz
		{
			this->Anahtar=Anahtar;		//anahtar adlý degiskenimizi bizim ustte tanimladigimiz anahtara ata 
			pSonraki=NULL;		// yapimizdaki bagli listemizim sonraki elemanin adresini tutacak alan 
		}
};

class HashTablo{		//hash tablomuz
	public:
		Dugum* Veri[MAX];		//degerimizin uzunlugunu girdik
		int toplam=0;
		void Ekle(int Anahtar);		// ekleme metodumuz	
		Dugum* Bul(int Anahtar);		//bulma metodumuz
		void Sil(int Anahtar);		//silme metodumuz
		HashTablo();			//kurucu fonksiyonumuz
		void tumunuSil();
			void sayac()
		{
			
			cout<<""<<toplam<<endl;
		}
};

HashTablo :: HashTablo()
{
	for (int i = 0;i<MAX;i++)		//tum elemanlari dolandiracak dongu
	Veri[i]=NULL;			// her bir elemana null(bos) degerini atadik
}
void HashTablo :: tumunuSil()
{
	toplam = 0;		//sayaci sifirladik
	for (int i = 0;i<MAX;i++)		//tum elemanlari dolandiracak dongu
	Veri[i]=NULL;			// her bir elemana null(bos) degerini atadik
}
void HashTablo :: Ekle(int Anahtar)
{
 toplam++;
 Dugum* pYeni = new Dugum(Anahtar);  //dugum tipinde veriyi tutacak bi pointer olusturalim
 int mod = Anahtar % MAX; //modumuzu bulalim
 if(!Veri[mod]) //eleman varmi kontrol edelim
  {
   Veri[mod] = pYeni; //yoksa yeni elemanimizi yerlestirecez
   return;  //bitti
  }

 Dugum* pTemp = Veri[mod]; // gecici bir eleman olusturalim
 // listenin baþýna insert edilecekse Veri[mod] deðiþecek
 if(pTemp->Anahtar > pYeni->Anahtar)
 {
  pYeni->pSonraki = pTemp;
  Veri[mod] = pYeni;
  return;
 }

 Dugum* pOnceki;
 while (pTemp != NULL)
 {
  if(pTemp->Anahtar > pYeni->Anahtar)
  { 
   pOnceki->pSonraki = pYeni;
   break;
  }
  pOnceki = pTemp;
  pTemp = pTemp->pSonraki;
 }
 pOnceki->pSonraki = pYeni;
 pYeni->pSonraki = pTemp;
}

Dugum* HashTablo :: Bul(int Anahtar)		//bul metodumuz
{
	int mod = Anahtar % MAX; //modumuzu bulalim
	Dugum* pTemp = Veri[mod];		// yeniden local bi pTemp olusturalým gecici eleman tutacak bu bize
	
	while(pTemp != NULL)		// pTemp bos olasiya kadar git 
	{
		if(pTemp->Anahtar == Anahtar)		//pTempin anahtari benim aradigim anahtarsa 
		{
			return pTemp; 		//ptempi dondurelim
		}
		pTemp=pTemp->pSonraki;	// p tempe degerimizi atadik
	}
	return NULL; // aradigimizi bulamadik ve null yaptik
}

void HashTablo :: Sil (int Anahtar)		//silme metodumuz
{
	toplam--;		// eleman sayisini arttirip azalttik
	int mod = Anahtar % MAX; //modumuzu bulalim
	
	if (!Veri[mod])	//eleman yoksa
		return;		//geri donderdik
	
	if (!Veri[mod]->pSonraki)		//bir deger varsa 
	{
		if (Veri[mod]->Anahtar==Anahtar)	// aradigim bir dugum mu var aynimi buna bakicaz
		{
			delete Veri[mod];		//veriyi sildik
			Veri[mod]=NULL;		//adresi de sildik hata almamak icinveri var zannetmesin
		}
		return;
	}
	if(Veri[mod]->Anahtar==Anahtar) // verimizin anahtarý anahtara esitmi  ve birden fazla dugum varsas
	{
		Dugum* pDon = Veri[mod]->pSonraki;		// degerimizin adrsini donus degerimizin adrsine gonderdik
		delete Veri[mod];		// degerimizi sildik
		Veri[mod] = pDon;		//yeni degerimizi vagladik
		return;			//bittirdik
	}
	// aradaki bir degeri silme
	Dugum* pTemp = Veri[mod];	// yeni bir gecici deger olusturalim
	while (pTemp->pSonraki != NULL)	//elemanlari bi gezelim 
	{
		if (pTemp->pSonraki->Anahtar == Anahtar) 	//aradigimiz veriyi bulduysak 
		{
			Dugum* pDon = pTemp->pSonraki;	// degeri yedekledekleyelim
			pTemp->pSonraki = pDon->pSonraki;
			delete pDon;
			return;
		}
		pTemp = pTemp->pSonraki; 		// while icerisinde ilerlicez 
		// bir arttirma operetoru gibi dusunebiliriz surekli bir sonraki degere gecicek
		// bulasiya kadar 
	}	
}





int main() // main fonk islemler burada gerceklesecek
{

	HashTablo h;// nesnemizi olusturduk
	IkiliAgac a;	//nesnemizi olsuturudk
	Queue q;  // nesne olustur
	Stack s;  //nesne olusturalim
	LinkedList l;		// nesnemizi olusturuk
	while (true) // surekli dongude kalmasi icin 
	{																// surekli bu menude kalmak icin gerekli dongu
		cout << "----------------Menu------------------" << endl;	//menu yazdiralim
		cout << " Yapmak istediginiz uygulamayi seciniz:" << endl;	//menu yazdiralim
		cout << "/ 1.Yigin uygulamasi	                " << endl; //menu yazdiralim
		cout << "/ 2.Kuyruk uygulamasi                " << endl;	//menu yazdiralim
		cout << "/ 3.Tek yonlu bagli liste uygulamasi " << endl;	//menu yazdiralim
		cout << "/ 4.Ikili Agac uygulamasi " << endl;	//menu yazdiralim
		cout << "/ 5.Hash Tablosu uygulamasi " << endl;	//menu yazdiralim
		cout << "/ 6.Cikis                            " << endl;	//menu yazdiralim
		cout << "--------------------------------------" << endl;	//menu yazdiralim
		int choice;												//secim icin bir degisken alalim
		cin >> choice;												// degiskene kullanicidan deger isteyelim
		if (choice==1)
		{		
				while (true)// surekli dongude kalmasi icin 
				{	
				
				/*
				
					odev dokumaninda 1,2,3 manulari gozukmesin istendigi icin manular kapatilmistir
				
				
				*/
				break;			
				// burada otomatik olarak deÄŸer veriyoruz
				cout << "-------------Stack Menu---------------" << endl;	//menu yazdiralim
				cout << " Yapmak istediginiz islemi seciniz:   " << endl;	//menu yazdiralim
				cout << "/ 1.Yigina eleman ekle 			" << endl; //menu yazdiralim
				cout << "/ 2.Yigindan eleman cikar			" << endl;		//menu yazdiralim
				cout << "/ 3.Yigini temizle					" << endl;		//menu yazdiralim
				cout << "/ 4.Yigindaki elemanlari goster  	" << endl;		//menu yazdiralim
				cout << "/ 5.Yigindaki eleman sayisini goster" << endl;	//menu yazdiralim
				cout << "/ 6.Ana menuye don 				" << endl; //menu yazdiralim
				cout << "--------------------------------------" << endl;	//menu yazdiralim
				int choice;												// secim icin bir degisken tanimlayalim
				cin >> choice;										// secimi alalaim kullanicidan
					if (choice==1){
						int input;	   // kullanicinin girmek istedigi deger icin degisken
						cout<<"<- lutfen eklemek istediginiz degeri giriniz->"<<endl;
						cin >> input;  // kullanicidan istedigi degeri alalim
						s.push(input); //degeri metotla gonderelim
						cout << "Stackge " << input << " degeri eklendi" << endl;
						}
					else if(choice == 2){
						s.pop(); // metodla cikrama islemini yapalim
						cout << "<-Stackten eleman cikarildi->" << endl;
						}
					else if(choice == 3){
						s.deleteAll(); // metodu ile tum verileri silelim
						cout << "<-Stack temizlendi...->" << endl;
						}
					else if(choice==4){
						cout<<"Yigindaki elemanlar "<<endl;// yýgýndaki elemanlarin baþlangici girilen degerle ayrildi 
						s.writeAll(); // metodu ile tum verileri yazdiralim
						}
					else if(choice == 5){
						cout << "Stackteki verilerin boyutu-> " << s.getSize()+1 << endl; // metodu kullanarak dizinin boyutunu gosterelim
						}
					else if(choice == 6){
						break; // ana menu ye donmek icin donguyu sonlandiracak atamayi yapalim
						}
					
					else{ // olasi istenmeyen tum durumlari ele alp yonlendirilmesini yapalim
						cout << "girilen deger istenilenler arasina bulunmamaktadir..." << endl;
						break; //ana menu ye donmek icin donguyu sonlandiralim
						}	
				}
	}
	
				else if(choice == 2)// kuyruk yapisi baslangici
					{						   
				while (true)// surekli dongude kalmasi icin 
				{	
				/*
				
					odev dokumaninda 1,2,3 manulari gozukmesin istendigi icin manular kapatilmistir
				
				
				*/	
				break;														// queue menumuzu surekli gormek icin bir dongu yazalim
					cout << "-------------Queue Menu---------------" << endl;	//menu yazdir
					cout << " Yapmak istediginiz islemi seciniz:   " << endl;	//menu yazdir
					cout << "/ 1.Kuyruga eleman ekle 			" << endl; //menu yazdir
					cout << "/ 2.Kuyruktan  eleman cikar		" << endl; //menu yazdir
					cout << "/ 3.Kuyrugu temizle				" << endl; //menu yazdir
					cout << "/ 4.Kuyruktaki elemanlari goster  	" << endl;		//menu yazdir
					cout << "/ 5.kuyruktaki eleman sayisini goster" << endl;	//menu yazdir
					cout << "/ 6.Ana menuye don 				" << endl; //menu yazdir
					cout << "--------------------------------------" << endl;	//menu yazdir

					// burada otomatik olarak deger veriyoruz
					int choice;	// secim icin degisken ata
					cin >> choice;	// degiskeni kulanicidan al
				    if (choice == 1)
					{
						int data;
						cout<<"<-lutfen eklemek istediginiz degeri giriniz->"<<endl;	  //kullanicidan isteyecegimiz degerin atanmasi
						cin >> data;									  // degiskenin alinmasi
						q.Add(data);									  // metodla istenen degerin eklenmesi kuyruk mantigi oldugundan ilk giren veri ilk cikar yani ekmek sirasi gibi yer belirtemeyiz
						cout << "kuyruga "<< data<<" degeri eklendi " << endl; //eklenen degeri gosteme
					}
					else if(choice == 2){
						q.Delete(); //metod la deger silme kuyruk yapisi oldugundan bastan cikma olur deger vermeyiz cikarma dedik mi en bastan cikar ekmek sirasi gibi ilk gelen ilk cikar
						cout << "<-islem gerceklesiyor...->\nKalan elemanlar" << endl;
						q.writeAll(); // metod yardimiyla tum vrileri yazdiralim
					}
					else if (choice == 3){
						q.deleteAll(); // metod yardimiyla tum verileri silelim
						cout << "<-kuyruk temizleniyor...->" << endl;
					}
					else if (choice == 4){
						cout<<"<-kuyryktaki elemeanlar->"<<endl;
						q.writeAll(); // metod yardimi ile tum degerleri yazdiralim
					}
					else if (choice == 5){
						cout << "<-kuyruktaki eleman sayisi-> \n"
							 << q.getSize() << endl; // metod yarimiyla dizinin eleman sayisina bakalim
					}
					else if (choice == 6){
						break; // donguden cikabilmek icin  sonlandirma koyalim 
					}
					else {
						cout << "boyle bir islem belitrilmemistir\n lütfen tekrar deneyiniz." << endl; //yanlis secim uyarisi
						break;// girilen yanklis secimleri ana menuye gondererek hatalardan kacinalim
					
					}
					}
				}
			
		else if(choice == 3){		// link list giris
			while(true)// surekli dongude kalmasi icin 
			{
				/*
				
					odev dokumaninda 1,2,3 manulari gozukmesin istendigi icin manular kapatilmistir
				
				
				*/
				break;// dongu sonlanrirdildi 
				cout<<endl;
				cout<<"-------------Linked List Menu---------------"<<endl;//menu yazdir
				cout<<"/ 1. Listeye eleman ekle"<<endl;//menu yazdir
				cout<<"/ 2. Listeden eleman cikar "<<endl;//menu yazdir
				cout<<"/ 3. Listeyi temizle"<<endl;//menu yazdir
				cout<<"/ 4. Listedeki elemanlari goster "<<endl;//menu yazdir
				cout<<"/ 5. Listedeki eleman sayisini goster"<<endl;//menu yazdir
				cout<<"/ 6. Ana menuye geri don"<<endl;//menu yazdir
				cout<<"-------------------------------------"<<endl;//menu yazdir
				cout<<"lutfen bir secim yapimniz:";
				int listChoice;
				cin>>listChoice;
				cout<<endl;
				if(listChoice == 1){
				
					while(true){// surekli dongude kalmasi icin 
						cout<<endl;
						cout<<"-------------Ekleme Menu---------------"<<endl;//menu yazdir
						cout<<"/ 1. Araya eleman ekle"<<endl;//menu yazdir
						cout<<"/ 2. Sona eleman ekle"<<endl;//menu yazdir
						cout<<"/ 3. Liste islemlerine geri don"<<endl;//menu yazdir
						cout<<"---------------------------------------"<<endl;//menu yazdir
						cout<<"lutfen bir secim yapimniz: ";
						int listAddChoice;
						cin>>listAddChoice;
						cout<<endl;
						if(listAddChoice == 1){ // eger araya eklemeyi secerse 
							cout<<"Eklemek istediginiz deger: ";
							int data;	// degisken tanimladý  altta kullanicidan alacaz degeri
							cin>>data; // kullanicidan deger alma 
							cout<<endl;
							cout<<"Listeye kacinci eleman olarak eklensin? ";
							int index;	
							cin>>index;	// verinin kacinci indexe eklenecegini aliyoruz
							if(index<= 0){		// eger naslangic degerimiz 0dan kucuk ise hata versin 
								cout<<"Gecerli Bir Deger Giriniz!"<<endl;
								continue;
							}
							cout<<endl;
							try{ 	//hata yakalama ayýklama bir deger mutlaka true dondurecek bize onu yakalamaya calisiyoruz
								l.push_at(l.begin(),data,index);	
							} catch(const char* ex){		// yukarda dedigim gibi ikisinden birinin hatali olmasi lazým ve mutlaka biri true donecek 
								cout<<ex<<endl;
							}

						}
						else if(listAddChoice == 2){	// sona eklemeyi secerse 
							cout<<"Eklemek istediginiz deger: ";
							int data;		// kullanici girisi icin degisken 	
							cin>>data;		// kullanicidan veri girisini aldik
							cout<<endl;		
							l.push_back(data);			// metod yardimiyla veriyi listeye ekledik
						}
						else if(listAddChoice == 3)		// listeleme manusunden cikis yapiyoruz
						{	
							break;		// while sonlandiriyoruz
						}
						
						else{
							cout<<"Gecersiz Giris!"<<endl;
							continue;
						}
					}
				}
				else if(listChoice == 2)	// cikarma icin secim yapilirsa 
				{							
				
					while(true){// surekli dongude kalmasi icin 
						cout<<endl;	
						cout<<"--------------cikarma Manu--------------"<<endl;		// cýikarma manu yazdýrma
						cout<<"/ 1. Aradan eleman cikar"<<endl;//menu yazdir
						cout<<"/ 2. Sondan eleman cikar"<<endl;//menu yazdir
						cout<<"/ 3. Liste islemlerine geri don"<<endl;//menu yazdir
						cout<<"----------------------------------------"<<endl;//menu yazdir
						cout<<"lutfen bir secim yapimniz: ";
						int listRemoveChoice;
						cin>>listRemoveChoice; // kulanýcý girisi seçme 
						cout<<endl;
						if(listRemoveChoice == 1)	// aradan eleman cikarma blogu
						{
							cout<<"Listeden kacinci eleman olarak cikarilsin? ";
							int index;				
							cin>>index;			//	kullanicidan kacinci elemanin cikarilacagini bizlere soyluyor 
							if(index<= 0){
								cout<<"Gecerli Bir Deger Giriniz!"<<endl;
								continue;
							}

							cout<<endl;
							try{					// yukarida tanimlamasini yaptim burda gerekmedigini dusunuyorm
								l.pop_at(l.begin(),index);
							} catch(const char* ex){
								cout<<ex<<endl;
							}
							
						}
						else if(listRemoveChoice == 2)		// sondan cikarma blogu 
						{
							try{
								l.pop_back();
							} catch(const char* ex){	// yukarida tanimlamasini yaptim burda gerekmedigini dusunuyorm
								cout<<ex<<endl;
							}
						}
						else if(listRemoveChoice == 3)
						{
							break; // menunun disina cikmak icin 
						}
						else{
							cout<<"Gecersiz Giris!"<<endl; // else durumlari 
							continue;
						}
				}
			}
				else if(listChoice == 3)
				{
					l.makeEmpty();		//listeyi bosaltma metodu
				}
				else if(listChoice == 4)
				{
					l.print(); 			//listedeki verileri yazacak metodu 
 				}
				else if(listChoice == 5)
				{
					cout<<"Eleman Sayisi: "<<l.getSize()<<endl; // eleman sayisini yazdiracak metod 
				}
				else if(listChoice == 6)
				{
					break;	// listeleme menusunden cikis metodu
				}
				else{
					cout<<"Gecersiz Giris!"<<endl;
					continue;
				}
			}
	
		}
		else if (choice == 4)		//Ikili Agac baslangic
		{
			while(true)
			{	
			cout<<"--------------Ikili Agac Manu--------------"<<endl;		// cýikarma manu yazdýrma
			cout<<"/ 1.Agaca Eleman Ekle "<<endl;//menu yazdir
			cout<<"/ 2.Agactan Eleman Sil "<<endl;//menu yazdir
			cout<<"/ 3.Agaci Temizle "<<endl;//menu yazdir
			cout<<"/ 4.Agactaki Eleman Sayisini Goster "<<endl;//menu yazdir
			cout<<"/ 5.Agaci InOrder Dolasarak Elemanlari Goster "<<endl;//menu yazdir
			cout<<"/ 6.Agaci PreOrder Dolasarak Elemanlari Goster  "<<endl;//menu yazdir
			cout<<"/ 7.Agaci PostOrder Dolasarak Elemanlari Goster "<<endl;//menu yazdir
			cout<<"/ 8.Agacta Eleman Ara"<<endl;//menu yazdir
			cout<<"/ 9.Cikis "<<endl;//menu yazdir
			cout<<"----------------------------------------"<<endl;//menu yazdir
			cout<<"Lutfen seciminizi yapiniz: ";
			int secim;		//secim degiskeni
			cin>>secim;		//isteneni aldik
			if(secim == 1)	// secim 1 ise 
			{
				cout<<"lutfen degeri giriniz: ";
				int deger;		//eklenecek degeri tanimladik
				cin>>deger;		// degeri aldik
				a.dugumEkle(deger);		//metodumuzu cagirdik
			}else if(secim == 2)
			{
				cout<<"lutfen degeri giriniz: ";
				int deger;		//silnecek degeri tanimladik
				cin>>deger;		// degeri aldik
				a.sil(deger);	//metodu cagirdik
			}else if(secim == 3)
			{
				cout<<"Agac Temizleniyor..."<<endl;
				a.tumunuSil();		//agaci temizleme metodumuzu cagýrdýk
				cout<<"Agac Temizlendi."<<endl;	
			}else if(secim == 4)
			{
				cout<<"Agactaki eleman Sayisi :";a.sayac();		//sayacimizi cagirip yazdirdik
			}else if(secim == 5)
			{
				cout<<"Degerler InOrder seklinde yazdirilacak"<<endl;
				a.DugumGorInOrderYaz();		// yazdirma mmetodlarimizi cagiriyoruz
			}else if(secim == 6)
			{
				cout<<"Degerler PreOrder seklinde yazdirilacak"<<endl;
				a.DugumGorPreOrderYaz();	// yazdirma mmetodlarimizi cagiriyoruz
			}else if(secim == 7)
			{
				cout<<"Degerler PostOrder seklinde yazdirilacak"<<endl;
				a.DugumGorPostOrderYaz();	// yazdirma mmetodlarimizi cagiriyoruz
			}
			else if(secim == 8)
			{
				a.DugumAra();		
			}
			else if(secim == 9)
				cout<<"cikis gerceklestiriliyor"<<endl;
			else
				{
				cout<<"boyle bir girdi yok"<<endl;
				break;
				}
			
			}
		}else if(choice == 5)// Hash Tablosu baslangic
		{
			while(true)
			{	
			cout<<"--------------Hash Tablo Manu--------------"<<endl;		// cýikarma manu yazdýrma
			cout<<"/ 1.Hash Tablosuna Eleman Ekle "<<endl;//menu yazdir
			cout<<"/ 2.Hash Tablosundan eleman Sil "<<endl;//menu yazdir
			cout<<"/ 3.Hash Tablosunu Temizle "<<endl;//menu yazdir
			cout<<"/ 4.Hash Tablosundaki Eleman Sayisini Goster "<<endl;//menu yazdir
			cout<<"/ 5.Hash Tablosundaki Elemanlari Goster "<<endl;//menu yazdir
			cout<<"/ 6.Cikis "<<endl;//menu yazdir
			cout<<"----------------------------------------"<<endl;//menu yazdir
			cout<<"Lutfen seciminizi yapiniz: ";
			int secim;		//secim degiskeni
			cin>>secim;		//isteneni aldik
			if(secim == 1)	// secim 1 ise 
			{
				cout<<"lutfen eklemek istediginiz degeri girin: ";
				int alinan;
				cin>>alinan;
				h.Ekle(alinan);
				cout<<"eleman eklendi"<<endl;
			}else if (secim == 2)
			{
				cout<<"lutfen silmek istediginiz sayiyi giriniz: ";
				int silinen;
				cin>>silinen;
				h.Sil(silinen);
				cout<<"deger silinmistir"<<endl;
			}else if(secim == 3)
			{
				cout<<"Hash tablosu temizleniyor..."<<endl;
				h.tumunuSil();
				cout<<"Temizlendi"<<endl;			
			}else if(secim == 4)
			{
				h.sayac();
			}else if(secim == 5)
			{
				int aranan;
				cout<<"lutfen aramak istediginiz veriyi giriniz \nunutmayin ki girilen degerler gore siralama yapilacaktir. ";
				cin>>aranan;
				Dugum* pTemp = h.Bul(aranan);
				//dugumu yazdiralim 
				while (pTemp != NULL)
				{
				cout<<pTemp->Anahtar<<endl;
				pTemp = pTemp->pSonraki;
				}
			}else if(secim == 6)
			{
				cout<<"cikis secildi"<<endl;
				break;
			}else 
			{
				cout<<"Boyle bi secim yoktur"<<endl;
				continue;
			}
		}
					
		}else if(choice == 6)	// secim olarak ciks secildimi yapilacak islem
		{
		break;
		}
		else{	
			cout<<"Gecersiz Giris!"<<endl;
			continue;
		}
	
	}
}
	

