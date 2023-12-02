#include <iostream>
#include <vector>

using namespace std;

struct MemoryPartition {
    int size;
    bool allocated;
};

struct Process {
    int size;
    bool allocated;
};

void allocateFirstFit(vector<MemoryPartition>& memory, vector<Process>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        for (int j = 0; j < memory.size(); j++) {
            if (!memory[j].allocated && memory[j].size >= processes[i].size) {
                memory[j].allocated = true;
                break;
            }
        }
    }
}

void allocateBestFit(vector<MemoryPartition>& memory, vector<Process>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        int bestFitIdx = -1;
        for (int j = 0; j < memory.size(); j++) {
            if (!memory[j].allocated && memory[j].size >= processes[i].size) {
                if (bestFitIdx == -1 || memory[j].size < memory[bestFitIdx].size) {
                    bestFitIdx = j;
                }
            }
        }
        if (bestFitIdx != -1) {
            memory[bestFitIdx].allocated = true;
        }
    }
}

void allocateWorstFit(vector<MemoryPartition>& memory, vector<Process>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        int worstFitIdx = -1;
        for (int j = 0; j < memory.size(); j++) {
            if (!memory[j].allocated && memory[j].size >= processes[i].size) {
                if (worstFitIdx == -1 || memory[j].size > memory[worstFitIdx].size) {
                    worstFitIdx = j;
                }
            }
        }
        if (worstFitIdx != -1) {
            memory[worstFitIdx].allocated = true;
        }
    }
}

int main() {
    vector<MemoryPartition> memory = {
        {200, false},
        {400, false},
        {600, false},
        {500, false},
        {300, false},
        {250, false}
    };

    vector<Process> processes = {
        {357, false},
        {210, false},
        {468, false},
        {491, false}
    };

    cout << "First Fit Algorithm:" << endl;
    allocateFirstFit(memory, processes);

    int externalFragmentation = 0;
    for (int i = 0; i < memory.size(); i++) {
        if (!memory[i].allocated) {
            externalFragmentation += memory[i].size;
        }
    }

    cout << "External Fragmentation: " << externalFragmentation << " KB" << endl;

    cout << "\nBest Fit Algorithm:" << endl;
    for (auto& mem : memory) {
        mem.allocated = false;
    }
    allocateBestFit(memory, processes);

    externalFragmentation = 0;
    for (int i = 0; i < memory.size(); i++) {
        if (!memory[i].allocated) {
            externalFragmentation += memory[i].size;
        }
    }

    cout << "External Fragmentation: " << externalFragmentation << " KB" << endl;

    cout << "\nWorst Fit Algorithm:" << endl;
    for (auto& mem : memory) {
        mem.allocated = false;
    }
    allocateWorstFit(memory, processes);

    externalFragmentation = 0;
    for (int i = 0; i < memory.size(); i++) {
        if (!memory[i].allocated) {
            externalFragmentation += memory[i].size;
        }
    }

    cout << "External Fragmentation: " << externalFragmentation << " KB" << endl;

    return 0;
}
