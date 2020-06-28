#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void login();
void registr();
void forgot();

int main()
{
  int choice;
  std::cout << "***********************************LOGIN**********************************" << '\n';
  std::cout << "1. Login" << '\n';
  std::cout << "2. Rgister" << '\n';
  std::cout << "3. Forgot Credentials" << '\n';
  std::cout << "4. Exit" << '\n';
  std::cout << "Enter your choice : " << '\n';
  cin>>choice;

  switch(choice)
  {
    case 1 :
          login();
          break;
    case 2 :
          registr();
          break;
    case 3 :
          forgot();
          break;
    case 4 :
          std::cout << "Thanks for using the login page" << '\n';
          break;
    default :
          std::cout << "Sorry, wrong choice selected" << '\n';
          main();

  }
  return 0;
}

void registr()
{
  string reg_user , reg_pass;
  system("cls");
  std::cout << "Enter the username : " << '\n';
  std::cin >> reg_user;
  std::cout << "Enter the password : " << '\n';
  std::cin >> reg_pass;

  ofstream reg("database.txt" , ios::app);
  reg<<reg_user<<" "<<reg_pass<<endl;
  system("cls");
  std::cout << "Registration Succesful " << '\n';
  main();

}

void login()
{
  int exist;
  std::string user , pass , u , p;
  system("cls");
  std::cout << "Enter the username : " << '\n';
  std::cin >> user;
  std::cout << "Enter the password : " << '\n';
  std::cin >> pass;
  ifstream input("database.txt");

  while (input>>u>>p)
  {
    if(u==user && p==pass)
    {
      exist = 1;
    }
  }
  input.close();
  if(exist == 1)
  {
    std::cout << "Hello " << user << '\n'<<"We're glad that you're here"<<"\n";
    cin.get();
    cin.get();
    system("cls");
    main();

  }
  else
  {
    std::cout << "Sorry, Login error .  " << '\n';
    cin.get();
    cin.get();
    system("cls");
    main();

  }
}

void forgot()
{
  int ch;
  system("cls");
  std::cout << "1. Search your account by username " << '\n';
  std::cout << "2. Search your account by password " << '\n';
  std::cout << "3. Main Menu " << '\n';
  std::cout << "Enter your choice : " << '\n';
  std::cin >> ch;

  switch (ch)
  {
    case 1:
    {    int ex=0;
        string search_user , su , sp ;
        std::cout << "Enter your remembered username :" << '\n';
        std::cin >> search_user;

        ifstream search_user_file("database.txt");
        while (search_user_file>>su>>sp)
        {
          if(su == search_user)
          {
            ex = 1;
            break;
          }
        }

        search_user_file.close();
        if(ex==1)
        {
            std::cout << "Hurray !  Account found !" << '\n';
            std::cout << "Your password is "<<sp << '\n';
            std::cout << "Your username is "<<su << '\n';
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
          std::cout << "Sorry, Your accountis not found " << '\n';
          cin.get();
          cin.get();
          main();

        }

    }    break;
    case 2 :
    {
        int exi=0 ;
        string search_pass , su2 , sp2;
        std::cout << "Enter your remembered password :" << '\n';
        std::cin >> search_pass;

        ifstream search_user_pass("database.txt");
        while (search_user_pass>>su2>>sp2)
        {
          if(sp2 == search_pass)
          {
            exi = 1;
            break;
          }
        }

        search_user_pass.close();
        if(exi==1)
        {
            std::cout << "Hurray !  Account found !" << '\n';
            std::cout << "Your usernsme is "<<su2 << '\n';
            std::cout << "Your password is "<<sp2 << '\n';
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
          std::cout << "Sorry, Your accountis not found " << '\n';
          cin.get();
          cin.get();
          main();
        }

        break;
    }
    case 3:
    {
        main();
        break;
    }
    default:
    {
        std::cout << "You have given a wrong choice. Press any key to try again. " << '\n';
        cin.get();
        cin.get();
        forgot();
    }
  }

}
