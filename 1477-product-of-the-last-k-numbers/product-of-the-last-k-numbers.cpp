
class ProductOfNumbers {
    vector<int> v;

public:
    ProductOfNumbers() {}

    void add(int num) {
        v.push_back(num);
    }

    int getProduct(int k) {
        int product = 1;
        int n = v.size();

        for (int i = n - 1; i >= n - k; i--) {
            product *= v[i];
        }

        return product;
    }
};
