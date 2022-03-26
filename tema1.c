/*
*   Created by Stefania Ghita on 14.03.2022
*   Copyright (c) 2022 Data Structures team. All rights reserved.
*   Tema 1 - Structuri de date
*   Facultatea de Automatica si Calculatoare
*   Anul Universitar 2021-2022, Seria CD
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "station.h"

void test_arrive_train() {
    FILE *f = fopen("output_arrive_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(5);
    show_existing_trains(station, f);
    arrive_train(station, 2, 19);
    show_existing_trains(station, f);
    arrive_train(station, 3, 100);
    show_existing_trains(station, f);
    arrive_train(station, 3, 10);
    show_existing_trains(station, f);
    close_train_station(station);
    station = open_train_station(100);
    for (int i = -2; i < 102; i++) {
        arrive_train(station, i, 1);
    }
    for (int i = 102; i < -1; i--) {
        arrive_train(station, i, 2);
    }
    show_existing_trains(station, f);
    close_train_station(station);
    station = NULL;
    show_existing_trains(station, f);
    fclose(f);
}

void test_leave_train() {
    FILE *f = fopen("output_leave_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(50);
    arrive_train(station, 5, 20);
    arrive_train(station, 4, 10);
    arrive_train(station, 0, 0);
    arrive_train(station, 3, 1);
    show_existing_trains(station, f);
    for (int i = -2; i < 102; i++) {
        leave_train(station, i);
    }
    show_existing_trains(station, f);
    for (int i = 0; i < 100; i++) {
        arrive_train(station, i, 1);
    }
    for (int i = 0; i < 100; i+=2) {
        leave_train(station, i);
    }
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_add_train_car() {
    FILE *f = fopen("output_add_train_car.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(5);
    arrive_train(station, 0, 100);
    arrive_train(station, 2, 200);
    arrive_train(station, 4, 300);
    show_existing_trains(station, f);
    add_train_car(station, -1, 0);
    add_train_car(station, 0, 1);
    add_train_car(station, 1, 2);
    add_train_car(station, 2, 3);
    add_train_car(station, 3, 4);
    add_train_car(station, 4, 5);
    add_train_car(station, 5, 6);
    add_train_car(station, 0, 1);
    add_train_car(station, 1, 2);
    add_train_car(station, 2, 3);
    add_train_car(station, 3, 4);
    add_train_car(station, 4, 5);
    show_existing_trains(station, f);
    for (int i = 0; i < 100; i++) {
        add_train_car(station, 0, 17);
    }
    show_existing_trains(station, f);
    for (int i = 0; i < 100; i++) {
        add_train_car(station, 2, 19);
        add_train_car(station, 4, 23);
    }
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_remove_train_cars() {
    FILE *f = fopen("output_remove_train_cars.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(8);
    arrive_train(station, 1, 100);
    arrive_train(station, 3, 300);
    arrive_train(station, 4, 4000);
    arrive_train(station, 7, 70);
    show_existing_trains(station, f);
    add_train_car(station, 1, 1);
    add_train_car(station, 3, 2);
    add_train_car(station, 3, 2);
    add_train_car(station, 4, 3);
    add_train_car(station, 4, 2);
    add_train_car(station, 4, 3);
    add_train_car(station, 7, 4);
    add_train_car(station, 7, 1);
    add_train_car(station, 7, 4);
    add_train_car(station, 7, 1);
    add_train_car(station, 7, 4);
    show_existing_trains(station, f);
    remove_train_cars(station, 1, 1);
    remove_train_cars(station, 3, 2);
    remove_train_cars(station, 4, 3);
    remove_train_cars(station, 7, 4);
    show_existing_trains(station, f);
    for (int i = -2; i < 10; i++) {
        remove_train_cars(station, i, 1);
        remove_train_cars(station, i, 2);
    }
    show_existing_trains(station, f);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 8; j++) {
            arrive_train(station, j, 100);
            add_train_car(station, j, 7);
            add_train_car(station, j, 7);
            add_train_car(station, j, i);
        }
    }
    show_existing_trains(station, f);
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 8; j++) {
            remove_train_cars(station, j, 7);
        }
    }
    show_existing_trains(station, f);
    for (int i = 50; i > -2; i--) {
        for (int j = 0; j < 5; j++) {
            remove_train_cars(station, j, i);
        }
    }
    show_existing_trains(station, f);
    leave_train(station, 5);
    leave_train(station, 6);
    leave_train(station, 7);
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_move_train_cars() {
    FILE *f = fopen("output_move_train_cars.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(3);
    arrive_train(station, 0, 100);
    arrive_train(station, 1, 100);
    arrive_train(station, 2, 100);
    for (int i = 1; i <= 10; i++) {
        add_train_car(station, 2, i);
        add_train_car(station, 0, i);
    }
    show_existing_trains(station, f);
    move_train_cars(station, 0, 4, 1, 2, 2);
    show_existing_trains(station, f);
    move_train_cars(station, 2, 1, 1, 0, 1);
    show_existing_trains(station, f);
    move_train_cars(station, 2, 1, 1, 1, 1);
    show_existing_trains(station, f);
    move_train_cars(station, 0, 10, 1, 1, 2);
    show_existing_trains(station, f);
    close_train_station(station);
    station = open_train_station(10);
    show_existing_trains(station, f);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, 100);
    }
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 9; j++) {
            add_train_car(station, j, i);
        }
    }
    show_existing_trains(station, f);
    move_train_cars(station, 0, 1, 3, 1, 11);
    show_existing_trains(station, f);
    move_train_cars(station, 1, 11, 3, 2, 1);
    show_existing_trains(station, f);
    move_train_cars(station, 2, 2, 9, 3, 3);
    show_existing_trains(station, f);
    move_train_cars(station, 4, 1, 12, 5, 1);
    move_train_cars(station, 4, 1, 10, 5, 0);
    move_train_cars(station, 4, 1, 3, 5, 12);
    move_train_cars(station, 4, 8, 3, 5, 10);
    move_train_cars(station, 6, 9, 3, 7, 5);
    show_existing_trains(station, f);
    move_train_cars(station, 6, 1, 10, 7, 11);
    show_existing_trains(station, f);
    move_train_cars(station, 7, 1, 10, 6, 11);
    move_train_cars(station, 8, 1, 10, 6, 1);
    move_train_cars(station, 7, 10, 10, 9, 1);
    add_train_car(station, 9, 10);
    show_existing_trains(station, f);
    move_train_cars(station, 3, 3, 0, 2, 2);
    show_existing_trains(station, f);
    for (int i = 0; i < 10; i++) {
        leave_train(station, i);
    }
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_find_express_train() {
    FILE *f = fopen("output_find_express_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(10);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, 100);
    }
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            add_train_car(station, j, i);
        }
    }
    show_existing_trains(station, f);
    for (int i = 0; i < 10; i++) {
        remove_train_cars(station, i, i+1);
        fprintf(f, "%d\n", find_express_train(station));
    }
    leave_train(station, 1);
    leave_train(station, 9);
    fprintf(f, "%d\n", find_express_train(station));
    arrive_train(station, 1, 100);
    fprintf(f, "%d\n", find_express_train(station));
    add_train_car(station, 1, 99);
    fprintf(f, "%d\n", find_express_train(station));
    show_existing_trains(station, f);
    close_train_station(station);
    station = open_train_station(10);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, i*10);
    }
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            add_train_car(station, j, i);
        }
    }
    fprintf(f, "%d\n", find_express_train(station));
    close_train_station(station);
    fclose(f);
}

void test_find_overload_train() {
    FILE *f = fopen("output_find_overload_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(10);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, 100 - i);
    }
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            add_train_car(station, j, i);
        }
    }
    show_existing_trains(station, f);
    fprintf(f, "%d\n", find_overload_train(station));
    for (int i = 9; i >= 0; i--) {
        remove_train_cars(station, i, 10-i);
        fprintf(f, "%d\n", find_overload_train(station));
    }
    show_existing_trains(station, f);
    move_train_cars(station, 9, 1, 9, 0, 1);
    move_train_cars(station, 8, 1, 9, 1, 1);
    fprintf(f, "%d\n", find_overload_train(station));
    move_train_cars(station, 2, 1, 9, 7, 1);
    fprintf(f, "%d\n", find_overload_train(station));
    remove_train_cars(station, 7, 10);
    add_train_car(station, 5, 50);
    fprintf(f, "%d\n", find_overload_train(station));
    leave_train(station, 5);
    add_train_car(station, 1, 1);
    fprintf(f, "%d\n", find_overload_train(station));
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_find_optimal_train() {
    FILE *f = fopen("output_find_optimal_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(10);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, 100-i);
    }
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            add_train_car(station, j, i);
        }
    }
    show_existing_trains(station, f);
    fprintf(f, "%d\n", find_optimal_train(station));
    for (int i = 9; i >= 0; i--) {
        remove_train_cars(station, i, 10);
        fprintf(f, "%d\n", find_optimal_train(station));
    }
    leave_train(station, 1);
    leave_train(station, 9);
    fprintf(f, "%d\n", find_optimal_train(station));
    arrive_train(station, 1, 100);
    fprintf(f, "%d\n", find_optimal_train(station));
    add_train_car(station, 1, 99);
    fprintf(f, "%d\n", find_optimal_train(station));
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_find_heaviest_sequence_train() {
    FILE *f = fopen("output_find_heaviest_sequence_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainCar *car = NULL;
    TrainStation *station = open_train_station(10);
    for (int i = 0; i < 10; i++) {
        arrive_train(station, i, 1000);
    }
    int p = find_heaviest_sequence_train(station, 1, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    for (int i = 1; i <= 10; i++) {
        for(int j = 0; j < 10; j++) {
            add_train_car(station, j, 1);
        }
    }
    add_train_car(station, 3, 2);
    p = find_heaviest_sequence_train(station, 1, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    add_train_car(station, 7, 3);
    p = find_heaviest_sequence_train(station, 1, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    add_train_car(station, 3, 4);
    p = find_heaviest_sequence_train(station, 1, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 20, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 2, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 3, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 12, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    for (int i = 0; i < 10; i++) {
        remove_train_cars(station, i, 1);
    }
    leave_train(station, 4);
    leave_train(station, 5);
    leave_train(station, 6);
    add_train_car(station, 3, 3);
    add_train_car(station, 3, 5);
    add_train_car(station, 3, 2);
    add_train_car(station, 3, 3);
    add_train_car(station, 7, 1);
    add_train_car(station, 7, 6);
    add_train_car(station, 7, 1);
    p = find_heaviest_sequence_train(station, 2, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 3, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    add_train_car(station, 1, 1);
    add_train_car(station, 1, 4);
    add_train_car(station, 1, 4);
    add_train_car(station, 1, 4);
    add_train_car(station, 1, 1);
    remove_train_cars(station, 3, 4);
    p = find_heaviest_sequence_train(station, 3, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    remove_train_cars(station, 1, 4);
    remove_train_cars(station, 3, 5);
    add_train_car(station, 3, 1);
    p = find_heaviest_sequence_train(station, 3, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 4, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    p = find_heaviest_sequence_train(station, 5, &car);
    fprintf(f, "%d %d\n", p, car ? car->weight : -1);
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_order_train() {
    FILE *f = fopen("output_order_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(1);
    arrive_train(station, 0, 789);
    add_train_car(station, 0, 1);
    order_train(station, 0);
    show_existing_trains(station, f);
    add_train_car(station, 0, 5);
    show_existing_trains(station, f);
    order_train(station, 0);
    show_existing_trains(station, f);
    add_train_car(station, 0, 3);
    order_train(station, 0);
    show_existing_trains(station, f);
    add_train_car(station, 0, 2);
    add_train_car(station, 0, 4);
    add_train_car(station, 0, 6);
    add_train_car(station, 0, 4);
    order_train(station, 0);
    show_existing_trains(station, f);
    order_train(station, 0);
    order_train(station, 0);
    show_existing_trains(station, f);
    leave_train(station, 0);
    arrive_train(station, 0, 789);
    for (int i = 0; i < 10; i++) {
        add_train_car(station, 0, 1);
        add_train_car(station, 0, 1);
        add_train_car(station, 0, i+2);
        add_train_car(station, 0, i+3);
    }
    add_train_car(station, 0, 1);
    add_train_car(station, 0, 1);
    show_existing_trains(station, f);
    order_train(station, 0);
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

void test_fix_overload_train() {
    FILE *f = fopen("output_fix_overload_train.out", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    TrainStation *station = open_train_station(4);
    for (int i = 0; i < 4; i++) {
        arrive_train(station, i, 10);
    }
    fix_overload_train(station);
    show_existing_trains(station, f);
    for (int i = 1; i < 5; i++) {
        add_train_car(station, 0, i);
        add_train_car(station, 1, i);
        add_train_car(station, 2, i);
    }
    fix_overload_train(station);
    show_existing_trains(station, f);
    add_train_car(station, 1, 0);
    add_train_car(station, 1, 5);
    fix_overload_train(station);
    show_existing_trains(station, f);
    remove_train_cars(station, 1, 4);
    add_train_car(station, 1, 5);
    show_existing_trains(station, f);
    fix_overload_train(station);
    show_existing_trains(station, f);
    remove_train_cars(station, 1, 5);
    add_train_car(station, 1, 6);
    fix_overload_train(station);
    show_existing_trains(station, f);
    add_train_car(station, 1, 4);
    add_train_car(station, 1, 4);
    remove_train_cars(station, 1, 6);
    remove_train_cars(station, 1, 0);
    fix_overload_train(station);
    show_existing_trains(station, f);
    move_train_cars(station, 0, 1, 2, 1, 3);
    move_train_cars(station, 1, 2, 1, 2, 2);
    show_existing_trains(station, f);
    leave_train(station, 2);
    add_train_car(station, 1, 5);
    fix_overload_train(station);
    show_existing_trains(station, f);
    close_train_station(station);
    fclose(f);
}

int main() {
    test_arrive_train();
    test_leave_train();
    test_add_train_car();
    test_remove_train_cars();
    test_move_train_cars();
    test_find_express_train();
    test_find_overload_train();
    test_find_optimal_train();
    test_find_heaviest_sequence_train();
    test_order_train();
    test_fix_overload_train();
    return 0;
}
