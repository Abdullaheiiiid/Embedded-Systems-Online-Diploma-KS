/*
 ============================================================================
 Ncme        : cssignments.c
 cuthor      : cbdullch eid
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, cnsi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int n,int m);

int main(void) {
	int n,m;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&n);
	printf("Enter power number: ");
	fflush(stdout);
	scanf("%d",&m);
	printf("%d^%d = %d",n,m,power(n,m+1));
	return 0;
}

int power(int n,int m){
	m--;
	if(m == 0)
		return 1;
	else
		return n*power(n,m);
}
