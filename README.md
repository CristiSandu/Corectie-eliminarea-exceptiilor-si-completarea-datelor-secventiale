# Corectie, eliminarea exceptiilor si completarea datelor secventiale

[Cerinta](https://github.com/cristysandu/Corectie-eliminarea-exceptiilor-si-completarea-datelor-secventiale/blob/master/Tema1_SD.pdf)

Pentru am fi mai usor am implementat functi pentru initializare lista ,adaugare la final de lista ,stergere element din lista ,printare lista si eliberare de lista.
Citrea listei sa realizat inaintea parcurgeri argumentelor 
Afisarea dupa parcurgerea tuturor argumentelor 
La test-ul 9 pentru lista de intrare e1e2e3uc diferenta dintre ce imi da mie difera printr-o zecime de sutime fata de ce ar trebui sa dea 

Task-ul 1 - Am implementa formulele pentru sigma si X-barat cu ajutorul unor functi de medie
			  respectiv deviatie ,daca un element nu apartineau 
			  intervalului respectiv le salvam valoarea intr-o noua lista pe care o parcurgeam mai tarziu ca sa le sterg din lista initiala si returnam la final lista modificata 
			  alaturi de nr de elemente;

Task-ul 2.1 - La acesta am creeat subliste de 5 elemente pe care le-am ordonat crescator folosind
			   o functie de sortare ,apoi se parcurge lista iar cand ajunge la elementul din mijloc il adauga intr-o noua lista incrementand un nr care la final da numarul elementelor din noua lista

Task-ul 2.2 - Am parcurs lista creeand subliste de 5 elemente apoi am parcurs sublistele pe rand 
			   apeland functia de medie cand ajungeam la mijlocul sublistei functia returneaza noua lista cu mediile sublistelor si numarul de elemente din ea

Task-ul 3 - Am parcurs lista iar daca diferenta timestamp-urilor era in intervalul[0.1,1] 
			   secunde faceam media timestamp-urior si cea a valorilor si inlocuiam valoarea curenta.Functia returneaza lista dupa modificari.

Task-ul 4 - Pentru Task-ul acesta am implementat o serie de functii:dreapta si stanga (care 
			   formeaza subsirul stang si subsirul drept a cate 3 elemente),calcW ,calcC si Ffunction (care calculeaza C si W din formula utilizandule in Ffunction pentru calcularea valori noului element care trebuie adaugat).Parcurg lista cat timp nu e nula si ma intreb daca diferenta dintre timestamp-urile elementelor consecutive este mai mare de 1000 in cazul afirmativ se completeaza cu elemente pana cand aceasta diferenta este mai mica de 200 trebuind sa introducem cel putin 5 elemente.Calculam C si f iar apoi il introducem in lista incrementand nr de elemente din lista 

Bonus(Task5)- In acest task am parcurs argv[i]-ul scotand valoarea lungimi intervalelor pe care 
			   trebuie sa le creez ,apoi sortez lista apeland functia de sortare creeata anterior.
			   Aflu prima valoare de la care pornesc si o salvez in variabila first si ultima valoare din lista in variabila last si cat timp first < last parcurg lista pentru fiecare interval si numar cate elemente din lista se afla in acel interval daca exista cel putin un element printez intervalul cu tot cu nr de elemente din el  
