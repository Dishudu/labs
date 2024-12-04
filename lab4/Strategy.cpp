#include <iostream>
#include <vector>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>& data) = 0;
    virtual ~SortingStrategy() = default;
};

class BubbleSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Sorting using Bubble Sort\n";
    }
};

class QuickSortStrategy : public SortingStrategy {
public:
    void sort(std::vector<int>& data) override {
        std::cout << "Sorting using Quick Sort\n";
    }
};

class Sorter {
private:
    SortingStrategy* strategy;
public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void sortArray(std::vector<int>& data) {
        if (strategy) {
            strategy->sort(data);
        }
    }
};

// Пример использования
int main() {
    std::vector<int> data = {5, 3, 8, 4, 2};

    Sorter sorter;

    sorter.setStrategy(new BubbleSortStrategy());
    sorter.sortArray(data);

    sorter.setStrategy(new QuickSortStrategy());
    sorter.sortArray(data);

    return 0;
}
