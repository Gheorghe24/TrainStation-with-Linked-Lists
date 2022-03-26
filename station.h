#ifndef _STATION_H_
#define _STATION_H_

/* 
 * Reprezentarea unui vagon. 
 */
typedef struct TrainCar {
    int weight;                 // greutatea unui vagon
    struct TrainCar *next;      // urmatorul vagon din secventa
} TrainCar;

/* 
 * Reprezentarea unui tren. 
 */
typedef struct Train {
    int locomotive_power;       // puterea de tractiune a locomotivei
    TrainCar* train_cars;       // primul vagon din secventa de vagoane
} Train;

/* 
 * Reprezentarea unei gari. 
 */
typedef struct TrainStation {
    int platforms_no;           // numarul de peroane
    Train **platforms;          // vector de peroane
} TrainStation;


TrainStation* open_train_station(int platforms_no);
void close_train_station(TrainStation *station);
void show_existing_trains(TrainStation *station, FILE *f);
void arrive_train(TrainStation *station, int platform, int locomotive_power);
void leave_train(TrainStation *station, int platform);
void add_train_car(TrainStation *station, int platform, int weight);
void remove_train_cars(TrainStation *station, int platform, int weight);
void move_train_cars(TrainStation *station, int platform_a, int pos_a, 
                                int cars_no, int platform_b, int pos_b);
int find_express_train(TrainStation *station);
int find_overload_train(TrainStation *station);
int find_optimal_train(TrainStation *station);
int find_heaviest_sequence_train(TrainStation *station, int cars_no, 
                                    TrainCar **start_car);
void order_train(TrainStation *station, int platform);
void fix_overload_train(TrainStation *station);

#endif
