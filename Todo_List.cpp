#include <iostream>
#include <string>
using namespace std;

const int MAXIMUM_TASKS = 100;

class todo
{
    struct Task
    {
        string name;
        bool complete;
    };

    Task t[MAXIMUM_TASKS];
    int taskcount;

public:
    todo()
    {
        taskcount = 0;
    }

    void addTask(const string &name)
    {
        if (taskcount < MAXIMUM_TASKS)
        {
            t[taskcount].name = name;
            t[taskcount].complete = false;
            taskcount++;
            cout << "Successfully Task added!" << endl;
        }
        else
        {
            cout << "Task list is full, can't able to add more tasks!" << endl;
        }
    }

    void display()
    {
        if (taskcount == 0)
        {
            cout << " No task to display.\n";
        }
        else
        {
            cout << "Tasks:\n";
            for (int i = 0; i < taskcount; i++)
            {
                cout << i + 1 << ".";
                if (t[i].complete)
                {
                    cout << " [X]";
                }
                else
                {
                    cout << " [ ]";
                }
                cout << t[i].name << endl;
            }
        }
    }

    void deleteTask(int taskno)
    {
        if (taskno >= 1 && taskno <= taskcount)
        {
            for (int i = taskno - 1; i < taskcount; i++)
            {
                t[i] = t[i + 1];
            }
            taskcount--;
            cout << "Successfully Task is deleted!\n";
        }
        else
        {
            cout << "Invalid task number.\n";
        }
    }
};

int main()
{

    todo todolist;
    cout << "******************* TODO LIST MANAGER *******************\n";
    while (true)
    {
        cout << "1. Add Task\n";
        cout << "2. Display Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";

        int k;
        cin >> k;

        if (k == 1)
        {
            string name;
            cout << "Enter task name or description:";
            cin.ignore();
            getline(cin, name);
            todolist.addTask(name);
        }
        else if (k == 2)
        {
            todolist.display();
        }
        else if (k == 3)
        {
            int taskno;
            cout << "Enter the task number to delete:";
            cin >> taskno;
            todolist.deleteTask(taskno);
        }
        else if (k == 4)
        {
            cout << "Thank you for using this!\n";
            break;
        }
        else
        {
            cout << "Invalid number. Try again.\n";
        }
    }
    return 0;
}