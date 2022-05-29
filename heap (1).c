#include <stdio.h>
int array[100], n;
main()
{
int choice, num;
n = 0;/*Represents number of nodes in the heap*/
while(1)
    {
        printf("1.Insert the element \n");
        printf("2.Display all elements \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
switch(choice)
{
        case 1:
        printf("Enter the element to be inserted to the list : ");
        scanf("%d", &num);
        insert(num, n);
        n = n + 1;
        break;


        case 2:
        display();
        break;


        case 3:
        exit(0);

        default:
        printf("Invalid choice \n");

            }/*End  of switch */

        }/*End of while */

}/*End of main()*/


display()
{
            int i;
            if (n == 0)
            {
            printf("Heap is empty \n");
            return;
            }
            for (i = 0; i < n; i++)
            printf("%d ", array[i]);
            printf("\n");

}/*End of display()*/


insert(int num, int location)
{
int parentnode;

            while (location > 0)
            {
                parentnode =(location - 1)/2;

                if (num <= array[parentnode])
                    {
                    array[location] = num;
                    return;
                    }
                else{
                    array[location] = array[parentnode];
                    location = parentnode;
                }
            }/*End of while*/
                    array[0] = num; /*assign number to the root node */

}/*End of insert()*/


