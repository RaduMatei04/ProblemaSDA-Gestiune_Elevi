#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elev{
  
  char nume[20];
  char cod[20];
  int note[9];
    
};

void afisare(int nrelevi,struct elev *elevi){
    for(int i=0;i<nrelevi;i++){
        printf("%s\n",elevi[i].nume);
        printf("%s\n",elevi[i].cod);
        for(int j=0;j<9;j++)
        printf("%d ",elevi[i].note[j]);
        
        printf("\n");
}
}

float medienote(int note[9]){
    int sum=0;
    for(int j=0;j<9;j++) sum+=note[j];
    
    return sum/9.00;
}

void mediemare(int nrelevi,struct elev *elevi){
    float max=0.00; int k;
    for(int i=0;i<nrelevi;i++){
        if(medienote(elevi[i].note)>max)  {
            max=medienote(elevi[i].note);
            k=i;
        }
    }
    
    printf("%s\n",elevi[k].nume);
}

void test3(int nrelevi,struct elev *elevi){
    
     for(int i=0;i<nrelevi;i++){
         
         if(medienote(elevi[i].note)<6){
             printf("%s\n",elevi[i].nume);
         }
     }
}

void sortare(int note[9]){
    
    int t;
    for(int i=0;i<8;i++)
    for(int j=i+1;j<9;j++)
    if(note[i]>note[j]){
        t=note[i];
        note[i]=note[j];
        note[j]=t;
    }
}

void test4(int nrelevi,struct elev *elevi,char codtemp[20]){
    int k;
    for(int i=0;i<nrelevi;i++){
        
        if(strcmp(elevi[i].cod,codtemp)==0){
            sortare(elevi[i].note);
            k=i;
        }
         }
         
         printf("%d\n",elevi[k].note[4]);
}

int main(){
    
    int nrelevi;  scanf("%d",&nrelevi);
    
    struct elev *elevi=malloc(nrelevi*sizeof(struct elev));
    
    for(int i=0;i<nrelevi;i++){
        scanf("%s",&elevi[i].nume);
        scanf("%s",&elevi[i].cod);
        for(int j=0;j<9;j++)
        scanf("%d",&elevi[i].note[j]);
    }
    
    int comanda;
    scanf("%d",&comanda);
    
    if(comanda==1){
        afisare(nrelevi,elevi);
    }
    
    if(comanda==2){
        mediemare(nrelevi,elevi);
    }
    
    if(comanda==3){
        test3(nrelevi,elevi);
    }
    
    if(comanda==4){
        
        char codtemp[20];
        scanf("%s",codtemp);
        test4(nrelevi,elevi,codtemp);
    }
    
    return 0;
}
