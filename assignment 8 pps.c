#include <stdio.h>
#include <string.h>

struct Sensor {
    int id;
    float dist;
    float thres;
    char status[50];
    char risk[30];
    char type[30];
};

int main() {
    int i;
    int n;
    int hr = 0, mr = 0, lr = 0;

    printf("Enter the number of sensors:\n");
    scanf("%d", &n);

    struct Sensor s[n];

    for (i = 0; i < n; i++) {
        printf("\nSensor %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &s[i].id);

        printf("Type: ");
        scanf("%29s", s[i].type);

        printf("Distance (cm): ");
        scanf("%f", &s[i].dist);

        printf("Threshold (cm): ");
        scanf("%f", &s[i].thres);

        if (s[i].dist <= s[i].thres) {
            strcpy(s[i].status, "Object Detected");
            strcpy(s[i].risk, "High Risk");
            hr++;
        } 
        else if (s[i].thres < s[i].dist && s[i].dist <= 1.5 * s[i].thres) {
            strcpy(s[i].status, "Obstacle near");
            strcpy(s[i].risk, "Medium Risk");
            mr++;
        } 
        else {
            strcpy(s[i].status, "Safe");
            strcpy(s[i].risk, "Low Risk");
            lr++;
        }
    }

    printf("\nID TYPE DISTANCE THRESHOLD STATUS RISK\n");
    printf("--------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d %s %f %f %s %s\n", s[i].id, s[i].type, s[i].dist, s[i].thres, s[i].status, s[i].risk);
    }

    printf("\n--- Summary ---\n");
    printf("High risk sensors: %d\n", hr);
    printf("Medium risk sensors: %d\n", mr);
    printf("Low risk sensors: %d\n", lr);

    printf("\nHigh Risk Sensor Details:\n");
    for (i = 0; i < n; i++) {
        if (strcmp(s[i].risk, "High Risk") == 0) {
            printf("Sensor ID: %d (%.2f cm)\n", s[i].id, s[i].dist);
        }
    }

    return 0;
}
