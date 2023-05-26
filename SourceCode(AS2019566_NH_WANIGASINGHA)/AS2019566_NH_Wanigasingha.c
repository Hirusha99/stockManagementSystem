#include <stdio.h>
#include <stdlib.h>
const int MAN=3;// no of vehicles or salesman in xyz, i assume that #vehicles=#salesmen
const int ITEM=2;// no of items in the xyz
const int SIZE=100;
void display_name();//declare function
void stock_details();//declare function
void displaystock();//declare function
void loading();//declare function
void display_loading();//declare function
void unloading();//declare function
void display_unloading();//declare function
void choices();//declare function
void main_menu();//declare function
void sales();
void salesman();
void main_page();
void report();
int i1;//availability of item 1
int i2;//availability of item 2
int in1,in2;//in1=item number of item 1, in2=item number of item 2
int si1,si2,si3,v1,v2,v3;//global variables salesmen's id nuber & vehicle numbers
int s1i1,s1i2,s2i1,s2i2,s3i1,s3i2;//global variables loading
int date;//loading date
int sales1i1,sales1i2,sales2i1,sales2i2,sales3i1,sales3i2;


int main()
{
   main_page();
    main_menu();
    return 0;
}
void choices ()//define function
{
    //choices
    printf("VEHICLES AND SALESMEN DETAILS - ENTER 1\n");
    printf("STOCK DETAILS                 - ENTER 2\n");
    printf("LOADIG DETAILS                - ENTER 3\n");
    printf("UNLOADIG DETAILS              - ENTER 4\n");
    printf("SALES                         - ENTER 5\n");

}
void main_menu()//define function
{ int choice;
  int choice1;
  int choice2;
  int choice3;
  int choice4;
  int choice5;
  choices();
  printf("ENTER YOUR CHOICE :");
  scanf("%d",&choice);

   switch(choice)//define function
   {
       case 01: system("cls");

                printf("\n");

                salesman();
                break;

       case 02: system("cls");
                display_name();
                printf("\n");
                printf("INPUT STOCK DETAILS   - ENTER [1]\n");
                printf("DISPLAY STOCK DETAILS - ENTER [2]\n");

                printf("ENTER :");
                scanf("%d",&choice2);
                   switch(choice2)
                   {
                       case 1: system("cls");
                               stock_details();
                                break;

                        case 2 :system("cls");
                                displaystock();
                                 break;

                       default: main_menu();

                   }
        break;

        case 3:
                printf("INPUT LOADING DETAILS - ENTER [1]\n");
                printf("PRINT LOADING DETAILS - ENTER [2]\n");
                scanf("%d",&choice3);
                switch(choice3)
                {
                    case 1 : system("cls");
                            loading();
                            break;
                    case 2 : system("cls");
                            display_loading();
                            break;

                }
                break;
        case 4: printf("INPUT UNLOADING DETAILS - ENTER [1]\n");
                printf("PRINT LOADING DETAILS   - ENTER [2]\n");
                printf("ENTER:");
                scanf("%d",&choice4);
                switch(choice4)
                {
                    case 1: system("cls");
                            unloading();
                            break;
                    case 2: system("cls");
                            display_unloading();
                            break;
                }
                break;
       case 5:

                printf("SALESMEN PROGRES                  - ENTER[1]\n");
                printf("MONTHLY SALES & STOCK AVILABILITY - ENTER[2]\n");
                printf("ENTER :");
                scanf("%d",&choice5);
                switch(choice5)
                {
                   case 1: system("cls");
                           sales();
                           break;
                    case 2:system("cls");
                          report();
                           break;
                }
            break;
         default: printf("NOT MATCHING!...");


   }
}
void display_name()//define function
{
    printf("*************************************************************************\n");
    printf("                                  XYZ \n");
    printf("*************************************************************************\n");
}
void salesman()//salesman and vehicle details
{
    display_name();
   int id[10];
   int vehicle_no[10];
   int enter;

   FILE* saleman;//make file to add details of salesmen and vehicle
   saleman=fopen("salesman_details.txt","a");
     FILE* global_variable;
   global_variable=fopen("global2.txt","w");
   //input details process
   for(int i=0;i<MAN;i++)
   {
       printf("ENTER SALESMAN ID NUMBER :");
       scanf("%d",&id[i]);
       printf("ENTER VEHICLE NUMBER :");
       scanf("%d",&vehicle_no[i]);
       fprintf(saleman,"%d \t %d\n\n",id[i],vehicle_no[i]);
       printf("\n");

   }
   si1=id[0];//salesman 01 ID number
   si2=id[1];//salesman 02 ID number
   si3=id[2];//salesman 03 ID number
   v1=vehicle_no[0];//vehicle 01 number
   v2=vehicle_no[1];//vehicle 02 number
   v3=vehicle_no[2];// vehicle 03 number

  // store above global variable in to file
   fprintf(global_variable,"%d\t%d\n%d\t%d\n%d\t%d\n",si1,v1,si2,v2,si3,v3);
   //file close
    fclose(global_variable);
    fclose(saleman);

    //back to main menu
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter);
    switch(enter)
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;

         default: printf("INVALD VALUE!..");
    }


}

void stock_details()//define function
{

    display_name();//Print name in head
    int enter;
    FILE* stockdetails;
    stockdetails= fopen("stockdetail.txt","a");//open stockdetail file on append mode

    if(stockdetails==NULL)
    {
        printf("FILE NOT FOUND!..");//if file haven't ,print message
    }
    //input stock details
    FILE* sales_items;
    sales_items=fopen("item.txt","a");
    int item_no[10];
    float item_price[10];
    int availability[10];
    // details input process
    for(int i=0;i<ITEM;i++)
    {
        printf("ITEM NO  :");
        scanf("%d",&item_no[i]);
        printf("ITEM PRICE :");
        scanf("%f",&item_price[i]);
        printf("ITEM QUANTITY :");
        scanf("%d",&availability[i]);

        fprintf(stockdetails,"%d\t %f\t %d\n",item_no[i],item_price[i],availability[i]);//details add to the stockdetails file
        fprintf(sales_items,"%d \t %d \n",item_no[i],availability[i]);

    }
    i1=availability[0];//quantity of item 1
    i2=availability[1];//quantity of item 2
    in1=item_no[0];//item 1 serial number
    in2=item_no[1];//item 2 serial number

    //above details add to file
    FILE* global_variable;
    global_variable=fopen("global.txt","w");
    fprintf(global_variable,"%d\t%d\t %d\t %d\n",i1,i2,in1,in2);
    fclose(global_variable);
    fclose(stockdetails);//close file
    fclose(sales_items);

    //back to main menu
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter);
    switch(enter)
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
        default: printf("INVALD VALUE!..");
    }

}

void displaystock()//define function
{
    display_name(); // display name
    float arr1[50][1];
    int arr2[50][2];
    int i=0;
    int enter1;

    //display process name
    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3 STOCK DETAILS \xB3 ");
    printf("\n\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    printf("\n________________________________________________\n");
    printf("ITEM NO\t\t PRICE \t\t QTY\n");
    printf("________________________________________________\n");

    FILE* display_stock;
    display_stock = fopen("stockdetail.txt","r");// open stock file in read mode
     if(display_stock==NULL)
     {
         printf("FILE NOT FOUND!..");
     }
    fscanf(display_stock,"%d %f %d ",&arr2[i][0],&arr1[i][0],&arr2[i][1]);
    while(!feof(display_stock)) //display stock details process
  {
     printf("%d\t\t%.2f\t\t%d\n",arr2[i][0],arr1[i][0],arr2[i][1]);//print process
     i++;
     fscanf(display_stock,"%d %f %d ",&arr2[i][0],&arr1[i][0],&arr2[i][1]);

  }
  printf("%d\t\t%.2f\t\t%d\n",arr2[i][0],arr1[i][0],arr2[i][1]);
  fclose(display_stock);// close stock file
  printf("\n\n\n");

    //back to main menu
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter1);
    switch(enter1)//back to main menu
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
       default : printf("INVAILD VALUE!..");
    }

}


void loading()//define function
{
    display_name();// display name in head
    printf("\n\n INPUT LOADING DETAILS.. \n");//input details
    int salesman_id[10];
    int vehicle_no[6];
    int item_no[5];
    int quantity[10];
    int date;
    int enter3;
    char line_count_1[1000];
    int available;


     FILE* global_variable;
    global_variable=fopen("global.txt","r");
    fscanf(global_variable,"%d %d %d %d",&i1,&i2,&in1,&in2);

    FILE* global_variable2;
    global_variable2=fopen("global2.txt","r");
    fscanf(global_variable2,"%d %d %d %d %d %d",&si1,&v1,&si2,&v2,&si3,&v3);

    FILE* global_variable3;
    global_variable3=fopen("global3.txt","w");

    FILE* loading_details;
    loading_details=fopen("LOADING_DETAILS.txt","a");//open LOADING_DETAILS File in append mode

    FILE* sales;
    sales=fopen("sales.txt","a");

   // FILE* item;
  //  item=fopen("item.txt","a");

    printf("ENTER DATE :");//input only date , don"t enter month or year
    scanf("%d",&date);

    /*check whether these ID number and vehicle numbers are in salesmen details
      above condition is true,
      checking correct item number or not
      this condition is true put loading quantity,
      it is wrong print message and back to loading
      */

    for(int i=0;i<MAN;i++)//add loading items
    {
        printf("SALESMAN ID NO :");
        scanf("%d",&salesman_id[i]);
        printf("VEHICLE NO :");
        scanf("%d",&vehicle_no[i]);
    if(si1==salesman_id[i]&&v1==vehicle_no[i])    {
        for(int j=0;j<ITEM;j++)

        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])//checking correct item number or not
            {

              printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
              s1i1=quantity[j];
            }
            else if (in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                s1i2=quantity[j];
            }
            else
            {
                printf("INVALID ITEM NUMBER...\n");
                loading();
                break;
            }

            fprintf(loading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
            fprintf(loading_details,"\n");
        }
        printf("\n");

    }
    else if(si2==salesman_id[i]&&v2==vehicle_no[i])
    {
         for(int j=0;j<ITEM;j++)

        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])
            {
              printf("ITEM QUANTITY :");
              scanf("%d",&quantity[j]);
              s2i1=quantity[j];

            }
            else if (in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                  s2i2=quantity[j];
            }
            else
            {
                printf("INVALID ITEM NUMBER...\n");
                loading();
                break;
            }

            fprintf(loading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
            fprintf(loading_details,"\n");
        }
        printf("\n");

    }
    else if (si3==salesman_id[i]&&v3==vehicle_no[i])
    {
         for(int j=0;j<ITEM;j++)

        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])
            {
              printf("ITEM QUANTITY :");
              scanf("%d",&quantity[j]);
              s3i1=quantity[j];

            }
            else if (in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                s3i2=quantity[j];
            }
            else
            {
                printf("INVALID ITEM NUMBER...\n");
                loading();
                break;
            }

            fprintf(loading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
            fprintf(loading_details,"\n");
        }
        printf("\n");

    }
    else
        {
            printf("INVALID ID NUMBER OR VEHICLE NUMBER!..\n\n");
        }
    }
       fprintf(global_variable3,"%d\t%d\t%d\t%d\t%d\t%d\t%d",date,s1i1,s1i2,s2i1,s2i2,s3i1,s3i2);


       //close files
      fclose(loading_details);
      fclose(global_variable);
      fclose(global_variable2);
      fclose(global_variable3);

      //back to main menu
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter3);
    switch(enter3)
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
        default: printf("INVALID VALUE!..");
    }

}


void display_loading()//define function
{

    display_name(); // display name
    int arr1[500][5];
    int i=0;
    int enter4;

    //print process name
    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3 LOADING DETAILS \xB3 ");
    printf("\n\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
     printf("\n________________________________________________________________________\n");
    printf("DATE\t\t S.ID\t\t V.NO\t\t I.NO\t \tQUANTITY\n");
    printf("________________________________________________________________________\n\n");

    FILE* display_loading;
    display_loading = fopen("LOADING_DETAILS.txt","r");// open loading file in read mode
     if(display_loading==NULL)
     {
         printf("FILE NOT FOUND!..");
     }
    while(!feof(display_loading)) //display loading process

  {
     printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr1[i][0],arr1[i][1],arr1[i][2],arr1[i][3],arr1[i][4]);
     i++;//increment values
     fscanf(display_loading,"%d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4]);

  }
  fclose(display_loading);// close file

   //back to main menu
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter4);
    switch(enter4)//back to main menu
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
    }

}

//assume that the unloading data applies only to that date
void unloading()
{

    display_name();// display name in head
    printf("\n\n INPUT UNLOADING DETAILS.. \n");//input details
    int salesman_id[10];
    int vehicle_no[6];
    int item_no[5];
    int quantity[10];
    int date2;
    int enter5;


    FILE* unloading_details;
    unloading_details=fopen("UNLOADING_DETAILS.txt","a");//open LOADING_DETAILS File in append mode

    FILE* global_variable3;
    global_variable3=fopen("global3.txt","r");
    fscanf(global_variable3,"%d %d %d %d %d %d %d",&date,&s1i1,&s1i2,&s2i1,&s2i2,&s3i1,&s3i2);

     FILE* global_variable;
    global_variable=fopen("global.txt","r");
    fscanf(global_variable,"%d %d %d %d",&i1,&i2,&in1,&in2);

    FILE* global_variable2;
    global_variable2=fopen("global2.txt","r");
    fscanf(global_variable2,"%d %d %d %d %d %d",&si1,&v1,&si2,&v2,&si3,&v3);

    FILE* sales;
    sales=fopen("sales.txt","a");

    FILE* global_variable4;
    global_variable4=fopen("global4.txt","w");

    printf("ENTER DATE :");
    scanf("%d",&date2);
       if(date==date2)
    {
    for(int i=0;i<MAN;i++)//add loading items
    {
        printf("SALESMAN ID NO :");
        scanf("%d",&salesman_id[i]);
        printf("VEHICLE NO :");
        scanf("%d",&vehicle_no[i]);
        if(si1==salesman_id[i]&&v1==vehicle_no[i])
        {
        for(int j=0;j<ITEM;j++)
        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])
            {
            printf("ITEM QUANTITY :");
            scanf("%d",&quantity[j]);
            if(s1i1>=quantity[j])
            {
                sales1i1=(s1i1-quantity[j]);
            }
            else
            {
                printf("INVALID VALUE!..\n");
                unloading();
                break;
            }
            } else if(in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                if(s1i2>=quantity[j])
                {
                    sales1i2=(s1i2-quantity[j]);
                }
                else
                {
                    printf("INVALID VALUE!..\n");
                    unloading();
                    break;
                }
            }
            else{ printf("INVALID ITEM NUMBER!..\n");
                main_menu();
                break;
            }
            fprintf(unloading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
        }
        printf("\n");
    }
    else if(si2==salesman_id[i]&&v2==vehicle_no[i])
    {
       for(int j=0;j<ITEM;j++)
        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])
            {
            printf("ITEM QUANTITY :");
            scanf("%d",&quantity[j]);
            if(s2i1>=quantity[j])
            {
                sales2i1=s2i1-quantity[j];
            }
             else
                {
                    printf("INVALID VALUE!..\n");
                    unloading();
                    break;
                }
            } else if(in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                if(s2i2>=quantity[j])
                {
                    sales2i2=s2i2-quantity[j];
                } else
                {
                    printf("INVALID VALUE!..\n");
                    unloading();
                    break;
                }
            }
            else{
                printf("INVALID ITEM NUMBER!..\n");
                unloading();
                break;
            }
            fprintf(unloading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
        } printf("\n");
    }
    else if(si3==salesman_id[i]&&v3==vehicle_no[i])
    {
        for(int j=0;j<ITEM;j++)
        {
            printf("ITEM NO :");
            scanf("%d",&item_no[j]);
            if(in1==item_no[j])
            {
            printf("ITEM QUANTITY :");
            scanf("%d",&quantity[j]);
            if(s3i1>=quantity[j])
            {
                sales3i1=s3i1-quantity[j];
            } else
                {
                    printf("INVALID VALUE!..\n");
                    unloading();
                    break;
                }
            } else if(in2==item_no[j])
            {
                printf("ITEM QUANTITY :");
                scanf("%d",&quantity[j]);
                if(s3i2>=quantity[j])
                {
                    sales3i2=s3i2-quantity[j];
                }
                 else
                {
                    printf("INVALID VALUE!..\n");
                   unloading();

                    break;
                }
            }
            else{
                printf("INVALID ITEM NUMBER!..\n");
                unloading();
                break;
            }
            fprintf(unloading_details,"%d\t %d\t %d\t %d\t %d\n",date,salesman_id[i],vehicle_no[i],item_no[j],quantity[j]);
        }  printf("\n");
    }else
    {
    printf("INVALID ID NUMBER OR VEHICLE NUMBER\n\n");
    main_menu();
    }
    }
    }
      fprintf(sales,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",date,sales1i1,sales1i2,sales2i1,sales2i2,sales3i1,sales3i2);
      fprintf(global_variable4,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",date,sales1i1,sales1i2,sales2i1,sales2i2,sales3i1,sales3i2);
      fclose(unloading_details);//close file
      fclose(global_variable3);
      fclose(global_variable2);
      fclose(global_variable);
      fclose(global_variable4);
      fclose(sales);
    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter5);
    switch(enter5)//back to main menu
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
    }

}

void display_unloading()//define function
{

    display_name(); // display name
    int arr1[500][5];
    int i=0;
    int enter6;

    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3 UNLOADING DETAILS \xB3 ");
    printf("\n\xC0\xC4\xC4\xC4\xc4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    printf("\n________________________________________________________________________\n");
    printf("DATE\t\t S.ID\t\t V.NO\t\t I.NO\t \tUN.QTY\n");
    printf("________________________________________________________________________\n\n");


    FILE* display_unloading;
    display_unloading = fopen("UNLOADING_DETAILS.txt","r");// open unloading file in read mode
     if(display_unloading==NULL)
     {
         printf("FILE NOT FOUND!..");
     }
    while(!feof(display_unloading)) //display process
  {
     printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr1[i][0],arr1[i][1],arr1[i][2],arr1[i][3],arr1[i][4]);
     i++;//increment values
     fscanf(display_unloading,"%d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4]);

  }
  fclose(display_unloading);// close  file
   printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter6);
    switch(enter6)//back to main menu
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
    }

}

void sales()
{
   //system("color F0");
   display_name();
   int enter7;
   int i=0;
   int arr1[31][7];
   int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0;


    FILE* global_variable3;
    global_variable3=fopen("global3.txt","r");
     if(global_variable3==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable3,"%d %d %d %d %d %d %d",&date,&s1i1,&s1i2,&s2i1,&s2i2,&s3i1,&s3i2);

     FILE* global_variable;
    global_variable=fopen("global.txt","r");
     if(global_variable==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable,"%d %d %d %d",&i1,&i2,&in1,&in2);

    FILE* global_variable2;
    global_variable2=fopen("global2.txt","r");
     if(global_variable2==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable2,"%d %d %d %d %d %d",&si1,&v1,&si2,&v2,&si3,&v3);

    FILE* calculations;
    calculations=fopen("calculation.txt","w");

    FILE* sales;
    sales=fopen("sales.txt","r");
    if(sales==NULL)
    {
        printf("NOT FOUND!..");
    }

    FILE* global_variable4;
    global_variable4=fopen("global4.txt","r");
    if(global_variable4==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable4,"%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&date,&sales1i1,&sales1i2,&sales2i1,&sales2i2,&sales3i1,&sales3i2);
    //printf("%d \n %d \n",sales1i1,sales1i2);

    FILE* display_sales;
    display_sales=fopen("sales.txt","r");

   printf("COL 1 - SALESMAN ID : %d\n",si1);
   printf("        ITEM NO     : %d\n\n",in1);
   printf("COL 2 - SALESMAN ID : %d\n",si1);
   printf("        ITEM NO     : %d\n\n",in2);
   printf("COL 3 - SALESMAN ID : %d\n",si2);
   printf("        ITEM NO     : %d\n\n",in1);
   printf("COL 4 - SALESMAN ID : %d\n",si2);
   printf("        ITEM NO     : %d\n\n",in2);
   printf("COL 5 - SALESMAN ID : %d\n",si3);
   printf("        ITEM NO     : %d\n\n",in1);
   printf("COL 6 - SALESMAN ID : %d\n",si3);
   printf("        ITEM NO     : %d\n\n",in2);

    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3    SALES     \xB3 ");
    printf("\n\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

   printf("____________________________________________________________\n");
   printf(" DATE \t COL 1\tCOL 2\tCOL 3\tCOL 4\tCOL 5\tCOL 6\n");
   printf("____________________________________________________________\n\n");
   fscanf(display_sales,"%d %d %d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4],&arr1[i][5],&arr1[i][6]);
   while(!feof(display_sales)) //display process
 {
     printf(" %d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr1[i][0],arr1[i][1],arr1[i][2],arr1[i][3],arr1[i][4],arr1[i][5],arr1[i][6]);

     sum1=sum1+arr1[i][1];
     sum2=sum2+arr1[i][2];
     sum3=sum3+arr1[i][3];
     sum4=sum4+arr1[i][4];
     sum5=sum5+arr1[i][5];
     sum6=sum6+arr1[i][6];
      i++;//increment values
     fscanf(display_sales,"%d %d %d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4],&arr1[i][5],&arr1[i][6]);

  }
   printf("\n____________________________________________________________\n");
   printf("  \t%d\t%d\t%d\t%d\t%d\t%d\n",sum1,sum2,sum3,sum4,sum5,sum6);
   printf("____________________________________________________________\n");
   fprintf(calculations,"%d\t%d\t%d\t%d\t%d\t%d\n",sum1,sum2,sum3,sum4,sum5,sum6);

    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3 PERFORMANCE  \xB3 ");
    printf("\n\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");


   int a1=sum1/100.0;

   printf("\nSALESMAN ID :%d\n",si1);
   printf("ITEM NO :%d\n  ",in1);
   for(i=0;i<a1;i++)
   {
       printf("\xDB");
   }
   printf("\n");

   int a2=sum2/100.0;

   printf("ITEM NO :%d\n  ",in2);
   for(i=0;i<a2;i++)
   {
       printf("\xDB");
   }
    printf("\n");
   int a7=(sum1+sum2)/100.0;
   printf("Total\n  ");
    for(i=0;i<a7;i++)
   {
       printf("\xDB");
   }

   printf("\n");
   int a3=sum3/100.0;

   printf("\nSALESMAN ID :%d\n",si2);
   printf("ITEM NO :%d\n  ",in1);
   for(i=0;i<a3;i++)
   {
       printf("\xDB");
   }
   printf("\n");

   int a4=sum4/100.0;

   printf("ITEM NO :%d\n  ",in2);
   for(i=0;i<a4;i++)
   {
       printf("\xDB");
   }
   printf("\n");
    int a8=(sum3+sum4)/100.0;
   printf("Total\n  ");
    for(i=0;i<a8;i++)
   {
       printf("\xDB");
   }

   printf("\n");

   int a5=sum5/100.0;

   printf("\nSALESMAN ID :%d\n",si3);
   printf("ITEM NO :%d\n  ",in1);
   for(i=0;i<a5;i++)
   {
       printf("\xDB");
   }
   printf("\n");

   int a6=sum6/100.0;

   printf("ITEM NO :%d\n  ",in2);
   for(i=0;i<a6;i++)
   {
       printf("\xDB");
   }
   printf("\n");

    int a9=(sum5+sum6)/100.0;
   printf("Total\n  ");
    for(i=0;i<a9;i++)
   {
       printf("\xDB");
   }

   printf("\n");
   printf("\n");
      fclose(display_sales);
      fclose(global_variable2);
      fclose(global_variable3);
      fclose(global_variable);
      fclose(global_variable4);
      fclose(calculations);



    printf("BACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter7);
    switch(enter7)//back to main menu
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;
    }
}

void report()
{
    display_name();
     int arr1[31][6];
  int item1=0,item2=0;
  int stock1=0,stock2=0;
int i=0;
int enter;

  FILE* global_variable3;
    global_variable3=fopen("global3.txt","r");
     if(global_variable3==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable3,"%d %d %d %d %d %d %d",&date,&s1i1,&s1i2,&s2i1,&s2i2,&s3i1,&s3i2);

     FILE* global_variable;
    global_variable=fopen("global.txt","r");
     if(global_variable==NULL)
    {
        printf("NOT FOUND!..");
    }
    fscanf(global_variable,"%d %d %d %d",&i1,&i2,&in1,&in2);

    FILE* calculations;
    calculations=fopen("calculation.txt","r");
    if(calculations==NULL)
    {
        printf("Not found!..");
    }

    fscanf(calculations,"%d %d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4],&arr1[i][5]);

    while(!feof(calculations))
    {   item1=item1+arr1[i][0]+arr1[i][2]+arr1[i][4];
        item2=item2+arr1[i][1]+arr1[i][3]+arr1[i][5];
        i++;
        fscanf(calculations,"%d %d %d %d %d %d",&arr1[i][0],&arr1[i][1],&arr1[i][2],&arr1[i][3],&arr1[i][4],&arr1[i][5]);

    }

    stock1=i1-item1;
    stock2=i2-item2;


    printf("\n           DATE: 1 to %d    SALES & AVALABILTY \n\n",date);

    printf("\n\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF");
    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xB3   ITEM NO             \xB3     SALES QTY      \xB3  AVAILABLE QTY     \xB3");
    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4");

    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xB3   ITEM %d           \xB3   %d           \xB3      %d          \xB3",in1,item1,stock1);
    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xC3\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4");
    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xB3   ITEM %d           \xB3   %d           \xB3      %d          \xB3",in2,item2,stock2);
    printf("\n\xB3                       \xB3                    \xB3                    \xB3");
    printf("\n\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9");


    fclose(calculations);
    fclose(global_variable);
    fclose(global_variable3);
     printf("\nBACK TO MAIN MENU : ENTER [1]\n");
    printf("ENTER :");
    scanf("%d",&enter);
     switch(enter)
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;

    }

}

void main_page()
{
    int enter;
    printf("\n\n  ******      ******");
    printf("\n   ******    ******");
    printf("\n    ******  ******");
    printf("\n    ************");
    printf("\n    ******  ******");
    printf("\n   ******    ******");
    printf("\n  ******      ******");

    printf("\n\n  ******      ******       WELCOME!..");
    printf("\n   ******    ******          CONTINUE PRESS 1");
    printf("\n    ******  ******           ");
    printf("\n     ************");
    printf("\n     ************");
    printf("\n     ************");
    printf("\n     ************");
    printf("\n     ************");

    printf("\n\n   **************");
    printf("\n   **************");
    printf("\n        *******");
    printf("\n       *******");
    printf("\n      *******");
    printf("\n     *******");
    printf("\n    *******");
    printf("\n   *******");
    printf("\n  **************");
    printf("\n  **************\n\n");
     scanf("%d",&enter);

     switch(enter)
    {
        case 1 : system("cls");
                 display_name();
                 printf("\n");
                 main_menu();
                 break;

         default: printf("INVALD VALUE!..");
         main_page();
    }
}
