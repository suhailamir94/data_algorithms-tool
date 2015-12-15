#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
//#include<iostream>
#include<string.h>
//char arrow[20][20],pattern[10];



void greedy()
{   system("cls");
        int choice;
      printf("\n________________________________________________________________________________");
        printf("\n\n1. Fractional Knapsack");


        printf("\n\nPlease enter your choice: ");
        scanf("%d",&choice);
        label1:
        if(choice==1)
         {fractional_knapsack();
            system("cls");
         }
        else
{

      printf("\n\nPlease Enter A Valid Choice: ");
        scanf("%d",&choice);
        goto label1;
}
}

//________________________________FRACTIONAL KNAPSACK________________________________________________________





void fractional_knapsack()
{
    int try,value[100],items,i,j=0;
    float capacity,weight[100],profit=0.0,swap1=0.0,s[100],x[100];
   // system("cls");
   system("cls");
    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tFractional Knapsack");
    printf("\n\nEnter Knapsack Capacity: ");
    scanf("%f",&capacity);\
    printf("\nEnter no. of Items: ");
    scanf("%d",&items);
    printf("\nEnter Weight For Each Item :");
    for(i=0;i<items;i++)
    { j++;
	printf("\n\n%d :  ",j);
	scanf("%f",&weight[i]);
	printf("\n");
    }
    j=0;
    printf("\nEnter Value of Each Item :");
   for(i=0;i<items;i++)
    { j++;
	printf("\n\n%d :  ",j);
	scanf("%d",&value[i]);
	printf("\n");
    }
    for(i=0;i<items;i++)
    {
    x[i]=0;
    s[i]=value[i]/weight[i];
    }

    for(i=0;i<items-1;i++)
    {

    for(j=i;j<items-1;j++)

    {


	    if(s[j]<s[j+1])
	    {
		swap1=s[j];
		s[j]=s[j+1];
		s[j+1]=swap1;
		swap1=value[j];
		value[j]=value[j+1];
		value[j+1]=swap1;
		swap1=weight[j];
		weight[j]=weight[j+1];
		weight[j+1]=swap1;
	    }
    }

    }

	    for(i=0;i<items;i++)
	    {
		if(weight[i]<capacity)
		{
		    x[i]=1;
		    capacity=capacity-weight[i];
		}

		else

		{
		    break;
		}
	    }

	    if(i<=items)
	    {
		    x[i]=capacity/weight[i];

	    }

	    for(i=0;i<items;i++)
	    {
		    profit=profit+(value[i]*x[i]);

	    }
	    printf("\n\nTotal Profit : Rs %f",profit);
	    printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {
            system("cls");


	    }
	    else
		exit(0);
}






//___________________________MATRIX CHAIN MULTIPLICATION__________________________________________________

void print_optimal_paranthesis(int array[50][50],int i,int j)
{

    if(i==j)
    {
	printf("%d",i);

    }
    else
	{
	    printf("(");


    print_optimal_paranthesis(array,i,array[i][j]);
    print_optimal_paranthesis(array,array[i][j]+1,j);
    printf(")");
	}


}







void matrix_chain_multiplication()
{
    int matrix[20],m[50][50],s[50][50],z,q,i,j=0,length,n,l,k,try;
   // system("cls");
   system("cls");
    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tMatrix Chain Multiplication");
    printf("\n\nEnter no. of elements: ");
    scanf("%d",&length);
    printf("\n\nEnter The Array:");
    n=length-1;
    z=n;
    for(i=0;i<length;i++)
    { j++;
	printf("\n\n%d :  ",j);
	scanf("%d",&matrix[i]);
	printf("\n");
    }

    for(i=1;i<=n;i++)
    {


	 m[i][i]=0;

    }
    for(l=2;l<=n;l++)
    {
	for(i=1;i<=n-l+1;i++)
	{
	    j=i+l-1;
	    m[i][j]=10000;
	    for(k=i;k<=j-1;k++)
	    {
		q=m[i][k]+m[k+1][j]+(matrix[i-1]*matrix[k]*matrix[j]);
		if(q<m[i][j])
		{
		    m[i][j]=q;
		    s[i][j]=k;
		}
	    }
	}
    }
/*    for(i=0;i<n;i++)
{

for(j=i;j<n;j++)
{
printf("%d %d\t",m[i][j]);
}
printf("\n");
}
*/
    printf("\n\nThe Sequence Of Matrix Multiplication Is: \n\n");
    print_optimal_paranthesis(s,1,z);
    printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {system("cls");


	    }
	    else
		exit(0);

}








//______________________________________Lowest Common Sequence______________________________________________________________



void print_lcs(int i,int j,char arrow[20][20],char *pattern)
{ int try;
		if(i==0 || j==0)
				return;
		if(arrow[i][j]=='c')
		{
				print_lcs( i-1,j-1,arrow,pattern);
				printf(" %c",pattern[i-1]);
		}
		else if(arrow[i][j]=='u')
				print_lcs(i-1,j,arrow,pattern);
		else
				{print_lcs(i,j-1,arrow,pattern);}

}

void lcs1()
{        int i,j,m,n,a,c[20][20],try;
	 char y[15],arrow[20][20],pattern[20];

	system("cls");
	printf("\n________________________________________________________________________________\n\n");
	printf("\n\n\t\t\tLongest Common Sequence\n");

		printf("\n\nEnter 1st sequence : ");
		fflush(stdin);
	gets(pattern);
		printf("\n\nEnter 2nd sequence : ");
		gets(y);
		printf("\n\nLongest common subsequence is : ");

		m=strlen(pattern);
		n=strlen(y);
		for(i=0;i<=m;i++)
				c[i][0]=0;
		for(i=0;i<=n;i++)
				c[0][i]=0;
		for(i=1;i<=m;i++)
				for(j=1;j<=n;j++)
				{
						if(pattern[i-1]==y[j-1])
						{
								c[i][j]=c[i-1][j-1]+1;
								arrow[i][j]='c';
						}
						else if(c[i-1][j]>=c[i][j-1])
						{
								c[i][j]=c[i-1][j];
								arrow[i][j]='u';
						}
						else
						{
								c[i][j]=c[i][j-1];
								arrow[i][j]='l';
						}
				}
				/*for(i=0;i<m;i++)
				{for(j=0;j<n;j++)
				{printf("%d ",c[i][j]);
				}
				printf("\n");
				}
				printf("array b is" );
					for(i=0;i<m;i++)
				{for(j=0;j<n;j++)
				{printf("%c ",b[i][j]);
				}
				printf("\n" );

				}*/
		 print_lcs(m,n,(char *)arrow,pattern);
		 printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {
system("cls");

	    }
	    else
		exit(0);

}







//_____________________________________________________1/0 knapsack___________________________________________________________







int maxi(int a,int b)
{
if(a>b)
return a;
else
return b;
}
void knapsack(int m,int n,int w[],int p[])
{
int v[20][20],x[10],i,j,sum=0,try;
for(i=0;i<=m;i++)
v[0][i]=0;
for(i=1;i<=n;i++)
{
for(j=0;j<=m;j++)
{
if(j>=w[i])
v[i][j]=maxi(v[i-1][j],v[i-1][j-w[i]]+p[i]);
else
v[i][j]=v[i-1][j];
}
}
for(i=1;i<=n;i++)
x[i]=0;
i=n;
j=m;
while(i>0 && j>0)
{
if(v[i][j]!=v[i-1][j])
{
x[i]=1;
j=j-w[i];
}
i--;
}
printf("\nThe Optimal Set Of Items: \n");
for(i=1;i<=n;i++)
{
if(x[i]==1)
{
printf("X%d=1\t",i);
sum=sum+p[i];
}
else
printf("X%d=0\t",i);
}
printf("\n\nTotal profit = %d",sum);
printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {
    system("cls");
	    }
	    else
		exit(0);
}
void zero_one_knapsack()
{

int w[10],p[10],i,m,n,j=0;
//system("cls");
system("cls");
printf("\n________________________________________________________________________________");
printf("\n\n\t\t\t0/1 KNAPSACK PROBLEM");
printf("\n\nEnter The No. Of Items: ");
scanf("%d",&n);
printf("\n\nEnter The Weight Of Items:");
for(i=1;i<=n;i++)
    { j++;
	printf("\n\n%d :  ",j);
	scanf("%d",&w[i]);
	printf("\n");
    }
printf("\n\nEnter The Value Of Each Item: \n");
for(i=1;i<=n;i++)
    { j++;
	printf("\n\n%d :  ",j);
	scanf("%d",&p[i]);
	printf("\n");
    }
printf("\n\nEnter The Capacity Of Knapsack: ");
scanf("%d",&m);
knapsack(m,n,w,p);

}




//______________________________________________________PATTERN MATCHING_______________________________________________________________




//                                       ______________NAIVE STRING MATCHER____________




void naive()
{


int i,j,m,n,b=0,v,ar[15],t=0,try;
char x[15],y[15];
system("cls");
    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tNaive String Matcher");
fflush(stdin);
   printf("\n\nEnter 1st sequence : ");
		gets(x);
	printf("\nEnter 2nd sequence : ");
		gets(y);
		n=strlen(x);
		m=strlen(y);
		for(i=0;i<=(n-m+1);i++)
		{j= 0;
		while(x[i+j-1]==y[j] && j<m)
		{j++;
		}
		if(j==m)
	       {      //	printf("match at %d",i);
	       b=1;
	       v=i;
	    //   printf("%d",v);
	       ar[t]=v;
	       t++;
		}
		}
		if(b==1)
		{printf("\n\nmatch found at:  ");
		for(i=0;i<t;i++)
		{printf("%d  ",ar[i]);}
		}
		else
		 {printf("\n\nmatch fail");
		}
printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {
             system("cls");

	    }
	    else
		exit(0);
}

//                                     ______________Robin Karp____________


void RobinKarpStringMatch(char *Text, char *Pattern)
{
       int m,n,h,P=0,T=0, d=0,TempT,Number=11;
       int i,j,try,match=0;
       m = strlen(Pattern);
       n = strlen(Text);
       h = (int)pow(d,m-1) % Number;
       for(i=0;i<m;i++)  {
                       P = ((d*P) + ((int)Pattern[i])) % Number;
                      TempT = ((d*T) + ((int)Text[i]));
                       T =  TempT % Number;
       }
       for(i=0;i<=n-m;i++)  {
                       if(P==T)  {
                                       for(j=0;j<m;j++)
                                                       if(Text[i+j] != Pattern[j])
                                                                       break;
                                       if(j == m)
                                       {
                                         match=1;

                                                       printf("\nPattern Found at Position :  %d",i+1);
                                       }

                       }
                       TempT =((d*(T - (int)Text[i]*h)) + ((int)Text[i+m]));
                       T = TempT % Number;
                       if(T<0)
                                       T=T+Number;
       }
       if(match<1)
                                       {
                                           printf("\nPattern Not Found");
                                       }
      // printf("\n\nPattern not found");
printf("\n\nPress 1 To Continue And 0 To Exit ");
	    scanf("%d",&try);
	    if(try==1)
	    {

             system("cls");
	    }
	    else
		exit(0);
}

void robin_karp()
{
       char Text[20], Pattern[15];

       system("cls");

    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tRobin Karp");
    fflush(stdin);
       printf("\n\nEnter Text String : ");
       gets(Text);
       printf("\nEnter Pattern String : ");
       gets(Pattern);

       RobinKarpStringMatch(Text,Pattern);



}






void dynamic()
{system("cls");
    int choice;
    printf("\n________________________________________________________________________________");
     printf("\n\n1. Matrix Chain Multiplication");
    printf("\n\n2. Longest Common Sub Sequence");
    printf("\n\n3. 0/1 Knapsack");
    printf("\n\nPlease Enter your Choice: ");
    abd:
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:matrix_chain_multiplication();
	break;
	case 2:lcs1();
	break;
	case 3:zero_one_knapsack();
	break;
        case 4:system("cls");
        break;
        default:printf("Please enter a valid choice: ");
        goto abd;
        break;

    }
}



void pattern_matching()
{
    int choice=0;
   // system("cls");
   system("cls");
label:
    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tPattern Matching");
    printf("\n\nYour choices for pattern matching are:");
    printf("\n\n1. Naive String Match");
    printf("\n\n2. Robin Karp");


    printf("\n\n3. Goto Main Menu");
    printf("\n\nPlease Enter Your Choice: ");
    pattern:
    scanf("%d",&choice);
    switch(choice)
	{
        case 1: naive();
        break;
        case 2:robin_karp();
        break;

	    case 3:system("cls");
        break;

	    default: printf("\n\nPlease Enter A Correct Choice: ");
	    goto pattern;
	    break;
	}


}





//_________________________________________MAIN FUNCTION__________________________________________________








int main()
{    system("cls");
    int choice=0;
    char name[10];
    printf("Enter Your Name: ");
    gets(name);
    printf("\n\t\t\t\tWelcome %s",name);

   while(1)
 {


    printf("\n________________________________________________________________________________");
    printf("\n\n\t\t\tYou have the following Choices:");
    printf("\n\n1. Greedy Approach Problems");
    printf("\n\n2. Dynamic Approach Problems");


    printf("\n\n3. Pattern Matching");
    printf("\n\n4. Exit");
    abc:
    printf("\n\nPlease enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1:greedy();
	break;
	case 2:dynamic();
	break;
	case 3:pattern_matching();
	break;
	case 4:exit(0);
	break;
	default:printf("\n\nInvalid Choice!!\nTry Again!! ");
	goto abc;
	break;
    }


 }
    return 0;
}
