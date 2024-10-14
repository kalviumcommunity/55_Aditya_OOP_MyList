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

    Task(string t, string d)
        : title(t), description(d), isCompleted(false) {
        taskCount++;
    }

    virtual ~Task() {
        cout << "Task '" << title << "' is being destroyed." << endl;
        taskCount--;
    }

    string getTitle() const {
        return this->title;
    }

    void setTitle(const string& t) {
        this->title = t;
    }

    string getDescription() const {
        return this->description;
    }

    void setDescription(const string& d) {
        this->description = d;
    }

    bool getIsCompleted() const {
        return this->isCompleted;
    }

    void setIsCompleted(bool completed) {
        this->isCompleted = completed;
    }

    void markAsCompleted() {
        setIsCompleted(true);
    }

    virtual void displayTask() const = 0; 

    static int getTaskCount() {
        return taskCount;
    }
};


int Task::taskCount = 0;

class PriorityTask : public Task {
private:
    int priority;

public:
    PriorityTask(string t, string d, int p)
        : Task(t, d), priority(p) {}

    int getPriority() const {
        return this->priority;
    }

    void setPriority(int p) {
        this->priority = p;
    }

    
    void displayTask() const override {
        cout << "Title: " << getTitle() << ", Description: " << getDescription()
             << ", Status: " << (getIsCompleted() ? "Completed" : "Pending") << endl;
        cout << "Priority: " << getPriority() << endl;
    }
};


class TimedTask : public PriorityTask {
private:
    string deadline;

public:
    TimedTask(string t, string d, int p, string dl)
        : PriorityTask(t, d, p), deadline(dl) {}

    string getDeadline() const {
        return this->deadline;
    }

    void setDeadline(const string& dl) {
        this->deadline = dl;
    }

    void displayTask() const override {
        PriorityTask::displayTask();
        cout << "Deadline: " << getDeadline() << endl;
    }
};

class TaskManager {
private:
    vector<Task*> tasks;

public:
    static int completedTasksCount;

    const vector<Task*>& getTasks() const {
        return this->tasks;
    }

    void addTask(Task* task) {
        this->tasks.push_back(task);
    }

    void markTaskAsCompleted(const string& title) {
        for (auto& task : this->tasks) {
            if (task->getTitle() == title) {
                task->markAsCompleted();
                completedTasksCount++;
                break;
            }
        }
    }

    void displayAllTasks() const {
        for (const auto& task : getTasks()) {
            task->displayTask();
            cout << endl;
        }
    }

    ~TaskManager() {
        for (auto task : tasks) {
            delete task;  
        }
    }
};

int TaskManager::completedTasksCount = 0;

int main() {
    TaskManager manager;

    Task* task1 = new PriorityTask("Buy groceries", "Buy milk, eggs, and bread", 2);
    Task* priorityTask = new PriorityTask("Complete project", "Finish project by the weekend", 1);
    Task* timedTask = new TimedTask("Submit assignment", "Complete and submit the assignment", 1, "2024-10-15");

    manager.addTask(task1);
    manager.addTask(priorityTask);
    manager.addTask(timedTask);

    cout << "All tasks:" << endl;
    manager.displayAllTasks();

    manager.markTaskAsCompleted("Buy groceries");

    cout << "\nAll tasks after marking 'Buy groceries' as completed:" << endl;
    manager.displayAllTasks();

    cout << "\nTotal number of tasks created: " << Task::getTaskCount() << endl;
    cout << "Total number of tasks completed: " << TaskManager::completedTasksCount << endl;

    return 0;
}
