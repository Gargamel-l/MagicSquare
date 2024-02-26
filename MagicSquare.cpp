#include <iostream>
#include <string>



using namespace std;

string encryptText(string text, int** keyMatrix, int size) {

    size_t textLeng = text.length();
    char* encryptedText = new char[textLeng + 1];
    int* flat_matrix = new int[size];

    // Нормализация текста: удаляем пробелы и приводим к верхнему регистру
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            text[i] = toupper(text[i]);
        }
    }

    int l = 0;
    for (int j = 0; j < size; j++)
    {
        for (int k = 0; k < size; k++)
        {
            flat_matrix[l] = keyMatrix[j][k];
            l++;
        }

    }

    for (size_t i = 0; i < textLeng; i++) {
        encryptedText[flat_matrix[i] - 1] = text[i];

    }
    encryptedText[textLeng] = '\0';


    return encryptedText;
    delete[] encryptedText;
    delete[] flat_matrix;
}

int main() {
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");
    string text;
    cout << "Enter the encryption text: ";
    getline(cin, text);

    int size = ceil(sqrt(text.length()));  // Вычисляем размер магического квадрата
    int** keyMatrix = new int* [size];  // Создаем двумерный массив для хранения ключевой матрицы
    for (int i = 0; i < size; i++) {  // Инициализируем каждую строку массива
        keyMatrix[i] = new int[size];
    }

    cout << "Enter " << size << "x" << size << " elements of the magic square:" << endl;
    for (int i = 0; i < size; i++) {  // Заполняем матрицу пользвательскими данными
        for (int j = 0; j < size; j++) {
            cin >> keyMatrix[i][j];
        }
    }

    string encryptedText = encryptText(text, keyMatrix, size);  // Зашифровываем текст
    cout << "Encrypted text: " << encryptedText << endl;  // Выводим зашифрованный текст на экран

    for (int i = 0; i < size; i++) {  // Освобождаем память, выделенную для массива
        delete[] keyMatrix[i];
    }
    delete[] keyMatrix;

    return 0;
}