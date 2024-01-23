#include <iostream>

using namespace std;


int main(){
	
	bool stop = false;

	int stores=4, products=5;
	int warehouses[stores][products];


	for(int i = 0;i<stores;i++){
		for(int j = 0;j<products;j++){
			warehouses[i][j] = 0;
		}

	}


	//uncomment for test data instead of adding data from scratch
	/*
	int testData[stores][products] = {
		{6,0,2,2,6},
		{4,5,6,9,15},
		{2,5,17,23,4},
		{8,6,4,3,1},
	};

	for(int i = 0;i<stores;i++){
		for(int j = 0;j<products;j++){
			warehouses[i][j] = testData[i][j];
		}
	}
	*/


	int bigTotal[stores+1];
	double bonus = 0.05;

	cout<<"TASAW DEMEKE ENA GUADEGNOCHU TEKLALA YE MEGAZEN SRA"<<endl;
	cout<<"TASAW DEMEKE AND HIS FRIENDS COMPLETE WAREHOUSE WORK"<<endl;
	cout<<"...........................................................";


	char choice1;


	home:

		cout<<endl<<endl<<"1-Add a product"<<endl;
		cout<<"2-Search"<<endl;
		cout<<"3-Summary/Report"<<endl;
		cout<<"4-Remove product"<<endl;
		cout<<"0-Quit"<<endl;
		cout<<": ";
		cin>>choice1;
		

		switch(choice1){

			case '1':
				add:
					cout<<endl<<endl<<"\t"<<"Add"<<endl<<endl<<"\t"<<"Enter the required information about the product."<<endl;
					cout<<"\t"<<"[Enter 0 to go back]"<<endl<<endl;

					int productNumber, warehouseNumber, quantity;

					cout<<"\t"<<"Product Number(1-5): ";
					cin>>productNumber;

					if(productNumber == 0){
						break;
					}

					cout<<"\t"<<"Warehouse Number(1-4): ";
					cin>>warehouseNumber;

					if(warehouseNumber == 0){
						break;
					}

					cout<<"\t"<<"Quantity Received: ";
					cin>>quantity;

					if(quantity == 0){
						break;
					}

					

					if(productNumber>=1 && productNumber<=5 && warehouseNumber>=1 && warehouseNumber<=4 && quantity>=1){
						warehouses[warehouseNumber-1][productNumber-1] += quantity;

						cout<<endl<<"\t"<<quantity<<" "<<"Product-"<<productNumber<<" successfully added to warehouse-"<<warehouseNumber;
					}else{
						cout<<endl<<"\t"<<"There is a problem with the information you have just entered. Please re-check and try again.";
					}
					
					goto add;

				break;
			case '2':

				search:
					char choice2;

					cout<<endl<<endl<<"\t"<<"Search"<<endl<<endl;
					cout<<"\t"<<"[Enter 0 to go back]"<<endl<<endl;

					cout<<"\t"<<"1-Search by product"<<endl;
					cout<<"\t"<<"2-Search by store keeper"<<endl;
					cout<<"\t"<<": ";
					cin>>choice2;

					if(choice2 == '0'){
						break;
					}else if(choice2 == '1'){
						searchByProduct:
							int searchProductNumber;

							cout<<endl<<endl<<"\t"<<"[Enter 0 to go back]"<<endl;
							cout<<"\t"<<"Product Number(1-5): ";
							cin>>searchProductNumber;

							if(searchProductNumber == 0){
								goto search;
							}else if(searchProductNumber>=1 && searchProductNumber<=5){

								cout<<endl;
								cout<<"\t"<<"Item\t\tStore-1\t\tStore-2\t\tStore-3\t\tStore-4\t\tTotal"<<endl;
								cout<<"\t"<<"Product-"<<searchProductNumber;

								int total = 0;
								int number;

								for(int i = 0;i<stores;i++){
									number = warehouses[i][searchProductNumber-1];
									total += number;


									if(i == 0){
										cout<<"\t"<<number;

									}else{
										cout<<"\t\t"<<number;

									}
								}

								cout<<"\t\t"<<total;

								goto searchByProduct;
								

							}else{
								cout<<endl<<"\t"<<"Invalid input!";
								goto searchByProduct;
							}

					}else if(choice2 == '2'){
						searchByKeeper:
							int searchWarehouseNumber;

							cout<<endl<<endl<<"\t"<<"[Enter 0 to go back]"<<endl;
							cout<<"\t"<<"Warehouse Number(1-4): ";
							cin>>searchWarehouseNumber;

							if(searchWarehouseNumber == 0){
								goto search;
							}else if(searchWarehouseNumber>=1 && searchWarehouseNumber<=4){

								cout<<endl;
								cout<<"\t"<<"Store\t\tProduct-1\tProduct-2\tProduct-3\tProduct-4\tProduct-5\tTotal"<<endl;
								cout<<"\t"<<"Warehouse-"<<searchWarehouseNumber;

								int total = 0;
								int number;

								for(int i = 0;i<products;i++){
									number = warehouses[searchWarehouseNumber-1][i];
									total += number;

									if(i == 0){
										cout<<"\t"<<number;

									}else{
										cout<<"\t\t"<<number;

									}
								}

								cout<<"\t\t"<<total;

								goto searchByKeeper;
								

							}else{
								cout<<endl<<"\t"<<"Invalid input!";
								goto searchByKeeper;
							}

					}else{
						cout<<endl<<"\t"<<"Invalid input!";
						goto search;

					}



				break;
			case '3':

				for(int i = 0;i<=stores;i++){
					bigTotal[i] = 0;
				}

				cout<<endl<<endl<<"\t"<<"Summary/Report"<<endl<<endl;

				cout<<"\t"<<"Item\t\tKeeper-1\tKeeper-2\tKeeper-3\tKeeper-4\tTotal"<<endl;

				for(int j = 0;j<products;j++){
					
					int total = 0;
					int number;
					
					cout<<"\t"<<"Product-"<<j+1;
					for(int i = 0;i<stores;i++){

						number = warehouses[i][j];

						if(i==0){
							cout<<"\t"<<number;
						}else{
							cout<<"\t\t"<<number;
						}

						total += number;

						bigTotal[i] += number;

					}

					cout<<"\t\t"<<total<<endl;

					bigTotal[stores] += total;

				}

				cout<<"\t"<<"Total";
				for(int i = 0;i<=stores;i++){
					if(i==0){
						cout<<"\t\t"<<bigTotal[i];
					}else{
						cout<<"\t\t"<<bigTotal[i];
					}
				}

				cout<<endl<<"\t"<<"Bonus";
				for(int i = 0;i<=stores;i++){
					if(i==0){
						cout<<"\t\t"<<(bigTotal[i]*bonus);
					}else{
						cout<<"\t\t"<<(bigTotal[i]*bonus);
					}
				}



				break;

			case '4':
				remove:
					cout<<endl<<endl<<"\t"<<"Remove"<<endl<<endl<<"\t"<<"Enter the required information about the product."<<endl;
					cout<<"\t"<<"[Enter 0 to go back]"<<endl<<endl;

					int r_productNumber, r_warehouseNumber, r_quantity;

					cout<<"\t"<<"Product Number(1-5): ";
					cin>>r_productNumber;

					if(r_productNumber == 0){
						break;
					}

					cout<<"\t"<<"Warehouse Number(1-4): ";
					cin>>r_warehouseNumber;

					if(r_warehouseNumber == 0){
						break;
					}

					cout<<"\t"<<"Quantity to remove: ";
					cin>>r_quantity;

					if(r_quantity == 0){
						break;
					}

					

					if(r_productNumber>=1 && r_productNumber<=5 && r_warehouseNumber>=1 && r_warehouseNumber<=4 && r_quantity>=1){
						
						if(r_quantity <= warehouses[r_warehouseNumber-1][r_productNumber-1]){
							warehouses[r_warehouseNumber-1][r_productNumber-1] -= r_quantity;
							
							cout<<endl<<"\t"<<r_quantity<<" "<<"Product-"<<r_productNumber<<" successfully removed from warehouse-"<<r_warehouseNumber;

						}else{
							cout<<endl<<"\t"<<"Insufficient quantity of product-"<<r_productNumber<<" in warehouse-"<<r_warehouseNumber;
							cout<<endl<<"\t"<<"[ Quantity in store: "<<warehouses[r_warehouseNumber-1][r_productNumber-1]<<" ]";

						}

					}else{
						cout<<endl<<"\t"<<"There is a problem with the information you have just entered. Please re-check and try again.";
					}

					goto remove;

				break;
			case '0':
				stop = true;
				
				break;
			default:
				cout<<endl<<"Invalid input!";

		}

		if(stop){
			cout<<endl<<"Thank you for using our service.";
		}else{
			goto home;
		}
	
	
	
	return 0;
}
