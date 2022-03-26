#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "station.h"


/* Creeaza o gara cu un numar fix de peroane.
 * 
 * platforms_no: numarul de peroane ale garii
 *
 * return: gara creata
 */
TrainStation* open_train_station(int platforms_no) {
    if(platforms_no <= 0)
    return NULL;
    TrainStation *newstation = (TrainStation*) malloc(sizeof(TrainStation));

    if (newstation) {
        newstation->platforms_no = platforms_no;
        newstation->platforms = (Train**) malloc(platforms_no*sizeof(Train*));

        if (newstation->platforms) {
            //alocarea fiecarui peron
            for(int i = 0; i < platforms_no; i++) {
                newstation->platforms[i] = (Train*) malloc(sizeof(Train));
                if (newstation->platforms[i]) {
                    newstation->platforms[i]->locomotive_power = 0;
                    newstation->platforms[i]->train_cars = NULL;
                }

            } 
        }
    }
    return newstation;
}


/* Elibereaza memoria alocata pentru gara.
 *
 * station: gara existenta
 */
void close_train_station(TrainStation *station) {
    if(station == NULL) return;
    if (station->platforms == NULL) {
        free(station);
        return;
        }

    int i ;
    for(i = 0; i < station->platforms_no; i++) {  
        if (station->platforms[i]) {
            TrainCar *iter = station->platforms[i]->train_cars;
            while(iter != NULL) {
                station->platforms[i]->train_cars = station->platforms[i]->train_cars->next;
                free(iter);
                iter = station->platforms[i]->train_cars;
            }
            free(station->platforms[i]);
        }
       
    } 
    // if(station->platforms != NULL)
    free(station->platforms);
    // if(station != NULL)
    free(station);
}


/* Afiseaza trenurile stationate in gara.
 *
 * station: gara existenta
 * f: fisierul in care se face afisarea
 */
void show_existing_trains(TrainStation *station, FILE *f) {
    // if(f == NULL) {
    //     fprintf(stderr, "\nError opened file\n");
    //     return;
    // }
     int i = 0;
     if(station == NULL) 
     return;
     if(station->platforms == NULL) 
     return;
    for(i = 0; i < station->platforms_no; i++) {
        fprintf(f, "%d: ", i);
        if(station->platforms[i] != NULL && station->platforms[i]->train_cars != NULL) {
            fprintf(f, "(%d)", station->platforms[i]->locomotive_power);
            TrainCar *current = station->platforms[i]->train_cars->next;
            while (current!=NULL)
            {
                fprintf(f, "-|%d|", current->weight);
                current = current->next;
            }
                
         }
        fprintf(f, "%s", "\n");
    }
}


/* Adauga o locomotiva pe un peron.
 * 
 * station: gara existenta
 * platform: peronul pe care se adauga locomotiva
 * locomotive_power: puterea de tractiune a locomotivei
 */
void arrive_train(TrainStation *station, int platform, int locomotive_power) {
    int i = 0;
    if(locomotive_power < 0) return;
    if(station != NULL) {
        if(station->platforms != NULL) {
            if(platform < station->platforms_no && platform >= 0) {
                if(station->platforms[platform] != NULL) {
                    if(station->platforms[platform]->train_cars == NULL ) { 
                        station->platforms[platform]->locomotive_power = locomotive_power;
                        station->platforms[platform]->train_cars = (TrainCar*) malloc(sizeof(TrainCar));
                        station->platforms[platform]->train_cars->weight = 0;
                        station->platforms[platform]->train_cars->next = NULL;
                        //printf("%d %d\n",i, station->platforms[i]->locomotive_power);
                    }
                }
            }
        }
    } 
}


/* Elibereaza un peron.
 * 
 * station: gara existenta
 * platform: peronul de pe care pleaca trenul
 */
void leave_train(TrainStation *station, int platform) {
if(station != NULL) {
        if(station->platforms != NULL) {
            if(platform < station->platforms_no && platform >= 0) {
                if(station->platforms[platform] != NULL) {
                    if(station->platforms[platform]->train_cars != NULL ) { 
                        
                        station->platforms[platform]->locomotive_power = 0;
                        TrainCar *iter = station->platforms[platform]->train_cars;
                        while(iter != NULL) {
                            station->platforms[platform]->train_cars = station->platforms[platform]->train_cars->next;
                            free(iter);
                            iter = station->platforms[platform]->train_cars;
                        }
                    }
                }
            }
        }
    } 
}


/* Adauga un vagon la capatul unui tren.
 * 
 * station: gara existenta
 * platform: peronul pe care se afla trenul
 * weight: greutatea vagonului adaugat
 */
void add_train_car(TrainStation *station, int platform, int weight) {
    if(weight < 0) {
        return ;
    }
    int i = 0;
    if(station != NULL) {
        if(station->platforms != NULL) {
            if(platform < station->platforms_no && platform >= 0) {
                if(station->platforms[platform]) {
                    if(station->platforms[platform]->train_cars){
                        TrainCar *vagon = (TrainCar*) malloc(sizeof(TrainCar));
                                vagon->weight = weight;
                                vagon->next = NULL;
                        TrainCar *last = station->platforms[platform]->train_cars;
                                while(last->next != NULL) {
                                    last = last->next;
                                }
                                last->next = vagon;
                    }
                } 
            }
        }
    }
}


/* Scoate vagoanele de o anumita greutate dintr-un tren.
 * 
 * station: gara existenta
 * platform: peronul pe care se afla trenul
 * weight: greutatea vagonului scos
 */
void remove_train_cars(TrainStation *station, int platform, int weight) {
    if(weight < 0) {
        return ;
    }
    if(station != NULL) {
        if(station->platforms != NULL) {
            if(platform < station->platforms_no && platform >= 0) {
                if(station->platforms[platform]) {
                    if(station->platforms[platform]->train_cars){
                        TrainCar *prev = station->platforms[platform]->train_cars, *current = prev->next;
                             while (current!=NULL) {
                                if(current->weight == weight) {
                                    prev->next = current->next;
                                    free(current);
                                    current=prev->next;
                                }
                                else {
                                    prev = current;
                                    current = current->next;
                                }
                            }                           
                    }
                } 
            }
        }
    }
}

int getCurrSize(struct TrainCar* node){
    int size = 0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}
/* Muta o secventa de vagoane dintr-un tren in altul.
 * 
 * station: gara existenta
 * platform_a: peronul pe care se afla trenul de unde se scot vagoanele
 * pos_a: pozitia primului vagon din secventa
 * cars_no: lungimea secventei
 * platform_b: peronul pe care se afla trenul unde se adauga vagoanele
 * pos_b: pozitia unde se adauga secventa de vagoane
 */
void move_train_cars(TrainStation *station, int platform_a, int pos_a, 
                                int cars_no, int platform_b, int pos_b) {

}

int train_speed(Train *train) {
    TrainCar *last = train->train_cars;
    int sum = 0;
    while (last!=NULL)
    {
        sum += last->weight;
        last = last->next;
    }
    return train->locomotive_power - sum ; 
}

/* Gaseste trenul cel mai rapid.
 * 
 * station: gara existenta
 *
 * return: peronul pe care se afla trenul
 */
int find_express_train(TrainStation *station) {
    int max = 0, speed = 0, i_max = 0 ;
    if(station != NULL) {
        if(station->platforms != NULL) {
            int len = station->platforms_no;
            for(int i = 0; i < len; i++) {
                speed = train_speed(station->platforms[i]);
                if(max < speed) 
                {   max = speed; 
                    i_max = i;
                }
            }
        }
    }
    return i_max;
}


/* Gaseste trenul supraincarcat.
 * 
 * station: gara existenta
 *
 * return: peronul pe care se afla trenul
 */
int find_overload_train(TrainStation *station) {
    int max = 0, speed = 0, i_max = -1 ;
    if(station != NULL) {
        if(station->platforms != NULL) {
            int len = station->platforms_no;
            for(int i = 0; i < len; i++) {
                speed = train_speed(station->platforms[i]);
                if(speed < 0) 
                    i_max = i;
            }
        }
    }
    return i_max;
}


/* Gaseste trenul cu incarcatura optima.
 * 
 * station: gara existenta
 *
 * return: peronul pe care se afla trenul
 */
int find_optimal_train(TrainStation *station) {
    int min = __INT_MAX__, speed = 0, i_min = 0 ;
    if(station != NULL) {
        if(station->platforms != NULL) {
            int len = station->platforms_no;
            for(int i = 0; i < len; i++) {
                speed = train_speed(station->platforms[i]);
                if(min > speed && speed > 0) 
                {   min = speed; 
                    i_min = i;
                }
            }
        }
    }
    return i_min;
}


/* Gaseste trenul cu incarcatura nedistribuita bine.
 * 
 * station: gara existenta
 * cars_no: lungimea secventei de vagoane
 *
 * return: peronul pe care se afla trenul
 */
int find_heaviest_sequence_train(TrainStation *station, int cars_no, TrainCar **start_car) {
    return -1;
}


/* Ordoneaza vagoanele dintr-un tren in ordinea descrescatoare a greutatilor.
 * 
 * station: gara existenta
 * platform: peronul pe care se afla trenul
 */
void order_train(TrainStation *station, int platform) {
    TrainCar *current = station->platforms[platform]->train_cars->next, *index = NULL;
    int temp = 0;
    if(station != NULL) {
        if(station->platforms != NULL) {
            if(platform < station->platforms_no && platform >= 0) { 
                while (current != NULL)
                {
                    index = current->next;
                    while (index!=NULL)
                    {
                        if(current->weight < index->weight) {
                            temp = current->weight;
                            current->weight = index->weight;
                            index->weight = temp;
                        }
                        index = index->next;
                    }
                    current = current->next;
                }  
            }
        }
    }
}


/* Scoate un vagon din trenul supraincarcat.
 * 
 * station: gara existenta
 */
void fix_overload_train(TrainStation *station) {
}
