#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int pageReference[MAX_PAGES];
int frames[MAX_FRAMES];
int pageFaults_LRU = 0;
int pageFaults_FIFO = 0;
int pageFaults_Optimal = 0;
int pageReferencesCount;
int numFrames;

// Function to initialize frames
void initializeFrames() {
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }
}

// Function to check if a page is present in frames
int isPageInFrames(int page) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

// LRU Page Replacement Algorithm
void* LRUReplacementAlgorithm(void* arg) {
    initializeFrames();

    for (int i = 0; i < pageReferencesCount; i++) {
        int page = pageReference[i];

        if (!isPageInFrames(page)) {
            pageFaults_LRU++;
            int oldestIndex = 0;

            for (int j = 1; j < numFrames; j++) {
                if (frames[j] < frames[oldestIndex]) {
                    oldestIndex = j;
                }
            }

            frames[oldestIndex] = page;
        }
    }
    pthread_exit(NULL);
}

// FIFO Page Replacement Algorithm
void* FIFOReplacementAlgorithm(void* arg) {
    initializeFrames();

    int queue[MAX_FRAMES];
    int front = 0, rear = 0;

    for (int i = 0; i < pageReferencesCount; i++) {
        int page = pageReference[i];

        if (!isPageInFrames(page)) {
            pageFaults_FIFO++;
            frames[rear] = page;
            rear = (rear + 1) % numFrames;
        }
    }
    pthread_exit(NULL);
}

// Optimal Page Replacement Algorithm
void* OptimalReplacementAlgorithm(void* arg) {
    initializeFrames();

    for (int i = 0; i < pageReferencesCount; i++) {
        int page = pageReference[i];

        if (!isPageInFrames(page)) {
            pageFaults_Optimal++;

            int replaceIndex = -1;
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }

                int farthest = i;
                for (int k = i + 1; k < pageReferencesCount; k++) {
                    if (pageReference[k] == frames[j]) {
                        farthest = k;
                        break;
                    }
                }

                if (farthest > i) {
                    replaceIndex = j;
                    i = farthest;
                    break;
                }
            }

            frames[replaceIndex] = page;
        }
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of page references: ");
    scanf("%d", &pageReferencesCount);

    printf("Enter the page reference sequence: ");
    for (int i = 0; i < pageReferencesCount; i++) {
        scanf("%d", &pageReference[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    pthread_t lru_thread, fifo_thread, optimal_thread;

    pthread_create(&lru_thread, NULL, LRUReplacementAlgorithm, NULL);
    pthread_create(&fifo_thread, NULL, FIFOReplacementAlgorithm, NULL);
    pthread_create(&optimal_thread, NULL, OptimalReplacementAlgorithm, NULL);

    pthread_join(lru_thread, NULL);
    pthread_join(fifo_thread, NULL);
    pthread_join(optimal_thread, NULL);

    printf("Page Faults (LRU): %d\n", pageFaults_LRU);
    printf("Page Faults (FIFO): %d\n", pageFaults_FIFO);
    printf("Page Faults (Optimal): %d\n", pageFaults_Optimal);

    return 0;
}
