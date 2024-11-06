#include <iostream>
#include <algorithm>

using namespace std;








// Домашнє завдання 1








// Завдання 1
struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    char genre[50];
};








void printBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Назва: " << books[i].title << ", Автор: " << books[i].author
            << ", Видавництво: " << books[i].publisher << ", Жанр: " << books[i].genre << endl;
    }
}






void editBook(Book& book) {
    cout << "Редагувати книгу" << endl;
    cout << "Введіть нову назву: ";
    cin >> book.title;
    cout << "Введіть нового автора: ";
    cin >> book.author;
    cout << "Введіть нове видавництво: ";
    cin >> book.publisher;
    cout << "Введіть новий жанр: ";
    cin >> book.genre;
}





void searchByAuthor(Book books[], int size, const char* author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].author, author) == 0) {
            cout << "Назва: " << books[i].title << ", Автор: " << books[i].author
                << ", Видавництво: " << books[i].publisher << ", Жанр: " << books[i].genre << endl;
            found = true;
        }
    }
    if (!found) cout << "Книги за автором не знайдено!" << endl;
}





void searchByTitle(Book books[], int size, const char* title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].title, title) == 0) {
            cout << "Назва: " << books[i].title << ", Автор: " << books[i].author
                << ", Видавництво: " << books[i].publisher << ", Жанр: " << books[i].genre << endl;
            found = true;
        }
    }
    if (!found) cout << "Книги за назвою не знайдено!" << endl;
}





void sortByTitle(Book books[], int size) {
    sort(books, books + size, [](Book a, Book b) {
        return strcmp(a.title, b.title) < 0;
        });
}






void sortByAuthor(Book books[], int size) {
    sort(books, books + size, [](Book a, Book b) {
        return strcmp(a.author, b.author) < 0;
        });
}






void sortByPublisher(Book books[], int size) {
    sort(books, books + size, [](Book a, Book b) {
        return strcmp(a.publisher, b.publisher) < 0;
        });
}









// Домашнє завдання 2

// Завдання 1
union CarNumber {
    int number;
    char word[8];
};

enum CarType { Sedan, Coupe, Hatchback };

struct Car {
    char color[20];
    char model[20];
    CarNumber number;
    CarType type;
};






void fillCar(Car& car) {
    cout << "Введіть колір машини: ";
    cin >> car.color;
    cout << "Введіть модель машини: ";
    cin >> car.model;
    cout << "Введіть номер машини (п'ятизначний або слово): ";
    char num[10];
    cin >> num;
    if (isdigit(num[0])) {
        car.number.number = atoi(num);
    }
    else {
        strncpy(car.number.word, num, 8);
    }
    cout << "Виберіть тип машини (0 - Sedan, 1 - Coupe, 2 - Hatchback): ";
    int type;
    cin >> type;
    car.type = static_cast<CarType>(type);
}




void printCar(const Car& car) {
    cout << "Колір: " << car.color << ", Модель: " << car.model;
    if (car.type == Sedan) cout << ", Тип: Sedan";
    else if (car.type == Coupe) cout << ", Тип: Coupe";
    else cout << ", Тип: Hatchback";
    cout << ", Номер: ";
    if (car.number.number) {
        cout << car.number.number;
    }
    else {
        cout << car.number.word;
    }
    cout << endl;
}














// Завдання 2

enum EntityType { Bird, Animal, Human };

union Characteristic {
    float flightSpeed;
    bool isHoofed;
    int iq;
};

struct Entity {
    float speed;
    EntityType type;
    char color[20];
    Characteristic characteristic;
};





void inputEntity(Entity& entity) {
    cout << "Введіть швидкість пересування: ";
    cin >> entity.speed;
    cout << "Введіть колір: ";
    cin >> entity.color;
    cout << "Виберіть тип (0 - Птах, 1 - Худоба, 2 - Людина): ";
    int type;
    cin >> type;
    entity.type = static_cast<EntityType>(type);

    if (entity.type == Bird) {
        cout << "Введіть швидкість польоту (км/год): ";
        cin >> entity.characteristic.flightSpeed;
    }
    else if (entity.type == Animal) {
        cout << "Введіть, чи є парнокопитною (1 - так, 0 - ні): ";
        cin >> entity.characteristic.isHoofed;
    }
    else if (entity.type == Human) {
        cout << "Введіть рівень IQ: ";
        cin >> entity.characteristic.iq;
    }
}





void printEntity(const Entity& entity) {
    cout << "Швидкість пересування: " << entity.speed << ", Колір: " << entity.color;
    if (entity.type == Bird) {
        cout << ", Тип: Птах, Швидкість польоту: " << entity.characteristic.flightSpeed;
    }
    else if (entity.type == Animal) {
        cout << ", Тип: Худоба, Парнокопитна: " << (entity.characteristic.isHoofed ? "Так" : "Ні");
    }
    else if (entity.type == Human) {
        cout << ", Тип: Людина, Рівень IQ: " << entity.characteristic.iq;
    }
    cout << endl;
}
