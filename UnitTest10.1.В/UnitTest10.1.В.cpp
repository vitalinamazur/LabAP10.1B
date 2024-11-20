#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP10.1.B/LabAP10.1.B.cpp" // Змінити шлях на актуальний

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStudentProgramLevelB
{
    TEST_CLASS(StudentTests)
    {
    public:

        TEST_METHOD(TestAverageCalculation)
        {
            const int N = 2;
            Student* students = new Student[N];

            students[0] = { "Ivanenko", 1, COMPUTER_SCIENCE, 5, 4 };
            students[0].thirdGrade.programming = 5;

            students[1] = { "Petrenko", 2, TECHNOLOGIES, 3, 3 };
            students[1].thirdGrade.numericMethods = 3;

            double avg1 = (students[0].fizyka + students[0].matematika + students[0].thirdGrade.programming) / 3.0;
            double avg2 = (students[1].fizyka + students[1].matematika + students[1].thirdGrade.numericMethods) / 3.0;

            Assert::AreEqual(4.67, avg1, 0.01); // Очікуваний середній бал 4.67
            Assert::AreEqual(3.00, avg2, 0.01); // Очікуваний середній бал 3.00

            delete[] students;
        }

        TEST_METHOD(TestPhysicsAboveThreshold)
        {
            const int N = 3;
            Student* students = new Student[N];

            students[0] = { "Ivanenko", 1, IT, 5, 4 };
            students[0].thirdGrade.pedagogy = 5;

            students[1] = { "Petrenko", 2, MATHEMATICS, 3, 3 };
            students[1].thirdGrade.pedagogy = 3;

            students[2] = { "Shevchenko", 3, ENGINEERING, 5, 5 };
            students[2].thirdGrade.pedagogy = 4;

            // Перевіряємо, скільки студентів отримали оцінку з фізики вище порога
            int threshold = 4;
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (students[i].fizyka > threshold)
                    count++;
            }

            Assert::AreEqual(2, count); // Очікуємо, що 2 студенти отримали більше ніж 4

            delete[] students;
        }

        TEST_METHOD(TestSpecializationGrouping)
        {
            const int N = 3;
            Student* students = new Student[N];

            students[0] = { "Ivanenko", 1, COMPUTER_SCIENCE, 5, 4 };
            students[0].thirdGrade.programming = 5;

            students[1] = { "Petrenko", 2, TECHNOLOGIES, 4, 3 };
            students[1].thirdGrade.numericMethods = 4;

            students[2] = { "Shevchenko", 3, IT, 3, 5 };
            students[2].thirdGrade.pedagogy = 3;

            // Перевірка розподілу спеціальностей
            int csCount = 0, techCount = 0, itCount = 0;
            for (int i = 0; i < N; i++) {
                if (students[i].spec == COMPUTER_SCIENCE) csCount++;
                else if (students[i].spec == TECHNOLOGIES) techCount++;
                else if (students[i].spec == IT) itCount++;
            }

            Assert::AreEqual(1, csCount); // Очікуємо 1 студент із Computer Science
            Assert::AreEqual(1, techCount); // Очікуємо 1 студент із Technologies
            Assert::AreEqual(1, itCount); // Очікуємо 1 студент із IT

            delete[] students;
        }
    };
}
