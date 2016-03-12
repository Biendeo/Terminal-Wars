#include <iostream>
#include <vector>
#include <functional>

class numHolder {
	public:
	numHolder(int num) {
		this->num = num;
	}
	int num;
};

int main() {
	std::vector<std::reference_wrapper<numHolder>> nums;
	numHolder num1(5);
	numHolder num2(6);
	numHolder num3(7);

	nums.emplace_back(std::reference_wrapper<numHolder>(num1));
	nums.emplace_back(std::reference_wrapper<numHolder>(num2));
	nums.emplace_back(std::reference_wrapper<numHolder>(num3));

	nums.at(0).get().num = 144;

	for (std::reference_wrapper<numHolder> x : nums) {
		std::cout << x.get().num << std::endl;
	}

	return 0;
}