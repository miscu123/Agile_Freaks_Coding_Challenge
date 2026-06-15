// header to implement car class with their info
#ifndef CODING_CHALLENGE_CAR_H
#define CODING_CHALLENGE_CAR_H
#include <cmath>
#include <cstring>
#include <vector>
#include <climits>

struct location {
    int X;
    int Y;
};

class Car {
    int ID;
    static int ID_next;

    public:
    // car information
    char manufacturer[100]{};
    char model[100]{};
    int curr_speed;
    location curr_location;
    unsigned int encountered_events;

    Car();
    Car(const char manufacturer[100],const char model[100],int curr_speed,location curr_location,unsigned int encountered_events);
    ~Car();

    int getID();
    void setID(int ID);
    void receive_info(Car other_car);
    void send_info(Car& other_car);
    void set_speed(int s);
    location calc_distance(Car other_car);
    int closest_car(std::vector<Car> cars);
};

// cannot init in class
inline int Car::ID_next = 1;

// default constructor
inline Car::Car() {
    this->manufacturer[0] = '\0';
    this->model[0] = '\0';
    this->curr_speed = 0;
    this->curr_location.X = 0;
    this->curr_location.Y = 0;
    this->encountered_events = 0;
    this->ID = ID_next;
    ID_next++;
}

// copy constr
inline Car::Car(const char manufacturer[100],const char model[100],int curr_speed, location curr_location,unsigned int encountered_events) {
    strncpy(this->manufacturer, manufacturer, 100);
    strncpy(this->model, model, 100);
    this->ID = ID_next;
    ID_next++;
    this->curr_speed = curr_speed;
    this->curr_location = curr_location;
    this->encountered_events = encountered_events;
}

inline Car::~Car() {}

// id getter
inline int Car::getID() {
    return this->ID;
}

// id setter
inline void Car::setID(const int ID) {
    this->ID = ID;
}

// if we try and set/get other information (ex: speed, location, model...)
// the current car would just become the other car, so we can just send / receive encountered events
inline void Car::receive_info(Car other_car) {
    this->encountered_events += other_car.encountered_events;
}

inline void Car::send_info(Car& other_car) {
    other_car.encountered_events += this->encountered_events;
}

inline void Car::set_speed(const int s) {
    this->curr_speed = s;
}

inline location Car::calc_distance(Car other_car) {
    // we use absolute function bc we do not know if our cars coord ar greater than the other cars coords
    int new_X = abs(this->curr_location.X - other_car.curr_location.X);
    int new_Y = abs(this->curr_location.Y - other_car.curr_location.Y);

    return {new_X, new_Y};
}

inline int Car::closest_car(std::vector<Car> cars) {
    int closest = -1;
    int min = INT_MAX;

    for (Car car : cars) {
        if (car.getID() == this->getID()) //skip my car
            continue;

        location dis = calc_distance(car);
        double dist = dis.X + dis.Y;

        if (dist < min) {
            min = dist;
            closest = car.getID();
        }
    }

    return closest;
}

#endif
