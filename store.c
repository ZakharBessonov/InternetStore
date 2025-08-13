// Program-simulator of internet-store
#include <stdio.h>
#include <stdbool.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCONT 0.05
#define LIMITPRICE 100

int main(void) {
    bool st = true;
    int choise, cntOfPounds;
    int commonWeight = 0, weightArtichoke = 0, weightBeet = 0, weightCarrot = 0;
    double costOfArtichoke = 0.0, costOfBeet = 0.0, costOfCarrot = 0.0; //products
    double costOfProducts = 0.0, discont = 0.0, costOfDelivery = 0.0;
    
    printf("Welcome to ABC Mail Order Grocery Market!\n");
    printf("Please, select productes:\n");
    printf("1) Artichoke $2.05/lb        2) Beet $1.15/lb\n");
    printf("3) Carrot $1.09/lb           4) Complete purchase\n\n");
    printf("There is a 5%% discount on orders of $100 or more (excluding shipping costs).\n");
    printf("Cost of delivery:\n");
    printf("$6.50 - orders 5 lbs or less\n");
    printf("$14.00 - orders over 5 lbs but under 20 lbs\n");
    printf("$14.00 + $0.50 for every lb - orders over 20 lbs\n\n");
    printf("Your choise: ");
    scanf("%d", &choise);
    
    if (choise != 4) {
        printf("How many pounds You want to take: ");
        scanf("%d", &cntOfPounds);
    }
    
    switch (choise) {
        case 1:
            weightArtichoke += cntOfPounds;
            costOfArtichoke += (double) cntOfPounds * ARTICHOKE;
            break;
        case 2:
            weightBeet += cntOfPounds;
            costOfBeet += (double) cntOfPounds * BEET;
            break;
        case 3:
            weightCarrot += cntOfPounds;
            costOfCarrot += (double) cntOfPounds * CARROT;
            break;
        case 4:
            st = false;
            break;
        default:
            break;
    }
    
    while (st) {
        
        // Count cost of products ans common weight
        costOfProducts = costOfArtichoke + costOfBeet + costOfCarrot;
        commonWeight = weightArtichoke + weightBeet + weightCarrot;
        
        // Count discont
        if ((int) costOfProducts >= LIMITPRICE)
            discont = DISCONT * costOfProducts;
        
        // Count cost of delivery
        if (commonWeight <= 5)
            costOfDelivery = 6.50;
        else if (commonWeight > 5 && commonWeight <= 20)
            costOfDelivery = 14.0;
        else
            costOfDelivery = 14.0 + (double)(commonWeight - 20) * 0.5;
        
        printf("Total cost of products: $%.2lf\n", costOfProducts);
        printf("Discont: $%.2lf\n", discont);
        printf("Cost of delivery: $%.2lf\n", costOfDelivery);
        printf("Total: $%.2lf\n\n", costOfProducts - discont + costOfDelivery);
        
        printf("You have in your cart:\n");
        printf("Artichoke - %d lbs, $%.2lf\n", weightArtichoke, costOfArtichoke);
        printf("Beet - %d lbs, $%.2lf\n", weightBeet, costOfBeet);
        printf("Carrot - %d lbs, $%.2lf\n", weightCarrot, costOfCarrot);
        
        
        printf("Please, select next productes:\n");
        printf("1) Artichoke $2.05/lb        2) Beet $1.15/lb\n");
        printf("3) Carrot $1.09/lb           4) Complete purchase\n");
        printf("Your choise: ");
        scanf("%d", &choise);
        
        if (choise != 4) {
            printf("How many pounds You want to take: ");
            scanf("%d", &cntOfPounds);
        }
        
        switch (choise) {
            case 1:
                weightArtichoke += cntOfPounds;
                costOfArtichoke += (double) cntOfPounds * ARTICHOKE;
                break;
            case 2:
                weightBeet += cntOfPounds;
                costOfBeet += (double) cntOfPounds * BEET;
                break;
            case 3:
                weightCarrot += cntOfPounds;
                costOfCarrot += (double) cntOfPounds * CARROT;
                break;
            case 4:
                st = false;
                break;
            default:
                break;
        }
    }
    
    printf("Thanks for your purchase!\n");
    printf("Total cost of products: $%.2lf\n", costOfProducts);
    printf("Discont: $%.2lf\n", discont);
    printf("Cost of delivery: $%.2lf\n", costOfDelivery);
    printf("Total: $%.2lf\n\n", costOfProducts - discont + costOfDelivery);
    
    
    return 0;
}
