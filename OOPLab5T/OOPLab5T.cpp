// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

// Ваші файли загловки 
//
#include "Lab5Exmaple.h"
int main()
{
    std::cout << " Lab #5  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту

    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();

}
//Laba 5 
//TASK 1
#include <iostream>
#include <string>

class Car {
protected:
    std::string brand;
    int cylinders;
    int power;

public:
    Car() {
        brand = "";
        cylinders = 0;
        power = 0;
        std::cout << "Car object created with default values" << std::endl;
    }

    Car(std::string b, int c, int p) {
        brand = b;
        cylinders = c;
        power = p;
        std::cout << "Car object created with custom values" << std::endl;
    }

    ~Car() {
        std::cout << "Car object destroyed" << std::endl;
    }

    void print() {
        std::cout << "Brand: " << brand << ", Cylinders: " << cylinders << ", Power: " << power << std::endl;
    }

    void setBrand(std::string b) {
        brand = b;
    }
};

class Truck : public Car {
private:
    int payload_capacity;

public:
    Truck() {
        payload_capacity = 0;
        std::cout << "Truck object created with default values" << std::endl;
    }

    Truck(std::string b, int c, int p, int pc) : Car(b, c, p) {
        payload_capacity = pc;
        std::cout << "Truck object created with custom values" << std::endl;
    }

    ~Truck() {
        std::cout << "Truck object destroyed" << std::endl;
    }

    void print() {
        std::cout << "Brand: " << brand << ", Cylinders: " << cylinders << ", Power: " << power << ", Payload Capacity: " << payload_capacity << std::endl;
    }

    void setPayloadCapacity(int pc) {
        payload_capacity = pc;
    }
};

int main() {
  
    Car car1;
    car1.print();

    Car car2("BMW", 6, 200);
    car2.print();


    Truck truck1;
    truck1.print();

    Truck truck2("MAN", 8, 300, 10000);
    truck2.print();


    truck2.setBrand("Mercedes");
    truck2.setPayloadCapacity(12000);
    truck2.print();

    return 0;
}


//TASK 2 

#include <iostream>
#include <string>

class Engine {
private:
    int power;
public:
    Engine(int p) : power(p) {}
    int getPower() const { return power; }
};

class Car {
private:
    Engine* engine;
    std::string brand;
    double price;
public:
    Car(Engine* e, const std::string& b, double p) : engine(e), brand(b), price(p) {}
    virtual ~Car() { delete engine; }
    const std::string& getBrand() const { return brand; }
    double getPrice() const { return price; }
    int getEnginePower() const { return engine->getPower(); }
};

class Truck : public Car {
private:
    double payload;
public:
    Truck(Engine* e, const std::string& b, double p, double pl) : Car(e, b, p), payload(pl) {}
    void print() const {
        std::cout << "Brand: " << getBrand() << ", Price: " << getPrice()
            << ", Engine power: " << getEnginePower() << ", Payload: " << payload << std::endl;
    }
};

int main() {
    Engine* e = new Engine(200);
    Truck* t = new Truck(e, "Volvo", 50000, 1000);
    t->print();
    delete t;
    return 0;
}

//TASK 3 
#include <iostream>
#include <string>

using namespace std;

class Furniture {
protected:
    string material;
    int weight;
public:
    Furniture() : material(""), weight(0) {}
    Furniture(const string& material, int weight) : material(material), weight(weight) {}
    Furniture(const Furniture& other) : material(other.material), weight(other.weight) {}

    virtual void print() const {
        cout << "Material: " << material << ", Weight: " << weight << "kg";
    }

    friend istream& operator>>(istream& is, Furniture& f);
    friend ostream& operator<<(ostream& os, const Furniture& f);
    Furniture& operator=(const Furniture& other) {
        if (this != &other) {
            material = other.material;
            weight = other.weight;
        }
        return *this;
    }
};

istream& operator>>(istream& is, Furniture& f) {
    is >> f.material >> f.weight;
    return is;
}

ostream& operator<<(ostream& os, const Furniture& f) {
    f.print();
    return os;
}

class Table : public Furniture {
protected:
    int height;
    int width;
public:
    Table() : Furniture(), height(0), width(0) {}
    Table(const string& material, int weight, int height, int width) :
        Furniture(material, weight), height(height), width(width) {}
    Table(const Table& other) : Furniture(other), height(other.height), width(other.width) {}

    void print() const override {
        Furniture::print();
        cout << ", Height: " << height << "cm, Width: " << width << "cm";
    }

    friend istream& operator>>(istream& is, Table& t);
    friend ostream& operator<<(ostream& os, const Table& t);
    Table& operator=(const Table& other) {
        if (this != &other) {
            Furniture::operator=(other);
            height = other.height;
            width = other.width;
        }
        return *this;
    }
};

istream& operator>>(istream& is, Table& t) {
    is >> static_cast<Furniture&>(t) >> t.height >> t.width;
    return is;
}

ostream& operator<<(ostream& os, const Table& t) {
    t.print();
    return os;
}

int main() {
    Table t1("wood", 20, 80, 120);
    cout << t1 << endl;

    Table t2;
    cin >> t2;
    cout << t2 << endl;

    Table t3 = t2;
    cout << t3 << endl;

    Table t4;
    t4 = t1;
    cout << t4 << endl;

    return 0;
}
