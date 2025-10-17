#include <iostream>
#include <string>
#include <iomanip>
#include <limits> 
#include <cctype>
using namespace std;
const double SERVICE_CHARGE_RATE = 0.05;
const int MAX_ORDERS = 1000;
//stock pants
int stock_pants_male = 100;
int stock_pants_female = 100;
//stock shirt
int stock_shirt_male = 100;
int stock_shirt_female = 100;
//stock skirt
int stock_skirt = 100;
//multiple order loop ( save the data(order_price) )
double all_order_total_price = 0;
//no_order
int no_order = 0;//list no_order
int customer_count = 1;//for customer count
int total_quantity_buy[5] = { 0,0,0,0,0 };//for sales report
void order_system()
{
	//multiple order loop 
	char more_order = ' ';
	customer_count = 1;//reset custome
	// variable for customer entry
	char category = ' ';
	int quantity = 0;
	string customerName = "";
	char next_customer = ' ';
	string size = " ";//S,M,L,XL,XXL
	int item = 0; // number of clothes

	//price
	int price = 0;
	int total_price = 0;
	double total_service_change = 0;

	//for invoice and savedata
	string gender = " ";
	string name_item = " ";//write item name in invoice

	do// CONTINUE TO NXT CUSTOMER
	{
		int current_order_count = 0; //clear for new customer                //current_order_count is the number of order of one customer
		all_order_total_price = 0; // clear for new customer                   //all_order_total_price is total price of all the order of one customer

		string temp_customerName[MAX_ORDERS];
		string temp_item[MAX_ORDERS];
		string temp_gender[MAX_ORDERS];
		string temp_size[MAX_ORDERS];
		int temp_quantity[MAX_ORDERS];
		double temp_total_price[MAX_ORDERS];
		system("cls");
		cout << "No.customer: " << customer_count << endl;
		cout << "\n=== AURORA CLOTHING SHOP ===\n";
		cout << "         WELCOME!\n";
		cout << "=============================\n";

		// Get customer name
		cout << "Enter customer name: ";
		cin >> ws;
		getline(cin, customerName);
		do//MULTIPLE ORDER
		{
			cout << "Choose product male or female(M/F): ";
			while (true)//cheak user input right char
			{
				cin >> category;


				if (category == 'M' || category == 'm' || category == 'F' || category == 'f')
				{
					if ((category == 'M' || category == 'm') && stock_shirt_male == 0 && stock_pants_male == 0)//if all male product out of stock 
					{
						cout << "male product out of stock, Please buy other:";
						continue;
					}
					if ((category == 'F' || category == 'f') && stock_shirt_female == 0 && stock_pants_female == 0 && stock_skirt == 0)//if all female product out of stock
					{
						cout << "female product out of stock, Please buy other:";
						continue;
					}
					break;
				}
				else
				{
					cout << "Invalid input! Please enter only M, m, F, or f: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			// for invoice and show menu
			if (category == 'M' || category == 'm')
			{
				gender = "Male";
				cout << "\n------------MALE PRODUCT MENU------------\n";
				cout << "=========================================\n";
				cout << "|TYPE      |  Shirt(1)   |  Pants(2)    |\n";
				cout << "-----------------------------------------\n";
				cout << "|Male      |   RM30      |   RM60       |\n";
				cout << "=========================================\n";

			}
			else
			{
				gender = "Female";
				cout << "\n------------------FEMALE PRODUCT MENU------------------\n";
				cout << "=======================================================\n";
				cout << "|TYPE      |  Shirt(1)   |  Pants(2)   |  Skirt(3)    |\n";
				cout << "-------------------------------------------------------\n";
				cout << "|Female    |   RM30      |   RM60      |   RM30       |\n";
				cout << "=======================================================\n";
			}
			if (gender == "Male")//male product
			{
				cout << "choose shirt(1)/pants(2): ";
			}
			else//female product 
			{
				cout << "choose shirt(1)/pants(2)/skirt(3): ";
			}

			while (true)//cheak user input right item
			{
				cin >> item;


				if ((gender == "Male" && (item == 1 || item == 2)) || (gender == "Female" && (item == 1 || item == 2 || item == 3)))
				{
					if (gender == "Male")//cheak the stock status
					{
						switch (item)
						{
						case 1:
							if (stock_shirt_male == 0)
							{
								cout << "This item is out of stock,Please buy other: ";
								continue;
							}
							break;
						case 2:
							if (stock_pants_male == 0)
							{
								cout << "This item is out of stock,Please buy other: ";
								continue;
							}
							break;
						default:
						{
							break;
						}
						}
						break;
					}
					else
					{
						switch (item)
						{
						case 1:
							if (stock_shirt_female == 0)
							{
								cout << "This item is out of stock,Please buy other: ";
								continue;
							}
							break;
						case 2:
							if (stock_pants_female == 0)
							{
								cout << "This item is out of stock,Please buy other: ";
								continue;
							}
							break;
						case 3:
							if (stock_skirt == 0)
							{
								cout << "This item is out of stock,Please buy other: ";
								continue;
							}
							break;
						default:
						{
							break;
						}
						}
						break;
					}
				}
				else
				{
					cout << "empty item,please input again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			switch (item)//get name item and price
			{
			case 1:
				name_item = "Shirt";
				price = 30;
				break;
			case 2:
				name_item = "Pants";
				price = 60;
				break;
			case 3:
				name_item = "Skirt";
				price = 30;
				break;
			}

			cout << "choose your size ( S , M , L , XL , XXL): ";
			while (true)//cheak user input right size
			{
				cin >> size;

				if ((size == "S" || size == "s") || (size == "M" || size == "m") || (size == "L" || size == "l") || (size == "XL" || size == "xl") || (size == "XXL" || size == "xxl"))
				{
					if (size == "S" || size == "s")
					{
						size = "S";
					}
					else if (size == "M" || size == "m")
					{
						size = "M";
					}
					else if (size == "L" || size == "l")
					{
						size = "L";
					}
					else if (size == "XL" || size == "xl")
					{
						size = "XL";
					}
					else if (size == "XXL" || size == "xxl")
					{
						size = "XXL";
					}
					break;
				}
				else
				{
					cout << "Invalid input! Please enter only S M L XL XXL: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

			}

			cout << "enter the quantity: ";
			while (true)//cheak user input right integer
			{
				if (cin >> quantity)
				{
					if (quantity <= 0)
					{
						cout << "Invalid input! Please enter more than 0: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						continue;
					}
					if ((item == 1 && gender == "Male") && (quantity <= stock_shirt_male))
					{
						stock_shirt_male = stock_shirt_male - quantity;
					}
					else if ((item == 2 && gender == "Male") && (quantity <= stock_pants_male))
					{
						stock_pants_male = stock_pants_male - quantity;
					}
					else if ((item == 1 && gender == "Female") && (quantity <= stock_shirt_female))
					{
						stock_shirt_female = stock_shirt_female - quantity;
					}
					else if ((item == 2 && gender == "Female") && (quantity <= stock_pants_female))
					{
						stock_pants_female = stock_pants_female - quantity;
					}
					else if ((item == 3 && gender == "Female") && (quantity <= stock_skirt))
					{
						stock_skirt = stock_skirt - quantity;
					}
					else
					{
						cout << "too many quantity,not enough of stock" << endl;
						if (item == 1 && gender == "Male")//display how many stock still have
						{
							cout << "now only have " << stock_shirt_male << " item" << ",enter quantity again: ";
							continue;
						}
						else if (item == 2 && gender == "Male")//display how many stock still have
						{
							cout << "now only have " << stock_pants_male << " item" << ", enter quantity again : ";
							continue;
						}
						else if (item == 1 && gender == "Female")//display how many stock still have
						{
							cout << "now only have " << stock_shirt_female << " item" << ", enter quantity again : ";
							continue;
						}
						else if (item == 2 && gender == "Female")//display how many stock still have
						{
							cout << "now only have " << stock_pants_female << ", enter quantity again : ";
							continue;
						}
						else if (item == 3 && gender == "Female")//display how many stock still have
						{
							cout << "now only have " << stock_skirt << ", enter quantity again : ";
							continue;
						}
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

					}
					break;
				}
				else
				{
					cout << "Invalid input! Please enter an integer: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			total_price = price * quantity;
			//save data temporarily
			temp_customerName[current_order_count] = customerName;
			temp_item[current_order_count] = name_item;
			temp_gender[current_order_count] = gender;
			temp_size[current_order_count] = size;
			temp_quantity[current_order_count] = quantity;
			temp_total_price[current_order_count] = total_price;

			//save for sales report
			if (gender == "Male" && item == 1)
			{
				total_quantity_buy[0] += quantity;
			}
			else if (gender == "Female" && item == 1)
			{
				total_quantity_buy[1] += quantity;
			}
			else if (gender == "Male" && item == 2)
			{
				total_quantity_buy[2] += quantity;
			}
			else if (gender == "Female" && item == 2)
			{
				total_quantity_buy[3] += quantity;
			}
			else if (gender == "Female" && item == 3)
			{
				total_quantity_buy[4] += quantity;
			}
			all_order_total_price += total_price;
			current_order_count++;//for marking no order(multiple order)
			cout << "need to continue order?(Y/N): ";
			cin >> more_order;
			if (more_order == 'Y' || more_order == 'y')
			{
				system("cls");//clear screen
			}
		} while (more_order == 'Y' || more_order == 'y');//add more order or not

		system("cls"); //clear command line if stop order
		total_service_change = all_order_total_price * SERVICE_CHARGE_RATE;
		all_order_total_price += total_service_change;
		char delivery_cheack;
		double delivery_fee = 7.0;
		cout << "need delivery?(Y/N):";
		while (true)//cheak user input right integer
		{
			cin >> delivery_cheack;
			if (delivery_cheack == 'Y' || delivery_cheack == 'y')
			{
				string address, phone;
				cout << "\nEnter your delivery address: ";
				cin.ignore();
				getline(cin, address);
				while (true)
				{
					cout << "\nEnter your phone number: ";
					getline(cin, phone);
					bool phone_check = true;
					for (char c : phone)
					{
						if (!isdigit(c))//cheack is digit or not
						{
							phone_check = false; break;
						}

					}
					if (phone_check) { break; }
					cout << "Phone number must be digits only";
				}
				all_order_total_price += delivery_fee;

				cout << "\nDelivery Details:\n";
				cout << "Address: " << address << endl;
				cout << "Phone: " << phone << endl;
				cout << "Delivery Fee: RM " << fixed << setprecision(2) << delivery_fee << endl;
				cout << "New Total (with delivery): RM " << fixed << setprecision(2) << all_order_total_price << endl;
				break;
			}
			else if (delivery_cheack == 'N' || delivery_cheack == 'n')
			{
				delivery_fee = 0;
				break;
			}
			else
			{
				cout << "Invalid input! Please enter only Y/N: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}


		//count order
		no_order++;

		//invoice(KeeM)
		// ===================== INVOICE SECTION =====================
		cout << "\n======================== INVOICE =================================\n";
		cout << "Order_No:#" << no_order << endl;
		cout << "Customer Name: " << customerName << endl;
		cout << "------------------------------------------------------------------\n";
		cout << left << setw(5) << "No"
			<< setw(10) << "Item"
			<< setw(10) << "Gender"
			<< setw(8) << "Size"
			<< setw(10) << "Qty"
			<< setw(14) << "Price/Item"
			<< setw(10) << "Subtotal" << endl;
		cout << "------------------------------------------------------------------\n";

		int total_items_invoice = 0;
		for (int i = 0; i < current_order_count; i++) {
			cout << left << setw(5) << (i + 1)                          // ? numbering
				<< setw(10) << temp_item[i]
				<< setw(10) << temp_gender[i]
				<< setw(8) << temp_size[i]
				<< setw(10) << temp_quantity[i]
				<< "RM " << setw(11) << fixed << setprecision(2) << (temp_total_price[i] / temp_quantity[i])
				<< "RM " << fixed << setprecision(2) << temp_total_price[i] << endl;

			total_items_invoice += temp_quantity[i];                    // ? count items
		}
		cout << "------------------------------------------------------------------\n";
		cout << left << setw(38) << "Total Items:" << total_items_invoice << endl;
		cout << left << setw(38) << "Subtotal:" << "RM " << fixed << setprecision(2) << all_order_total_price - total_service_change - delivery_fee << endl;
		cout << left << setw(38) << "Service Charge (5%):" << "RM " << fixed << setprecision(2) << total_service_change << endl;
		cout << left << setw(38) << "Delivery Fee:" << "RM " << fixed << setprecision(2) << delivery_fee << endl;
		cout << left << setw(38) << "Grand Total:" << "RM " << fixed << setprecision(2) << all_order_total_price << endl;
		cout << "==================================================================\n";

		//payment(kai jin)
		double payment = 0;
		double payment_return = 0;
		int payOpt = 0;
		string payMethod = " ";

		while (true)
		{
			cout << "\nPayment Method:\n1. Cash\n2. Credit Card\n3. E-Wallet\nChoose: ";
			cin >> payOpt;
			if (cin.fail() || payOpt < 1 || payOpt > 3) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Please enter 1, 2, or 3.\n";
			}
			else {
				cin.ignore();
				break;
			}
		}

		// ????????
		switch (payOpt)
		{
		case 1:
		{ // Cash
			payMethod = "Cash";
			cout << "\nEnter amount you want to pay: RM";
			while (true)
			{
				cin >> payment;
				if (payment >= all_order_total_price)
				{
					payment_return = payment - all_order_total_price;   // ? calculate balance
					cout << "Thank you for buying!" << endl;
					if (payment_return > 0)
					{

					}
					break;
				}
				else
				{
					cout << "Please enter the correct amount: RM";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			break;
		}



		case 2:
		{
			// Credit Card
			{
				payMethod = "credit card";
				string cardNumber, expiry, cvv;

				// cardnumber
				while (true) {
					cout << "Enter Cardnumber (16 Digit): ";
					getline(cin, cardNumber);
					bool cardNumber_check = true;
					if (cardNumber.length() != 16) {//cheak length is 16 or not
						cardNumber_check = false;
					}
					else {
						for (char c : cardNumber)
						{
							if (!isdigit(c))//cheack is digit or not
							{
								cardNumber_check = false; break;
							}
						}
					}
					if (cardNumber_check) { break; }//if all digit and length is 16 then stop loop
					cout << "card number must be digit and 16 digit !\n";
					cardNumber_check = " ";
				}
				// expiry date
				while (true) {
					cout << "Enter expiry_date(MM/YY): ";
					getline(cin, expiry);

					bool expiry_check = true;
					if (expiry.length() != 5 || expiry[2] != '/') {
						expiry_check = false;
					}
					else
					{
						for (int i = 0; i < 5; i++) {
							if (i != 2 && !isdigit(expiry[i])) {
								expiry_check = false;
								break;
							}
						}
					}
					if (expiry_check) { break; }
					cout << "must follow the format [MM/YY] and MM and YY must digit !" << endl;
				}
				// CVV
				while (true) {
					bool cvv_check = true;
					cout << "input CVV (3 Digit): ";
					getline(cin, cvv);
					if (cvv.length() != 3) {
						cvv_check = false;
					}
					else {
						for (char c : cvv)
						{
							if (!isdigit(c))
							{
								cvv_check = false; break;
							}
						}
					}
					if (cvv_check) { cout << "Payment Successful !\n"; break; }
					cout << "Error!: card number must be digit and 3 digit\n";
				}
			}
			break;
		}


		case 3:
		{ // E-Wallet
			// qrcode
			payMethod = "E-Wallet";
			char confirm = ' ';
			cout << "\n=== Scan This QR Code to Pay ===\n";
			cout << " :+++++++++++   ++      ++ ++++++++  +++++++++++  \n";
			cout << " +@@@@@@@@@@@   @@      @@ @@@@@@@@  @@@@@@@@@@@  \n";
			cout << " +@        @@ +@@@ @@@@@@@@       @  @@        @  \n";
			cout << " +@        @@ +@@@ @@@@@@@@       @  @@        @  \n";
			cout << " +@  @@@@@ @@   @@@@@   @@@@@   @@@  @@ @@@@@  @  \n";
			cout << " +@  @@@@@ @@ +@@@ @@ +@  @@@@@@@@   @@ @@@@@  @  \n";
			cout << " +@  @@@@@ @@ +@@@ @@ +@  @@@@@@@@   @@ @@@@@  @  \n";
			cout << " +@  @@@@@ @@     @  @@@@@   @@@@@@  @@ @@@@@  @  \n";
			cout << " +@  @@@@@ @@     @  @@@@@   @@@@@@  @@ @@@@@  @  \n";
			cout << " +@        @@ +@  @       @@@@@   @  @@        @  \n";
			cout << " +@@@@@@@@@@@ +@  @  @+ @@ @@  @  @  @@@@@@@@@@@  \n";
			cout << " +@@@ @@@@    +@     @+ @@@@@     @  @@@@@   @@   \n";
			cout << "              +@@@@  @+        @  @     @@@@@@@@  \n";
			cout << "              +@@@@  @+        @  @     @@@@@@@@  \n";
			cout << " +@@@@@@@@@@@ +@  @   +@  @  @@@@@@  @@ @@@@@     \n";
			cout << " +@@@@@@@@@@@ +@  @   +@  @  @@@@@@  @@ @@@@@     \n";
			cout << " +@        @@     @  @+ @@ @@   @@@     @@     @  \n";
			cout << " +@  @@@@@ @@ +@  @  @+ @@@@@@@   @@@@@@@@ +@@@@  \n";
			cout << " +@  @@@@@ @@ +@  @  @+ @@@@@@@   @@@@@@@@ +@@@@  \n";
			cout << " +@  @@@@@ @@ +@@@      @@ @@@@@@@     @  @@@@@@  \n";
			cout << " +@  @@@@@ @@ +@@@ +++: +++@@++@@@   ++@++@@@@@+  \n";
			cout << " +@  @@@@@ @@ +@@@ @@@+   @@@  @@@   @@@@@@@@@@   \n";
			cout << " +@        @@ +@   @@   @@ @@  @@@@    @  @+ @@   \n";
			cout << " +@        @@ +@   @@   @@ @@  @@@@    @  @+ @@   \n";
			cout << " +@@@@@@@@@@@ +@@@ @@@+    @@@@@@@ @@  @@@@@@     \n";
			cout << "[ Please scan with your E-Wallet app ]\n";

			cout << "input any key to continue:";
			cin >> confirm;
		}
		}
		cout << "\nPayment received via: " << payMethod << "\n";
		cout << "Receipt printed. Thank you!\n";

		//Receipt (tan and junjie and ming)
		cout << "\n==========================  RECEIPT ========================== \n";
		cout << "                   AURORA WORKSHOP                   \n";
		cout << "Order No:#" << no_order << endl;
		cout << "Customer: " << customerName << endl;
		cout << "--------------------------------------------------------------\n";

		cout << "No\tItem(Size)\tGender\t          Qty\t      Price\n";

		int total_items_receipt = 0;
		for (int i = 0; i < current_order_count; i++)
		{
			double price_per_item = (temp_quantity[i] > 0) ? temp_total_price[i] / temp_quantity[i] : 0.0;
			cout << (i + 1) << "\t"                        // ✅ numbering
				<< temp_item[i] << "(" << temp_size[i] << ")\t" << setw(18) << temp_gender[i]
				<< temp_quantity[i] << "\t      "
				<< "RM " << fixed << setprecision(2) << price_per_item << endl;

			total_items_receipt += temp_quantity[i];       // ✅ count items
		}

		cout << "--------------------------------------------------------------\n";
		cout << left << setw(30) << "Total Items:" << total_items_receipt << endl;

		// ✅ Calculate subtotal properly (without service charge & delivery)
		double subtotal = all_order_total_price - total_service_change - delivery_fee;

		cout << left << setw(30) << "Subtotal:"
			<< "RM " << fixed << setprecision(2) << subtotal << endl;
		cout << left << setw(30) << "Service Charge (5%):"
			<< "RM " << fixed << setprecision(2) << total_service_change << endl;
		cout << left << setw(30) << "Delivery Fee:"
			<< "RM " << fixed << setprecision(2) << delivery_fee << endl;

		// ✅ Final Receipt Total
		cout << left << setw(30) << "Grand Total:"
			<< "RM " << fixed << setprecision(2) << all_order_total_price << endl;

		// ✅ Cash balance (only for cash)
		if (payMethod == "Cash") {
			cout << left << setw(30) << "Cash Paid:"
				<< "RM " << fixed << setprecision(2) << payment << endl;
			cout << left << setw(30) << "Balance Returned:"
				<< "RM " << fixed << setprecision(2) << payment_return << endl;
		}

		cout << left << setw(30) << "Payment Method:" << payMethod << endl;
		cout << "----------------------------------------------------\n";
		cout << "======================== Check Closed ========================\n";


		// Next customer?
		cout << "\nContinue to next customer? (Y/N): ";
		cin >> next_customer;
		if (next_customer == 'Y' || next_customer == 'y')
		{
			customer_count++;
		}
	} while (next_customer == 'Y' || next_customer == 'y');
	system("cls");

}

void reporting()
{
	double unit_price[2] = { 30,60 };
	system("cls");
	cout << "\n=== AURORA Clothing Store Report ===\n";
	cout << "================ STOCK BALANCE ================\n";
	cout << left << setw(20) << "Male Pants:" << stock_pants_male << endl;
	cout << left << setw(20) << "Female Pants:" << stock_pants_female << endl;
	cout << left << setw(20) << "Male Shirt:" << stock_shirt_male << endl;
	cout << left << setw(20) << "Female Shirt:" << stock_shirt_female << endl;
	cout << left << setw(20) << "Female Skirt:" << stock_skirt << endl;
	cout << "================================================\n";

	cout << "\n================ WEEKLY SALES REPORT ============\n";
	cout << left << setw(20) << "Shop Item" << left << setw(20) << "Unit_Price(RM)" << left << setw(20) << "Quantity" << left << setw(20) << "Total Earn" << endl;
	cout << "========================================================================================" << endl;
	cout << left << setw(20) << "1. Male shirt" << left << setw(20) << fixed << setprecision(2) << unit_price[0] << left << setw(20) << total_quantity_buy[0] << left << setw(20) << unit_price[0] * total_quantity_buy[0] << endl;
	cout << left << setw(20) << "2. Female shirt" << left << setw(20) << fixed << setprecision(2) << unit_price[0] << left << setw(20) << total_quantity_buy[1] << left << setw(20) << unit_price[0] * total_quantity_buy[1] << endl;
	cout << left << setw(20) << "3. Male Pants" << left << setw(20) << fixed << setprecision(2) << unit_price[1] << left << setw(20) << total_quantity_buy[2] << left << setw(20) << unit_price[1] * total_quantity_buy[2] << endl;
	cout << left << setw(20) << "4. Female Pants" << left << setw(20) << fixed << setprecision(2) << unit_price[1] << left << setw(20) << total_quantity_buy[3] << left << setw(20) << unit_price[1] * total_quantity_buy[3] << endl;
	cout << left << setw(20) << "5. Female Skirt" << left << setw(20) << fixed << setprecision(2) << unit_price[0] << left << setw(20) << total_quantity_buy[4] << left << setw(20) << unit_price[0] * total_quantity_buy[4] << endl;
	cout << "========================================================================================" << endl;
	cout << "Total Item : 5 " << endl;
	cout << "Grand_total:RM" << (unit_price[0] * total_quantity_buy[0]) +
		(unit_price[0] * total_quantity_buy[1]) +
		(unit_price[1] * total_quantity_buy[2]) +
		(unit_price[1] * total_quantity_buy[3]) +
		(unit_price[0] * total_quantity_buy[4]) << endl;
}

int main()
{
	int choose = 0;
	while (true)
	{
		//menu
		cout << "***********WELOCOME TO AURORA WORKSHOP***************" << endl;
		cout << " ██████╗ ██╗   ██╗██████╗   ██████╗ ██████╗  █████╗" << endl;
		cout << "██╔═══██╗██║   ██║██╔══██╗██╔════██╗██╔══██╗██╔══██╗" << endl;
		cout << "████████║██║   ██║██████╔╝██║    ██║██████╔╝███████║" << endl;
		cout << "██╔═══██║██║   ██║██╔══██╗██║    ██║██╔══██╗██╔══██║" << endl;
		cout << "██║   ██║╚██████╔╝██║  ██║╚███████╔╝██║  ██║██║  ██║" << endl;
		cout << "╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝" << endl;
		cout << "***********WELOCOME TO AURORA WORKSHOP***************" << endl;
		cout << "input number to order,reporting and exit" << endl;
		cout << "1.order(1)\n2.reporting(2)\n3.exit(3)" << endl;
		cout << "Enter number to continue:";
		//user input number to choose
		if (cin >> choose)// if user input number
		{
			switch (choose)
			{
			case 1:
				order_system();
				break;
			case 2:
				reporting();
				break;
			case 3:
				cout << "thank for using aurora order system\n";
				return 0;
				break;
			default:
				system("cls");
				cout << "=====Invalid choice, Please enter 1, 2, OR 3===== " << endl;
				break;
			}
		}
		else// if user put non-number
		{
			system("cls");
			cout << "=====Invalid input,Please enter again===== " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choose = 0;
		}
	}
	return 0;
}