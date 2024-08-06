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

class TaskManager {
private:
    vector<Task> tasks;

public:
    
    void addTask(const Task& task) {
        this->tasks.push_back(task); 
    }

    void markTaskAsCompleted(const string& title) {
        for (auto& task : this->tasks) { 
            if (task.getTitle() == title) {
                task.markAsCompleted();
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

int main() {
    
    TaskManager manager;

    Task taskArray[] = {
        Task("Buy groceries", "Buy milk, eggs, and bread"),
        Task("Finish assignment", "Complete the OOP assignment"),
        Task("Exercise", "Go for a run"),
        Task("Read book", "Read 'The Great Gatsby'")
    };

    
    for (const auto& task : taskArray) {
        manager.addTask(task);
    }

    
    cout << "All tasks:" << endl;
    manager.displayAllTasks();

    
    manager.markTaskAsCompleted("Buy groceries");
    manager.markTaskAsCompleted("Read book");

    
    cout << "\nAll tasks after marking the first task as completed:" << endl;
    manager.displayAllTasks();

    return 0;
}
