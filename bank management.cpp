 #include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

    char mainMenu();
    void createAccount();
    char bankingMenu();
   class bank
   {
    int bal;
    public :
    void deposit(void);
    void withdraw(void);
    void login(void);
    void displayBalance();
    void ShowTransHist();
    };
int main()
{

    char choice;
    bank account;
    while (choice != 'q' || choice != 'Q')
    {
        choice = mainMenu();
        if (choice == 'q' || choice == 'Q'){
         cout << "Thanks for stopping by Justin's Bank!";   break;}
        switch (choice)
        {
        case 'l':
        case 'L':
            account.login();
            break;
        case 'c':
        case 'C':
            createAccount();
            break;
        case 'v':
        case 'V':
            cout << "Thank you for using our bank.\nFor your continuous support,we are offering 3% cash back on all debit purchases." << endl;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
char mainMenu()
{
    char choice;
    cout << "********** MAIN MENU ********** " << endl << endl;
    cout << "l(L) -> Login to Banking Menu" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "v -> View Promotions" << endl;
    cout << "q -> Quit the Program" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    return choice;

}
void createAccount()
{

   string username;
   string password;
   cout << "Please create a username" << endl;
   cin >> username;
   cout << "Please create a password" << endl;
   cin >> password;
   ofstream createaccount;
   createaccount.open("accounts.txt", ios::app);
   createaccount << username << " " << password << endl;
   createaccount.close();
   cout << "Account created!" << endl;

}
void bank :: login(void)
{
   string username;
   string password;
   char choice;
   bank decision;
   ifstream savedaccount;
   savedaccount.open("accounts.txt");
   cout << "Enter your username:" << endl;
   cin >> username;
   cout << "Enter your password:" << endl;
   cin >> password;
   string username2, password2;
   savedaccount >> username2 >> password2;
   savedaccount.close();
   if (username != username2 || password != password2)
    cout << "Incorrect login! Create new account or try again." << endl;
    while(username == username2 && password == password2)
    {
        choice = bankingMenu();
        if (choice == 'q' || choice =='Q') break;
        switch (choice){


case 'd':
case 'D':
    decision.deposit();
    break;
case 'w':
case 'W':
    decision.withdraw();
    break;
case 'b':
case 'B':
    decision.displayBalance();
    break;
case 'r':
case 'R':
    decision.ShowTransHist();
    break;
default:
    cout << "Invalid choice!" << endl;

        }
}
}
char bankingMenu()
{
    char choice;
    cout << "********* BANKING MENU *********" << endl << endl;
    cout << "d. Deposit Money" << endl;
    cout << "w. Withdraw Money" << endl;
    cout << "b. Check Balance" << endl;
    cout << "r. Review Account Activities History" << endl;
    cout << "q. Return to Main Menu" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    return choice;
    }
void bank :: deposit(void)
{
   long deposit;
   cout << "Enter how much you would like to deposit: ";
   cin >> deposit;
   bal = deposit+bal;
   cout << "You have deposited: $" << deposit << endl;
   if (deposit >= 100000)
    cout << "Now that is a lot of money!" << endl;

}
void bank :: withdraw(void)
{
    long withdraw;
    cout << "Enter how much you would like to withdraw: ";
    cin >> withdraw;
    if (bal > withdraw || bal == withdraw){
    bal= bal - withdraw;
    cout << "You have withdrawn: $" << withdraw << endl;}
    else if (bal < withdraw)
    cout << "You don't have enough funds to cover your withdraw request!" << endl;
}
void bank :: displayBalance()
{
    cout << "Your current balance is: $" << bal << endl;
    if (bal >= 1000000)
        cout << "Wow, you're a high roller!" << endl;
}
void bank :: ShowTransHist()
{
   ofstream balance;
   int bal;
   balance.open("transHistory.output", std::ios_base::app);
   balance << bal << endl;
}
