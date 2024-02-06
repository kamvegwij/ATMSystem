#include <iostream>
#include <string>
#include <conio.h>
//ATM SYSTEM

class atm
{
private:
	//MEMBER VARIABLES
	double balance = 0.0;
	int branch_code = 34587;
	std::string first_name = "", surname = "", ID = "", mobile_num = "", pin_code = "", acc_num = "";

public:
	
	//SET METHODS:
	void set_user_details(std::string fname, std::string lname, std::string userID, std::string user_num, std::string user_pin, std::string user_acc_num)
	{
		first_name = fname;
		surname = lname;
		ID = userID;
		mobile_num = user_num;
		pin_code = user_pin;
		acc_num = user_acc_num;
	}
	//GET METHODS:

	void get_user_details()
	{
		std::cout << "User Fullname: " << get_fullname() << std::endl << "User ID Number: " << get_userID() << std::endl << "User Phone Number: " << get_phone_number() << std::endl;
		_getch();
	}

	double get_balance()
	{
		return balance;
	}

	std::string get_account_number()
	{
		return acc_num;
	}

	std::string get_pin_code()
	{
		return pin_code;
	}
	std::string get_fullname()
	{
		return first_name + " " + surname;
	}
	std::string get_userID()
	{
		return ID;
	}
	std::string get_phone_number()
	{
		return mobile_num;
	}

	//LOGIC METHODS:

	void withdraw(double amount)
	{
		if (amount <= balance) //CAN'T WITHDRAW MORE THAN BALANCE
		{
			balance -= amount;
		}
	}

	void deposit(double amount)
	{
		if (amount > 0)
		{
			balance += amount;
		}
	}

	bool check_pin(std::string user_pin)
	{
		if (user_pin == pin_code)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void update_mobile_num(std::string num)
	{
		if (num.length() == 10) //SOUTH AFRICAN NUMBERS
		{
			mobile_num = num;
		}
		
	}

};

int main()
{
	atm user_obj; //CREATE AN INSTANCE OF THE CLASS->OBJECT
	double amount = 0.0;
	int temp = 0;
	std::string stemp = "", stemp2 = "";
	bool logged_in = false;

	user_obj.set_user_details("Kamvelihle", "Gwijana", "0011025120087", "0655784075", "1122", "1234");
	//user_obj.get_user_details();

	while (1) //infinite
	{
		std::cout << "Enter Account Number: ";
		std::cin >> stemp;
		std::cout << "Enter Pin: ";
		std::cin >> stemp2;

		if ((stemp.compare(user_obj.get_account_number())) == 0 && (stemp2.compare(user_obj.get_pin_code())) == 0)
		{
			system("cls");
			logged_in == true;
			break;
		}
		else
		{
			std::cout << "Incorrect Login Details!\n";
			_getch();
			system("cls");
			logged_in == false;
		}
	}
		
	while (1)
	{
		std::cout << "***Welcome to Bank KGW***" << "\n";
		std::cout << "(1) To view balance\n(2) To view pin number\n(3) To make a deposit\n(4) To make a withdrawal\n(5) Update phone number\n(6) View Details\n(0) To cancel \n";
		std::cin >> temp;

		switch (temp)
		{
		case 0:
			logged_in == false;
			break;

		case 1:
			std::cout << "User Balance: R" << user_obj.get_balance() << "\n";
			_getch();
			system("cls");
			break;

		case 2:
			std::cout << "User Pin Code: " << user_obj.get_pin_code() << "\n";
			_getch();
			system("cls");
			break;

		case 3:
			std::cout << "Enter Deposit Amount: ";
			std::cin >> amount;
			user_obj.deposit(amount);
			std::cout << "Successfully Deposited\n";
			_getch();
			system("cls");
			break;

		case 4:
			std::cout << "Enter Withdraw Amount: ";
			std::cin >> amount;
			user_obj.withdraw(amount);
			std::cout << "Successfully Withdrew\n";
			_getch();
			system("cls");
			break;

		case 5:
			std::cout << "Enter new phone number: ";
			std::cin >> stemp;
			user_obj.update_mobile_num(stemp);
			std::cout << "Updated Phone Number!\n";
			_getch();
			system("cls");
			break;

		case 6:
			user_obj.get_user_details();
			_getch();
			system("cls");
			break;

		default:
			std::cout << "Incorrect Input";
			
		}
	}
	return 0;
}
