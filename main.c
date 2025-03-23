/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

// Function prototypes
void initializeSystem(int rooms, int lights[], int temps[], int motions[], int locks[]);
void displayMenu();
void controlLights(int rooms, int lights[]);
void readTemperature(int rooms, int temps[]);
void detectMotion(int rooms, int motions[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], int temps[], int motions[], int locks[]);

int main() {
    int rooms;
    printf("Enter number of rooms: ");
    scanf("%d", &rooms);
    
    int lights[rooms], temps[rooms], motions[rooms], locks[rooms];
    initializeSystem(rooms, lights, temps, motions, locks);
    
    int choice;
    do {
        printf("\n===== Smart Home Menu =====\n");
        printf("1. Toggle Light\n");
        printf("2. Read Temperature\n");
        printf("3. Check Motion Sensor\n");
        printf("4. Lock/Unlock Security System\n");
        printf("5. House Status Summary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: toggleLight(rooms, lights); break;
            case 2: readTemperature(rooms, temps); break;
            case 3: checkMotion(rooms, motions); break;
            case 4: lockUnlockSecurity(rooms, locks); break;
            case 5: houseStatus(rooms, lights, temps, motions, locks); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
    


    return 0;
}

 
void initializeSystem(int rooms, int lights[], int temps[], int motions[], int locks[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;  // Lights OFF
        temps[i] = 22;  // Default temperature
        motions[i] = 0; // No motion detected
        locks[i] = 1;   // Doors locked
    }
    printf("System Initialized.\n");
}

//void displayMenu() {
   
//}
void controlLights(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }

}
void readTemperature() {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d is %d°C.\n", room, temps[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }

}
void detectMotion(int rooms, int motions[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d is %s.\n", room, motions[room - 1] ? "Detected" : "Not Detected");
    } else {
        printf("Invalid room number!\n");
    }
    
}
void securitySystem(int rooms, int locks[]) {int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);
    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number!\n");
    }

}
void analyzeHouseStatus(int rooms, int lights[], int temps[], int motions[], int locks[]) {
    printf("House Status:\n");
    for (int i = 0; i < rooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
               i + 1, 
               lights[i] ? "ON" : "OFF", 
               temps[i], 
               motions[i] ? "Motion Detected" : "No Motion", 
               locks[i] ? "Locked" : "Unlocked");
    }
}
