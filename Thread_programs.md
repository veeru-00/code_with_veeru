1.Write a C program to create a thread that prints "Hello, World!"?
```
#include<stdio.h>
#include<pthread.h>
void *print(void *arg)
{
	printf("hello world\n");
	return NULL;
}

int main(void)
{
	pthread_t id;
	if(pthread_create(&id,NULL,print,NULL) !=0)
	{
		printf("Failed to create the thread");
	}
	pthread_join(id,NULL);
	return 0;
}
```
2.Modify the above program to create multiple threads, each printing its own message?
```
#include<stdio.h>
#include<stdlib.h>-
#include<pthread.h>
void *thread_1(void *arg)
{
	printf("This is first thread\n");
	return NULL;
}
void *thread_2(void *arg)
{
	printf("This is second thread\n");
	return NULL;
}
int main(void)
{
	pthread_t id,id2;
	pthread_create(&id,NULL,thread_1,NULL);
	pthread_create(&id2,NULL,thread_2,NULL);
	pthread_join(id,NULL);
	pthread_join(id2,NULL);
	return 0;
}
```
3.Develop a C program to create two threads that print numbers from 1 to 10 concurrently?
```
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define N 10
void *thread_1(void *arg)
{
	for(int i=1;i<=N;i++)
	{
		printf("%d ",i);
	}
	return NULL;
}
void *thread_2(void *arg)
{
	for(int i=1;i<=N;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	return NULL;
}

int main(void)
{
	pthread_t id1,id2;
	pthread_create(&id1,NULL,thread_1,NULL);
	pthread_create(&id2,NULL,thread_2,NULL);
	pthread_join(id1,NULL);
	pthread_join(id2,NULL);
	return 0;
}
```
4.Implement a C program to create a thread that calculates the factorial of a given number?
```
#include<stdio.h>
#include<pthread.h>

void *thread(void *n)
{
	int y=*(int *)n;
	long int fact=1;
	int i;
	for(i=1;i<=y;i++)
	{
		fact=fact*i;
	}
	printf("%ld is the result",fact);
	return NULL;
}
int main(void)
{
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	pthread_t pt;
	if(n<0)
	{
		printf("Enter the positive number");
		return 0;
	}
	pthread_create(&pt,NULL,thread,&n);
	pthread_join(pt,NULL);
	return 0;
}
```
5.Write a C program to create two threads that print their thread IDs?
```
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *fun()
{
	printf("%d is the thread id",getpid());
}
int main(void)
{
	pthread_t t1;
	pthread_create(&t1,NULL,fun,NULL);
	pthread_join(t1,NULL);
	return 0;
}
```
6.Develop a C program to create a thread that prints the sum of two numbers?
```
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *sum(void *arg)
{
	int *arr=(int*)arg;
	int *sum=malloc(sizeof(int));
	if(sum==NULL)
	{
		printf("Error in malloc");
		return NULL;
	}
	*sum=arr[0]+arr[1];
	return sum;
}
int main(void)
{
	int arr[2]={1,2};
	void *ret;
	pthread_t pt;
	pthread_create(&pt,NULL,sum,arr);
	pthread_join(pt,&ret);
	int *sum=(int *)ret;
	printf("%d is the sum",*sum);
	free(sum);
	return 0;
}
```
7.Implement a C program to create a thread that calculates the square of a number?
```
#include<stdio.h>
#include<pthread.h>

void *fun(void *arg)
{
	int *x=(int *)arg;
	*x=(*x)*(*x);
	printf("product=%d",*x);
}
int main(void)
{
	int x;
	printf("Enter the number:");
	scanf("%d",&x);
	pthread_t t1;
	pthread_create(&t1,NULL,fun,&x);
	pthread_join(t1,NULL);
	return 0;
}
```
8.Write a C program to create a thread that prints the current date and time?
```
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>

void *fun(void *arg)
{
	time_t now;
	struct tm *timeinfo;
	time(&now);
	timeinfo=localtime(&now);
	printf("Current date and time:%s",asctime(timeinfo));
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t t1;
	pthread_create(&t1,NULL,fun,NULL);
	pthread_join(t1,NULL);
	return 0;
}
```	
9.Develop a C program to create a thread that checks if a number is prime?
```
#include<stdio.h>
#include<pthread.h>
#include<math.h>
void *fun(void *arg)
{
	int *x=(int*)arg;
	int i;
	for(i=2;i<=sqrt(*x);i++)
	{
		if(*x%i==0)
		{
			printf("%d is not a prime number",*x);
			return NULL;
		}
	}
	printf("%d is a prime number",*x);
	return NULL;

}
int main(void)
{
	pthread_t tp;
	int x;
	printf("Enter the number:");
	scanf("%d",&x);
	pthread_create(&tp,NULL,fun,&x);
	pthread_join(tp,NULL);
	return 0;
}
```
10.Implement a C program to create a thread that checks if a given string is a palindrome?
```
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdbool.h>
#define N 100
void *ispalindrom(void *arg)
{
	char *str=(char*)arg;
	int len=strlen(str);
	bool ispal=true;
	for(int i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-i-1])
		{
			ispal=false;
			break;
		}
	}
	if(ispal)
	{
		printf("%s is palindrome",str);
		return NULL;
	}
	else
	{
		printf("%s is not palindrome",str);
		return NULL;
	}
}
int main(void)
{
	char str[N];
	printf("Enter the string:");
	fgets(str,sizeof(str),stdin);
	pthread_t pt;
	pthread_create(&pt,NULL,ispalindrom,str);
	pthread_join(pt,NULL);
	return 0;
}
```
11.Write a C program to create a thread that prints "Hello, World!" with thread synchronization? 
```
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *hell(void *arg)
{
	pthread_mutex_lock(&lock);
	printf("Hello world");
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,hell,NULL);
	pthread_join(pt,NULL);
	return 0;
}

//12.Develop a C program to create two threads that print their thread IDs and synchronize theiroutput?
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *fun(void *arg)
{
	pthread_mutex_lock(&lock);
	printf("Thread id: %lu",pthread_self());
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(void)
{
	pthread_t p1,p2;
	pthread_create(&p1,NULL,fun,NULL);
	pthread_create(&p2,NULL,fun,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}
```
13.Implement a C program to create a thread that generates random numbers and synchronizes access to a shared buffer?
```
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include<stdlib.h>
#define NUM 5
int i,size;
pthread_mutex_t lock;
void *number(void *args)
{
	for(i=0;i<NUM;i++)
	{
		pthread_mutex_lock(&lock);
		size=rand()%100;
		printf("Geenrated numbers:%d\n",size);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(void)
{
	pthread_t pt;
	srand(time(NULL));
	pthread_create(&pt,NULL,number,NULL);
	pthread_join(pt,NULL);
	printf("Final value:%d",size);
	pthread_mutex_destroy(&lock);
	return 0;
}
```
14.Write a C program to create a thread that performs addition of two numbers with mutex locks?
```
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t lock;
void *fun(void *arg)
{
	int *num=(int*)arg;
	pthread_mutex_lock(&lock);
	int *sum=malloc(sizeof(int));
	*sum=num[0]+num[1];
	pthread_mutex_unlock(&lock);
	pthread_exit((void*)sum);
}
int main(void)
{
	int arr[]={1,2};
	void *res;
	pthread_t pt;
	pthread_create(&pt,NULL,fun,arr);
	pthread_join(pt,&res);
	int *sum=(int *)res;
	printf("sum=%d",*sum);
	free(sum);
	pthread_mutex_destroy(&lock);
	return 0;
}
```
15.Implement a C program to create two threads that increment and decrement a shared variable, respectively, using mutex locks? 
```
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
int size=5;
void *in(void *arg)
{
	int i,num=5;
	for(i=0;i<size;i++)
	{
		pthread_mutex_lock(&lock);
		printf("Increse:%d\n",num++);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
void *de(void *arg)
{
	int i,num=5;
	for(i=0;i<size;i++)
	{
		pthread_mutex_lock(&lock);
		printf("Decrease:%d\n",num--);
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(void)
{
	pthread_t p1,p2;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&p1,NULL,in,NULL);
	pthread_create(&p2,NULL,de,NULL);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	return 0;
}
```
16.Develop a C program to create a thread that reads input from the user and synchronizes access to shared resources? 
```
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define SIZE 100
pthread_mutex_t lock;
char shared_buffer[SIZE];
void *read(void *arg)
{
	pthread_mutex_lock(&lock);
	printf("Enter the string:");
	fgets(shared_buffer,SIZE,stdin);
	shared_buffer[strcspn(shared_buffer,"\n")]='\0';
	printf("Thread read:%s\n",shared_buffer);
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_mutex_init(&lock,NULL);
	pthread_create(&pt,NULL,read,NULL);
	pthread_join(pt,NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
```
17.Implement a C program to create a thread that prints prime numbers up to a given limit with mutex locks?
```
#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>
#include<math.h>

pthread_mutex_t lock;
bool isprime(int n)
{
	if(n<2)
	{
		return false;
	}
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
void *fun(void *arg)
{
	int *limit=(int*)arg;
	for(int i=0;i<=*limit;i++)
	{
		if(isprime(i))
		{
			pthread_mutex_lock(&lock);
			printf("%d ",i);
			pthread_mutex_unlock(&lock);
		}
	}
	printf("\n");
	return NULL;
}
int main(void)
{
	pthread_t pt;
	int limit;
	printf("Enter the limit:");
	scanf("%d",&limit);
	pthread_create(&pt,NULL,fun,&limit);
	pthread_join(pt,NULL);
	return 0;
}
```
18.Implement a C program to create a thread that calculates the sum of Fibonacci numbers up to a given limit using dynamic programming with mutex locks?
```
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t lock;
int sum;
void *fun(void *arg)
{
	int n=*(int*)arg;
	int i;
	int *fib=malloc((n+1)*sizeof(int));
	if(fib==NULL)
	{
		printf("Memory allocation failed");
		return NULL;
	}
	fib[0]=0;
	fib[1]=1;
	pthread_mutex_lock(&lock);
	sum=fib[0]+fib[1];
	for(i=2;i<=n;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		sum=sum+fib[i];
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	int limit;
	printf("Enter the limit:");
	scanf("%d",&limit);
	pthread_mutex_init(&lock,NULL);
	pthread_create(&pt,NULL,fun,&limit);
	pthread_join(pt,NULL);
	pthread_mutex_destroy(&lock);
	printf("Sum of fibonacci series upto %d is %d:",limit,sum);
	return 0;
}
```
19.Write a C program to create a thread that checks if a given year is a leap year using dynamic programming with mutex locks? 
```
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t lock;
void *fun(void *arg)
{
	int year=*(int*)arg;
	pthread_mutex_lock(&lock);
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
	{
		printf("%d is a leap year",year);
	}
	else
	{
		printf("%d is not a leap year",year);
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	int year;
	printf("Enter the year:");
	scanf("%d",&year);
	pthread_mutex_init(&lock,NULL);
	pthread_create(&pt,NULL,fun,&year);
	pthread_join(pt,NULL);
	return 0;
}
```
20.Write a C program to create a thread that checks if a given string is a palindrome using dynamic programming with mutex locks?
```
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
pthread_mutex_t lock;
void *fun(void *arg)
{
	char *str=(char*)arg;
	int len=strlen(str),i=0;
	int ispal= 1;
	if(str[len-1]=='\n')
	{
		str[len-1]='\0';
	}
	pthread_mutex_lock(&lock);
	for(i=0;i<len;i++)
	{
		if(str[i]!=str[--len])
		{
			ispal=0;
			break;
		}
	}
	if(ispal==0)
	{
		printf("The given string is palindrome");
		return NULL;
	}
	else
	{
		printf("The given string is not palindrome");
		return NULL;
	}
	pthread_mutex_unlock(&lock);
}
int main(void)
{
	char str[100];
	pthread_t pt;
	printf("Enter the string:");
	fgets(str,sizeof(str),stdin);
	pthread_create(&pt,NULL,fun,(void*)str);
	pthread_join(pt,NULL);
	return 0;
}
```
21.Implement a C program to create a thread that performs selection sort on an array of integers? 
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int i,j,temp,index,n,arr[100];
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[index])
			{
				index=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[index];
		arr[index]=temp;
	}
	printf("Sorted array:");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
22.Develop a C program to create a thread that calculates the area of a triangle?
```
#include<stdio.h>
#include<pthread.h>
struct triangle
{
	float b;
	float h;
};
void *cal(void *arg)
{
	struct triangle *t = (struct triangle *)arg;
	float area=0.5* t->b *t->h;
	printf("Area of triangle = %.2f\n",area);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	struct triangle t;
	printf("Enter the base of triangle:");
	scanf("%f",&t.b);
	printf("Enter the height of triangle:");
	scanf("%f",&t.h);
	pthread_create(&pt,NULL,cal,&t);
	pthread_join(pt,NULL);
	return 0;
}
```
23.Write a C program to create a thread that calculates the sum of squares of numbers from 1 to 100?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int i;
	long long sum=0;
	for(i=0;i<100;i++)
	{
		sum=sum+(i*i);
	}
	printf("sum=%lld",sum);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
24.Write a C program to create a thread that generates a random array of integers?
```
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void *fun(void *arg)
{
	int a[10],i=0;
	while(i<10)
	{
		a[i]=rand() % 100;
		i++;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
25.Implement a C program to create a thread that performs bubble sort on an array of integers?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int arr[100],n,i=0,temp;
	printf("Enter the number of elemenst in array:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return NULL;

}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
26.Develop a C program to create a thread that calculates the greatest common divisor (GCD) of two numbers?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int a,b,temp;
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	while(b!=0)
	{
		temp=b;
		b=a%b;
		a=temp;
	}
	printf("%d\n",a);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
27.Write a C program to create a thread that calculates the sum of Fibonacci numbers up to a given limit?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int num=*(int*)arg;       
	int c,a=0,b=1,sum=0;
	if(num>=1)
	{
		sum=1;
	}
	while(a <= num)
	{
		sum=sum+c;
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d\n",sum);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	pthread_create(&pt,NULL,fun,&num);
	pthread_join(pt,NULL);
	return 0;
}
```
28.Implement a C program to create a thread that calculates the sum of even numbers from 1 to 100?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void*arg)
{
	int i=0,sum=0;
	for(i=0;i<100;i++)
	{
		if(i%2==0)
		{
			sum=sum+i;
		}
	}
	printf("Sum=%d",sum);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
29.Develop a C program to create a thread that calculates the factorial of a given number using iteration? 
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
	int fact=1;
	int num,i=0;
	printf("Enter the number:");
	scanf("%d",&num);
	if(num<0)
	{
		return NULL;
	}
	for(i=1;i<=num;i++)
	{
		fact=fact*i;
	}
	printf("Factorial=%d",fact);
	return NULL;
}
int main(void)
{
	pthread_t pt;
	pthread_create(&pt,NULL,fun,NULL);
	pthread_join(pt,NULL);
	return 0;
}
```
31.Implement a C program to create a thread that performs multiplication of two matrices?
```
#include<stdio.h>
#include<pthread.h>
#define ROW1 3
#define COL1 4
#define ROW2 4
#define COL2 2
void *fun(void *arg)
{
        int mat1[ROW1][COL1],mat2[ROW2][COL2],mat3[ROW1][COL2],i,j;
        for(i=0;i<ROW1;i++)
        {
                for(j=0;j<COL1;j++)
                {
                        printf("Enter the elements of matrix1:");
                        scanf("%d",&mat1[i][j]);
                }
        }
        for(i=0;i<ROW2;i++)
        {
                for(j=0;j<COL2;j++)
                {
                        printf("Elements of matrix2:");
                        scanf("%d",&mat2[i][j]);
                }
        }
        //Multiplication
        for(i=0;i<ROW1;i++)
        {
                for(j=0;j<COL2;j++)
                {
                        mat3[i][j]=0;
                        for(int k=0;k<ROW2;k++)
                        {
                                mat3[i][j]+=mat1[i][k]*mat2[k][j];
                        }
                }
        }
        printf("The resultant matrix is:");
        for(i=0;i<ROW1;i++)
        {
                for(j=0;j<COL2;j++)
                {
                        printf("%d",mat3[i][j]);
                }
        }
        return NULL;
}
int main(void)
{
        pthread_t pt;
        pthread_create(&pt,NULL,fun,NULL);
        pthread_join(pt,NULL);
        return 0;
}
```
32.Develop a C program to create a thread that calculates the average of numbers from 1 to 100?
```
#include<stdio.h>
#include<pthread.h>
void *fun(void *arg)
{
        int num=100,i=0;
        float sum,avg;
        while(i<=num)
        {
                sum=sum+i;
                i++;
        }
        avg=sum/num;
        printf("Average :%.2f",avg);
        return NULL;
}
int main(void)
{
        pthread_t pt;
        pthread_create(&pt,NULL,fun,NULL);
        pthread_join(pt,NULL);
        return 0;
}
```
33.Implement a C program to create a thread that generates a random string?
```
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define LENGTH 10
void *fun(void *arg)
{
        char *str=malloc(LENGTH+1);
        if(str==NULL)
        {
                printf("Error in memory creation");
                return NULL;
        }
        const char charset[]="abcdefghijklmonpqrstuvwxyz0123456789";
        int charset_size = sizeof(charset)-1;
        srand(time(NULL));
        for(int i=0;i<LENGTH;i++)
        {
                str[i]=charset[rand() % charset_size];
        }
        str[LENGTH]='\0';
        printf("Random string:%s",str);
        free(str);
        return NULL;
}
int main(void)
{
        pthread_t pt;
        pthread_create(&pt,NULL,fun,NULL);
        pthread_join(pt,NULL);
        return 0;
}
```
