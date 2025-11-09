#include <iostream>
#include <string>
#include<vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct Car{
    string name;
    int year;
    double v;
    double price;
    bool operator==(const Car& other) const {
        return (name == other.name && year == other.year && v == other.v && price == other.price);
    }
};

class Cars{
private:
    vector<Car> cars;
public:
    void addCar(){
        string name;
        int year;
        double v;
        double price;
        
        cout << "Введіть марку та модель авто: ";
        getline(cin, name);
        
        cout << "Введіть рік випуску авто: ";
        cin >> year;
        cin.ignore();
        
        cout << "Введіть обʼєм двигуна авто: ";
        cin >> v;
        cin.ignore();
        
        cout << "Введіть ціну авто: ";
        cin >> price;
        cin.ignore();
        
        
        Car newCar;
        newCar.name = name;
        newCar.year = year;
        newCar.price = price;
        newCar.v = v;
        
        cars.push_back(newCar);
    }
    
    void deleteCar(){
        string name;
        int year;
        double v;
        double price;
        
        cout << "Введіть марку та модель авто: ";
        getline(cin, name);
        
        cout << "Введіть рік випуску авто: ";
        cin >> year;
        cin.ignore();
        
        cout << "Введіть обʼєм двигуна авто: ";
        cin >> v;
        cin.ignore();
        
        cout << "Введіть ціну авто: ";
        cin >> price;
        cin.ignore();
        
        
        Car newCar;
        newCar.name = name;
        newCar.year = year;
        newCar.price = price;
        newCar.v = v;
        
        auto it = find(cars.begin(), cars.end(), newCar);
        
        if(it != cars.end()){
            cars.erase(it);
        }else{
            cout << "Авто не знайдено" << endl;
        }
    }
    
    void print(){
        for (Car c:cars){
            cout << "Модель: " << c.name << ", ціна: " << c.price << ", обʼєм двигуна" << c.v << ", рік випуску: " << c.year << endl;
        }
    }
    
    void search(){
        int choise;
        cout << "За чим ви хочите знайти авто: модель(1), рік(2), обʼєм двигуна(3), ціна(4)";
        cin >> choise;
        cin.ignore();
        
        if (choise == 1){
            string tmp;
            cout << "Введіть ознаку для пошуку: ";
            getline(cin, tmp);
            for (Car c : cars){
                if(tmp == c.name) cout << "Модель: " << c.name
                    << ", ціна: " << c.price
                    << ", обʼєм двигуна" << c.v
                    << ", рік випуску: " << c.year << endl;
            }
        }else if (choise == 2){
            int tmp;
            cout << "Введіть ознаку для пошуку: ";
            cin >> tmp;
            cin.ignore();
            for (Car c : cars){
                if(tmp == c.year) cout << "Модель: " << c.name
                    << ", ціна: " << c.price
                    << ", обʼєм двигуна" << c.v
                    << ", рік випуску: " << c.year << endl;
            }
        }else if (choise == 3){
            double tmp;
            cout << "Введіть ознаку для пошуку: ";
            cin >> tmp;
            cin.ignore();
            for (Car c : cars){
                if(tmp == c.v) cout << "Модель: " << c.name
                    << ", ціна: " << c.price
                    << ", обʼєм двигуна" << c.v
                    << ", рік випуску: " << c.year << endl;
            }
        }else if (choise == 4){
            int tmp;
            cout << "Введіть ознаку для пошуку: ";
            cin >> tmp;
            cin.ignore();
            for (Car c : cars){
                if(tmp == c.price) cout << "Модель: " << c.name
                    << ", ціна: " << c.price
                    << ", обʼєм двигуна" << c.v
                    << ", рік випуску: " << c.year << endl;
            }
        }
    }
    void sort(){
        int choise;
        cout << "За чим ви хочите знайти авто: модель(1), рік(2), обʼєм двигуна(3), ціна(4)";
        cin >> choise;
        cin.ignore();
        
        if (choise == 1){
            std::sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b){
                return a.name<b.name;
                }
            );
        }else if (choise == 2){
            std::sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b){
                return a.year<b.year;
            }
                      );
        }else if (choise == 3){
            std::sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b){
                return a.v<b.v;
            }
                      );
        }else if (choise == 4){
            std::sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b){
                return a.price<b.price;
            }
                      );
        }
    }
};



int main() {
    Cars carManager;
    cout << "Додаємо авто:" << endl;
    carManager.addCar();
    carManager.addCar();
    carManager.addCar();
    cout << "Видаляємо авто:" << endl;
    carManager.deleteCar();
    cout << "Виводимо всі авто:" << endl;
    carManager.print();
    cout << "Шукаємо авто:" << endl;
    carManager.search();
    cout << "сорторуємо авто:" << endl;
    carManager.sort();
    cout << "Виводимо всі авто:" << endl;
    carManager.print();
    
    return 0;
}
