
const int COUNT = 1000 * 1000 * 100;
const int A_LEN = 100;

class A {
    char a[A_LEN];
};

int main() {
    A a;
    A to_set;
    for (int i = 0; i < COUNT; i++) {
        to_set = a;
    }

    return 0;
}