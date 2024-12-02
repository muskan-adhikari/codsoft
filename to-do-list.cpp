#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

void displayTasks(string tasks[], bool completed[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks in the to-do list!" << endl;
    } else {
        cout << "\nTo-Do List:" << endl;
        for (int i = 0; i < taskCount; i++) {
            cout << i + 1 << ". " << tasks[i] << " [";
            if (completed[i]) {
                cout << "Completed";
            } else {
                cout << "Pending";
            }
            cout << "]" << endl;
        }
    }
}

void removeTask(string tasks[], bool completed[], int& taskCount, int taskIndex) {
    for (int i = taskIndex; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        completed[i] = completed[i + 1];
    }
    taskCount--;
    cout << "Task removed successfully!" << endl;
}

int main() {
    string tasks[MAX_TASKS];
    bool completed[MAX_TASKS] = {false}; 
    int taskCount = 0;

    int choice;
    string task;
    int taskIndex;

    do {
        cout << endl << "--- To-Do List ---" << endl;
        cout << "1. Add a Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (taskCount < MAX_TASKS) {
                    cout << "Enter the task: ";
                    getline(cin, task);
                    tasks[taskCount] = task;
                    completed[taskCount] = false;
                    taskCount++;
                    cout << "Task added successfully!" << endl;
                } else {
                    cout << "To-Do list is full!" << endl;
                }
                break;

            case 2:
                displayTasks(tasks, completed, taskCount);
                break;

            case 3:
                if (taskCount == 0) {
                    cout << "No tasks to mark as completed!" << endl;
                } else {
                    cout << "Enter task number to mark as completed: ";
                    cin >> taskIndex;
                    taskIndex--;
                    if (taskIndex >= 0 && taskIndex < taskCount) {
                        completed[taskIndex] = true;
                        cout << "Task marked as completed!" << endl;
                    } else {
                        cout << "Invalid task number!" << endl;
                    }
                }
                break;

            case 4:
                if (taskCount == 0) {
                    cout << "No tasks to remove!" << endl;
                } else {
                    cout << "Enter task number to remove: ";
                    cin >> taskIndex;
                    taskIndex--;
                    if (taskIndex >= 0 && taskIndex < taskCount) {
                        removeTask(tasks, completed, taskCount, taskIndex);
                    } else {
                        cout << "Invalid task number!" << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
