#include <iostream>
#include <vector>
#include "car.h"

int main() {
    // unique IDs
    Car a("Dacia", "Logan", 0, {0, 0}, 0);
    Car b("Renault", "Clio", 0, {0, 0}, 0);
    Car c("Ford", "Focus", 0, {0, 0}, 0);
    std::cout << "IDs: " << a.getID() << " " << b.getID() << " " << c.getID() << "\n";

    std::vector<Car> only_self = {a};
    std::cout << "closest with only self: " << a.closest_car(only_self) << "\n";
    std::vector<Car> empty_vec;
    std::cout << "closest empty vector: " << a.closest_car(empty_vec) << "\n";

    // send/receive with encountered_events at 0
    Car zero1("Skoda", "Octavia", 0, {0, 0}, 0);
    Car zero2("Seat", "Leon", 0, {1, 1}, 0);
    zero1.send_info(zero2);
    std::cout << "events after send with 0: " << zero1.encountered_events << " " << zero2.encountered_events << "\n";

    // two cars at the same location, distance should be 0
    Car same1("Honda", "Civic", 0, {2, 2}, 0);
    Car same2("Mazda", "3", 0, {2, 2}, 0);
    location d = same1.calc_distance(same2);
    std::cout << "distance same location: X=" << d.X << " Y=" << d.Y << "\n";

    std::vector<Car> same_loc_group = {same1, same2};
    std::cout << "closest same location: " << same1.closest_car(same_loc_group) << " (same2=" << same2.getID() << ")\n";

    return 0;
}