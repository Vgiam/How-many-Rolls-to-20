#include <iostream>
#include <random>

#include<chrono>
#include<thread>
int main() {
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>dis(1, 6);
	std::chrono::milliseconds duration(300);
	int points{ 0 };
	int count{ 0 };
	std::cout << "Rolls" << "\t" << "Score" << std::endl;
	while(points<=10) {
		int dice = dis(gen);
		std::cout << dice << "\t";
		if (dice == 6) {
			points+=dice;
			
		}
		else {
			switch (dice) {
			case 5:
				points += 2;
				break;
			case 4:
				points += 1;
				break;
			case 3:
				points -= 1;
				break;
			case 2:
				points -= 2;
				break;
			case 1:
				points -= 3;
			}
		}
		std::cout << points << std::endl;
		count++;
		//std::cout << "Tries : " << count << std::endl;
		std::this_thread::sleep_for(duration);
	}
	
	std::cout << "You reach 20 points after " << count << " rolls";
	return 0;

}
