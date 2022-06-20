
#include <iostream>
#include <thread>
#include <chrono>

#include <windows.h>
const int width = 30;
const int height = 10;
void func1()
{
	for (int i = width/2; i <= width; i++)
	{
		std::cout << "-";
	}
	std::cout << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	for (int j = 0; j < height; j++)
	{
        for (int i = width / 2; i < width; i++)
    	{
    		if (i == j ) std::cout << "\\";
			if (i == (width-j-1)) std::cout << "/";
    		else std::cout << " ";
    	}
		std::cout << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	for (int i = width / 2; i < width; i++)
	{
		if ((i<=width-height)&&(i >= height ))
		  std::cout << "-";
		else std::cout << " ";
	}
	std::cout << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(100));


}

void func2()
{
	for (int i = 0; i <= width/2; i++)
	{
		std::cout << "-";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width/2; i++)
		{
			if (i == j) std::cout << "\\";
			if (i == (width - j - 1)) std::cout << "/";
			else std::cout << " ";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	for (int i = 0; i < width/2; i++)
	{
		if ((i <= width - height) && (i >= height))
			std::cout << "-";
		else std::cout << " ";
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

}

void func3()
{
   
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &coninfo);
	
	
	for (int j = height; j >0 ; j--)
	{
		coninfo.dwCursorPosition.Y--;
		SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);

		std::cout << "\r";
			for (int i = 0; i < width; i++)
			{
				if (i == j) std::cout << "\\";
				if (i == (width - j - 1)) std::cout << "/";
				if ((i > j)&&(i <(width - j - 1)))
					std::cout << "~";
				else std::cout << " ";
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}

		
	}

}

int main()
{
	{

		std::thread t1(func2);

		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		std::thread t2(func1);



		t1.join();
		t2.join();

		std::thread t3(func3);
		t3.join();

		system("pause");
		return 0;
	}
}
