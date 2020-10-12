#ifndef TEAMTASKS_CPP
#define TEAMTASKS_CPP

#include <string>
#include <tuple>
#include "misc.cpp"

using namespace std;

class TeamTasks {
public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string &person) const {
		return m_team_tasks.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчика
	void AddNewTask(const string &person) {
		++m_team_tasks[person][TaskStatus::NEW];
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person,
			int task_count) {
		TasksInfo updated_tasks, untouched_tasks;
		if (m_team_tasks.count(person) != 0) {
			for (const auto &item : m_team_tasks[person]) {
				if (item.first == TaskStatus::DONE) {
					break;
				}

				if (task_count > 0) {
					TaskStatus next_status =
							static_cast<TaskStatus>(static_cast<int>(item.first)
									+ 1);
					if (task_count >= item.second) {
						task_count -= item.second;
						updated_tasks[next_status] = item.second;
					} else {
						untouched_tasks[item.first] = item.second - task_count;
						updated_tasks[next_status] = task_count;
						task_count = 0;
					}

				} else {
					untouched_tasks[item.first] = item.second;
				}
			}
			UpdateTasks(person, updated_tasks);
		}
		return make_tuple(updated_tasks, untouched_tasks);
	}
private:
	void UpdateTasks(const string &person, const TasksInfo &updated_tasks) {
		for (const auto &item : updated_tasks) {
			TaskStatus previous_status =
					static_cast<TaskStatus>(static_cast<int>(item.first) - 1);
			m_team_tasks[person][previous_status] -= item.second;
			if (m_team_tasks[person][previous_status] == 0) {
				m_team_tasks[person].erase(previous_status);
			}
			m_team_tasks[person][item.first] += item.second;
		}
	}
	map<string, TasksInfo> m_team_tasks;
};

#endif
