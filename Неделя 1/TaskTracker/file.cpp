#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

// Функция для удаления нулей из словаря
void RemoveZeros(TasksInfo& tasks_info) {
    // Соберём те статусы, которые нужно убрать из словаря
    vector<TaskStatus> statuses_to_remove;
    for (const auto& task_item : tasks_info) {
        if (task_item.second == 0) {
            statuses_to_remove.push_back(task_item.first);
        }
    }
    for (const TaskStatus status : statuses_to_remove) {
        tasks_info.erase(status);
    }
}

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return staff_.at(person);
    }
  
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person)
    {
        staff_[person][TaskStatus::NEW]++;
    }
  
    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count)
    {
      try
      {
        TasksInfo person_info=staff_.at(person);
            int total_tasks = 0;
        for (const auto &task_stat : person_info)
        {
                total_tasks += task_stat.second;
        }

            if (task_count > total_tasks) task_count = total_tasks;

            TasksInfo person_updated_info;
        if(task_count < person_info[TaskStatus::NEW])
        {
                person_updated_info[TaskStatus::IN_PROGRESS] = task_count;
        }
            else
            {
                person_updated_info[TaskStatus::IN_PROGRESS] = person_info[TaskStatus::NEW];
              if(task_count - person_info[TaskStatus::NEW] < person_info[TaskStatus::IN_PROGRESS])
              {
                    person_updated_info[TaskStatus::TESTING] = task_count - person_info[TaskStatus::NEW];
              }
                else
                {
                    person_updated_info[TaskStatus::TESTING] = person_info[TaskStatus::IN_PROGRESS];
                  if(task_count - person_info[TaskStatus::NEW] - person_info[TaskStatus::IN_PROGRESS] <
                                    person_info[TaskStatus::TESTING])
                  {
                        person_updated_info[TaskStatus::DONE] = task_count - person_info[TaskStatus::NEW] - person_info[TaskStatus::IN_PROGRESS];
                  }
                    else
                    {
                        person_updated_info[TaskStatus::DONE] = person_info[TaskStatus::TESTING];
                    }
                }                              
            }

            TasksInfo person_untouched_info = person_info, person_new_info;
        for (auto item : person_updated_info) //person_untouched_info)
        {
                //item.second -= person_untouched_info[static_cast<TaskStatus>(static_cast<int>(item.first) + 1)];
                person_untouched_info[static_cast<TaskStatus>(static_cast<int>(item.first) - 1)] -= item.second;
            }

            person_new_info[TaskStatus::NEW] = person_untouched_info[TaskStatus::NEW] + person_updated_info[TaskStatus::NEW];
            person_new_info[TaskStatus::IN_PROGRESS] = person_untouched_info[TaskStatus::IN_PROGRESS] + person_updated_info[TaskStatus::IN_PROGRESS];
            person_new_info[TaskStatus::TESTING] = person_untouched_info[TaskStatus::TESTING] + person_updated_info[TaskStatus::TESTING];
            person_new_info[TaskStatus::DONE] = person_untouched_info[TaskStatus::DONE] + person_updated_info[TaskStatus::DONE];
        /*
        for (auto elem : person_new_info)
        {
                person_new_info[elem.first] = person_untouched_info[elem.first] + person_updated_info[elem.first];
        }
        */
            person_untouched_info.erase(TaskStatus::DONE);
            RemoveZeros(person_untouched_info);
            RemoveZeros(person_updated_info);
            RemoveZeros(person_new_info);
            //PrintTasksInfo(person_new_info);
            staff_[person] = person_new_info;
            return tie(person_updated_info, person_untouched_info);
      }
      catch(out_of_range) // Если такого разработчика не существует
      {
            TasksInfo a, b;
            return tie(a, b);
      }
      
    }
private:
     map<string, TasksInfo> staff_;
};