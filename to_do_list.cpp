#include<iostream>
#include<string>
#include<vector>
using namespace std;

void addTask(vector<string>& tasks){
    string task;
    cin.ignore();
    cout<<"Enter task: ";
    getline(cin, task);
    
    tasks.push_back(task);
    cout<<"Task added successfully! "<<endl;
}

void viewTasks(const vector<string>& tasks){
    if(tasks.empty()){
        cout<<"Please enter the valid task.\n";
        return;
    }
    cout<<"\n----Task List----\n";
    for(int i=0;i<tasks.size();i++){
        cout<<i+1<<". "<<tasks[i]<<endl;
    }
}

void deleteTask(vector<string>& tasks){
    if(tasks.empty()){
        cout<<"No tasks to delete.\n";
        return;
    }
    viewTasks( tasks);

    int taskNumber;
    cout<<"Enter task number to delete: ";
    cin>>taskNumber;

    if(taskNumber >= 1 && taskNumber <= tasks.size()){
        tasks.erase(tasks.begin()+taskNumber - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                deleteTask(tasks);
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}