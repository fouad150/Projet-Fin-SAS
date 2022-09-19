#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Product{
char name[50],code[30];
float price;
int quantity;
  };
struct Product p[10000];

int i,j,products;
int choice,index=0;
int order;

void addproduct(){
    for(i=0;i<products;i++){
                printf("\nproduct(%d) information :\n",index+1);
                printf("enter the name of product: ");
                scanf("%s",&p[index].name);
                printf("enter the price of product: ");
                scanf("%f",&p[index].price);
                printf("enter the quantity of product: ");
                scanf("%d",&p[index].quantity);
                printf("enter the code of product: ");
                scanf("%s",&p[index].code);
                index++;
                }

}

float priceTTC(float price){
return price+price*((float)15/(float)100);}

char productcode[30];
int productquantity;

void buyproduct(){
    for(i=0;i<index;i++){
        int comparecode=strcmp(p[i].code,productcode);
        if(comparecode==0){
            p[i].quantity-=productquantity;
            /*time_t dateV ;
            dateV = time(NULL);
            printf("date : %s\n",ctime(&dateV));*/
        }
    }
}
int codeorquantity;
void searchproduct(){
    printf("1- enter the code of product.\n");
    printf("2- enter the quantity of product.\n ");
    scanf("%d",&codeorquantity);
    if(codeorquantity==1){
        printf("enter the code: ");
        scanf("%s",&productcode);
        for(i=0;i<index;i++){
                int comparecode=strcmp(p[i].code,productcode);
                if(comparecode==0){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",priceTTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);
                }
    }
    }else if(codeorquantity==2){
        printf("enter the quantity: ");
        scanf("%d",&productquantity);
           for(i=0;i<index;i++){
                 if(productquantity==p[i].quantity){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",priceTTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);

                }
    }
    }
}

int exist=0;
void stockstatus(){
         printf("\nthe products their quantity less than 3 are: \n");
         for(i=0;i<index;i++){
                if(p[i].quantity<3){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",priceTTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);
                     exist++;
                }
          if(exist==0){
            printf(" 0. ");
          }else{}
    }
}

void supplystock(){
    printf("enter the code of product: ");
    scanf("%s",productcode);
    printf("enter the quantity:  ");
    scanf("%d",&productquantity);
      for(i=0;i<index;i++){
        int comparecode=strcmp(p[i].code,productcode);
        if(comparecode==0){
            p[i].quantity=p[i].quantity+productquantity;

        }
    }

}
int main()
{

    printf("            |---{PHARMACY MANAGEMENT}---|\n\n");

    do{
        printf("\n                   [--MENU--]\n\n");
        printf("1- add a new product.\n");
        printf("2- add several new products.\n");
        printf("3- sort the products.\n");
        printf("4- buy a product.\n");
        printf("5- search a product.\n");
        printf("6- stock status.\n");
        printf("7- supply the stock.\n");
        printf("8- delete a product.\n");
        printf("9- sales statistics.\n");
        printf("0- exit program.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                products=1;
             addproduct();
                break;
            case 2:
                printf("\nhow many products do you want: ");
                scanf("%d",&products);
                addproduct();

                break;
            case 3:
                printf("\n1-sort the list of products in ascending alphabetical order of name.\n");
                printf("2-sort the list of products in descending order of price.\n");
                scanf("%d",&order);
                if(order==1){
                    for(i=0;i<index;i++){
                        for(j=0;j<index-1;j++){
                            int compare=strcmp(p[j].name,p[j+1].name);
                            if(compare>0){
                                struct Product T=p[j];
                                p[j]=p[j+1];
                                p[j+1]=T;
                            }

                        }
                    }

                }
               else if(order==2){
                    for(i=0;i<index;i++){
                        for(j=0;j<index-1;j++){

                            if(p[j].price<p[j+1].price){
                                struct Product T=p[j];
                                p[j]=p[j+1];
                                p[j+1]=T;
                            }

                        }
                    }
                    }
                for(i=0;i<index;i++){

                        printf("name: %s                 ",p[i].name);
                        printf("price: %.2f                 ",p[i].price);
                        printf("price TTC: %.2f                 \n",priceTTC(p[i].price));
                    }
                break;
            case 4://not complaited

                printf("enter the code of product: ");
                scanf("%s",productcode);
                printf("enter the quantity that you want: ");
                scanf("%d",&productquantity);
                buyproduct();
                break;
            case 5:
                searchproduct();
                break;
            case 6:
                stockstatus();
                break;
            case 7:
                supplystock();
                break;
            case 8:
                break;
            case 9:
                break;
        }


    }while(choice!=0);

    return 0;
}



