#include <stdio.h>

#define MAX 3 // MAX FRAMES

// Function to check if a page is present in the current frame
int isPagePresent(int page, int frames[], int frameCount)
{
    for (int i = 0; i < frameCount; i++)
    {
        if (frames[i] == page)
        {
            return 1; // Page is present
        }
    }
    printf("-\n");
    return 0; // Page is not present
}

// Function to implement FIFO page replacement algorithm
void FIFO(int pages[], int page_count)
{
    int frames[MAX];    // Array to store the current pages in memory
    int frameCount = 0; // Number of pages currently in memory
    int pageFaults = 0; // Counter for page faults

    // Initialize frames array with -1 to represent empty frames
    for (int i = 0; i < MAX; i++)
    {
        frames[i] = -1;
    }

    // Iterate through each page
    for (int i = 0; i < page_count; i++)
    {
        // Check if the page is already present in memory
        if (!isPagePresent(pages[i], frames, frameCount))
        {
            // Page is not present, a page fault occurs
            if (frameCount < MAX)
            {
                // There is space in memory, add the page to an empty frame
                frames[frameCount] = pages[i];
                frameCount++;
            }
            else
            {
                // Memory is full, replace the oldest page with the new page
                for (int j = 0; j < MAX - 1; j++)
                {
                    frames[j] = frames[j + 1];
                }
                frames[MAX - 1] = pages[i];
            }
            pageFaults++;
        }

        // Display the current state of memory after each page access
        printf("Pages in memory: ");
        for (int j = 0; j < frameCount; j++)
        {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    // Display total number of page faults
    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int pages[] = {5, 6, 7, 1, 2, 3};
    int page_count = sizeof(pages) / sizeof(pages[0]);
   printf("\nPAGE REPLACEMENT USING FIFO\n");
   FIFO(pages, page_count);

    return 0;
}
