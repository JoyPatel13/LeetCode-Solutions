class ProductOfNumbers {
public:
    vector<int> list;
    vector<int> ans;
    ProductOfNumbers() {
       ans.push_back(NULL);
    }
    
    void add(int num) {
        list.push_back(num);
        ans.push_back(num);
    }
    
    int getProduct(int k) {
        int n = list.size();
        int K = k;
        int prod = 1;
        int i = n-1;
        while(K>0){
            prod*=list[i];
            i--;
            K--;
        }
        ans.push_back(prod);
        return prod;
    }
    
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */