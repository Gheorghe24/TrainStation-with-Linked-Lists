# Application of Linked List in C

Open_train_station
-------------------
In this function I first allocated memory for the station, then for the platform vector and for each platform separately. I also initialized with 0 the power of the locomotive to help me in the future

Close_train_station
------------------------
I first took the special cases in which there would be no station or platforms (here I 
evacuated the station). Then for each platform I went through the train cars to the 
end with an auxiliary "traincar" and I dislocated them as well if they exist together 
with the platform and the platform vector.

Show_existing_trains
--------------------
As above and in most of the functions in the theme, we started with the cases in which 
something would not exist (station, platforms, train).

Then I followed the rules of writing in the file (platform number, locomotive power and weight of each car).

Arrive_train
-------------
Here I allocated memory for the locomotive and gave it the power given as a parameter.

Leave train
-----------------
I went through the train cars until the end with an auxiliary pointer and I dislocated 
memory for each car separately (if any).

Add_train_car
-------------
If there is a locomotive to which I should attach the wagon, I assign a wagon and give 
it the necessary weight, then I go through the wagons until the end and on the last 
position I connect them 2.

Remove_train_cars
-----------------------
I use 2 auxiliary pointers to go through the wagons until the end and when I find the 
necessary weight for a certain wagon, I delete it but keep the connection between the 
nodes.

Move_train_cars
----------------
To solve this function we implemented 2 more auxiliary functions 

- getCurrSize-number of wagons
- add_at_pos - adding a node to a certain position)

For a start, I check all the special cases in which I could not use the given 
function. Then I go through the first platform to the position pos_a + cars_no to 
insert in turn "from the end" a wagon in position pos_b in platform B using the 
add_at_pos function.

After inserting, I free the moved wagon from the first platform.

Find_express_train
-------------------
For this function I implement another one that calculates the weight of all the wagons 
of a train and returns the difference between the locomotive power and this weight 
(train_speed).

So I use the function for each platform and see what the maximum difference is.

Find_overload_train
----------------------
As in the function below, I use the auxiliary function and find out which of the 
trains has the minimum difference to return as a result the platform on which it is 
located.

Find_optimal_train
--------------------
It looks a lot like "Find_express_train" only I find the minimum and return the 
platform it is on.

Find_heaviest_sequence_train
----------------------------------
For each train I calculate the maximum weight for a given sequence with the help of a 
function (weight_train) and at the same time I save in a pointer the first wagon in 
that sequence. 

Further on, I find the maximum weight and save the pointer through start_car and 
return the platform with the maximum sequence.

Order_train
-------------------
I use the "Bubble sort" algorithm and change the wagons (nodes) between them when I 
find a case where the list is not in descending order.

For this I also needed the number of wagons in the list (function created above). \
In the second repetitive structure I initialize 2 auxiliary pointers with which I will 
go through the list and the third one in case I need to swap between them.

I stop when I go through the list "in vain" (the list is sorted). I find this out 
because I have a "boolean" variable in which I save this case (ordering).

Fix_overload_train
-------------------
I find the platform that is overloaded.
I initialize 2 pointers (train and wagon). With the help of the above functions I find 
the weight of the wagons of a train.

For this I find the minimum difference between the weight of the wagons and the weight 
of each wagon traveled. 
I save the position of the wagon and with the help of a function that deletes the node 
from a certain position in the train I delete the wagon.
