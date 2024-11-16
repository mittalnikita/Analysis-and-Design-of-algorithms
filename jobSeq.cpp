#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job class representing each job with an id, deadline, and profit
class Job {
public:
    int id;       // Job ID
    int deadline; // Job deadline
    int profit;   // Profit if the job is completed before or on the deadline

    // Constructor to initialize job properties
    Job(int i, int d, int p) : id(i), deadline(d), profit(p) {}
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Class to perform job sequencing
class JobSequencing {
public:
    // Function to find the maximum profit by scheduling jobs
    void jobSequencing(vector<Job> &jobs) {
        // Sort the jobs by decreasing order of profit
        sort(jobs.begin(), jobs.end(), compare);

        int maxDeadline = 0;
        for (const auto& job : jobs) {
            if (job.deadline > maxDeadline) {
                maxDeadline = job.deadline;
            }
        }

        // Array to keep track of free time slots
        vector<int> result(maxDeadline + 1, -1);  // Initialize all slots to -1 (empty)
        int maxProfit = 0;  // Variable to store the total profit

        // Loop through each job and place it in the closest available slot
        for (const auto& job : jobs) {
            // Find a free slot for this job before its deadline
            for (int j = min(maxDeadline, job.deadline); j > 0; j--) {
                if (result[j] == -1) {  // If the slot is free
                    result[j] = job.id;  // Assign job id to this slot
                    maxProfit += job.profit;  // Add profit
                    break;
                }
            }
        }

        // Output the job sequence and total profit
        cout << "Jobs scheduled: ";
        for (int i = 1; i <= maxDeadline; i++) {
            if (result[i] != -1) {
                cout << result[i] << " ";  // Print job IDs
            }
        }
        cout << "\nTotal Profit: " << maxProfit << endl;
    }
};

int main() {
    // Create a list of jobs (job id, deadline, profit)
    vector<Job> jobs = {
        Job(1, 2, 100),
        Job(2, 1, 19),
        Job(3, 2, 27),
        Job(4, 1, 25),
        Job(5, 3, 15)
    };

    // Create JobSequencing object and call jobSequencing function
    JobSequencing js;
    js.jobSequencing(jobs);

    return 0;
}
