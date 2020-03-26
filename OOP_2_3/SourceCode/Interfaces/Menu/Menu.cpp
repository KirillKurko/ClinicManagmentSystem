#include "Menu.hpp"

using namespace std;

Clinic* clinic = nullptr;

void terminate_func() {
    cout << "Собственная функция завершения: возникло необработанное исключение" << endl;
    exit(-1);
}

int mainMenu() {
    Logger::FileLogger logger;
    int selection;
    set_terminate(terminate_func);
    while (true) {
        cout << "\n1 - Создать клинику\n2 - Просмотреть\n3 - Добавить\n4 - Удалить\n5 - Поиск"
        << "\n6 - Редактирование\n7 - Задание\n8 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                try {
                    if (clinic != nullptr) throw -1;
                    if (!(clinic = new Clinic(CreateClinic()))) throw bad_alloc();
                }
                catch (bad_alloc exception) {
                    cout << "Ошибка создания клиники: " << exception.what() << endl;
                }
                break;
            case 2:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                viewMenu();
                break;
            case 3:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                add();
                break;
            case 4:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                remove();
                break;
            case 5:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                search();
                break;
            case 6:
                if (clinic == nullptr) {
                    cout << "Сначала создайте клинику" << endl;
                    break;
                }
                edit();
                break;
            case 7:
                task();
                break;
            default:
                cout << "Работа завершена" << endl;
                delete clinic;
                return 0;
        }
    }
}

void add() {
    int selection;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                clinic->addDoctor(CreateDoctor());
                break;
            case 2:
                clinic->addDentist(CreateDentist());
                break;
            case 3:
                clinic->addParamedic(CreateParamedic());
                break;
            case 4:
                clinic->addNurse(CreateNurse());
                break;
            case 5:
                clinic->addPatient(make_shared<Person>(CreatePerson()));
                break;
            default:
                cout << "Добавление завершено" << endl;
                return;
        }
    }
}

void remove() {
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        switch (selection) {
            case 1:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeDoctor(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeDentist(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 3:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeParamedic(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removeNurse(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            case 5:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                try {
                    clinic->removePatient(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                }
                break;
            default:
                cout << "Удаление завершено" << endl;
                return;
        }
    }
}

void task() {
    int input = 0;
    cout << "Вопрос: для чего необходимо использовать абсолютный обработчик?" << endl
    << "Чтобы просмотреть ответ нажмите 1: ";
    input = CorrectCin<int>();
    while (input != 1) {
        cout << "Неверный ввод, повторите попытку: ";
        input = CorrectCin<int>();
    }
    cout << "Ответ: абсолютный обработчик используемя для перехвата исключений любых типов" << endl;
    return;
}
