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
    static int taskCount; 

    // Constructor
    Task(string t, string d)
        : title(t), description(d), isCompleted(false) {
        taskCount++;  
    }

    Task& setTitle(const string& t) {
        this->title = t;
        return *this;
    }

    Task& setDescription(const string& d) {
        this->description = d;
        return *this;
    }

    void markAsCompleted() {
        this->isCompleted = true;
    }

    void displayTask() const {
        cout << "Title: " << title << ", Description: " << description
             << ", Status: " << (isCompleted ? "Completed" : "Pending") << endl;
    }

    string getTitle() const {
        return this->title;
    }
};


int Task::taskCount = 0;

class TaskManager {
private:
    vector<Task> tasks;
    
public:
    static int completedTasksCount;  

    void addTask(const Task& task) {
        this->tasks.push_back(task);
    }

    void markTaskAsCompleted(const string& title) {
        for (auto& task : this->tasks) {
            if (task.getTitle() == title) {
                task.markAsCompleted();
                completedTasksCount++;  
                break;
            }
        }
    }

    void displayAllTasks() const {
        for (const auto& task : tasks) {
            task.displayTask();
        }
    }
};


int TaskManager::completedTasksCount = 0;

int main() {
    TaskManager manager;

    Task* task1 = new Task("Buy groceries", "Buy milk, eggs, and bread");
    Task* task2 = new Task("Finish assignment", "Complete the OOP assignment");
    Task* task3 = new Task("Exercise", "Go for a run");
    Task* task4 = new Task("Read book", "Read 'The Great Gatsby'");

    manager.addTask(*task1);
    manager.addTask(*task2);
    manager.addTask(*task3);
    manager.addTask(*task4);

    cout << "All tasks:" << endl;
    manager.displayAllTasks();

    manager.markTaskAsCompleted("Buy groceries");
    manager.markTaskAsCompleted("Read book");

    cout << "\nAll tasks after marking some tasks as completed:" << endl;
    manager.displayAllTasks();

    
    cout << "\nTotal number of tasks created: " << Task::taskCount << endl;
    cout << "Total number of tasks completed: " << TaskManager::completedTasksCount << endl;

    delete task1;
    delete task2;
    delete task3;
    delete task4;

    return 0;
}
