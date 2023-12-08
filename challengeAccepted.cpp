#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>
#include <map>



void printArray(const std::vector<std::string>& array) {
    for (const auto& element : array) {
        std::cout << element << std::endl;
    }
}
void change_pos(int index, std::vector<int>& array){
    int temp = array[index];
    int random = rand() % array.size();
    while (random == index){
        random = rand() % array.size();
    }
    array[index] = array[random];
    array[random] = temp;
}
int guessedNumber(){
    std::cout<<"Enter a number between 1 and 100 and try to guess the magic number"<<std::endl;
    int x;
    int random_int = rand()%100+1;
    do{
        std::cin>>x;
        x>random_int?std::cout<<" lower ":std::cout<<" higher ";
    }while(x != random_int); // repeat reading from the user until entering the correct number
    std::cout<<"Correct! your guessed the magic number : "<<random_int<<std::endl;
    return x;
}
int transformer(int magic_number){
    int x = magic_number>30?magic_number/10:magic_number;
    return x;
}
// search an element in an array
int find(std::vector<std::string>& array, int magic_number){
    int index_of_element;
    int index = 0;
        while (index != array.size()){
            if (index == magic_number){
                index_of_element = index;
            }
            index++;
        }
    // random function
    int random_int = rand() % 100+1;
    while (random_int != magic_number){
        index = 0;
        while (index != array.size()){
            if (index == magic_number){
                index_of_element = index;
            }
            index++;
        }
        random_int = rand() % 100+1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return index_of_element;
}

int main() {
    srand((unsigned) time(NULL));
    // create a an array filled with 30 climate change tips
    std::vector<std::string> climateChangeSolutions = {
        "Increase the use of renewable energy sources such as solar, wind, and hydropower.",
        "Implement and enforce strict energy efficiency standards for buildings, appliances, and industrial processes.",
        "Launch large-scale afforestation programs to plant trees and restore forests.",
        "Encourage the use of electric vehicles, public transportation, and cycling.",
        "Invest in research and development of CCS technologies to capture and store carbon dioxide emissions.",
        "Promote sustainable farming practices to reduce deforestation and limit the use of chemical fertilizers.",
        "Implement comprehensive waste management strategies to reduce landfill emissions and promote recycling and composting.",
        "Raise awareness about climate change through educational campaigns.",
        "Develop and upgrade infrastructure with climate resilience in mind.",
        "Foster global collaboration and agreements to address climate change on an international scale.",
        "Implement carbon pricing mechanisms such as carbon taxes or cap-and-trade systems.",
        "Provide financial incentives for private landowners to engage in reforestation efforts and sustainable land management.",
        "Enforce and enhance green building standards to promote energy-efficient and environmentally friendly construction practices.",
        "Increase funding for research and development of clean and sustainable technologies.",
        "Support community-led initiatives that focus on adapting to the impacts of climate change at the local level.",
        "Promote a circular economy by encouraging the recycling and reusing of products to minimize waste.",
        "Encourage a shift toward plant-based diets to reduce the environmental impact of livestock farming.",
        "Provide financial incentives and subsidies to businesses and individuals investing in renewable energy.",
        "Invest in the development and promotion of crop varieties that are more resilient to changing climatic conditions.",
        "Upgrade energy infrastructure with smart grids to improve efficiency and better integrate renewable energy sources.",
        "Encourage financial institutions to prioritize investments in environmentally sustainable projects.",
        "Implement measures to protect and restore marine ecosystems, including the reduction of plastic pollution.",
        "Introduce labels on products indicating their carbon footprint, enabling consumers to make environmentally conscious choices.",
        "Integrate climate change education into school curricula to ensure future generations are well-informed.",
        "Support local and sustainable food production to reduce the carbon footprint associated with long-distance transportation.",
        "Plan and design cities with a focus on sustainability, including green spaces, efficient public transportation, and energy-efficient buildings.",
        "Provide training to farmers on climate-smart agricultural practices that enhance resilience.",
        "Invest in scientific research to discover new and innovative solutions for mitigating and adapting to climate change.",
        "Provide financial and technical assistance to developing nations vulnerable to the impacts of climate change.",
        "Develop and promote tools for individuals to calculate and reduce their carbon footprint, encouraging personal responsibility."
    };
    // Display information for a specific index (e.g., index 5)
    int specificIndex = find(climateChangeSolutions,transformer(guessedNumber()));
    std::cout<<climateChangeSolutions[specificIndex]<<std::endl;
    std::cout<<"end of program!";
    return 0;
}
