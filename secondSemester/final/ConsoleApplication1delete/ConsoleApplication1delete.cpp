#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <memory>
#include <algorithm>
#include <array>


// Forward declaration
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hours = h;
            minutes = m;
            seconds = s;
        }
        else {
            std::cout << "Error: Invalid time values." << std::endl;
        }
    }

    std::string getTime() const {
        std::string h = (hours < 10 ? "0" : "") + std::to_string(hours);
        std::string m = (minutes < 10 ? "0" : "") + std::to_string(minutes);
        std::string s = (seconds < 10 ? "0" : "") + std::to_string(seconds);

        return std::format("{}:{}:{}", h, m, s);
    }

    friend bool operator==(const Time& t1, const Time& t2);
    friend bool operator<(const Time& t1, const Time& t2);
    friend bool operator<=(const Time& t1, const Time& t2);
    friend bool operator>=(const Time& t1, const Time& t2);
    friend bool operator!=(const Time& t1, const Time& t2);
    friend bool operator>(const Time& t1, const Time& t2);
};

bool operator==(const Time& t1, const Time& t2) {
    return (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds);
}

bool operator!=(const Time& t1, const Time& t2) {
    return (t1.hours != t2.hours && t1.minutes != t2.minutes && t1.seconds != t2.seconds);
}

bool operator<(const Time& t1, const Time& t2) {
    if (t1.hours < t2.hours)
        return true;
    else if (t1.hours == t2.hours && t1.minutes < t2.minutes)
        return true;
    else if (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds < t2.seconds)
        return true;
    else
        return false;
}

bool operator>(const Time& t1, const Time& t2) {
    return t2 < t1;
}

bool operator<=(const Time& t1, const Time& t2) {
    return t1 < t2 || t1 == t2;
}

bool operator>=(const Time& t1, const Time& t2) {
    return t2 <= t1;
}

enum class DegreeImp {
    notImp,
    imp,
    veryimp
};

// Declaration of Attachment class
class Attachment {
public:
    std::string nameFile;
    std::string directory;
};

// Definition of Attachments class
class Attachments {
public:
    std::vector<Attachment> attachments;

    void push_back(const Attachment& attachment) {
        attachments.push_back(attachment);
    }

    void print() const {
        for (const Attachment& attachment : attachments) {
            std::cout << attachment.nameFile << " ";
        }
        std::cout << std::endl;
    }

    bool is_empty() const {
        return attachments.empty();
    }
    
};

// Declaration of Time class

// Declaration of Task class
class Task {
private:
    std::string name;
    std::string description;
    Attachments attachments;
    Time timeComplection;
    Time settingTime;
    DegreeImp degreeImpotant;

public:
    Task() {}

    Task(const std::string& name, const std::string& description, const Time& timeComplection, DegreeImp degreeImpotant)
        : name(name), description(description), timeComplection(timeComplection), degreeImpotant(degreeImpotant) {}

    std::string getName() const {
        return name;
    }

    std::string getDescription() const {
        return description;
    }

    void setDescription(const std::string& description) {
        this->description = description;
    }

    Attachments getAttachments() const {
        return attachments;
    }

    void setAttachments(const Attachments& attachments) {
        this->attachments = attachments;
    }

    Time getTimeComplection() const {
        return timeComplection;
    }

    void setTimeComplection(const Time& timeComplection) {
        this->timeComplection = timeComplection;
    }

    Time getSettingTime() const {
        return settingTime;
    }

    void setSettingTime(const Time& settingTime) {
        this->settingTime = settingTime;
    }

    DegreeImp getDegreeImpotant() const {
        return degreeImpotant;
    }

    void setDegreeImpotant(DegreeImp degreeImpotant) {
        this->degreeImpotant = degreeImpotant;
    }
    std::tuple<std::string, std::string, Attachments, Time, Time, DegreeImp> getTaskData() const {
        return std::make_tuple(name, description, attachments,timeComplection,settingTime, degreeImpotant);
    }
};

bool operator==(const Task& task1, const Task& task2) {
    return task1.getDescription() == task2.getDescription();
}

bool operator<(const Task& task1, const Task& task2) {
    return task1.getTimeComplection() < task2.getTimeComplection();
}

bool operator>(const Task& task1, const Task& task2) {
    return task1.getTimeComplection() > task2.getTimeComplection();
}

// Declaration of NodeList class
class NodeList {
public:
    int cnt;
    Task task;
    NodeList* next;

    NodeList(const Task& v) : task(v), next(nullptr), cnt(1) {}
};

// Declaration of ListTask class
class ListTask {
public:
    NodeList* head;

    ListTask() : head(nullptr) {}

    bool findTaskByName(const Task& item) {
        NodeList* curr = head;
        if (curr == nullptr)
            return false;
        do {
            if (curr->task == item) {
                return true;
            }
            curr = curr->next;
        } while (curr != head);
        return false;
    }

    void add_node(const Task& item) {
        NodeList* node = new NodeList(item);
        if (head == nullptr) {
            head = node;
            head->next = head;
        }
        else {
            NodeList* curr = head;
            do {
                if (head == curr->next) {
                    if (curr->task < item) {
                        node->next = head;
                        curr->next = node;
                    }
                    else {
                        node->next = curr;
                        curr->next = node;
                        head = node;
                    }
                    curr = head;
                }
                else if (curr->task > item) {
                    NodeList* new_node = new NodeList(curr->task);
                    new_node->next = curr->next;
                    curr->task = item;
                    curr->next = new_node;
                    curr = head;
                }
                else {
                    curr = curr->next;
                }
            } while (curr != head);
        }
    }

    void delete_node(const Task& item) {
        NodeList* curr = head;
        NodeList* curr_next = curr->next;
        if (curr == nullptr)
            return;
        do {
            if (curr == head && curr->task == item) {
                head->task = head->next->task;
                NodeList* BuffNext = head->next;
                head->next = BuffNext->next;
                delete BuffNext;
            }
            else if (curr_next != nullptr && curr_next->task == item && curr_next != head) {
                curr->next = curr->next->next;
                delete curr_next;
            }
            else {
                curr = curr->next;
                curr_next = curr->next;
            }
        } while (curr != head);
    }

    void print() {
        NodeList* curr = head;
        if (curr == nullptr)
            return;
        do {
            if (curr->task == curr->next->task) {
                curr->next->cnt = curr->cnt + 1;
            }
            std::cout << curr->task.getName() << " " << curr->task.getDescription() << "(" << curr->cnt << ")" << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << std::endl;
    }

    class IteratorListTask {
    private:
        NodeList* current;

    public:
        IteratorListTask(NodeList* start) : current(start) {}

        Task* operator->() const {
            return &(current->task);
        }

        bool operator==(const IteratorListTask& other) const {
            return current == other.current;
        }

        bool operator!=(const IteratorListTask& other) const {
            return !(*this == other);
        }

        Task& operator*() const {
            return current->task;
        }

        IteratorListTask& operator++() {
            current = current->next;
            return *this;
        }

        IteratorListTask operator++(int) {
            IteratorListTask temp = *this;
            ++(*this);
            return temp;
        }

        IteratorListTask operator+(int n) {
            IteratorListTask temp = *this;
            for (int i = 0; i < n; i++) {
                ++temp;
            }
            return temp;
        }

        bool operator<(const IteratorListTask& other) const {
            return current->task < other.current->task;
        }

        bool operator>(const IteratorListTask& other) const {
            return current->task > other.current->task;
        }
    };
};

template<typename T, std::size_t Size>
class WeekTask {
private:
    std::array<T, Size> tasks;
    std::size_t count;

public:
    WeekTask() : count(0) {}

    void addTask(const T& task) {
        if (count < Size) {
            tasks[count++] = task;
        }
        else {
            std::cout << "Cannot add more tasks. WeekTask is full." << std::endl;
        }
    }

    std::size_t size() const {
        return count;
    }

    // Iterator class
    class Iterator {
    private:
        WeekTask& container;
        std::size_t index;

    public:
        Iterator(WeekTask& container, std::size_t index) : container(container), index(index) {}

        // Required iterator operations
        Iterator& operator++() {
            ++index;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        T& operator*() const {
            return container.tasks[index];
        }
    };

    // Required container operations
    Iterator begin() {
        return Iterator(*this, 0);
    }

    Iterator end() {
        return Iterator(*this, count);
    }
};

// Declaration of WeekTaskContainerFactory class
template<typename T, std::size_t Size>
class WeekTaskContainerFactory {
public:
    static std::unique_ptr<WeekTask<T, Size>> createWeekTaskContainer() {
        return std::make_unique<WeekTask<T, Size>>();
    }
};




class Observer {
public:
    virtual void update(Task& task) = 0;
    virtual ~Observer() {}
};

class Subject {
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        // Найдем и удалим наблюдателя из вектора
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notifyObservers(Task task) {
        for (Observer* observer : observers) {
            observer->update(task);
        }
    }
};

class TaskObserver : public Observer {
public:
    void update(Task &task) override {
        std::cout << "Задача '" << task.getName() << "' была изменена." << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    // Testing the corrected code
    Time time1(9, 30, 0);
    Time time2(12, 0, 0);
    Time time3(15, 45, 0);

    std::string formattedTime = time1.getTime();
    std::cout << "Current time: " << formattedTime << std::endl;

    Task task1("Task1", "Description1", time1, DegreeImp::veryimp);
    Task task2("Task2", "Description2", time2, DegreeImp::imp);
    Task task3("Task3", "Description3", time3, DegreeImp::notImp);

    std::tuple<std::string, std::string, Attachments, Time, Time, DegreeImp> taskData = task1.getTaskData();

    // Извлечение значений из кортежа
    std::string name = std::get<0>(taskData);
    std::string description = std::get<1>(taskData);
    Attachments attachments = std::get<2>(taskData);
    Time timeComplection = std::get<3>(taskData);
    Time settingTime = std::get<4>(taskData);
    DegreeImp degreeImpotant = std::get<5>(taskData);

    // Вывод полученных значений
    //std::cout << "Task name: " << name << std::endl;
    std::cout << "Task description: " << description << std::endl;

    std::unique_ptr<WeekTask<Task, 7>> container = WeekTaskContainerFactory<Task, 7>::createWeekTaskContainer();

    container->addTask(task1);
    container->addTask(task2);
    container->addTask(task3);

    for (const auto& task : *container) {
        std::cout << task.getName() << std::endl;
    }

    
    


    Subject subject;
    TaskObserver observer1;
    TaskObserver observer2;

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Пример добавления задачи и оповещения наблюдателей
    subject.notifyObservers(task1);

    // Удаление одного из наблюдателей
    subject.removeObserver(&observer1);

    // Пример изменения задачи и оповещения оставшегося наблюдателя
    subject.notifyObservers(task2);

    


    return 0;
}
