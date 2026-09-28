// .hpp header file. Keeps the description of the class. No implementation.
#include <string>

class Car {
public:
    // No arg constructor
    Car();
    Car(std::string _make, std::string _model, int _year, double _mpg);

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
