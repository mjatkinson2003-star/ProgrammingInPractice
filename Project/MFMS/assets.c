#include <stdio.h>
#include <string.h>
 
#define MAX_ASSETS 999
 
typedef struct{
    int   assetID;
    char  assetName[100];
    char  assetType[256];
    float purchaseValue;
    char  department[100];
    char  condition[50];
}Asset;
 
Asset assetsTable[MAX_ASSETS];
int assetCount = 0;
 
void searchAsset(void);
void displayAssets(void);
 
void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset table is full.\n");
        return;
    }
    Asset *a = &assetsTable[assetCount];
 
    printf("Asset ID: ");
    scanf("%d", &a->assetID);
    getchar();
 
    printf("Asset Name: ");
    fgets(a->assetName, sizeof a->assetName, stdin);
    a->assetName[strcspn(a->assetName, "\n")] = '\0';
 
    printf("Asset Type: ");
    fgets(a->assetType, sizeof a->assetType, stdin);
    a->assetType[strcspn(a->assetType, "\n")] = '\0';
 
    printf("Purchase value of Asset: ");
    scanf("%f", &a->purchaseValue);
    getchar();
 
    printf("Department allocation: ");
    fgets(a->department, sizeof a->department, stdin);
    a->department[strcspn(a->department, "\n")] = '\0';
 
    printf("Condition of asset: ");
    fgets(a->condition, sizeof a->condition, stdin);
    a->condition[strcspn(a->condition, "\n")] = '\0';
 
    assetCount++;
    printf("Asset added.\n");
}
 
void searchAsset(void) { //only search single asset using ID
    int searchID;
    printf("Enter Asset ID to view: ");
    scanf("%d", &searchID);
    getchar();
 
    for (int i = 0; i < assetCount; i++) {
        if (assetsTable[i].assetID == searchID) {
            Asset *a = &assetsTable[i];
            printf("Asset ID: %d\n", a->assetID);
            printf("Asset Name: %s\n", a->assetName);
            printf("Asset Type: %s\n", a->assetType);
            printf("Purchase value of asset: %.2f\n", a->purchaseValue);
            printf("Department allocation: %s\n", a->department);
            printf("Condition of asset: %s\n", a->condition);
            return;
        }
    }
    printf("Asset with ID %d not found.\n", searchID);
}
 
void displayAssets(void) { //display all assets in the table
    if (assetCount == 0) {
        printf("No assets yet.\n");
        return;
    }
    for (int i = 0; i < assetCount; i++) {
        Asset *a = &assetsTable[i];
        printf("%d | %s | %s | %.2f | %s | %s\n",
               a->assetID, a->assetName, a->assetType,
               a->purchaseValue, a->department, a->condition);
    }
}
 
int assets(void) {
    int choice;
 
    do {
        printf("\nChoose what to do from the list below:\n");
        printf("1. Add Asset\n");
        printf("2. View Asset\n");
        printf("3. Display Assets\n");
        printf("4. Back to main menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) return 1;
 
        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2: // search by assetID
                searchAsset();
                break;
            case 3:
                displayAssets();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
 
    return 0;
}
 
int main(void) {
    return assets();
}
 
