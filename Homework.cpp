#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <Windows.h>

//1.Структура книги
struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
};

int main() {
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //1.Основной каталог книг на основе vector (минимум 5 книг)

    std::vector<Book> catalog = {
        {1, "Война и мир", "Лев Толстой", 1869},
        {2, "Преступление и наказание", "Фёдор Достоевский", 1866},
        {3, "Мастер и Маргарита", "Михаил Булгаков", 1967},
        {4, "Евгений Онегин", "Александр Пушкин", 1833},
        {5, "Анна Каренина", "Лев Толстой", 1877},
        {6, "Отцы и дети", "Иван Тургенев", 1862}
    };

    std::cout << "=== КАТАЛОГ КНИГ (vector) ===" << std::endl;
    for (const auto& book : catalog) {
        std::cout << "ID: " << book.id
            << " | " << book.title
            << " | Автор: " << book.author
            << " | Год: " << book.year << std::endl;
    }
    //2.Контейнер map: ключ — id, значение — структура книги
    std::map<int, Book> bookMap;
    for (const auto& book : catalog) {
        bookMap[book.id] = book;
    }

    std::cout << "\n=== КАТАЛОГ КНИГ (map) ===" << std::endl;
    for (const auto& pair : bookMap) {
        std::cout << "Ключ (ID): " << pair.first
            << " | " << pair.second.title
            << " | Автор: " << pair.second.author << std::endl;
    }
    //3.Множество уникальных авторов
    std::set<std::string> authors;
    for (const auto& book : catalog) {
        authors.insert(book.author);
    }

    std::cout << "\n=== УНИКАЛЬНЫЕ АВТОРЫ (set) ===" << std::endl;
    for (const auto& author : authors) {
        std::cout << author << std::endl;
    }

    std::cout << "\nВсего авторов в множестве: " << authors.size() << std::endl;
    std::cout << "(Лев Толстой встречается в каталоге дважды, но в set хранится один раз)" << std::endl;

    return 0;
}