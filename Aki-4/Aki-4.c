#include <stdio.h>
#include <stdlib.h>

#define BRUREDU  10
#define ENTER    13
#define ESC      27

enum bool {false,true};


int main()
{
    int xu,yu,i,j,br,brmax,brr=0,ip,ik;
    long a=1,b,max=0;
    enum bool kon=false;
    unsigned pod=0;

    printf("\nUnosite brojeve sve dok se ne unese broj nula!!\n");

    i=1;
    brr=0;

    while (a)
    {
        printf("\n%ld : ",i); 
        scanf("%ld ",&a);

        if(i>1&&a>b){
            if(kon==false){
                brr++, br=2, ip=i-1, ik=i;
                kon=true;
            }else{
                br++;
                ik++;
            }
        }else{
            if(kon==true){
                if(br>max) max=br,pod=ip;
                    else if(br==max) pod=(ip<<7*(brr-1)) | pod;
            }
            kon=false;
        }

        b=a;
        i++;
    }

    printf("\n\nBroj rastucih intervala = %d",brr);
     if(brr>0){

        printf("\nNajveci rastuci interval ima clanova = %d",max);
        printf("\nNajveci rastuci intervali su na intervalima:\n");
        while(pod){
            ip=pod&0x7f;
            ik=ip+max-1;
            printf("[%d..%d]U",ip,ik);
            pod>>=0x7;
        }
        printf("\b \n");
    }

     return 0;
        
    }
