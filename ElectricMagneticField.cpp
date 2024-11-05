#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;

public:
    // Default constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    // Parameterized constructor
    Electric_Field(double x, double y, double z) {
        E = new double[3]{x, y, z};
    }

    // Destructor
    ~Electric_Field() {
        delete[] E;
    }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    // Calculate inner product
    double calculateInnerProduct() const {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }

    void printInnerProduct() const {
        std::cout << "Inner Product of Electric Field: " << calculateInnerProduct() << std::endl;
    }
};

class Magnetic_Field {
private:
    double *B;

public:
    // Default constructor
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }

    // Parameterized constructor
    Magnetic_Field(double x, double y, double z) {
        B = new double[3]{x, y, z};
    }

    // Destructor
    ~Magnetic_Field() {
        delete[] B;
    }

    // Getters
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    // Setters
    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    // Calculate magnitude
    double calculateMagnitude() const {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    // Calculate unit vector
    void calculateUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude == 0) {
            std::cout << "Magnetic field is zero, unit vector is undefined." << std::endl;
            return;
        }
        std::cout << "Magnetic Field Unit Vector: ("
                  << B[0] / magnitude << ", "
                  << B[1] / magnitude << ", "
                  << B[2] / magnitude << ")" << std::endl;
    }
};

int main() {
    // Create electric field objects
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    // Display magnitudes and inner product
    std::cout << "Magnitude of default Electric Field: " << E_default.calculateMagnitude() << std::endl;
    std::cout << "Magnitude of specific Electric Field: " << E_components.calculateMagnitude() << std::endl;
    E_components.printInnerProduct();

    // Create magnetic field objects
    Magnetic_Field B_default;
    Magnetic_Field B_components(1e3, 5.0, 2.2e1);

    // Display magnitudes and unit vector
    std::cout << "Magnitude of default Magnetic Field: " << B_default.calculateMagnitude() << std::endl;
    std::cout << "Magnitude of specific Magnetic Field: " << B_components.calculateMagnitude() << std::endl;
    B_components.calculateUnitVector();

    return 0;
}
