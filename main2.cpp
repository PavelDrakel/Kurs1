#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

struct service {
    string selected_service;
    string date;
    string selected_time;
};

struct Card {
    string Fname, Mname, Lname;
    string password;
    string email;
    int age;
    int room;
    char gender;
    vector<service> serv;
};

class Registry {
private:
    vector<Card> cards;
    string empEmail = "admin";
    string empPas = "root";

public:
    bool find_email(string mail) {
        if (cards.empty())
            return true;
        for (int i = 0; i < cards.size(); ++i) {
            if (mail == cards[i].email)
                return false;
        }
        return true;
    }

    void registration() {
        string fname, mname, lname;
        string mail;
        string pas;
        int ag;
        int rom;
        char gen;
        
        cout << "Давйте начнем регистрацию\n";

        while (true) {
            cout << "Введите ваш email: \n";
            cin >> mail;
            int cdog = 0;
            for (char ch : mail) {
                if (ch == '@')
                    cdog++;
            }
            if (cdog != 1) {
                cout << "email введён не корректно\nПопробуйте еще раз\n";
                continue;
            }
            if (!cards.empty()) {
                bool f = true;
                for (int i = 0; i < cards.size(); ++i) {
                    if (mail == cards[i].email) {
                        f = false;
                        cout << "Такой email уже зарегисрирован\nПопробуйте еще раз\n";
                        break;
                    }
                }
                if (f == false)
                    continue;
            }
            break;
        }
        cout << "Отлично!\n\n";

        cout << "Введите ваше ФИО (через пробел): \n";
        cin >> lname >> fname >> mname;
        cout << "Отлично!\n\n";

        while (true) {
            cout << "Введите ваш возраст \n";
            if (cin >> ag) {
                if (ag > 0 && ag < 120) {
                    break;
                }
                cout << "Возраст должен быть реальным числом (от 1 до 119)!\n";
            }
            else {
                cout << "Ошибка! Вы ввели не число. Пожалуйста, используйте цифры.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
        cout << "Отлично!\n\n";

        while (true) {
            cout << "Введите ваш пол (M/F): \n";
            cin >> gen;
            gen = toupper(gen);
            if (gen == 'M' || gen == 'F') {
                break;
            }
            cout << "Вы ввели не корекстный пол\nПопробуйте еще раз\n";
        }
        cout << "Отлично!\n\n";

        while (true) {
            cout << "Введите номер вашей комнаты: ";
            if (cin >> rom) {
                if (rom > 0) {
                    break;
                }
                cout << "Вы ввели не корекстный номер комнаты\nПопробуйте еще раз\n";
            } 
            else {
                cout << "Ошибка! Вы ввели не число. Пожалуйста, используйте цифры.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
        cout << "Отлично!\n\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        while (true) {
            cout << "Придумайте пароль: \n";
            getline(cin, pas);
            
            if (pas.find(' ') == string::npos && !pas.empty()) {
                break;
            }
            if (pas.empty()) {
                cout << "Пароль не может быть пустым!\n";
            } else {
                cout << "В пароле не должно быть пробелов!\nПопробуйте еще раз\n";
            }
        }
        cout << "Отлично!\n\n";

        Card obj;
        obj.Fname = fname;
        obj.Lname = lname;
        obj.Mname = mname;
        obj.age = ag;
        obj.email = mail;
        obj.gender = gen;
        obj.password = pas;
        obj.room = rom;

        cards.push_back(obj);
        cout << "Регистрация завершена!\n";

        personal_account(mail, pas);
    }

    void personal_account(string mail, string pas) {
        bool f = false;
        int t = -1;
        for (int i = 0; i < cards.size(); ++i) {
            if (mail == cards[i].email && pas == cards[i].password) {
                f = true;
                t = i;
                break;
            }
        }
        if (f) {
            personal_account(t);
        }
        else {
            cout << "Неудалось войти\nНеверный email или пороль\n";
        }
    }

    void personal_account(int t) {
        cout << "----------ЛИЧНЫЙ КАБИНЕТ----------\n";
        cout << "Имя: " << cards[t].Fname << endl;
        cout << "Фамилие: " << cards[t].Lname << endl;
        cout << "Отчество: " << cards[t].Mname << endl;
        cout << "Возраст: " << cards[t].age << endl;
        cout << "Пол: " << cards[t].gender << endl;
        cout << "Номер комнаты: " << cards[t].room << endl;

        cout << "---------Список записей---------\n";
        if (cards[t].serv.empty()) {
            cout << "У вас пока нет активных записей.\n";
        } else {
            for (int i = 0; i < cards[t].serv.size(); ++i) {
                cout << "[" << i + 1 << "] " << cards[t].serv[i].selected_service 
                     << " | Дата: " << cards[t].serv[i].date 
                     << " | Время: " << cards[t].serv[i].selected_time << endl;
            }
        }
        cout << "--------------------------------\n";

        while (true) {
            int m;
            cout << "[0] Выход\n";
            if (cin >> m && m == 0) {
                cout << endl << endl << endl;
                return;
            }
        }
    }

    void login() {
        string mail;
        string pas;

        while (true) {
            cout << "Введите ваш email: \n";
            cin >> mail;
            int cdog = 0;
            for (char ch : mail) {
                if (ch == '@')
                    cdog++;
            }
            if (cdog != 1) {
                cout << "email введён не корректно\nПопробуйте еще раз\n";
                continue;
            }
            break;
        }

        cout << "Введите ваш пароль: \n";
        cin >> pas;
        if (!cards.empty()) {
            for (int i = 0; i < cards.size(); ++i) {
                if (mail == cards[i].email) {
                    if (pas == cards[i].password) {
                        personal_account(i);
                        return;
                    } else {
                        break;
                    }
                }
            }
        }
        cout << "Пользователь не найден.\nПроверьте правильность email и пароля и попробуйте снова.\n";
    }

    void add_srv() {
        if (cards.empty()) {
            cout << "В базе еще нет зарегистрированных отдыхающих!\n";
            return;
        }

        string name, fam;
        int rom;
        cout << "Введите Имя, Фамилию и номер комнаты отдыхающего (через пробел):\n";
        cin >> name >> fam >> rom;

        int user_index = -1;
        for (int i = 0; i < cards.size(); ++i) {
            if (name == cards[i].Fname && fam == cards[i].Lname && rom == cards[i].room) {
                user_index = i;
                break;
            }
        }

        if (user_index == -1) {
            cout << "Пользователь с такими данными не найден.\n";
            return;
        }

        string available_services[4] = {"Бальнеотерапия", "Массаж", "Физиотерапия", "Ингаляции"};
        string available_times[4] = {"12:00", "13:00", "14:00", "15:00"};

        service new_booking;

        // 1. Выбор услуги
        cout << "\n--- Выберите услугу ---\n";
        for (int i = 0; i < 4; ++i) {
            cout << "[" << i + 1 << "] " << available_services[i] << endl;
        }
        int choice_ser;
        while (!(cin >> choice_ser) || choice_ser < 1 || choice_ser > 4) {
            cout << "Неверный ввод. Выберите от 1 до 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        new_booking.selected_service = available_services[choice_ser - 1];

        // 2. Ввод даты
        cout << "\nВведите дату приема (например, 28.05.2026): ";
        cin >> new_booking.date;

        // 3. Выбор времени
        cout << "\n--- Выберите доступное время ---\n";
        for (int i = 0; i < 4; ++i) {
            cout << "[" << i + 1 << "] " << available_times[i] << endl;
        }
        int choice_time;
        while (!(cin >> choice_time) || choice_time < 1 || choice_time > 4) {
            cout << "Неверный ввод. Выберите от 1 до 4: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        new_booking.selected_time = available_times[choice_time - 1];

        bool is_busy = false;
        for (int i = 0; i < cards[user_index].serv.size(); ++i) {
            if (cards[user_index].serv[i].date == new_booking.date && 
                cards[user_index].serv[i].selected_time == new_booking.selected_time) {
                is_busy = true;
                cout << "\n[ОШИБКА] Отдыхающий уже записан на " 
                     << cards[user_index].serv[i].selected_service 
                     << " в это же время (" << new_booking.selected_time << " " << new_booking.date << ")!\n";
                break;
            }
        }

        if (is_busy) {
            cout << "Запись отклонена. Выберите другое время или дату.\n";
            return;
        }

        cards[user_index].serv.push_back(new_booking);

        cout << "\nУспешно! Отдыхающий " << fam << " " << name << " записан на " 
             << new_booking.selected_service << " (" << new_booking.date << " в " << new_booking.selected_time << ")\n";
    }

    void cancel_srv() {
        if (cards.empty()) {
            cout << "В базе еще нет зарегистрированных отдыхающих!\n";
            return;
        }

        string name, fam;
        int rom;
        cout << "Введите Имя, Фамилию и номер комнаты отдыхающего для отмены записи (через пробел):\n";
        cin >> name >> fam >> rom;

        int user_index = -1;
        for (int i = 0; i < cards.size(); ++i) {
            if (name == cards[i].Fname && fam == cards[i].Lname && rom == cards[i].room) {
                user_index = i;
                break;
            }
        }

        if (user_index == -1) {
            cout << "Пользователь с такими данными не найден.\n";
            return;
        }

        if (cards[user_index].serv.empty()) {
            cout << "У отдыхающего " << fam << " " << name << " нет активных записей.\n";
            return;
        }

        cout << "\n--- Список текущих записей отдыхающего ---\n";
        for (int i = 0; i < cards[user_index].serv.size(); ++i) {
            cout << "[" << i + 1 << "] " << cards[user_index].serv[i].selected_service 
                 << " (" << cards[user_index].serv[i].date << " в " << cards[user_index].serv[i].selected_time << ")\n";
        }
        cout << "[0] Отмена (вернуться назад)\n";

        int choice;
        cout << "\nВыберите номер записи для удаления: ";
        while (!(cin >> choice) || choice < 0 || choice > cards[user_index].serv.size()) {
            cout << "Неверный ввод. Выберите корректный номер: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 0) {
            cout << "Отмена операции.\n";
            return;
        }

        string deleted_name = cards[user_index].serv[choice - 1].selected_service;
        cards[user_index].serv.erase(cards[user_index].serv.begin() + (choice - 1));

        cout << "\nЗапись на процедуру \"" << deleted_name << "\" успешно отменена!\n";
    }

    void emp_account() {
        while (true) {
            cout << "----------ЛИЧНЫЙ КАБИНЕТ СОТРУДНИКА----------\n";
            cout << "Логин сотрудника: " << empEmail << endl << endl;
            cout << "[1] Записать отдыхающего на приём\n";
            cout << "[2] Отменить приём у отдыхающего\n";
            cout << "[0] Выйти\n";
            int menu;
            cin >> menu;
            switch (menu) {
                case 1:
                    add_srv();
                    break;
                case 2:
                    cancel_srv();
                    break;
                case 0:
                    return;
                default:
                    cout << "Неверный пункт меню!\n";
                    break;
            }
        }
    }

    void emplogin() {
        string mail;
        string pas;
        cout << "Введите email сотрудника: \n";
        cin >> mail;
        cout << "Введите пароль сотрудника: \n";
        cin >> pas;
        if (mail == empEmail && pas == empPas) {
            cout << "Вход выполнен успешно!\n\n";
            emp_account();
        }
        else {
            cout << "Неправильный email или пароль\n";
        }
    }
};

int main() {
    Registry MyReg;
    bool f = true;
    do {
        cout << "----------МЕНЮ-----------\n";
        cout << "[1] Зарегистрироваться как отдыхающий\n";
        cout << "[2] Войти как отдыхающий\n";
        cout << "[3] Войти как сотрудник\n";
        cout << "[0] Выйти из программы\n";
        int menu;
        if (!(cin >> menu)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (menu) {
            case 1:
                MyReg.registration();
                break;
            case 2:
                MyReg.login();
                break;
            case 3:
                MyReg.emplogin();
                break;
            case 0:
                f = false;
                break;
            default:
                cout << "Неверный ввод!\n";
                break;
        }

    } while (f);

    return 0;
}