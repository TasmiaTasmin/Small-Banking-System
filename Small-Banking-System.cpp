/// Project Name- "Banking System"

#include<iostream>
#include<istream>
#include<cstdio>
#include<string>

#define AccountNumber 10
#define Branch 3
#define NameLength 50

using namespace std;

class AC_Holder_Info
{
private:
    int accountNumber;
    char Name[NameLength];
    float Balance;
    float Withdraw, Deposit;
public:
    AC_Holder_Info()						/// Constructor of AC_Bank_Info Class
    {

    }
    void accountNumberCounter()			    /// Counting Account Number
    {
        static int temp1 = 1;
        static int temp2 = 100;
        accountNumber = 110000 + temp2 + temp1;
        temp1++;
        if (temp1 > 10)
        {
            temp1 = 1;
            temp2 += 100;
        }
    }
    int getAccountNumberCounter()const
    {
        return accountNumber;
    }
    void inputAccountHolderBalanceInformation(int i, int j)
    {
        accountNumberCounter();
        cout << "Branch- " << i + 1 << ", Account Number: " << getAccountNumberCounter() << ", Name- ";
        cin.get(Name, NameLength);
        fflush(stdin);
        cout << "Your Balance of amount is: ";
        cin >> Balance;
        fflush(stdin);
    }
    void showAccountHolderBalanceInformation(int i, int j)
    {
        accountNumberCounter();
        cout << "Branch- " << i + 1 << ", Account Number: " << getAccountNumberCounter() << ", Name- " << Name << endl;
        cout << "Your current Balance is: " << Balance << endl;
        fflush(stdin);
    }
    AC_Holder_Info(float balance)
    {
        Balance = balance;
    }
    float getAccountHolderBalanceInformation()const
    {
        return Balance;
    }
    void inputAccountHolderWithdrawAmount(int i, int j)
    {
        accountNumberCounter();
        cout << "Branch- " << i + 1 << ", Account Number: " << getAccountNumberCounter() << ", Name- " << Name << endl;
        cout << "How much amount you want to Withdraw ?" << endl;
        cout << "Your Withdrawing amount is: ";
        cin >> Withdraw;
        fflush(stdin);
        if (Balance >= Withdraw)
        {
            cout << "You can Withdraw your money " << endl;
            Balance = Balance - Withdraw;
        }
        else
        {
            cout << "You can not Withdraw your money " << endl;
        }
        cout << "\n";
        fflush(stdin);
    }
    void inputAccountHolderDepositAmount(int i, int j)
    {
        accountNumberCounter();
        cout << "Branch- " << i + 1 << ", Account Number: " << getAccountNumberCounter() << ", Name- " << Name << endl;
        cout << "How much amount you want to Deposit ?" << endl;
        cout << "Your Depositing amount is: ";
        cin >> Deposit;
        fflush(stdin);
        Balance = Deposit + Balance;
    }
    void showAccountHolderInterestAmount(int i, int j)
    {
        accountNumberCounter();
        Balance = Balance + Balance * (2 / 100);
        cout << "Branch- " << i + 1 << ", Account Number: " << getAccountNumberCounter() << ", Name- " << Name << endl;
        cout << "After getting interest your current Balance is: " << Balance << endl;
        fflush(stdin);
    }
    ~AC_Holder_Info()						/// Distructor of AC_Bank_Info Class
    {
        cout << "AC_Holder_Info Constructor Has Distructred" << endl;
    }
};


class Branch_Info
{
private:
    float branchTotal;
public:
    Branch_Info()						/// Constructor of Branch_Info Class
    {

    }
    void showBranchTotalTransaction(int i, AC_Holder_Info ACH[][10])
    {
        int j;
        float Sum = 0;
        for (j = 0; j < AccountNumber; j++)
        {
            Sum = Sum + ACH[i][j].getAccountHolderBalanceInformation();
        }
        branchTotal = Sum;
        fflush(stdin);
    }
    Branch_Info(float branchtotal)
    {
        branchTotal = branchtotal;
    }
    float getBranchTotalTransaction()const
    {
        return branchTotal;
    }
    ~Branch_Info()						/// Distructor of Branch_Info Class
    {
        cout << "Branch_Info Constructor Has Distructred" << endl;
    }
};

class Employee_Info
{
private:
    float    employeeBonusAmount;
public:
    Employee_Info()						/// Constructor of Employee_Info Class
    {

    }
    void showEmployeeBonusAmount(int i, int Employee, float Percentage, int Start, int End, AC_Holder_Info ACH[][10])
    {
        int j;
        float Sum = 0;
        for (j = Start - 1; j < End; j++)
        {
            Sum = Sum + (ACH[i][j].getAccountHolderBalanceInformation() * (Percentage / 100));
        }
        employeeBonusAmount = Sum;
        fflush(stdin);
    }
    Employee_Info(float employeebonusamount)
    {
        employeeBonusAmount = employeebonusamount;
    }
    float getEmployeeBonusAmount()const
    {
        return employeeBonusAmount;
    }
    ~Employee_Info()						/// DIstructor of Employee_Info Class
    {
        cout << "Enployee_Info Constructor Has Distructred" << endl;
    }
};

int main()
{
    Employee_Info      EM_Info[3];
    Branch_Info        BR_Info[3];
    AC_Holder_Info     ACh_Info[3][10];

    for (int i = 0; i < Branch; i++)
    {
        for (int j = 0; j < AccountNumber; j++)
        {
            ACh_Info[i][j].inputAccountHolderBalanceInformation(i, j);
        }
        cout << "\n";
        fflush(stdin);
    }
    cout << "\n\n";
    for (int i = 0; i < Branch; i++)
    {
        for (int j = 0; j < AccountNumber; j++)
        {
            ACh_Info[i][j].inputAccountHolderWithdrawAmount(i, j);
        }
        cout << "\n";
        fflush(stdin);
    }
    cout << "\n\n";
    for (int i = 0; i < Branch; i++)
    {
        for (int j = 0; j < AccountNumber; j++)
        {
            ACh_Info[i][j].inputAccountHolderDepositAmount(i, j);
            ACh_Info[i][j].showAccountHolderBalanceInformation(i, j);
            cout << "\n";
        }
        cout << "\n";
        fflush(stdin);
    }
    cout << "\n\n";
    for (int i = 0; i < Branch; i++)
    {
        BR_Info[i].showBranchTotalTransaction(i, ACh_Info);
        cout << "Branch- " << i + 1 << " total Transaction is: " << BR_Info[i].getBranchTotalTransaction() << endl;
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 0; i < Branch; i++)
    {
        for (int j = 0; j < AccountNumber; j++)
        {
            ACh_Info[i][j].showAccountHolderInterestAmount(i, j);
        }
        cout << "\n";
    }
    cout << "\n\n";
    for (int i = 0; i < Branch; i++)
    {
        EM_Info[i].showEmployeeBonusAmount(i, 0, 3, 1, 5, ACh_Info);
        cout << "Branch- " << i + 1 << " Accounatant- 1 You have got bonus Amount is: " << EM_Info[i].getEmployeeBonusAmount() << endl;
        cout << "\n";
        EM_Info[i].showEmployeeBonusAmount(i, 1, 3, 6, 10, ACh_Info);
        cout << "Branch- " << i + 1 << " Accounatant- 2 You have got bonus Amount is: " << EM_Info[i].getEmployeeBonusAmount() << endl;
        cout << "\n";
        EM_Info[i].showEmployeeBonusAmount(i, 2, 5, 1, 10, ACh_Info);
        cout << "Branch- " << i + 1 << " Manager You have got bonus Amount is: " << EM_Info[i].getEmployeeBonusAmount() << endl;
        cout << "\n";
    }

    fflush(stdin);
    getchar();
    return 0;
}



