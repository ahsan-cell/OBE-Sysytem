#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<cstring>
using namespace std;
class address;
class Date;
class User;
class Evaluation;
class Course;
class Teacher;
class academicOfficer;
class Program;
class CLO;
class PLO;
class Question;
class Topic;

vector<Course*> Allcourses;
vector<Program*> Allprograms;
vector<CLO*> AllCLOS;
vector<PLO*>AllPLOS;

void printAllPrograms();
void printAllCourses();
void printAllCLOS();
void printAllPLOS();


#pragma warning(disable : 4996)
struct pc {
    Course* c;
    PLO* p;
    CLO* cl;
    Program* pro;
};


class address {
    char houseno[10];
    char street[20];
    char city[20];
    char completeAddress[70];
public:

    char* gethouseno()
    {
        return houseno;
    }

    char* getstreet()
    {
        return street;
    }


    char* getcity()
    {
        return city;
    }
    

    char* getcompleteAddress()
    {
        return completeAddress;
    }



    address(const char* houseno, const char* street, const char* city) {
        strcpy(this->houseno, houseno);
        strcpy(this->street, street);
        strcpy(this->city, city);
        char comma[2];
        comma[0] = ',';
        comma[1] = '\0';
        strcpy(completeAddress, this->houseno);
        strcat(completeAddress, comma);
        strcat(completeAddress, this->street);
        strcat(completeAddress, comma);
        strcat(completeAddress, this->city);
    }

    char* getAddress()
    {
        char* x = new char[70];
        strcpy(x, completeAddress);
        return x;
    }
    address& operator=(const address& a1) {
        strcpy(houseno, a1.houseno);
        strcpy(street, a1.street);
        strcpy(city, a1.street);
        strcpy(completeAddress, a1.completeAddress);
        return *this;
    }
    address(address& a1) {
        strcpy(houseno, a1.houseno);
        strcpy(street, a1.street);
        strcpy(city, a1.city);
        strcpy(completeAddress, a1.completeAddress);
    }


    void saveAddress(ofstream& f1) {
        //f1 << "*" << endl;
        f1 << houseno << endl;
        f1 << street << endl;
        f1 << city << endl;
        //f1 << "*" << endl;
    }

};



class Date {
    // Private Members
private:
    char month[20];
    char day[20];
    int date;
    int year;
    // Public Members
public:
    // Default Constructor


    char* getmonth()
    {
        return month;
    }

    char* getday()
    {
        return day;
    }

    int getdate()
    {
        return date;
    }

    int getyear()
    {
        return year;
    }

    void printDate(void) {
        std::cout << "DOB: "
            << this->month << " " << this->day << " "
            << this->date << " " << this->year;
    }


    Date(const char* m, const char d[], int dat, int y)
    {
        strcpy(month, m);
        strcpy(day, d);
        this->date = dat;
        this->year = y;
    }

    Date(Date& obj)
    {
        this->date = obj.date;
        this->year = obj.year;

        // int len1 = strlen(day);
         //len1++;

 //        int len2 = strlen(month);
   //      len2++;
        strcpy(day, obj.day);
        strcpy(month, obj.month);
    }
    // Destructor
    ~Date() {}

    void saveDate(ofstream & f1){
        f1 <<"*"<< endl;
        f1 << month << endl;
        f1 << day << endl;
        f1 << date << endl;
        f1 << year << endl;
        f1 <<"*"<< endl;
    }
};




class User
{
    char uName[20];
    int uId;
    Date* uDob; //compositon
    address* uAdd;//compositon
    char uGender[2];
public:
    User()
    {
        // uName = NULL;
        uId = -1;

    }
    User(const char name[20], int id, Date db, address add, const char gen[2])
    {

        strcpy(uName, name);
        uId = id;
        uAdd = new address(add);
        // uGender = new char[2];
        uDob = new Date(db);
        strcpy(uGender, gen);
        uGender[1] = '\0';
    }

    User(User& obj)
    {
        this->uId = obj.uId;
        strcpy(this->uName, obj.uName);
        uDob = new Date(*obj.uDob);
        uAdd = new address(*obj.uAdd);
        strcpy(uGender, obj.uGender);
        uGender[2] = '\0';

    }

    char* getname(){
        return uName;

    }
    int getuId(){
        return uId;
    }
    Date* getDate(){
        return uDob;
    }
    address* getadress(){
        return this->uAdd;
    }
    char* getgender(){
        return uGender;
    }
    //virtual void logIn(char* username, char* password) = 0;

    ~User()
    {

    }

    void savedate(ofstream &f1)
    {
        this->uDob->saveDate(f1);
    }

    void saveaddress(ofstream& f1)
    {
        this->uAdd->saveAddress(f1);
    }



};



class PLO
{
    int pId;
    char des[50];
    bool satisfied;
    int programID;
    //vector<CLO*> cloList;
   // vector<Program*>ProgramPLOBelongsTo;
public:

    void setprogramid(int x){
        programID = x;
    }
    int getprogramid(){
        return programID;
    }
    PLO()
    {
        programID = -1;
        pId = -1;
        satisfied = false;
    }
    PLO(int x, const char description[50])
    {
        pId = x;
        strcpy(des, description);
        satisfied = false;
        programID =- 1;

    }
    PLO(PLO& obj)
    {
        this->pId = obj.pId;
        strcpy(this->des, obj.des);
        satisfied = obj.satisfied;
        programID = obj.programID;

    }

    int getPLOid()
    {
        return pId;
    }

  /*  void addCLO(CLO* clo)
    {
        cloList.push_back(clo);
    }*/

  /*  void addProgram(Program* p)
    {
        ProgramPLOBelongsTo.push_back(p);
    }*/

    int getpId()
    {
        return pId;
    }
    char* getDes()
    {
        return des;
    }

    void updatePLO()
    {
        int choice = 0;
        cout << "Do you want to [1]edit the description, [2]edit id: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter the New description for the PLO: ";
            char newdes[20];
            cin.ignore();
            cin.getline(newdes, 20);
            strcpy(this->des, newdes);
            cout << "Completed"<<endl;
        }
        //    //for new CLO
        //    else if (strncmp(option, "No", 3) == 0 || strncmp(option, "no", 3) == 0)
        //    {
        //        char des[20];
        //        int id;
        //        cout << "Enter Description: ";
        //        cin.ignore();
        //        cin.getline(des, 50);
        //        cout << "Enter id: ";
        //        cin >> id;
        //        cin.ignore();
        //        CLO* c = new CLO(id, des);
        //        cloList.push_back(c);
        //        AllCLOS.push_back(c);
        //    }
        //}
        // 
        // 
        //else if (choice == 2)
        //{
        //    cout << "You are adding another program PLO belongs to";
        //    printAllPrograms();
        //    char name[20];
        //    cin.ignore();
        //    cin.getline(name, 20);
        //    int len = strlen(name);
        //    for (std::vector<Program*> ::iterator it = Allprograms.begin(); it != Allprograms.end(); ++it)
        //    {
        //        if (strncmp((*it)->getpName(), name, len) == 0)
        //        {
        //            ProgramPLOBelongsTo.push_back(*it);
        //          //  pc3->pro = (*it);
        //            cout << "Updated" << endl;
        //            break;
        //        }
        //    }

        else if (choice == 2)
        {
            int id;
            cout << "You are editing PLO id" << endl;
            cout << "Enter new id :";
            cin >> id;
            cout << endl;
            cin.ignore();
            this->pId = id;
            cout << "Updated the id" << endl;
        }
        
        else
        {
            cout << "invalid input";
        }
    }





    void savePLO(int programId)
    {
        this->programID = programId;
        ofstream f1;
        f1.open("PLO.txt", ios::app);
        if (f1.is_open())
        {
            f1 << programID << endl;
            f1 << pId << endl;
            f1 << des << endl;
            f1 << satisfied << endl;
            f1 << "#" << endl;;
        }
        f1.close();
      
    }

    //satisfyPLO()

};







class CLO
{
    int cId;
    char des[50];
    bool satisfied;
    int courseid;
    vector<PLO*> satisfiesPlo;
public:
    CLO()
    {
        cId = -1;
        satisfied = false;
        courseid = -1;
    }
    CLO(int x, const char description[50])
    {
        cId = x;
        strcpy(des, description);
        satisfied = false;
        courseid = -1;

    }
    CLO(CLO& obj)
    {
        this->cId = obj.cId;
        strcpy(this->des, obj.des);
        satisfied = obj.satisfied;
        courseid = obj.courseid;

    }

    int getcId()
    {
        return this->cId;
    }

    void addPLO(PLO* pointer)
    {
        satisfiesPlo.push_back(pointer);
    }

    void updateCLO() {
        int choice;
        cout << "Do you want to edit [1]Description, [2]PLO that this CLO satisfies:";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the New description for the PLO: ";
            char newdes[20];
            cin.ignore();
            cin.getline(newdes, 20);
            strcpy(this->des, newdes);
            cout << "Completed" << endl;
        }
        else if (choice == 2)
        {
            printAllPLOS();

            int id;
            cout << "Enter existing PLO id you want to add";
            cin >> id;
            cin.ignore();
            cout << endl;
            for (std::vector<PLO*> ::iterator it = AllPLOS.begin(); it != AllPLOS.end(); ++it)
            {
                if ((*it)->getpId() == id)
                {
                    satisfiesPlo.push_back(*it);
                }

            }
        }

    }


    char* getDes() {
        return des;
    }


    void setcourseid(int id)
    {
        this->courseid = id;
    }

    int getcourseid()
    {
        return this->courseid;
    }
     

    void saveCLO(int courseId)    
    {
        this->courseid = courseId;
        ofstream f1;
        f1.open("CLO.txt", ios::app);
        if (f1.is_open())
        {
            f1 << courseid << endl;
            f1 << cId << endl;
            f1 << des << endl;
            f1 << satisfied << endl;
            f1 << "/" << endl;
            for (std::vector<PLO*> ::iterator it = satisfiesPlo.begin(); it != satisfiesPlo.end(); ++it)
            {
                f1<< (*it)->getpId() << endl;
            }
            f1 << "/" << endl;
            f1 << "#"<<endl;

        }
        f1.close();

    }


    //satisfyCLO
};







class Course
{
    char cName[20];
    int creditHours;
    Course* preReq;
    vector<CLO*> cloList;
    int programID;
    int courseID;

public:

      void setprogramid(int x){
        programID = x;
    }
    int getprogramid(){
        return programID;
    }
    Course(int courseID,const char name[20], int ch, Course* preReq = NULL)
    {
        strcpy(cName, name);
        creditHours = ch;
        this->preReq = preReq;
        programID=-1;
        this->courseID = courseID;
    }
    Course(Course& obj)
    {
        strcpy(cName, obj.cName);
        creditHours = obj.creditHours;
        preReq = obj.preReq;
        programID = obj.programID;
    }

    ~Course()
    {

        preReq = NULL;
    }
    void addCLO(CLO* c)
    {
        cloList.push_back(c);
    }

    char* getcName() {
        return cName;
    }

    void updateCourse( pc *p) {
        int choice = 0;
        cout << "Do you want to [1]edit the name, [2]edit credit hourse, [3]add a clo, [4]add a pre req: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the New Course name: ";
            char newName[20];
            cin.ignore();
            cin.getline(newName, 20);
            strcpy(this->cName, newName);
            cout << "Completed" << endl;
        }
        else if (choice == 2) {
            //for existing course to be implemented or maybe not
            int ch;
            cout << "Enter credit hours: ";
            cin >> ch;
            cin.ignore();
            creditHours = ch;

        }
        else if (choice == 3) {
            //for existing course 

            char option[20];
            cout << "Do you want to add an existing CLO?";
            cin.ignore();
            cin.getline(option, 20);
            if (strncmp(option, "Yes", 3) == 0 || strncmp(option, "yes", 3) == 0)
            {
                printAllCLOS();

                int id;
                cout << "Enter existing CLO id you want to add";
                cin >> id;
                cout << endl;
                for (std::vector<CLO*> ::iterator it = AllCLOS.begin(); it != AllCLOS.end(); ++it)
                {
                    if ((*it)->getcId() == id)
                    {
                        cloList.push_back(*it);
                    }

                }
            }
            //for new course
            else if (strncmp(option, "No", 3) == 0 || strncmp(option, "no", 3) == 0)
            {
                char des[20];
                int id;
                cout << "Enter Description: ";
                //cin.ignore();
                cin.getline(des, 50);
                cout << "Enter id: ";
                cin >> id;
                cin.ignore();
                CLO* c = new CLO(id, des);
                c->setcourseid(courseID);
                p->cl = c;
                cloList.push_back(c);
                AllCLOS.push_back(c);
            }
        }
        else if (choice == 4)
        {
            cout << "add a pre req to be implemented";
            cout << "The available courses are: " << endl;
            printAllCourses();
            char name[20];
            cin.ignore();
            cin.getline(name, 20);
            int len = strlen(name);
            for (std::vector<Course*> ::iterator it = Allcourses.begin(); it != Allcourses.end(); ++it)
            {
                if (strncmp((*it)->getcName(), name,len) == 0)
                {
                    this->preReq = (*it);
                }

            }


        }
        else {
            cout << "invalid input";
        }

    }


    //void savePLO(int programId)
    //{
    //    this->programID = programId;

    //    ofstream f1;
    //    f1.open("PLO.txt", ios::app);
    //    if (f1.is_open())
    //    {
    //        f1 << programID << endl;
    //        f1 << pId << endl;
    //        f1 << des << endl;
    //        f1 << satisfied << endl;
    //    }
    //    f1.close();

    //}


    void savecourse(int programId)
    {
        this->programID = programId;
       
        ofstream f2;
        f2.open("course.txt", ios::app);
        if (f2.is_open())
        {
            f2 << programID << endl;
            f2 << this->courseID << endl;
            f2 << this->cName << endl;
            f2 << this->creditHours << endl;
            if (preReq == NULL)
                f2 << -1 << endl;
            else
              f2 << preReq->getcName()<< endl;      
            for (std::vector<CLO*> ::iterator it = cloList.begin(); it != cloList.end(); ++it)
            {
                (*it)->saveCLO(courseID);
            }

        }
        f2 << "#" << endl;
        f2.close();

    }




};














class Program
{
    int pId;
    char pName[20];
    vector<Course*> courses;//association
    vector<PLO*>ploList;//association

public:
    Program(int id,const char name[20])
    {
        pId = id;
        strcpy(pName, name);

    }
    Program(Program& obj)
    {
        this->pId = obj.pId;
        strcpy(pName, obj.pName);
    }
    void addCourse(Course* c)
    {
        courses.push_back(c);
    }
    void addPLO(PLO* plo) {
        ploList.push_back(plo);
    }
    void updateProgram(pc* pc1) {
        int choice = 0;
        cout << "Do you want to [1]edit the name, [2]add a course, [3]add a plo: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the New Program name: ";
            char newName[20];
            cin.ignore();
            cin.getline(newName, 20);
            strcpy(this->pName, newName);
            cout << "Completed" << endl;
        }
        else if (choice == 2)
        {
            //for existing course 

            char option[20];
            cout << "Do you want to add an existing course?";
            cin.ignore();
            cin.getline(option, 20);
            if (strncmp(option, "Yes", 3) == 0 || strncmp(option, "yes", 3) == 0)
            {
                printAllCourses();
                char name[20];
                cout << "Enter existing course name you want to add";
                cin.getline(name, 20);
                cout << endl;
                int len = strlen(name);
                for (std::vector<Course*> ::iterator it = Allcourses.begin(); it != Allcourses.end(); ++it)
                {
                    if (strncmp((*it)->getcName(), name,len) == 0)
                    {
                        courses.push_back(*it);
                    }

                }
            }
            //for new course
            else if (strncmp(option, "No", 3) == 0 || strncmp(option, "no", 3) == 0)
            {
                char cname[20];
                int creditHours;
                cout << "Enter Course Name: ";
                //cin.ignore();
                cin.getline(cname, 20);
                int id;
                cout << "Enter course id: ";
                cin >> id;
                cout << endl;
                cout << "Enter credit hours: ";
                cin >> creditHours;
                cin.ignore();
                Course* c = new Course(id,cname, creditHours);
                c->setprogramid(pId);
                addCourse(c);
                //coursesManaged.push_back(c);
                Allcourses.push_back(c);
                pc1->c = c;
                

                

            }

        }
        else if (choice == 3) {
            //for existing PLO 

            char option[20];
            cout << "Do you want to add an existing PLO?";
            cin.ignore();
            cin.getline(option, 20);
            if (strncmp(option, "Yes", 3) == 0 || strncmp(option, "yes", 3) == 0)
            {
                printAllPLOS();

                int id;
                cout << "Enter existing PLO id you want to add";
                cin >> id;
                cout << endl;
                for (std::vector<PLO*> ::iterator it = AllPLOS.begin(); it != AllPLOS.end(); ++it)
                {
                    if ((*it)->getpId() == id)
                    {
                        ploList.push_back(*it);
                    }

                }

            }
            //for new PLO
            else if (strncmp(option, "No", 3) == 0 || strncmp(option, "no", 3) == 0)
            {
                char des[20];
                int id;
                cout << "Enter Description: ";
                //cin.ignore();
                cin.getline(des, 50);
                cout << "Enter id: ";
                cin >> id;
                cin.ignore();
                PLO* c = new PLO(id, des);
                c->setprogramid(pId);
                ploList.push_back(c);
                AllPLOS.push_back(c);
                pc1->p = c;

            }

        }
        else {
            cout << "Invlid input";

        }

    }
    char* getpName() {
        return pName;
    }



   /* void prineac()
    {
        cout << this->pId << endl;
        cout<<this->
    }*/



    void saveprogram()
    {

        ofstream f1;
        f1.open("programs.txt", ios::app);
        if (f1.is_open())
        {
            f1 << this->pId << endl;
            f1 << this->pName << endl;
            f1 << "#" << endl;

            for (std::vector<PLO*> ::iterator it = ploList.begin(); it != ploList.end(); ++it)
            {
                (*it)->savePLO(this->pId);
            }

            for (std::vector<Course*> ::iterator it = courses.begin(); it != courses.end(); ++it)
            {
                (*it)->savecourse(this->pId);
            }
        }
        f1.close();

    }
};

/*  ifstream f1("programs.txt");
        if (f1.is_open())
        {
            while (!f1.eof())
            {

            }
        }*/


class academicOfficer : public User {

    char department[20];
    vector<Course*> coursesManaged; //association
    vector<Program*> programsManaged; //association
    vector<CLO*> CLOSManaged; //association
    vector<PLO*>PLOSManaged;
    string username;


public:

    void setUsername(string x){
        username = x;
    }
    string getUsername(){
        return username;
    }
    academicOfficer(const char department[20], const char name[20], int id, Date db, address add, const char gen[2]) :User(name, id, db, add, gen)
    {
        strcpy(this->department, department);
    }
    academicOfficer(academicOfficer& obj) : User(obj)
    {
        strcpy(this->department, obj.department);
    }

    void addCourseManaged(Course* c) {
        coursesManaged.push_back(c);
        Allcourses.push_back(c);
    }

    void addProgramManaged(Program* p)
    {
        programsManaged.push_back(p);
        Allprograms.push_back(p);
    }

    void addCLOSManaged(CLO* c)
    {
        CLOSManaged.push_back(c);
        AllCLOS.push_back(c);
    }

    void addPLOSManaged(PLO* p)
    {
        PLOSManaged.push_back(p);
        AllPLOS.push_back(p);
    }

    void printprograms() {

        cout << "--------------------------------------------------------------------------------------" << endl;
        for (std::vector<Program*> ::iterator it = programsManaged.begin(); it != programsManaged.end(); ++it) {
            cout << (*it)->getpName() << endl;
        }
        cout << "--------------------------------------------------------------------------------------" << endl;

    }

    void printcourses() {

        cout << "--------------------------------------------------------------------------------------" << endl;
        for (std::vector<Course*> ::iterator it = coursesManaged.begin(); it != coursesManaged.end(); ++it) {
            cout << (*it)->getcName() << endl;
        }
        cout << "--------------------------------------------------------------------------------------" << endl;

    }

    void printCLOS() {

        cout << "--------------------------------------------------------------------------------------" << endl;
        for (std::vector<CLO*> ::iterator it = CLOSManaged.begin(); it != CLOSManaged.end(); ++it) {
            cout << (*it)->getcId() << " " << (*it)->getDes() << endl;
        }
        cout << "--------------------------------------------------------------------------------------" << endl;
    }

    void printPLOS() {

        cout << "--------------------------------------------------------------------------------------" << endl;
        for (std::vector<PLO*> ::iterator it = PLOSManaged.begin(); it != PLOSManaged.end(); ++it) {
            cout << (*it)->getpId() << " " << (*it)->getDes() << endl;
        }
        cout << "--------------------------------------------------------------------------------------" << endl;
    }



    void addprogram()
    {
        int choice = 0;
        cout << "[1]Add existing program,[2]Add a new program: ";
        cin >> choice;
        if (choice == 1) {


        }
        else if (choice == 2) {
            char pName[20];
            cout << "You are entering a new program" << endl;
            cout << "Enter program name: ";
            
            cin.ignore();
            cin.getline(pName, 20);
            cout << endl;
            cout << "Enter program id: ";
            int id;
            cin >> id;
            cout << endl;
            cin.ignore();
            Program* pro = new Program(id, pName);
            programsManaged.push_back(pro);
            Allprograms.push_back(pro);
            while (1)
            {
                char input[20];
                cout << "do you want to add further information about your program?  ";
               // cin.ignore();
                cin.getline(input, 20);
                //Course *c=NULL;
                //PLO *P=NULL
                pc pc1;
                pc1.c = NULL;
                pc1.p = NULL;
                if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
                {
                    pro->updateProgram(&pc1);
              
                    if (pc1.c != NULL)
                        coursesManaged.push_back(pc1.c);
                    if (pc1.p != NULL)
                        PLOSManaged.push_back(pc1.p);
                }

                else
                    return;
            }


        }

    }


    void removeprogram()
    {
        bool flag = false;
        char input[20];
        printprograms();
        cout << "Enter program name that you want to remove: ";
        //cin.ignore();
        cin.getline(input, 20);
        cout << endl;
        int len = strlen(input);
        for (std::vector<Program*> ::iterator it = programsManaged.begin(); it != programsManaged.end(); ++it)
        {
            if (strncmp((*it)->getpName(), input,len) == 0)
            {
                programsManaged.erase(it);
                cout << "Removed" << endl;
                flag = true;
                break;
            }
            

        }
        if(flag==false)
         cout << "No such program exists" << endl;
    }

    void updateprogram()
    {
        pc pc1;
        pc1.c = NULL;
        pc1.p = NULL;
        bool flag = false;
        char arr[20];
        cout << "You are about to update program" << endl;
        printprograms();
        cout << "Enter the program name you want to update: ";
        cin.getline(arr, 20);
        for (std::vector<Program*> ::iterator it = programsManaged.begin(); it != programsManaged.end(); ++it)
        {
            if (strcmp((*it)->getpName(), arr) == 0)
            {
                (*it)->updateProgram(&pc1);
                cout << "Updated" << endl;
                if (pc1.c != NULL)
                    coursesManaged.push_back(pc1.c);
                if (pc1.p != NULL)
                    PLOSManaged.push_back(pc1.p);
                flag = true;
                break;
            }
        }
        if(flag==false)
            cout << "No such program exists" << endl;

    }

    void managePrograms()// this is like the menu
    {
        Course* c = NULL;
        PLO* p = NULL;
        char input[20];
        cout << "Do you want to add, delete or update the program? ";
        //cin.ignore();
        cin.getline(input, 20);
        if (strncmp(input, "add", 3) == 0)
            addprogram();
        else if (strncmp(input, "update", 6) == 0)
        {
            updateprogram();
            

        }
        else
            removeprogram();

    }
    ////////////////////////////////////////////////////////////////////////////


    void updatecourse()
    {
        pc p2;
        p2.cl = NULL;
        p2.c = NULL;
        p2.p = NULL;
        char arr[20];
        cout << "You are about to update a course" << endl;
        printcourses();
        cout << "Enter the course name you want to update: ";
        cin.getline(arr, 20);
        for (std::vector<Course*> ::iterator it = coursesManaged.begin(); it != coursesManaged.end(); ++it)
        {
            if (strcmp((*it)->getcName(), arr) == 0)
            {
                (*it)->updateCourse(&p2);
                cout << "Updated" << endl;
                if (p2.cl != NULL)
                    CLOSManaged.push_back(p2.cl);
                break;
            }
        }
        cout << "No such course exists" << endl;

    }


    void addcourse()
    {

        char cName[20];
        int crhs;
        cout << "You are entering a new course" << endl;
        cout << "Add information about the new course";
        cout << endl;
        cout << "Enter course name: ";
        cin.getline(cName, 20);
        cout << endl;
        int id;
        cout << "Enter course id: ";
        cin >> id;
        cout << endl;
        cout << "Enter credit hours: ";
        cin >> crhs;
        cin.ignore();
        cout << endl;
        Course* c = new Course(id,cName, crhs, NULL);
        coursesManaged.push_back(c);
        Allcourses.push_back(c);
        while (1)
        {
            pc p3;
            p3.c = NULL;
            p3.cl = NULL;
            p3.p = NULL;
            char input[20];
            cout << "Do you want to add further information about the course?";
           // cin.ignore();
            cin.getline(input, 20);
            if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
            {
                c->updateCourse(&p3);
                if (p3.cl != NULL)
                    CLOSManaged.push_back(p3.cl);
            }
            else
                return;
        }
    }

    void removecourse()
    {
        char input[20];
        bool flag = false;
        printcourses();
        cout << "Enter course name that you want to remove: ";
        cin.getline(input, 20);
        cout << endl;
        int len = strlen(input);
        for (std::vector<Course*> ::iterator it = coursesManaged.begin(); it != coursesManaged.end(); ++it)
        {
            if (strncmp((*it)->getcName(), input,len) == 0)
            {
                coursesManaged.erase(it);
                cout << "Removed" << endl;
                flag = true;
                break;
            }

        }
        if (flag==false)
                 cout << "No such course exists" << endl;
    }

    void manageCourses()
    {
        char input[20];
        cout << "Do you want to add, delete or update a course? ";
       // cin.ignore();
        cin.getline(input, 20);
        if (strncmp(input, "add", 3) == 0)
            addcourse();
        else if (strncmp(input, "update", 6) == 0)
        {
           
            updatecourse();
           
        }
        else
            removecourse();

    }

    //////////////////////////////////////////////////////////////////////

    void updatePLO()
    {
        int id;
        cout << "You are about to update a PLO" << endl;
        printPLOS();
        cout << "Enter the PLO id you want to update: ";
        cin >> id;
        cin.ignore();
        cout << endl;
        for (std::vector<PLO*> ::iterator it = PLOSManaged.begin(); it != PLOSManaged.end(); ++it)
        {
            if ((*it)->getPLOid() == id)
            {
                (*it)->updatePLO();
                cout << "Updated" << endl;
                break;
            }
        }
        cout << "No such PLO exists" << endl;

    }


    void removePLO()
    {
        int id;
        printPLOS();
        cout << "Enter PLO id that you want to remove: ";
        cin >> id;
        cout << endl;
        cin.ignore();
        bool flag = true;
        for (std::vector<PLO*> ::iterator it = PLOSManaged.begin(); it != PLOSManaged.end(); ++it)
        {
            if ((*it)->getPLOid() == id)
            {
                PLOSManaged.erase(it);
                cout << "Removed" << endl;
                flag = false;
                break;
            }
        }
        if(flag==true)
            cout << "No such PLO exists" << endl;
    }


    void addPLO()
    {

        char des[20];
        int id;
        cout << "You are entering a new PLO" << endl;
        cout << "Add information about the new PLO";
        cout << endl;
        cout << "Enter PLO description: ";
        cin.getline(des, 20);
        cout << endl;
        cout << "Enter id for your PLO: ";
        cin >> id;
        cin.ignore();

        cout << endl;
        PLO* p = new PLO(id, des);
        PLOSManaged.push_back(p);
        AllPLOS.push_back(p);
        
        while (1)
        {
            
            char input[20];
            cout << "Do you want to add further information?";
            cin.getline(input, 20);
            if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
            {
                p->updatePLO();
                
            }

            else
                return;
        }
    }


    void managePLOS()
    {
        char input[20];
        cout << "Do you want to add, delete or update a PLO? ";
        //cin.ignore();
        cin.getline(input, 20);
        if (strncmp(input, "add", 3) == 0)
            addPLO();
        else if (strncmp(input, "update", 6) == 0)
            updatePLO();
        else
            removePLO();

    }

    //////////////////////////////////////////////////////////////////////////


    void updateCLO()
    {
        int id;
        cout << "You are about to update a CLO" << endl;
        printPLOS();
        cout << "Enter the CLO id you want to update: ";
        cin >> id;
        cout << endl;
        for (std::vector<CLO*> ::iterator it = CLOSManaged.begin(); it != CLOSManaged.end(); ++it)
        {
            if ((*it)->getcId() == id)
            {
                (*it)->updateCLO();
                cout << "Updated" << endl;
                break;
            }
        }
        cout << "No such CLO exists" << endl;

    }




    void addCLO()
    {

        char des[20];
        int id;
        cout << "You are entering a new CLO" << endl;
        cout << "Add information about the new CLO";
        cout << endl;
        cout << "Enter course description: ";
        cin.getline(des, 20);
        cout << endl;
        cout << "Enter id for your CLO: ";
        cin >> id;
        cout << endl;
        cin.ignore();
        CLO* p = new CLO(id, des);
        CLOSManaged.push_back(p);
      
        AllCLOS.push_back(p);
        while (1)
        {
            char input[20];
            cout << "Do you want to add further information for the program?";
            cin.getline(input, 20);
            if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
            {
                p->updateCLO();
            }
            else
                return;
        }
    }


    void removeCLO()
    {
        int id;
        printCLOS();
        cout << "Enter CLO id that you want to remove: ";
        cin >> id;
        cout << endl;
        for (std::vector<CLO*> ::iterator it = CLOSManaged.begin(); it != CLOSManaged.end(); ++it)
        {
            if ((*it)->getcId() == id)
            {
                CLOSManaged.erase(it);
                cout << "Removed" << endl;
                break;
            }
        }
        cout << "No such CLO exists" << endl;
    }




    void manageCLOS()
    {
        char input[20];
        cout << "Do you want to add, delete or update a CLO? ";
        cin.getline(input, 20);
        if (strncmp(input, "add", 3) == 0)
            addCLO();
        else if (strncmp(input, "update", 6) == 0)
            updateCLO();
        else
            removeCLO();

    }




    void saveacademicofficer()
    {
        ofstream f1;
        f1.open("academicofficer.txt", ios::app);
        if (f1.is_open())
        {
            f1<<this->username<<endl;
            f1 << this->department << endl;
            f1 << this->getname()<<endl;
            f1 << this->getgender()<<endl;
            savedate(f1);
            saveaddress(f1);
          
            ofstream f2;
            ofstream f3;
            ofstream f4;
            ofstream f5;
            for (std::vector<CLO*> ::iterator it = this->CLOSManaged.begin(); it != CLOSManaged.end(); ++it)
            {
                f2.open("CLO.txt", ios::app);
                if (f2.is_open())
                {
                    f2 << username << endl;
                    f2.close();
                }
                (*it)->saveCLO((*it)->getcourseid());
            }
          
            for (std::vector<PLO*> ::iterator it = this->PLOSManaged.begin(); it != PLOSManaged.end(); ++it)
            {
             
                f3.open("PLO.txt", ios::app);
                if (f3.is_open())
                {
                    f3 << username << endl;
                    f3.close();
                }
                (*it)->savePLO((*it)->getprogramid());
            }


            for (std::vector<Course*> ::iterator it = this->coursesManaged.begin(); it != coursesManaged.end(); ++it)
            {
                f4.open("course.txt", ios::app);
                if (f4.is_open())
                {
                    f4 << username << endl;
                    f4.close();
                }
                (*it)->savecourse((*it)->getprogramid());
            }



            for (std::vector<Program*> ::iterator it = this->programsManaged.begin(); it != programsManaged.end(); ++it)
            {
                f5.open("programs.txt", ios::app);
                if (f5.is_open())
                {
                    f5 << username << endl;
                    f5.close();
                }
                (*it)->saveprogram();
            }

        }
        f1 << "#" << endl;
        f1.close();
    }


    







};





class Question
{
    int qId;
    char complexity[20];
    char statement[50];
    int marksofQuestion;
    int evaid;
    vector<CLO*> CLOToBeTested;  //association
public:
    Question()
    {
        qId = -1;
        marksofQuestion = 0;
    }
    Question(int id, const char c[20], const char s[20], int m)
    {
        qId = id;
        strcpy(complexity, c);
        strcpy(statement, s);
        marksofQuestion = m;
    }
    /* Question(Question& obj)
     {
         qId = obj.qId;
         strcpy(complexity, obj.complexity);
         strcpy(statement, obj.statement);
         this->marksofQuestion = obj.marksofQuestion;
     }*/
    int getMarks()
    {
        return marksofQuestion;
    }
    void addtestedCLO(CLO* c)
    {
        CLOToBeTested.push_back(c);
    }

    void updateQuestion()
    {
        int choice;
        cout<<"do you want to [1]edit marks, [2]edit complexity, [3]edit statement: ";
        cin >> choice;
        if(choice==1){
            int m;
            cout << "Enter marks: ";
            cin >> m;
            cin.ignore();
            marksofQuestion = m;
        }
        else if(choice==2) {
            char c[20];
            cout << "enter complexity: ";
            cin.ignore();
            cin.getline(c, 20);
            strcpy(complexity, c);
        }
        else if (choice==3)
        {
            char x[50];
            cout << "Enter statement: ";
            cin.ignore();
            cin.getline(x, 50);
            strcpy(statement, x);

        }
    }

    void savequestion(int evaiD)
    {
        ofstream f1;
        this->evaid = evaiD;
        f1.open("questions.txt", ios::app);
        if (f1.is_open())
        {
            f1 << evaiD << endl;
            f1 << this->qId << endl;
            f1 << this->complexity << endl;
            f1 << this->statement << endl;
            f1 << this->marksofQuestion << endl;
            f1 << "/" << endl;
            for (std::vector<CLO*> ::iterator it = CLOToBeTested.begin(); it != CLOToBeTested.end(); ++it)
            {
                f1<<(*it)->getcId()<< endl;
            }
            f1<<"/"<<endl;
            f1 << "#";

        }
        f1.close();
    }
   

};





class Evaluation
{
    int eId;
    char evaluationType[20];
    Date* date;
    //vector<Question> questions;
    unordered_map<int, Question> questions;// compostion and hashing [O(1) access]

public:
    Evaluation(int id, const char arr[20], Date d)
    {
        eId = id;
        strcpy(evaluationType, arr);
        date = new Date(d);
    }

    Evaluation(Evaluation& obj)
    {
        eId = obj.eId;
        strcpy(evaluationType, obj.evaluationType);
        this->date = new Date(*obj.date);
    }


    int geteId()
    {
        return eId;
    }

    void createQuestion(int id, const char complexity[20], const char statement[50], int marksofQuestion)
    {
        Question q(id, complexity, statement, marksofQuestion);
        //    questions.insert(make_pair(id, q));
        questions.insert({ id, q });

    }

    int getTotalMarks()
    {
        std::unordered_map<int, Question>::iterator it = questions.begin();

        int totalMarks = 0;
        while (it != questions.end()) {

            totalMarks = totalMarks + it->second.getMarks();
            it++;
        }
        return totalMarks;
    }


    void saveevaluation()
    {
        //this->courseid = courseId;
        ofstream f1;
        f1.open("evaluation.txt", ios::app);
        if (f1.is_open())
        {
            f1 << this->eId << endl;

            f1 << this->evaluationType << endl;
            date->saveDate(f1);           
            //f1 << "/" << endl;
            std::unordered_map<int, Question>::iterator it = questions.begin();
            while (it != questions.end()) {

                it->second.savequestion(eId);
                it++;
            }
            f1 << "#" << endl;
           // f1 << "/" << endl;

        }
        f1.close();
    }







    void updateEvaluation()
    {

        int choice;
        cout << "do you want to [1]Edit evaluation type [2]Edit date [3]add a new question [4]edit a question";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            char x[20];
            cout << "Enter evaluation type: ";
            cin.getline(x, 20);
            strcpy(evaluationType, x);
        }
        else if (choice == 2) {
            delete date;
            int d, y;
            char m[10];
            char day[10];
            cout << "Enter day(int): ";
            cin >> d;
            cin.ignore();
            cout << "Enter month: ";
            cin.getline(m, 10);
            cout << "Enter year: ";
            cin >> y;
            cin.ignore();
            cout << "Enter day(char): ";
            cin.getline(day, 10);
            date = new Date(m, day, d, y);
        }
        else if (choice == 3) {
            int id, marks;
            char comp[20];
            char stat[50];
            cout << "Enter id: ";
            cin >> id;
            cout << "Enter complexity: ";
            cin.ignore();
            cin.getline(comp, 20);
            cout << "Enter statement: ";
            cin.getline(stat, 50);
            cout << "Enter marks: ";
            cin >> marks;
            cin.ignore();
            createQuestion(id, comp, stat, marks);
        }
        else if (choice == 4)
        {
            int  option;
            cout << "enter [1]to update question [2]to remove question ";
            cin >> option;
            cout << endl;
            int id;
            cout << "enter question id: ";
            cin >> id;
            cin.ignore();
            cout << endl;
            Question* q = &questions.at(id);
            if (option == 1)
                q->updateQuestion();
            else if (option == 2)
            {
                cout << "You are removing a question" << endl;
                questions.erase(id);
            }
            else
                cout << "invalid choice";
        }
    }
};




class Topic
{
    int Tid;
    char topicName[20];
    vector<CLO*> CLOCovered;
public:
    Topic(int id, const char n[20])
    {
        Tid = id;
        strcpy(topicName, n);
    }
    Topic(Topic& obj)
    {
        Tid = obj.Tid;
        strcpy(topicName, obj.topicName);
    }
    void addcoveredCLO(CLO* c)
    {
        CLOCovered.push_back(c);
    }

    int getTopicid()
    {
        return this->Tid;
    }

    void updateTopic()
    {
        int choice;
        char n[20];
        cout << "Do you want to [1]Edit topic name [2]Add a coressponding CLO";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(n, 20);
            strcpy(topicName, n);
        }
        else if (choice == 2)
        {
            char option[20];
            cout << "You are adding an existing CLO:- ";
            //cin.ignore();
           // cin.getline(option, 20);
            printAllCLOS();
            int id;
            cout << "Enter existing CLO id you want to add";
            cin >> id;
            cin.ignore();
            cout << endl;
            for (std::vector<CLO*> ::iterator it = AllCLOS.begin(); it != AllCLOS.end(); ++it)
            {
                if ((*it)->getcId() == id)
                {
                    CLOCovered.push_back(*it);
                }

            }
        }

        else
            cout << "Invalid option\n";
    }



    void savetopics()
    {

        ofstream f1;
        f1.open("Topic.txt", ios::app);
        if (f1.is_open())
        {
            f1 << this->Tid << endl;
            f1 << this->topicName << endl;
            f1 << "/" << endl;
            for (std::vector<CLO*> ::iterator it = CLOCovered.begin(); it != CLOCovered.end(); ++it)
            {
                f1 << (*it)->getcId() << endl;
            }
            f1 << "/" << endl;
            f1<<"#"<<endl;

        }
        f1.close();
    }
};






class Teacher : public User
{
    char Tdepartment[20];
    vector<Course*> coursesTaught; //association
    vector<Evaluation*> evaluationHandled; //association
    vector<Topic*> topicHandled; //association
    string username;



public:
    Teacher() : User()
    {
        Tdepartment[0] = '\0';
    }

  
    void setUsername(string x){
        username = x;
    }
    string getusername(){
        return username;
    }

    Teacher(const char dep[20], const char name[20], int id, Date db, address add, const char gen[2]) : User(name, id, db, add, gen)
    {
        strcpy(Tdepartment, dep);
    }

    Teacher(Teacher& obj) : User(obj)
    {
        strcpy(Tdepartment, obj.Tdepartment);
    }
    void addCourseTaught(Course* c) {
        coursesTaught.push_back(c);
    }
    void addEvaluationHandled(Evaluation* e)
    {
        evaluationHandled.push_back(e);
    }
    void addTopicHandled(Topic* t)
    {
        topicHandled.push_back(t);
    }







    void removetopic()
    {
        int id;
        // printPLOS();
        cout << "Enter topic id that you want to remove: ";
        cin >> id;
        cout << endl;
        bool flag = true;
        for (std::vector<Topic*> ::iterator it = topicHandled.begin(); it != topicHandled.end(); ++it)
        {
            if ((*it)->getTopicid() == id)
            {
                topicHandled.erase(it);
                cout << "Removed" << endl;
                flag = false;
                break;
            }
        }
        if(flag==true)
            cout << "No such Topic exists" << endl;
    }


    void updatetopic()
    {
        int id;
        cout << "You are about to update a topic" << endl;
        cout << "Enter the topic id you want to update: ";
        cin >> id;
        cout << endl;
        bool flag=false;
        for (std::vector<Topic*> ::iterator it = topicHandled.begin(); it != topicHandled.end(); ++it)
        {
            if ((*it)->getTopicid() == id)
            {
                (*it)->updateTopic();
                flag = true;
                cout << "Updated" << endl;
                break;
            }
        }
        if(flag==false)
            cout << "No such Topic exists" << endl;

    }


    void addtopic()
    {

        char name[20];
        int id;
        cout << "You are entering a new Topic" << endl;
        cout << "Add information about the new Topic";
        cout << endl;
        cout << "Enter topic name: ";
        cin.getline(name, 20);
        cout << endl;
        cout << "Enter id for your topic: ";
        cin >> id;
        cin.ignore();
        cout << endl;
        Topic* p = new Topic(id, name);
        topicHandled.push_back(p);
        while (1)
        {
            char input[20];
            cout << "Do you want to add further information?";
            cin.getline(input, 20);
            if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
                p->updateTopic();
            else
                return;
        }
    }


    void manageTopic()
    {
        char input[20];
        cout << "Do you want to add, delete or update a topic? ";
        cin.getline(input, 20);
        if (strncmp(input, "add", 3) == 0)
            addtopic();
        else if (strncmp(input, "update", 6) == 0)
            updatetopic();
        else
            removetopic();


    }


    ////////////////////////////////////////////////////////////////////////////////////////////






    void removeevaluation()
    {
        int id;
        cout << "Enter evaluation id you want to remove: ";
        cin >> id;
        cout << endl;
        bool flag = false;
        for (std::vector<Evaluation*> ::iterator it = evaluationHandled.begin(); it != evaluationHandled.end(); ++it)
        {
            if ((*it)->geteId() == id)
            {
                evaluationHandled.erase(it);
                flag=true;
                cout << "Removed" << endl;
                break;
            }
        }
        if(flag==false)
            cout << "No such evaluation exists" << endl;
    }





    void updateevaluation()
    {
        int id;
        cout << "You are about to update an evaluation" << endl;
        cout << "Enter the evaluation id you want to update: ";
        cin >> id;
        cout << endl;
        for (std::vector<Evaluation*> ::iterator it = evaluationHandled.begin(); it != evaluationHandled.end(); ++it)
        {
            if ((*it)->geteId() == id)
            {
                (*it)->updateEvaluation();
                cout << "Updated" << endl;
                break;
            }
        }
        cout << "No such Evaluation exists" << endl;

    }


    void addevaluation()
    {

        char name[20];
        int id;
        cout << "You are entering a new evaluation" << endl;
        cout << "Add information about the new evaluation";
        cout << endl;
        cout << "enter id: ";
        cin >> id;
        cout << endl;
        cout << "Enter evaluation type: ";
        cin.ignore();
        cin.getline(name, 20);
        cout << endl;
        char day[20];
        char month[20];
        int year = 0;
        int dat = 0;
        cout << "Enter day: ";
        cin >> day;
        cout << endl;
        cout << "Enter month:";
        cin >> month;
        cout << endl;
        cout << "enter year: ";
        cin >> year;
        cout << endl;
        cout << "enter date: ";
        cin >> dat;
        cout << endl;
        Date* d = new Date(day, month, year, dat);
        Evaluation* p = new Evaluation(id, name, *d);
        cin.ignore();
        evaluationHandled.push_back(p);

        while (1)
        {
            char input[20];
            cout << "Do you want to add further information?";
            cin.getline(input, 20);
            if (strncmp(input, "yes", 3) == 0 || strncmp(input, "Yes", 3) == 0)
                p->updateEvaluation();
            else
                return;
        }
    }


    void manageEvaluation()
    {
        char input[20];
        cout << "Do you want to add, delete or update an evaluation? ";
        cin.getline(input, 20);
       // cin.ignore();
        if (strncmp(input, "add", 3) == 0)
            addevaluation();
        else if (strncmp(input, "update", 6) == 0)
            updateevaluation();
        else
            removeevaluation();


    }



    void saveteacher()
    {

        ofstream f1;
        f1.open("teacher.txt", ios::app);
        if (f1.is_open())
        {
            f1 << this->username << endl;
            f1 << this->Tdepartment << endl;
            f1 << this->getname() << endl;
            f1 << this->getgender() << endl;
            savedate(f1);
            saveaddress(f1);

            ofstream f2;
            ofstream f3;
            ofstream f4;
            for (std::vector<Topic*> ::iterator it = this->topicHandled.begin(); it != topicHandled.end(); ++it)
            {
                f2.open("Topic.txt", ios::app);
                if (f2.is_open())
                {
                    f2 << username << endl;
                    f2.close();
                }
                (*it)->savetopics();
            }
            f2.close();


            for (std::vector<Evaluation*> ::iterator it = this->evaluationHandled.begin(); it != evaluationHandled.end(); ++it)
            {
                f3.open("evaluation.txt", ios::app);
                if (f3.is_open())
                {
                    f3 << username << endl;
                    f3.close();
                }
                (*it)->saveevaluation();
            }
            f3.close();


            for (std::vector<Course*> ::iterator it = this->coursesTaught.begin(); it != coursesTaught.end(); ++it)
            {
                f4.open("course.txt", ios::app);
                if (f4.is_open())
                {
                    f4 <<"!"<< username << endl;
                    f4.close();
                }
                (*it)->savecourse((*it)->getprogramid());
            }
            f4.close();
        }
        f1.close();



    }




};







void printAllPrograms()
{

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    for (std::vector<Program*> ::iterator it = Allprograms.begin(); it != Allprograms.end(); ++it) {
        cout << (*it)->getpName() << endl;
    }
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

}

void printAllCourses() 
{

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    for (std::vector<Course*> ::iterator it = Allcourses.begin(); it != Allcourses.end(); ++it) {
        cout << (*it)->getcName() << endl;
    }
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

}

void printAllCLOS()
{

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    for (std::vector<CLO*> ::iterator it = AllCLOS.begin(); it != AllCLOS.end(); ++it) {
        cout << (*it)->getcId() << " " << (*it)->getDes() << endl;
    }
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
}

void printAllPLOS()
{

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    for (std::vector<PLO*> ::iterator it = AllPLOS.begin(); it != AllPLOS.end(); ++it) {
        cout << (*it)->getpId() << " " << (*it)->getDes() << endl;
    }
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

}








string logIn(int &x)
{
    cout << "WELCOME TO OBE SYSTEM" << endl;
    cout << "Enter credentials" << endl;
    x = 0;
    cout << "Are you a [1]Teacher or an [2]Academic officer:  ";
    cin >> x;
    cout << endl;
    if (x == 1)
    {
        ifstream f1;
        f1.open("teacherlist.txt", ios::in);
        if (f1.is_open())
        {
            string arrname;
            string pass;
            cout << "Enter username: ";
            cin >> arrname;
            cout << "Enter password: ";
            cin >> pass;
            string parr;
            string farr;
            bool found = false;
            while (!f1.eof() && !found)
            {

                f1 >> farr;
                f1 >> parr;
                if (arrname == farr && pass == parr)
                {
                    cout << "Teacher log in successful " << endl;
                    found = true;
                    return arrname;
                }
                
            }
            if (found == false)
            {
                cout << "Invalid Credentials\nTeacher Login failed." << endl;
                return "-1";
            }
        }
        f1.close();
    }
    else if (x == 2)
    {
        ifstream f1;
        f1.open("academicofficerlist.txt", ios::in);
        if (f1.is_open())
        {
            string user;
            string pass;
            cout << "Enter username: ";
            cin >> user;
            cout << "Enter Password: ";
            cin >> pass;
            string readUsername;
            string readPassword;
            bool found = false;
            while (!f1.eof() && !found)
            {
                f1 >> readUsername;
                f1 >> readPassword;
                if (readUsername == user && pass == readPassword)
                {
                    cout << "Academic Officer login successful" << endl;
                    found = true;
                    return user;
                }
            }
            if (found == false)
            {
                cout << "Invalid Credentials\nAcademic Officer Login failed." << endl;
                return "-1";
            }


        }
        f1.close();
    }





}



int main()
{

    /*
    ATTRIBUTES OF PROGRAM
     
    char pName[20];
    vector<Course*> courses;//association
    vector<PLO*>ploList;

             Program
          /           \
    (Course)           (PLO)
       |                |
    pre req            
      clo
       |
      PLO

      we have a program id
      which is included in course and PLO
      we load program object with empty lists
      we load course and plo objects with empty lists
      then we add objects in list on the basis of matching ids

      save()
      first place the id
      then other details
      go to all lists and save() them similarly
    
     */




        



   // Date d("June", "Tuesday", 24, 2001);
    // d.printDate();

//    address addr("50", "Awesome avenue", "Silver city");
    //char arr[20]="malaika";
    //User obj1("Malaika", 1, d, addr, "M");
   // Teacher t1("Islamic studies", "Malaika", 1, d, addr, "M");
  //  academicOfficer a1("CS", "Ahsan", 3, d, addr, "M");
    //Program p2(1,"CPS");
    //Program p1(1,"Computer Sci");

    //Course c1(1,"PF", 3);
    //Course c2(2,"OOP", 3);
    //Topic t2(1,"code");
    // Topic t3(2, "history");
    //CLO clo1(1, "polishing  ");
    //CLO clo2(2, "Information on ");

   
    //PLO plo1(1, "learn OOP");
    //PLO plo2(2, "learn BST");

   // clo1.addPLO(&plo1);

   // c1.addCLO(&clo1);
   // c1.addCLO(&clo2);

   //// p2.addPLO(&plo2);
   // p1.addPLO(&plo1);

   // p1.addPLO(&plo2);

   // p1.addCourse(&c1);
   // p1.addCourse(&c2);

   // a1.addPLOSManaged(&plo1);
   // a1.addProgramManaged(&p1);

   // p1.addCourse(&c2);
   // p1.addPLO(&plo2);

   //a1.addCLOSManaged(&clo2);
   // a1.addCourseManaged(&c2);
   // a1.addCourseManaged(&c1);

   /* a1.addPLOSManaged(&plo1);
    a1.addPLOSManaged(&plo2);*/

    //a1.addProgramManaged(&p1);
  //  a1.addProgramManaged(&p2);

  //  plo1.addCLO(&clo1);
  //  clo1.addPLO(&plo1);
    
    //p1.addPLO(&plo1);
    //p1.addPLO(&plo2);

    /*p1.addCourse(&c1);
    p1.addCourse(&c2);*/

   /* c1.addCLO(&clo1);
    c2.addCLO(&clo2);*/


   /*  Evaluation e1(1, "quiz", d);

    e1.createQuestion(1, "mild", "HOW many starts are there?", 20);
    e1.createQuestion(2, "mild", "HOW many planets are there?", 10);*/
   // int marks = e1.getTotalMarks();
    //cout << "marks: " << marks << endl;




       
   // a1.addCLOSManaged(&clo1);
   // a1.managePrograms();
  //  a1.manageCourse();
   // a1.manageCLOS();
    //cout << endl << endl;
   // printAllPLOS();
  //  printAllCourses();
  //  t1.addCourseTaught(&c1);
    //t1.addevaluation();
   // t1.addEvaluationHandled(&e1);
  //  t1.manageEvaluation();
   // AllCLOS.push_back(&clo1);
    //AllCLOS.push_back(&clo2);
    //t1.addTopicHandled(&t2);
   // t1.manageTopic();
    



    //p1.saveprogram();
    //p2.saveprogram();


    /*plo1.savePLO(1);
    plo2.savePLO(2);*/



    //Topic t(2, "pf");
    
    //t.addcoveredCLO(&clo1);

    //e1.saveevaluation();
    //t.savetopics();
   // logIn();

   // a1.setUsername("abc1234");
    //a1.saveacademicofficer();


    //t1.setusername("userabc");
    //t1.saveteacher();

    

    //a1.managePrograms();
    //cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
    //a1.manageCourses();
    //cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
    //a1.manageCLOS();
    //cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
    //a1.managePLOS();
    //cout << "%%%%%%%%%%%%%%%%%%%%" << endl;
    //
  //  a1.saveacademicofficer();
    



   // LOADING ACADEMIC OFFICER'S DATA
    academicOfficer* a1;
    Teacher* t1;
    string readUsername;
    char department[20];
    char name[20];
    char gender[2];
    char junk[10];
    char month[20];
    char day[20];
    int date;
    int year;
    char houseno[20];
    char streetno[20];
    char city[20];
    string uname;
    int loginby = 0;
    address* a;
    Date* d;

    uname = logIn(loginby);
    if (uname == "-1")
        return 0;
    if(loginby==1)
    {

        ifstream f1;
       f1.open("teacher.txt", ios::in);
        if (f1.is_open())
        {
            while (!f1.eof())
            {
                f1 >> readUsername;
                if (uname == readUsername)
                {
                    f1 >> department;
                    f1 >> name;
                    f1 >> gender;
                    f1 >> junk;
                    f1 >> month;
                    f1 >> day;
                    f1 >> date;
                    f1 >> year;
                    f1 >> junk;
                    f1 >> houseno;
                    f1 >> streetno;
                    f1 >> city;
                    f1 >> junk;
                    break;
                }


            }
        }
        f1.close();
        a=new address(houseno, streetno, city);
        d=new Date(month, day, date, year);
        t1=new Teacher(department, name, 1, *d, *a, gender);
        t1->setUsername(uname);


    }
    else if (loginby == 2)
    {
        ifstream f1;
        
        f1.open("academicofficer.txt", ios::in);
        if (f1.is_open())
        {
            while (!f1.eof())
            {
                f1 >> readUsername;
                if (uname == readUsername)
                {
                    f1 >> department;
                    f1 >> name;
                    f1 >> gender;
                    f1 >> junk;
                    f1 >> month;
                    f1 >> day;
                    f1 >> date;
                    f1 >> year;
                    f1 >> junk;
                    f1 >> houseno;
                    f1 >> streetno;
                    f1 >> city;
                    f1 >> junk;
                    break;
                }


            }
        }
        f1.close();
        a=new address(houseno, streetno, city);
        d=new Date(month, day, date, year);
        a1=new academicOfficer(department, name, 1, *d, *a, gender);
        a1->setUsername(uname);


    }
    







    system("pause");


}