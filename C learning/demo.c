#include <stdio.h>

// 定義 Ticket 結構
typedef struct Ticket {
    int dayType;       
    int passengerType; 
    int ticketType;    
    double fare;      

    void (*discounter)(struct Ticket *);
    void (*bonuser)(struct Ticket *);
} Ticket;

// t -> something == *t.something
void discountRule(Ticket *t) {
    if (t->passengerType == 2 || t->passengerType == 3) {
        t->fare *= 0.5;
    }
}

void surchargeRule(Ticket *t) {
    if (t->dayType == 2) {
        t->fare *= 1.2;
    }
}

void calculateFare(Ticket *t) {
    t->fare = (t->ticketType == 2) ? 250.0 : 150.0;
    
    t->discounter(t);
    t->bonuser(t);
}


int main() {
    Ticket myTicket;

    myTicket.discounter = discountRule;
    myTicket.bonuser = surchargeRule;

    scanf("%d %d %d", &myTicket.dayType, &myTicket.passengerType, &myTicket.ticketType);

    calculateFare(&myTicket);
    printf("Final Fare: %d\n", (int)myTicket.fare);

    return 0;
}
