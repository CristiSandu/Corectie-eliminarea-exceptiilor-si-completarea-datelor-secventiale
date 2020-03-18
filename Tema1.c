#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct list                  				//definim lista 
{
	double n;
	int timestamp;
	struct list *next;
	struct list *prev;

}*List;

List initList(double n,int t){						//initializam o lista cu un singur element   

	List l=(List)malloc(sizeof(struct list));		//alocam dinamic nodul
	l->n=n;		
	l->timestamp=t;									
	l->next=NULL;
	l->prev=NULL;

	return(l);
}

List addLast (List l,double n,int t){				//adauga la finalul unei liste valoarea n alturi de timestampul t 
	List k,q=l;

	if (l==NULL)									//daca lista e viza atunci returnam initList 
		return(initList(n,t));
	else
	{
		k=initList(n,t);							//initializam un nod 
		k->next=NULL;
		while(l->next!=NULL)						//parcurgem lista pana la final 
			l=l->next;
		l->next=k;									//facem finalul sa pointeze la nodul initializat 
		k->prev=l;									//facem nodul initializat sa pointeze la lista 
		return(q);
	}

}

void printlist (List l){							//printeaza lista l

	while(l!=NULL)									//cat timp lista nu e vida printam timestam si valoare 
	{
		printf("%d %.2lf\n",l->timestamp,l->n);
		l=l->next;
	}
}

List deleteitem(List l,double val){					//sterge elementul val 
	List q=l,t,r=l;
	if (l->n==val)									//daca val este primul element 
	{
		t=l;
		l=l->next;
		l->prev=NULL;
		free(t);
		return(l);
	}
		
			while(r->n!=val)				
			{
				r=r->next;
			}

			if (r->next==NULL)						//daca val este ultimul
			{
				t=r;
				r=r->prev;
				r->next=NULL;
				free(t);
				return(l);
			}else{									//daca val este in interiorul listei
					
				t=r;
				r->prev->next=t->next;
				t->next->prev=r->prev;
				free(t);
				return(q);
			}
	return(l);
		
}

List deleteList(List l){							//sterge lista l

	List q = l;										
	List k;
	while(q->next !=NULL)							//cat timp urmatorul element nu e null eliberam pe rand fiecare element din lista 
	{	k = q->next;
		free(q);								
		q = k;
	}
	l = NULL;									
		return(l);	
}

double media(List l,int n){							//calculeaza media vecinilor lui l->n

	double suma1;
	suma1=(l->next->next->n+l->next->n+l->n+l->prev->n+l->prev->prev->n);

	return ((suma1/(double)n));
}

double deviatia(List l,double dev1,int n){				//calculeaza deviatia 

	double suma2;
	suma2=(pow(((l->next->next->n)-dev1),2)+pow(((l->next->n)-dev1),2)+pow(((l->n)-dev1),2)+pow(((l->prev->n)-dev1),2)+pow(((l->prev->prev->n)-dev1),2));
	return (sqrt(suma2/n));
}


void SortList(List subs){ 								//sorteaza lista subs
    int schimbat;
    double aux; 
    List lista; 
    List llista = NULL; 
   
    if (subs == NULL) 
        return; 
   
    do
    { 
        schimbat = 0; 
        lista = subs; 
   
        while (lista->next != llista) 
        { 
	            if (lista->n > lista->next->n) 			//daca lista->n > lista->next->n le interschimba 
            {  
            	aux=lista->n;
            	lista->n=lista->next->n;
            	lista->next->n=aux;
                schimbat= 1; 
            } 
            lista = lista->next; 
        } 
        llista = lista; 
    } 
    while (schimbat); 
} 

List task1(List l1,int *n1){							 
	List q1=l1,desters=NULL;
	int nr1=0;
	double deviatie,sigma;
			for (int j = 0; j < *n1; ++j)
			{
				sigma=0;deviatie=0;
				if ((j>1)&&(((*n1)-1-j)>1))              //conditia pentru ignorarea primelor 2 respectiv ultimelor 2 valori din lista 
				{
					sigma=media(l1,5);											//calcualre sigma
					deviatie=deviatia(l1,sigma,5);								//calcualrea deviatiei
					if((l1->n<(sigma-deviatie))||(l1->n>(sigma+deviatie)))		//verificarea daca elementul apartiene intervalului [sigma-deviatie,sigma+deviatie]
					{
						desters=addLast(desters,l1->n,l1->timestamp);			//salvarea elementelor de sters in alta lista 
						nr1++;													//incrementare contor 			
					}	

				}
				l1=l1->next;													
			}
			for(int k=0;k<nr1 ;k++)												//stergera elementelor 
			{
				q1=deleteitem(q1,desters->n);
				(*n1)--;
				desters=desters->next;
			}

			l1=q1;
	return (q1);
}

List task2_1(List l1,int *n){
	List subs=NULL,q2=NULL,rezultat=NULL;
	int nr=0;
	while(l1->next->next->next->next!=NULL)
	{
		subs=NULL;q2=l1;	
		for (int j = 0; j < 5; ++j)	
		{
			subs=addLast(subs,q2->n,q2->timestamp);     //imparte lista in subliste 
			q2=q2->next;
		}

		SortList(subs);									//ordoneaza sublista 

		for (int k = 0; k < 5; ++k)
		{
				if(k==2)
				{
					rezultat=addLast(rezultat,subs->n,subs->timestamp);		//adaug elementul din mijloc la o noua lista rezultat 
					nr++;													//incrementez nr de elemente din lista rezultat 

				}
				subs=subs->next;		
		}

		l1=l1->next;
	}
	(*n)=nr;								//atribui n-ului noua valoare a listei 						
	l1=q2;

	return(rezultat);						//returnez lista rezultat 
}

List task2_2(List l1,int *n){
	List subs3=NULL,q3=NULL,medie=NULL;
	int nr=0;
	double med;
			while(l1->next->next->next->next!=NULL)
			{
				subs3=NULL; q3=l1;
				for (int i = 0; i < 5; ++i)
				{
					subs3=addLast(subs3,q3->n,q3->timestamp);				//creez subliste de 5 
					q3=q3->next;
				}
			

				for (int i = 0; i < 5; ++i)
				{
					if ((i>1)&&((4-i)>1))									//ignor piele 2 respectiv ultimele 2 elemente din subs3
					{
						med=media(subs3,5);
						medie=addLast(medie,med,subs3->timestamp);			//adauga la finalul listei medie 
						nr++;
					}
					subs3=subs3->next;
				}
				l1=l1->next;

			}
			*n=nr;
			deleteList(l1);
	return(medie);									//returneaza lista medie 
}

List task3(List l1,int n1){
	List q4=NULL;
	q4=l1->next;
	for (int i = 1; i < n1; ++i)
	{
			if(((q4->timestamp-q4->prev->timestamp)>=100)&&((q4->timestamp-q4->prev->timestamp)<=1000))   //daca diferenta dintre doua timestampuri e intre [0.1 si 1] secunde 
			{
				q4->timestamp=(q4->prev->timestamp+q4->timestamp)/2;
				q4->n=(q4->prev->n+q4->n)/(double)2;
			}
		q4=q4->next;
	}
	q4=l1;

	return l1;
}

List stanga(List l1)						//formeaza lista stanga pentru task-ul 4
{
	List q=NULL;
	q=addLast(q,l1->prev->prev->n,l1->prev->prev->timestamp);
	q=addLast(q,l1->prev->n,l1->prev->timestamp);
	q=addLast(q,l1->n,l1->timestamp);

	return q;
}

List dreapta(List l1)						//formeaza lista dreapta pt task-ul 4
{
	List q=NULL;
	q=addLast(q,l1->next->n,l1->next->timestamp);
	q=addLast(q,l1->next->next->n,l1->next->next->timestamp);
	q=addLast(q,l1->next->next->next->n,l1->next->next->next->timestamp);

	return q;
}

double calcC(int timestamp,int L,int R)		//caluleaza C ul de la task-ul 4
{
	double c = 0;
	c=(double)(timestamp-L);
		   c=(double)c/(double)(R-L);
	return c;
}
double calcW(int i, int k)					//calculeaza w de la task-ul 4
{
	double w=0,s=0;
	w=pow((double)(i/(double)(k - 1)), 2)*0.9+0.1;
	for (int j = 0; j < k; j++)
	{
		s+=pow((double)(j/(double)(k-1)),2)*0.9+0.1;
	}
	return(w/s);
}
double Ffunction(double C,List left,List right)		//calculeaza noua valoare ce trebuie inserata la task-ul 4 
{
	List L1=left,R1=right;
	double suma1=0,suma2=0,f;

	for (double i = 0; i < 3; i++)
	{
		suma1+=left->n*calcW(i,3);
		suma2+=right->n*calcW(i,3);
		left=left->next;
		right=right->prev;
	}

	f=(1-C)*suma1+C*suma2;
	left=L1;
	right=R1;
	
	return f;
}

List task4(List l1, int *n1)
{
	List q1=l1,L=NULL,R=NULL,R1=NULL,left=NULL,right=NULL,q=NULL;
	double C,f;
			while(l1->next->next!=NULL){

				if(l1->next->timestamp - l1->timestamp > 1000)		//daca diferenta dintre timestampuri consecutive ste mai mare de 1000 ms 
				{
					left=stanga(l1);
					right=dreapta(l1);
					
					L=left;
					//L1=left;
					R1=right;
					R=right;
					//R1=right;
					while(L->next!=NULL)
						L=L->next;
					while(R1->next!=NULL)
						R1=R1->next;


					while(l1->next->timestamp-l1->timestamp>200)                     //cat timp diferenta dintre timestampuri este mai mica de 200 adauga valori noi implementand functiile                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
					{
						
						C=calcC(l1->timestamp+200,L->timestamp,R->timestamp);
						
						
						f=Ffunction(C,left,R1);
						q=initList(f,l1->timestamp+200);
						
						(*n1)++;
						q->next=l1->next;
						l1->next=q;
						q->prev=l1;

						l1=l1->next;
					}

				}
				l1=l1->next;
			}
					
			l1=q1;	
		return l1;
}

int main(int argc, char const *argv[])
{
	List l1=NULL,q=NULL;
	int n1,t1,nr,first,m,nrelementeinterval;
	int val;
	double last ;
	double x1;

	scanf("%d",&n1);					//citirea nr de elemente

	for (int i = 0; i < n1; ++i)		//initializare lista cu valoare si timestamp
	{
		scanf("%d",&t1);
		scanf("%lf",&x1);
		l1=addLast(l1,x1,t1);
	}

	for (int i = 1; i < argc; i++)       //parcurgerea sirului dde argumente 
	{
		
		if(strcmp(argv[i],"--e1")==0)
		{
			l1=task1(l1,&n1);			//apelarea functie pentru --e1
		}

		if (strcmp(argv[i],"--e2")==0)
		{
			l1=task2_1(l1,&n1);			//apelarea functie pentru --e2
		}

		if ((strcmp(argv[i],"--e3")==0))
		{
			l1=task2_2(l1,&n1);			//apelarea functie pentru --e3
		}

		if (strcmp(argv[i],"--u")==0)
		{	
			l1=task3(l1,n1);			//apelarea functie pentru --u
		}

		if (strcmp(argv[i],"--c")==0)
		{
			l1=task4(l1,&n1);				//apelarea functie pentru --c
		}

		if(argv[i][2]==115)					//apelare bonus 
	 	{
	 		int k=4;
	 		val=0;
	 		
	 		
	 		while(argv[i][k]!=0)			//extragerea stringului din argument 
	 		{
	 			val=argv[i][k]+val*10-48;
	 			k++;
	 		}
	 		
	 		SortList(l1);					//sortare lista 
	 		first=(int)l1->n;
	 		q=l1;
	 		nr=0;
	 		
	 		if(first<0)								//determinarea margini inferioare 
	 			first=first-(val+(first%val));
	 		else
	 			first=first-(first%val);

	 		while(l1->next!=NULL)				//pargurcere lista pana la ultimul element 
	 		{
	 			l1=l1->next;
	 		}
	 		
	 		last=l1->n;							//last primeste ultimul element 
	 		
	 		l1=q;
	 		m=first+val;

	 		while(first<last)					//parcurgere lista 
	 		{
	 			l1=q;							//atriguim pozitia de inceput lui l1
	 			nrelementeinterval=0;			//initializare contor cu 0 pt nr de elemente din interval 
	 			
	 			while(l1!=NULL)					
	 			{
	 				if((l1->n>=first)&&(l1->n<=m))			//testam daca valoare apartine intervalului [first,m]
	 					nrelementeinterval++;				//daca da incrementam contorul 
	 				l1=l1->next;
	 			}
	 			if (nrelementeinterval!=0)					//daca contor >0 
	 			{
	 				printf("[%d, %d] %d\n",first ,m ,nrelementeinterval );	//printam intervalul cu nr de elemente din el 

	 			} 
	 			first+=val; 								//trecem la urmatorul interval 
	 			m+=val;
	 		}
	 		nr=1;								//daca acest task a fost facut nr=1
	 	}


	}
	if (nr!=1)									//daca bonus nu sa facut atunci printam lista l1 si n1 
	{
		printf("%d\n",n1 );
		printlist(l1);
		deleteList(l1);							//eliberam memoria
	}
	
	return 0;
}