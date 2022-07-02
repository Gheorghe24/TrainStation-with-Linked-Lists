The Story:

Hogsmeade Railway Station is developing rapidly and needs to be digitized
information to make it easier to plan your activities. 

Our goal is to create a program to solve the most important operations of the station, in order to facilitate the work
of the employees.

In order to implement the necessary functions, we will use three data structures:

a). TrainStation is the structure that represents the station. \
The station has several platforms, and each one platform can park a train. \
The platforms_no field represents the number of platforms in the station, and \
the platforms field is a vector that contains stationary platforms and trains. 

It is not mandatory that there is a stationary train on each platform at a certain point in time.

    struct {
        int platforms_no;
        Train **platforms;
    } TrainStation;

b). Train is the structure that represents a train. \
Each train consists of a locomotive and a wagon sequence. 
The locomotive_power field represents the maximum weight it can transport the locomotive. 

If the total weight of the wagons exceeds this value, the train does not
will be able to leave the station. The train_cars field represents the first wagon in 
the wagon sequence a train (is the wagon attached to the locomotive).

    struct {
        int locomotive_power;
        TrainCar* train_cars;
    } Train;
  
c). TrainCar is the structure that represents a wagon. Each wagon has an associated 
weight that is retained in the weight field. The next field represents the next wagon 
in the sequence of train wagons.

    struct {
        int weight;
        TrainCar *next;
    } TrainCar;
