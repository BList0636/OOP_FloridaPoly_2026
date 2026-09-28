// .hpp header file. Keeps the description of the class. No implementation.
#include <string>

class Car {
public:
    // No arg constructor
    Car() {
        make = "-";
        model = "-";
        year = 1900;
        mpg = 0.0;
    }

    // printInfo method
    void printInfo() const;

    // Getters
    std::string getMake() const;
    std::string getModel() const;
    int         getYear() const;
    double      getMPG() const;

    // Setters
    void        setMake(const std::string& mk);
    void        setModel(const std::string& md);
    void        setYear(int y);
    void        setMPG(double new_mpg);

private:
    std::string make;
    std::string model;
    int year;
    double mpg;
};
