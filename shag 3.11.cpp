#include <iostream>
#include <algorithm>

using namespace std;








// ������ �������� 1








// �������� 1
struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    char genre[50];
};








void printBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "�����: " << books[i].title << ", �����: " << books[i].author
            << ", �����������: " << books[i].publisher << ", ����: " << books[i].genre << endl;
    }
}






void editBook(Book& book) {
    cout << "���������� �����" << endl;
    cout << "������ ���� �����: ";
    cin >> book.title;
    cout << "������ ������ ������: ";
    cin >> book.author;
    cout << "������ ���� �����������: ";
    cin >> book.publisher;
    cout << "������ ����� ����: ";
    cin >> book.genre;
}





void searchByAuthor(Book books[], int size, const char* author) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].author, author) == 0) {
            cout << "�����: " << books[i].title << ", �����: " << books[i].author
                << ", �����������: " << books[i].publisher << ", ����: " << books[i].genre << endl;
            found = true;
        }
    }
    if (!found) cout << "����� �� ������� �� ��������!" << endl;
}





void searchByTitle(Book books[], int size, const char* title) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (strcmp(books[i].title, title) == 0) {
            cout << "�����: " << books[i].title << ", �����: " << books[i].author
                << ", �����������: " << books[i].publisher << ", ����: " << books[i].genre << endl;
            found = true;
        }
    }
    if (!found) cout << "����� �� ������ �� ��������!" << endl;
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









// ������ �������� 2

// �������� 1
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
    cout << "������ ���� ������: ";
    cin >> car.color;
    cout << "������ ������ ������: ";
    cin >> car.model;
    cout << "������ ����� ������ (�'���������� ��� �����): ";
    char num[10];
    cin >> num;
    if (isdigit(num[0])) {
        car.number.number = atoi(num);
    }
    else {
        strncpy(car.number.word, num, 8);
    }
    cout << "������� ��� ������ (0 - Sedan, 1 - Coupe, 2 - Hatchback): ";
    int type;
    cin >> type;
    car.type = static_cast<CarType>(type);
}




void printCar(const Car& car) {
    cout << "����: " << car.color << ", ������: " << car.model;
    if (car.type == Sedan) cout << ", ���: Sedan";
    else if (car.type == Coupe) cout << ", ���: Coupe";
    else cout << ", ���: Hatchback";
    cout << ", �����: ";
    if (car.number.number) {
        cout << car.number.number;
    }
    else {
        cout << car.number.word;
    }
    cout << endl;
}














// �������� 2

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
    cout << "������ �������� �����������: ";
    cin >> entity.speed;
    cout << "������ ����: ";
    cin >> entity.color;
    cout << "������� ��� (0 - ����, 1 - ������, 2 - ������): ";
    int type;
    cin >> type;
    entity.type = static_cast<EntityType>(type);

    if (entity.type == Bird) {
        cout << "������ �������� ������� (��/���): ";
        cin >> entity.characteristic.flightSpeed;
    }
    else if (entity.type == Animal) {
        cout << "������, �� � ������������� (1 - ���, 0 - �): ";
        cin >> entity.characteristic.isHoofed;
    }
    else if (entity.type == Human) {
        cout << "������ ����� IQ: ";
        cin >> entity.characteristic.iq;
    }
}





void printEntity(const Entity& entity) {
    cout << "�������� �����������: " << entity.speed << ", ����: " << entity.color;
    if (entity.type == Bird) {
        cout << ", ���: ����, �������� �������: " << entity.characteristic.flightSpeed;
    }
    else if (entity.type == Animal) {
        cout << ", ���: ������, ������������: " << (entity.characteristic.isHoofed ? "���" : "ͳ");
    }
    else if (entity.type == Human) {
        cout << ", ���: ������, г���� IQ: " << entity.characteristic.iq;
    }
    cout << endl;
}
