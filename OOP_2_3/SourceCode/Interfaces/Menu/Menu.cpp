#include "Menu.hpp"

using namespace std;

Clinic* clinic = nullptr;
extern Logger::FileLogger logger;

void terminate_func() {
    string message = "Собственная функция завершения: возникло необработанное исключение";
    cout << message << endl;
    logger << make_pair(Logger::FileLogger::LOG_ERROR, message);
    exit(-1);
}

int mainMenu() {
    int selection;
    set_terminate(terminate_func);
    while (true) {
        cout << "\n1 - Создать клинику\n2 - Просмотреть\n3 - Добавить\n4 - Удалить\n5 - Поиск"
        << "\n6 - Редактирование\n7 - Задание\n8 - Выход" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                try {
                    if (clinic != nullptr) throw -1;
                    if (!(clinic = new Clinic(CreateClinic()))) throw bad_alloc();
                }
                catch (bad_alloc exception) {
                    string message = "Ошибка создания клиники: " + string(exception.what());
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, message);
                }
                break;
            case 2:
                if (clinic == nullptr) {
                    string message = "Сначала создайте клинику";
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                    break;
                }
                viewMenu();
                break;
            case 3:
                if (clinic == nullptr) {
                    string message = "Сначала создайте клинику";
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                    break;
                }
                add();
                break;
            case 4:
                if (clinic == nullptr) {
                    string message = "Сначала создайте клинику";
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                    break;
                }
                remove();
                break;
            case 5:
                if (clinic == nullptr) {
                    string message = "Сначала создайте клинику";
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                    break;
                }
                search();
                break;
            case 6:
                if (clinic == nullptr) {
                    string message = "Сначала создайте клинику";
                    cout << message << endl;
                    logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                    break;
                }
                edit();
                break;
            case 7:
                task();
                break;
            default:
                string message = "Работа завершена";
                cout << message << endl;
                logger << make_pair(Logger::FileLogger::LOG_WARNING, message);
                delete clinic;
                return 0;
        }
    }
}

void add() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции добавления");
    int selection;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
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
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Добавление завершено");
                cout << "Добавление завершено" << endl;
                return;
        }
    }
}

void remove() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции удаления");
    int selection;
    size_t index;
    while (true) {
        cout << "\n1 - Врач\n2 - Стоматолог\n3 - Фельдшер\n4 - Медсестра\n5 - Пациент\n6 - Назад" << endl;
        cout << "Выберите пункт меню: ";
        selection = CorrectCin<int>();
        logger << make_pair(Logger::FileLogger::LOG_INFO, string("Выбрано значение: " + to_string(selection)));
        switch (selection) {
            case 1:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    clinic->removeDoctor(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            case 2:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    clinic->removeDentist(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            case 3:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    clinic->removeParamedic(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    clinic->removeNurse(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            case 5:
                cout << "Введите индекс: ";
                index = CorrectCin<int>();
                logger << make_pair(Logger::FileLogger::LOG_INFO, string("Введен индекс: " + to_string(index)));
                try {
                    clinic->removePatient(index);
                }
                catch (...) {
                    cout << "Невозможно выполнить операцию" << endl;
                    logger << make_pair(Logger::FileLogger::LOG_ERROR, "Невозможно выполнить операцию");
                }
                break;
            default:
                cout << "Удаление завершено" << endl;
                logger << make_pair(Logger::FileLogger::LOG_INFO, "Удаление завершено");
                return;
        }
    }
}

void task() {
    logger << make_pair(Logger::FileLogger::LOG_INFO, "В функции задания");
    int input = 0;
    cout << "Вопрос: для чего необходимо использовать абсолютный обработчик?" << endl
    << "Чтобы просмотреть ответ нажмите 1: ";
    input = CorrectCin<int>();
    while (input != 1) {
        cout << "Неверный ввод, повторите попытку: ";
        input = CorrectCin<int>();
    }
    cout << "Ответ: абсолютный обработчик используемя для перехвата исключений любых типов" << endl;
    logger << make_pair(Logger::FileLogger::LOG_INFO, "Выход из функции задания");
    return;
}
