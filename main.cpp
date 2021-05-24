#include <iostream>
#include <sstream>
#include "main.h"

using namespace std;

string usageString ()
{
  return "Welcome to your Todo List! Follow the Menu Below to Navigate Through the App\n"
    "(1) Add Todo\n"
    "(2) Open all the Current Todos\n"
    "(3) Mark Todo as Done\n"
    "(4) Help \n"
    "(5) Quit\n";
}

void usage() {
  cout << usageString() << endl;
}

void addTodo(TodoList &tl) {
  string title;
  Todo todo;

  cout << "Whats your Todo?";
  getline(cin, title);
  tl.addTodo(title);
  cout << endl << "Todo added!" << endl;
}

int main()
{
  TodoList todoList;
  usage();
  string inputOption, inputToggle;
  int option, toggle;

  while (1) {
    getline(cin, inputOption);
    stringstream(inputOption) >> option;

    switch (option) {
      case 1:
        addTodo(todoList);
        break;
      case 2:
        todoList.listTodos();
        break;
      case 3:
        cout << "Which task would you like to mark as done?";
        getline(cin, inputToggle);
        stringstream(inputToggle) >> toggle;
        todoList.toggleTodo(toggle);
        cout << endl;
        break;
      case 0:
        cout << "no 0 and no letters" << endl;
        return 1;
      case 5:
        cout << "See you!" << endl;
        return 0;
      default:
        usage();
        break;
    }
  }
}
