#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

void MakeArrInt(int* mass, int n);
void MakeArrDouble(double* mass, int n);
void ShowArrInt(int* mass, int n);
void ShowArrDouble(double* mass, int n);
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
    case 6:
        Task6();
        break;
    case 7:
        Task7();
        break;
    case 8:
        Task8();
        break;
    case 9:
        Task7();
        break;
    case 10:
        Task8();
        break;
    default:
        cout << "Такой задачи нет((";
        break;
    }
}

void Task1() {
    int n;
    do {
        cout << "Сколько чисел хотите в массиве? "; cin >> n;
    } while (n <= 0);
    int* mass = new int[n];
    MakeArrInt(mass, n);
    ShowArrInt(mass, n);
    delete[] mass;
}

void MakeArrInt(int* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = rand() % 200 - 100;
    }
}

void MakeArrDouble(double* mass, int n) {
    for (int i = 0; i < n; i++) {
        mass[i] = 0.01 * (rand() % 200 - 100);
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

void Task2() {
    int n;
    do {
        cout << "Сколько чисел хотите в массиве? "; cin >> n;
    } while (n <= 0);
    double* mass = new double[n];
    MakeArrDouble(mass, n);
    ShowArrDouble(mass, n);
}

void Task3() {
    int n;
    do {
        cout << "Сколько чисел хотите в массиве? "; cin >> n;
    } while (n <= 0);
    double* mass = new double[n];
    MakeArrDouble(mass, n);
    ShowArrDouble(mass, mass[0]);
    cout << SumElEvDouble(mass, mass[0]);
}

double SumElEvDouble(double* mass, int n) {
    double summ = 0.0;
    for (int i = 0; i < n + 1; i++) {
        if (i % 2 != 0)summ += mass[i];
    }
    return summ;
}

int MultIntAfterMax(int* mass, int n) {
    int maxx = mass[1];
    for (int i = 1; i < n + 1; i++) {
        if (maxx < mass[i])maxx = i;
    }
    int mult = 1;
    for (int i = maxx + 1; i <= n + 1; i++) {
        mult *= mass[i];
    }
    return mult;
}

void Task4() {
    int* array = createIntArrayFromInput(n);

    int first = -1;
    int last = -1;
    for (unsigned i = 0; i < n; i++)
        if (array[i] < 0)
            if (first == -1)
                first = i;
            else
                last = i;

    if (first == -1 || last == -1) {
        cout << "Найти сумму не удалось" << endl;
        return;
    }

    int S = 0;
    for (unsigned i = first + 1; i < last; i++)
        S += array[i];
    cout << S << endl;
    delete[] array;
}

void Task5() {
    double* array = Task2();
    for (unsigned i = 0; i < n; i++)
        if (array[i] > 0)
            array[i] = -rand() - ((float)rand() / (float)rand());
    ShowArrDouble(array, n);
    delete[] array;
}

void Task6() {
    float* array = createFloatArrayFromInput(n);
    float findEl;
    cout << "Введите элемент, который нужно найти: ";
    cin >> findEl;

    for (unsigned i = 0; i < n; i++)
        if (abs(array[i] - findEl) < __FLT_EPSILON__) {
            cout << "Номер элемента: " << i << endl;
            return;
        }
    cout << "Элемент не найден" << endl;
    delete[] array;
}

void Task7() {
    float* array = createFloatArrayFromInput(n);
    floatSelectionSort(array, n);
    ShowArrDouble(array, n);
    delete[] array;
}

void Task8() {
    float* array = createFloatArrayFromInput(n);
    for (unsigned i = 0; i < n; i++) {
        unsigned index = i;
        if (isFloatEven(array[i])) continue;
        for (unsigned j = i + 1; j < n; j++) {
            if (isFloatEven(array[j])) {
                float buf = array[i];
                array[i] = array[j];
                array[j] = buf;
            }
        }
    }
    ShowArrDouble(array, n);
    delete[] array;
}

void Task9() {
    int* array = createIntArrayFromInput(n);
    intFastSort(array, n);
    ShowArrInt(array, n);
    delete[] array;
}

void Task10() {
    int* array = createIntArrayFromInput(n);
    int key;
    cout << "Введите число, которое надо найти: "; cin >> key;
    intFastSort(array, n);
    int index = intBinarySearch(array, n, key);
    if (index != -1) 
        cout << "Индекс элемента: " << index << endl;
    else 
        cout << "Элемент не найден" << endl;
    delete[] array;
}


int* createIntArrayFromInput(unsigned length) {
    int* array = new int[length];

    for (unsigned i = 0; i < length; i++) {
        int el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

float* createFloatArrayFromInput(unsigned length) {
    float* array = new float[length];

    for (unsigned i = 0; i < length; i++) {
        float el;
        cin >> el;
        array[i] = el;
    }
    return array;
}

void floatSelectionSort(float array[], unsigned size) {
    for (unsigned i = 0; i < size; i++) {
        int min_index = i;
        for (unsigned j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) 
                min_index = j;
        }
        if (min_index != i) {
            float buf = array[i];
            array[i] = array[min_index];
            array[min_index] = buf;
        }
    }
}

bool isFloatEven(float number) {
    return (int)number % 2 == 0;
}

void intFastSort(int array[], unsigned size) {
    helpIntFastSort(array, size, 0, size - 1);
}

void helpIntFastSort(int array[], unsigned size, unsigned low, unsigned high) {
    if (low < high) {
        unsigned mid_index = partition(array, size, low, high);
        helpIntFastSort(array, size, low, mid_index);
        helpIntFastSort(array, size, mid_index + 1, high);
    }
}

unsigned partition(int array[], unsigned size, unsigned low, unsigned high) {
    int pivot = array[(low + high) / 2];
    unsigned i = low;
    unsigned j = high;
    while (1) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;
        if (i >= j) return j;
        int buf = array[i];
        array[i] = array[j];
        array[j] = buf;
    }
}

int intBinarySearch(int array[], unsigned size, int key) {
    ShowArrInt(array, size);
    return helpIntBinarySearch(array, size, key, 0, size - 1);
}

int helpIntBinarySearch(int array[], unsigned size, int key, unsigned first, unsigned last) {
    while (first <= last) {
        unsigned mid = (first + last) / 2;
        int el = array[mid];
        if (key < el) last = mid - 1;
        else if (key > el) first = mid + 1;
        else return mid;
    }
    return -1;
}