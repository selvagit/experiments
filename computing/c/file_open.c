#include <stdio.h>
#include <strings.h>


int main ( void )
{

    FILE *fp = NULL;

    /* to test when a file containing some 
     * text is opened and closed immediately */
    fp = fopen("Test.txt", "w");
    fclose(fp);

    /* to test removal of the file */
    remove("Test1.txt");

    remove("Test2.txt");

    return 0;
} 



/* sets to test 
 *
 * echo "test" > ./Test.txt
 * cp ./Test.txt ./Test1.txt
 *
 * gcc -Wall ./file_open.c -o ./test
 *
 */

