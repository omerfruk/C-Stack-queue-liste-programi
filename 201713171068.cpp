#include <iostream>
using namespace std;

//
class StackQueueNode
{
public:
	int data;
	StackQueueNode *next; //burada yapacagimiz islem stack yapimizdan boyutsuz olmasini saglayacak.
	//const bir verinin surekli olarak sabit kalmasini saglar
	StackQueueNode(const int &data = 0, StackQueueNode *next = NULL) : data(data), next(next) {}
};

//Stack yapimizi yazal覺m.

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
// dugum classini burda belirtiyoruz ve nesne ureterek kullanicaz
class node
{
public:
	node()
	{
		pNextValue = NULL;
		//int toplam=0;
	}
	int veri;
	node *pNextValue;
};
/*
buradaki algoritmada yapmaya calistigim bir node verisi olusturmak istedigimizde direk olarak degerler atans覺n 
ve baglamalar覺 otomatik olarak yapilsin fakat tam olarak yapamadim
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
	
}*/

//-----node fonk.-----
void ArayaEkle(node *, node *, int); //araya ekleme fonk
void SonaEkle(node *, node *);		 // sona ekleme fonk
node *AradanCikar(node *, int);		 // aradan cikarma fonk
node *SondanCikar(node *);			 // sondan cikarma fonk
void Bagla();						 //baglama fonk

int main() // main fonk islemler burada gerceklesecek
{
	Queue q;  // nesne olustur
	Stack s;  //nesne olusturalim
	bool MainManu = true; // ana menuye donmek icin gerekli degiskenimiz
	while (MainManu)
	{																// surekli bu menude kalmak icin gerekli dongu
		cout << "----------------Menu------------------" << endl;	//menu yazdiralim
		cout << " Yapmak istediginiz uygulamayi seciniz:" << endl;	//menu yazdiralim
		cout << "/ 1.Yigin uygulamasi	                " << endl; //menu yazdiralim
		cout << "/ 2.Kuyruk uygulamasi                " << endl;	//menu yazdiralim
		cout << "/ 3.Tek yonlu bagli liste uygulamasi " << endl;	//menu yazdiralim
		cout << "/ 4.Cikis                            " << endl;	//menu yazdiralim
		cout << "--------------------------------------" << endl;	//menu yazdiralim
		int choice;												//secim icin bir degisken alalim
		cin >> choice;												// degiskene kullanicidan deger isteyelim

		if (choice==1){
				cout<<"otomatik veriler atanm�st�r"<<endl;
				cout<<"Stack yapisini en bastan duzenlemek icin lutfen temizleyin"<<endl;
				for (int i = 0; i <= 5; i++)
				{				  // dongu ile veri yazdiralim	
					s.push(i+1); // metodumuzla veriyi gonderelim
				}
				
				bool StackManu = true; //Stack menusunde kalmak icin degisken tanimlayalim
				while (StackManu)
				{					// menude kalmak icin dongu kural覺m
				// burada otomatik olarak de��er veriyoruz
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
				cin >> choice;												// secimi alalaim kullanicidan
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
						s.writeAll(); // metodu ile tum verileri yazdiralim
						}
					else if(choice == 5){
						cout << "Stackteki verilerin boyutu " << s.getSize()+1 << endl; // metodu kullanarak dizinin boyutunu gosterelim
						}
					else if(choice == 6){
						StackManu = false; // ana menu ye donmek icin donguyu sonlandiracak atamayi yapalim
						}
					
					else{ // olasi istenmeyen tum durumlari ele alp yonlendirilmesini yapalim
						cout << "girilen deger istenilenler arasina bulunmamaktadir..." << endl;
						StackManu = false; //ana menu ye donmek icin donguyu sonlandiracak atamayi yapalim
					}	
				}
	}
	
				else if(choice == 2)// kuyruk yapisi baslangici
					{					   
					cout<<"otomatik veriler atanmistir"<<endl;
					cout<<"kuyruk yapisini en bastan kurmak icin lutfen temizleyiniz."<<endl;
					int data; // ekleme islemi icin degisken ata
					for (int i = 0; i <= 5; i++)
					{				 // dongu kur
						data = i;	 // degiskeni dongunun adedine esitle
						q.Add(data); // metodla ekleme yap
					}
				bool QueueManu = true; // dongu kurabilmek icin degisken atayalim
				while (QueueManu)
				{																// queue menumuzu surekli gormek icin bir dongu yazalim
					cout << "-------------Queue Menu---------------" << endl;	//menu yazd覺r
					cout << " Yapmak istediginiz islemi seciniz:   " << endl;	//menu yazd覺r
					cout << "/ 1.Kuyruga eleman ekle 			" << endl; //menu yazd覺r
					cout << "/ 2.Kuyruktan  eleman cikar		" << endl; //menu yazd覺r
					cout << "/ 3.Kuyrugu temizle				" << endl; //menu yazd覺r
					cout << "/ 4.Kuyruktaki elemanlari goster  	" << endl;		//menu yazd覺r
					cout << "/ 5.kuyruktaki eleman sayisini goster" << endl;	//menu yazd覺r
					cout << "/ 6.Ana menuye don 				" << endl; //menu yazd覺r
					cout << "--------------------------------------" << endl;	//menu yazd覺r

					// burada otomatik olarak de��er veriyoruz
					int choice;	// secim icin degisken ata
					cin >> choice;	// degiskeni kulanicidan al
				    if (choice == 1)
					{
						int data;
						cout<<"<-lutfen eklemek istediginiz degeri giriniz->"<<endl;	  //kullanicidan isteyecegimiz degerin atanmasi
						cin >> data;									  // degiskenin alinmasi
						q.Add(data);									  // metodla istenen degerin eklenmesi kuyruk mantigi oldugundan ilk giren veri ilk cikar yani ekmek sirasi gibi yer belirtemeyiz
						cout << "kuyruga "<< data<<"degeri eklendi " << endl; //eklenen degeri gosteme
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
						QueueManu = false; // donguden cikabilmek icin gereken false atamasini yapalim
					}
					else {
						cout << "boyle bir islem belitrilmemistir\n l�tfen tekrar deneyiniz." << endl; //yanlis secim uyarisi
						QueueManu = false;									// girilen yanklis secimleri ana menuye gondererek hatalardan kacinalim
					
					}
					}
				}
			
			else if(choice == 3)
			{
				//siradan veriler yazdiralimm ve baglamayi yapalim 
				//yeni dugumler ekledik.
				node *value1 = new node(); // nesne olusturalim
				node *value2 = new node(); // nesne olusturalim
				node *value3 = new node(); // nesne olusturalim
				node *value4 = new node(); // nesne olusturalim
				node *value5 = new node(); // nesne olusturalim
				// dugumlerin veri yerlerine eleman ekledik.
				value1->veri = 1; //nesnelerin veri bolmelerine istedigimiz degerleri yazalim
				value2->veri = 2; //nesnelerin veri bolmelerine istedigimiz degerleri yazalim
				value3->veri = 3; //nesnelerin veri bolmelerine istedigimiz degerleri yazalim
				value4->veri = 4; //nesnelerin veri bolmelerine istedigimiz degerleri yazalim
				value5->veri = 5; //nesnelerin veri bolmelerine istedigimiz degerleri yazalim
				//dugumleri birbirine baglad�k
				value1->pNextValue = value2; // veri tipimiz liste oldugu icin 2 bogumlu bir kutu dusunup bir kutumuzun icine deger verirken diger kutumuzun icine bir sonraki verimizin adresini at覺yal覺m
				value2->pNextValue = value3; //liste mantigini uygulama
				value3->pNextValue = value4; //liste mantigini uygulama
				value4->pNextValue = value5; //liste mantigini uygulama
				cout<<"otomatik veriler yuklendi"<<endl;
				cout<<"listeyi en bastan yapmak icin temizleyiniz"<<endl;
				bool BagilListe = true;		 // bagil liste icinde kalmak icin bir degisken tanimlayalim
				while (BagilListe)			 // dongumuzu kurup bu menude kalalim
				{
					cout << "------------Liste   Menu--------------" << endl;	//liste yazdir
					cout << " Yapmak istediginiz islemi seciniz:   " << endl;	//liste yazdir
					cout << "/ 1.Listeye eleman ekle 			" << endl; //liste yazdir
					cout << "/ 2.Listeden  eleman cikar	     	" << endl;		//liste yazdir
					cout << "/ 3.listeyi temizle					" << endl; //liste yazdir
					cout << "/ 4.listedeki elemanlari goster    	" << endl;		//liste yazdir
					cout << "/ 5.listenin eleman sayisini goster    " << endl;	//liste yazdir
					cout << "/ 6.Ana menuye don 					" << endl; //liste yazdir
					cout << "--------------------------------------" << endl;	//liste yazdir
					int choice;												// secim icin degisken tanimlayalim
					cin >> choice;												// kulanicidan deger alalim
					if(choice == 1)
					{
						int degisen = 6;		 //eklenecek degerin nerden eklenecegini son degeri arttirmak icin
						bool EklemeSekli = true; // menu icinde kalabilme degiskeni
						while (EklemeSekli)
						{																// menu icerisinde gezinebilmek icin dongu
							cout << "---------Ekleme seklini seciniz---------" << endl; //liste yazdir
							cout << "/ 1. Araya eleman ekleme.              " << endl; //liste yazdir
							cout << "/ 2. Sona eleman ekleme.             " << endl; //liste yazdir
							cout << "/ 3. Listeleme islemlerine geri don.   " << endl; //liste yazdir
							cout << "----------------------------------------" << endl; //liste yazdir
							char choice;												// secim icin degisken tanimlama
							cin >> choice;												// kullanicidan secim alma
							if (choice == 1)
							{/*
								int istenen, index;			   // degisken tanimlayalim altta anlaticaz
								node *value(degisen) = new node(); // nesnemizi olusturduk her bu metoda gelindiginde otomatik olarak 1 adet nesne olusturacaz
								cout << "istenen degeri giriniz" << endl;
								cin >> istenen;					// kulanicidan bir deger isteyecez bunu istenen degiskenine atiyacaz bunu da degisken indexli nesnemizin verisine atiyacaz
								value(degisen)->veri = istenen; //  degisken indexli nesnemizin verisine atama
								cout << "degeri kacinci index e yuklemek istersiniz" << endl;
								cin >> index;							  // yapimizda nereye ekleme yapacagimizi belirlemek icin kullanicidan index isteme
								ArayaEkle(value1, value(degisen), index); // fonk. parametrelerimizi gonderiyoruz
								degisken++;								  // degiskenimizi arttiriyoruz ki bir sonraki veriyi ustine yazmasin
							*/
							}
							else if(choice == 2)
							{
							/*	
								int istenen;					   // degisken tanimlayalim alta anlatalim
								node *value(degisen) = new node(); // nesne olusturuyoruz fakat 羹stte global(degisen) degiskenimiz inexinde
								cout << "degeri giriniz" << endl;
								cin >> istenen;					  // eklemek istedigimiz degeri istiyoruz
								value(degisen)->veri = istenen;	  // atama oparetorleri ile degisken indexli nesnemizin verisine kullanicidan aldigimiz veriyi atiyoruz
								SonaEkle(value1, value(degisen)); // metodumuza parametre gondererek calistiriyoruz
								degisen++;						  // tabiki global degiskenimizi arttirmayi unutmuyoruz
							*/
							}
							else if (choice == 3)
							{
								EklemeSekli = false; //ekleme menusunden cikmak icin gerekli atamayi yapiyoruz
							}
							else 
							{
								cout << "seciminiz dogru degildir" << endl;
								EklemeSekli = false; //istenmeyen islem seceneklerini menuye tekrar gondererek engelliyoruz
							}
						}
					}
					else if (choice ==2 )
						{
						bool SilmeSekli = true; // silme islem menusu icin degisken olusturma
						while (SilmeSekli)
						{																 // menuyu surekli onumuzde tutmak icin dongu
							cout << "---------Silme seklini seciniz---------" << endl;	 //menu yazdir
							cout << "/ 1. Aradan eleman silme.              " << endl;	 //menu yazdir
							cout << "/ 2. Sondan eleman silme.             " << endl; //menu yazdir
							cout << "/ 3. Listeleme islemlerine geri don.   " << endl;	 //menu yazdir
							cout << "----------------------------------------" << endl;	 //menu yazdir
							char choice;												 // secim degiskenini tanimlama
							cin >> choice;												 // kullanicidan secimi alma
							if (choice == 1)
							{
								int index; // degisken tanimlayalim
								cout << "silmek istediginiz eleman覺n indexini giriniz" << endl;
								cin >> index;				// cikarilacak elemanin indexini kullanicidan alalim
								AradanCikar(value1, index); // metodlara parametre gondererk calistiralim
							}
							else if (choice == 2)
							{
								SondanCikar(value1); // sondan c覺karma metodunun parametresini direk atayalim
							}
							else if (choice == 3)
							{
								SilmeSekli = false; // metod cikisi icin gerekli atamayi yapalim
							}
							else 
							{ 
								cout << "girilen islem bulunamad覺" << endl;
								SilmeSekli = false; // istenmeyen secimler icin manuye tekrar yonlendirme
							}
						}
						}
					else if (choice == 3)
					{
						value1->veri = NULL; //nesnemizim en basindaki veriyi null yaparsak listemizi sileriz
					}
					else if (choice == 4) // burada yazd覺��覺m覺z fonk ta yapt覺g覺m覺z while d繹ng羹s羹yle kuyrukta gezmek
						{/*
						int x = 1;				 // degisken tanimlayalim
						while (x != degisen + 1) // verileri listeleme icin gerekli donguyu olusturalim
						{
							cout << "" value(x)->veri << endl; // elemanlari birer bire yazdiralim
							x++;							   // degiskenimiz artiralim
						}*/
						}
					else if (choice == 5)
					{/*
						for (int y = 1; y <= degisken; y++) // listemizdki elemanlarin sayisini gormemizi saglayacak metod
						{
							int toplam = 0; // degisken atamasi
							toplam++;		//toplam degiskeni bize listemizde ka癟 adet degisken oldugunu g繹stersin
						}
						cout << "toplam veri say覺s覺" toplam << endl;
					*/}
					else if (choice == 6)
					{
						BagilListe = false; // liste manumuzden cikmak icin gerekli false atamasini yapalim
					}
					 else 
					{
						cout << "boyle bir secenek yoktur" << endl;
					}
				}
			}
			else if (choice ==4)
				MainManu = false;
			else 
				MainManu = false;
			}
		}
	


// dugum sona veri ekleme fonk.
void SonaEkle(node *veri, node *pNew)
{
	while (veri->pNextValue != NULL)
		veri = veri->pNextValue;

	veri->pNextValue = pNew;
}
// bu fonk bir node olusturduk mu otomatik olarak nesneyi olustutrup verileri atiyacak
/*
void Bagla()
{
	int i =1,ekle;
	node* value(i)=new node();
	cout<<"lutfen eklenecek degeri giriniz"<<endl;
	cin>>ekle;
	value(i)->veri=ekle;
	i++;
}
*/
//dugumde araya veri ekleme fonk.
void ArayaEkle(node *veri, node *pNew, int index) //metod parametreleri belirtme
{
	for (int i = 0; i < index - 2; i++)
		veri = veri->pNextValue;

	pNew->pNextValue = veri->pNextValue; // yeni girilen verinin pointirini bir onceki veriye baglama
	veri->pNextValue = pNew;			 // yeni girilen degerin adresini ondan onceki verinin adres bolumune atama
}

//dugumde aradan cikarma fonk.
node *AradanCikar(node *veri, int index) // metoda parametre alma
{
	for (int i = 0; i < index - 2; i++) // donguyle ilerleme
		veri = veri->pNextValue;

	node *pNew = veri->pNextValue;
	veri->pNextValue = veri->pNextValue->pNextValue; // burada yaptigimiz bir verinin uzerinden bagli oldugu veriye ulasip ortada kalan veriyi bir nevi devreden cikarmak icin

	return pNew;
}

//dugumde sondan c覺karma fonk.
node *SondanCikar(node *veri)
{
	while (veri->pNextValue->pNextValue != NULL) // son degere kadar ilerlemek icin gerekli dongu
		veri = veri->pNextValue;

	node *pNew = veri->pNextValue; //nesne olusturma
	veri->pNextValue = NULL;	   // silinecek olan veriden bir onceki verinin adres bolmunu nullama yani silem

	return pNew;
}
