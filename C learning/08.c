#include <stdio.h>
typedef struct Ticketinfo{
  int when;
  int who;
  int whattype;
  double fare; //discount

  void(*diser)(struct Ticketinfo *);
  void(*boser)(struct Ticketinfo *);
}Ticket;


void How2discount(Ticket *t){
  if (t->who == 2 || t->who == 3) t->fare *= 0.5;
}
void How2bonus(Ticket *t){
  if (t->when == 2) t->fare *= 1.2;
}
void How2Calculate(Ticket *t){
  t->fare = (t->whattype == 2)? 250.0 : 150.0;
  t->diser(t);
  t->boser(t);
}

int main(){
  Ticket theTic;
  theTic.diser = How2discount;
  theTic.boser = How2bonus;
  scanf("%d %d %d" , &theTic.when, &theTic.who, &theTic.whattype);

  How2Calculate(&theTic);
  printf("Final fare:%d\n" , (int)theTic.fare);
  return 0;
}