#include <stdio.h>

struct BankAccount {
    int accountNumber;
    float balance;
};

void createAccount(struct BankAccount *account) {
    printf("Enter account number: ");
    scanf("%d", &(account->accountNumber));
    printf("Enter initial balance: ");
    scanf("%f", &(account->balance));
    printf("Account created successfully!\n");
}

void deposit(struct BankAccount *account) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposit successful!\n");
}

void withdraw(struct BankAccount *account) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawal successful!\n");
    } else {
        printf("Insufficient balance!\n");
    }
}

void displayBalance(struct BankAccount account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Balance: %.2f\n", account.balance);
}

int main() {
    struct BankAccount account;
    int choice;

    printf("Bank Management System\n");
    printf("======================\n");

    while (1) {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                withdraw(&account);
                break;
            case 4:
                displayBalance(account);
                break;
            case 5:
                printf("Thank you for using the Bank Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}