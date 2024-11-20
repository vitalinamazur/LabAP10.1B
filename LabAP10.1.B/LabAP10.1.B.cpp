#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { IT, PHYSICS, MATHEMATICS, ENGINEERING, COMPUTER_SCIENCE, TECHNOLOGIES };

string specialnistStr[] = { "IT", "Physics", "Mathematics", "Engineering", "Computer Science", "Technologies" };

union ThirdGrade {
    int programming;      // Для Комп'ютерних наук
    int numericMethods;   // Для Інформатики
    int pedagogy;         // Для інших спеціальностей
};

struct Student {
    string prizv;
    int kurs;
    Specialnist spec;
    int fizyka;
    int matematika;
    ThirdGrade thirdGrade;
};

void Create(Student* students, const int N);
void Print(const Student* students, const int N);
void PrintTable(const Student* students, const int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];

    Create(students, N);
    PrintTable(students, N);

    delete[] students;
    return 0;
}

void Create(Student* students, const int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.ignore();
        cout << "    Прізвище: ";
        getline(cin, students[i].prizv);

        cout << "    Курс (1-4): ";
        cin >> students[i].kurs;

        cout << "    Спеціальність (0 - IT, 1 - Physics, 2 - Mathematics, 3 - Engineering, 4 - Computer Science, 5 - Informatics): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;

        cout << "    Оцінка з фізики: ";
        cin >> students[i].fizyka;

        cout << "    Оцінка з математики: ";
        cin >> students[i].matematika;

        // Визначаємо оцінку з третього предмета залежно від спеціальності
        if (students[i].spec == COMPUTER_SCIENCE) {
            cout << "    Оцінка з програмування: ";
            cin >> students[i].thirdGrade.programming;
        }
        else if (students[i].spec == TECHNOLOGIES) {
            cout << "    Оцінка з чисельних методів: ";
            cin >> students[i].thirdGrade.numericMethods;
        }
        else {
            cout << "    Оцінка з педагогіки: ";
            cin >> students[i].thirdGrade.pedagogy;
        }

        cout << endl;
    }
}

void PrintTable(const Student* students, const int N) {
    // Виведення заголовка таблиці
    cout << "==================================================================================================================" << endl;
    cout << "| № | Прізвище       | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        // Виведення даних студентів
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(15) << left << students[i].prizv
            << "| " << setw(4) << right << students[i].kurs << " "
            << "| " << setw(13) << left << specialnistStr[students[i].spec]
            << "| " << setw(7) << right << students[i].fizyka
            << "| " << setw(11) << right << students[i].matematika;

        // Виведення третьої оцінки в залежності від спеціальності
        if (students[i].spec == COMPUTER_SCIENCE) {
            cout << "| " << setw(14) << right << students[i].thirdGrade.programming;
        }
        else {
            cout << "| " << setw(14) << right << "-";
        }

        if (students[i].spec == TECHNOLOGIES) {
            cout << "| " << setw(16) << right << students[i].thirdGrade.numericMethods;
        }
        else {
            cout << "| " << setw(16) << right << "-";
        }

        if (students[i].spec != COMPUTER_SCIENCE && students[i].spec != TECHNOLOGIES) {
            cout << "| " << setw(12) << right << students[i].thirdGrade.pedagogy;
        }
        else {
            cout << "| " << setw(12) << right << "-";
        }

        cout << " |" << endl;
    }

    cout << "==================================================================================================================" << endl;
}
