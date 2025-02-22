from dataclasses import dataclass
@dataclass
class Account :
    accID : int
    total : int
    cusName : str

accounts = []

def menu() :
    print("-----MENU-----")
    print("1. Make Accout ")
    print("2. Insert money")
    print("3. Withdraw money")
    print("4. Information about account ")
    print('5. Exit')
def make() :
    print("Make the Accout")
    try :
        acc_id = int(input("Accout's ID : "))
        name = input("Name : ")
        total = int(input("Money : "))
    except ValueError :
        print("Try Again!")
        return
    new_account = Account(accID=acc_id, total=total, cusName=name)
    accounts.append(new_account)
    print("Complete")

def deposit() :
    print("Deposit")
    try :
        acc_Id = int(input("Insert ID : "))
        money = int(input("Insert money : "))
    except ValueError :
        print("Try again")
        return
    for i in accounts :
        if accounts[i].accID == acc_Id:
            total += money
            print("Complete")
            return
def withdraw() :
    print("Withdraw")
    try :
        acc_id = input("Enter the id : ")
        money = int(input("Enter the money : "))
    except ValueError :
        print("Try again!")
    
    for i in accounts :
        if accounts[i].accID == acc_id :
            total -= money
            print("Complete")
            return

def inform()  :
    print("Show your account")
    for i in accounts :
        print("Your ID : ", accounts[i].accID)
        print("Your name : ", accounts[i].cusName)
        print("Total : ", accounts[i].total)
    
    print()

def main() :
    while True :
        menu()
        try :
            choice = int(input("Enter Your Choice : "))
        except ValueError :
            print("Try again!")
        
        if choice==1 :
            make()
        elif choice==2 :
            deposit()
        elif choice == 3 :
            withdraw()
        elif choice == 4 :
            inform()
        elif choice == 5 :
            print("End this program")
            break
if __name__ == "__main__":
    main()
