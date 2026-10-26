
#include <stdio.h>

int main() {
    int choice;
    float income = 0, expenses = 0, amount;

    do {
        printf("\n=== EXPENSE TRACKER ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income amount: ");
                scanf("%f", &amount);

                if (amount > 0) {
                    income += amount;
                    printf("Income added!\n");
                } else {
                    printf("Enter a positive amount.\n");
                }
                break;

            case 2:
                printf("Enter expense amount: ");
                scanf("%f", &amount);

                if (amount > 0 && amount <= income - expenses) {
                    expenses += amount;
                    printf("Expense recorded!\n");
                } else {
                    printf("Invalid amount or insufficient balance.\n");
                }
                break;

            case 3:
                printf("\nTotal Income: Rs. %.2f\n", income);
                printf("Total Expenses: Rs. %.2f\n", expenses);
                printf("Balance: Rs. %.2f\n",
                       income - expenses);
                break;

            case 4:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
