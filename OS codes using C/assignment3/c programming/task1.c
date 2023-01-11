#include <stdio.h>
#include <stdlib.h>
 
struct order{
    int quantity;
    int price;
};


int main()
{   int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int people;
    int total;
    float res;
    printf("Quantity of Paratha: ");
    scanf("%d",&a);
    printf("\nUnit Price: ");
    scanf("%d",&b);
    printf("\nQuantity of Vegetable: ");
    scanf("%d",&c);
    printf("\nUnit Price: ");
    scanf("%d",&d);
    printf("\nQuantity of Mineral Water: ");
    scanf("%d",&e);
    printf("\nUnit Price: ");
    scanf("%d",&f);
    printf("\nNumber of people: ");
    scanf("%d",&people);


    struct order paratha;
    paratha.quantity=a;
    paratha.price=b;

    struct order vegetable;
    vegetable.quantity=c;
    vegetable.price=d;

    struct order mineral_water;
    mineral_water.quantity=e;
    mineral_water.price=f;

    total=(paratha.quantity*paratha.price) + (vegetable.quantity*vegetable.price) + (mineral_water.quantity*mineral_water.price);
    
    res=total / people;
    printf("Individual people will pay: %f tk \n",res);

    return 0;
}

