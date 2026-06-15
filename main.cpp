/*
* Autonomous Cars Communication
Imagine a world where cars are autonomous and they need to talk with each other and share information about:

Car information (manufacturer, model, unique ID)
Current Speed
Current Location (in coordinates X and Y)
Encountered events in the last 100km
You will need to implement a class (or multiple if you see it fit) that will do at least the following tasks:

Receive information from other cars
Send information to another car
Set the current speed
Calculate distance to another car
Pick the closest car
 */
#include <iostream>
#include "car.h"

int main() {
 location loc = {0, 0};

 Car car_one("Toyota", "AE86", 80, loc, 2);
 Car car_two("BMW", "X5", 100, location{10, 5}, 5);
 Car car_tr("Audi", "A3", 20, location{3, 4}, 10);

 // get id from a car
 std::cout << "Car 1 id: " << car_one.getID() << "\n";
 std::cout << "Car 2 id: " << car_two.getID() << "\n";

 // set custom speed to a car
 car_one.set_speed(90);
 std::cout << "Car 1 new speed: " << car_one.curr_speed << "\n";

 // calculate distance between 2 cars
 location d = car_one.calc_distance(car_tr);
 std::cout << "Distance car 1 - car 3: X=" << d.X << " Y=" << d.Y << "\n";

 // closest car
 std::vector cars = {car_one, car_two, car_tr};
 int closest_id = car_one.closest_car(cars);
 std::cout << "Closest car to car 1 has ID: " << closest_id << "\n";

 // receive events
 std::cout << "Car 1 events before: " << car_one.encountered_events << "\n";
 car_one.receive_info(car_two);
 std::cout << "Car 1 events after receiving info: " << car_one.encountered_events << "\n";

 // send events
 std::cout << "Car 3 events before: " << car_tr.encountered_events << "\n";
 car_one.send_info(car_tr);
 std::cout << "Car 3 events after Car 1 sent info: " << car_tr.encountered_events << "\n";

 return 0;
}