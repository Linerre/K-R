/* 
 * Print length of arbitrary long line 
 * based on the longest line program on page 29 
 */

#include <stdio.h>
#define MAXLINE 50    /* maximum input line size */ 

int getline(char line[], int maxline); 
/* void copy(char to[], char from[]); */

/* print longest input line */
int main()
{
    int len;	    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];	   /* current input line  */ 
    char longest[MAXLINE];  /* longest line saved here  */ 

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
	if (len > max) {
	    max = len;
/* 	    copy(longest, line); */
	}
    if (max > 0)   /* there was a line  */ 
	printf("%s", longest);
    return 0;
}

/* getline: read a line of arbitrary length into s, 
 * print its length even it exceeds the size of s 
 */
int getline(char s[], int lim)
{
    int c, i, j, k;

   /* keep couting characters and storing them in s 
    * when the line is shorter s  
    */ 
    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;

   /* keep counting when line is longer than s  */ 
    for (j = i; (c=getchar()) != EOF && c != '\n'; ++j);
    if (c == '\n') {
/* 	s[i] = c; */
/* 	++i; */
	++j;
    }
/*     s[i] = '\0'; */
    
    /* print length  */
    printf("The length of the line is %d characters\n", j);
    /* print as much as possible the line  */ 
    printf("The line can only be printed onto screen this much: \n");
    for (k = 0; k < lim - 1; ++k)
	printf("%s", s[k]);
    return 0;
}

/* copy: copy 'from' to 'to'; assume to is big enough  */
/* void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
	++i;
} */
