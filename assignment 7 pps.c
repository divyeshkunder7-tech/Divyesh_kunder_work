#include <stdio.h>
#include <string.h>

struct Sensor {
    int id;
    char type[15];
    float distance;
    float threshold;
    char status[25]; // Increased from 10 to 25 to fit "Obstacle Detected" safely
    char risk[15];
};

int main() {
    int n, i;
    int highCount = 0, mediumCount = 0, lowCount = 0;
    int minIndex = 0;

    printf("Enter the number of sensors: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of sensors.\n");
        return 1;
    }

    struct Sensor sensors[n];

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Sensor %d ---\n", i + 1);
        printf("Sensor ID: ");
        scanf("%d", &sensors[i].id);

        printf("Sensor Type (Ultrasonic / IR / LiDAR): ");
        scanf("%s", sensors[i].type);

        printf("Measured Distance (in cm): ");
        scanf("%f", &sensors[i].distance);

        printf("Safety Threshold (in cm): ");
        scanf("%f", &sensors[i].threshold);

        if (sensors[i].distance <= sensors[i].threshold) {
            strcpy(sensors[i].status, "Obstacle Detected");
        } else {
            strcpy(sensors[i].status, "Path Clear");
        }

        if (sensors[i].distance <= sensors[i].threshold) {
            strcpy(sensors[i].risk, "High Risk");
            highCount++;
        } else if (sensors[i].distance <= 1.5 * sensors[i].threshold) {
            strcpy(sensors[i].risk, "Medium Risk");
            mediumCount++;
        } else {
            strcpy(sensors[i].risk, "Low Risk");
            lowCount++;
        }

        if (sensors[i].distance < sensors[minIndex].distance) {
            minIndex = i;
        }
    }

    printf("\n=====================================================================================\n");
    printf("%-8s %-14s %-14s %-14s %-20s %-15s\n", 
           "ID", "Type", "Distance(cm)", "Threshold(cm)", "Status", "Risk Level");
    printf("=====================================================================================\n");

    for (i = 0; i < n; i++) {
        printf("%-8d %-14s %-14.2f %-14.2f %-20s %-15s\n",
               sensors[i].id,
               sensors[i].type,
               sensors[i].distance,
               sensors[i].threshold,
               sensors[i].status,
               sensors[i].risk);
    }

    printf("\n--- Risk Level Summary ---\n");
    printf("High Risk Sensors   : %d\n", highCount);
    printf("Medium Risk Sensors : %d\n", mediumCount);
    printf("Low Risk Sensors    : %d\n", lowCount);

    printf("\n--- Nearest Obstacle Detected By ---\n");
    printf("Sensor ID   : %d\n", sensors[minIndex].id);
    printf("Sensor Type : %s\n", sensors[minIndex].type);
    printf("Distance    : %.2f cm (Threshold: %.2f cm)\n", 
           sensors[minIndex].distance, sensors[minIndex].threshold);
    printf("Status      : %s (%s)\n", sensors[minIndex].status, sensors[minIndex].risk);

    return 0;
}
