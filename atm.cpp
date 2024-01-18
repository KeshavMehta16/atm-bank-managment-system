#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


class bank{
    private:
        string id,pwd,name,fname,address;
        int pin,phone;
        float balance;
    public:
    void menu();
    void bank_manager();
    void atm_manager();
    void new_user();
    void existing_user();
    void deposit();
    void withdraw();
    void transfer();
    void pay_bills();
    void search();
    void edit_user();
    void del_user();
    void all_records();
    void payment_history();
    void user_balance();
    void withdraw_atm();
    void user_details();
};

void introduction(){
    cout<<"\n\n\n\n\n\t    ";
    for(int i=0;i<56;i++){
        cout<<"*";
    }
    cout<<"\n\t   ";
    for(int i=0;i<58;i++){
        cout<<"*";
    }
    cout<<"\n\t  ";
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    cout<<"\n\n\t\t\t    Bank & ATM \n\t\t\t Management System\n\n\t";
    for(int i=0;i<60;i++){
        cout<<"*";
    }
    cout<<"\n\t ";
    for(int i=0;i<58;i++){
        cout<<"*";
    }
    cout<<"\n\t  ";    
    for(int i=0;i<56;i++){
        cout<<"*";
    }
    getch();
}


void bank::menu(){
    getInput:
    system("cls");
    int choice;
    string email;
    char ch;
    string pin;
    string pwd;
    cout<<"\n\n\t\t\tControl Panel";
    cout<<"\n\n 1. Bank Management";
    cout<<"\n 2. ATM  Management";
    cout<<"\n 3. Exit";
    cout<<"\n\n Enter Your Choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        system("cls");
        cout<<"\n\n\t\t\tLogin Account";
        cout<<"\n\nYour E-mail :";
        cin>>email;
        cout<<"\n\nPassword :";
        for(int i=1;i<=6;i++){
            ch = getch();
            pwd += ch;
            cout<<"*";
        }
        cout<<"\n\n Pin Code :";
        for(int i=1;i<=6;i++){
            ch = getch();
            pin += ch;
            cout<<"*";
        }
        if(email == "keshubhai@gmail.com" && pwd == "251001" && pin == "144002"){
            bank_manager();             
        }else{
            cout<<"\n\n Invalid Credentials.";
        }
        break;

    case 2:
        atm_manager(); 
        break;
    
    case 3:
        exit(0); 
    default:
        cout<<"\n\n Invalid Value. Please Try Again..";
    }
    getch();      //baar baar input leta rhega jab tak khud se exit nhi kr dete
    goto getInput;  //ye vapis upar jump karva dega where we have aur label and runs the same function
}

void bank::bank_manager(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t BANK Management System";
    cout<<"\n\n 1. New User";
    cout<<"\n 2. Existing User";
    cout<<"\n 3. Deposit";
    cout<<"\n 4. Withdraw";
    cout<<"\n 5. Transfer";
    cout<<"\n 6. Pay Your Bills";
    cout<<"\n 7. Search User";
    cout<<"\n 8. Edit User";
    cout<<"\n 9. Delete User";
    cout<<"\n 10. Show All Records";
    cout<<"\n 11. Payment All Records";
    cout<<"\n 12. Go Back";
    cout<<"\n\n\t\t\t Enter Your Choice :";
    cin>>choice;
    switch (choice)
    {
    case 1:
        new_user();
        break;
    
    case 2:
        existing_user();
        break;

    case 3:
        deposit();
        break;

    case 4:
        withdraw();
        break;

    case 5:
        transfer();
        break;
    
    case 6:
        pay_bills();
        break;

    case 7:
        search();
        break;

    case 8:
        edit_user();
        break;
    
    case 9:
        del_user();
        break;
    
    case 10:
        all_records();
        break;

    case 11:
        payment_history();
        break;

    case 12:
        menu();

    default:
        cout<<"\n\n Invalid Value. Please Try Again..";
    }
    getch();
    goto p;
}

void bank::atm_manager(){
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\t ATM Management System";
    cout<<"\n\n 1. User Login & Check Balance";
    cout<<"\n 2. Withdraw Amount";
    cout<<"\n 3. Account Details";
    cout<<"\n 4. Go Back";
    cout<<"\n\n\t\t\t Enter Your Choice :";
    cin>>choice;
    switch (choice)
    {
    case 1:
        user_balance();
        break;
    
    case 2:
        withdraw_atm();
        break;

    case 3:
        user_details();
        break;

    case 4:
        menu();

    default:
        cout<<"\n\n Invalid Value. Please Try Again..";
    }
    getch();
    goto p;
}

void bank::new_user(){
    p:
    system("cls");
    fstream file;    //to check from records weather the new user registered have unique details or not
    int pn,ph;
    float b;
    string n,fn,pass,a,i;   //these value compares new users values to previous users
    cout<<"\n\n\t\t\t Add New User";
    cout<<"\n\n User ID : ";
    cin>>id;
    cout<<"\n\n\t Name : ";
    cin>>name;
    cout<<"\n\n\t Father's Name : ";
    cin>>fname;
    cout<<"\n\n\t Address : ";
    cin>>address;
    cout<<"\n\n\t Pin Code (6-digits) : ";
    cin>>pin;
    cout<<"\n\n\t Password (6-digits) : ";
    cin>>pwd;
    cout<<"\n\n\t Phone Number : ";
    cin>>phone;
    cout<<"\n\n\t Current Balance : ";
    cin>>balance;
    file.open("bank.txt" , ios::in);
    if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }else{
        file>>i>>n>>fn>>a>>pn>>pass>>ph>>b;
        while(!file.eof()){
            if(i == id){         //checking if user already exist or not
                cout<<"\n\n User ID Already Exits..";
                getch();
                goto p;
            }
            file>>i>>n>>fn>>a>>pn>>pass>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);    //now here record doesnt already exits so we are sending it to file after checking its existence
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    cout<<"\n\n New User Added";
}


void bank::existing_user(){
    system("cls");
    fstream file;
    string t_id;
    bool found = false;
    cout<<"\n\n Existing User Account";
    file.open("bank.txt" , ios::in);   //ios::in means open file for read mode
    if(!file){
        cout<<"\n\n File dosen't exists..";
    }else{
        cout<<"\n\n User ID :";
        cin>>t_id;
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){    //eof = end of file;
            if(t_id == id){
                system("cls");
                cout<<"\n\n\t\t\t User Already Exist";
                cout<<"\n\n User ID : "<<id<<"  "<<"Pin Code : "<<pin<<"  "<<"Password : "<<pwd;
                found = true;
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance; 
        }
        file.close();
        if(found == false){
            cout<<"\n\n User ID can't found.";
        }
    }
}

void bank::deposit(){
    fstream file,file1;
    string t_id;
    float amt;
    bool found = false;
    system("cls");
    cout<<"\n\n\t\t\t Deposit Amount";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File dosen't exists..";
    }else{
        cout<<"\n\n User ID :";
        cin>>t_id;
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){    //eof = end of file;
            if(t_id == id){
                cout<<"\n\n Enter Amount : ";
                cin>>amt;
                balance += amt;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                found = true;
                cout<<"\n\n\t\t\t Your Amount "<<amt<<" deposited successfully";
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance; 
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == false){
            cout<<"\n\n User ID can't found.";
        }
    }
}

void bank::withdraw(){
    fstream file,file1;
    string t_id;
    float amt;
    bool found = false;
    system("cls");
    cout<<"\n\n\t\t\t Withdraw Amount";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File dosen't exists..";
    }else{
        cout<<"\n\n User ID :";
        cin>>t_id;
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){    //eof = end of file;
            if(t_id == id){
                cout<<"\n\n Enter Amount : ";
                cin>>amt;
                if(amt <= balance){
                    balance -= amt;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                    found = true;
                    cout<<"\n\n\t\t\t Your Amount "<<amt<<" withdrawn successfully";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n\t\t\t Your Current Balance("<<balance<<") is Less.";
                }
                found = true;
                
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance; 
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == false){
            cout<<"\n\n User ID can't found.";
        }
    }
}

void bank::transfer(){
    fstream file,file1;
    float amt;
    int found = 0;
    system("cls");
    string sender_id , reciever_id;
    cout<<"\n\n\t\t\t Transfer Money.";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File doesn't exits.";
    }else{
        cout<<"\n\n Enter Your User ID : ";
        cin>>sender_id;
        cout<<"\n\n Enter Client's User ID : ";
        cin>>reciever_id;
        cout<<"\n\n Enter Amount : ";
        cin>>amt;
        // file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(sender_id == id and amt <= balance){
                found++;
            }else if(reciever_id == id){
                found++;
            }         
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        if(found == 2){
            file.open("bank.txt",ios::in);
            file1.open("bank1.txt",ios::app|ios::out);
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
            while(!file.eof()){
                if(sender_id == id){
                    balance -= amt;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                }else if(reciever_id == id){
                    balance += amt;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt" , "bank.txt");
        }else{
            cout<<"\n\n\t\t\t Sender or Reciever is Invalid.";
        }


    }
}

void bank::pay_bills(){
    system("cls");
    fstream file,file1;
    string user_id,b_name;
    float amt;
    int found = 0;
    // SYSTEMTIME x;
    // auto timenow = 
    //   chrono::system_clock::to_time_t(chrono::system_clock::now()); 
    time_t t = std::time(nullptr);
    tm* now = std::localtime(&t);
    cout<<"\n\n\t\t\t Pay Your Bills Here";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\n File Doesn't Exists";
    }else{
        cout<<"\n\n Enter User ID : ";
        cin>>user_id;
        cout<<"\n\n Bill Name : ";
        cin>>b_name;
        cout<<"\n\n Enter Amount : ";
        cin>>amt;
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(user_id == id and amt <= balance){
                balance -= amt;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                found++;
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == 1){
            // GetSystemTime(&x);
            file.open("bill.txt" , ios::app|ios::out);
            file<<user_id<<" "<<b_name<<" "<<amt<<" "<<now->tm_mday << '/' << (now->tm_mon + 1) << '/'
            << (now->tm_year + 1900)<<"\n";
            file.close();
            cout<<"\n\n\t\t\t"<<b_name<<" Bill paid Successfully.";
        }else{
            cout<<"\n\n\t\t\t  User ID or Amount Invalid.";
        }
    }
}

void bank::search(){
    system("cls");
    string user_id;
    bool found = false;
    cout<<"\n\n\t\t\t Search User Record";
    fstream file;
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n\t\t\t File Doesn't Exists.";
    }else{
        cout<<"\n\n Enter User ID : ";
        cin>>user_id;
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(user_id == id){
                system("cls");
                cout<<"\n\n\t\t\t Search User Record";
                cout<<"\n\n User ID: "<<id<<"\n"<<" Name: "<<name<<"\n"<<" Father's Name: "<<fname<<"\n";
                cout<<" Address: "<<address<<"\n"<<" Pin: "<<pin<<"\n"<<" Password "<<pwd<<"\n";
                cout<<" Phone No. "<<phone<<"\n"<<" Current Balance "<<balance<<"\n";
                found = true;
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        if(found == false){
            cout<<"\n\n\t\t\t User Can't be Found.";
        }
    }
}

void bank::edit_user(){
    system("cls");
    string u_id;
    bool found = false;
    fstream file,file1;
    int new_pn , new_p;
    string new_n,new_fn,new_a,new_pwd;
    cout<<"\n\n\t\t\t Edit User Record";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File doesn't Exists.";
    }else{
        cout<<"\n\n Enter User ID : ";
        cin>>u_id;
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(u_id == id){
                cout<<"\n\n\t Name : ";
                cin>>new_n;
                cout<<"\n\n\t Father's Name : ";
                cin>>new_fn;
                cout<<"\n\n\t Address : ";
                cin>>new_a;
                cout<<"\n\n\t Pin Code : ";
                cin>>new_pn;
                cout<<"\n\n\t\t\t Password : ";
                cin>>new_pwd;
                cout<<"\n\n\t\t\t Phone Number : ";
                cin>>new_p;                

                file1<<" "<<id<<" "<<new_n<<" "<<new_fn<<" "<<new_a<<" "<<new_pn<<" "<<new_pwd<<" "<<new_p<<" "<<balance<<"\n";   
                cout<<"\n\n\t\t\t Your Record Updated Successfully.";
                found = true;
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == false){
            cout<<"\n\n\t\t\t User Can't be Found.";
        }
    }
}

void bank::del_user(){
    system("cls");
    string u_id;
    bool found = false;
    fstream file,file1;
    cout<<"\n\n\t\t\t Edit User Record";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File doesn't Exists.";
    }else{
        cout<<"\n\n Enter User ID : ";
        cin>>u_id;
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(u_id == id){           
                cout<<"\n\n\t\t\t Record Deleted Successfully.";
                found = true;
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == false){
            cout<<"\n\n\t\t\t User Can't be Found.";
        }
    }
}

void bank::all_records(){
    system("cls");
    fstream file;
    bool found = false;
    cout<<"\n\n\t\t\t All User's Records";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File doesn't Exist.";
    }else{
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            cout<<"\n\n User ID : "<<id;
            cout<<"\n\n Name : "<<name;
            cout<<"\n\n Father's Name : "<<fname;
            cout<<"\n\n Address : "<<address;
            cout<<"\n\n Pin : "<<pin;
            cout<<"\n\n Password : "<<pwd;
            cout<<"\n\n Phone : "<<phone;
            cout<<"\n\n Balance : "<<balance;
            cout<<"\n\n****************************************************";
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
            found = true;
        }
        file.close();
        if(found == false){
            cout<<"\n\n\t\t\t Database is Empty.";
        }
    }
}

void bank::payment_history(){
    system("cls");
    fstream file;
    float amt;
    string date;
    bool found = false;
    // auto timenow = 
    //   chrono::system_clock::to_time_t(chrono::system_clock::now()); 
    cout<<"\n\n\t\t\t Transaction Records";
    file.open("bill.txt" , ios::in);
    if(!file){
        cout<<"\n\n File doesn't Exist.";
    }else{   
        // file<<user_id<<" "<<b_name<<" "<<amt<<" "<<ctime(&timenow)<<"\n";     
        file>>id>>name>>amt>>date;
        while(!file.eof()){
            cout<<"\n\n User ID : "<<id;
            cout<<"\n\n Bill Name : "<<name;            
            cout<<"\n\n Bill Amount : "<<amt;
            cout<<"\n\n Date : "<<date;
            cout<<"\n\n****************************************************";
            file>>id>>name>>amt>>date;
            found = true;
        }
        file.close();
        if(found == false){
            cout<<"\n\n\t\t\t Database is Empty.";
        }
    }
}

void bank::user_balance(){
    system("cls");
    string u_id,u_pwd;
    string pin;
    char ch;
    bool found = false;
    cout<<"\n\n\t\t\t User Login & Check Balance";
    fstream file;
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File Doesn't Exists.";
    }else{
        cout<<"\n\n\t User ID : ";
        cin>>u_id;
        cout<<"\n\n\t Password : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            u_pwd += ch;
            cout<<"*";
        }
        cout<<"\n\n\t Pin Code : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            pin += ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){
            if(u_id == id && u_pwd == pwd && pin == pin){
                cout<<"\n\n\t\t\t Your Current Balance is "<<balance;
                found = true;
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        }
        file.close();
        if(found == false){
            cout<<"\n\n\t\t\t Invalid Login Credentials.";
        }
    }
}

void bank::withdraw_atm(){
    fstream file,file1;
    string t_id,t_pwd,pin;
    float amt;
    char ch;
    bool found = false;
    system("cls");
    cout<<"\n\n\t\t\t Withdraw Amount";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File dosen't exists..";
    }else{
        cout<<"\n\n User ID :";
        cin>>t_id;
        cout<<"\n\n\t Password : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            t_pwd += ch;
            cout<<"*";
        }
        cout<<"\n\n\t Pin Code : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            pin += ch;
            cout<<"*";
        }
        file1.open("bank1.txt" , ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){    
            if(t_id == id && t_pwd == pwd && pin == pin){
                cout<<"\n\n Enter Amount : ";
                cin>>amt;
                if(amt <= balance){
                    balance -= amt;
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                    found = true;
                    cout<<"\n\n\t\t\t Your Amount "<<amt<<" withdrawn successfully";
                    cout<<"\n\n\t\t\t Your Current Balance Is : "<<balance;
                }else{
                    file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\n\t\t\t Your Current Balance("<<balance<<") is Less.";
                }
                found = true;
                
            }else{
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pwd<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance; 
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt" , "bank.txt");
        if(found == false){
            cout<<"\n\n User ID can't found.";
        }
    }
}

void bank::user_details(){
    fstream file;
    string t_id,t_pwd,pin;
    char ch;
    bool found = false;
    system("cls");
    cout<<"\n\n\t\t\t Check Account Details";
    file.open("bank.txt" , ios::in);
    if(!file){
        cout<<"\n\n File dosen't exists..";
    }else{
        cout<<"\n\n User ID :";
        cin>>t_id;
        cout<<"\n\n\t Password : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            t_pwd += ch;
            cout<<"*";
        }
        cout<<"\n\n\t Pin Code : ";
        for(int i=1;i<=6;i++){
            ch = getch();
            pin += ch;
            cout<<"*";
        }
        file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance;
        while(!file.eof()){    
            if(t_id == id && t_pwd == pwd && pin == pin){
                system("cls");
                cout<<"\n\n\t\t\t Check Account Details";
                cout<<"\n\n User ID : "<<id;
                cout<<"\n\n Name : "<<name;
                cout<<"\n\n Father's Name : "<<fname;
                cout<<"\n\n Address : "<<address;
                cout<<"\n\n Pin : "<<pin;
                cout<<"\n\n Password : "<<pwd;
                cout<<"\n\n Phone : "<<phone;
                cout<<"\n\n Balance : "<<balance;
                found = true;            
            }
            file>>id>>name>>fname>>address>>pin>>pwd>>phone>>balance; 
        }
        file.close();
        if(found == false){
            cout<<"\n\n User ID can't found.";
        }
    }
}

int main(){
    cout<<"Jai Shri Ram"<<endl;
    cout<<"namaste bharat"<<endl;
    bank obj;
    introduction();
    obj.menu();
    return 0;
}