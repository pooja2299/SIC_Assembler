#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int getint(char a);
int hex_to_dec(char hexnum)
{
    int tennum=0;

    switch(hexnum)
        {
            case '0':
                tennum=0;
                break;
            case '1':
                tennum=1;
                break;
            case '2':
                tennum=2;
                break;
            case '3':
                tennum=3;
                break;
            case '4':
                tennum=4;
                break;
            case '5':
                tennum=5;
                break;
            case '6':
                tennum=6;
                break;
            case '7':
                tennum=7;
                break;
            case '8':
                tennum=8;
                break;
            case '9':
                tennum=9;
                break;
            case 'A':
                tennum=10;
                break;
            case 'B':
                tennum=11;
                break;
            case 'C':
                tennum=12;
                break;
            case 'D':
                tennum=13;
                break;
            case 'E':
                tennum=14;
                break;
            case 'F':
                tennum=15;
                break;
        }
    

    return tennum;
}
void bitmask()
{
	FILE *p,*q;
	p=fopen("record.txt","r");
	q=fopen("finalobjectcode.txt","w");
	char* line = (char*)malloc(100) ;
	int len=0;
	
	while(fgets(line,100,p)!=NULL)
	{
		
		
		int k=strlen(line);
		if(line[0]=='H')
		{
			fprintf(q,"%s",line);

		}
		else if(line[0]=='T')
		{
			char a1 =line[9];
			char a2=line[10];
			
			int i=(hex_to_dec(a1)*16)+hex_to_dec(a2);
			
			i=i/3;
			
			char s1[4];
			s1[0]='^';
			if(i==1)
			{
				char s11[3]={'8','0','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==2)
			{
				 char s11[3]={'C','0','0'};
				for(int i=0;i<3;i++)
					s1[i+1+1]=s11[i];
			}
			else if(i==3)
			{
				char s11[3]={'E','0','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==4)
			{
				char s11[3]={'F','0','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==5)
			{
				char s11[3]={'F','8','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==6)
			{
				char s11[3]={'F','C','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==7)
			{
				char s11[3]={'F','E','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==8)
			{
				char s11[3]={'F','F','0'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else if(i==9)
			{
				char s11[3]={'F','F','8'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			else
			{
				char s11[3]={'F','F','C'};
				for(int i=0;i<3;i++)
					s1[i+1]=s11[i];
			}
			
		
			for(int j=0,i=0;j<k+4;j++)
			{
				if(j<11)
				{
					
					fprintf(q,"%c",line[j]);
					
				}
                
				else if (j<15 && j>10)
				{
					
					fprintf(q,"%c",s1[i]);
					i++;
				}
                
				else
				{
					
					fprintf(q,"%c",line[j-4]);
					
				}
                
			}
			
		
		}
		else if(line[0]=='E')
		{
			fprintf(q,"%s",line);
		}
			
	}
	
	fclose(q);
	fclose(p);
	//finalobjectcode.txt FILE IS READY!!	


}

int getint(char a)
{
	if(a=='0')
		return 0;
	else if(a=='1')	
		return 1;
	else if(a=='2')
		return 2;
	else if(a=='3')
		return 3;
	else if(a=='4')
		return 4;
	else if(a=='5')
		return 5;
	else if(a=='6')
		return 6;
	else if(a=='7')
		return 7;
	else if(a=='8')
		return 8;
	else if(a=='9')
		return 9;
	else if(a=='a')
		return 10;
	else if(a=='b')
		return 11;
	else if(a=='c')
		return 12;
	else if(a=='d')
		return 13;
	else if(a=='e')
		return 14;
	else if(a=='f')
		return 15;
	else
		return 0;
}