# include <iostream>

int main{

    if (std::cin >> currVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
    std::cout << currVal << " occurs "
        << cnt << "times" << std::endl;
}






if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
        if (val == currVal)
            ++cnt;
        else {
            std::cout << currVal << " occurs "
                << cnt << " times" << std::endl;
            currVal = val;
            cnt = 1;
        }
    }
    std::cout << currVal << " occurs "
        << cnt << "times" << std::endl;
}