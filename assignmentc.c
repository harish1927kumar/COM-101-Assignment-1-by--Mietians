#include<stdio.h>/*header file related to input and output
                  fuctions*/
#include<stdlib.h>/*header file which contain information for
                  memory allocation and freeing space*/
#include<netdb.h>/* header file used for networked accessed
                  used for hostent structure*/
#include<time.h>/* header file that contain information about
                  time and date manipulation and formatting*/
int main(int argc,char const*argv[])
 // main function that is function main logic begins from here
{
	//declaration of variables
	char*hostname;
    /* declaration of structure is done with the help of struct 
    keyword*/
	struct hostent*hostinfo;
	time_t t =time(NULL);
	struct tm tm= *localtime(&t);
	FILE*fptr;// it is an pointeer to a function

    /*Hostinfo to check the connectivity,using google because their up
	  time is 99.998%*/
	hostname="google.com";
	hostinfo=gethostbyname(hostname);
	
	//checking the connection and writing log accordingly
	if(hostinfo==NULL)
	{
		(fptr=fopen("file.txt","a"));
		/* fopen is used to open a  desired file and write in it */
		/* some  pc's are compaitable with file.log if not then use
		   file.txt */
		if(fptr==NULL)
		{
			printf("\n Couldn't fetch log file.");
		}
		else
		{
			fprintf(fptr,"Internet unavialable at: %d-%d-%d %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec );
		    // fprintf stand for print formatted i.e main C output functions
		    /*%d-%d-%d %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec 
		      is the format to get day,date ,time etc*/
		    fclose(fptr);
		}
	}
    else
     {
     (fptr=fopen("file.txt","a"));
	 if(fptr==NULL)
		{
			printf("\n Couldn't fetch log file.");
		}
		else
		{
			fprintf(fptr,"Internet Avialable at: %d-%d-%d %d:%d:%d\n",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec );
		    fclose(fptr);
		    /* fclose is used to close the file opened and to stop
		      writing log in it*/
		}
     }
return 0;
/* return  should return an integer value and considered as exit
   status of the program or logic or conditions inside main function*/
}
	 

