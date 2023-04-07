/*******************************************************************************************************************************************************
 * *FILE NAME : myFunction.c
 * *
 * *DESCRIPTION : This file all the necessary functions for CDR Application
 *
 * *REVISION HISTORY :
 *
 * *DATE                                           NAME                                     REFERENCE                           REASON
 * -----------------------------------------------------------------------------------------------------------------------------------------------------
 *  07 APR 2023                                   GROUP 5                                    new file                           Initial                 
 *  ****************************************************************************************************************************************************
 *  *STANDARD HEADER FILE
 *  ***************************************************************************************************************************************************/
#include<myHeader.h>
/******************************************************************************************************************************************************
 * DELARATION OF FUNCTION POINTER FOR MULTI-THREADING
 * ****************************************************************************************************************************************************/
void *customerDataProcess(void *);
void *operatorDataProcess(void *);
/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME :signUp
 *
 * *DESCRIPTION :This function perform the sign up operation
 *
 * *PARAMETERS : user name , password
 *
 * *RETURNS : 1 on success or 0 on failure
 *
 * *****************************************************************************************************************************************************/
int signUp(char user_name[],char password [])
{
	char exist_user_name[MAX_LINE_LENGTH];
	char exist_password[MAX_LINE_LENGTH];
	FILE *fp;
	int flag=1;

	fp = fopen("./data/user_details.dat","r");
	if(fp == NULL)
	{
		printf("\nSorry,,please Try again\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fscanf(fp,"%s %s\n",exist_user_name,exist_password)==2)
		{
			if(strcmp(user_name,exist_user_name)==0)
			{
				flag=0;
				break;
			}
			else if(strcmp(password,exist_password)==0)
			{
				flag=0;
				break;
			}
		}
	}
	fclose(fp);
	return flag;
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : logIn
 *
 * *DESCRIPTION : This Function helps in log in the user
 *
 * *PARAMETERS : username, password
 *
 * *RETURNS : 1 on success or 0 on failure
 *
 * *****************************************************************************************************************************************************/
int logIn(char user_name[],char password[])
{
	char exist_user_name[MAX_LINE_LENGTH];
	char exist_password[MAX_LINE_LENGTH];
	FILE *fp=NULL;
	fp = fopen("./data/user_details.dat","r");
	if(fp == NULL)
	{
		printf("\nSorry !!! Try again Later\n");
		exit(EXIT_FAILURE);
	}
	int flag=0;

	while(fscanf(fp,"%s %s\n",exist_user_name,exist_password)==2)
		{
			if(strcmp(user_name,exist_user_name)==0)
			{
				if(strcmp(password,exist_password)==0)
				{
					flag=1;
					break;
				}
			}
		}
	fclose(fp);
	return flag;
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : dataProcess
 *
 * *DESCRIPTION : This Function performs the data processing for both customer and inter-operator using Multi-threading
 *
 * *PARAMETERS : array pointer having user data , array pointer having inter-operator data
 *
 * *RETURNS : Nothing
 *
 * *****************************************************************************************************************************************************/
void dataProcess(struct User *CS,IP *IOS)
{

	pthread_t CDthread,IDthread;
	pthread_create(&CDthread,NULL,customerDataProcess,(void *)CS);
	pthread_join(CDthread,NULL);
	pthread_cancel(CDthread);
	pthread_create(&IDthread,NULL,operatorDataProcess,(void *)IOS);
	pthread_join(IDthread,NULL);
	pthread_cancel(IDthread);
	
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : customerDataProcess 
 *
 * *DESCRIPTION : This function process the CDR file for customer billing
 *
 * *PARAMETERS : void pointers for multi_threading
 *
 * *RETURNS : a void pointer use for Multi-threading
 *
 * *****************************************************************************************************************************************************/
void *customerDataProcess(void *cargs)
{
	long int n=0;	
	struct User *CS=(struct User*)cargs;
	FILE *fp;
	fp=fopen("data/data.cdr","r");
	if(fp == NULL)
	{
		return NULL;
	}
	else
	{	
			
		char line[MAX_LINE_LENGTH]={0,};
		int i=0,j=0,token_count = 0;
		char tokens[9][MAX_LINE_LENGTH]={0,};
		
   	 	while (fgets(line,MAX_LINE_LENGTH,fp) != NULL) 
		{	
			for(i=0;line[i]!='\0';i++)
			{
				if(line[i]=='|')
				{
					tokens[token_count][j]='\0';
					token_count++;
					j=0;
					continue;
				}
				tokens[token_count][j]=line[i];
				j++;
			}

			n++;		
        	strcpy(CS[n-1].msisdn, tokens[0]);
      	    strcpy(CS[n-1].opbrandname, tokens[1]);
        	strcpy(CS[n-1].opmmc, tokens[2]);
        	strcpy(CS[n-1].caltype, tokens[3]);
        	strcpy(CS[n-1].dur, tokens[4]);
        	strcpy(CS[n-1].down, tokens[5]);
        	strcpy(CS[n-1].upload, tokens[6]);
        	strcpy(CS[n-1].thirdparmsisdn, tokens[7]);
        	strcpy(CS[n-1].thirdparmmc, tokens[8]);
			token_count=0;
			j=0;
    	}
    fclose(fp);
   }
   return NULL;
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : operatorDataProcess
 *
 * *DESCRIPTION : This function process the data of CDR file for inter-operator billing
 *
 * *PARAMETERS : void pointer for multi-threading
 *
 * *RETURNS : pointer for multithreading
 *
 * *****************************************************************************************************************************************************/
void *operatorDataProcess(void *oargs)
{
	IP *op=(IP*)oargs;
	FILE *fp;
	fp=fopen("data/data.cdr","r");
	if(fp == NULL)
	{
		printf("\nfile error\n");
		return NULL;
	}
	else
	{

		char line[MAX_LINE_LENGTH]={0,};
		int i=0,j=0,token_count = 0;
		long int IN=0;
		char tokens[9][MAX_LINE_LENGTH]={0,};
		struct User *us=(struct User *)malloc(1*(sizeof(struct User)));
		while (fgets(line,MAX_LINE_LENGTH,fp) != NULL)
		{

			us=(struct User *)realloc(us,(IN+1)*sizeof(struct User));
			for(i=0;line[i]!='\0';i++)
			{
				if(line[i]=='|')
				{
					tokens[token_count][j]='\0';
					token_count++;
					j=0;
					continue;
				}
				tokens[token_count][j]=line[i];
				j++;
			}

			IN++;
			strcpy(us[IN-1].msisdn, tokens[0]);
      	   	strcpy(us[IN-1].opbrandname, tokens[1]);
        	strcpy(us[IN-1].opmmc, tokens[2]);
        	strcpy(us[IN-1].caltype, tokens[3]);
        	strcpy(us[IN-1].dur, tokens[4]);
        	strcpy(us[IN-1].down, tokens[5]);
        	strcpy(us[IN-1].upload, tokens[6]);
        	strcpy(us[IN-1].thirdparmsisdn, tokens[7]);
        	strcpy(us[IN-1].thirdparmmc, tokens[8]);

			token_count=0;
			j=0;
    	}

		strcpy(op[0].opmmc,"42500");
		strcpy(op[1].opmmc,"42501");
		strcpy(op[2].opmmc,"42502");
		strcpy(op[3].opmmc,"42503");
		strcpy(op[4].opmmc,"42504");
		int k=0;
		while(k<5)
		{
			bzero(op[k].opname,20);
			op[k].incomingcall=0;
			op[k].outgoingcall=0;
			op[k].incomingsms=0;
			op[k].outgoingsms=0;
			op[k].downloaded=0;
			op[k].uploaded=0;
			k++;
		}
	    char *mtc="MTC", *moc="MOC", *smsin="SMS-MT", *smsout="SMS-MO", *gprs="GPRS";
		k=0;
		while(k<IN)
		{
			if(atol(us[k].opmmc)==atol(op[0].opmmc))
			{
				if(strcmp(us[k].caltype,mtc)==0)
				{
					op[0].incomingcall=op[0].incomingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,moc)==0)
				{
					op[0].outgoingcall=op[0].outgoingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,smsin)==0)
				{
					op[0].incomingsms=op[0].incomingsms+1;
				}
				else if(strcmp(us[k].caltype,smsout)==0)
				{
					op[0].outgoingsms=op[0].outgoingsms+1;
				}
				else if(strcmp(us[k].caltype,gprs)==0)
				{
					op[0].downloaded=op[0].downloaded+atol(us[k].down);
					op[0].uploaded=op[0].uploaded+atol(us[k].upload);
				}
				
				strcpy(op[0].opname,us[k].opbrandname);
				k++;
			}

			else if(atol(us[k].opmmc)==atol(op[1].opmmc))
			{
				if(strcmp(us[k].caltype,mtc)==1)
				{
					op[1].incomingcall=op[1].incomingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,moc)==0)
				{
					op[1].outgoingcall=op[1].outgoingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,smsin)==0)
				{
					op[1].incomingsms=op[1].incomingsms+1;
				}
				else if(strcmp(us[k].caltype,smsout)==0)
				{
					op[1].outgoingsms=op[1].outgoingsms+1;
				}
				else if(strcmp(us[k].caltype,gprs)==0)
				{
					op[1].downloaded=op[1].downloaded+atol(us[k].down);
					op[1].uploaded=op[1].uploaded+atol(us[k].upload);
				}
			
				strcpy(op[1].opname,us[k].opbrandname);
				k++;
			}
			else if(atol(us[k].opmmc)==atol(op[2].opmmc))
			{
				if(strcmp(us[k].caltype,mtc)==0)
				{
					op[2].incomingcall=op[2].incomingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,moc)==0)
				{
					op[2].outgoingcall=op[2].outgoingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,smsin)==0)
				{
					op[2].incomingsms=op[2].incomingsms+1;
				}
				else if(strcmp(us[k].caltype,smsout)==0)
				{
					op[2].outgoingsms=op[2].outgoingsms+1;
				}
				else if(strcmp(us[k].caltype,gprs)==0)
				{
					op[2].downloaded=op[2].downloaded+atol(us[k].down);
					op[2].uploaded=op[2].uploaded+atol(us[k].upload);
				}
				strcpy(op[2].opname,us[k].opbrandname);
				k++;
			}
			else if(atol(us[k].opmmc)==atol(op[3].opmmc))
			{
				if(strcmp(us[k].caltype,mtc)==0)
				{
					op[3].incomingcall=op[3].incomingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,moc)==0)
				{
					op[3].outgoingcall=op[3].outgoingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,smsin)==0)
				{
					op[3].incomingsms=op[3].incomingsms+1;
				}
				else if(strcmp(us[k].caltype,smsout)==0)
				{
					op[3].outgoingsms=op[3].outgoingsms+1;
				}
				else if(strcmp(us[k].caltype,gprs)==0)
				{
					op[3].downloaded=op[3].downloaded+atol(us[k].down);
					op[3].uploaded=op[3].uploaded+atol(us[k].upload);
				}
				strcpy(op[3].opname,us[k].opbrandname);
				k++;
			}
			else if(atol(us[k].opmmc)==atol(op[4].opmmc))
			{
				if(strcmp(us[k].caltype,mtc)==0)
				{
					op[4].incomingcall=op[4].incomingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,moc)==0)
				{
					op[4].outgoingcall=op[4].outgoingcall+atol(us[k].dur);
				}
				else if(strcmp(us[k].caltype,smsin)==0)
				{
					op[4].incomingsms=op[4].incomingsms+1;
				}
				else if(strcmp(us[k].caltype,smsout)==0)
				{
					op[4].outgoingsms=op[4].outgoingsms+1;
				}
				else if(strcmp(us[k].caltype,gprs)==0)
				{
					op[4].downloaded=op[4].downloaded+atol(us[k].down);
					op[4].uploaded=op[4].uploaded+atol(us[k].upload);
				}
				strcpy(op[4].opname,us[k].opbrandname);
				k++;
			}
				
		}
		free(us);
	}
    fclose(fp);
	return NULL;

}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : customerbilling
 *
 * *DESCRIPTION : This function display the requested customer data
 *
 * *PARAMETERS : a pointer having the base address of array of structures contains the cusomer processed data and the MSISDN no for search
 *
 * *RETURNS : a chracter poiner having base address of a character aaray containing output data
 *
 * *****************************************************************************************************************************************************/
char * customerbilling(struct User *us,char msisdnc[])
{
	int k=0,flag=0;
	char * mkg=(char *)malloc(MAXBUFF);
	bzero(mkg,MAXBUFF);
	long int n=100000;
	while(k<n)
	{
		
		if(atoi(msisdnc)==atoi(us[k].msisdn))
		{
			strcpy(mkg,"\n#Customers Data Base:\nCustomer ID: ");
			strcat(mkg,us[k].msisdn);
			strcat(mkg,"(");
			strcat(mkg,us[k].opbrandname);
			strcat(mkg,")");
			if(strcmp(us[k].opmmc,us[k].thirdparmmc)==0)
			{
				strcat(mkg,"\n\t*Services within the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
					
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
				
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			
			else
			{

				strcat(mkg,"\n\t*Services within the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");

				strcat(mkg,"\n\t*Services outside the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
					
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
				
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			flag=1;
		
	
			return mkg;
		}
		k++;
	}
	if(flag==0)
	{	

		strcpy(mkg,"User not found!!");

		return mkg;
	}
	return mkg;
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : customerbillingfile
 *
 * *DESCRIPTION : This function download the requested cusomer data in CB.txt file
 *
 * *PARAMETERS : a pointer having the base address of array of structures contains the cusomer processed data and the MSISDN no for search
 *
 * *RETURNS : a character pointer having the base address of character array containing output data
 *
 * *****************************************************************************************************************************************************/
char * customerbillingfile(struct User *us,char msisdnc[])
{
	int k=0,flag=0;
	long int n=100000;
	char * mkg=(char *)malloc(MAXBUFF);
	bzero(mkg,MAXBUFF);
	FILE *fp=NULL;
	fp=fopen("data/CB.txt","w+");
	if(fp==NULL)
	{
		perror("fopen() ");
	}
	else{
	while(k<n)
	{
		if(atoi(msisdnc)==atoi(us[k].msisdn))
		{
			strcpy(mkg,"\n#Customers Data Base:\nCustomer ID: ");
			strcat(mkg,us[k].msisdn);
			strcat(mkg,"(");
			strcat(mkg,us[k].opbrandname);
			strcat(mkg,")");
			if(strcmp(us[k].opmmc,us[k].thirdparmmc)==0)
			{
				strcat(mkg,"\n\t*Services within the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
					
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
				
				strcat(mkg,"\n\t*Services outside the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			
			else
			{

				strcat(mkg,"\n\t*Services within the mobile operator*");
				strcat(mkg,"\n\tIncoming voice call durations: 0");
				strcat(mkg,"\n\tOutgoing voice call durations: 0");
				strcat(mkg,"\n\tIncoming SMS messages: 0");
				strcat(mkg,"\n\tOutgoing SMS messages: 0");

				strcat(mkg,"\n\t*Services outside the mobile operator*");
				if(strcmp(us[k].caltype,"MOC")==0 || strcmp(us[k].caltype,"MTC")==0)
				{
					if(strcmp(us[k].caltype,"MOC")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: ");
						strcat(mkg,us[k].dur);
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"SMS-MO")==0 || strcmp(us[k].caltype,"SMS-MT")==0)
				{
					
					if(strcmp(us[k].caltype,"SMS-MO")==0)
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 0");
						strcat(mkg,"\n\tOutgoing SMS messages: 1");
					}
					else
					{
						strcat(mkg,"\n\tIncoming voice call durations: 0");
						strcat(mkg,"\n\tOutgoing voice call durations: 0");
						strcat(mkg,"\n\tIncoming SMS messages: 1");
						strcat(mkg,"\n\tOutgoing SMS messages: 0");
					}
				}
				else if(strcmp(us[k].caltype,"GPRS")==0)
				{
					strcat(mkg,"\n\tIncoming voice call durations: 0");
					strcat(mkg,"\n\tOutgoing voice call durations: 0");
					strcat(mkg,"\n\tIncoming SMS messages: 0");
					strcat(mkg,"\n\tOutgoing SMS messages: 0");
				}
				
				strcat(mkg,"\n\t*Internet use*");
				strcat(mkg,"\n\tMB downloaded: ");
				strcat(mkg,us[k].down);
				strcat(mkg,"| MB uploaded:  ");
				strcat(mkg,us[k].upload);
				strcat(mkg,"\n\n");
			}
			flag=1;
			fprintf(fp,"%s",mkg);
			break;
		}
		k++;
	}
	}
	if(flag==0)
	{
		bzero(mkg,MAXBUFF);
		fclose(fp);
	
	
		strcpy(mkg,"failed");
		return mkg;
	}
	else
	{
		bzero(mkg,MAXBUFF);
		fclose(fp);
	

		strcpy(mkg,"success");
		return mkg;
	}

}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : interoperatorbilling
 *
 * *DESCRIPTION : This function print the inter-Operator billing data
 * 
 * *PARAMETERS : a pointer having the base address of array of structures contains the inter-operator processed data and the MMC no for search
 *
 * *RETURNS : a character pointer having the base address of a character array containg the output data
 *
 * *****************************************************************************************************************************************************/
char * interoperatorbilling(IP *IOS,char mmc[])
{
	int k=0;
	int flag=0;
	char * mkg=(char *)malloc(MAXBUFF);
	bzero(mkg,MAXBUFF);
	while(k<5)
	{
		if(atol(IOS[k].opmmc)==atol(mmc))
		{
			char dum[MAXBUFF]={0,};
			strcpy(mkg,"\n\nInter operator billing!\n");
			strcat(mkg,"==============================\n");
			strcat(mkg,"\n\nOperator Brand : ");
			strcat(mkg,IOS[k].opname);
			strcat(mkg," (");
			strcat(mkg,mmc);
			strcat(mkg,")");
			strcat(mkg,"\nIncoming voice call duration: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].incomingcall);
			strcat(mkg,dum);
			strcat(mkg,"\nOutgoing voice call duration: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].outgoingcall);
			strcat(mkg,dum);
			strcat(mkg,"\nIncoming SMS messages: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].incomingsms);
			strcat(mkg,dum);
			strcat(mkg,"\nOutgoing SMS messages: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].outgoingsms);
			strcat(mkg,dum);
			strcat(mkg,"\nMB downloaded: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].downloaded);
			strcat(mkg,dum);
			strcat(mkg," | MB uploaded: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",IOS[k].uploaded);
			strcat(mkg,dum);
			strcat(mkg,"\n\n");
		
			flag=1;
			break;
		}
		k++;
	}
	if(flag==1)
	{
			return mkg;
	}
	else
	{	
		strcpy(mkg,"Operator not found!!");
	
		return mkg;
	}
	return mkg;
}

/*******************************************************************************************************************************************************
 *
 * *FUNCTION NAME : interoperatorbillingfile
 *
 * *DESCRIPTION : this function download the processed operator data in IOSB.txt file
 *
 * *PARAMETERS : a pointer having the base address of array of structures contains the inter-Operator processed data and the MMC no for search
 *
 * *RETURNS : a character pointer having the base address of a character array containing the output 
 *
 * *****************************************************************************************************************************************************/
char * interoperatorbillingfile(IP *op)
{
	FILE *fp=NULL;
	fp=fopen("data/IOSB.txt","w+");
    char * mkg=(char *)malloc(2048);
	bzero(mkg,2048);
	int flag=0;
	if(fp==NULL)
	{
		perror("fopen()");
	}
	else
	{
		int z=0;
		strcpy(mkg,"\n\nInter operator billing!\n");
		strcat(mkg,"==============================\n");
		while(z<5)
		{
			char dum[MAXBUFF]={0,};
			strcat(mkg,"\n\nOperator Brand : ");
			strcat(mkg,op[z].opname);
			strcat(mkg," (");
			strcat(mkg,op[z].opmmc);
			strcat(mkg,")");
			strcat(mkg,"\nIncoming voice call duration: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].incomingcall);
			strcat(mkg,dum);
			strcat(mkg,"\nOutgoing voice call duration: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].outgoingcall);
			strcat(mkg,dum);
			strcat(mkg,"\nIncoming SMS messages: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].incomingsms);
			strcat(mkg,dum);
			strcat(mkg,"\nOutgoing SMS messages: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].outgoingsms);
			strcat(mkg,dum);
			strcat(mkg,"\nMB downloaded: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].downloaded);
			strcat(mkg,dum);
			strcat(mkg," | MB uploaded: ");
			bzero(dum,MAXBUFF);
			sprintf(dum,"%ld",op[z].uploaded);
			strcat(mkg,dum);
			strcat(mkg,"\n\n");
			z++;
			flag=1;
		}
	}
	if(flag==1)
	{
		fprintf(fp,"%s",mkg);
		bzero(mkg,MAXBUFF);
		strcpy(mkg,"yes");
	
		fclose(fp);
		return mkg;
	}
	else
	{
		fclose(fp);

		bzero(mkg,MAXBUFF);
		strcpy(mkg,"no");
		return mkg;
	}

	return mkg;	

}

