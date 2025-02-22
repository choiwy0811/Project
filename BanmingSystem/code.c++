# include <iostream>
# include <cstring>

using namespace std;

void menu(void);
void make(void);
void input(void);
void output(void);
void inform(void);

typedef struct{

    int acc_total;
    int acc_id;
    char acc_name[20]; 
} Account;

Account accArr[200];
int num=0;

enum {Make = 1, INPUT, OUTPUT, INFORM, EXIT};

int main(void){

    int choice;

    while(1) {

        menu();
        cout<<"선택 : ";
        cin>>choice;

        switch(choice) {

            case Make :
                 make();
                 break;
            case INPUT :
                 input();
                 break;
            case OUTPUT :
                 output();
                 break;
            case INFORM :
                 inform();
                 break;
            case EXIT :
                 return 0;
            
                 }
    }
}

void menu(void){

    cout<<"-----MENU-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입    금"<<endl;
    cout<<"3. 출    금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void make(void){
    
    int id;
    int money;
    char name[20];
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID : ";
    cin>>id;
    cout<<"이 름 : ";
    cin>>name;
    cout<<"입금액 : ";
    cin>>money;

    accArr[num].acc_id = id;
    accArr[num].acc_total = money;
    strcpy(accArr[num].acc_name, name);

    num++;
}

void input(void){
    int id;
    int money;
    cout<<"[입 금]"<<endl;
    cout<<"계좌 ID : ";
    cin>>id;
    cout<<"입금액 : ";
    cin>>money;

    for(int i=0; i<num;i++){

        if(accArr[i].acc_id == id){

            accArr[i].acc_total += money;
            cout<<"입금완료"<<endl;
            return;
        }


    }
}

void output(void){
    int id;
    int money;
    cout<<"[출 금]"<<endl;
    cout<<"계좌 ID : ";
    cin>>id;
    cout<<"출금액 : ";
    cin>>money;

    for(int i=0; i<num;i++){

        if(accArr[i].acc_id == id){
            if(accArr[i].acc_total-money<0){

                cout<<"잔액이 부족합니다"<<endl;;
            }

            accArr[i].acc_total -= money;
            cout<<"출금완료"<<endl;
            return;
        }


    }
}

void inform(void){

    for(int i=0; i<num; i++){

        cout<<"계좌ID : "<<accArr[i].acc_id<<endl;
        cout<<"이  름 : "<<accArr[i].acc_name<<endl;
        cout<<"잔  액 : "<<accArr[i].acc_total<<"원"<<endl;
        

    }
}
