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

struct Statistics{
    char name[50];
    time_t date;
    float priceTTC;
    float total_priceTTC;//user quantity * priceTTC
};
struct Statistics st[10000];
float total_prices=0;
float average_price;
int sold_products=0;//the number of the sold pieces

int i,j,products;
int choice,index=0;
int order;

int exist_code;//check if the code existed

// delete product case 8
char productcode[30];//the code of the user
int productquantity;//user quantity

//buy a product case 4
int sale_index=0;
int oneortwo;//one or two.


float price_TTC(float price){
return price+price*((float)15/(float)100);}

void add_oneproduct(){
                int samecode=0;//check if the code was repeated
                printf("\nproduct(%d) information :\n",index+1);
                printf("enter the name of product: ");
                scanf("%s",&p[index].name);
                printf("enter the price: ");
                scanf("%f",&p[index].price);
                if(p[index].price<=0){//if negative price
                       printf("\nthe price must be positive,try again.\n");
                       add_oneproduct();//there is another solution (goto)
                }else {
                    printf("enter the quantity: ");
                    scanf("%d",&p[index].quantity);
                    if(p[index].quantity<=0){//if negative quantity
                         printf("\nthe quantity must be positive,try again.\n");
                         add_oneproduct();

                    }else {

                        printf("enter the code: ");
                        scanf("%s",&p[index].code);
                        for(j=0;j<index;j++){
                            if(strcmp(p[index].code,p[j].code)==0){
                                  samecode++;
                            }

                        }
                       if(samecode==0){
                          index++;
                       }else{
                           printf("this code is already existed,try another code.\n");
                           add_oneproduct();
                       }
                    }
                }
}

void add_severalproducts(){
    for(i=0;i<products;i++){
        add_oneproduct();
    }
}

void sortproducts(){
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

    }else if(order==2){
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
                printf("name: %s           ",p[i].name);
                printf("price: %.2f           ",p[i].price);
                printf("price TTC: %.2f           \n",price_TTC(p[i].price));
            }
    }



void buyproduct(){
     exist_code=0;
     printf("\nenter the code of product: ");
     scanf("%s",productcode);
     printf("enter the quantity that you want: ");
     scanf("%d",&productquantity);
    for(i=0;i<index;i++){
        int comparecode=strcmp(p[i].code,productcode);
        if(comparecode==0){
                exist_code++;
                if(productquantity<=p[i].quantity&&productquantity>=0){
                        p[i].quantity-=productquantity;
                        strcpy(st[sale_index].name,p[i].name);//strcpy replace string with another string
                        time_t saledate ;
                        saledate=time(NULL);
                        st[sale_index].date=saledate;
                        //printf("date : %s\n",ctime(&st[sale_index].date));
                        st[sale_index].priceTTC=price_TTC(p[i].price);
                        st[sale_index].total_priceTTC=productquantity*price_TTC(p[i].price);
                        total_prices+=st[sale_index].total_priceTTC;
                        sold_products+=productquantity;
                        average_price=total_prices/sold_products;
                        sale_index++;
                        printf("the operation was successful.");
                    }else{
                        printf("this quantity doesn't exist,return to the MENU and choose a quantity between 1 and %d.",p[i].quantity);
                    }

         }

    }
    if(exist_code==0){
        printf("this code doesn't exist choose one choice:\n");
        printf("  1- try another code.\n");
        printf("  2- back to the MENU.\n");
        scanf("%d",&oneortwo);
        if(oneortwo==1){
            buyproduct();
        }

    }

}

int codeorquantity;//code or quantity

void searchproduct(){
    printf("\n 1- enter the code.\n");
    printf(" 2- enter the quantity.\n ");
    scanf("%d",&codeorquantity);
    if(codeorquantity==1){
         int code_exist=0;
        printf("enter the code: ");
        scanf("%s",&productcode);
        for(i=0;i<index;i++){
                int comparecode=strcmp(p[i].code,productcode);
                if(comparecode==0){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",price_TTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);
                     code_exist++;
                }
    }
    if(code_exist==0){
        printf("there is no product has this code.");
    }
    }else if(codeorquantity==2){
        int quantity_exist=0;
        printf("enter the quantity: ");
        scanf("%d",&productquantity);
           for(i=0;i<index;i++){
                 if(productquantity==p[i].quantity){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",price_TTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);
                     quantity_exist++;
                }
        }
        if(quantity_exist==0){
            printf("there is no product has this quantity");
        }

    }
}


void stockstatus(){
         int exist=0;
         printf("\nthe products their quantity less than 3 are: \n");
         for(i=0;i<index;i++){
                if(p[i].quantity<3){
                     printf("name: %s                 ",p[i].name);
                     printf("price: %.2f                 ",p[i].price);
                     printf("price TTC: %.2f                 ",price_TTC(p[i].price));
                     printf("quantity: %d                 ",p[i].quantity);
                     printf("code: %s                 \n\n",p[i].code);
                     exist++;
                }
          }
        if(exist==0){
            printf("0");
          }
}

void supplystock(){
    printf("\nenter the code of product: ");
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

void deleteproduct(){
    exist_code=0;
    printf("\nenter the code of product: ");
    scanf("%s",productcode);
      for(i=0;i<index-1;i++){
        int comparecode=strcmp(p[i].code,productcode);
        if(comparecode==0){
            for(j=i;j<index-1;j++){
                    strcpy(p[j].name,p[j+1].name);
                    strcpy(p[j].code,p[j+1].code);
                    p[j].price=p[j+1].price;
                    p[j].quantity=p[j+1].quantity;

                    }
            index--;
            exist_code++;
            printf("the operation was successful.");
            }
        }
    int comparecode=strcmp(p[index-1].code,productcode);
    if(comparecode==0){
            index--;
            exist_code++;
            printf("the operation was successful.");

    }
    else if(exist_code==0){
            printf("there is no product has this code.");
    }
}



void sales_statistics(){
    float max=0;
    for(i=0;i<sale_index;i++){
        printf("\nname= %s       ",st[i].name);
        printf("total price TTC= %.2f        ",st[i].total_priceTTC);
        printf("date : %s",ctime(&st[i].date));
    }
    printf("\n\n");
    printf("\nthe total prices of the sold products today: %.2f\n",total_prices);
    printf("the average price of the sold products: %.2f\n",average_price);
    printf("the max price of the sold products: ");
    for(i=0;i<sale_index;i++){
        if(st[i].priceTTC>max){
            max=st[i].priceTTC;
        }
    }
    printf("%.2f\n",max);
    float min=max;
    printf("the min price of the sold products: ");
      for(i=0;i<sale_index;i++){
        if(st[i].priceTTC<min){
            min=st[i].priceTTC;
        }
    }
    printf("%.2f",min);
}




int main()
{

    printf("\n\n            |---PHARMACY MANAGEMENT---|\n");

    do{
        printf("\n\n                   [--MENU--]\n\n");
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
                add_oneproduct();
                break;
            case 2:
                printf("\nhow many products do you want: ");
                scanf("%d",&products);
                add_severalproducts();
                break;
            case 3:
                sortproducts();
                break;
            case 4:
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
                deleteproduct();
                break;
            case 9:
                sales_statistics();
                break;
        }


    }while(choice!=0);

   return 0;
}

