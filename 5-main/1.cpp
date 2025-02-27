#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string word = "danilpydidi";
    string guessedWord(word.length(), '_');
    vector<char> wrongGuesses;
    int attempts = 100;

    cout << "Добро пожаловать в игру Виселица!" << endl;

    while (attempts > 0 && guessedWord != word) {
        cout << "Неправильные догадки: ";
        for (char c : wrongGuesses) {
            cout << c << ' ';
        }
        cout << endl;
        cout << "У вас осталось попыток: " << attempts << endl;

        char guess;
        cout << "Введите букву: ";
        cin >> guess;


        if (find(wrongGuesses.begin(), wrongGuesses.end(), guess) != wrongGuesses.end() ||
            guessedWord.find(guess) != string::npos) {
            cout << "Вы уже угадывали эту букву. Попробуйте другую." << endl;
            continue;
        }


        if (word.find(guess) != string::npos) {
            for (size_t i = 0; i < word.length(); ++i) {
                if (word[i] == guess) {
                    guessedWord[i] = guess;
                }
            }
        }
        else {
            wrongGuesses.push_back(guess);
            attempts--;
        }
    }

    if (guessedWord == word) {
        cout << "Поздравляем! Вы угадали слово: " << word << endl;
    }
    else {
        cout << "Вы проиграли! Загаданное слово было: " << word << endl;
    }

    return 0;
}