Tema 1 !!!

Open_train_station :
In aceasta functie am alocat mai intai memorie ptu gara, apoi ptu vectorul de peroane si ptu fiecare peron in parte.De asemenea am initializat cu 0 puterea locomotivei ptu a ma ajuta de asta pe viitor(Sper ca e ok :) ).

Close_train_station :
Am luat mai intai cazurile speciale in care nu ar exista gara sau peroanele(aici am dezalocat gara).Apoi ptu fiecare platforma am parcurs vagoanele trenului pana la final cu un "traincar" auxiliarm si le-am dezalocat si pe acestea in cazul in care exista impreuna cu platforma si vectorul de platforme.

Show_existing_trains :
La fel ca mai sus si in majoritatea functiilor din tema am inceput cu cazurile in care ceva nu ar exista(gara,plaformele,trenul).
Apoi am respectat regulile de scriere in fisier (numarul peronului, puterea locomotivei si greutatea fiecarui vagon).

Arrive_train: 
Aici am alocat memorie ptu locomotiva si i-am oferit puterea data ca parametru.

Leave train:
Am parcurs vagoanele trenului pana la final cu un pointer auxiliar si am dezalocat memorie ptu fiecare vagon in parte(in cazul in care exista).

Add_train_car:
In cazul in care exista locomotiva careia ar trebui sa ii atasez vagonul, imi aloc un vagon si ii dau weightul necesar, apoi parcurg vagoanele pana la final si pe ultima pozitie fac legatura intre acestea 2.

Remove_train_cars:
Ma folosesc de 2 pointeri auxiliari pentru a parcurge vagoanele pana la final iar atunci cand gasesc greutatea necesara la un anumit vagon, il sterg dar pastrez legatura intre noduri.

Move_train_cars:
Pentru rezolvarea acestei functii am mai implementat 2 functii ajutatoare (getCurrSize-numarul de vagoane, add_at_pos - adaugarea unui nod la o anumita pozitie).
Pentru inceput verific toate cazurile mai speciale in care nu as putea folosi functia data. Apoi parcurg prima plaforma pana la pozitia pos_a + cars_no pentru a insera pe rand "de la final" cate un vagon pe pozitia pos_b in plaforma B cu ajutorul functiei add_at_pos.
Dupa ce inserez, sterg din prima plaforma vagonul mutat.

Find_express_train:
Pentru aceasta functie implementez inca una care imi calculeaza greutatea tuturor vagoanelor unui tren si imi returneaza diferenta intre puterea locomotivei si aceasta greutate(train_speed).
Astfel folosesc functia ptu fiecare plaforma si vad care e diferenta maxima.

Find_overload_train:
La fel ca in functia de mai jos folosesc functia ajutatoare si aflu care din trenuri are diferenta minima ca sa intorc ca rezultat platforma pe care se afla.

Find_optimal_train:
Aceasta seamana foarte mult cu "Find_express_train" doar ca aflu minimul si returnez plaforma pe care se afla.

Find_heaviest_sequence_train:
Pentru fiecare tren calculez greutatea maxima pentru o anumita secventa data cu ajutorul unei functii(weight_train) si totodata salvez intr-un pointer primul vagon din acea secventa. Mai departe in functie aflu greutatea maxima si salvez pointerul prin start_car si returnez plaforma cu secventa maxima.

Order_train:
Folosesc algoritmul "Bubble sort" si schimb vagoanele(nodurile) intre ele atunci cand gasesc un caz in care lista nu e ordonata descrescator.
Ptu asta am avut nevoie si de numarul de vagoane al listei(functie creata mai sus). In cea de-a II-a structura repetitiva initializez 2 pointeri auxiliari cu care o sa fac parcurg lista si al III-lea in cazul in care e nevoie sa fac swap intre acestia. Ma opresc atunci cand parcurg lista "degeaba"(lista e sortata).Aflu asta pentru ca am o variabila de tip semafor in care salvez acest caz(de ordonare).

Fix_overload_train:
Aflu platforma care e supraincarcata. 
Imi initializez 2 pointeri(train si vagon).Cu ajutorul functiilor de mai sus aflu greutatea vagoanelor unui tren.Parcurg trenul pana la final si aflu vagonul care e cel mai optim ptu a-l scoate ca trenul sa se poata misca.
Ptu aceasta aflu diferenta minima intre greutatea vagoanelor si greutatea fiecarui vagon parcurs.Salvez pozitia vagonului si cu ajutorul unei functii care sterge nodul de pe o anumita pozitie din tren sterg vagonul.