#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

                        printf("%s                 ",p[i].name);
                        printf("%.2f                 ",p[i].price);
                        printf("%.2f                 \n",priceTTC(p[i].price));
                    }
                break;
            case 4:

                printf("enter the code of product: ");
                scanf("%s",productcode);
                printf("enter the quantity that you want: ");
                scanf("%d",&productquantity);
                buyproduct();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
        }


    }while(choice!=0);

    return 0;
}



