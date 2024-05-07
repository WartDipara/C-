
class Login_Success : Login // div
{
public:
    int service_n; // function wanna
    void getIdentity(int identity)
    {
        _identity = identity;
    }
    void displayBasicFunctions()
    {
        if (_identity == 0)
        {
            cout << "Welcome back, administrator!" << endl;
            cout << "1.Add admin-user" << endl;
            cout << "2.Delete admin-user" << endl;
            cout << "3.List of arrears" << endl;
            cout << "4.Delete user" << endl;
            cout << "5.View students" << endl;
            cout << "6.View teachers" << endl;
            cout << "7.View all" << endl;
            cout << "8.Search" << endl;
            cout << "9.Exit" << endl;
            cout << endl;
            cout << "What can I help you?:";
            cin >> service_n;
            selectBranch(_identity);
            return;
        }
        if (_identity == 1)
            cout << "Welcome back, student!" << endl;
        if (_identity == 2)
            cout << "Welcome back, teacher!" << endl;
        cout << "1.My water & electricity bill" << endl;
        cout << "2.Wallet" << endl;
        cout << "3.Exit" << endl;
        cout << endl;
        cout << "What can I help you?:";
        cin >> service_n;
        selectBranch(_identity);
    }
    void selectBranch(int identity)
    {
        if (identity == 0)
            ADM_section(service_n);
        else
            USR_section(service_n);
    }
    void initGroup()
    {
        linkGroup();
    }
    void dispA()
    {
        displayALL();
    }

private:
    int _identity;
    vector<Administrator> AdminMembers;
    vector<Student> StudentMembers;
    vector<Teacher> TeacherMembers;
    void linkGroup() // trans login vector materials->Member
    {
        for (const auto &admin : accounts_administrator) // push admin
        {
            Administrator new_admin(admin.getNickname(), admin.getAge(), admin.getCds(), admin.getUsername());
            AdminMembers.push_back(new_admin);
        }
        for (const auto &stu : accounts_students) // push stu
        {
            Student new_student(stu.getNickname(), stu.getAge(), stu.getCds(), stu.getUsername(), 0.0, 0.0); // new student
            StudentMembers.push_back(new_student);
        }
        for (const auto &tec : accounts_teachers) // push tec
        {
            Teacher new_teacher(tec.getNickname(), tec.getAge(), tec.getCds(), tec.getUsername(), 0.0, 0.0);
            TeacherMembers.push_back(new_teacher);
        }
    }
    void ADM_section(int service)
    {
        switch (service)
        {
        case 1:
            addAdmin();
            break;
        case 2:
            deleteAdmin();
            break;
        case 3:
            // find
            ListArrears();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            viewStu();
            break;
        case 6:
            viewTec();
            break;
        case 7:
            viewAll();
            break;
        case 8:
            searchKey();
            break;
        case 9:
            system("cls");
            cout << "See you next time" << endl;
            exit(1);
        default:
            cout << "Error input" << endl;
            displayBasicFunctions();
        }
    }
    void addAdmin()
    {
        string add_temp_nickname;
        int add_temp_age;
        string add_temp_id;
        cout << "Please enter your name:";
        getline(cin, add_temp_nickname);
        cout << "Please enter your age:";
        cin >> add_temp_age;
        cout << "Please enter your id:";
        getline(cin, add_temp_id);

        Administrator new_admin(add_temp_nickname, add_temp_age, "admin", add_temp_id, 0.0, 0.0);
        AdminMembers.push_back(new_admin);
        cout << "Finish!!" << endl;
    }
    void deleteAdmin()
    {
        if (AdminMembers.size() == 1)
        {
            cout << "Only one administrator in system!" << endl;
        }
        else
        {
            for (const auto &admin : AdminMembers) // find members
            {
                cout << admin.name << endl;
            }
            string delete_name;
            cout << "Enter a name which you wanna delete:";
            getline(cin, delete_name);
            // delete
            for (auto i = AdminMembers.begin(); i != AdminMembers.end();)
            {
                if ((*i).name == delete_name)
                    i = AdminMembers.erase(i);
                else
                {
                    ++i;
                }
            }

            for (auto &member : AdminMembers) // check members
            {
                cout << member.name << endl;
            }
            cout << "Finish!" << endl;
        }
    }
    void ListArrears()
    {
        // find
        for (auto &stu : StudentMembers)
        {
            if ((stu.used_electric < 0) || (stu.used_water < 0))
            {
                cout << stu.name << endl;
            }
        }
        for (auto &tec : TeacherMembers)
        {
            if ((tec.used_electric < 0) || (tec.used_water < 0))
            {
                cout << tec.name << endl;
            }
        }
    }
    void deleteUser()
    {
        cout << "if delete User-student enter '1' " << endl;
        cout << "if delete User-teacher enter '2' " << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            for (auto &stu : StudentMembers)
            {
                cout << stu.name << endl;
            }
            string delete_stu;
            cout << "Enter the name you wanna delete:" << endl;
            cin.ignore();
            cin >> delete_stu;
            getchar();
            for (auto i = StudentMembers.begin(); i < StudentMembers.end();)
            {
                if ((*i).name == delete_stu)
                    i = StudentMembers.erase(i);
                else
                    ++i;
            }
            cout << "Finish!" << endl;
            return;
        }
        else if (n == 2)
        {
            for (auto &tec : TeacherMembers)
            {
                cout << tec.name << endl;
            }
            string delete_tec;
            cout << "Enter the name you wanna delete:";
            cin.ignore();
            cin >> delete_tec;
            getchar();
            for (auto i = TeacherMembers.begin(); i < TeacherMembers.end();)
            {
                if ((*i).name == delete_tec)
                    i = TeacherMembers.erase(i);
                else
                    ++i;
            }
            cout << "Finish!" << endl;
            return;
        }
        else
        {
            cout << "Error nums enter" << endl;
            return;
        }
    }

    void viewStu()
    {
        for (const auto &stu : StudentMembers)
        {
            cout << "student-name:" << stu.name << " age:" << stu.age << " water-used:" << stu.used_water << " electric-used:" << stu.used_electric << endl;
        }
    }

    void viewTec()
    {
        for (const auto &tec : TeacherMembers)
        {
            cout << "teacher-name:" << tec.name << " age:" << tec.age << " water-used:" << tec.used_water << " electric-used:" << tec.used_electric << endl;
        }
    }

    void viewAll()
    {
        cout << "Administrator Info-list" << endl;
        for (auto &admin : AdminMembers)
        {
            admin.displayInfo();
        }
        cout << "Student Info-list:" << endl;
        for (auto &stu : StudentMembers)
        {
            stu.displayInfo();
        }
        cout << "Teacher Info-list" << endl;
        for (auto &tec : TeacherMembers)
        {
            tec.displayInfo();
        }
    }
    void searchKey()
    {
        string key;
        cout << "Enter the name or ID to search:";
        getchar();
        getline(cin, key);
        for (const auto &admin : AdminMembers)
        {
            if (admin.name == key)
                cout << "admin-name:" << admin.name << " age:" << admin.age << endl;
            else if (admin.getAdminID() == key)
                cout << "admin-name:" << admin.name << " age:" << admin.age << endl;
        }
        // stu list
        for (const auto &stu : StudentMembers)
        {
            if (stu.name == key)
                cout << "student-name:" << stu.name << " age:" << stu.age << " water-used:" << stu.used_water << " electric-used:" << stu.used_electric << endl;
            else if (stu.getStuID() == key)
                cout << "student-name:" << stu.name << " age:" << stu.age << " water-used:" << stu.used_water << " electric-used:" << stu.used_electric << endl;
        }
        // tec list
        for (const auto &tec : TeacherMembers)
        {
            if (tec.name == key)
                cout << "teacher-name:" << tec.name << " age:" << tec.age << " water-used:" << tec.used_water << " electric-used:" << tec.used_electric << endl;
            else if (tec.getTecID() == key)
                cout << "teacher-name:" << tec.name << " age:" << tec.age << " water-used:" << tec.used_water << " electric-used:" << tec.used_electric << endl;
        }
    }
    void USR_section(int service)
    {
        return;
    }

    void displayALL()
    {
        if (AdminMembers.empty() == 0)
        {
            cout << "empty admin" << endl;
        }
        if (TeacherMembers.empty() == 0)
        {
            cout << "empty tec" << endl;
        }
        if (StudentMembers.empty() == 0)
        {
            cout << "empty stu" << endl;
        }
        for (auto &it : AdminMembers)
        {
            it.displayInfo();
            cout << endl;
        }
        for (auto &it : StudentMembers)
        {
            it.displayInfo();
            cout << endl;
        }
        for (auto &it : TeacherMembers)
        {
            it.displayInfo();
            cout << endl;
        }
    }
};