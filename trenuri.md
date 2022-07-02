Enunț: 

Gara din Hogsmeade se dezvoltă rapid și are nevoie de o digitalizare a
informației pentru a-și planifica mai ușor activitățile. Scopul nostru este să creăm un program
care să rezolve operațiile cele mai importante ale gării, pentru a ușura munca angajaților.
Pentru a putea implementa funcțiile necesare, vom folosi trei structuri de date:

a). TrainStation este structura care reprezintă gara. Gara are mai multe peroane, iar pe fiecare
peron poate staționa un tren. Câmpul platforms_no reprezintă numărul de peroane al gării, iar
câmpul platforms este un vector care conține peroanele și trenurile staționate. Nu este
obligatoriu ca pe fiecare peron să existe un tren staționat la un anumit moment de timp.

  struct {
  int platforms_no;
  Train **platforms;
  } TrainStation;

b). Train este structura care reprezintă un tren. Fiecare tren este format dintr-o locomotivă și o
secvență de vagoane. Câmpul locomotive_power reprezintă greutatea maximă pe care o poate
transporta locomotiva. Dacă greutatea totală a vagoanelor depășește această valoare, trenul nu
va putea pleca din stație. Câmpul train_cars reprezintă primul vagon din secvența de vagoane a
trenului (este vagonul atașat de locomotivă).

  struct {
  int locomotive_power;
  TrainCar* train_cars;
  } Train;
  
c). TrainCar este structura care reprezintă un vagon. Fiecare vagon are o greutate asociată care
este reținută în câmpul weight. Câmpul next reprezintă următorul vagon din secvența de
vagoane a trenului.

struct {
int weight;
TrainCar *next;
} TrainCar;
