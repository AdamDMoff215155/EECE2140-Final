#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// -----------------------------
// ENUMS
// -----------------------------
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

enum class LightState {
    RED,
    YELLOW,
    GREEN
};

// -----------------------------
// HELPER FUNCTIONS
// -----------------------------
string directionToString(Direction dir) {
    switch (dir) {
        case Direction::NORTH: return "North";
        case Direction::SOUTH: return "South";
        case Direction::EAST:  return "East";
        case Direction::WEST:  return "West";
        default: return "Unknown";
    }
}

string lightStateToString(LightState state) {
    switch (state) {
        case LightState::RED:    return "RED";
        case LightState::YELLOW: return "YELLOW";
        case LightState::GREEN:  return "GREEN";
        default: return "UNKNOWN";
    }
}

bool isNorthSouth(Direction dir) {
    return dir == Direction::NORTH || dir == Direction::SOUTH;
}

bool isEastWest(Direction dir) {
    return dir == Direction::EAST || dir == Direction::WEST;
}

// -----------------------------
// VEHICLE CLASS
// -----------------------------
class Vehicle {
private:
    int id;
    Direction direction;
    double position;     // distance from intersection stop line
    double speed;
    bool emergency;

public:
    Vehicle(int id, Direction direction, double speed, bool emergency = false)
        : id(id), direction(direction), position(100.0), speed(speed), emergency(emergency) {}

    int getId() const {
        return id;
    }

    Direction getDirection() const {
        return direction;
    }

    double getPosition() const {
        return position;
    }

    double getSpeed() const {
        return speed;
    }

    bool isEmergency() const {
        return emergency;
    }

    void move() {
        position -= speed;
        if (position < 0) {
            position = 0;
        }
    }

    void wait() {
        // vehicle stays in current position
    }

    bool hasReachedIntersection() const {
        return position <= 0;
    }
};

// -----------------------------
// TRAFFIC LIGHT CLASS
// -----------------------------
class TrafficLight {
private:
    LightState state;

public:
    TrafficLight() : state(LightState::RED) {}

    void setState(LightState newState) {
        state = newState;
    }

    LightState getState() const {
        return state;
    }
};

// -----------------------------
// LANE CLASS
// -----------------------------
class Lane {
private:
    Direction direction;
    deque<Vehicle> vehicles;

public:
    Lane(Direction direction) : direction(direction) {}

    Direction getDirection() const {
        return direction;
    }

    void addVehicle(const Vehicle& vehicle) {
        vehicles.push_back(vehicle);
    }

    bool empty() const {
        return vehicles.empty();
    }

    int size() const {
        return static_cast<int>(vehicles.size());
    }

    bool hasEmergencyVehicle() const {
        for (const auto& v : vehicles) {
            if (v.isEmergency()) {
                return true;
            }
        }
        return false;
    }

    bool emergencyAtFront() const {
        if (vehicles.empty()) return false;
        return vehicles.front().isEmergency();
    }

    const deque<Vehicle>& getVehicles() const {
        return vehicles;
    }

    void updateVehicles(bool greenLight) {
        if (vehicles.empty()) return;

        // Simple movement model:
        // - front vehicle moves if light is green
        // - vehicles behind move only if enough space exists
        // - if light is red/yellow, front vehicle stops near intersection

        // Update front vehicle
        if (greenLight) {
            vehicles.front().move();
        } else {
            // front vehicle may still approach until stop line, but here we simplify:
            // if close to intersection, it waits; otherwise it can approach a bit
            if (vehicles.front().getPosition() > 10) {
                vehicles.front().move();
            } else {
                vehicles.front().wait();
            }
        }

        // Update following vehicles
        for (size_t i = 1; i < vehicles.size(); ++i) {
            double frontPos = vehicles[i - 1].getPosition();
            double currentPos = vehicles[i].getPosition();

            // Maintain approximate 10-unit gap
            if (currentPos - frontPos > 10) {
                vehicles[i].move();
            } else {
                vehicles[i].wait();
            }
        }

        // Remove vehicles that passed intersection
        while (!vehicles.empty() && vehicles.front().hasReachedIntersection()) {
            cout << "   -> Vehicle " << vehicles.front().getId()
                 << " from " << directionToString(vehicles.front().getDirection())
                 << " passed the intersection";
            if (vehicles.front().isEmergency()) {
                cout << " [EMERGENCY]";
            }
            cout << endl;
            vehicles.pop_front();
        }
    }
};

// -----------------------------
// INTERSECTION CONTROLLER CLASS
// -----------------------------
class IntersectionController {
private:
    TrafficLight northSouthLight;
    TrafficLight eastWestLight;

    int cycleTimer;
    int greenDuration;
    int yellowDuration;

    bool emergencyMode;
    Direction emergencyDirection;

public:
    IntersectionController(int greenDuration = 8, int yellowDuration = 2)
        : cycleTimer(0),
          greenDuration(greenDuration),
          yellowDuration(yellowDuration),
          emergencyMode(false),
          emergencyDirection(Direction::NORTH) {
        // Start with North-South green
        northSouthLight.setState(LightState::GREEN);
        eastWestLight.setState(LightState::RED);
    }

    void activateEmergencyMode(Direction dir) {
        emergencyMode = true;
        emergencyDirection = dir;

        if (isNorthSouth(dir)) {
            northSouthLight.setState(LightState::GREEN);
            eastWestLight.setState(LightState::RED);
        } else {
            eastWestLight.setState(LightState::GREEN);
            northSouthLight.setState(LightState::RED);
        }
    }

    void deactivateEmergencyMode() {
        emergencyMode = false;
        cycleTimer = 0;
        // Reset to a safe default cycle
        northSouthLight.setState(LightState::GREEN);
        eastWestLight.setState(LightState::RED);
    }

    bool isEmergencyMode() const {
        return emergencyMode;
    }

    Direction getEmergencyDirection() const {
        return emergencyDirection;
    }

    LightState getNorthSouthState() const {
        return northSouthLight.getState();
    }

    LightState getEastWestState() const {
        return eastWestLight.getState();
    }

    bool canLaneMove(Direction dir) const {
        if (isNorthSouth(dir)) {
            return northSouthLight.getState() == LightState::GREEN;
        } else {
            return eastWestLight.getState() == LightState::GREEN;
        }
    }

    void updateNormalCycle() {
        cycleTimer++;

        // Full cycle:
        // NS GREEN for greenDuration
        // NS YELLOW for yellowDuration
        // EW GREEN for greenDuration
        // EW YELLOW for yellowDuration

        int totalCycle = 2 * greenDuration + 2 * yellowDuration;

        int t = cycleTimer % totalCycle;

        if (t < greenDuration) {
            northSouthLight.setState(LightState::GREEN);
            eastWestLight.setState(LightState::RED);
        } else if (t < greenDuration + yellowDuration) {
            northSouthLight.setState(LightState::YELLOW);
            eastWestLight.setState(LightState::RED);
        } else if (t < 2 * greenDuration + yellowDuration) {
            northSouthLight.setState(LightState::RED);
            eastWestLight.setState(LightState::GREEN);
        } else {
            northSouthLight.setState(LightState::RED);
            eastWestLight.setState(LightState::YELLOW);
        }
    }
};

// -----------------------------
// SIMULATION ENGINE CLASS
// -----------------------------
class SimulationEngine {
private:
    vector<Lane> lanes;
    IntersectionController controller;
    int nextVehicleId;
    int currentStep;

public:
    SimulationEngine()
        : controller(8, 2), nextVehicleId(1), currentStep(0) {
        lanes.emplace_back(Direction::NORTH);
        lanes.emplace_back(Direction::SOUTH);
        lanes.emplace_back(Direction::EAST);
        lanes.emplace_back(Direction::WEST);
    }

    void generateVehicles() {
        // Random generation
        // About 40% chance per lane each step
        for (auto& lane : lanes) {
            int chance = rand() % 100;
            if (chance < 40) {
                bool emergency = (rand() % 100 < 8); // 8% emergency chance
                double speed = emergency ? 20.0 : 10.0 + (rand() % 6);

                Vehicle v(nextVehicleId++, lane.getDirection(), speed, emergency);
                lane.addVehicle(v);

                cout << "   + New ";
                if (emergency) cout << "EMERGENCY ";
                cout << "vehicle added to "
                     << directionToString(lane.getDirection())
                     << " lane (ID: " << v.getId() << ", Speed: " << v.getSpeed() << ")\n";
            }
        }
    }

    bool detectEmergency(Direction& emergencyDir) {
        for (const auto& lane : lanes) {
            if (lane.hasEmergencyVehicle()) {
                emergencyDir = lane.getDirection();
                return true;
            }
        }
        return false;
    }

    bool emergencyStillExists(Direction dir) const {
        for (const auto& lane : lanes) {
            if (lane.getDirection() == dir && lane.hasEmergencyVehicle()) {
                return true;
            }
        }
        return false;
    }

    void updateController() {
        Direction emergencyDir;
        bool foundEmergency = detectEmergency(emergencyDir);

        if (foundEmergency) {
            if (!controller.isEmergencyMode()) {
                cout << "   ! Emergency vehicle detected in "
                     << directionToString(emergencyDir)
                     << " lane. Activating priority mode.\n";
                controller.activateEmergencyMode(emergencyDir);
            } else {
                // already in emergency mode, keep it
            }
        } else {
            if (controller.isEmergencyMode()) {
                cout << "   ! Emergency cleared. Returning to normal traffic cycle.\n";
                controller.deactivateEmergencyMode();
            } else {
                controller.updateNormalCycle();
            }
        }
    }

    void updateLanes() {
        for (auto& lane : lanes) {
            bool canMove = controller.canLaneMove(lane.getDirection());
            lane.updateVehicles(canMove);
        }
    }

    void printSystemState() const {
        cout << "\n==================================================\n";
        cout << "Time Step: " << currentStep << "\n";
        cout << "==================================================\n";

        cout << "Traffic Lights:\n";
        cout << "   North-South: " << lightStateToString(controller.getNorthSouthState()) << "\n";
        cout << "   East-West  : " << lightStateToString(controller.getEastWestState()) << "\n";

        if (controller.isEmergencyMode()) {
            cout << "Emergency Mode: ON (" 
                 << directionToString(controller.getEmergencyDirection())
                 << " direction has priority)\n";
        } else {
            cout << "Emergency Mode: OFF\n";
        }

        cout << "\nLane Status:\n";
        for (const auto& lane : lanes) {
            cout << "   " << setw(5) << directionToString(lane.getDirection())
                 << " Lane -> " << lane.size() << " vehicle(s)\n";

            const auto& vehicles = lane.getVehicles();
            if (vehicles.empty()) {
                cout << "      [empty]\n";
            } else {
                for (const auto& v : vehicles) {
                    cout << "      Vehicle " << setw(2) << v.getId()
                         << " | Pos: " << setw(6) << fixed << setprecision(1) << v.getPosition()
                         << " | Speed: " << setw(4) << v.getSpeed();

                    if (v.isEmergency()) {
                        cout << " | EMERGENCY";
                    }
                    cout << "\n";
                }
            }
        }
        cout << endl;
    }

    void run(int totalSteps) {
        for (currentStep = 1; currentStep <= totalSteps; ++currentStep) {
            printSystemState();
            generateVehicles();
            updateController();
            updateLanes();
        }

        cout << "\nSimulation finished.\n";
    }
};

// -----------------------------
// MAIN
// -----------------------------
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=========================================\n";
    cout << " Traffic Intersection Simulation in C++\n";
    cout << "=========================================\n\n";

    int steps;
    cout << "Enter number of simulation steps: ";
    cin >> steps;

    if (steps <= 0) {
        cout << "Invalid number of steps.\n";
        return 1;
    }

    SimulationEngine simulation;
    simulation.run(steps);

    return 0;
}