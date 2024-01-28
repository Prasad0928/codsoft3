#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:

    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "Task added successfully." << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << (tasks[i].completed ? "[X]" : "[ ]") << " " << tasks[i].description << endl;
            }
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index. Please enter a valid index." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task index. Please enter a valid index." << endl;
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    ToDoList toDoList;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                toDoList.markTaskCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    }
    while (choice != 5);
    return 0;
}
