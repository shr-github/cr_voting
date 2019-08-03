#include <stdio.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char un[20], pw[20];
int ch,n,i,sec,y;

void input();
void teacher_login();
void student_login();
void student();
void teacher();
void compare1();
void compare2();
void result();

struct student{
    int rollno; 
	float cgpa;
    char name[20];
}S1[10],S2[10] ;


void teacher_login(){
	input();
	compare1();
}

void student_login(){
	input();
	compare2();
}

void input(){
	printf("\nUsername: ");
	scanf("%s",&un);
	printf("\nPassword: ");
	scanf("%s",&pw);
	printf("\nYear: ");
	scanf("%d", &y);
	printf("\nSection: ");
	scanf("%d", &sec);
}

void compare2(){
		if(strcmp(un,"sshr")==0 && strcmp(pw,"pws")==0 || strcmp(un,"sath")==0 && strcmp(pw,"pass")==0){
			//clrscr();printf("\n*************CR Voting System.******************\n");
			printf("\n                Welcome to CR voting system\n");
			printf("\n                     Student login\n");
			printf("\nBranch: CSE		Year: %d		Section: %d",y,sec);
			student();
		}
		else{
			//clrscr();
        	printf("\n Invalid username or password. Please try again.\n");
	        input();
	        compare2();
		}
}

void compare1(){
	if(strcmp(un,"taru")==0 && strcmp(pw,"psw")==0 || strcmp(un,"tnik")==0 && strcmp(pw,"paas")==0){
			//clescr();printf("\n*********CR Voting System.***************\n");
			printf("\n                Welcome to CR voting system\n");
			printf("\n                     Teacher login\n");
			printf("\nBranch: CSE		Year: %d		Section: %d",y,sec);
			teacher();
		}
		else{
			//clrscr();
        	printf("\n Invalid username or password. Please try again.\n");
	        input();
	        compare1();
		}
}

void teacher(){
	printf("\nEnter the no of candidates: ");
	scanf("%d", &n);
	if(sec==1){
		FILE*fp;
		fp =fopen("Candidates", "a");
		printf("\nBoy Candidates:");
    	for(i=0;i<n;i++){
        	printf("\n\nEnter the Roll no of Candidate: ");
        	scanf("%d", &S1[i].rollno);
        	printf("Enter the Name of Candidate: ");
        	scanf("%s",&S1[i].name);
        	printf("Enter the cgpa of Candidate:");
        	scanf("%f", &S1[i].cgpa);
    	}
    
    	printf("\nGirl Candidates:");
    	for(i=0;i<n;i++){
        	printf("\n\nEnter the Roll no of Candidate: ");
        	scanf("%d", &S2[i].rollno);
        	printf("Enter the Name of Candidate: ");
        	scanf("%s",&S2[i].name);
        	printf("Enter the cgpa of Candidate:");
        	scanf("%f", &S2[i].cgpa);
    	}
    
		fwrite(&S1,sizeof(S1),1,fp);
		fwrite(&S2,sizeof(S2),1,fp);
		fclose(fp);
		printf("\nEnter 1 to display the list of candidates.\nEnter 0 to exit.\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				student();
				break;
			case 0:
				exit(0);
		}
	}
	
	else if (sec==2){
		FILE*fp1;
		fp1 =fopen("Candidates", "a");
		printf("\nBoy Candidates:");
    	for(i=0;i<n;i++){
        	printf("\n\nEnter the Roll no of Candidate: ");
        	scanf("%d", &S1[i].rollno);
        	printf("Enter the Name of Candidate: ");
        	scanf("%s",&S1[i].name);
        	printf("Enter the cgpa of Candidate:");
        	scanf("%f", &S1[i].cgpa);
    	}
    
    	printf("\nGirl Candidates:");
    	for(i=0;i<n;i++){
        	printf("\n\nEnter the Roll no of Candidate: ");
        	scanf("%d", &S2[i].rollno);
        	printf("Enter the Name of Candidate: ");
        	scanf("%s",&S2[i].name);
        	printf("Enter the cgpa of Candidate:");
        	scanf("%f", &S2[i].cgpa);
    	}
    
		fwrite(&S1,sizeof(S1),1,fp1);
		fwrite(&S2,sizeof(S2),1,fp1);
		fclose(fp1);
		printf("\nEnter 1 to display the list of candidates.\nEnter 0 to exit.\nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				student();
				break;
			case 0:
				exit(0);
		}

	}
	else{
		printf("Invalid section!");
	}
}

void student(){
	if(sec==1){
		FILE*fptr;
		fptr=fopen("Candidates","r");
		while(fread(&S1,sizeof(S1),1,fptr)){
    		printf("\nThe roll no of Candidate =%d",S1[i].rollno);
    		printf("\nThe name of Candidate =%s",S1[i].name);
    		printf("\nThe cgpa of Candidate =%f",S1[i].cgpa);
		}
		while(fread(&S2,sizeof(S2),1,fptr)){
    		printf("\nThe roll no of Candidate =%d",S2[i].rollno);
    		printf("\nThe name of Candidate =%s",S2[i].name);
    		printf("\nThe cgpa of Candidate =%f",S2[i].cgpa);
		}
		fclose(fptr);
	}
	else if(sec==2){
		FILE*fptr1;
		fptr1=fopen("Candidates","r");
		while(fread(&S1,sizeof(S1),1,fptr1)){
    		printf("\nThe roll no of Candidate =%d",S1[i].rollno);
    		printf("\nThe name of Candidate =%s",S1[i].name);
    		printf("\nThe cgpa of Candidate =%f",S1[i].cgpa);
		}
		while(fread(&S2,sizeof(S2),1,fptr1)){
    		printf("\nThe roll no of Candidate =%d",S2[i].rollno);
    		printf("\nThe name of Candidate =%s",S2[i].name);
    		printf("\nThe cgpa of Candidate =%f",S2[i].cgpa);
		}
		fclose(fptr1);
	}
	else{
		printf("Data not available!");
	}
}



void result(){
	//clescr();printf("\n*****************************CR Voting System.*****************************************\n");
	printf("\nStill counting the number of votes...\n");
}

void main()
{
	printf("\n***********************************CR Voting System.****************************************\n");
	printf("\nEnter 1 for teacher login \nEnter 2 for student login \nEnter 3 to View result.\nEnter your choice: ");
	scanf("%d", &ch);
	switch(ch){
		case 1: teacher_login();
		        break;
		
		case 2: student_login();
		        break;
		        
		case 3: result();
		        break;
		        
		default: printf("\n Invalid choice!");
		    
	}
}
