#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialnist { IT, PHYSICS, MATHEMATICS, ENGINEERING, COMPUTER_SCIENCE, TECHNOLOGIES };

string specialnistStr[] = { "IT", "Physics", "Mathematics", "Engineering", "Computer Science", "Technologies" };

union ThirdGrade {
    int programming;      // ��� ����'������� ����
    int numericMethods;   // ��� �����������
    int pedagogy;         // ��� ����� ��������������
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
    cout << "������ ������� ��������: ";
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
        cout << "������� � " << i + 1 << ":" << endl;

        cin.ignore();
        cout << "    �������: ";
        getline(cin, students[i].prizv);

        cout << "    ���� (1-4): ";
        cin >> students[i].kurs;

        cout << "    ������������ (0 - IT, 1 - Physics, 2 - Mathematics, 3 - Engineering, 4 - Computer Science, 5 - Informatics): ";
        cin >> spec;
        students[i].spec = (Specialnist)spec;

        cout << "    ������ � ������: ";
        cin >> students[i].fizyka;

        cout << "    ������ � ����������: ";
        cin >> students[i].matematika;

        // ��������� ������ � �������� �������� ������� �� ������������
        if (students[i].spec == COMPUTER_SCIENCE) {
            cout << "    ������ � �������������: ";
            cin >> students[i].thirdGrade.programming;
        }
        else if (students[i].spec == TECHNOLOGIES) {
            cout << "    ������ � ��������� ������: ";
            cin >> students[i].thirdGrade.numericMethods;
        }
        else {
            cout << "    ������ � ���������: ";
            cin >> students[i].thirdGrade.pedagogy;
        }

        cout << endl;
    }
}

void PrintTable(const Student* students, const int N) {
    // ��������� ��������� �������
    cout << "==================================================================================================================" << endl;
    cout << "| � | �������       | ���� | ������������ | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        // ��������� ����� ��������
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(15) << left << students[i].prizv
            << "| " << setw(4) << right << students[i].kurs << " "
            << "| " << setw(13) << left << specialnistStr[students[i].spec]
            << "| " << setw(7) << right << students[i].fizyka
            << "| " << setw(11) << right << students[i].matematika;

        // ��������� ������ ������ � ��������� �� ������������
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
