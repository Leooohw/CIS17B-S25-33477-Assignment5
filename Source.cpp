#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for string
template<>
class Package<string> {
private:
    string item;
public:
    Package(string i) : item(i) {}
    void label() {
        cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

//Specialization for holding a number of fixed items.
template<typename T, int Size>
class Box {
private:
    array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            cout << " - " << items[i] << "\n";
        }
    }
};

//Ships items based on the type such as int, char, string, etc.
template<typename T>
void shipItem(const T& item) {
    cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

int main()
{
   // Sets int package and string package / names
    
    Package<int> intPackage(22);
    intPackage.label();
    
    Package<string> pack("Ice Cream");
    pack.label();


    //pointer for fragilePackage
    double temp = 22.5;
    Package<double*> fragilePackage(&temp);
    fragilePackage.label();

    // adds item
    Box<string, 2> box;
    
    box.addItem("StrawBerry Vanilla");

    box.addItem("Cookies n Cream");

    box.printItems();

   
    // call shipItem
    shipItem(10);
   
    shipItem(string("Program"));
    
    shipItem(22.5); // double

    
    return 0;
}