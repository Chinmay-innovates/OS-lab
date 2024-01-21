#include <stdio.h>

#define MAX 3

// Function to check if a page is present in the current frame
int isPagePresent(int page, int frames[], int frameCount)
{
    for (int i = 0; i < frameCount; i++)
    {
        if (frames[i] == page)
        {
            return 1; // Page is present in memory
        }
    }
    printf("-\n");
    return 0; // Page is not present in memory
}

// Function to find the index of the least recently used page in memory
int findLRUIndex(int counter[], int frameCount)
{
    int min = counter[0];
    int index = 0;

    for (int i = 1; i < frameCount; i++)
    {
        if (counter[i] < min)
        {
            min = counter[i];
            index = i;
        }
    }

    return index;
}

// Function to implement LRU page replacement algorithm
void LRU(int pages[], int page_count)
{
    int frames[MAX];  // Array to store current pages in memory
    int counter[MAX]; // Counter for each frame to track usage
    int frameCount = 0;
    int pageFaults = 0;

    // Initialize frames array with -1 to represent empty frames
    for (int i = 0; i < MAX; i++)
    {
        frames[i] = -1;
        counter[i] = 0;
    }

    for (int i = 0; i < page_count; i++)
    {
        if (!isPagePresent(pages[i], frames, frameCount))
        {
            // Page is not present, a page fault occurs
            if (frameCount < MAX)
            {
                // There is space in memory, add the page to an empty frame
                frames[frameCount] = pages[i];
                counter[frameCount] = i; // Set counter to the page access index
                frameCount++;
            }
            else
            {
                // Memory is full, replace the least recently used page with the new page
                int lruIndex = findLRUIndex(counter, frameCount);
                frames[lruIndex] = pages[i];
                counter[lruIndex] = i;
            }
            pageFaults++;
        }

        // Update counter for each page in memory
        for (int j = 0; j < frameCount; j++)
        {
            counter[j]++;
        }

        // Display the current state of memory after each page access
        printf("Pages in memory: ");
        for (int j = 0; j < frameCount; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    // Display the total number of page faults
    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int pages[] = {1, 3, 2, 4, 5, 5, 6, 3, 4, 3, 5, 2, 5, 3, 4, 6, 3, 7, 8, 9, 5, 4, 6, 5, 4, 6, 1, 3};
    int page_count = sizeof(pages) / sizeof(pages[0]);
    printf("\nPAGE REPLACEMENT USING LRU\n");
    LRU(pages, page_count);
    return 0;
}
