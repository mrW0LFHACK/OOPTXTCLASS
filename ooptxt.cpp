#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Person {
private:
    string name;
    string hp;
    string height;
    string gender;
    string weight;
    string race;
/* 
    string name;
    int hp;
    double height;
    string gender;
    int weight;
    string race;
*/
public:
        Person(const string& n, const string& h, const string& ht, const string& g, const string& w, const string& r)
: name(n), hp(h), height(ht), gender(g), weight(w), race(r) {}
//  Person(const string& n, int h, double ht, const string& g, int w, const string& r): name(n), hp(h), height(ht), gender(g), weight(w), race(r) {}
        string getName() const {
        return name;
        }
        string getHp() const {
        return hp;
        }
        string getHeight() const {
        return height;
        }
        string getGender() const {
        return gender;
        }
        string getWeight() const {
        return weight;
        }
        string getRace() const {
        return race;
    }
};
//Открытие файла и запись в конец файла
void saveToFile(const vector<Person>& people) {
    ofstream file("data.txt", ios::app); 
    if (file.is_open()) {
        for (const Person& person : people) {
            file << person.getName() << endl;
            file << person.getHp() << endl;
            file << person.getHeight() << endl;
            file << person.getGender() << endl;
            file << person.getWeight() << endl;
            file << person.getRace() << endl;
        }
        file.close();
        cout << "Данные успешно сохранены в файл." << endl;
    } else {
        cerr << "Не удалось открыть файл для записи. Создайте файл data.txt" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    vector<Person> people;
    string input;

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести имена всех людей" << endl;
        cout << "2. Вывести информацию о человеке" << endl;
        cout << "3. Добавить нового человека" << endl;
        cout << "q. Выйти из программы" << endl;

        cin >> input;

        if (input == "q") {
            break;
        } else if (input == "1") {
            cout << "\nИмена всех людей:" << endl;
            for (const Person& person : people) {
                cout << person.getName() << endl;
            }
        } else if (input == "2") {
            cout << "\nВведите имя человека: ";
            cin.ignore();
            getline(cin, input);

            bool found = false;
            for (const Person& person : people) {
                if (person.getName() == input) {
                    cout << "\nИнформация о человеке:" << endl;
                    cout << "Имя: " << person.getName() << endl;
                    cout << "Кол-во очков здоровья: " << person.getHp() << endl;
                    cout << "Рост в см: " << person.getHeight() << " м" << endl;
                    cout << "Пол М/Ж: " << person.getGender() << endl;
                    cout << "Вес в кг: " << person.getWeight() << " кг" << endl;
                    cout << "Раса: " << person.getRace() << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Человек с именем '" << input << "' не найден." << endl;
            }
        } else if (input == "3") {
            cout << "\nДобавление нового человека:" << endl;
            string name;
            string hp;
            string height;
            string gender;
            string weight;
            string race;

            cout << "Введите имя: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите кол-во HP: ";
            cin >> hp;
            cout << "Введите рост: ";
            cin >> height;
            cout << "Введите пол: ";
            cin.ignore();
            getline(cin, gender);
            cout << "Введите вес: ";
            cin >> weight;
            cout << "Введите расу: ";
            cin.ignore();
            getline(cin, race);

            people.push_back(Person(name, hp, height, gender, weight, race));
            saveToFile(people); // Сохраняем данные в файл
        } else {
            cout << "Некорректный ввод. Попробуйте еще раз." << endl;
        }
    }

    return 0;
}
