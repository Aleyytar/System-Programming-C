#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *prices, int pricesSize, int *buyDays, int *sellDays) {
    int dif=0, 
    buy1 =-1, sell1 =-1, 
    buy2 =-1, sell2 =-1, 
    profitMax=0, 
    profit1=0,   
    profit2 =0,  
    trade1=0, trade2=0; 
   
    int line;
    for (  line = 1; line < pricesSize; line++) 
    {   
	    int i;
	    int j;
        for ( i = 0; i <line; i++)                 // Ýlk alýmsatým bölgesi döngüsü
            for ( j = i+1; j <= line; j++)         // Ýlk bölge için maksimum karý bulur(profit1)
            {
                dif=prices[j]-prices[i] ;             // mevcut ticaretin profiti

                if (dif>=profit1 && dif!=0 ){         // Eðer profit >= profit2 trade2 (buy2, sell2...)
                    buy1   = i;
                    sell1  = j;
                    profit1= dif;
                    trade1 = 1;
                }               
            }
        
        for ( i = line+1; i < pricesSize; i++)  // Ýkinci alým satým bölgesi döngüsü
            for ( j = i+1; j < pricesSize; j++)   // Ýkinci bölge için max kar bulur (profit2)
            {
                dif=prices[j]-prices[i] ;            //  mevcut ticaretin profiti

                if (dif>=profit2 && dif!=0 ){        // EÐER profit >= profit2,  trade2 (buy2, sell2...)
                    buy2   = i;
                    sell2  = j;
                    profit2= dif;
                    trade2 = 1;
                }                
            }


        if((profit1+profit2) >=profitMax  && ((trade1 + trade2)==2)){ // // toplam  profit>=profitMax, Dizileri ve kârMax'ý ayarla
            buyDays[0]  = buy1 ;
            buyDays[1]  = buy2 ;
            sellDays[0] = sell1 ;
            sellDays[1] = sell2 ;
            profitMax   = profit1+profit2 ; 
        }  

        else if(profit1>=profitMax && trade1==1){   //profit1>=profitMax  Dizileri ve kârMax'ý ayarla
            buyDays[0]  = buy1 ;
            buyDays[1]  = -1;
            sellDays[0] = sell1 ;
            sellDays[1] = -1;
            profitMax   = profit1; 
        }  

        else if(profit2>=profitMax && trade2==1){   //  profit2>=profitMax Trade2 bittiyse  , Dizileri ve kârMax'ý ayarla
            buyDays[0]  = buy2 ;
            buyDays[1]  = -1;
            sellDays[0] = sell2 ;
            sellDays[1] = -1;
            profitMax   = profit2 ; 
        }
        
        trade1=trade2=profit1=profit2=0;  
    }

    return profitMax;
}


int main() {
    int prices[] = {3,3,5,0,0,3,1,4};
    int buyDays[2] ={-1,-1};
    int selsDays[2]={-1,-1};;
    int size=sizeof(prices)/sizeof(int);
    int profit=maxProfit(prices,size,buyDays,selsDays);
    printf("%d\n",profit);
   
    
    }




