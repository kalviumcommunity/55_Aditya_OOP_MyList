#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
private:
    string title;
    string description;
    bool isCompleted;

public:
    // Constructor
    Task(string t, string d)
        : title(t), description(d), isCompleted(false) {}

    
    void markAsCompleted() {
        isCompleted = true;
    }

    
    void displayTask() const {
        cout << "Title: " << title << ", Description: " << description
             << ", Status: " << (isCompleted ? "Completed" : "Pending") << endl;
    }

    
    string getTitle() const {
        return title;
    }
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    // Add a task to the list
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    
    void markTaskAsCompleted(const string& title) {
        for (auto& task : tasks) {
            if (task.getTitle() == title) {
                task.markAsCompleted();
                break;
            }
        }
    }

    // Display all tasks
    void displayAllTasks() const {
        for (const auto& task : tasks) {
            task.displayTask();
        }
    }
};

int main() {
    // Create TaskManager object
    TaskManager manager;

    // Create Task objects
    Task task1("Buy groceries", "Buy milk, eggs, and bread");
    Task task2("Finish assignment", "Complete the OOP assignment");

    // Add tasks to the manager
    manager.addTask(task1);
    manager.addTask(task2);

    // Display all tasks
    cout << "All tasks:" << endl;
    manager.displayAllTasks();


    manager.markTaskAsCompleted("Buy groceries");

    
    cout << "\nAll tasks after marking the first task as completed:" << endl;
    manager.displayAllTasks();

    return 0;
}
