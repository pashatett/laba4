#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

void RandArrInt(int* mass, int n);
int* newArrInt(int n);
double* newArrDouble(int n);
void RandArrDouble(double* mass, int n);
void ShowArrInt(int* mass, int n);
void ShowArrDouble(double* mass, int n);
void chislo_mensheC_0(int* mass, int n, int C);
int N();
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();
void Task8();
void Task9();
void Task10();
double SumElEvDouble(double* mass, int n);
int MultIntAfterMax(int* mass, int n);

int main()
{
    srand(unsigned(time(0)));
    cout << "*******************************" << endl;
    cout << setw(45) << "Лабораторная работа №4" << endl;
    cout << setw(40) << "Одномерные массивы" << endl;
    cout << "Выполнил студент группы 151412" << endl;
    cout << setw(49) << "Пирогов Павел Алексеевич" << endl;
    cout << setw(30) << "Вариант №17" << endl;
    cout << "*******************************" << endl << endl;
    int n;
    cout << "Какую задачу хотите запустить? "; cin >> n;
    switch (n) {
    case 1:
        Task1();
        break;
    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        Task4();
        break;
    case 5:
        Task5();
        break;

    default:
        cout << "Такой задачи нет((";
        break;
    }
}

int N(){
    int n;
    do {
        cout << "Сколько чисел хотите в массиве? "; cin >> n;
    } while (n <= 0);
    return n;
}

int* newArrInt(int n){
    int* mass = new int[n];
    RandArrInt(mass,n);
    return mass;
}

double* newArrDouble(int n){
    double* mass = new double[n];
    RandArrDouble(mass,n);
    return mass;
}

void RandArrInt(int* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 200 - 100;
    }
}

void RandArrDouble(double* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = 0.01 * (rand() % 20000 - 10000);
    }
}

void ShowArrInt(int* mass, int n) {
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}
void ShowArrDouble(double* mass, int n) {
    for (int i = 0; i < n; i++) {
        cout << mass[i] << " ";
    }
    cout << endl;
}

void Task1() {
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass, n);
    delete[] mass;
}

void Task2() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    delete[] mass;
}

void Task3() {
    int n = N();
    double* mass = newArrDouble(n);
    ShowArrDouble(mass, n);
    cout << "сумма элементов массива с четными индексами = "<<SumElEvDouble(mass, n);
    delete[] mass;
}

double SumElEvDouble(double* mass, int n) {
    double summ = 0.0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)summ += mass[i];
    }
    return summ;
}

void Task4(){
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass,n);

    int mult = MultIntAfterMax(mass, n);

    cout<<"произведение, расположенных после максимального элемента = "<<mult;

    delete[] mass;
}

int MultIntAfterMax(int* mass, int n) {
    int maxx = mass[0];
    int mmm = 0;

    for (int i = 1; i < n; i++){
        if (maxx < mass[i]){
            maxx = mass[i];
            mmm = i;
        }
    }
    if (mmm == n-1)
        return mass[mmm];
    else{
        int mult = 1;
        for (int i = mmm + 1; i<n;i++){
            mult *= mass[i];
        }
        return mult;
    }
}

void Task5(){
    int n = N();
    int* mass = newArrInt(n);
    ShowArrInt(mass,n);

    int C;
    cout<<"Введите число С, числа которые меньше заменятся на 0: ";cin>>C;
    chislo_mensheC_0(mass,n, C);
    ShowArrInt(mass,n);

    delete[] mass;
}

void chislo_mensheC_0(int* mass, int n, int C){
    for (int i = 0; i<n; i++){
        if (mass[i] < C) mass[i] = 0;
    }
}
