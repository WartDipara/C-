#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Member
{
public:
    string name;
    int age;
    double used_electric;
    double used_water;
    void displayInfo()
    {
        cout << "name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "electric:" << used_electric << endl;
        cout << "water:" << used_water << endl;
    }
};

class Student : public Member
{
public:
    Student(){}; // default
    Student(string name, int age, string cls, string id, double electric = 30, double water = 50, double money = 0)
    {
        this->name = name;
        this->age = age;
        this->student_class = cls;
        this->student_ID = id;
        this->used_electric = electric;
        this->used_water = water;
        this->money = money;
    }

    void displayInfo()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Student-ID:" << student_ID << endl;
        cout << "Student-class:" << student_class << endl;
        cout << "Electric-used:" << used_electric << endl;
        cout << "Water-used:" << used_water << endl;
    }

    string getStuID() const
    {
        return student_ID;
    }
    string getStuCls() const
    {
        return student_class;
    }
    double getMoney() const
    {
        return money;
    }
    void addMoney(double cash)
    {
        this->money += cash;
    }
    void changeCds(string newCds)
    {
        this->student_class=newCds;
    }
private:
    string student_class;
    string student_ID;
    double money;
};

class Teacher : public Member
{
public:
    Teacher(){}; // default
    Teacher(string name, int age, string dept, string id, double electric = 0, double water = 0, double money = 30)
    {
        this->name = name;
        this->age = age;
        this->teacher_department = dept;
        this->teacher_ID = id;
        this->used_electric = electric;
        this->used_water = water;
        this->money = money;
    }

    void displayInfo()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Teacher-ID:" << teacher_ID << endl;
        cout << "Teacher-department:" << teacher_department << endl;
        cout << "Electric-used:" << used_electric << endl;
        cout << "Water-used:" << used_water << endl;
    }
    string getTecID() const
    {
        return teacher_ID;
    }
    string getTecCls() const
    {
        return teacher_department;
    }
    double getMoney() const
    {
        return money;
    }
    void addMoney(double cash)
    {
        this->money += cash;
    }
    void changeCds(string newCds)
    {
        this->teacher_department=newCds;
    }
private:
    string teacher_department;
    string teacher_ID;
    double money;
};

class Administrator : public Member
{
public:
    Administrator(){}; // default
    Administrator(string name, int age, string dept, string id, double electric = 30, double water = 10, double money = 9999)
    {
        this->name = name;
        this->age = age;
        this->admin_department = dept;
        this->admin_ID = id;
        this->used_electric = electric;
        this->used_water = water;
        this->money = money;
    }

    void displayInfo()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Teacher-ID:" << admin_ID << endl;
        cout << "Department:" << admin_department << endl;
    }
    string getAdminID() const
    {
        return admin_ID;
    }
    string getAdminCls() const
    {
        return admin_department;
    }

private:
    string admin_department;
    string admin_ID;
    double money;
};
class Account_Management
{
public:
    Account_Management(const string &username, const string &password, const string &nickname, const int &age, const string &cds) // cds=class or department
    {
        this->username = username;
        this->password = password;
        this->nickname = nickname;
        this->age = age;
        this->cds = cds;
    }
    bool check(const string &username, const string &password) const
    {
        return this->username == username && this->password == password;
    }
    string getUsername() const
    {
        return username;
    }
    string getPassword() const
    {
        return password;
    }

    string getNickname() const
    {
        return nickname;
    }

    int getAge() const
    {
        return age;
    }

    string getCds() const
    {
        return cds;
    }

    void changePwd(string newPWD)
    {
        this->password = newPWD;
    }

private:
    string username;
    string password;
    int age;
    string nickname;
    string cds;
};

class Login
{
public:
    int login_check;
    char user_id[13];
    char user_pw[13];
    int len_userID;
    int len_userPW;
    vector<Account_Management> accounts_students; // DATA SAVE
    vector<Account_Management> accounts_teachers;
    vector<Account_Management> accounts_administrator;

    void index()
    {
        // Index part
        cout << "--->>-Welcome to W&E System-<<---" << endl;
        while (1)
        {
            cout << "->Please Login&Register<-" << endl;
            cout << "1.Admin        2.User-student        3.User-teacher        4.Register        5.Exit" << endl;
            cin >> login_check;
            if (login_check == 1 || login_check == 2 || login_check == 3 || login_check == 4)
            {
                system("cls");
                break;
            }
            if (login_check == 5)
            {
                cout << "See you next time" << endl;
                exit(1);
            }
        }
        login();
    }
    void displayAccounts() const
    {
        cout << "-------------------------" << endl;
        cout << "Administrator List" << endl;
        cout << "-------------------------" << endl;
        for (const auto &account : accounts_administrator)
        {
            cout << "Username: " << account.getUsername() << endl;
            cout << "Password: " << account.getPassword() << endl;
            cout << "Nickname:" << account.getNickname() << endl;
            cout << "Age:" << account.getAge() << endl;
            cout << "Class/Department:" << account.getCds() << endl;
            cout << endl;
        }
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "Student List" << endl;
        cout << "-------------------------" << endl;
        for (const auto &account : accounts_students)
        {
            cout << "Username: " << account.getUsername() << endl;
            cout << "Password: " << account.getPassword() << endl;
            cout << "Nickname:" << account.getNickname() << endl;
            cout << "Age:" << account.getAge() << endl;
            cout << "Class/Department:" << account.getCds() << endl;
            cout << endl;
        }
        cout << endl;
        cout << "-------------------------" << endl;
        cout << "Teacher List" << endl;
        cout << "-------------------------" << endl;
        for (const auto &account : accounts_teachers)
        {
            cout << "Username: " << account.getUsername() << endl;
            cout << "Password: " << account.getPassword() << endl;
            cout << "Nickname:" << account.getNickname() << endl;
            cout << "Age:" << account.getAge() << endl;
            cout << "Class/Department:" << account.getCds() << endl;
            cout << endl;
        }
    }
    
    void Build() // data->member
    {
        for (auto it = accounts_administrator.begin(); it < accounts_administrator.end(); ++it) // ok
        {
            Mana_Adm.push_back(Administrator((*it).getNickname(), (*it).getAge(), (*it).getCds(), (*it).getUsername()));
        }
        // if(!Mana_Adm.empty())
        // cout<<"success"<<endl;
        for (auto it = accounts_students.begin(); it < accounts_students.end(); ++it) // ok
        {
            Mana_Stu.push_back(Student((*it).getNickname(), (*it).getAge(), (*it).getCds(), (*it).getUsername()));
        }
        for (auto it = accounts_teachers.begin(); it < accounts_teachers.end(); ++it) // ok
        {
            Mana_Tec.push_back(Teacher((*it).getNickname(), (*it).getAge(), (*it).getCds(), (*it).getUsername()));
        }
    }

    void index_login()
    {
        int n;
        if (card_login == 0) // admin part
        {
            cout << "==============Welcome back, administrator!============" << endl;
            cout << "=================1.Add admin-user=====================" << endl;
            cout << "=================2.Delete admin-user==================" << endl;
            cout << "=================3.List of arrears====================" << endl;
            cout << "=================4.Delete user========================" << endl;
            cout << "=================5.View students======================" << endl;
            cout << "=================6.View teachers======================" << endl;
            cout << "=================7.View all===========================" << endl;
            cout << "=================8.Search=============================" << endl;
            cout << "=================9.Edit===============================" << endl;
            cout << "=================0.Logout=============================" << endl;
            cout << endl;
            cout << "What can I help you?(enter a number):";
            cin >> n;
            getchar();
            switch (n)
            {
            case 1:
                ADM_f1();
                system("cls");
                break;
            case 2:
                ADM_f2();
                system("cls");
                break;
            case 3:
                ADM_f3();
                system("cls");
                break;
            case 4:
                ADM_f4();
                system("cls");
                break;
            case 5:
                ADM_f5();
                system("cls");
                break;
            case 6:
                ADM_f6();
                system("cls");
                break;
            case 7:
                ADM_f7();
                system("cls");
                break;
            case 8:
                ADM_f8();
                system("cls");
                break;
            case 9:
                ADM_f9();
                system("cls");
                break;
            default:
                ADM_f10();
                system("cls");
                break;
            }
            if (n != 0)
            {
                index_login();
            }
        }
        if (card_login == 1 || card_login == 2)
        {
            cout << "===============Welcome back!==========================" << endl;
            cout << "===============1.My water & electricity bill==========" << endl;
            cout << "===============2.Wallet===============================" << endl;
            cout << "===============3.Pay==================================" << endl;
            cout << "===============4.Change Password======================" << endl;
            cout << "===============5.Logout===============================" << endl;
            cout << endl;
            cout << "What can I help you?(enter a number):";
            cin >> n;
            getchar();
            switch (n)
            {
            case 1:
                USR_f1();
                system("cls");
                break;
            case 2:
                USR_f2();
                system("cls");
                break;
            case 3:
                USR_f3();
                system("cls");
                break;
            case 4:
                USR_f4();
                system("cls");
                break;
            case 5: // out exec
                break;
            default:
                cout << "Error input" << endl;
                index_login();
            }
            if (n != 5)
            {
                index_login();
            }
            USR_f5();
            system("cls");
        }
        index();
    }

    void transTxt() // save to txt
    {
        ofstream f("test.txt");
        f << "---------Admin-List---------" << endl;
        for (auto &it : Mana_Adm)
        {
            f << "Name: " << it.name << endl;
            f << "Age: " << it.age << endl;
            f << "ID: " << it.getAdminID() << endl;
            f << endl;
        }
        f << "---------Stu-List---------" << endl;
        for (auto &it : Mana_Stu)
        {
            f << "Name: " << it.name << endl;
            f << "Age: " << it.age << endl;
            f << "ID: " << it.getStuID() << endl;
            f << endl;
        }
        f << "---------Tec-List---------" << endl;
        for (auto &it : Mana_Tec)
        {
            f << "Name: " << it.name << endl;
            f << "Age: " << it.age << endl;
            f << "ID: " << it.getTecID() << endl;
            f << endl;
        }
    }

private:
    vector<Administrator> Mana_Adm;
    vector<Student> Mana_Stu;
    vector<Teacher> Mana_Tec;
    int card_login = 0; // identity 0admin 1stu 2teach
    void login()
    {
        switch (login_check)
        {
        case 1:
            cout << "Admin" << endl;
            Login_Branch(login_check);
            break;
        case 2:
            cout << "User-student" << endl;
            Login_Branch(login_check);
            break;
        case 3:
            cout << "User-teacher" << endl;
            Login_Branch(login_check);
            break;
        case 4:
            cout << "Register" << endl;
            Add_Account(login_check);
        default:
            index();
            break;
        }
    }
    void Login_Branch(int login_check)
    {
        char *id_login = new char[13]();
        int len_id;
        char *pwd_login = new char[13]();
        int len_pwd;

        if (login_check == 2)
            cout << "Student Login" << endl;
        if (login_check == 3)
            cout << "Teacher Login" << endl;

        // id
        cout << "ID:";
        cin.ignore();
        Login_Info_get(id_login, len_id);
        strcpy(user_id, id_login); // send to public
        len_userID = len_id;

        // pw
        cout << "PW:";
        Login_Info_get(pwd_login, len_pwd);
        strcpy(user_pw, pwd_login);
        len_userPW = len_pwd;

        // check is_valid
        if (login_check == 1) // admin part
        {
            bool login_is_valid = false;
            for (const auto &account : accounts_administrator)
            {
                if (account.check(user_id, user_pw))
                {
                    login_is_valid = true;
                    break;
                }
            }
            if (login_is_valid)
            {
                cout << endl;
                cout << "Login success!" << endl;
                card_login = 0;
                system("cls");
                index_login();
                cout << endl;
            }
            else
            {
                cout << "ID or Password wrong!" << endl;
                cout << "Try again" << endl;
                index();
            }
        }
        if (login_check == 2) // student part
        {
            bool login_is_valid = false;
            for (const auto &account : accounts_students)
            {
                if (account.check(user_id, user_pw))
                {
                    login_is_valid = true;
                    break;
                }
            }

            if (login_is_valid)
            {
                cout << endl;
                cout << "Login success!" << endl;
                card_login = 1;
                system("cls");
                index_login();
                cout << endl;
            }
            else
            {
                cout << "ID or Password wrong!" << endl;
                cout << "Try again" << endl;
                index();
            }
        }
        if (login_check == 3) // teacher part
        {
            bool login_is_valid = false;
            for (const auto &account : accounts_teachers)
            {
                if (account.check(user_id, user_pw))
                {
                    login_is_valid = true;
                    break;
                }
            }

            if (login_is_valid)
            {
                cout << endl;
                cout << "Login success!" << endl;
                card_login = 2;
                index_login();
                cout << endl;
            }
            else
            {
                cout << "ID or Password wrong!" << endl;
                cout << "Try again" << endl;
                index();
            }
        }
        delete[] id_login;
        delete[] pwd_login;
        id_login = pwd_login = nullptr;
    }
    void Add_Account(int login_check)
    {
        char *new_id_login = new char[13]();
        char *tmp_pwd = new char[13]();
        char *new_pwd_login = new char[13]();
        int flag;

        cout << "Input '1' to create User-Student or input '2' to create User-Teacher" << endl; // branch
        while (1)
        {
            cin >> flag;
            getchar();
            if (flag > 2 || flag < 1)
            {
                cout << "invalid input" << endl;
                continue;
            }
            if (flag == 2 || flag == 1)
                break;
        }

        cout << "newID(Limit:13):";
        cin.getline(new_id_login, 13, '\n');
        for(auto&it:accounts_administrator)
        {
            if(it.getUsername()==new_id_login)
            {
                cout << endl;
                cout << "Account already exist" << endl;
                cout << endl;
                exit(1);
            }
        }
        for(auto&it:accounts_students)
        {
            if(it.getUsername()==new_id_login)
            {
                cout << endl;
                cout << "Account already exist" << endl;
                cout << endl;
                exit(1);
            }
        }
         for(auto&it:accounts_teachers)
        {
            if(it.getUsername()==new_id_login)
            {
                cout << endl;
                cout << "Account already exist" << endl;
                cout << endl;
                exit(1);
            }
        }
        cout << "newPassword(Limit:13):";
        cin.getline(tmp_pwd, 13, '\n');
        cout << "Password confirm:";
        cin.getline(new_pwd_login, 13, '\n');
        // check_is_valid?

        // send to AM
        // success register, addition materials ↓
        string temp_nickname;
        int temp_age;
        string temp_cds; // class or department
        // id -> login username
        if (flag == 1)
        {
            if (strcmp(tmp_pwd, new_pwd_login) == 0)
            {
                cout << "-----------Please enter the personal information------------" << endl;
                cout << "Your name:";
                cin >> temp_nickname;
                cout << "Your age:";
                cin >> temp_age;
                cout << "Your class/department:";
                cin >> temp_cds;

                accounts_students.push_back(Account_Management(new_id_login, new_pwd_login, temp_nickname, temp_age, temp_cds));
                Mana_Stu.push_back(Student(temp_nickname, temp_age, temp_cds, new_id_login));
            }
            else
            {
                cout << "Not the same password,please try again" << endl;
                index();
            }
        }
        if (flag == 2)
        {

            // send to AM
            if (strcmp(tmp_pwd, new_pwd_login) == 0)
            {
                cout << "-----------Please enter the personal information------------" << endl;
                cout << "Your name:";
                cin >> temp_nickname;
                cout << "Your age:";
                cin >> temp_age;
                cout << "Your class/department:";
                cin >> temp_cds;

                accounts_teachers.push_back(Account_Management(new_id_login, new_pwd_login, temp_nickname, temp_age, temp_cds));
                Mana_Tec.push_back(Teacher(temp_nickname, temp_age, temp_cds, new_id_login));
            }
            else
            {
                cout << "Not the same password,please try again" << endl;
                index();
            }
        }
        transTxt();
        delete[] tmp_pwd;
        delete[] new_id_login;
        delete[] new_pwd_login;
        tmp_pwd = new_id_login = new_pwd_login = nullptr;
    }
    void Login_Info_get(char *arr, int &len)
    {
        cin.getline(arr, 13, '\n');
        len = strlen(arr);
    }

    // switch part
    void ADM_f1() // Add admin-user ok
    {
        string add_temp_nickname;
        int add_temp_age;
        string add_temp_id;
        string add_temp_pwd;
        cout << "Please enter your name:";
        getline(cin, add_temp_nickname);
        cout << "Please enter your age:";
        cin >> add_temp_age;
        getchar();
        cout << "Please enter your id:";
        getline(cin, add_temp_id);
        for(auto&it:Mana_Adm)
        {
            if(it.getAdminID()==add_temp_id)
                {
                    cout<<"Error: ID already exist"<<endl;
                    cout<<endl;
                    index_login();
                }
        }
        cout<<"Please enter your pwd: ";
        getline(cin,add_temp_pwd);

        Mana_Adm.push_back(Administrator(add_temp_nickname, add_temp_age, "admin", add_temp_id));
        accounts_administrator.push_back(Account_Management(add_temp_id,add_temp_pwd,add_temp_nickname,add_temp_age,"admin"));
        cout << "============Now admin-list============" << endl;
        for (auto &it : Mana_Adm)
        {
            it.displayInfo();
            cout << endl;
        }
        transTxt();
        cout << "Finish!" << endl;
    }
    void ADM_f2() // delete admin ok
    {
        string d_id;
        cout << "==========Find the ID you wanna delete===========" << endl;
        for (auto &admin : Mana_Adm)
            cout << admin.getAdminID() << endl;
        cout << "Enter ID here:";
        getline(cin, d_id);
        cout << "Your target is: " << d_id << endl;
        for (auto it = Mana_Adm.begin(); it < Mana_Adm.end();)
        {
            if ((*it).getAdminID() == d_id)
            {
                it = Mana_Adm.erase(it);
            }
            else
                ++it;
        }

        cout << "------------After delete list------------" << endl;
        for (auto &admin : Mana_Adm)
            cout << admin.getAdminID() << endl;
        for (auto &stu : Mana_Stu)
            cout << stu.getStuID() << endl;
        for (auto &tec : Mana_Tec)
            cout << tec.getTecID() << endl;
        
        transTxt();
        cout << "FInish!!" << endl;
    }
    void ADM_f3() // ListArrears ok
    {
        cout << "----------List of arrears(name)----------" << endl;
        for (auto it = Mana_Stu.begin(); it < Mana_Stu.end();)
        {
            if ((((*it).used_electric - 15) * 0.5 + ((*it).used_water - 10) * 0.7) > 0)
            {
                cout << (*it).name << " energy bill: $" << ((*it).used_electric - 15) * 0.5 + ((*it).used_water - 10) * 0.7 << endl;
                ++it;
            }
            else
                ++it;
        }
        for (auto it = Mana_Tec.begin(); it < Mana_Tec.end();)
        {
            if ((((*it).used_electric - 15) * 0.5 + ((*it).used_water - 10) * 0.7) > 0)
            {
                cout << (*it).name << " energy bill: $" << ((*it).used_electric - 15) * 0.5 + ((*it).used_water - 10) * 0.7 << endl;
                ++it;
            }
            else
                ++it;
        }
        cout << endl;
    }
    void ADM_f4() // delete User ok
    {
        int n;
        string d_id;
        cout << "if delete User-student enter '1' " << endl;
        cout << "if delete User-teacher enter '2' " << endl;
        cin >> n;
        getchar();
        if (n < 1 || n > 2)
        {
            cout << "Error input" << endl;
            return;
        }
        if (n == 1)
        {
            cout << "--------Student list---------" << endl;
            for (auto &stu : Mana_Stu)
                cout << stu.getStuID() << endl;
            cout << "Enter ID to delete" << endl;
            getline(cin, d_id);
            cout << "Your target is: " << d_id << endl;
            for (auto it = Mana_Stu.begin(); it < Mana_Stu.end();)
            {
                if ((*it).getStuID() == d_id)
                {
                    it = Mana_Stu.erase(it);
                }
                else
                    ++it;
            }
            cout << "------------After delete list------------" << endl;
            for (auto &admin : Mana_Adm)
                cout << admin.getAdminID() << endl;
            for (auto &stu : Mana_Stu)
                cout << stu.getStuID() << endl;
            for (auto &tec : Mana_Tec)
                cout << tec.getTecID() << endl;
            
            transTxt();
            cout << "FInish!!" << endl;
        }
        if (n == 2)
        {
            cout << "--------Teacher list---------" << endl;
            for (auto &tec : Mana_Tec)
                cout << tec.getTecID() << endl;
            cout << "Enter ID to delete" << endl;
            getline(cin, d_id);
            cout << "Your target is: " << d_id << endl;
            for (auto it = Mana_Tec.begin(); it < Mana_Tec.end();)
            {
                if ((*it).getTecID() == d_id)
                {
                    it = Mana_Tec.erase(it);
                }
                else
                    ++it;
            }
            cout << "------------After delete list------------" << endl;
            for (auto &admin : Mana_Adm)
                cout << admin.getAdminID() << endl;
            for (auto &stu : Mana_Stu)
                cout << stu.getStuID() << endl;
            for (auto &tec : Mana_Tec)
                cout << tec.getTecID() << endl;
            
            transTxt();
            cout << "FInish!!" << endl;
        }
    }
    void ADM_f5() // view stu ok
    {
        cout << "-----------Student List------------" << endl;
        for (auto &stu : Mana_Stu)
        {
            stu.displayInfo();
            cout << endl;
        }
        cout << endl;
    }
    void ADM_f6() // view Tec ok
    {
        cout << "-----------Teacher List------------" << endl;
        for (auto &tec : Mana_Tec)
        {
            tec.displayInfo();
            cout << endl;
        }
        cout << endl;
    }
    void ADM_f7() // viewAll ok
    {
        cout << "-----------Admin List------------" << endl;
        for (auto &it : Mana_Adm)
        {
            it.displayInfo();
            cout << endl;
        }
        cout << endl;
        ADM_f5();
        ADM_f6();
    }
    void ADM_f8() // searchKey ok
    {
        string key;
        cout << "Enter the name or ID to search:";
        getline(cin, key);
        for (const auto &admin : Mana_Adm)
        {
            if (admin.name == key)
                cout << "admin-name:" << admin.name << " age:" << admin.age << endl;
            else if (admin.getAdminID() == key)
                cout << "admin-name:" << admin.name << " age:" << admin.age << endl;
        }

        // stu list
        for (const auto &stu : Mana_Stu)
        {
            if (stu.name == key)
                cout << "student-name:" << stu.name << " age:" << stu.age << " water-used:" << stu.used_water << " electric-used:" << stu.used_electric << endl;
            else if (stu.getStuID() == key)
                cout << "student-name:" << stu.name << " age:" << stu.age << " water-used:" << stu.used_water << " electric-used:" << stu.used_electric << endl;
        }

        // tec list
        for (const auto &tec : Mana_Tec)
        {
            if (tec.name == key)
                cout << "teacher-name:" << tec.name << " age:" << tec.age << " water-used:" << tec.used_water << " electric-used:" << tec.used_electric << endl;
            else if (tec.getTecID() == key)
                cout << "teacher-name:" << tec.name << " age:" << tec.age << " water-used:" << tec.used_water << " electric-used:" << tec.used_electric << endl;
        }
        cout<<endl;
    }
    void ADM_f9() //Edit
    {
        string key;

        string change_name;
        string change_cds;
        int change_age;
        double change_water;
        double change_elec;

        int n;
        ADM_f7();
        
        cout<<"Enter the ID to find person who you wanna change: ";
        getline(cin,key);
        
        cout<<"1.change name"<<endl;
        cout<<"2.change group"<<endl;
        cout<<"3.change age"<<endl;
        cout<<"4.change water-used"<<endl;
        cout<<"5.change electric-used"<<endl;

        cout<<"Enter which you wanna change: ";
        cin>>n;
        getchar();
        for(auto& it:Mana_Stu)
        {
            if(key==it.getStuID())
            {
                switch(n)
                {
                    case 1: //change name
                        cout<<"Enter a new name: ";
                        getline(cin,change_name);
                        it.name=change_name;
                        break;
                    case 2: //change group
                        cout<<"Enter a new group: ";
                        getline(cin,change_cds);
                        it.changeCds(change_cds);
                        break;
                    case 3://change age
                        cout<<"Enter a new age: ";
                        cin>>change_age;
                        getchar();
                        it.age=change_age;
                        break;
                    case 4://change water
                        cout<<"Change water-used: ";
                        cin>>change_water;
                        getchar();
                        it.used_water=change_water;
                        break;
                    case 5://change elec
                        cout<<"Change elec-used: ";
                        cin>>change_elec;
                        getchar();
                        it.used_electric=change_elec;
                        break;
                    default:
                        break;
                }
                transTxt();
                cout<<"Finish!"<<endl;
            }
        }
        for(auto& it:Mana_Tec)
        {
            if(key==it.getTecID())
            {
                 switch(n)
                {
                    case 1: //change name
                        cout<<"Enter a new name: ";
                        getline(cin,change_name);
                        it.name=change_name;
                        break;
                    case 2: //change group
                        cout<<"Enter a new group: ";
                        getline(cin,change_cds);
                        it.changeCds(change_cds);
                        break;
                    case 3://change age
                        cout<<"Enter a new age: ";
                        cin>>change_age;
                        getchar();
                        it.age=change_age;
                        break;
                    case 4://change water
                        cout<<"Change water-used: ";
                        cin>>change_water;
                        getchar();
                        it.used_water=change_water;
                        break;
                    case 5://change elec
                        cout<<"Change elec-used: ";
                        cin>>change_elec;
                        getchar();
                        it.used_electric=change_elec;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    void ADM_f10() // exit ok
    {
        cout << "Logout" << endl;
        return;
    }

    void USR_f1() // energy bill ok
    {
        double sum;
        for (auto &it : Mana_Stu)
        {
            if (it.getStuID() == user_id)
            {
                sum = it.used_water + it.used_electric;
                cout << "You need to pay: $" << sum << " in energy fee" << endl;
            }
        }
        for (auto &it : Mana_Tec)
        {
            if (it.getTecID() == user_id)
            {
                sum = it.used_water + it.used_electric;
                cout << "You need to pay: $" << sum << " in energy fee" << endl;
            }
        }
    }
    void USR_f2() // money ok
    {
        int t;
        double cash = 0;
        for (auto &it : Mana_Stu)
        {
            if (it.getStuID() == user_id)
            {
                cout << "Money: $" << it.getMoney() << endl;
                cout << "Enter '1' to top up your wallet" << endl;
                cout << "Enter '0' to continue" << endl;
                cin >> t;
                getchar();
                if (t == 1)
                {
                    cout << "Money:$";
                    cin >> cash;
                    getchar();
                    it.addMoney(cash);
                    cout << "Finish, now your money: $" << it.getMoney() << endl;
                }
                else
                    return;
            }
        }
        for (auto &it : Mana_Tec)
        {
            if (it.getTecID() == user_id)
            {
                cout << "Money: $" << it.getMoney() << endl;
                cout << "Enter '1' to top up your wallet" << endl;
                cout << "Enter '0' to continue" << endl;
                cin >> t;
                getchar();
                if (t == 1)
                {
                    cout << "Money:$";
                    cin >> cash;
                    getchar();
                    it.addMoney(cash);
                    cout << "Finish, now your money: $" << it.getMoney() << endl;
                }
                else
                    return;
            }
        }
    }
    void USR_f3() // pay
    {
        double need_pay;
        for (auto &it : Mana_Stu)
        {
            if (it.getStuID() == user_id)
            {
                need_pay = (it.used_electric - 15) * 0.5 + (it.used_water - 10) * 0.7;
                if (need_pay > 0)
                {
                    cout << "You need to pay: $" << need_pay << endl;
                    if (it.getMoney() >= need_pay)
                    {
                        cout << "Your bill have already paid" << endl;
                        it.addMoney((-1) * need_pay);
                        cout << "Balance: $" << it.getMoney() << endl;
                        // do clear energy bill
                        it.used_electric = 0;
                        it.used_water = 0;
                    }
                    if (it.getMoney() < need_pay)
                    {
                        cout << "Please check your balance, remember to pay your bill" << endl;
                        cout << "Balance: $" << it.getMoney() << endl;
                        cout<<endl;
                    }
                }
            }
        }
        for (auto &it : Mana_Tec)
        {
            if (it.getTecID() == user_id)
            {
                need_pay = (it.used_electric - 15) * 0.5 + (it.used_water - 10) * 0.7;
                if (need_pay > 0)
                {
                    cout << "You need to pay: $" << need_pay << endl;
                    if (it.getMoney() >= need_pay)
                    {
                        cout << "Your bill have already paid" << endl;
                        it.addMoney((-1) * need_pay);
                        cout << "Balance: $" << it.getMoney() << endl;
                        it.used_electric = 0;
                        it.used_water = 0;
                    }
                    if (it.getMoney() < need_pay)
                    {
                        cout << "Please check your balance, remember to pay your bill" << endl;
                        cout << "Balance: $" << it.getMoney() << endl;
                    }
                }
            }
        }
    }
    void USR_f4() // change shadow
    {
        string temp_pwd;
        for (auto &it : Mana_Stu) // stu
        {
            if (user_id == it.getStuID())
            {
                cout << "Enter current password:";
                getline(cin, temp_pwd);
                if (user_pw == temp_pwd)
                {
                    cout << "Enter your new Password:";
                    getline(cin, temp_pwd);
                    for (auto &it : accounts_students)
                    {
                        if (it.getUsername() == user_id) // primary key
                        {
                            it.changePwd(temp_pwd);
                            cout << "new password: " << it.getPassword() << endl;
                            cout << "Finish!" << endl;
                        }
                    }
                }
            }
        }
        for (auto &it : Mana_Tec) // stu
        {
            if (user_id == it.getTecID())
            {
                cout << "Enter current password:";
                getline(cin, temp_pwd);
                for (auto &it : accounts_teachers)
                {
                    if (it.getUsername() == user_id)
                    {
                        it.changePwd(temp_pwd);
                        cout << "new password: " << it.getPassword() << endl;
                        cout << "Finish!" << endl;
                    }
                }
            }
        }
        transTxt();
    }
    void USR_f5() // exit ok
    {
        cout << "Logout" << endl;
        return;
    }
};

void init_someAc(Login &A) //
{
    A.accounts_administrator.push_back(Account_Management("admin", "admin", "admin", 21, "admin"));
    A.accounts_students.push_back(Account_Management("s20234751", "tt45789", "joe", 19, "4A"));
    A.accounts_students.push_back(Account_Management("s20231714", "c1s5730", "ddd", 19, "4B"));
    A.accounts_teachers.push_back(Account_Management("t20157697", "nie455", "meta", 31, "sport"));
    A.accounts_teachers.push_back(Account_Management("t1997", "a71559721", "ana", 25, "sport"));
}

int main()
{
    int identity;
    Login login_used;
    init_someAc(login_used);
    login_used.Build(); // build member info
    login_used.transTxt();
    login_used.index();
    return 0;
}
