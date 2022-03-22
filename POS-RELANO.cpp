#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
using namespace std;

double itemprice(int itemcode);

int main(){

  double order[10][4],cash,change;
  string name = " ";
  int i=0,item,transaction=1,tot=0,supertot=0;
  int quan1=0,price1=0,totalprice1=0,quan2=0,price2=0,totalprice2=0,quan3=0,price3=0,totalprice3=0,quan4=0,price4=0,totalprice4=0,quan5=0,price5=0,totalprice5=0,quan6=0,price6=0,totalprice6=0,quan7=0,price7=0,totalprice7=0,quan8=0,price8=0,totalprice8=0,quan9=0,price9=0,totalprice9=0,quan10=0,price10=0,totalprice10=0;
  char check,check2,check3; 
  char date[100];
  char time[10];
  restart:

  tot=0;
  cout << "Welcome to PLM Canteen!" << endl;
  cout << "\n\n***************** MENU ****************** \n\n";
  cout << "1-	Java Rice\t\t25 pesos\n2-	Java Rice w/ Egg\t35 pesos\n3-	Java Rice w/ Hotdog\t35 pesos\n4-	Java Rice w/ Porkchop\t45 pesos\n5-	Java Rice w/ Adobo\t45 pesos\n";
  cout << "6-	Fish Fillet w/ Rice\t50 pesos\n7-	Sisig w/ Rice\t\t50 pesos\n8-	Shawarma Rice\t\t55 pesos\n9-	Siomai Rice\t\t55 pesos\n10-	Pancit\t\t\t60 pesos\n" << endl;
  cout << "***************************************** \n\n";
  cout << "Enter the date: ";
  cin >> date;
  cout << "Enter the time: ";
  cin >> time;
  i=0;
  do {
 	again:
 		
 		tot = 0;
    cout << "\n\nItem code: ";
    cin >> order[i][0];
    item = order[i][0];
	switch(item){
    	case 1: cout << "	Java Rice\n";
    		break;
    	case 2: cout << "	Java Rice w/ Egg\n";
    		break;
    	case 3: cout << "	Java Rice w/ Hotdog\n";
    		break;
    	case 4: cout << "	Java Rice w/ Porkchop\n";
    		break;
    	case 5: cout << "	Java Rice w/ Adobo\n";
    		break;
    	case 6: cout << "	Fish Fillet w/ Rice\n";
    		break;
    	case 7: cout << "	Sisig w/ Rice\n";
    		break;
    	case 8: cout << "	Shawarma Rice\n";
    		break;
    	case 9: cout << "	Siomai Rice\n";
    		break;
    	case 10: cout << "	Pancit\n";
    		break;
    	default: cout << "Invalid item code\n";
    		break;
    }
    if(item > 10 || item < 1){
    	goto again;
    }
    cout << "Quantity : ";
    cin >> order[i][1];
    
    order[i][2] = itemprice(order[i][0]); 
    order[i][3] = order[i][1] * order[i][2]; 
    
    cout << "Is there anything else you would like to order (y/n) ? ";
    cin >> check;
  
    i++;
  } while(check == 'y');
  ofstream outfile;
  ofstream outfile2;
  ofstream outfile3;
  remove("Inventory.txt");
  outfile.open("Owner Receipt.txt",ofstream :: app);
  outfile2.open("Costumer Receipt.txt",ofstream :: app);
  outfile3.open("Inventory.txt",ofstream :: app);
  if(outfile.is_open()){
  
  
  outfile << "\n---------------------------------------------------------\n\n";
  outfile << "\t\t\t   PLM Canteen\n\t\t      Official Receipt\n\n\n";
  outfile << "Date : " << date << "\n";
  outfile << "Time : " << time << "\n";
  outfile << "Transaction number: " << transaction << "\n\n";
  outfile << "Item Code\tQuantity\tItem Price\tTotal Price\n\n";
  
  outfile2 << "\n---------------------------------------------------------\n\n";
  outfile2 << "\t\t\t   PLM Canteen\n\t\t      Official Receipt\n\n\n";
  outfile2 << "Date : " << date << "\n";
  outfile2 << "Time : " << time << "\n";
  outfile2 << "Transaction number: " << transaction << "\n\n";
  
  outfile2 << "Item Code\tQuantity\tItem Price\tTotal Price\n\n";
  tot = 0;
  for(int k=0; k<i; k++){   
		for(int l=0; l<4; l++){ 
			if (l==0 || l==1){
				outfile << order [k][l] << "\t\t";
				outfile2 << order [k][l] << "\t\t";
			}
			if (l==1 && order [k][0] == 1){
				quan1 = quan1 + order [k][l];
			}
			if (l==1 && order [k][0] == 2){
				quan2 = quan2 + order [k][l];
			}
				
			if (l==1 && order [k][0] == 3){
				quan3 = quan3 + order [k][l];
			}
		
			if (l==1 && order [k][0] == 4){
				quan4 = quan4 + order [k][l];
			}
		
			if (l==1 && order [k][0] == 5){
				quan5 = quan5 + order [k][l];
			}
			
			if (l==1 && order [k][0] == 6){
				quan6 = quan6 + order [k][l];
			}
			
			if (l==1 && order [k][0] == 7){
				quan7 = quan7 + order [k][l];
			}
			
			if (l==1 && order [k][0] == 8){
				quan8 = quan8 + order [k][l];
			} 
			if (l==1 && order [k][0] == 9){
				quan9 = quan9 + order [k][l];
			}
				
			if (l==1 && order [k][0] == 10){
				quan10 = quan10 + order [k][l];
			} 
			if (l==2 || l==3){
				outfile << order [k][l] << " pesos\t";
				outfile2 << order [k][l] << " pesos\t";	
    		}
    	if (l==3){
    	item = order[k][0];
		switch(item){
					
    	case 1: 
		{
		outfile << "\nJava Rice\n";
		outfile2 << "\nJava Rice\n";
		}
    		break;
    	case 2: {
		outfile << "\nJava Rice w/ Egg\n";
		outfile2 << "\nJava Rice w/ Egg\n";
		}
    		break;
    	case 3: 
    	{
		
		outfile << "\nJava Rice w/ Hotdog\n";
		outfile2 << "\nJava Rice w/ Hotdog\n";
		}
    		break;
    	case 4: 
    	{
		
		outfile << "\nJava Rice w/ Porkchop\n";
		outfile2 << "\nJava Rice w/ Porkchop\n";
		}
    		break;
    	case 5: 
    	{
		
		outfile << "\nJava Rice w/ Adobo\n";
		outfile2 << "\nJava Rice w/ Adobo\n";
		}
 	   		break;
    	case 6: 
    	{
		
		outfile<< "\nFish Fillet w/ Rice\n";
		outfile2<< "\nFish Fillet w/ Rice\n";
		}
    		break;
    	case 7: 
    	{
		
		outfile << "\nSisig w/ Rice\n";
		outfile2 << "\nSisig w/ Rice\n";
		}
    		break;
    	case 8: 
    	{
		
		outfile << "\nShawarma Rice\n";
		outfile2 << "\nShawarma Rice\n";
		}
    		break;
    	case 9: 
    	{
		
		outfile << "\nSiomai Rice\n";
		outfile2 << "\nSiomai Rice\n";
		}
    		break;
    	case 10: 
    	{
		
		outfile << "\nPancit\n";
		outfile2 << "\nPancit\n";
		}
    		break;
    
    	default: cout << "Invalid item code\n";
    		break;
    	
		}
		item = 0;
		}
				   
		}
		outfile << endl;
		outfile2 << endl;
		tot = tot + order[k][3];
	}
  system("pause");
  system("cls");
  cout << "Item Code\tQuantity\tItem Price\tTotal Price\n\n";
  for(int k=0; k<i; k++){   
		for(int l=0; l<4; l++){ 
			if (l==0 || l==1){
				cout << order [k][l] << "\t\t";
			}	
			if (l==2 || l==3){
				cout << order [k][l] << " pesos\t";	
    		}
    	if (l==3){
    	item = order[k][0];
		switch(item){
					
    	case 1: cout << "\nJava Rice\n";
    		break;
    	case 2: cout << "\nJava Rice w/ Egg\n";
    		break;
    	case 3: cout << "\nJava Rice w/ Hotdog\n";
    		break;
    	case 4: cout << "\nJava Rice w/ Porkchop\n";
    		break;
    	case 5: cout << "\nJava Rice w/ Adobo\n";
    		break;
    	case 6: cout << "\nFish Fillet w/ Rice\n";
    		break;
    	case 7: cout << "\nSisig w/ Rice\n";
    		break;
    	case 8: cout << "\nShawarma Rice\n";
    		break;
    	case 9: cout << "\nSiomai Rice\n";
    		break;
    	case 10: cout << "\nPancit\n";
    		break;
    	default: cout << "Invalid item code\n";
    		break;
		}
		item = 0;
		}
				   
		}
		cout << endl;
		
	}
  outfile << "\n\nTotal: " << tot << " pesos";
  outfile2 << "\n\nTotal: " << tot << " pesos";
  cout << "\n\nTotal: " << tot << " pesos" << endl;
  cout << "Is the order correct (y/n) ? ";
  cin >> check2;
 

  if (check2 == 'n'){
    VOID:
  	system("cls");
  	cout << "\nThe transaction will be voided" << endl;
  	cout << "Enter the name of the one who will void the transaction: ";
  	cin.ignore();
    getline(cin,name);
    outfile << "\n(VOIDED TRANSACTION)" << endl;
    outfile2 << "\n(VOIDED TRANSACTION)" << endl;
    transaction++;
  	outfile << "\n\nVoided by: " << name << "\n" << "Date: " << date << endl;
  	outfile2 << "\n\nVoided by: " << name << "\n" << "Date: " << date << endl;
  	system("pause");
	system("cls");
  	goto restart;
  }
  cout << "Cash: ";
  cash:
  cin >> cash;
  change = cash - tot;
  if (cash < tot){
  	cout << "You don't have enough money, void transaction (y/n) ?";
  	cin >> check3;
  		if (check3 == 'y'){
  			goto VOID;
  		}
  		else if (check3 == 'n'){
  			cout << "Enter cash again: ";
  			goto cash;
  		}
  }
  outfile << "\nCash: " << fixed << setprecision(2) << cash << " pesos" << endl;
  outfile << "Change: " << fixed << setprecision(2) << change << " pesos" << endl;
  outfile << "\n\n---------------------------------------------------------\n\n\n";
  outfile2 << "\nCash: " << fixed << setprecision(2) << cash << " pesos" << endl;
  outfile2 << "Change: " << fixed << setprecision(2) << change << " pesos" << endl;
  outfile2 << "\n\n---------------------------------------------------------\n\n\n";
  system("pause");
  system("cls");
  transaction++;
  
  outfile.close();
  outfile2.close();
  if(outfile3.is_open()){
  	
  	supertot = supertot + tot;
  	
  	outfile3 << "ITEM CODE\tITEM NAME\tQUANTITY\tPRICE\tTOTAL PRICE\n";

  
  	for(int k=0; k<i; k++){   
		for(int l=0; l<4; l++){
		
			if (l==0){
				outfile3 << order [k][l] << "\t";
				item = order[k][0];
				switch(item){
					
    			case 1: 
				{
				outfile3 << "Java Rice\t";

				}
		    		break;
		    	case 2: {
				outfile3 << "Java Rice w/ Egg\t";
			
				}
		    		break;
		    	case 3: 
		    	{
				
				outfile3 << "Java Rice w/ Hotdog\t";
		
				}
		    		break;
		    	case 4: 
		    	{
				
				outfile3 << "Java Rice w/ Porkchop\t";
		
				}
		    		break;
		    	case 5: 
		    	{
				
				outfile3 << "Java Rice w/ Adobo\t";
			
				}
		  	  		break;
		    	case 6: 
		    	{
				
				outfile3<< "Fish Fillet w/ Rice\t";
		
				}
		    		break;
		    	case 7: 
		    	{
				
				outfile3 << "Sisig w/ Rice\t";
		
				}
		    		break;
		    	case 8: 
		    	{
				
				outfile3 << "Shawarma Rice\t";
		
				}
		    		break;
		    	case 9: 
		    	{
				
				outfile3 << "Siomai Rice\t";
			
				}
		    		break;
		    	case 10: 
		    	{
				
				outfile3 << "Pancit\t";
			
				}
		    		break;
		    
		    	default: cout << "Invalid item code\n";
		    		break;
		    	
				}
				item = 0;
				}

    		if (l==1 && order [k][0] == 1){
				outfile3 << quan1 << "\t";
			}
			if (l==2 && order [k][0] == 1){
				outfile3 << "25";
			}
			if (l==3 && order [k][0] == 1){
				outfile3 << quan1 * 25;
			}	
			if (l==1 && order [k][0] == 2){
				outfile3 << quan2 << "\t";
			}
			if (l==2 && order [k][0] == 2){
				outfile3 << "35";
			}
			if (l==3 && order [k][0] == 2){
				outfile3 << quan2 * 35;
			}	
			if (l==1 && order [k][0] == 3){
				outfile3 << quan3 << "\t";
			}
			if (l==2 && order [k][0] == 3){
				outfile3 << "35";
			}
			if (l==3 && order [k][0] == 3){
				outfile3 << quan3 * 35;
			}	
			if (l==1 && order [k][0] == 4){
				outfile3 << quan4 << "\t";
			}
			if (l==2 && order [k][0] == 4){
				outfile3 << "45";
			}
			if (l==3 && order [k][0] == 4){
				outfile3 << quan4 * 35;
			}	
			if (l==1 && order [k][0] == 5){
				outfile3 << quan5 << "\t";
			}
			if (l==2 && order [k][0] == 5){
				outfile3 << "45";
			}
			if (l==3 && order [k][0] == 5){
				outfile3 << quan5 * 45;
			}	
			if (l==1 && order [k][0] == 6){
				outfile3 << quan6 << "\t";
			}
			if (l==2 && order [k][0] == 6){
				outfile3 << "50";
			}
			if (l==3 && order [k][0] == 6){
				outfile3 << quan6 * 45;
			}	
			if (l==1 && order [k][0] == 7){
				outfile3 << quan7 << "\t";
			}
			if (l==2 && order [k][0] == 7){
				outfile3 << "50";
			}
			if (l==3 && order [k][0] == 7){
				outfile3 << quan7 * 50;
			}	
			if (l==1 && order [k][0] == 8){
				outfile3 << quan8 << "\t";
			}
			if (l==2 && order [k][0] == 8){
				outfile3 << "55";
			}
			if (l==3 && order [k][0] == 8){
				outfile3 << quan8 * 55;
			}	
			if (l==1 && order [k][0] == 9){
				outfile3 << quan9 << "\t";
			}
			if (l==2 && order [k][0] == 9){
				outfile3 << "55";
			}
			if (l==3 && order [k][0] == 9){
				outfile3 << quan9 * 55;
			}	
			if (l==1 && order [k][0] == 10){
				outfile3 << quan10 << "\t";
			}
			if (l==2 && order [k][0] == 10){
				outfile3 << "60";
			}
			if (l==3 && order [k][0] == 10){
				outfile3 << quan10 * 60;
			}	
			if (l==2 || l==3){
				outfile3 << " pesos\t";
		
    		}
		   
		}
		outfile3 << endl;
	}
		outfile3 << "\n\nTotal: " << supertot << " pesos";
	
  }
  goto restart;
  }
  else cout << "Unable to open file.";
  
  return 0;
  }
  


double itemprice(int itemcode){
  double price;
  switch (itemcode){

    case 1: price = 25;
      break; 
    case 2: price = 35;
	  break;
    case 3: price = 35;
      break;
    case 4: price = 45;
      break;
    case 5: price = 45;
      break;
    case 6: price = 50;
      break;
    case 7: price = 50;
      break;
    case 8: price = 55;
      break;
    case 9: price = 55;
      break;
    case 10: price = 60;
      break;

    default: price = 0;
      break;
  }
  return price;
}
