The Story:

Hogsmeade Railway Station is developing rapidly and needs to be digitized
information to make it easier to plan your activities. 

Our goal is to create a program to solve the most important operations of the station, in order to facilitate the work
of the employees.

In order to implement the necessary functions, we will use three data structures:

a). TrainStation is the structure that represents the station. 
The station has several platforms, and each one platform can park a train. 
The platforms_no field represents the number of platforms in the station, and
the platforms field is a vector that contains stationary platforms and trains. 
It is not mandatory that there is a stationary train on each platform at a certain point in time.

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
