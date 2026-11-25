#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RobotRecord {
    int robot_id;
    float depth;
    float pressure;
    float temperature;
    float battery;
    char defect[50];
};

void addRecord(const char *filename) {
    FILE *fp = fopen(filename, "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct RobotRecord rec;
    printf("\n--- Enter New Robot Telemetry Data ---\n");
    printf("Robot ID: ");
    scanf("%d", &rec.robot_id);
    printf("Depth (m): ");
    scanf("%f", &rec.depth);
    printf("Pressure (MPa): ");
    scanf("%f", &rec.pressure);
    printf("Temperature (C): ");
    scanf("%f", &rec.temperature);
    printf("Battery (%%): ");
    scanf("%f", &rec.battery);

    getchar();
    printf("Structural Defect (enter 'None' if no defects): ");
    fgets(rec.defect, sizeof(rec.defect), stdin);
    rec.defect[strcspn(rec.defect, "\n")] = 0;

    fwrite(&rec, sizeof(struct RobotRecord), 1, fp);
    fclose(fp);
    printf("Record saved successfully!\n");
}

void generateReport(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    struct RobotRecord rec;
    printf("\n--- Inspection Report ---\n");
    while (fread(&rec, sizeof(struct RobotRecord), 1, fp)) {
        printf("Robot ID: %d | Depth: %.2fm | Pressure: %.2fMPa | Temp: %.2fC | Battery: %.2f%% | Defect: %s\n",
               rec.robot_id, rec.depth, rec.pressure, rec.temperature, rec.battery, rec.defect);
    }
    fclose(fp);
}

int main() {
    int choice;
    const char *filename = "robot_records.dat";

    while (1) {
        printf("\n1. Add New Robot Record\n");
        printf("2. Generate Inspection Report\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(filename);
                break;
            case 2:
                generateReport(filename);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

