#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Function to add a task
void addTask() {
    string taskDesc;
    cin.ignore();
    cout << "Enter task description: ";
    getline(cin, taskDesc);
    tasks.push_back({taskDesc, false});
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to mark a task as completed
void markCompleted() {
    int taskNum;
    viewTasks();
    if (tasks.empty()) return;
    cout << "Enter task number to mark as completed: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks[taskNum - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask() {
    int taskNum;
    viewTasks();
    if (tasks.empty()) return;
    cout << "Enter task number to remove: ";
    cin >> taskNum;
    if (taskNum > 0 && taskNum <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}