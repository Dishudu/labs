#include <iostream>
#include <vector>

template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};

template <typename T>
class ArrayIterator : public Iterator<T> {
private:
    const std::vector<T>& items;
    size_t position;
public:
    explicit ArrayIterator(const std::vector<T>& items) : items(items), position(0) {}

    bool hasNext() const override {
        return position < items.size();
    }

    T next() override {
        if (hasNext()) {
            return items[position++];
        }
        throw std::out_of_range("No more elements");
    }
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};

    ArrayIterator<int> iterator(data);

    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
