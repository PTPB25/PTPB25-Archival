#ifndef TASK_MANAGER_HPP
#define TASK_MANAGER_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string id;
    string title;
    int priority;
    int duration;
public:
    /* CONSTRUCTOR */
    Task(const string& id, const string& title, int priority, int duration)
        : id(id), title(title), priority(priority), duration(duration) {}

    /* GETTERS */
    const string& getId() const { return id; }
    const string& getTitle() const { return title; }
    int getPriority() const { return priority; }
    int getDuration() const { return duration; }

    /* SETTERS */
    void setTitle(const string& newTitle) { title = newTitle; }
    void setPriority(int newPriority) { priority = newPriority; }
    void setDuration(int newDuration) { duration = newDuration; }
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    /**
     * @brief Inserts a new task from raw fields into the internal container.
     * @details This overload does not check uniqueness; duplicate policy is handled by the caller.
     * @param id Unique identifier of the task.
     * @param title Display title of the task.
     * @param priority Priority value of the task.
     * @param duration Estimated duration of the task.
     */
    void add(const string& id, const string& title, int priority, int duration);

    /**
     * @brief Inserts an existing Task object into the internal container.
     * @param task Task object to be appended.
     */
    void add(const Task& task);

    /**
     * @brief Updates title, priority, and duration for the first task matching @p id.
     * @details If no matching id is found, the container remains unchanged.
     * @param id Target task identifier.
     * @param title New title value.
     * @param priority New priority value.
     * @param duration New duration value.
     */
    void update(const string& id, const string& title, int priority, int duration);

    /**
     * @brief Removes the first task matching @p id.
     * @param id Target task identifier.
     * @return true if a task is removed, false otherwise.
     */
    bool remove(const string& id);

    /**
     * @brief Finds a task by id.
     * @param id Target task identifier.
     * @return Pointer to the stored task, or nullptr if not found.
     */
    const Task* find(const string& id) const;

    /**
     * @brief Sorts tasks by priority, duration, and id.
     * @details Ordering rule: higher priority first, then shorter duration,
     *          then lexicographically smaller id.
     */
    void sort();

    /**
     * @brief Computes total duration for tasks with priority >= @p minPriority.
     * @param minPriority Minimum priority threshold.
     * @return Sum of matching task durations.
     */
    long long totalDuration(long long minPriority) const;

    /**
     * @brief Prints tasks whose title contains @p keyword as a case-sensitive substring.
     * @param keyword Substring to match against task titles.
     * @details Prints "EMPTY" if no task matches.
     */
    void print(const string& keyword) const;

    /**
     * @brief Prints all tasks in their current container order.
     * @details Prints "EMPTY" if the container has no elements.
     */
    void print() const;
};

#endif