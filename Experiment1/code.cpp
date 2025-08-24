class MyStack {
    vector<int> v;
    int i = -1;
public:
    void push(int x) {
        if (i + 1 < v.size()) {
            v[++i] = x;
        } else {
            v.push_back(x);
            i++;
        }
    }

    int pop() {
        if (i == -1) return -1;
        return v[i--];
    }
};
