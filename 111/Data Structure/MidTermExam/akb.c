#include <stdio.h>

typedef struct userInput {
    char device;
    int cpu_time;
    int drive_time;
    int printer_time;
} userInput;

typedef struct processQueue {
    int top;
    int time[25];
} processQueue;

void pushProcessQueue(processQueue *s, int min) {
    s->top++;
    s->time[s->top] = min;
}

int main(void) {
    int tasks = 0;

    userInput current;
    processQueue cpuProcess;
    processQueue driveProcess;
    processQueue printerProcess;

    cpuProcess.top = -1;
    driveProcess.top = -1;
    printerProcess.top = -1;

    scanf("%d", &tasks);

    int cpuTasks = tasks;
    int driveTasks = tasks;
    int printerTasks = tasks;

    for (int i = 0; i < tasks; i++) {
        scanf("%s %d %d %d", current.device, &current.cpu_time, &current.drive_time, &current.printer_time);

        pushProcessQueue(&cpuProcess, current.cpu_time);
        pushProcessQueue(&driveProcess, current.drive_time);
        pushProcessQueue(&printerProcess, current.printer_time);
    }

    for (int i = 0; i < tasks; i++) {
        if ((cpuProcess.time[i] > 1) && (cpuProcess.time[i + 1] == 0)) {
            for (int j = i + 1; j < cpuTasks - 1; j++) {
                cpuProcess.time[j] = cpuProcess.time[j + 1];
            }
            cpuTasks--;
        }

        if ((driveProcess.time[i] > 1) && (driveProcess.time[i + 1] == 0)) {
            for (int j = i + 1; j < driveTasks - 1; j++) {
                driveProcess.time[j] = driveProcess.time[j + 1];
            }
            driveTasks--;
        }

        if ((printerProcess.time[i] > 1) && (printerProcess.time[i + 1] == 0)) {
            for (int j = i + 1; j < printerTasks - 1; j++) {
                printerProcess.time[j] = printerProcess.time[j + 1];
            }
            printerTasks--;
        }
    }

    for (int i = 0; i < cpuTasks; i++) {
        if ((cpuProcess.time[i] > 2)) {
            for (int j = i; j < cpuProcess.time[i]; j++) {

            }
        }
    }
}