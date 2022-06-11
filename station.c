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
TrainStation * open_train_station(int platforms_no) {
  if (platforms_no <= 0)
    return NULL;
  TrainStation * newstation = (TrainStation * ) malloc(sizeof(TrainStation));

  if (newstation) {
    newstation -> platforms_no = platforms_no;
    newstation -> platforms = (Train ** ) malloc(platforms_no * sizeof(Train * ));

    if (newstation -> platforms) {
      //alocarea fiecarui peron
      for (int i = 0; i < platforms_no; i++) {
        newstation -> platforms[i] = (Train * ) malloc(sizeof(Train));
        if (newstation -> platforms[i]) {
          newstation -> platforms[i] -> locomotive_power = 0;
          newstation -> platforms[i] -> train_cars = NULL;
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
void close_train_station(TrainStation * station) {
  if (station == NULL) return;
  if (station -> platforms == NULL) {
    free(station);
    return;
  }

  int i;
  for (i = 0; i < station -> platforms_no; i++) {
    if (station -> platforms[i]) {
      TrainCar * aux = station -> platforms[i] -> train_cars;
      while (aux != NULL) {
        station -> platforms[i] -> train_cars = station -> platforms[i] -> train_cars -> next;
        free(aux);
        aux = station -> platforms[i] -> train_cars;
      }
      free(station -> platforms[i]);
    }

  }
  free(station -> platforms);
  free(station);
}

/* Afiseaza trenurile stationate in gara.
 *
 * station: gara existenta
 * f: fisierul in care se face afisarea
 */
void show_existing_trains(TrainStation * station, FILE * f) {
  int i = 0;
  if (station == NULL)
    return;
  if (station -> platforms == NULL)
    return;
  for (i = 0; i < station -> platforms_no; i++) {
    fprintf(f, "%d: ", i);
    if (station -> platforms[i] != NULL && station -> platforms[i] -> train_cars != NULL) {
      fprintf(f, "(%d)", station -> platforms[i] -> locomotive_power);
      TrainCar * current = station -> platforms[i] -> train_cars -> next;
      while (current != NULL) {
        fprintf(f, "-|%d|", current -> weight);
        current = current -> next;
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
void arrive_train(TrainStation * station, int platform, int locomotive_power) {
  int i = 0;
  if (locomotive_power < 0) return;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform < station -> platforms_no && platform >= 0) {
        if (station -> platforms[platform] != NULL) {
          if (station -> platforms[platform] -> train_cars == NULL) {
            station -> platforms[platform] -> locomotive_power = locomotive_power;
            station -> platforms[platform] -> train_cars = (TrainCar * ) malloc(sizeof(TrainCar));
            station -> platforms[platform] -> train_cars -> weight = 0;
            station -> platforms[platform] -> train_cars -> next = NULL;
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
void leave_train(TrainStation * station, int platform) {
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform < station -> platforms_no && platform >= 0) {
        if (station -> platforms[platform] != NULL) {
          if (station -> platforms[platform] -> train_cars != NULL) {

            station -> platforms[platform] -> locomotive_power = 0;
            TrainCar * aux = station -> platforms[platform] -> train_cars;
            while (aux != NULL) {
              station -> platforms[platform] -> train_cars = station -> platforms[platform] -> train_cars -> next;
              free(aux);
              aux = station -> platforms[platform] -> train_cars;
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
void add_train_car(TrainStation * station, int platform, int weight) {
  if (weight < 0) {
    return;
  }
  int i = 0;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform < station -> platforms_no && platform >= 0) {
        if (station -> platforms[platform]) {
          if (station -> platforms[platform] -> train_cars) {
            TrainCar * vagon = (TrainCar * ) malloc(sizeof(TrainCar));
            vagon -> weight = weight;
            vagon -> next = NULL;
            TrainCar * last = station -> platforms[platform] -> train_cars;
            while (last -> next != NULL) {
              last = last -> next;
            }
            last -> next = vagon;
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
void remove_train_cars(TrainStation * station, int platform, int weight) {
  if (weight < 0) {
    return;
  }
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform < station -> platforms_no && platform >= 0) {
        if (station -> platforms[platform]) {
          if (station -> platforms[platform] -> train_cars) {
            TrainCar * prev = station -> platforms[platform] -> train_cars, * current = prev -> next;
            while (current != NULL) {
              if (current -> weight == weight) {
                prev -> next = current -> next;
                free(current);
                current = prev -> next;
              } else {
                prev = current;
                current = current -> next;
              }
            }
          }
        }
      }
    }
  }
}

void add_at_pos(TrainCar * start, int weight, int pos) {
  TrainCar * ptr = start, * ptr2 = (TrainCar * ) malloc(sizeof(TrainCar));
  ptr2 -> weight = weight;
  ptr2 -> next = NULL;
  while (pos - 1 && ptr -> next != NULL) {
    ptr = ptr -> next;
    pos--;
  }
  ptr2 -> next = ptr -> next;
  ptr -> next = ptr2;
}

int getCurrSize(TrainCar * train) {
  int size = 0;
  TrainCar * current = train -> next;
  while (current != NULL) {
    current = current -> next;
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
void move_train_cars(TrainStation * station, int platform_a, int pos_a,
  int cars_no, int platform_b, int pos_b) {
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform_a < station -> platforms_no && platform_a >= 0 
      && platform_b < station -> platforms_no && platform_b >= 0) {
        if (pos_a + cars_no <= getCurrSize(station -> platforms[platform_a] -> train_cars) + 1 
        && pos_b <= getCurrSize(station -> platforms[platform_b] -> train_cars) + 1 && pos_b >= 1) {
          for (int i = 0; i < cars_no; i++) {
            int c = 1;
            if (station -> platforms[platform_a] -> train_cars) {
              TrainCar * prev = station -> platforms[platform_a] -> train_cars, * current = prev -> next;
              while (c != pos_a + cars_no - 1 - i) {
                prev = current;
                current = current -> next;
                c++;
              }
              add_at_pos(station -> platforms[platform_b] -> train_cars, current -> weight, pos_b);
              prev -> next = current -> next;
              free(current);
            }
          }
        }
      }
    }
  }
}

int train_speed(Train * train) {
  TrainCar * last = train -> train_cars;
  int sum = 0;
  while (last != NULL) {
    sum += last -> weight;
    last = last -> next;
  }
  return train -> locomotive_power - sum;
}

/* Gaseste trenul cel mai rapid.
 * 
 * station: gara existenta
 *
 * return: peronul pe care se afla trenul
 */
int find_express_train(TrainStation * station) {
  int max = 0, speed = 0, i_max = 0;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      int len = station -> platforms_no;
      for (int i = 0; i < len; i++) {
        speed = train_speed(station -> platforms[i]);
        if (max < speed) {
          max = speed;
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
int find_overload_train(TrainStation * station) {
  int max = 0, speed = 0, i_max = -1;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      int len = station -> platforms_no;
      for (int i = 0; i < len; i++) {
        speed = train_speed(station -> platforms[i]);
        if (speed < 0)
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
int find_optimal_train(TrainStation * station) {
  int min = __INT_MAX__, speed = 0, i_min = 0;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      int len = station -> platforms_no;
      for (int i = 0; i < len; i++) {
        speed = train_speed(station -> platforms[i]);
        if (min > speed && speed > 0) {
          min = speed;
          i_min = i;
        }
      }
    }
  }
  return i_min;
}

// calculeaza greutatea maxima ptu o secventa de vagoane in c 
int weight_train(TrainCar * train, int cars_no, TrainCar ** pointer) {
  TrainCar * prev = train -> next, * current = prev;
  int sum = 0, max = 0;
  for (int j = 0; j < getCurrSize(train) + 1; j++) {
    sum = 0;
    for (int i = 0; i < cars_no; i++) {
      sum = sum + current -> weight;
      current = current -> next;
    }
    if (sum > max) {
      max = sum;
      * pointer = prev;
    }
    if (current == NULL) {
      return max;
    }
    prev = prev -> next;
    current = prev;
  }
}
/* Gaseste trenul cu incarcatura nedistribuita bine.
 * 
 * station: gara existenta
 * cars_no: lungimea secventei de vagoane
 *
 * return: peronul pe care se afla trenul
 */
int find_heaviest_sequence_train(TrainStation * station, int cars_no, TrainCar ** start_car) {
  if (cars_no < 0) {
    * start_car = NULL;
    return -1;
  }
  if (station != NULL) {
    if (station -> platforms != NULL) {
      int max = 0, weight_i = 0, i_max = 0;
      TrainCar * pointer = NULL;
      for (int i = 0; i < station -> platforms_no; i++) {
        if (station -> platforms[i] -> train_cars != NULL) {
          if (cars_no <= getCurrSize(station -> platforms[i] -> train_cars)) {
            weight_i  = weight_train(station -> platforms[i] -> train_cars, cars_no, & pointer);
            if (weight_i > max) {
              max = weight_i;
              i_max = i;
              * start_car = pointer;
            }
          }
        }
      }
      if (max) {
        return i_max;
      }
    }
  }
  * start_car = NULL;
  return -1;
}

void order_train(TrainStation * station, int platform) {
  TrainCar * start = station -> platforms[platform] -> train_cars;
  int count = getCurrSize(station -> platforms[platform] -> train_cars);
  int i, j, ok = 0;
  if (station != NULL) {
    if (station -> platforms != NULL) {
      if (platform < station -> platforms_no && platform >= 0) {
        if (station -> platforms[platform] != NULL) {
          if (start != NULL) {
            for (i = 0; i < count; i++) {
              start = station -> platforms[platform] -> train_cars;
              ok = 0;
              for (j = 0; j < count - i - 1; j++) {
                TrainCar * p1 = start -> next;
                TrainCar * p2 = p1 -> next;
                if (p1 -> weight < p2 -> weight) {
                  TrainCar * temp = p2 -> next;
                  p2 -> next = p1;
                  p1 -> next = temp;
                  start -> next = p2;
                  ok = 1;
                }
                start = start -> next;
              }
              if (ok == 0)
                break;
            }
          }
        }
      }
    }
  }
}


void delete_at_pos(int pos, Train * train) {
  TrainCar * prev = train -> train_cars, * current = prev -> next;
  for (int i = 0; i < pos - 1; i++) {
    prev = current;
    current = current -> next;
  }
  prev -> next = current -> next;
  free(current);
}
/* Scoate un vagon din trenul supraincarcat.
 * 
 * station: gara existenta
 */
void fix_overload_train(TrainStation * station) {
  int platform = find_overload_train(station);
  if (platform == -1) {
    return;
  }
  if (station != NULL && station -> platforms != NULL) {
    if (station -> platforms[platform] != NULL) {
      Train * train = station -> platforms[platform];
      TrainCar * vagon = train -> train_cars;
      int weight_trains = train -> locomotive_power - train_speed(train);
      if (train_speed(train) == 0)
        return;
      int min = weight_trains, i_min = 0, pos = 0;
      TrainCar * last = vagon;
      while (last -> next != NULL) {
        last = last -> next;
        pos++;
        if (min > weight_trains - last -> weight && weight_trains - last -> weight >= train -> locomotive_power) {
          min = weight_trains - last -> weight;
          i_min = pos;
        }
      }
      delete_at_pos(i_min, station -> platforms[platform]);
    }
  }
}