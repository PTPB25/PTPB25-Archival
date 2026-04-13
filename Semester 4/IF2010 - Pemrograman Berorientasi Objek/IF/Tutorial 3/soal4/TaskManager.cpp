#include "TaskManager.hpp"

bool isSameId(const Task& t1, const string& id) {
    return t1.getId() == id;
}

void TaskManager::add(const string& id, const string& title, int priority, int duration) {
    tasks.push_back(Task(id, title, priority, duration));
}

void TaskManager::add(const Task& task) {
    tasks.push_back(task);
}

void TaskManager::update(const string& id, const string& title, int priority, int duration) {
    auto it = find_if(tasks.begin(), tasks.end(), [&id](const Task& task) {return task.getId() == id;});

    if(it != tasks.end()) {
        it->setTitle(title);
        it->setPriority(priority);
        it->setDuration(duration);
    }
}

bool TaskManager::remove(const string& id) {
    auto it = find_if(tasks.begin(), tasks.end(), [&id](const Task& task) {return task.getId() == id;});

    if(it != tasks.end()) {
        tasks.erase(it);
        return true;
    }
    return false;
}

const Task* TaskManager::find(const string& id) const {
    auto it = find_if(tasks.begin(), tasks.end(), [&id](const Task& task) {return task.getId() == id;});

    if(it != tasks.end()) {
        return &(*it);   
    }
    return nullptr;
}

void TaskManager::sort() {
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if(a.getPriority() != b.getPriority())
            return a.getPriority() > b.getPriority();
        if(a.getDuration() != b.getDuration())
            return a.getDuration() < b.getDuration();
        return a.getId() < b.getId();
    });
}

long long TaskManager::totalDuration(long long minPriority) const {
    return accumulate(tasks.begin(), tasks.end(), 0LL, [minPriority](int lhs, const Task& task) {
        if(task.getPriority() >= minPriority) return lhs + task.getDuration(); 
        else return lhs;
    });
}

void TaskManager::print(const string& keyword) const {
    auto start = tasks.begin();
    bool found = false;
    while(start != tasks.end()) {
        auto it = find_if(start, tasks.end(), [&keyword](const Task& task) {
            int index = task.getTitle().find(keyword);
            return index != string::npos; 
        });
        if (it != tasks.end()) {
            found = true;
            Task task = *it;
            cout << task.getId() << "|" << task.getTitle() << "|" << task.getPriority() << "|" << task.getDuration() << "\n";
            start = it + 1;
        }
        else {
            start = it;
        }
    }
    if(!found) cout << "EMPTY\n";
}

void TaskManager::print() const {
    if(tasks.empty()) {
        cout << "EMPTY\n";
        return;
    }
    for_each(tasks.begin(), tasks.end(), [](const Task& task) {
        cout << task.getId() << "|" << task.getTitle() << "|" << task.getPriority() << "|" << task.getDuration() << "\n";
    });
}